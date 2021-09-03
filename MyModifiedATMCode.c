//For Info About Program check About Section from NSTTPKS Bank Service mainmenu.
#include <stdio.h>
#include <stdlib.h>             //used only for goto statement
#include <string.h>             // used for comparing Username string literal
#include <time.h>               // Used to show time of transaction

int transactionTime()
{
  FILE *fptr2;
  fptr2 = fopen("D:/Users/Zaphkil!/Documents/GitHub/Basic-ATM-Machine-Project-in-C/User_Account_info/Transaction_History.txt","a");
    printf("\nSession time added to Transaction_History.txt file.\n----------------------------------");
   
    time_t t;
    time(&t);
    fprintf(fptr2,"\n%s ",ctime(&t));
    fclose(fptr2);
    return 0;
}

int accountUpdate()
{
  FILE *fptr1;
  fptr1 = fopen("D:/Users/Zaphkil!/Documents/GitHub/Basic-ATM-Machine-Project-in-C/User_Account_info/Account_Details.txt","a");
  printf("\nSession time added to Account_Details.txt file.\n----------------------------------");
    printf("\nUpdated Account_Details.txt file.\n----------------------------------");
   
    time_t t;
    time(&t);
    fprintf(fptr1,"\n====================\n%s=================== ",ctime(&t));
    fclose(fptr1);
    return 0;
}

unsigned long amount, deposit, withdraw, exchange, exchangedAmount;
int choice, pin, k, currecyExchange;
char transaction = 'y';
char name[20];
FILE *fptr1; 
FILE *fptr2;
FILE *fptr3;

void main()
{
  Name:
    printf("\nEnter Your Username: ");//Asks User to enter their username only "Prakash" accepted.
    scanf("%s", name);
    if (strcmp(name, "Prakash") == 0)//strcmp function compare the Username string literal to "Prakash"
    { 
      while (pin != 1234)           //if Password is 1234 only then the account will open
      {
        printf("Enter Your Secret Pin Number: ");
        scanf("%d", & pin);
        
        if (pin != 1234)
        {
          printf("Please Enter Valid Password! \a\n");
        }     
      }
    }
    else
    {
      printf("invalid Username"); //Invalid username
      goto Name;//Jumps to the start of main Function
    }
    fptr3 = fopen("D:/Users/Zaphkil!/Documents/GitHub/Basic-ATM-Machine-Project-in-C/User_Account_info/Account_Balance.txt","r");
    printf("-----------------------------\nOpened Account_Balance.txt file.");
    if(fptr3 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }

    fptr2 = fopen("D:/Users/Zaphkil!/Documents/GitHub/Basic-ATM-Machine-Project-in-C/User_Account_info/Transaction_History.txt","a");
    printf("\nOpened Transaction_History.txt file.\n----------------------------------\n");
    transactionTime();
    if(fptr2 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
  printf("\nFetching Account Balance!");
  while (fscanf(fptr3, "%lu", &amount) == 1)
  { 
    printf("\nAccount Balance fetched Successfully!.\n");
  }
  printf("\nAccount Balance: %lu \n", amount);

  fclose(fptr3);

  do
  {
    printf("\n                Hello, %s", name);
    printf("\n*****Welcome to NSTTPKS Bank ATM Service*****\n"); //NSTTPKS bank ATM Main Menu. 
    printf("1. Check Balance\n");           
    printf("2. Withdraw Cash\n");
    printf("3. Deposit Cash\n");
    printf("4. Currency Exchange\n");
    printf("5. About NSTTPKS Bank\n");
    printf("6. Quit\n");

    printf("********************\n\n");

    printf("Enter Your Choice: ");  // choice is an integer value which is used for switch case
    scanf("%d", & choice);

    switch (choice)
    {

    case 1:         //This case simply shows current balance in account

      printf("\n Your Balance is: Rs.%lu ", amount);
      fprintf(fptr2,"\nShown balance Amount: Rs.%lu \n",amount);

      break;

    case 2:         //This case is used to withdraw cash from the user account, minimum ammount should be 500 in account
                    //Balance can only be withdrawn in Multiples of 100

      printf("\n Enter the Amount(Multiples of 100) to Withdraw(500 Minimum balance required in account): ");
      scanf("%lu", &withdraw);
      

      if (withdraw % 100 != 0)
      {

        printf("\n Please Enter the Amount in Multiples of 100");

      }
      else if (withdraw > (amount - 500))
      {

        printf("\n Insufficent Balance, Minimum balance couldn't be less then ₹500 in account");
      }
      
      else
      {
        amount = amount - withdraw;
        
        printf("\n\n Please Collect Cash");
        printf("\n Your Current Balance is Rs.%lu", amount);

        fprintf(fptr2,"\nAmount Withdrawn: Rs.%lu \n",withdraw);
        fprintf(fptr2,"Your Current Balance is Rs.%lu \n", amount);

      }

      break;

    case 3:             //This case is used to Deposit the money in bank account

      printf("\nEnter the Amount to Deposit: Rs.\n");
      scanf("%lu", &deposit);

      amount = amount + deposit;

      printf("Your Balance is Rs.%lu", amount);

      fprintf(fptr2,"\nAmount Deposited: Rs.%lu \n", deposit);
      fprintf(fptr2,"Your Current Balance is Rs.%lu \n", amount);
      
      break;
      
    case 4:             //This case is used for Currency exchange only $,€,¥ are accepted at the moment

      printf("\nEnter the Amount You Want to Exchange: Rs."); //Currency to be exchanged from main balance 
      scanf("%lu", &exchange);
      
      printf("\nChoose the Currency to Exchange into\n");   //Currency Selection menu, To which Currency you need to convertinto 
      
      printf("1. US Dollar\n");  //US $ Current Exchange rate(30 Aug, 2021): 100 Rupee = $1.36
      printf("2. European Euro\n");  //European € Current Exchange rate(30 Aug, 2021): 100 Rupee = €1.15
      printf("3. Japanese Yen\n");   //Japanese ¥ Current Exchange rate(30 Aug, 2021): 100 Rupee = ¥149.52
        

      scanf("%d", & currecyExchange);
      
      switch(currecyExchange)
      {
          case 1: //Exchange into USD
                    printf("\nAmount You Want to Exchange: Rs. %lu", exchange);
                    amount= amount-exchange;
                    exchangedAmount = (exchange/73.49) ;
                    printf("\nAmount Rs.%lu Exchanged in $%lu\n", exchange, exchangedAmount);

                      fprintf(fptr2,"\nAmount Rs.%lu Exchanged in $%lu \n",exchange, exchangedAmount);

                    printf("\n\n Please Collect Cash\n");
                    break;
                    
          case 2: //Exchange into EUR
                    printf("\nAmount You Want to Exchange: Rs. %lu", exchange);
                    amount= amount-exchange;
                    exchangedAmount = (exchange/86.68) ;
                    printf("\nAmount Rs.%lu Exchanged in %lu Euros\n", exchange, exchangedAmount);

                      fprintf(fptr2,"\nAmount Rs.%lu Exchanged in €%lu \n",exchange, exchangedAmount);

                    printf("\n\n Please Collect Cash\n");
                    break;
          
          case 3: //Exchange into JPY
                    printf("\nAmount You Want to Exchange: Rs. %lu", exchange);
                    amount= amount-exchange;
                    exchangedAmount = (exchange*1.49) ;
                    printf("\nAmount Rs.%lu Exchanged in %lu Yens \n", exchange, exchangedAmount);

                      fprintf(fptr2,"\nAmount Rs.%lu Exchanged in ¥%lu \n",exchange, exchangedAmount); 

                    printf("\n\n Please Collect Your Cash\n");
                    break;  
      }
      
      fprintf(fptr2,"Your Current Account Balance is Rs.%lu \n", amount);

      printf("Your Balance is Rs.%lu", amount);//Balance after Exchanged
      break;
    
    case 5: //About and Credit
                    printf("\n\n\n===========Welcome to NSTTPKS Bank ATM About section============\n\n\n");
                    printf("Our Name NSTTPKS is formed of Initials of each of our Project group member Name.\n");
                    printf("That is:(in Alphabetically ascending order)\n");
                    
                    printf("Neezam Ali\nSonali Rawat\nTeesha\nTanu\nPrakash\nKirty\nSagar Goswami\n");
                    
                    printf("\n\nThis project of ATM machine Code Contains the Following functionality:\n");
                    printf("1. Check the balance\n2. Withdrawn cash\n3. Deposit Cash\n4. Currency Exchange to\n\t1. USD \n\t2. EUR \n\t3. JPY\n5. About NSTTPKS ATM\n\n\n\n");
                    printf("Keeping a record of Transaction History\n");
                    break;

    case 6:
      k = 1;
      goto jump;

    default:
        printf("\n Invalid Choice, Please enter a valid choice.");
        
    }
    
    // to Repeat the Last Transcation Press Y, Or choose a option from Menu Below
    printf("\n\nDo U Wish to Repeat Last Operation/Transcation, then Press 'Y', Or Press any key(Except Y/N) to return to Mainmenu: \nPress 'N' to Exit.\n");
    fflush(stdin);

    scanf("%c", & transaction);

    if (transaction == 'n' || transaction == 'N')
        k = 1;
  }
  
    while (!k);
    jump:
    fptr1 = fopen("D:/Users/Zaphkil!/Documents/GitHub/Basic-ATM-Machine-Project-in-C/User_Account_info/Account_Details.txt","a");
    printf("-----------------------------\nOpened Account_Details.txt file.");
    if(fptr1 == NULL)
   {
      printf("Error!");   
      exit(1);             
   }
   fptr3 = fopen("D:/Users/Zaphkil!/Documents/GitHub/Basic-ATM-Machine-Project-in-C/User_Account_info/Account_Balance.txt","w");
    printf("\nOpened Account_Balance.txt file.");
    accountUpdate();
    fprintf(fptr3,"%lu",amount);
    printf("Overwritten Account_Balance.txt");
    fprintf(fptr1,"\nUpdated Account Balance: Rs.%lu",amount);

    fprintf(fptr2,"=====================Session End=======================");
    fclose(fptr1);
    fclose(fptr2);
    fclose(fptr3);
    printf("\n\nThank You for Using NSTTPKS Bank ATM.\n          Have a Nice Day.");   
}
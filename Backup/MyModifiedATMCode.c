#include <stdio.h>
#include <stdlib.h>             //used only for goto statement
#include <string.h>             // used for comparing Username string literal

unsigned long amount = 1000, deposit, withdraw, exchange, exchangedAmount;
int choice, pin, k, currecyExchange;
char transaction = 'y';
char name[20];

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

      printf("\n Your Balance is: ₹%lu ", amount);

      break;

    case 2:         //This case is used to withdraw cash from the user account, minimum ammount should be 500 in account
                    //Balance can only be withdrawn in Multiples of 100

      printf("\n Enter the Amount(Multiples of 100) to Withdraw(500 Minimum balance required in account): ");
      scanf("%lu", & withdraw);

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
        printf("\n Your Current Balance is ₹%lu", amount);
      }

      break;

    case 3:             //This case is used to Deposit the money in bank account

      printf("\nEnter the Amount to Deposit: ₹");
      scanf("%lu", & deposit);

      amount = amount + deposit;

      printf("Your Balance is ₹%lu", amount);
      
      break;
      
    case 4:             //This case is used for Currency exchange only $,€,¥ are accepted at the moment

      printf("\nEnter the Amount You Want to Exchange: ₹"); //Currency to be exchanged from main balance 
      scanf("%lu", &exchange);
      
      printf("\nChoose the Currency to Exchange into\n");   //Currency Selection menu, To which Currency you need to convertinto 
      
      printf("1. $(US Dollar)\n");  //US $ Current Exchange rate(30 Aug, 2021): 100 Rupee = $1.36
      printf("2. €(European Euro)\n");  //European € Current Exchange rate(30 Aug, 2021): 100 Rupee = €1.15
      printf("3. ¥(Japanese Yen)\n");   //Japanese ¥ Current Exchange rate(30 Aug, 2021): 100 Rupee = ¥149.52
        

      scanf("%d", & currecyExchange);
      
      switch(currecyExchange)
      {
          case 1: //Exchange into USD
                    printf("\nAmount You Want to Exchange: ₹ %lu", exchange);
                    amount= amount-exchange;
                    exchangedAmount = (exchange/73.49) ;
                    printf("\nAmount ₹%lu Exchanged in $%lu\n", exchange, exchangedAmount);
                    printf("\n\n Please Collect Cash");
                    break;
                    
          case 2: //Exchange into EUR
                    printf("\nAmount You Want to Exchange: ₹ %lu", exchange);
                    amount= amount-exchange;
                    exchangedAmount = (exchange/86.68) ;
                    printf("\nAmount ₹%lu Exchanged in €%lu\n", exchange, exchangedAmount);
                    printf("\n\n Please Collect Cash");
                    break;
          
          case 3: //Exchange into JPY
                    printf("\nAmount You Want to Exchange: ₹ %lu", exchange);
                    amount= amount-exchange;
                    exchangedAmount = (exchange*1.49) ;
                    printf("\nAmount ₹%lu Exchanged in ¥%lu \n", exchange, exchangedAmount);
                    printf("\n\n Please Collect Cash");
                    break;  
      }
      
      printf("Your Balance is ₹%lu", amount);//Balance after Exchanged
      break;
    
    case 5: //About and Credit
                    printf("\n\n\n===========Welcome to NSTTPKS Bank ATM About section============\n\n\n");
                    printf("Our Name NSTTPKS is formed of Initials of each of our Project group member’s Name.\n");
                    printf("That is:(in Alphabetically ascending order)\n");
                    
                    printf("Neezam Ali\nSonali Rawat\nTeesha\nTanu\nPrakash\nKirty\nSagar Goswami\n");
                    
                    printf("\n\nThis project of ATM machine Code Contains the Following functionality:\n");
                    printf("1. Check the balance\n2. Withdrawn cash\n3. Deposit Cash\n4. Currency Exchange to\n\t1. USD \n\t2. EUR \n\t3. JPY\n5. About NSTTPKS ATM\n\n\n\n");
                    
                    break;

    case 6:
      k = 1;
      goto jump;

    default:
        printf("\n Invalid Choice, Please enter a valid choice.");
      
    }
    
    // to Repeat the Last Transcation Press Y, Or choose a option from Menu Below
    printf("\n\nDo U Wish to Repeat Last Operation/Transcation, then Press 'Y', Or Choose from the options below: \nPress 'N' to Exit.\n");
    fflush(stdin);
    scanf("%c", & transaction);

    if (transaction == 'n' || transaction == 'N')
        k = 1;

  }
  
    while (!k);
    jump:
    printf("\n Thank You for Using NSTTPKS Bank ATM.\n          Have a Nice Day.");   
}
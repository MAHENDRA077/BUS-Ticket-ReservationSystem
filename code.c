#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#include<conio.h>

// welocme message...
void welcome()
{
    printf("****************************************\n");
    printf("   WELOCME TO BUS TICKET BOOKING SYSTEM \n");
    printf("****************************************\n");
}

// display fare of buses ...
void fare_chart()
{
    printf("------Fare over various Routes------\n");
    printf("Vijayawada to Vizag     : 650 \n");
    printf("Vijayawada to Bengalore : 1400\n");
    printf("Vijayawada to Chennai   : 1000\n");
    printf("Guntur to Rajam         : 890\n");
}

// display routes with timings ...
void display_buses()
{
    printf("------Routes------\n");
    printf("Route-1: Vijayawada to Vizag\n");
    printf("Route-2: Vijayawada to Bengalore\n");
    printf("Route-3: Vijayawada to Chennai\n");
    printf("Route-4: Guntur to Rajam\n\n");

}

// diplay seating order of busess ....
void view_tickets()
{
    int i=1;
    while(i<=32)
    {
        printf("%d ",i);
        printf("%d ",i+1);
        printf("\t");
        printf("%d ",i+2);
        printf("%d \n",i+3);
        i+=4;
    }
    printf("$ not reserved\t* for booked\t# for booked and ladies");
}

// book a ticket ...
void book_ticket()
{
    char name[30],source[20],destination[20],phno[20],date[20],gender[10];
    int tickets,ticket_no,count=0;
    int arr[32];
    printf("Enter Name:\n");
    scanf("%s",name);
    printf("Enter Source:\n");
    scanf("%s",source);
    printf("Enter Destination:\n");
    scanf("%s",destination);
    printf("Enter Phno:\n");
    scanf("%s",phno);
    printf("Enter Gender:\n");
    scanf("%s",gender);
    printf("Enter Date:\n");
    scanf("%s",date);
    printf("Enter No of Tickets\n");
    scanf("%d",&tickets);
    count=tickets;

    if (tickets>0)
    {
      do
     {
        printf("Enter Ticket No:\n");
        scanf("%d",&ticket_no);
        arr[tickets-1]=ticket_no;
        tickets--;
     } while (tickets<=32 && tickets>0);
    }
    else
    {
        return;
    }
    int total=0;
    if((strcmp(source,"Vijayawada")==0 && strcmp(destination,"Vizag")==0) || (strcmp(destination,"Vijayawada")==0 && strcmp(source,"Vizag")==0))
    {
        total=650*count;
        total=total+total*0.05;
    }
    else if((strcmp(source,"Vijayawada")==0 && strcmp(destination,"Bengalore")==0) || (strcmp(destination,"Vijayawada")==0 && strcmp(source,"Bengalore")==0))
    {
        total=1400*count;
        total=total+total*0.1;
    }
    else if((strcmp(source,"Vijayawada")==0 && strcmp(destination,"Chennai")==0) || (strcmp(destination,"Vijayawada")==0 && strcmp(source,"Chennai")==0))
    {
        total=1000*count;
        total=total+total*0.1;
    }
    else if((strcmp(source,"Guntur")==0 && strcmp(destination,"Rajam")==0)||(strcmp(destination,"Guntur")==0 || strcmp(source,"Rajam")==0))
    {
        total=890*count;
        total=total+total*0.05;
    }
    else
    {
        printf("--Source or Destination MisMatch--");
        return;
    }
   int pay;
   printf("Please Pay(including taxes): %d\n",total);
   scanf("%d",&pay);
   if(pay!=total)
   {
    printf("Sorry Transaction Failed Due to insufficent pay \n P.S (your amount will be refunded if deducted)");
    return;
   }
   printf("************Ticket Details*******************s\n");
   printf("Name: %s \t gender:%s \t Phoneno:%s\t\n",name,gender,phno);
   printf("Source:%s \t Destination:%s \t Date Of Deparrture:%s\n",source,destination,date);
   
   printf("Ticket No's------");
   for(int i=0;i<count;i++)
   {
    printf("%d  ",arr[i]);
   }
   printf("\n----------------\n");
   printf("\nTotal Fare::%d\n\n",total);
   printf("\n************************************\n");
   printf("Have a Safe Journey");
}

// cancel a ticket ...
void cancel_ticket()
{
    char name[30],source[20],destination[20];
    int tickets;
    printf("Enter Name:\n");
    scanf("%s",name);
    printf("Enter Source:\n");
    scanf("%s",source);
    printf("Enter Destination:\n");
    scanf("%s",destination);
    printf("Enter No of Tickets\n");
    scanf("%d",&tickets);
    
    int total=0;
    if((strcmp(source,"Vijayawada")==0 && strcmp(destination,"Vizag")==0) || (strcmp(destination,"Vijayawada")==0 && strcmp(source,"Vizag")==0))
    {
        total=650*tickets;
        total=total*0.80;
    }
    else if((strcmp(source,"Vijayawada")==0 && strcmp(destination,"Bengalore")==0) || (strcmp(destination,"Vijayawada")==0 && strcmp(source,"Bengalore")==0))
    {
        total=1400*tickets;
        total=total*0.75;
    }
    else if((strcmp(source,"Vijayawada")==0 && strcmp(destination,"Chennai")==0) || (strcmp(destination,"Vijayawada")==0 && strcmp(source,"Chennai")==0))
    {
        total=1000*tickets;
        total=total*0.8;
    }
    else if((strcmp(source,"Guntur")==0 && strcmp(destination,"Rajam")==0)||(strcmp(destination,"Guntur")==0 || strcmp(source,"Rajam")==0))
    {
        total=890*tickets;
        total=total*0.75;
    }
    else
    {
        printf("--Source or Destination MisMatch--");
        return;
    }
    
    printf("Amount %d is refunded into your account %s on ticket cancellation\n",total,name);

}

// help function...
void help()
{
    printf("\n *****Contact Deatils**** \n");
    printf("Phno: 89030-00012 \t Email: help_desk@booking.system.com \n");
    printf("For more clarity You can visit our near branches \n");
    printf("Vijayawad \t Vizag\t Bengalore \t Chennai \t");

}
void display_menu(int choice)
{
    if(choice==1)
    {
       printf("\n 1.Fare Chart\n 2.Display Buses\n 3.View Ticket Booking\n 4.Exit \n");
    }
    else
    {
       printf("\n 1.Book a Ticket\n 2.Cancel a Ticket\n 3.Display Buses\n 4.View Ticket Booking\n 5.Help \n 6.Exit \n");
    }
    return;
}
void goto_login_menu()
{
int choice;
    printf("Enter your choice \n");
    scanf("%d",&choice);
    do
    {
        switch (choice)
        {
        case 1:
               book_ticket();
            break;
        case 2:
            cancel_ticket();
            break;
        case 3: display_buses();
            break;
        case 4: view_tickets();
                break;
        case 5: help();
            break;
        case 6:return;
        default: printf("Invalid number");
            break;
        }
        display_menu(2);
        printf("Enter your choice \n");
        scanf("%d",&choice);
    } while (choice!=6);
    return;
}
void user_login()
{
    int count=5;
    char name[30],name1[20];
    printf("Enter User Name \n");
    scanf("%s",name);
    printf("Re-Enter User Name  \n");
    scanf("%s",name1);
    while (strcmp(name,name1)!=0 &&count!=0)
    {
        printf("Login Failed  you have only left %d times\n",count);
        count--;
        printf("Enter User Name \n");
        scanf("%s",name);
        printf("Re-Enter User Name \n");
        scanf("%s",name1);
        if(count==0)
        {
            printf("Try again \n");
            return;
        }
    }
    printf("user successfully logged in");
    display_menu(2);
    goto_login_menu();
}

void goto_admin()
{
    int choice;
    printf("Enter your choice \n");
    scanf("%d",&choice);
    do
    {
        switch (choice)
        {
        case 1:
                fare_chart();
            break;
        case 2: display_buses();
            break;
        case 3: view_tickets();
                break;
        case 4: return;
        default: printf("Invalid number");
            break;
        }
        display_menu(1);
        printf("Enter your choice \n");
        scanf("%d",&choice);
    } while (choice!=4);
    
  return;
}
void admin_login()
{
    int count=2;
    char name[30],password[20];
    printf("Enter Id \n");
    scanf("%s",name);
    printf("Enter Password \n");
    scanf("%s",password);
    while (strcmp(name,"admin")!=0 &&count!=0&& strcmp(password,"admin123") )
    {
        printf("Login Failed  you have only left %d times\n",count);
        count--;
        printf("Enter User Name \n");
        scanf("%s",name);
        printf("Enter Password \n");
        scanf("%s",password);
        if(count==0)
        {
            printf("Try again \n");
            return;
        }
    }
    printf("admin successfully logged in");
    display_menu(1);
    goto_admin();

}
int main()
{
    welcome();
    int logintype;
    printf("  ______Please Login______ \n");
    printf("Enter 1 for user Login \n");
    printf("Enter 2 for admin login\n");
    scanf("%d",&logintype);
    switch(logintype)
    {
        case 1: user_login();
                break;
        case 2:
                admin_login();
                break;
        default: printf("please enter correct choice");
    }
    //system("CLS");
    return 0;
}

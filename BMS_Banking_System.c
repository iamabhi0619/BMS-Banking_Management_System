#include <stdio.h>
#include <time.h> //time
#include <stdlib.h> //exit, system()
// #include <conio.h> //getch

char name[20];
int total=10000, account_number;

void main_menu();
void divider();
void deposite_to_bank();
void withdraw_from_bank();
void transfer_between_bank();
void see_account_details();
void see_transation();

int main() {
    int choice;

    printf("Enter Your Name:- ");
    gets(name);

    printf("Enter Your Account Number:- ");
    scanf("%d",&account_number);
    while (1)
    {
        main_menu();

        printf("Enter Your INPUT:- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            system("clear");
            deposite_to_bank();
            break;
        case 2:
            system("clear");
            withdraw_from_bank();
            break;
        case 3:
            system("clear");
            transfer_between_bank();
            break;
        case 4:
            system("clear");
            see_account_details();
            break;
        case 5:
            system("clear");
            see_transation();
            break;
        case 6:
            exit(0);
            break;
        default:
            printf("Required VALID INPUT\n");
            break;
        }
    }
    
    
    return 0;
}

void main_menu(){
    printf("HOME PAGE\n");
    printf("1~~~/- Deposite TO Bank -/~~~\n");
    printf("2~~~/- Withdraw FROM Bank -/~~~\n");
    printf("3~~~/- Transfer Between Bank -/~~~\n");
    printf("4~~~/- See Account Details -/~~~\n");
    printf("5~~~/- See Transation -/~~~\n");
    printf("6~~~/- EXIT -/~~~\n");
}

void divider()
{
    for (int i = 0; i < 50; i++)
    {
        printf("-");
    }
    printf("\n");
}

void deposite_to_bank() {
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account_details.txt", "a");
    int deposit_amount;

    printf("DEPOSITING MONEY\n");
    divider();
    printf("Enter Amount to be Deposited: ");
    scanf("%d", &deposit_amount);

    total += deposit_amount;
    printf("%d Amount Deposited Successfully...!!!\n", deposit_amount);
    printf("Current Amount: Rs%d\n", total);

    fprintf(ptr, "C\t%s \tRs%d/- has been deposited, Total Balance: Rs%d/-\n", ctime(&tm), deposit_amount, total);
    fclose(ptr);
    getchar();
}

void withdraw_from_bank(){
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account_details.txt", "a");
    int withdraw_amount;

    printf("WITHDRAW MONEY\n");
    divider();
    printf("Enter Amount Want to WITHDRAW:- ");
    scanf("%d", &withdraw_amount);
    if (withdraw_amount>total)
    {
        printf("INSUFFICIENT BALANCE\n");
    }
    else{
        total -= withdraw_amount;
        printf("%d Amount Withdraw Successfully...!!!\n", withdraw_amount);
        printf("Current Amount: Rs%d\n", total);

        fprintf(ptr, "D\t%s \tRs%d/- has been withdraw, Total Balance: Rs%d/-\n", ctime(&tm), withdraw_amount, total);
        fclose(ptr);
    }
    getchar();
}

void transfer_between_bank(){
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account_details.txt", "a");
    int transfer_amount, taccount_number;

    printf("TRANSFER MONEY\n");
    divider();
    printf("Plese Enter the account number where you want to transfer Money:-\n");
    scanf("%d", &taccount_number);
    printf("Enter Amount Want to TRANSFER:- ");
    scanf("%d", &transfer_amount);
    if (transfer_amount>total)
    {
        printf("INSUFFICIENT BALANCE\n");
    }
    else{
        total -= transfer_amount;
        printf("%d Amount Transfered Successfully...!!!\n", transfer_amount);
        printf("Amount Transfered on Account No.:- %d",taccount_number);
        printf("Current Amount:- Rs%d\n", total);

        fprintf(ptr, "D\t%s \tRs%d/- has been Transfered to Account No.-%d, Total Balance: Rs%d/-\n", ctime(&tm), transfer_amount, taccount_number, total);
        fclose(ptr);
    }
}

void see_account_details(){
    printf("ACCOUNT DETAILS\n");
    divider();
    printf("\nName:- %s\n",name);
    printf("Account Number:- %d\n",account_number);
    printf("Balance:- %d\n",total);
    getchar();
}

void see_transation(){
    FILE *ptr = fopen("Account_details.txt", "r");

    char c = fgetc(ptr);
    if (c == EOF)
    {
        printf("No Transition");
    }
    else{
        printf("TRANSITION DETAILS\n");
        divider();
        while (c!=EOF)
        {
            printf("%c",c);
            c = fgetc(ptr);
        }
        
    }
}
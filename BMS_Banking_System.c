#include <stdio.h>
#include <time.h> //time
#include <stdlib.h> //exit, system()
#include <string.h>
// #include <conio.h> //getch

typedef struct customer
{
    int account_number;
    int balance;
    char name[20];
    char gender;
    char address[50];
}customer;
char name[20];
int total=10000, account_number;

void clearBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}
void main_menu();
void divider();
void deposite_to_bank();
void withdraw_from_bank();
void transfer_between_bank();
void see_account_details();
void see_transation();
void create_account();
void Account_Find();

//Global Variable declear
struct customer cust;

int main() {
    int choice;
    while (1) {
        Account_Find();
        int inner = 0;
        while (inner == 0)
        {
            main_menu();
            printf("Enter Your INPUT:- ");
            scanf("%d", &choice);

            switch (choice) {
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
                create_account();
                break;
            case 7:
                inner = 1;
                break;
            case 0:
                exit(0);
            default:
                printf("Required VALID INPUT\n");
                break;
            }
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
    printf("6~~~/- Create An Account -/~~~\n");
    printf("7~~~/- EXIT -/~~~\n");
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
    
    //char file_name[10] =  (char)cust.account_number+".txt";
    time_t tm;
    time(&tm);
    FILE *ptr = fopen("Account_details.txt", "a");
    int deposit_amount;

    printf("DEPOSITING MONEY\n");
    divider();
    printf("Enter Amount to be Deposited: ");
    scanf("%d", &deposit_amount);

    cust.balance += deposit_amount;
    printf("%d Amount Deposited Successfully...!!!\n", deposit_amount);
    printf("Current Amount: Rs%d\n", cust.balance);

    fprintf(ptr, "C\t%s \tRs%d/- has been deposited, Total Balance: Rs%d/-\n", ctime(&tm), deposit_amount, cust.balance);
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
    if (withdraw_amount>cust.balance)
    {
        printf("INSUFFICIENT BALANCE\n");
    }
    else{
        cust.balance -= withdraw_amount;
        printf("%d Amount Withdraw Successfully...!!!\n", withdraw_amount);
        printf("Current Amount: Rs%d\n", cust.balance);

        fprintf(ptr, "D\t%s \tRs%d/- has been withdraw, Total Balance: Rs%d/-\n", ctime(&tm), withdraw_amount, cust.balance);
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
    printf("\nName:- %s\n",cust.name);
    printf("Account Number:- %d\n",cust.account_number);
    printf("Balance:- %d\n",cust.balance);
    printf("Gender:- %c\n",cust.gender);
    printf("Address:- %s\n",cust.address);
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

void create_account(){
    customer c;

    FILE *fp = fopen("list.txt", "a");
    if (fp == NULL) {
        printf("Error opening the file.\n");
        return;
    }

    clearBuffer();

    printf("Enter Name: ");
    fgets(c.name, sizeof(c.name), stdin);
    c.name[strcspn(c.name, "\n")] = '\0';  // Remove the newline character
    // clearBuffer();
    
    printf("Please Enter gender: ");
    scanf(" %c", &c.gender);
    clearBuffer();

    printf("Please Enter the address: ");
    fgets(c.address, sizeof(c.address), stdin);
    c.address[strcspn(c.address, "\n")] = '\0';  // Remove the newline character

    printf("Please Enter the Deposit Amount: ");
    if (scanf("%d", &c.balance) != 1) {
        printf("Invalid input for deposit amount.\n");
        fclose(fp);
        return;
    }
    clearBuffer();

    // Generating a random Account number
    srand(time(NULL));
    int randomNumber = rand() % 900 + 100;  // 3 digit random number
    int ac = (121 * 1000) + randomNumber;    // Fixing the first 3 digits
    c.account_number = ac;

    // fprintf(fp, "%d\n%d\n%s\n%c\n%s\n\n", c.account_number, c.balance, c.name, c.gender, c.address);
    fwrite(&c,sizeof(c),1,fp);
    fclose(fp);
    printf("Account Created Sucessfully..!!\n");
    divider();
    printf("\nName:- %s\n",c.name);
    printf("Account Number:- %d\n",c.account_number);
    printf("Balance:- %d\n",c.balance);
    printf("Gender:- %c\n",c.gender);
    printf("Address:- %s\n",c.address);
    divider();
}

void Account_Find(){
    struct customer c1;
    int account_number, flag=0;
    FILE *fp;
    fp = fopen("list.txt","rb");
    int account_search = 121;

    do
    {
        printf("/--Enter 121 to create Account--/");
        printf("Enter Account Number:- ");
        scanf("%d",&account_number);
        if (account_number == 0)
        {
            create_account();
            exit(0);
        }
        
        while (fread(&c1,sizeof(c1),1,fp)>0 && flag == 0)
        {
            if(c1.account_number == account_number)
            {
                flag = 1;
                printf("Account Found \n WELCOME TO AK BANK\n");
                divider();
                cust = c1;
                account_search = 1;
            }
        }
        if(flag == 0)
        {
            printf("Not Found");
        }
    } while (account_search == 0);
    
    
    fclose(fp);
}
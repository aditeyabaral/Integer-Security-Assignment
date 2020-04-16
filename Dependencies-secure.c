#include "header.h"
ACCOUNT* init(int *pos)
{
    *pos = 0;
    FILE* fp = fopen("Database.dat","r");
    if (fp==NULL)
        return NULL;
    else
    {
        ACCOUNT temp;
        while (fread(&temp,sizeof(ACCOUNT),1,fp))
        {
            accounts[*pos] = temp;
            (*pos)++;
        }
        fclose(fp);
        if(*pos==0)
            return NULL;
        else
            return accounts;
    }
}
void display_account(ACCOUNT* account)
{
    printf("\nUsername: %s\n",account->username);
    printf("Password: %s\n",account->password);
    printf("Balance: %d\n",account->balance);
    printf("Stocks: %d\n",account->stock);
}
void display(ACCOUNT* account)
{
    for(int i=0;i<N;i++)
    {
        printf("\nUsername: %s\n",account[i].username);
        printf("Password: %s\n",account[i].password);
        printf("Balance: %d\n",account[i].balance);
        printf("Stocks: %d\n\n",account[i].stock);
    }
}
void register_account()
{
    printf("\nEnter username: ");
    scanf("%s",accounts[N].username);
    printf("Enter password: ");
    scanf("%s",accounts[N].password);
    printf("Enter balance: ");
    scanf("%d",&accounts[N].balance);
    accounts[N].stock = 0;
    current = &accounts[N];

    FILE* fp = fopen("Database.dat","a");
    fwrite(&accounts[N],sizeof(ACCOUNT),1,fp);
    fclose(fp);

    N++;
}
void login()
{
    char user[20];
    char passw[20];
    printf("\nEnter username: ");
    scanf("%s",user);
    printf("Enter password: ");
    scanf("%s",passw);
    bool found = false;
    for(int i=0;i<N;i++)
    {
        if(!strcmp(accounts[i].username,user) && !strcmp(accounts[i].password,passw))
        {
            current = &accounts[i];
            found = true;
            break;
        }
    }
    if(!found)
    {
        printf("\nInvalid details. Try Again!\n\n");
        free(accounts);
        main();
    }
    else
        printf("\nYou have logged in!\n\n");
}
void activity()
{
    int choice,s,total;
    char ch;
    while(true)
    {
        printf("1. Check Account Balance\n2. Buy Stocks\n3. Exit\nEnter choice: ");
        scanf("%d",&choice);
        printf("\n");
        if (choice==1)
            printf("Current balance: Rs %d\n",current->balance);
        else if (choice==2)
        {
            printf("How many stocks do you want to buy? ");
            scanf("%d",&s);
            total = s*1000;
            if(s>INT_MAX || total<0)
            {
                printf("Cannot provide so many flags! Please choose a smaller quantity.\n\n");
                continue;
            }
            if (total>current->balance)
            {
                printf("Your balance is too low! Please purchase lesser flags!\n\n");
                continue;
            }
            printf("Total cost: Rs %d\n",total);
            printf("Transaction successful!\n");
            current->stock+=1;
            current->balance-=total;
            printf("Current balance: Rs %d\n",current->balance);
            update();
        }
        else if (choice==3)
        {
            free(accounts);
            main();
        }
        else
            printf("\nInvalid choice! Try again.\n");
        printf("\n");
    }
}
void update()
{
    FILE* fp = fopen("Database.dat","w");
    for(int i=0;i<N;i++)
        fwrite(&accounts[i],sizeof(ACCOUNT),1,fp);
    fclose(fp);
}

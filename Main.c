#include "header.h"
int main()
{
    accounts = (ACCOUNT*)malloc(sizeof(ACCOUNT)*10000);
    current = NULL;
    init(&N);
    flag = false;
    if (N!=0)
        flag = true;
    printf("1. Register\n2. Login\n3. Exit\nEnter choice: ");
    int choice;
    scanf("%d",&choice);
    if(choice==1)
    {
        register_account();
        printf("\nYou have registered successfully!\n\n");
        activity();
    }
    else if (choice==2 && flag)
    {
        login();
        activity();
    }
    else if (choice==3)
    {
        printf("Thank you!\n");
        exit(0);
    }
    else
    {
        printf("Invalid choice. Try Again!\n");
        free(accounts);
        main();
    }
}
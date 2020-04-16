#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <limits.h>
struct account
{
    char username[20];
    char password[20];
    int balance;
    int stock;
};
typedef struct account ACCOUNT;
int main();
ACCOUNT* init(int*);
void display_account(ACCOUNT*);
void display(ACCOUNT*);
void login();
void register_account();
void activity();
void update();
int N;
bool flag;
ACCOUNT* accounts;
ACCOUNT* current;
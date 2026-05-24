#include <stdio.h>
#include <string.h>
#include "info_struct.h"

int main(void)
{
    char masterPass[100];
    const char *master = "master.txt";
    char MainPass[100];

    FILE *masterTxt = fopen(master, "r");
    if (!masterTxt)
    {
        masterTxt = fopen(master, "w");
        if (!masterTxt)
        {
            printf("Error Opening File.\n");
            return 1;
        }
        printf("Please Set a Main Password: ");
        scanf("%99s", masterPass);

        fprintf(masterTxt, "%s\n", masterPass);
        fclose(masterTxt);
        printf("Password set successfully!");
    }
    else
    {
        fclose(masterTxt);
    }

    
    printf("Please Enter the Main Password: ");
    scanf("%99s", MainPass);

    masterTxt = fopen(master, "r");
    fscanf(masterTxt, "%99s", masterPass);
    fclose(masterTxt);

    if (strcmp(masterPass, MainPass) != 0)
    {
        printf("Incorrect Password, please try again. ");
        
    }
    else
    {
        int code = 0;
        printf("Enter the associated number to the option you would like.");
        printf("\n(1) View Passwords\n(2) Add Passwords\n(3) Set a New Main Password\n(4) Exit\n");
        scanf("%d", &code);
        
        Password account;
        const char *pass = "passwords.txt";
        switch(code)
        {
            case 1:
            {
                FILE *subPasswords = fopen(pass, "r");
                if (!subPasswords)
                {
                    printf("No Passwords Saved Yet.");
                    fclose(subPasswords);
                    return 1;
                }
                else
                {
                    while(fscanf(subPasswords, "%99s %99s", account.email, account.password) != EOF)
                    {
                        printf("email: %s\n", account.email);
                        printf("password: %s\n", account.password);
                        printf("----------------------------------------------------------\n");
                    }
                    fclose(subPasswords);
                    return 1;
                }
            }
            case 2:
            {
                printf("Enter email: ");
                scanf("%s", &account.email);
                printf("\nEnter associated password:");
                scanf("%s", &account.password);
                printf("----------------------------------------------------------\n");
                FILE *subPasswords = fopen(pass,"a");
                fprintf(subPasswords, "%s %s\n", account.email, account.password);
                fclose(subPasswords);
                return 1;
            }
            case 3:
            {
                char newMain[100];
                FILE *masterTxt = fopen(master, "w");
                if (!masterTxt)
                {
                    printf("Error Opening File.\n");
                    return 1;
                }
                printf("Please Set a New Main Password: ");
                scanf("%99s", newMain);
                
                fprintf(masterTxt, "%s\n", newMain);
                fclose(masterTxt);
                printf("Password set successfully!");
                return 1;
            }
            case 4:
            {
                return 1;
            }
        }
    }
    return 1;
}
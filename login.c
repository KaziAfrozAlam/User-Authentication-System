#include <stdio.h>
#include <string.h>
#include <stdlib.h>


#define MAX_LEN_user_name 30
#define MAX_LEN_passwd 20


struct login                           
{
    char f_name[MAX_LEN_user_name];
    char l_name[MAX_LEN_user_name];
    char user_name[MAX_LEN_user_name];
    char passwd[MAX_LEN_passwd];
};

int  enter_login (void);
void registrartion (void);
void clear_input_stream() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}
}
int  get_choice(void){
    int d = 0;
    printf("\n1. Register\n2. Login\n3. Logout\n4. Exit");
    printf("\nENTER YOUR CHOICE: ");
    fflush(stdin);
    scanf("%d",&d);
    return d;
}

int main (void)
{
    int option;
    int logout_mask = 7;
    do {
        option = get_choice();
        if (3 == option) {
            logout_mask = 7;
        }
        option = option & logout_mask;
        
        switch (option)
        {
        case 0: {
            printf("Please logout .. Press any key to return to the main menu..\n");
            clear_input_stream();
            getchar();
            break;
        }
        case 1: {
            registrartion();
            printf("Redirecting to the Login Page ..Press any key to continue...");
            clear_input_stream();
            getchar();
            logout_mask = enter_login();
            break;
        }

        case 2: {

            logout_mask = enter_login();
            break;
        }
        case 3: {
            printf("Press any key to Log out from the System ....\n");
            clear_input_stream();
            getchar();
            logout_mask = 7;
            break;
        }
        case 4:
            printf("Exit from the program..\n");
            break;

        default: {
               printf("Not a valid choice..Return to main menu \n\n");
               clear_input_stream();
               getchar();
        }
        }
    } while(option != 4);

    return 0;
}

int enter_login (void)
{
    char user_name[MAX_LEN_user_name],passwd[MAX_LEN_passwd];
    FILE *log;
    

    log = fopen("passwd.txt","r");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }

    struct login l;

    clear_input_stream();
    printf("Please Enter your login credentials below\n\n");
    printf("user_name:  ");
    scanf("%s", user_name);
    printf("passwd: ");
    scanf("%s",passwd);

    while(fread(&l,sizeof(l),1,log))
        {
        if(strcmp(user_name,l.user_name)==0 && strcmp(passwd,l.passwd)==0)

            {   
                printf("\nSuccessful Login\n");
                return 0;
            }
        else 
            {
                printf("\nIncorrect Login Details\nPlease enter the correct credentials\n");
 
            }
        }

    fclose(log);

    return 7;
}




void registrartion(void)
{
    char firstname[15];
    FILE *log;
    clear_input_stream();
    log=fopen("passwd.txt","w");
    if (log == NULL)
    {
        fputs("Error at opening File!", stderr);
        exit(1);
    }


    struct login l;
 
    printf("\nWelcome to your online course provider. We need to enter some details for registration.\n\n");
    printf("\nEnter First Name:\n");
    scanf("%s",l.f_name);
    printf("\nEnter Surname:\n");
    scanf("%s",l.l_name);

    printf("Thank you.\nNow please choose a user_name and passwd as credentials for system login.\nEnsure the user_name is no more than 30 characters long.\nEnsure your passwd is at least 8 characters long and contains lowercase, uppercase, numerical and special character values.\n"); 

    printf("\nEnter user_name:\n");
    scanf("%s",l.user_name);
    printf("\nEnter passwd:\n");
    scanf("%s",l.passwd);
    fwrite(&l,sizeof(l),1,log);
    fclose(log);

    printf("\nConfirming details...\n...\nWelcome, %s!\n\n",firstname);
    printf("\nRegistration Successful!\n");
    
}

#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define MAX_USERNAME_LEN 25
#define MAX_PASSWORD_LEN 25
#define MAX_EMAIL_LEN 30
#define MAX_PHONE_LEN 15

struct User {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];
};

int i;
int user_count = 0;
//Numbers of users are 100
struct User users[100];

bool valid_username(char* username)
{
    for (i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username) == 0)
        {
            return false;
        }
    }
    return true;
}

bool valid_verification_code(int code)
{
    bool ret_val = false;
    //Code to validate the verification code
    return ret_val;
}

void send_verification_code(char* email, char* phone)
{
    // Code to send the verification code to email and phone
}

void register_user()
{
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char email[MAX_EMAIL_LEN];
    char phone[MAX_PHONE_LEN];

    printf("Enter a new username: ");
    scanf("%s", &username);
    if (!valid_username(username))
    {
        printf("This username is already taken.\n");
        return;
    }

    printf("Enter a new password: ");
    scanf("%s", &password);

    printf("Enter your email: ");
    scanf("%s", &email);

    printf("Enter your phone number: ");
    scanf("%s", &phone);

    send_verification_code(email, phone);

    int verification_code;
    printf("Enter the verification code sent to your email and phone: ");
    scanf("%d", &verification_code);
    if (!valid_verification_code(verification_code))
    {
        printf("Invalid verification code.\n");
        return;
    }

    struct User new_user;
    memcpy(new_user.username,username, MAX_USERNAME_LEN);
    memcpy(new_user.password, password, MAX_PASSWORD_LEN);
    memcpy(new_user.email, email, MAX_EMAIL_LEN);
    memcpy(new_user.phone,phone, MAX_PHONE_LEN);

    users[user_count++] = new_user;
    printf("Registration successful!\n");
}
bool valid_credentials(char* username, char* password)
{
    for (i = 0; i < user_count; i++)
    {
        if (strcmp(username, users[i].username) == 0 &&
            strcmp(password, users[i].password) == 0)
        {
            return true;
        }
    }
    return false;
}

void login()
{
    char username[MAX_USERNAME_LEN], password[MAX_PASSWORD_LEN];
    int tries = 3;

    printf("Enter username: ");
    scanf("%s", &username);

    while (tries > 0)
    {
        printf("Enter password: ");
        scanf("%s", &password);

        if (valid_credentials(username, password))
        {
            printf("Access granted!\n");
            return;
        }
        else
        {
            printf("Access denied. %d tries left.\n", --tries);
        }
    }
    printf("You have run out of tries. Access denied.\n");
}


int main() {
    login();
    return 0;
}

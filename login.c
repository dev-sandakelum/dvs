#include <stdio.h>
#include <string.h>


int login_user() {
    char nic[20];
    char password[20];
    int attempts = 3;

    while (attempts > 0) {
        top_bar();
        printf("| USER LOGIN -------------------------\n");

        color_text(2);
        printf("Enter NIC Numer: %s",nic);
        printf("Enter Password: %s",password);
        color_text(0);

        
        if (strcmp(nic, "123456789123") == 0 && strcmp(password, "pass123") == 0) {
            printf("\nLogin successful! Welcome, %s.\n", nic);
            return 1;
        } else {
            attempts--;
            printf("\nIncorrect username or password. You have %d attempts remaining.\n", attempts);
        }
    }

    printf("\nToo many failed attempts. Exiting.\n");
    return 0;
}

// Main function
int main() {
    if (login_user()) {
    
        printf("Access granted to the system.\n");
    } else {
        printf("Access denied.\n");
    }

    return 0;
}


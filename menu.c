#include <stdio.h>
#include <stdlib.h> // Add this line for atoi
#include <string.h>

// global variables
char *err ;

int clear_screen() {
    if (system("ver") == 0) {
        system("cls");
    } else {
        system("clear");
    }
}

int error_message(char *err) {
    if (err) {
        printf("----------------------------------------\n");
        printf("%s\n", err);
        printf("----------------------------------------\n");
    }
}

int top_bar(){

    clear_screen();
    printf("\n========================================\n");
    printf("SRI LANKA PARLIAMENTARY ELECTION SYSTEM\n");
    printf("----------------------------------------\n");
}

int register_user() {
    err = NULL;
    int exit;
    top_bar();
    printf("| REGISTRATION -------------------------\n");

    // Get user details
    printf("  Enter your name: ");
    char name[100];
    scanf("%s", &name);

    // Get NIC number & validate
    while(1){
        error_message(err);
        printf("  Enter your NIC number: ");
        char nic[20];
        scanf("%s", &nic);
        if (strlen(nic) != 12) {
            err = "Invalid NIC number.\nPlease enter a 12-digit NIC number.";
            continue;
        }else{
            printf("\n| ELIGIBILITY -------------------------\n");
            printf("  Enter your year of birth (YYYY): ");
            char dob[5];
            scanf("%s", &dob);
            int birth_year = atoi(dob);
            int age = 2025 - birth_year;
            if (age >= 18) {   
                err = "Registration successful.";
                error_message(err);
                printf("Press any key to return to menu: ");
                char dummy;
                scanf(" %c", &dummy);
                break;
            } else {
                err = "User is not eligible to register.";
                error_message(err);
                printf("Press any key to return to menu: ");
                char dummy;
                scanf(" %c", &dummy);
                return 0;
            }
        }
    }
    return 1;
}

int main() {
    while(1){
        int choice;
        top_bar();
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Vote\n");
        printf("4. View Results\n");
        printf("0. Exit\n");
        printf("========================================\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        int key_return = 0;
        switch (choice) {
            case 1:
                printf("Login selected.\n");
                break;
            case 2:
                register_user();
                break;
                    
            case 3:
                printf("Vote selected.\n");
                break;
            case 4:
                printf("View Results selected.\n");
                break;
            case 0:
                printf("Exiting...\n");
                key_return = 5;
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
        if (key_return == 1) {
            printf("========================================\n");
            printf("You must be at least 18 years old\n");
            printf("========================================\n");
            
        }else if(key_return == 5){
            printf("========================================\n");
            printf("Successfully exited\n");
            printf("========================================\n");
            break;
        }
    }
    return 0;
}

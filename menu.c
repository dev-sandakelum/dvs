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

int lines(int type) {
    if(type == 1){
        printf("----------------------------------------\n");
    }else if (type == 2) {
        printf("\n----------------------------------------\n");
    }else if (type == 3) {
        printf("========================================\n");
    }else if (type == 4) {
        printf("\n========================================\n");
    }
}

int exit_to() {
    printf("Press any key to return to menu: ");
    char temp;
    scanf(" %c", &temp);
}

int error_message(char *err) {
    if (err) {
        lines(1);
        printf("%s\n", err);
        lines(1);
    }
}

int top_bar(){

    clear_screen();
    lines(4);
    printf("SRI LANKA PARLIAMENTARY ELECTION SYSTEM\n");
    lines(1);
}

int register_user() {
    err = NULL;
    //new variables
    int exit;
    char nic[20];
    char name[100];
    int dob , age;
    char password[20] , confirm_password[20];
    int section = 1;

    while(section != 0){
        top_bar(); //insert top bar
        printf("| REGISTRATION -------------------------\n");

        if(section == 1){
            // Get user details
            printf("  Enter your name: ");
            scanf("%s", &name);

            // Get NIC number & validate
            while(1){
                error_message(err);
                printf("  Enter your NIC number: ");
                scanf("%s", &nic);
                if (strlen(nic) != 12) {
                    err = "Invalid NIC number.\nPlease enter a 12-digit NIC number.";
                    continue;
                }else{
                    //DOB check but,only using birth year yet
                    printf("\n| ELIGIBILITY -------------------------\n");
                    printf("  Enter your year of birth (YYYY): ");
                    scanf("%d", &dob);
                    age = 2025 - dob;
                    if (age >= 18) {
                        section = 2;
                        break;
                    } else {
                        err = "User is not eligible to register.";
                        error_message(err);
                        exit_to();
                        break;
                    }
                }
            }
        }
        else if(section == 2){

            lines(1);
            printf("You are eligible to register.\n");
            lines(1);
            printf("User name: %s\n", name);
            printf("NIC number: %s\n", nic);
            lines(3);

            // password
            printf("  Enter your password: ");
            scanf("%c", password);
            printf("  Confirm your password: ");
            scanf("%c", confirm_password);

            if (password != confirm_password) {
                err = "Passwords do not match.";
                error_message(err);
            
                lines(1);
                printf("Error: Password attempts exceeded. \nExiting after 1 failed tries.\n");
                lines(3);
                exit_to();
                break;
            }
        }
        
    }
        return 1;
}

int main() {
    while(1){
        int choice , key_return = 0;
        top_bar();
        printf("1. Login\n");
        printf("2. Register\n");
        printf("3. Vote\n");
        printf("4. View Results\n");
        printf("0. Exit\n");
        lines(3);
        printf("Enter your choice: ");
        scanf("%d", &choice);

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
       
        if(key_return == 5){
            lines(3);
            printf("Successfully exited\n");
            lines(3);
            break;
        }
    }
    return 0;
}

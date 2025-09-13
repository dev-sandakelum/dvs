#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Global variables
char *err;

int clear_screen() {
    if (system("ver") == 0) {
        system("cls");
    } else {
        system("clear");
    }
    return 0;
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
    return 0;
}

int exit_to() {
    printf("Press any key to return to menu: ");
    char temp;
    scanf(" %c", &temp);
    return 0;
}

int error_message(char *err) {
    if (err) {
        lines(1);
        printf("%s\n", err);
        lines(1);
    }
    return 0;
}

int top_bar(){
    clear_screen();
    lines(4);
    printf("SRI LANKA PARLIAMENTARY ELECTION SYSTEM\n");
    lines(1);
    return 0;
}

int success_message(char *message) {
    lines(1);
    printf("SUCCESS: %s\n", message);
    lines(1);
    return 0;
}

int login_user() {
    err = NULL;
    char nic[20];
    char password[20];
    
    top_bar();
    printf("| LOGIN -------------------------------\n");
    
    printf("  Enter your NIC number: ");
    scanf("%s", nic);
    
    printf("  Enter your password: ");
    scanf("%s", password);
    
    lines(2);
    printf("Login functionality not yet implemented.\n");
    lines(3);
    exit_to();
    
    return 0;
}

int register_user() {
    err = NULL;
    char nic[20];
    char name[100];
    int dob, age;
    char password[20], confirm_password[20];
    int section = 1;

    while(section != 0){
        top_bar();
        printf("| REGISTRATION -------------------------\n");

        if(section == 1){
            // Get user details
            printf("  Enter your name: ");
            scanf("%s", name);

            // Get NIC number & validate
            while(1){
                error_message(err);
                printf("  Enter your NIC number: ");
                scanf("%s", nic);
                if (strlen(nic) != 12) {
                    err = "Invalid NIC number.\nPlease enter a 12-digit NIC number.";
                    continue;
                }else{
                    // DOB check
                    printf("\n| ELIGIBILITY -------------------------\n");
                    printf("  Enter your year of birth (YYYY): ");
                    scanf("%d", &dob);
                    age = 2025 - dob;
                    if (age >= 18) {
                        section = 2;
                        break;
                    } else {
                        err = "User is not eligible to register.\nMinimum age requirement is 18 years.";
                        error_message(err);
                        lines(3);
                        exit_to();
                        section = 0;
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
            printf("Age: %d years\n", age);
            lines(1);

            // Password section
            printf("| PASSWORD SETUP ----------------------\n");
            printf("  Enter your password: ");
            scanf("%s", password);
            printf("  Confirm your password: ");
            scanf("%s", confirm_password);

            if (strcmp(password, confirm_password) != 0) {
                err = "Passwords do not match.\nPlease try again.";
                error_message(err);
                lines(1);
                printf("Registration failed due to password mismatch.\n");
                lines(3);
                exit_to();
                section = 0;
            } else {
                // Registration successful
                lines(2);
                success_message("Registration completed successfully!");
                printf("Welcome to the Sri Lanka Parliamentary Election System, %s!\n", name);
                lines(3);
                exit_to();
                section = 0;
            }
        }
    }
    return 0;
}

int vote_user() {
    top_bar();
    printf("| VOTING -------------------------------\n");
    lines(2);
    printf("Voting functionality not yet implemented.\n");
    printf("This section will allow registered users to cast their votes.\n");
    lines(3);
    exit_to();
    return 0;
}

int view_results() {
    top_bar();
    printf("| ELECTION RESULTS ---------------------\n");
    lines(2);
    printf("Results viewing functionality not yet implemented.\n");
    printf("This section will display current election results.\n");
    lines(3);
    exit_to();
    return 0;
}

int main() {
    while(1){
        int choice;
        int key_return = 0;
        
        top_bar();
        printf("| MAIN MENU ----------------------------\n");
        printf("  1. Login\n");
        printf("  2. Register\n");
        printf("  3. Vote\n");
        printf("  4. View Results\n");
        printf("  0. Exit\n");
        lines(3);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                login_user();
                break;
            case 2:
                register_user();
                break;
            case 3:
                vote_user();
                break;
            case 4:
                view_results();
                break;
            case 0:
                top_bar();
                printf("| EXIT ---------------------------------\n");
                lines(2);
                printf("Thank you for using Sri Lanka Parliamentary Election System!\n");
                printf("Goodbye!\n");
                lines(3);
                key_return = 1;
                break;
            default:
                top_bar();
                printf("| ERROR --------------------------------\n");
                error_message("Invalid choice. Please select a valid option (0-4).");
                lines(3);
                exit_to();
                break;
        }
       
        if(key_return == 1){
            break;
        }
    }
    return 0;
}
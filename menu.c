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
int color_text (int color) {
    if (color == 0) {
        // white
        printf("\033[0;37m");
    }else if(color == 1){
        // Red
        printf("\033[0;31m");
    }else if (color == 2) {
        // Green    
        printf("\033[0;32m");
    }else if (color == 3) {
        // Blue
        printf("\033[0;34m");
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
    char nic[20] = "";
    char name[100];
    int dob , age ,nic_attempt = 0 ,pass_attempt = 0;
    char password[20], confirm_password[20];
    int section = 1 ,sec = 0;
        // sec 0 -> name section
        // sec 1 -> nic section
        // sec 2 -> DOB section
        // sec 3 -> password section

    while(1){
        top_bar();
        printf("| REGISTRATION -------------------------\n");

        color_text(2);
        printf("Name: %-14s     attempt: %d/3\n", name, nic_attempt );
        printf("NIC: %-12s          age: %d\n", nic, age );
        color_text(0);
        
        lines(1);
        if(sec == 0) {
            printf("  Enter your name: ");
            scanf("%s", &name);
            sec = 1;
            continue;
        }

        
        // Get NIC number & validate
        if(nic_attempt < 3){
            if(sec == 1 ){
                color_text(1);
                error_message(err);
                color_text(0);

                printf("  Enter your NIC number: ");
                scanf("%s", nic);
                if (strlen(nic) != 12) {
                    nic_attempt++;
                    err = "Invalid NIC number.\nPlease enter a 12-digit NIC number.";
                    continue;
                }else if(strlen(nic) == 12){
                    sec = 2;
                    continue;
                }
            }
        }else{
            exit_to();
            break;
        }
        
        if(sec == 2){                // DOB check
            printf("\n| ELIGIBILITY -------------------------\n");
            printf("  Enter your year of birth (YYYY): ");
            scanf("%d", &dob);
            age = 2025 - dob;
            if (age >= 18) {
                sec = 3;
                nic_attempt = 0;
                continue;
            } else {
                err = "User is not eligible to register.\nMinimum age requirement is 18 years.";
                color_text(1);
                error_message(err);
                color_text(0);
                lines(3);
                exit_to();
                section = 0;
                break;
            }
        }
                        
        if(sec == 3){
            color_text(2);
            if(pass_attempt == 0){
                err ="You are eligible to register.";
                error_message(err);
            }else{
                color_text(1);
                lines(1);
                printf("Passwords do not match.\nPlease try again. \tattempt: %d/3\n" ,pass_attempt);
                lines(1);
                color_text(0);
                
            }
            
            color_text(0);
            lines(1);


            // Password section
            printf("| PASSWORD SETUP ----------------------\n");

            printf("  Enter your password: ");
            scanf("%s", password);
            printf("  Confirm your password: ");
            scanf("%s", confirm_password);
            
            if(pass_attempt < 4){
                if (strcmp(password, confirm_password) != 0) {
                    pass_attempt++;
                    lines(1);
                    printf("Registration failed due to password mismatch.\n");
                    lines(3);
                    continue;
                } else {
                    // Registration successful
                    lines(2);
                    color_text(2);
                    success_message("Registration completed successfully!");
                    printf("Welcome to \nThe Sri Lanka Parliamentary \nElection System, %s!\n", name);
                    color_text(0);
                    lines(3);
                    exit_to();
                    break;
                }
            }else{
                lines(1);
                printf("Registration failed due to password mismatch.\n");
                lines(3); 
                exit_to();
                break;
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
    color_text(0);
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
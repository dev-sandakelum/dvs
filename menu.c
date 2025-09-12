#include <stdio.h>
#include <stdlib.h> // Add this line for atoi

int clear_screen() {
    if (system("ver") == 0) {
        system("cls");
    } else {
        system("clear");
    }
}
int top_bar(){

    clear_screen();
    printf("\n========================================\n");
    printf("SRI LANKA PARLIAMENTARY ELECTION SYSTEM\n");
    printf("----------------------------------------\n");
}

int register_user() {
    top_bar();
    printf("| REGISTRATION -------------------------\n");
    printf("  Enter your name: ");
    char name[100];
    scanf("%s", &name);
    printf("  Enter your NIC number: ");
    char nic[20];
    scanf("%s", &nic);

    printf("\n| ELIGIBILITY -------------------------\n");
    printf("  Enter your year of birth (YYYY): ");
    char dob[5];
    scanf("%s", &dob);

    if (atoi(dob) <= (2025-18)) {
        printf("User is eligible to register.\n");
        printf("User registered successfully.\n");

        return 0;
    } else {
        printf("User is not eligible to register.\n");
        return 1; //exit
    }
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
                while(key_return == 0) {
                    int x  = register_user();
                    key_return = x;
                }
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
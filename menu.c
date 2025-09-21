#include <stddef.h>

int main_menu(char *user_nic) {
    while(1){
        int choice;
        int key_return = 0;
        
        top_bar();

        // Display user NIC if logged in
        
        if (user_nic != NULL){
            color_text(2);
            printf("| USER: ");
            printf("%s", user_nic);
        }else{
            color_text(1);
            printf("Please login first");
        }
        
        color_text(0);
        lines(2);
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
                //login_user();
                break;
            case 2:
                register_user();
                break;
            case 3:
                vote_user(user_nic);
                break;
            case 4:
                view_results();
                break;
            case 0:
                top_bar();
                printf("| EXIT ---------------------------------\n");
                lines(2);
                printf("Thank you for using SL Election System!\n"); 
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
}
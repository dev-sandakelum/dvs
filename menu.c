#include <stddef.h>

int main_menu(char *user_nic, char *user_name, char *user_pass, char *user_age)
{
    while (1)
    {
        int choice;
        int key_return = 0;
        top_bar();

        color_text(2);
        printf("             Welcome to the\n");
        printf("      Digital Voting System (DVS)!\n");
        color_text(0);
        lines(1);
        // Display user NIC if logged in
        if (user_nic != NULL && strlen(user_nic) > 11)
        {

            if (user_nic)
            {
                color_text(2);
                printf("| USER: ");
                printf("%s", user_nic);
            }
            else
            {
                color_text(1);
                printf("| USER: Not logged in");
            }
        }
        else
        {
            color_text(1);
            printf("Please login first to vote.");
        }

        color_text(0);
        lines(2);
        printf("| MAIN MENU ----------------------------\n");
        printf("  1. Login\n");
        printf("  2. Register\n");
        printf("  3. Vote\n");
        printf("  4. View Results\n");
        printf("  5. Instructions\n");
        printf("  6. Logout\n");
        printf("  0. Exit\n");
        // For admin
        lines(1);
        printf("  99. Administrative\n");
        lines(3);
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            login_user();
            break;
        case 2:
            register_user();
            break;
        case 3:
            vote_user(user_nic, user_name);
            break;
        case 4:
            view_results();
            break;
        case 5:
            instructions();
            break;
        case 6:
            logout();
            break;
        case 0:
            good_bye();
            key_return = 1;
            break;
        case 99:
            administrator(user_nic);
            break;
        default:
            menu_default_error();
            break;
        }

        if (key_return == 1)
        {
            break;
        }
    }
}
#include <stddef.h>

int main_menu(char *user_nic, char *user_name, char *user_pass, char *user_age)
{
    char *err = NULL;
    while (1)
    {
        int choice;
        int key_return = 0;
        top_bar();

        color_text(2);
        printf("            Welcome to the\n");
        printf("      Digital Voting System (DVS)!\n");
        color_text(0);
        lines(1);
        // Display user NIC if logged in
        if (user_nic != NULL && strlen(user_nic) > 11)
        {
            color_text(5);
            printf("| Welcome back, %s!\n", user_name);
        }
        else
        {
            color_text(1);
            printf("Please login first to vote.\n");
        }
        color_text(1);
        error_message(err);

        color_text(0);
        lines(1);
        printf("| MAIN MENU ----------------------------\n");

        printf("  1. Login\n");
        printf("  2. Register\n");
        printf("  3. Vote\n");
        printf("  4. View Results\n");
        printf("  5. Instructions\n");
        printf("  6. About Us\n");
        printf("  7. Logout\n");
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
            if (user_nic != NULL && strlen(user_nic) > 11)
            {
                err = "You are already logged in.\nPlease logout first to login again.";
                continue;
            }
            err = NULL;
            login_user();
            break;
        case 2:
            err = NULL;
            register_user();
            break;
        case 3:
            err = NULL;
            vote_user(user_nic, user_name);
            break;
        case 4:
            err = NULL;
            view_results();
            break;
        case 5:
            err = NULL;
            instructions();
            break;
        case 6:
            err = NULL;
            about_us();
            break;
        case 7:
            err = NULL;
            logout();
            break;
        case 0:
            err = NULL;
            good_bye();
            key_return = 1;
            break;
        case 99:
            err = NULL;
            administrator(user_nic);
            break;
        default:
            err = NULL;
            menu_default_error();
            break;
        }

        if (key_return == 1)
        {
            break;
        }
    }
}
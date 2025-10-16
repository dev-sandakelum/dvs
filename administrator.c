#include <stdio.h>
#include <stddef.h>

int admin_menu();
int set_results_status(int enable);
//int check_results_status();

int administrator(char user_nic[20])
{

    char temp_admin_pass[20] = "dvsadmin";
    top_bar();
    printf("| ADMINISTRATIVE PANEL -----------------\n");
    if (user_nic == NULL || strlen(user_nic) < 12)
    {
        color_text(1);
        lines(1);
        printf("You are not logged in.Please login first\n");
        lines(1);
        color_text(0);
        lines(1);
        exit_to();
        return 1;
    }

    printf("require admin password: ");
    color_text(5);
    char admin_pass[20];
    scanf("%s", admin_pass);
    color_text(0);
    if (strcmp(admin_pass, temp_admin_pass) != 0)
    {
        color_text(1);
        printf("Access denied! Invalid admin password.\n");
        color_text(0);
        lines(1);
        exit_to();
        return 0;
    }
    else
    {
        lines(1);
        color_text(2);
        printf("Access granted! \nWelcome to the administrative panel.\n");
        color_text(0);
        lines(1);
        continue_to();

        admin_menu();
    }
    return 0;
}
int admin_menu()
{
    while (1)
    {
        top_bar();
        int status = check_results_status();
        lines(1);
        color_text(2);
        printf("| ADMINISTRATIVE PANEL\n");
        color_text(0);
        lines(1);
        printf("Current Status: ");
        if (status)
        {
            color_text(5);
            printf("Results Released\n");
            color_text(0);
            lines(1);
            printf("1. Hide Results\n");
        }
        else
        {
            color_text(5);
            printf("Results Not Released\n");
            color_text(0);
            lines(1);
            printf("1. Release Results\n");
        }

        printf("0. Exit \n");
        lines(1);
        printf("Select an option (0-1): ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:

            printf("Releasing results...\n");
            if (status)
            {
                set_results_status(0);
            }
            else
            {
                set_results_status(1);
            }
            break;
        case 0:
            printf("Exiting administrative panel...\n");
            return 0;
        default:
            printf("Invalid option. Please try again.\n");
            break;
        }

        lines(1);
    }
}
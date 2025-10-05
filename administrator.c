int admin_menu();

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
        lines(1);
        color_text(2);
        printf("| ADMINISTRATIVE PANEL\n");
        color_text(0);
        lines(1);
        printf("1. Release Results\n");
        printf("0. Exit \n");
        lines(1);
        printf("Select an option (0-1): ");
        int choice;
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            // Call function to release results
            printf("Releasing results...\n");
            // release_results(); // Uncomment and implement as needed
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
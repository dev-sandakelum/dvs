

int register_user()
{
    char *err = NULL;
    char nic[20] = "";
    char name[100];
    int dob, age, nic_attempt = 0, pass_attempt = 0;
    char password[20], confirm_password[20];
    int section = 1, sec = 0;
    // sec 0 -> name section
    // sec 1 -> nic section
    // sec 2 -> DOB section
    // sec 3 -> password section

    while (1)
    {
        top_bar();
        printf("| REGISTRATION -------------------------\n");

        color_text(2);
        printf("Name: %-14s     attempt: %d/3\n", name, nic_attempt);
        printf("NIC: %-12s          age: %d\n", nic, age);
        color_text(0);

        lines(1);
        if (sec == 0)
        {
            printf("  Enter your name: ");
            scanf("%s", &name);
            sec = 1;
            continue;
        }

        // Get NIC number & validate
        if (nic_attempt < 3)
        {
            if (sec == 1)
            {
                color_text(1);
                error_message(err);
                color_text(0);

                printf("  Enter your NIC number: ");
                scanf("%s", nic);
                if (strlen(nic) != 12)
                {
                    nic_attempt++;
                    err = "Invalid NIC number.\nPlease enter a 12-digit NIC number.";
                    continue;
                }
                else if (strlen(nic) == 12)
                {
                    sec = 2;
                    continue;
                }
            }
        }
        else
        {
            exit_to();
            break;
        }

        if (sec == 2)
        { // DOB check
            printf("\n| ELIGIBILITY -------------------------\n");
            printf("  Enter your year of birth (YYYY): ");
            scanf("%d", &dob);
            age = 2025 - dob;
            if (age >= 18)
            {
                sec = 3;
                nic_attempt = 0;
                continue;
            }
            else
            {
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

        if (sec == 3)
        {
            color_text(2);
            if (pass_attempt == 0)
            {
                err = "You are eligible to register.";
                error_message(err);
            }
            else
            {
                color_text(1);
                lines(1);
                printf("Passwords do not match.\nPlease try again. \tattempt: %d/3\n", pass_attempt);
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

            if (pass_attempt < 4)
            {
                if (strcmp(password, confirm_password) != 0)
                {
                    pass_attempt++;
                    lines(1);
                    printf("Registration failed due to password mismatch.\n");
                    lines(3);
                    continue;
                }
                else
                {

                    // Add file operations
                    save_user_to_file(nic, name, password, age);
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
            }
            else
            {
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

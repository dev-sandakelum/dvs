

#include <stddef.h>
void details_section(int nic_status, char *nic, char *name, int age, int nic_attempt);

int register_user()
{
    char *err = NULL;
    char nic[20] = "";
    char name[100];
    int dob, age = 0, nic_attempt = 0, pass_attempt = 0, nic_status = 0;
        // nic_status 0 -> invalid / not entered
        // nic_status 1 -> valid
        // nic_status -1 -> already exists
    char password[20], confirm_password[20];
    int sec = 0;
        // sec 0 -> name section
        // sec 1 -> nic section
        // sec 2 -> DOB section
        // sec 3 -> password section

    while (1)
    {
        top_bar();
        details_section(nic_status, nic, name, age, nic_attempt);

        //---------------------------------------------------------------------------------------------------
                                        // Section 0 starts here
        //---------------------------------------------------------------------------------------------------
        if (sec == 0)
        {
            printf("| PERSONAL DETAILS --------------------\n");
            printf("  Enter your name: ");
            scanf("%s", &name);
            sec = 1;
            continue;
        }

        //---------------------------------------------------------------------------------------------------
                                        // Section 1 starts here
        //---------------------------------------------------------------------------------------------------
        
        // Get NIC number & validate
        if (nic_attempt < 3)
        {
            if (sec == 1)
            {
                color_text(1);
                error_message(err);
                color_text(0);

                if(nic_status == -1){
                    lines(1);
                    color_text(1);
                    printf("This NIC number is already registered.\n");
                    color_text(3);
                    printf("      you can exit & Login.\n");
                    printf("    1.Try again          0.Exit\n");
                    color_text(0);
                    lines(1);
                    printf("Enter your choice: ");
                    int exit_choice;
                    scanf("%d", &exit_choice);
                    if (exit_choice == 0)
                    {
                        break;
                    }else{
                        nic_status = 0;
                        continue;
                    }
                }
                printf("  Enter your NIC number: ");
                scanf("%s", nic);
                // check if NIC is 12 digits
                if (strlen(nic) != 12)
                {
                    nic_attempt++;
                    err = "Invalid NIC number.\nPlease enter a 12-digit NIC number.";
                    continue;
                }
                // Check if NIC already exists
                else if (check_nic_exists(nic) == 1)
                {
                    nic_attempt++;
                    nic_status = -1;
                    continue;
                }
                else
                {
                    nic_status = 1;
                    err = NULL;
                }
                sec = 2;
                continue;
            }
        }
        else
        {
            exit_to();
            break;
        }

        //---------------------------------------------------------------------------------------------------
                                        // Section 2 starts here
        //---------------------------------------------------------------------------------------------------
        
        // DOB section
        if (sec == 2)
        { 
            printf("| ELIGIBILITY -------------------------\n");
            printf("  Enter your year of birth (YYYY): ");
            scanf("%d", &dob);
            age = 2025 - dob;
            if (age >= 18)
            {
                sec = 3;
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
                break;
            }
        }

        //---------------------------------------------------------------------------------------------------
                                        // Section 3 starts here
        //---------------------------------------------------------------------------------------------------
        // Password section
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

            printf("| PASSWORD SETUP -----------------------\n");

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
                    //----("----------------------------------------");
                    printf("           Welcome to \n");
                    printf("    The Sri Lanka Parliamentary \n");
                    printf("          Election System, %s!\n", name);
                    //----("----------------------------------------");
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

void details_section(int nic_status, char *nic, char *name, int age, int nic_attempt)
{
    //| REGISTRATION -------------------------
    // Name:                    attempt: 0/3
    // NIC:                       age: 0
    // ----------------------------------------

    printf("| REGISTRATION -------------------------\n");

    color_text(2);
    printf("Name: %-14s     attempt: %d/3\n", name, nic_attempt);

    // change color based on nic validity
    printf("NIC: ");
    if (nic_status > 0)
    {
        color_text(2);
    }
    else
    {
        color_text(1);
    }

    printf("%-12s", nic);
    color_text(2);

    printf("          age: %d\n", age);
    color_text(0);
    lines(1);
}
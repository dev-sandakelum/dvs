#include <stddef.h>
#include <stdio.h>
#include <string.h>
void details_section(int nic_status, char *nic, char *name, int age, int nic_attempt);

int register_user()
{
    char *err = NULL;
    char nic[20] = "";
    char name[100];
    int dob, age = 0, nic_attempt = 0, pass_attempt = 0, nic_status = 0, register_as, party = 0, district = 0;
    // nic_status 0 -> invalid / not entered
    // nic_status 1 -> valid
    // nic_status -1 -> already exists
    //          ------
    // register_as 0 -> voter
    // register_as 1 -> candidate
    //          ------
    // party 1 -> BP -> blue party
    // party 2 -> GA -> green alliance
    // party 3 -> RM -> red movement
    // party 4 -> PF -> people's front
    // party 5 -> NU -> national unity
    //          ------
    // district 1 -> Mathara
    char password[20], confirm_password[20];
    int sec = 4;
    // sec 4 -> registration type section (future use)
    // sec 5 -> district section (candidate only)
    // sec 6 -> party section (candidate only)
    //         ------
    // sec 0 -> name section
    // sec 1 -> nic section
    // sec 2 -> DOB section
    // sec 3 -> password section

    while (1)
    {
        top_bar();
        details_section(nic_status, nic, name, age, nic_attempt);

        //---------------------------------------------------------------------------------------------------
        // Section 4 starts here
        //---------------------------------------------------------------------------------------------------
        if (sec == 4)
        {
            // Registration type section (future use)
            printf("| REGISTRATION TYPE -------------------\n");
            printf("  Register as:\n");
            color_text(3);
            printf("    1. Voter\n");
            printf("    2. Candidate\n");
            color_text(0);
            lines(1);
            color_text(1);
            error_message(err);
            color_text(0);
            printf("Enter your choice: ");
            scanf("%d", &register_as);
            lines(1);
            if (exit_from_0(register_as, 0))
            {
                break;
            }

            if (register_as < 3 && register_as > 0)
            {
                sec = (register_as == 1) ? 0 : 5;
                err = NULL;
                continue;
            }
            else
            {
                err = "Invalid choice entered. \nPlease select 1 or 2.";
                continue;
            }
        }
        //---------------------------------------------------------------------------------------------------
        // Section 5 starts here
        //---------------------------------------------------------------------------------------------------
        if (sec == 5)
        {
            // District section (candidate only)
            printf("| DISTRICT ----------------------------\n");
            printf("  Districts:\n");
            color_text(3);
            printf("    1. Mathara\n");
            color_text(0);
            lines(1);
            printf("  Enter your district: ");
            scanf("%d", &district);
            lines(1);
            if (exit_from_0(district, 0))
            {
                break;
            }
            if (district != 1)
            {
                err = "Invalid choice entered. \nPlease select a valid district.";
                continue;
            }
            sec = 6;
            continue;
        }
        //---------------------------------------------------------------------------------------------------
        // Section 6 starts here
        //---------------------------------------------------------------------------------------------------
        if (sec == 6)
        {
            // Party section (candidate only)
            printf("| PARTY -------------------------------\n");
            printf("  Enter your party (1-5):\n");
            color_text(4);
            printf("    1. BP -> blue party\n");
            color_text(2);
            printf("    2. GA -> green alliance\n");
            color_text(1);
            printf("    3. RM -> red movement\n");
            color_text(5);
            printf("    4. PF -> people's front\n");
            color_text(3);
            printf("    5. NU -> national unity\n");
            color_text(0);
            lines(1);
            printf("  Your choice: ");
            scanf("%d", &party);
            lines(1);
            if (exit_from_0(party, 0))
            {
                break;
            }
            if (party < 1 || party > 5)
            {
                err = "Invalid choice entered. \nPlease select a valid party.";
                continue;
            }
            sec = 0;
            continue;
        }

        //---------------------------------------------------------------------------------------------------
        // Section 0 starts here
        //---------------------------------------------------------------------------------------------------
        if (sec == 0)
        {
            printf("| PERSONAL DETAILS --------------------\n");
            printf("  Enter your name: ");
            color_text(5);
            scanf("%s", name);
            color_text(0);
            lines(1);
            if (exit_from_0(1, *name))
            {
                break;
            }
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

                if (nic_status == -1)
                {
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
                    }
                    else
                    {
                        nic_status = 0;
                        continue;
                    }
                }
                printf("  Enter your NIC number: ");
                color_text(5);
                scanf("%s", nic);
                color_text(0);
                lines(1);
                if (exit_from_0(1, *nic))
                {
                    break;
                }
                // check nic is number or not
                int invalid_nic = 0;
                for (int i = 0; i < strlen(nic); i++)
                {
                    if (nic[i] < '0' || nic[i] > '9')
                    {
                        err = "Invalid NIC number.\nPlease enter a valid NIC number.";
                        invalid_nic = 1;
                        break;
                    }
                }
                if (invalid_nic) {
                    continue;
                }

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
            color_text(1);
            error_message(err);
            color_text(0);
            printf("  Enter your year of birth(YYYY):");
            color_text(5);
            char temp_dob[10];
            scanf("%s", temp_dob);
            color_text(0);
            lines(1);
            if (exit_from_0(dob, 0))
            {
                break;
            }
            int invalid_age = 0;
            for (int i = 0; i < strlen(temp_dob); i++)
            {
                if (temp_dob[i] < '0' || temp_dob[i] > '9')
                {
                    err = "Invalid Input.\nPlease enter a valid Year of birth.";
                    invalid_age = 1;
                    break;
                }
            }
            if (invalid_age) {
                continue;
            }
            dob = atoi(temp_dob);
            printf("%d\n", dob);

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

            if (pass_attempt == 0)
            {
                color_text(2);
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
            if (pass_attempt < 4)
            {
                printf("| PASSWORD SETUP -----------------------\n");
                printf("  Enter your password: ");
                color_text(5);
                scanf("%s", password);
                color_text(0);
                lines(1);
                if (exit_from_0(1, *password))
                {
                    break;
                }
                printf("  Confirm your password: ");
                color_text(5);
                scanf("%s", confirm_password);
                color_text(0);

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

                    // file operations
                    // file operations
                    int save_result = 0;
                    if (register_as == 2)
                    {
                        save_result = save_user_as_candidate(nic, name, password, age, district, party);
                        if (save_result == 0)
                        { // 0 means failure
                            printf("Failed to save candidate data!");
                            // Handle error
                        }
                    }
                    else if (register_as == 1)
                    {
                        save_result = save_user_as_voter(nic, name, password, age);
                        if (save_result == 0)
                        { // 0 means failure
                            printf("Failed to save voter data!");
                            // Handle error
                        }
                    }

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

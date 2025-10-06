int instructions()
{
    int section = 0;
    char temp;

    while (1)
    {
        top_bar();

        if (section == 0)
        {
            printf("| INSTRUCTIONS -------------------------\n");
            lines(1);
            color_text(6);
            printf("Welcome to the Digital Voting\n");
            printf("System (DVS) - University Project\n");
            color_text(0);
            lines(1);
            printf("This screen gives full testing\n");
            printf("instructions and examples.\n");
            lines(1);
            printf("Press '1' Basic flow\n");
            printf("Press '2' Data rules\n");
            printf("Press '3' Voting flow\n");
            printf("Press '4' Results & admin\n");
            printf("Press '5' Test cases (part 1)\n");
            printf("Press '6' Test cases (part 2)\n");
            printf("Press '0' to return\n");
            lines(2);
            printf("Enter choice: ");
            scanf(" %c", &temp);
            if (temp == '1') section = 1;
            else if (temp == '2') section = 2;
            else if (temp == '3') section = 3;
            else if (temp == '4') section = 4;
            else if (temp == '5') section = 5;
            else if (temp == '6') section = 6;
            else if (temp == '0') break;
            else continue;
        }

        else if (section == 1)
        {
            top_bar();
            printf("| BASIC FLOW --------------------------\n");
            lines(1);
            color_text(6);
            printf("1) Register as voter or candidate\n");
            printf("2) Login using NIC & password\n");
            printf("3) Select district & party\n");
            printf("4) Choose exactly 3 candidates\n");
            printf("5) Confirm and submit vote\n");
            color_text(3);
            lines(1);
            printf("Navigation:\n");
            color_text(6);
            printf("- Use menu numbers (0-6)\n");
            printf("- '0' returns to previous screen\n");
            color_text(0);
            lines(2);
            printf("Press '1' Data rules\n");
            printf("Press '0' Main menu\n");
            scanf(" %c", &temp);
            if (temp == '1') section = 2;
            else section = 0;
        }

        else if (section == 2)
        {
            top_bar();
            printf("| DATA RULES --------------------------\n");
            lines(1);
            color_text(6);
            printf("NIC: exactly 12 digits\n");
            printf("Example: 200012345678\n");
            printf("Name: no spaces (use _)\n");
            printf("Year: YYYY (must be 18+)\n");
            printf("Password: case-sensitive\n");
            printf(" - Confirm password on reg\n");
            color_text(3);
            lines(1);
            printf("Candidate rules:\n");
            color_text(6);
            printf(" - Choose district (Matara)\n");
            printf(" - Choose party number (1-5)\n");
            printf(" - Party cannot be changed\n");
            color_text(0);
            lines(2);
            printf("Press '1' Voting flow\n");
            printf("Press '0' Main menu\n");
            scanf(" %c", &temp);
            if (temp == '1') section = 3;
            else section = 0;
        }

        else if (section == 3)
        {
            top_bar();
            printf("| VOTING FLOW -------------------------\n");
            lines(1);
            color_text(6);
            printf("Pre-conditions:\n");
            printf(" - Registered voter & logged in\n");
            printf(" - Status != VOTED\n");
            lines(1);
            printf("Steps:\n");
            printf(" 1) Select district\n");
            printf(" 2) Select party (1-5)\n");
            printf(" 3) Enter 3 candidate IDs\n");
            printf(" 4) System validates party match\n");
            printf(" 5) Confirm to submit (final)\n");
            color_text(3);
            lines(1);
            printf("If validation fails, you\n");
            printf("will be prompted to retry.\n");
            color_text(0);
            lines(2);
            printf("Press '1' Results/admin\n");
            printf("Press '0' Main menu\n");
            scanf(" %c", &temp);
            if (temp == '1') section = 4;
            else section = 0;
        }

        else if (section == 4)
        {
            top_bar();
            printf("| RESULTS & ADMIN --------------------\n");
            lines(1);
            color_text(6);
            printf("Viewing results:\n");
            printf(" - Select '4. View Results'\n");
            printf(" - Shows totals and ranks\n");
            printf(" - Voter choices remain private\n");
            lines(1);
            color_text(3);
            printf("Admin panel:\n");
            color_text(6);
            printf(" - Accessible via option 99\n");
            printf(" - Admin password: ");
            color_text(5);
            printf("dvsadmin\n");
            color_text(6);
            printf(" - Admin can Release/Hide\n");
            printf("   results using menu (1/0)\n");
            color_text(0);
            lines(2);
            printf("Press '1' Test cases (1)\n");
            printf("Press '0' Main menu\n");
            scanf(" %c", &temp);
            if (temp == '1') section = 5;
            else section = 0;
        }

        else if (section == 5)
        {
            top_bar();
            printf("| TEST CASES - PART 1 ----------------\n");
            lines(1);
            color_text(6);
            printf("1) Register valid voter:\n");
            printf("   NIC: 200012345678\n");
            printf("   Year: 2000\n");
            printf("   Expect: Success\n");
            lines(1);
            printf("2) Register with bad NIC:\n");
            printf("   NIC: 12345\n");
            printf("   Expect: Reject (format)\n");
            lines(1);
            printf("3) Duplicate NIC reg:\n");
            printf("   Try same NIC again\n");
            printf("   Expect: 'NIC already'\n");
            lines(1);
            printf("4) Login attempts:\n");
            printf("   Enter wrong pass 3 times\n");
            printf("   Expect: return to menu\n");
            color_text(0);
            lines(2);
            printf("Press '1' Test cases (2)\n");
            printf("Press '0' Main menu\n");
            scanf(" %c", &temp);
            if (temp == '1') section = 6;
            else section = 0;
        }

        else if (section == 6)
        {
            top_bar();
            printf("| TEST CASES - PART 2 ----------------\n");
            lines(1);
            color_text(6);
            printf("5) Voting validation:\n");
            printf("   Pick 3 candidates from\n");
            printf("   different parties\n");
            printf("   Expect: validation fail\n");
            lines(1);
            printf("6) Admin release test:\n");
            printf("   Go to 99, enter 'dvsadmin'\n");
            printf("   Use option 1 to release\n");
            printf("   Then check View Results\n");
            lines(1);
            printf("7) Reset results status:\n");
            printf("   Admin hides results again\n");
            color_text(3);
            lines(1);
            printf("Checklist complete for testing.\n");
            color_text(0);
            lines(2);
            printf("Press any key to return: ");
            scanf(" %c", &temp);
            section = 0;
        }
    }

    return 0;
}

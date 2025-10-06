#include <stdio.h>

int instructions()
{
    int section = 0;
    
    while (1)
    {
        top_bar();
        
        if (section == 0)
        {
            // Welcome & Overview Section
            printf("|INSTRUCTIONS ==========================\n");
            color_text(2);
            printf("Welcome to Sri Lanka Parliamentary\n");
            printf("Election Voting System\n");
            color_text(0);
            lines(1);
            color_text(6);
            printf("This digital voting system allows you to:\n");
            printf(" - Register as a voter or candidate\n");
            printf(" - Cast your vote securely for your\n");
            printf("   preferred political party\n");
            printf(" - Select 3 candidates from that party\n");
            printf(" - View real-time election results\n");
            lines(1);
            color_text(3);
            printf("IMPORTANT NOTES:\n");
            printf(" - Minimum age requirement: 18 years\n");
            printf(" - Each NIC can register only once\n");
            printf(" - Each voter can vote only once\n");
            printf(" - All votes are final and cannot be\n");
            printf("   changed after submission\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' for navigation guide or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 1;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 1)
        {
            // Navigation Section
            printf("|NAVIGATION & GENERAL USAGE ============\n");
            color_text(2);
            printf("System Navigation ---------------------\n");
            color_text(6);
            printf(" - Use number keys to select menu\n");
            printf("   options (0-6)\n");
            printf(" - Enter '0' at any prompt to exit\n");
            printf("   current section and return to menu\n");
            printf(" - Follow on-screen prompts carefully\n");
            printf(" - Press Enter after each input\n");
            lines(1);
            color_text(2);
            printf("Data Entry Guidelines -----------------\n");
            color_text(6);
            printf(" - NIC must be exactly 12 digits\n");
            printf("   (e.g., 200012345678)\n");
            printf(" - Names should not contain spaces\n");
            printf("   (use _ if needed)\n");
            printf(" - Passwords are case-sensitive\n");
            printf(" - Keep your credentials secure\n");
            printf(" - Year of birth format: YYYY\n");
            printf("   (e.g., 2001)\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' for registration guide or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 2;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 2)
        {
            // Registration Section
            printf("|REGISTRATION INSTRUCTIONS =============\n");
            color_text(2);
            printf("Voter Registration --------------------\n");
            color_text(6);
            printf("Step 1: Select registration type\n");
            printf(" - Choose '1' for Voter\n");
            printf(" - Choose '2' for Candidate\n");
            lines(1);
            printf("Step 2: Enter personal details\n");
            printf(" - Full name (without spaces)\n");
            printf(" - 12-digit NIC number\n");
            printf(" - Year of birth (must be 18+)\n");
            lines(1);
            printf("Step 3: Create password\n");
            printf(" - Enter your password\n");
            printf(" - Confirm password (must match)\n");
            printf(" - You have 3 attempts for matching\n");
            lines(1);
            color_text(2);
            printf("Candidate Registration ----------------\n");
            color_text(6);
            printf("Additional steps for candidates:\n");
            printf(" - Select district (currently Matara)\n");
            printf(" - Choose your political party:\n");
            color_text(4);
            printf("   1. BP - Blue Party\n");
            color_text(2);
            printf("   2. GA - Green Alliance\n");
            color_text(1);
            printf("   3. RM - Red Movement\n");
            color_text(5);
            printf("   4. PF - People's Front\n");
            color_text(3);
            printf("   5. NU - National Unity\n");
            color_text(6);
            lines(1);
            printf("Note: You cannot change party after\n");
            printf("registration is complete\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' for login guide or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 3;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 3)
        {
            // Login Section
            printf("|LOGIN INSTRUCTIONS ====================\n");
            color_text(2);
            printf("User Login ----------------------------\n");
            color_text(6);
            printf("Step 1: From main menu, select '1'\n");
            lines(1);
            printf("Step 2: Enter your credentials\n");
            printf(" - Enter your 12-digit NIC number\n");
            printf(" - Enter your password\n");
            lines(1);
            printf("Step 3: Access granted\n");
            printf(" - You will see your NIC displayed\n");
            printf("   in green on the main menu\n");
            printf(" - You can now proceed to vote\n");
            lines(1);
            color_text(2);
            printf("Login Attempts ------------------------\n");
            color_text(6);
            printf(" - You have 3 login attempts\n");
            printf(" - After 3 failed attempts, you'll\n");
            printf("   return to main menu\n");
            printf(" - Ensure correct NIC and password\n");
            lines(1);
            color_text(2);
            printf("Session Management --------------------\n");
            color_text(6);
            printf(" - Login persists during session\n");
            printf(" - Select '6. Logout' from main menu\n");
            printf("   to end your session\n");
            printf(" - For security, logout after voting\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' for voting guide or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 4;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 4)
        {
            // Voting Section
            printf("|VOTING INSTRUCTIONS ===================\n");
            color_text(2);
            printf("Pre-Voting Requirements ---------------\n");
            color_text(6);
            printf(" - You must be logged in to vote\n");
            printf(" - You must be registered as a voter\n");
            printf(" - You can vote only once\n");
            printf(" - Voters with 'VOTED' status cannot\n");
            printf("   vote again\n");
            lines(1);
            color_text(2);
            printf("Voting Process ------------------------\n");
            color_text(6);
            printf("Step 1: Select district\n");
            printf(" - Choose from available districts\n");
            printf(" - Currently: Matara district\n");
            printf(" - District boundaries are enforced\n");
            lines(1);
            printf("Step 2: Select political party\n");
            printf(" - Choose from 5 available parties\n");
            printf(" - Each party has unique candidates\n");
            color_text(4);
            printf("   1. BP - Blue Party (Flower)\n");
            color_text(2);
            printf("   2. GA - Green Alliance (Elephant)\n");
            color_text(1);
            printf("   3. RM - Red Movement (Telephone)\n");
            color_text(5);
            printf("   4. PF - People's Front (Compass)\n");
            color_text(3);
            printf("   5. NU - National Unity (Key)\n");
            color_text(6);
            lines(1);
            printf("Step 3: Select 3 candidates\n");
            printf(" - You must select exactly 3 candidates\n");
            printf(" - All 3 must be from your chosen party\n");
            printf(" - Use candidate ID numbers shown\n");
            printf(" - Each candidate must be different\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' to continue or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 5;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 5)
        {
            // Voting Confirmation & Rules
            printf("|VOTING RULES & CONFIRMATION ===========\n");
            color_text(2);
            printf("Vote Validation -----------------------\n");
            color_text(6);
            printf(" - System validates all 3 candidates\n");
            printf("   belong to selected party\n");
            printf(" - Invalid votes will be rejected\n");
            printf(" - You'll be prompted to re-enter\n");
            printf("   if validation fails\n");
            lines(1);
            color_text(2);
            printf("Vote Confirmation ---------------------\n");
            color_text(6);
            printf(" - Review your selected candidates\n");
            printf(" - District and party will be shown\n");
            printf(" - Candidate IDs and names displayed\n");
            printf(" - Confirm before final submission\n");
            lines(1);
            color_text(2);
            printf("After Voting --------------------------\n");
            color_text(6);
            printf(" - Your status changes to 'VOTED'\n");
            printf(" - Vote is recorded in database\n");
            printf(" - You cannot vote again with same NIC\n");
            printf(" - Success message will be displayed\n");
            lines(1);
            color_text(3);
            printf("IMPORTANT VOTING RULES:\n");
            printf(" - All votes are final\n");
            printf(" - No changes after submission\n");
            printf(" - One vote per NIC number\n");
            printf(" - Cross-party voting not allowed\n");
            printf(" - Ensure accuracy before confirming\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' for results guide or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 6;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 6)
        {
            // Results Section
            printf("|RESULTS & ANALYTICS ===================\n");
            color_text(2);
            printf("Viewing Results -----------------------\n");
            color_text(6);
            printf(" - Select '4. View Results' from menu\n");
            printf(" - Results updated in real-time\n");
            printf(" - No login required to view results\n");
            printf(" - Available to all users\n");
            lines(1);
            color_text(2);
            printf("Results Display -----------------------\n");
            color_text(6);
            printf("Information shown:\n");
            printf(" - Total votes cast\n");
            printf(" - Votes by political party\n");
            printf(" - Individual candidate performance\n");
            printf(" - District-wise breakdown\n");
            printf(" - Vote percentages and rankings\n");
            lines(1);
            color_text(2);
            printf("Privacy & Security --------------------\n");
            color_text(6);
            printf(" - Individual voter choices are private\n");
            printf(" - Only aggregate results are shown\n");
            printf(" - Results cannot be manipulated\n");
            printf(" - All data stored securely\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' for troubleshooting or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 7;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 7)
        {
            // Troubleshooting Section
            printf("|TROUBLESHOOTING & SUPPORT =============\n");
            color_text(2);
            printf("Common Issues -------------------------\n");
            color_text(6);
            printf("'NIC already registered' error:\n");
            printf(" - Each NIC can register only once\n");
            printf(" - If you registered, use Login\n");
            printf(" - Contact admin if error persists\n");
            lines(1);
            printf("'Already voted' message:\n");
            printf(" - Each voter can vote once only\n");
            printf(" - Check your voter status\n");
            printf(" - This ensures election integrity\n");
            lines(1);
            printf("'Invalid district' error:\n");
            printf(" - Currently only Matara available\n");
            printf(" - District boundaries enforced\n");
            printf(" - Register in correct district\n");
            lines(1);
            printf("'Candidates not from party' error:\n");
            printf(" - All 3 votes must be same party\n");
            printf(" - Check candidate IDs carefully\n");
            printf(" - Re-enter correct candidate IDs\n");
            lines(1);
            color_text(2);
            printf("Getting Help --------------------------\n");
            color_text(6);
            printf(" - Read error messages carefully\n");
            printf(" - Use '0' to exit problematic sections\n");
            printf(" - Re-attempt with correct information\n");
            printf(" - Contact system administrator\n");
            color_text(0);
            lines(2);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press '1' for final notes or '0' to exit: ");
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 8;
                continue;
            }
            else if (temp == '0')
            {
                break;
            }
            else
            {
                continue;
            }
        }
        else if (section == 8)
        {
            // Final Section - System Info & Exit
            printf("|SYSTEM INFORMATION ====================\n");
            color_text(2);
            printf("Available Parties ---------------------\n");
            color_text(4);
            printf("BP - Blue Party\n");
            color_text(6);
            printf(" Symbol: Flower | Color: Blue\n");
            printf(" 5 candidates available\n");
            color_text(2);
            printf("GA - Green Alliance\n");
            color_text(6);
            printf(" Symbol: Elephant | Color: Green\n");
            printf(" 5 candidates available\n");
            color_text(1);
            printf("RM - Red Movement\n");
            color_text(6);
            printf(" Symbol: Telephone | Color: Red\n");
            printf(" 5 candidates available\n");
            color_text(5);
            printf("PF - People's Front\n");
            color_text(6);
            printf(" Symbol: Compass | Color: Purple\n");
            printf(" 5 candidates available\n");
            color_text(3);
            printf("NU - National Unity\n");
            color_text(6);
            printf(" Symbol: Key | Color: Orange\n");
            printf(" 5 candidates available\n");
            lines(1);
            color_text(2);
            printf("System Features -----------------------\n");
            color_text(6);
            printf(" - 25 total candidates across parties\n");
            printf(" - Multiple districts supported\n");
            printf(" - Real-time vote counting\n");
            printf(" - Secure data storage\n");
            printf(" - User-friendly interface\n");
            lines(1);
            color_text(3);
            printf("Thank you for using Sri Lanka\n");
            printf("Parliamentary Election System 2025!\n");
            color_text(0);
            lines(3);
            printf("\033[25;0H"); // Move cursor to line 25
            printf("Press any key and enter to return to menu: ");
            char temp;
            scanf(" %c", &temp);
            break;
        }
    }
    
    return 0;
}
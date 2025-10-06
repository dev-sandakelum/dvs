#include <stdio.h>

int welcome_screen()
{
    char choice;
    top_bar();
    color_text(2);
    printf("             Welcome to the\n");
    printf("      Digital Voting System (DVS)!\n");
    color_text(4);
    lines(1);
    printf("----------------------------------------\n");
    color_text(3);
    printf("This system enables you to:\n");
    printf("  - Register as a voter or candidate\n");
    printf("  - Cast your vote securely\n");
    printf("  - View election results\n");
    printf("\nPlease use the menu options to\n");
    printf("navigate through the system.\n");
    color_text(4);
    printf("----------------------------------------\n");
    color_text(0);
    printf("Would you like to skip instructions and\n");
    printf("     proceed to the main menu?\n");
    lines(1);
    printf("         (1. Yes  0. No): ");
    scanf(" %c", &choice);
    if (choice == '1')
    {
        return 0;
    }
    else if (choice == '0')
    {
        instructions();
        return 3;
    }
    return 1;
}
int instructions()
{
    int section = 0;
    while (1)
    {

        top_bar();
        printf("|INSTRUCTIONS ==========================\n");
        color_text(2);
        if (section == 0)
        {
            printf("General Instructions ------------------\n");
            color_text(6);
            printf(" - Exit any section: enter 0\n");
            printf(" - Provide accurate information\n");
            printf(" - Keep your credentials secure\n");
            printf(" - Each NIC can only register once\n");
            color_text(0);
            printf("\033[12;0H"); // Move cursor to line 12
            printf("Press '1' and then enter to proceed to\nnext section or '0' to quit instructions: ");  
            char temp;
            scanf(" %c", &temp);
            if (temp == '1')
            {
                section = 1;
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

        color_text(2);
        printf("Registration --------------------------\n");
        color_text(6);
        printf(" - Provide valid NIC, name, age,\n");
        printf("   and password\n");
        printf(" - Candidates select district and\n");
        printf("   party\n");
        printf(" - Must be at least 18 years old\n");
        printf(" - Each NIC can only register once\n");
        color_text(2);
        printf("Voting --------------------------------\n");
        color_text(6);
        printf(" - Select district and party\n");
        printf(" - Vote for up to 3 candidates from\n");
        printf("   the same party\n");
        color_text(2);
        printf("Results -------------------------------\n");
        color_text(6);
        printf(" - View election results\n");
        printf(" - Results are updated after voting\n");
        color_text(0);
        lines(3);

        break;
    }
    printf("Press any key and then enter to\nproceed to the main menu: ");
    int temp;
    scanf("%d", &temp);
    return 0;
}

int the_front()
{
    clear_screen();
    /*color_text(4);
    lines(3);
    color_text(3);
    int a = 40;
    for (int i = 4; i <= a; i+=4)
    {
        for (int k = (a-i)*.5; k > 0; k--)
        {
            printf("*");
        }
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int m = (a-i)*.5; m > 0; m--)
        {
            printf("*");
        }
            printf("\n");
    }

    color_text(2);

    printf(" SRI LANKA PARLIAMENTARY ELECTION SYSTEM\n");
    printf("                  2025");

    color_text(3);
    a = 40;
    for (int i = a; i > 0; i-=4)
    {
        for (int k = (a-i)*.5; k > 0; k--)
        {
            printf("*");
        }
        for (int j = 0; j < i; j++)
        {
            printf(" ");
        }
        for (int m = (a-i)*.5; m > 0; m--)
        {
            printf("*");
        }
            printf("\n");
    }

    color_text(4);
    lines(3);*/

    printf("\n");
    printf("========================================\n");
    printf("##                                    ##\n");
    printf("##    ####    ##   ##   ####          ##\n");
    printf("##    ##  #   ##   ##  ##             ##\n");
    printf("##    ##   #   ## ##    ####          ##\n");
    printf("##    ##  #     ###        ##         ##\n");
    printf("##    ####       ##     ####          ##\n");
    printf("##                                    ##\n");
    printf("##  ==============================    ##\n");
    printf("##     DIGITAL VOTING SYSTEM          ##\n");
    printf("##  ==============================    ##\n");
    printf("##                                    ##\n");
    printf("##       >> CAST YOUR VOTE <<         ##\n");
    printf("##                                    ##\n");
    printf("##       ------- by ---------         ##\n");
    printf("##       TG/2024/2073                 ##\n");
    printf("##              TG/2024/2075          ##\n");
    printf("##       TG/2024/2122                 ##\n");
    printf("##              TG/2024/2142          ##\n");
    printf("##                                    ##\n");
    printf("========================================\n");
    printf("\n");
    printf("Press any key and then enter to\nproceed to the main menu: ");
    int s;
    getchar();
    color_text(0);
    return 0;
}
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

int the_front()
{
    clear_screen();

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
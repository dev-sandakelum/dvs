#include <stdio.h>

int welcome_screen()
{
    char choice;
    top_bar();
    color_text(2);
    printf("             Welcome to the\n");
    printf("      Digital Voting System (DVS)!\n");
    color_text(0);
    lines(1);
    color_text(6);
    printf("University project simulating\n");
    printf("Sri Lanka's Parliamentary Election\n");
    printf("System with secure digital voting.\n");
    color_text(0);
    lines(1);
    color_text(3);
    printf("KEY FEATURES:\n");
    color_text(2);
    printf("  > Secure voter registration\n");
    printf("  > Candidate registration\n");
    printf("  > Multi-party voting\n");
    printf("  > Real-time results\n");
    printf("  > Admin controls\n");
    printf("  > Data validation\n");
    color_text(0);
    lines(1);
    color_text(5);
    printf("SCOPE: Matara district, 5 parties\n");
    printf("TECH: C language, file storage\n");
    color_text(1);
    printf("NOTE: Educational simulation only\n");
    color_text(0);
    lines(1);
    color_text(5);
    printf("Choose: ");
    color_text(2);
    printf("1=Menu ");
    color_text(6);
    printf("0=Instructions: ");
    color_text(0);
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
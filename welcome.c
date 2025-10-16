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
    color_text(2);
    printf("\t1. Main Menu \n");
    color_text(6);
    printf("\t0. Instructions\n");
    color_text(0);
    lines(1);
    printf("Choose: ");

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
    lines(1);
    //printf("  /\\::::/\\::::/\\::::/\\::::/\\::::/\\::::/\\\n");
    //printf("  \\/____\\/____\\/____\\/____\\/____\\/____\\/\n");
    printf("|                                      |\n");
    printf("|   /$$$$$$$  /$$    /$$  /$$$$$$      |\n");
    printf("|  | $$__  $$| $$   | $$ /$$__  $$     |\n");
    printf("|  | $$  \\ $$| $$   | $$| $$  \\__/     |\n");
    printf("|  | $$  | $$|  $$ / $$/|  $$$$$$      |\n");
    printf("|  | $$  | $$ \\  $$ $$/  \\____  $$     |\n");
    printf("|  | $$  | $$  \\  $$$/   /$$  \\ $$     |\n");
    printf("|  | $$$$$$$/   \\  $/   |  $$$$$$/     |\n");
    printf("|  |_______/     \\_/     \\______/      |\n");
    printf("|                                      |\n");
    printf("|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |\n");
    printf("|       DIGITAL VOTING SYSTEM          |\n");
    printf("|  ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~  |\n");
    printf("|                                      |\n");
    printf("|   Sri Lanka Parliamentary Election   |\n");
    printf("|                                      |\n");
    printf("|       >>> CAST YOUR VOTE <<<         |\n");
    printf("|                                      |\n");
    printf("|  ::::::::::::::::::::::::::::::::    |\n");
    printf("|           Developed by:              |\n");
    printf("|                                      |\n");
    printf("|    TG/2024/2073  |  TG/2024/2075     |\n");
    printf("|    TG/2024/2122  |  TG/2024/2142     |\n");
    printf("|                                      |\n");
    //printf("  \\/____\\/____\\/____\\/____\\/____\\/____\\/\n");
    //printf("  /\\::::/\\::::/\\::::/\\::::/\\::::/\\::::/\\\n");
    lines(1);
    
    
    printf("Press any key and then enter to\nproceed to the main menu: ");
    int s;
    getchar();
    color_text(0);
    return 0;
}
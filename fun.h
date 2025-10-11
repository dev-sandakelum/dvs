#ifndef FUN_H
#define FUN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int clear_screen()
{
    if (system("ver") == 0)
    {
        system("cls");
    }
    else
    {
        system("clear");
    }
    return 0;
}

int color_text(int color)
{
    if (color == 0)
    {
        // white
        printf("\033[0;37m");
    }
    else if (color == 1)
    {
        // Red
        printf("\033[0;31m");
    }
    else if (color == 2)
    {
        // Green
        printf("\033[0;32m");
    }
    else if (color == 3)
    {
        // magenta
        printf("\033[0;35m");
    }
    else if (color == 4)
    {
        // blue
        printf("\033[0;34m");
    }
    else if (color == 5)
    {
        // yellow
        printf("\033[0;33m");
    }
    else if (color == 6)
    {
        // cyan
        printf("\033[0;36m");
    }
    return 0;
}

int lines(int type)
{
    if (type == 1)
    {
        printf("----------------------------------------\n");
    }
    else if (type == 2)
    {
        printf("\n----------------------------------------\n");
    }
    else if (type == 3)
    {
        printf("========================================\n");
    }
    else if (type == 4)
    {
        printf("\n========================================\n");
    }
    return 0;
}

int exit_to()
{
    printf("type something and \nPress enter to return to menu: ");
    char temp;
    scanf(" %c", &temp);
    return 0;
}
int exit_from_0(char input, char check_char )
{
    //lines(1);
    if (input == 0 || check_char == '0')
    {
        exit_to();
        return 1;
    }
    return 0;
}
int continue_to(){
    printf("type something and \nPress enter to continue: ");
    char temp;
    scanf(" %c", &temp);
    return 0;
}

int top_bar()
{
    clear_screen();
    lines(4);
    printf("SRI LANKA PARLIAMENTARY ELECTION SYSTEM\n");
    lines(1);
    return 0;
}

int error_message(char *err)
{
    if (err)
    {
        lines(1);
        printf("%s\n", err);
        lines(1);
    }
    return 0;
}

int success_message(char *message)
{
    lines(1);
    printf("| %s \n", message);
    lines(1);
    return 0;
}

int try_again()
{
    lines(1);
    printf("are you want to try again? \n\t(1.Yes 0.No): ");
    int try_again;
    scanf("%d", &try_again);
    if (try_again == 1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

char *get_party_by_num(int party_num)
{
    switch (party_num)
    {
    case 1:
        return "BP";
    case 2:
        return "GA";
    case 3:
        return "RM";
    case 4:
        return "PF";
    case 5:
        return "NU";
    default:
        return "Unknown";
    }
}
int good_bye()
{
    top_bar();
    printf("| EXIT ---------------------------------\n");
    lines(2);
    color_text(5);
    printf("Thank you \nfor using SL Election System!\n");
    printf("Goodbye!\n");
    color_text(0);
    lines(3);
    return 1;
}
int menu_default_error()
{
    top_bar();
    printf("| ERROR --------------------------------\n");
    color_text(1);
    error_message("\t   Invalid choice. \n     Please select a valid option.");
    color_text(0);
    lines(3);
    exit_to();
}
#endif

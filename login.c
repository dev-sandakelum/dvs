
#include <stdio.h>
#include <string.h>

int cookie_msg();

int login_user()
{
    top_bar();
    char nic[20] = "";
    char password[20] = "";

    printf("| LOGIN --------------------------------\n");
    printf(" NIC : ");
    color_text(5);
    scanf("%s", nic);
    color_text(0);
    //lines(1);
    if (exit_from_0(1, *nic))
    {
        return 0;
    }
    //printf("\033[1A"); // Move cursor up one line]")
    printf(" Password : ");
    color_text(5);
    scanf("%s", password);
    color_text(0);
    lines(1);
    if (exit_from_0(1, *password))
    {
        return 0;
    }

    //------- Check credentials from file
    int result = login_by_pass(nic, password, "password"); // nic , password , login_type
    if (result == 1)
    {
        color_text(2);
        printf("Login successful! Welcome, %s.\n", nic);
        color_text(0);
        lines(1);
        cookie_msg();
    }
    else if (result == 0)
    {
        color_text(1);
        printf("Login failed! \nInvalid NIC or password.\n");
    }
    else
    {
        color_text(1);
        printf("Error opening user data file.\n");
        return 2;
    }
    color_text(0);
    lines(1);
    exit_to();
    return 0;
}

int cookie_msg()
{
    color_text(3);
    printf("COOKIE POLICY -------------------------\n");
    printf("This project uses cookies to enhance\n");
    printf("user experience. By continuing to use\n");
    printf("this application, you agree to our use\n");
    printf("of cookies.\n");
    color_text(0);
}
#include <stddef.h>
#include <stdio.h>
#include <string.h>

int login_user()
{
    top_bar();
    char nic[20] = "";
    char password[20] = "";

    printf("NIC : ");
    scanf("%s", nic);

    printf("Password : ");
    scanf("%s", password);

    //------- Check credentials from file
    int result = login_by_pass(nic, password ,"password"); // nic , password , login_type
    if (result == 1)
    {
        color_text(2);
        printf("Login successful! Welcome, %s.\n", nic);
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


#include <stddef.h>
#include <stdio.h>
#include <string.h>


int login_user() {

    top_bar();
    char nic[20]= "";
    char password[20]= "";

    printf("NIC  : ");
    scanf("%s",nic);

    printf("Password  : ");
    scanf("%s",password);

    int result = login_by_pass(nic,password);
    if (result == 1)
    {
        color_text(2);
        printf("Login Successful! Welcome, %s.\n",nic);
    }
    else if (result == 0)
    {
        color_text(1);
        printf("Login Failed! Invalid NIC or Password.\n");
    }
    else 
    {
        color_text(1);
        printf("Error opening User data file.\n");
        return 2;
    }
    color_text(0);
    lines(1);
    exit_to();
    return 0;
}
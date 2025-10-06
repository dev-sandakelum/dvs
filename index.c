#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include .c files
#include "fun.h" // common functions

int instructions();
int the_front();
int welcome_screen();
int register_user();
int login_user();
int vote_user(char *user_nic, char *user_name);
int view_results();
int main_menu(char *user_nic, char *user_name, char *user_pass, char *user_age);
int save_user_as_voter(char *nic, char *name, char *password, int age);
int save_user_as_candidate(char *nic, char *name, char *password, int age, int district, int party);
int check_nic_exists(char *nic);
char *find_nic(char *nic);
int login_by_pass(char *nic, char *password, char log_type[10]);
char *check_login();
int save_login_session(char *nic);
int administrator(char user_nic[20]);

// Global variables
char *err;
char user[4][100] = {"", "", "", ""}; // nic, name, password, age

int set_user(char *nic, char *name, char *password, char *age)
{
    strcpy(user[0], nic);
    strcpy(user[1], name);
    strcpy(user[2], password);
    strcpy(user[3], age);
    return 0;
}
char *request_user_password()
{
    return user[2];
}
char *request_user_age()
{
    return user[3];
}
int logout()
{
    save_login_session("0");
    strcpy(user[0], "");
    strcpy(user[1], "");
    strcpy(user[2], "");
    strcpy(user[3], "");
}

int main()
{
    char *nic_if_logged = check_login();
    //printf("%s\n", nic_if_logged);
    login_by_pass(nic_if_logged, "", "session");

    color_text(0);
    // printf("%s" , user[0]);
    the_front();
    welcome_screen();
    main_menu(user[0], user[1], "", user[3]);

    return 0;
}

#include "login.c"
#include "welcome.c"
#include "register.c"
#include "vote.c"
#include "results.c"
#include "menu.c"
#include "file_handle_register.c"
#include "file_handle_login.c"
#include "file_handle_vote.c"
#include "file_handle_session.c"
#include "administrator.c"
#include "file_handle_administrator.c"
#include "instructions.c"

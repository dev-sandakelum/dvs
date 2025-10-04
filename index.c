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
int vote_user(char *user_nic , char *user_name);
int view_results();
int main_menu(char *user_nic , char *user_name, char *user_pass, char *user_age);
int save_user_as_voter(char *nic, char *name, char *password, int age );
int save_user_as_candidate(char *nic, char *name, char *password, int age , int district, int party);
int check_nic_exists(char *nic);
char *find_nic(char *nic);
int login_by_pass(char *nic ,char *password);
//char *login_user_data(char *nic, char *password);

// Global variables
char *err;
char user[4][100] = {"", "", "", ""}; // nic, name, password, age

int set_user(char *nic, char *name, char *password, char *age) {
    strcpy(user[0], nic);
    strcpy(user[1], name);
    strcpy(user[2], password);
    strcpy(user[3], age);
    return 0;
}

int main() {
    
    color_text(0);
    //printf("%s" , user[0]);
    the_front();
    welcome_screen();
    main_menu(user[0] , user[1], user[2], user[3]);
    
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
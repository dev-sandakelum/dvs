#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include .c files
#include "fun.h" // common functions

int register_user();
//int login_user();
int vote_user();
int view_results();
int main_menu(char *user_nic);
int save_user_to_file(char *nic, char *name, char *password, int age);
int check_nic_exists(char *nic);
char *find_nic(char *nic);

// Global variables
char *err;
char *user[] = {"200334455667", NULL, NULL, NULL}; // nic, name, password, age

int main() {
    
    color_text(0);
    //printf("%s" , user[0]);
    main_menu(user[0]);
    
    return 0;
}

//#include "login.c"
#include "register.c"
#include "vote.c"
#include "results.c"
#include "menu.c"
#include "file_handle.c"
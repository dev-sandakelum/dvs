#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include .c files
#include "fun.c"

int register_user();
int login_user();
int vote_user();
int view_results();
int main_menu();
int save_user_to_file(char *nic, char *name, char *password, int age);
int check_nic_exists(char *nic);

// Global variables
char *err;
char *user[] = {NULL, NULL, NULL, NULL}; // nic, name, password, age

int main() {
    
    color_text(0);
    main_menu();
    
    return 0;
}

#include "login.c"
#include "register.c"
#include "vote.c"
#include "results.c"
#include "menu.c"
#include "file_handle.c"
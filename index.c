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

// Global variables
char *err;


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
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Include .c files
#include "fun.c"
#include "login.c"
#include "register.c"
#include "vote.c"
#include "results.c"
#include "menu.c"

// Global variables
char *err;


int main() {
    color_text(0);
    main_menu();
    
    return 0;
}
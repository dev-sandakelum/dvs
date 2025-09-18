#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int clear_screen() {
    if (system("ver") == 0) {
        system("cls");
    } else {
        system("clear");
    }
    return 0;
}

int color_text (int color) {
    if (color == 0) {
        // white
        printf("\033[0;37m");
    }else if(color == 1){
        // Red
        printf("\033[0;31m");
    }else if (color == 2) {
        // Green    
        printf("\033[0;32m");
    }else if (color == 3) {
        // Blue
        printf("\033[0;34m");
    } 
    return 0;
}   

int lines(int type) {
    if(type == 1){
        printf("----------------------------------------\n");
    }else if (type == 2) {
        printf("\n----------------------------------------\n");
    }else if (type == 3) {
        printf("========================================\n");
    }else if (type == 4) {
        printf("\n========================================\n");
    }
    return 0;
}

int exit_to() {
    printf("Press any key to return to menu: ");
    char temp;
    scanf(" %c", &temp);
    return 0;
}

int top_bar(){
    clear_screen();
    lines(4);
    printf("SRI LANKA PARLIAMENTARY ELECTION SYSTEM\n");
    lines(1);
    return 0;
}

int error_message(char *err) {
    if (err) {
        lines(1);
        printf("%s\n", err);
        lines(1);
    }
    return 0;
}

int success_message(char *message) {
    lines(1);
    printf("SUCCESS: %s\n", message);
    lines(1);
    return 0;
}

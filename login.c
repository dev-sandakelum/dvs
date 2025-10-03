#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include "fun.h"

void login_details_section(char *nic, char *name) {
    top_bar();
    printf("| LOGIN DETAILS -----------------------\n");
    color_text(3);
    printf("NIC: %s\n", nic);
    printf("Name: %s\n", name);
    color_text(0);
    lines(1);
}
char *send[4] = {NULL, NULL, NULL, NULL}; // nic, name, password, age
int login_user() {
    char *err = NULL;
    char nic[20] = "";
    char password[20] = "";
    char name[100] = "";
    int attempts = 3;
    char *user_details; 

    while (attempts > 0) {
        //top_bar();
        printf("| USER LOGIN -------------------------\n");
        color_text(3);
        
        // Get NIC
        printf("Enter NIC Number (0 to exit): ");
        scanf("%s", nic);
        if (exit_from_0(*nic, 0)) {
            return 0;
        }

        // Get Password
        printf("Enter Password (0 to exit): ");
        scanf("%s", password);
        if (exit_from_0(*password, 0)) {
            return 0;
        }

        user_details = login_user_data(nic, password);
        color_text(0);

        if (user_details == NULL) {
            err = "NIC number not found";
            error_message(err);
            attempts--;
            if (attempts > 0 && try_again() == 0) {
                continue;
            }
            break;
        } else {
            char *db_nic = strtok(user_details, ",");
            char *db_name = strtok(NULL, ",");
            char *db_password = strtok(NULL, ",");
            char *db_age = strtok(NULL, ",");
            printf("user_details: %s\n", db_nic);
            printf("user_details: %s\n", db_name);
            printf("user_details: %s\n", db_password);
            printf("user_details: %s\n", db_age);
        }

        free(user_details);
    }

    if (attempts == 0) {
        error_message("Too many failed attempts");
    }
    exit_to();
    return 0;
}
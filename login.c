#include <stddef.h>
int login_user(){
    char nic[20];
    char password[20];
    int attempts = 3;

    while (attempts > 0) {
        //top_bar();
        printf("| USER LOGIN -------------------------\n");

        printf("Enter NIC Number: ");
        scanf("%s", nic);
        printf("Enter Password: ");
        scanf("%s", password);

        char *user_details = find_nic(nic);
        
        printf("%s", user_details); // Debugging line to see the fetched details

        if (user_details == NULL) {
            printf("\nNIC number not found\n");
            attempts--;
            continue;
        } else {
            char *nic = strtok(user_details, ",");
            char *name = strtok(NULL, ",");
            char *stored_password = strtok(NULL, ",");

            printf("\nLogin successful! Welcome, %s.\n", name);

            if (strcmp(stored_password, password) == 0) {
                printf("\nPassword is correct.\n");
                exit_to();
            } else {
                printf("\nIncorrect password. Please try again.\n");
                attempts--;
                continue;
            }
        }
        exit_to();
        break;
    }
    printf("\nToo many failed attempts. Exiting.\n");
    return 0;


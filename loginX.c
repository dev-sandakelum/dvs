#include <stdio.h>
#include <string.h>


int login_user() {
    char *nic[20];
    char password[20];
    int attempts = 3;

    while (attempts > 0) {
        top_bar();
        printf("| USER LOGIN -------------------------\n");

        printf("Enter NIC Number: ");
        scanf("%s", nic);
        printf("Enter Password: ");
        scanf("%s", password);

        if(find_nic(*nic) == 0){
            printf("\nNIC number not found. Please register first.\n");
            attempts--;
            continue;
        }else{
            printf("\nLogin successful! Welcome, %s.\n", *nic);
            return 1;
        }
        //if (strcmp(*nic, "123456789123") == 0 && strcmp(password, "pass123") == 0) {
        //    printf("\nLogin successful! Welcome, %s.\n", *nic);
        //    return 1;
        //} else {
        //    attempts--;
        //    printf("\nIncorrect username or password. You have %d attempts remaining.\n", attempts);
       // }
       exit_to();
       break;
    }

    printf("\nToo many failed attempts. Exiting.\n");
    return 0;
}


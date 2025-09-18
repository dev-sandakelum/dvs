
#include <stdio.h>
#include <stdio.h>

int save_user_to_file(char *nic, char *name, char *password, int age)
{
    FILE *users_txt = fopen("data/users.txt", "a");
    if (users_txt == NULL)
        return 0;
    fprintf(users_txt, "%s,%s,%s,%d\n", nic, name, password, age);
    fclose(users_txt);
    return 1;
}

int check_nic_exists(char *nic){
    FILE *users_txt = fopen("data/users.txt", "r");
    if (users_txt == NULL){
        return 0; 
    }
    char line[256];
    for(; fgets(line,sizeof(line),users_txt) !=NULL;){
        if (strcmp(strtok(line,","), nic) == 0){
            fclose(users_txt);
            return 1; 
        }
    }
    fclose(users_txt);
    return 0;
}
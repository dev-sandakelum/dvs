
#include <stdio.h>
#include <string.h>
#include <stddef.h>

//--------------------------------------------------------------------------------------------------
//                              Save user details to file
//--------------------------------------------------------------------------------------------------
int save_user_as_voter(char *nic, char *name, char *password, int age)
{
    FILE *users_txt = fopen("data/users.txt", "a");
    if (users_txt == NULL)
        return 0;
    fprintf(users_txt, "%s,%s,%s,%d,Mathara\n", nic, name, password, age);
    fclose(users_txt);
    return 1;
}
int save_user_as_candidate(char *nic, char *name, char *password, int age , int district, int party)
{
    FILE *candidates_txt = fopen("data/candidates.txt", "a");
    if (candidates_txt == NULL)
        return 0;
    fprintf(candidates_txt, "%s,%s,%s,%d,%d,%d\n", nic, name, password, age , district, party);
    fclose(candidates_txt);
    return 1;
}
//--------------------------------------------------------------------------------------------------
//                              Check if NIC exists
//--------------------------------------------------------------------------------------------------
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

//--------------------------------------------------------------------------------------------------
//                            Find NIC and return 1 if found, else 0
//--------------------------------------------------------------------------------------------------
char *find_nic(char *nic) {
    
    FILE *users_txt = fopen("data/users.txt", "r");
    if (users_txt == NULL){
        return NULL; 
    }
    char line[256] ,*token;
    for(; fgets(line,sizeof(line),users_txt) !=NULL;){
        if (strcmp(strtok(line, ","), nic) == 0){
            //return user details
            token = strdup(line);
            fclose(users_txt);
            return token; 
        }
    }
    fclose(users_txt);
    return NULL;
}
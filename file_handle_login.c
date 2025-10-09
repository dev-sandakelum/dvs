#include <stdio.h>
#include <string.h>
#include <stddef.h>

//--------------------------------------------------------------------------------------------------
//                              login -->>
//--------------------------------------------------------------------------------------------------

int login_by_pass(char *nic ,char *password , const char *log_type){
    FILE *user_text = fopen("data/users.txt", "r");
    if (user_text == NULL)
    {
        return 2;
    }
    char line[256] , db_nic[12] , db_name[50] , db_password[30] , db_age[3];
    while (fgets(line, sizeof(line), user_text))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,]", db_nic ,db_name, db_password , db_age );
        if(strcmp(db_nic , nic)== 0 && (strcmp(db_password , password)== 0 || (log_type != NULL && strcmp(log_type, "session") == 0))){
            save_login_session(db_nic);
            set_user(db_nic, db_name, db_password, db_age);
            fclose(user_text);
            return 1; // success
        }
    }
    fclose(user_text);
    return 0;
    
}
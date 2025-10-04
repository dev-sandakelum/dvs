#include <stdio.h>
#include <string.h>

int save_vote(char *voter_id, char *userName, int vote1, int vote2, int vote3, char *district, char **read_all_users, int u_count)
{
    //========================================================================================
    FILE *f = fopen("data/votes.txt", "a");
    if (!f)
    {
        printf("votes.txt not found\n");
        exit(1);
    }

    fprintf(f, "%s,%s,%d|%d|%d,%s\n", voter_id, userName, vote1, vote2, vote3, district);
    fclose(f);

    //========================================================================================
    char *status;
    status = "ACTIVE";
    if (remove("data/users.txt") == 0)
    {
        printf("file deleted\n");
    }
    FILE *append = fopen("data/users.txt", "a+");
    int i = 0;
    while (i < u_count)
    {
        fprintf(append, "%s", read_all_users[i]);
        i++;
    }
    char *password = request_user_password();
    char *age = request_user_age();
    fprintf(append, "%s,%s,%s,%s,Matara,%s\n", voter_id, userName, password, age, status);
    fclose(append);
    //========================================================================================
    return 0;
}
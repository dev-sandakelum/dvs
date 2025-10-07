#include <stdio.h>
#include <string.h>
char *check_login()
{
    char nic[20];
    FILE *f = fopen("data/login_save.txt", "r");
    if (f == NULL)
    {
        return "0";
    }
    if (fgets(nic, sizeof(nic), f) == NULL)
    {
        return "0";
    }
    fclose(f);
    return strdup(nic);
}
int save_login_session(char *nic)
{
    char filepath[30];
    sprintf(filepath, "data/login_save.txt");
    remove(filepath);
    FILE *f = fopen(filepath, "w+");
    fprintf(f, "%s", nic);
    fclose(f);
    return 0;
}
#include <stdio.h>
#include <string.h>

char *check_login()
{
    static char nic[20];
    FILE *f = fopen("data/login_save.txt", "r");
    if (f == NULL)
    {
        strcpy(nic, "0");
        return nic;
    }
    if (fgets(nic, sizeof(nic), f) == NULL)
    {
        fclose(f);
        strcpy(nic, "0");
        return nic;
    }
    fclose(f);
    // trim trailing newline if present
    size_t len = strlen(nic);
    if (len > 0 && (nic[len - 1] == '\n' || nic[len - 1] == '\r'))
    {
        nic[len - 1] = '\0';
    }
    return nic;
}

int save_login_session(char *nic)
{
    const char *filepath = "data/login_save.txt";
    remove(filepath);
    FILE *f = fopen(filepath, "w");
    if (!f)
    {
        return 1;
    }
    fprintf(f, "%s", nic);
    fclose(f);
    return 0;
}


int save_user_to_file(char *nic, char *name, char *password, int age)
{
    FILE *file = fopen("data/users.txt", "a");
    if (file == NULL)
        return 0;
    fprintf(file, "%s,%s,%s,%d\n", nic, name, password, age);
    fclose(file);
    return 1;
}
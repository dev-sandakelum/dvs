
int check_results_status(){
    FILE *file = fopen("data/system.txt", "r");
    if (file == NULL)
    {
        return 0; 
    }

    char line[100];
    while (fgets(line, sizeof(line), file))
    {
        sscanf(line, "results:%s", line);
        if (strcmp(line, "enable") == 0)
        {
            fclose(file);
            return 1; 
        }
        else
        {
            fclose(file);
            return 0; 
        }
    }
    fclose(file);
    return 0; 
}
int set_results_status(int enable){
    FILE *file = fopen("data/system.txt", "w");
    if (file == NULL)
    {
        return 0; 
    }
    if (enable)
    {
        fprintf(file, "results:enable\n");
    }
    else
    {
        fprintf(file, "results:disable\n");
    }
    fclose(file);
    return 1;
}
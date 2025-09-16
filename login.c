int login_user() {
    char *err = NULL;
    char nic[20];
    char password[20];
    
    top_bar();
    printf("| LOGIN -------------------------------\n");
    
    printf("  Enter your NIC number: ");
    scanf("%s", nic);
    
    printf("  Enter your password: ");
    scanf("%s", password);
    
    lines(2);
    printf("Login functionality not yet implemented.\n");
    lines(3);
    exit_to();
    
    return 0;
}
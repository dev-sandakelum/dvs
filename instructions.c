int navigate(int temp){
    switch (temp)
            {
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '0':
                return 0;
            default:
                
                break;
            }
}

int instructions()
{
    int section = 0;
    char temp;

    while (1)
    {
        top_bar();
        if (section == 0)
        {
            printf("| INSTRUCTIONS -------------------------\n");
            printf("\t1) Basic flow\n");
            printf("\t2) Data rules\n");
            printf("\t3) Voting flow\n");
            printf("\t4) Results & admin\n");
            printf("\t0) Return to main menu\n");
            lines(1);
            printf("Enter choice: ");
            scanf(" %c", &temp);
            
        }
        else if (section == 1)
        {
            printf("| INSTRUCTIONS - BASIC FLOW -----------\n");
            printf("1. User Registration\n");
            printf("2. User Login\n");
            printf("3. Voting Process\n");
            printf("4. Results Announcement\n");
            printf("\033[13;0H"); 
            lines(1);
            printf("Press any key to return: ");
            getchar();
            section = 0;
        }
        else if (section == 2)
        {
            printf("| INSTRUCTIONS - DATA RULES ------------\n");
            printf("1. Age Limit: 18 years and above\n");
            printf("2. Valid NIC required for registration\n");
            printf("3. One vote per user\n");
            lines(1);
            printf("Press any key to return: ");
            getchar();
            section = 0;
        }
        else if (section == 3)
        {
            printf("| INSTRUCTIONS - VOTING FLOW -----------\n");
            printf("1. Voting Eligibility\n");
            printf("2. Voting Process\n");
            printf("3. Vote Confirmation\n");
            lines(1);
            printf("Press any key to return: ");
            getchar();
            section = 0;
        }
        else if (section == 4)
        {
            printf("| INSTRUCTIONS - RESULTS & ADMIN -------\n");
            printf("1. Viewing Results\n");
            printf("2. Admin Controls\n");
            printf("3. User Management\n");
            lines(1);
            printf("Press any key to return: ");
            getchar();
            section = 0;
        }
        

    }

    return 0;
}

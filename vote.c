#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_CANDIDATES 50
#define MAX_USERS 50
#define MAX_DISTRICTS 10
#define MAX_PARTY 10

typedef struct
{
    char id[20];
    char name[50];
    char password[30];
    int age;
    char district[20];
    char status[10];
} User;

typedef struct
{
    char id[10];
    char name[50];
    char party[10];
    int party_no;
} Candidate;

char districts[MAX_DISTRICTS][20];
int district_count = 0;

char parties[MAX_PARTY][10];
int party_count = 0;

Candidate candidates[MAX_CANDIDATES];
int candidate_count = 0;

User users[MAX_USERS];
int user_count = 0;

// ----------------------------------------------------------------------------------------------------
//                           Function declarations - file handling
// ----------------------------------------------------------------------------------------------------
void load_users()
{
    FILE *f = fopen("data/users.txt", "r");
    if (!f)
    {
        printf("users.txt not found\n");
        exit(1);
    }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), f))
    {
        User u;
        sscanf(line, "%[^,],%[^,],%[^,],%d,%[^,],%s", u.id, u.name, u.password, &u.age, u.district, u.status);
        users[user_count++] = u;
        int found = 0;
        for (int i = 0; i < district_count; i++)
            if (strcmp(districts[i], u.district) == 0)
                found = 1;
        if (!found)
            strcpy(districts[district_count++], u.district);
    }
    fclose(f);
}

void load_candidates()
{
    FILE *f = fopen("data/candidates.txt", "r");
    if (!f)
    {
        printf("candidates.txt not found\n");
        exit(1);
    }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), f))
    {
        Candidate c;
        sscanf(line, "%[^,],%[^,],%[^,],%d", c.id, c.name, c.party, &c.party_no);
        candidates[candidate_count++] = c;
        int found = 0;
        for (int i = 0; i < party_count; i++)
            if (strcmp(parties[i], c.party) == 0)
                found = 1;
        if (!found)
            strcpy(parties[party_count++], c.party);
    }
    fclose(f);
}

User *find_user_by_id(const char *id)
{
    for (int i = 0; i < user_count; i++)
        if (strcmp(users[i].id, id) == 0)
            return &users[i];
    return NULL;
}

void show_districts()
{
    printf("Districts:\n");
    color_text(3);
    for (int i = 0; i < district_count; i++)
        printf("%d. %s\n", i + 1, districts[i]);
    color_text(0);
}

void show_parties()
{
    printf("Parties:\n");
    color_text(3);
    for (int i = 0; i < party_count; i++)
        printf("%d. %s\n", i + 1, parties[i]);
    color_text(0);
}

void show_candidates(const char *party, const char *district)
{
    // printf("Candidates for party %s in district %s:\n", party, district);
    printf("Candidates:\n");
    lines(1);
    color_text(3);
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].party, party) == 0)
            printf("%s. %s\n", candidates[i].id, candidates[i].name);
    }
    color_text(0);
}
void voter_details_section(int nic_status, char *nic, char *name, char *district, char *party);
void voted_details_section(const char *district, const char *party,const char *ids[3], const char *names[3]);

//--------------------------------------------------------------------------------------------
//                           Main vote function starts here
//--------------------------------------------------------------------------------------------
int vote_user()
{
    int section = 0, d_choice, p_choice, nic_status = 1;
    // section 0 -> enter NIC
    // section 1 -> select district
    // section 2 -> select party
    // section 3 -> select candidates
    char *district = "", *party = "", *userName = ""; // section 1 & 2 choices
    char vote1[10], vote2[10], vote3[10];             // candidate IDs for section 4
    User *user;                                       // logged in user

    char voter_id[20];

    load_users();
    load_candidates();
    while (1)
    {
        top_bar(); // from fun.c
        voter_details_section(nic_status, voter_id, userName, district, party);
        // --------------------------------------------------------------------------------------------
        //                           Section control starts here
        //                                      section 0
        // --------------------------------------------------------------------------------------------
        if (section == 0)
        {
            printf("Enter your NIC: ");
            scanf("%s", voter_id);
            user = find_user_by_id(voter_id);
            if (!user)
            {
                printf("User not found.\n");
                return 1;
            }
            userName = user->name;
            section = 1;
            continue;
        }
        // --------------------------------------------------------------------------------------------
        //                            section 2 - select district
        // --------------------------------------------------------------------------------------------
        if (section == 1)
        {
            lines(1);
            color_text(2);
            printf("Welcome %s!\n", userName);
            color_text(0);
            lines(1);

            show_districts();
            lines(1);
            printf("Select your district (number): ");
            scanf("%d", &d_choice);
            if (d_choice < 1 || d_choice > district_count)
            {
                printf("Invalid district.\n");
                return 1;
            }
            district = districts[d_choice - 1];
            section = 3;
            continue;
        }

        // --------------------------------------------------------------------------------------------
        //                            section 3 - select party
        // --------------------------------------------------------------------------------------------
        if (section == 3)
        {
            show_parties();
            lines(1);
            printf("Select your party (number): ");
            scanf("%d", &p_choice);
            if (p_choice < 1 || p_choice > party_count)
            {
                printf("Invalid party.\n");
                return 1;
            }
            party = parties[p_choice - 1]; // assign selected party
            section = 4;
            continue;
        }
        // --------------------------------------------------------------------------------------------
        //                            section 4 - select candidates
        // --------------------------------------------------------------------------------------------
        if (section == 4)
        {
            show_candidates(party, district);
            lines(1);
            printf("Enter your 3 candidate votes:\n");
            printf("  - Use candidate IDs\n");
            printf("  - All must be from the same party\n");
            lines(1);
            printf("Vote 1: ");
            scanf("%s", vote1);
            printf("Vote 2: ");
            scanf("%s", vote2);
            printf("Vote 3: ");
            scanf("%s", vote3);
            section = 5;
            continue;
        }
        // --------------------------------------------------------------------------------------------
        //                            section 5 - confirm & save vote
        // --------------------------------------------------------------------------------------------
        if (section == 5)
        {
            FILE *f = fopen("data/votes.txt", "a");
            if (!f)
            {
                printf("votes.txt not found\n");
                exit(1);
            }
            fprintf(f, "%s,%s,%s|%s|%s,%s\n", voter_id, userName, vote1, vote2, vote3, district);
            fclose(f);


            voted_details_section(district, party, (const char *[3]){vote1, vote2, vote3}, (const char *[3]){"", "", ""});
            // Update user status to VOTED
            user->status[0] = 'V'; // 'V' means VOTED
            lines(1);
            color_text(2);
            printf("Vote declared successfully!\n");
            color_text(0);
            lines(1);
            exit_to();
            return 0;
        }
    }
    printf("Exiting vote function.\n");
    exit_to();
    return 0;
}

void voter_details_section(int nic_status, char *nic, char *name, char *district, char *party)
{
    //| ---------------------------------------
    // Name:                   district:
    // NIC:                       party:
    // ----------------------------------------

    printf("| ---------------------------------------\n");

    color_text(2);
    printf("Name: %-14s   district: %s\n", name, district);

    // change color based on nic validity
    printf("NIC: ");
    if (nic_status > 0)
    {
        color_text(2);
    }
    else
    {
        color_text(1);
    }

    printf("%-12s", nic);
    color_text(2);

    printf("      party: %s\n", party);
    color_text(0);

    lines(1);
}

void voted_details_section(const char *district, const char *party,const char *ids[3], const char *names[3])
{
    //| YOUR VOTED DETAILS --------------------
    // district:  <district_name>          party: <party_name>
    //   <candidate_id> - <candidate_name>
    //   <candidate_id> - <candidate_name>
    //   <candidate_id> - <candidate_name>
    // ----------------------------------------

    printf("| YOUR VOTED DETAILS --------------------\n");

    color_text(2); 
    printf("district: %-18s party: %s\n", district, party);

    for (int i = 0; i < 3; i++)
    {
        printf("  %-10s - %s\n", ids[i], names[i]);
    }

    color_text(0); 
    printf("-----------------------------------------\n");
}

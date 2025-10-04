#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int id;
    int nic[12];
    char name[50];
    char password[30];
    int age;
    char party[10];
    int party_no;
} Candidate;

char districts[10][20];
int district_count = 0;

char parties[10][10];
int party_count = 0;

Candidate candidates[50];
int candidate_count = 0;

int user_count = 0;
char *read_all_users[50] = {};
int u_count = 0;

int primary_color = 0;
int party_color[10];

// ----------------------------------------------------------------------------------------------------
//                           Function declarations - file handling
// ----------------------------------------------------------------------------------------------------

int load_users(char *user_nic)
{
    FILE *f = fopen("data/users.txt", "r");
    if (!f)
    {
        printf("users.txt not found\n");
        exit(1);
    }
    char line[256]; // users count except logged account owner
    while (fgets(line, sizeof(line), f))
    {
        char n_id[20], n_name[50], n_password[30], n_district[20], n_status[10];
        int n_age;
        sscanf(line, "%[^,],%[^,],%[^,],%d,%[^,],%s", n_id, n_name, n_password, &n_age, n_district, n_status);

        if (strcmp(n_id, user_nic) == 0)
        {
            if (strcmp(n_status, "VOTED") == 0)
            {
                return 1;
            }
        }
        else
        {
            read_all_users[u_count++] = strdup(line);
        }

        int found = 0;
        for (int i = 0; i < district_count; i++)
            if (strcmp(districts[i], n_district) == 0)
                found = 1;
        if (!found)
            strcpy(districts[district_count++], n_district);
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
    char line[256];
    while (fgets(line, sizeof(line), f))
    {
        Candidate c;
        // sscanf(line, "%[^,],%[^,],%[^,],%d", c.id, c.name, c.party, &c.party_no);
        sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%[^,],%d", &c.id, c.nic, c.name, c.password, &c.age, &c.party, &c.party_no);
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
    {
        // BP,Blue Party,Flower,Blue
        // GA,Green Alliance,Elephant,Green
        // RM,Red Movement,Telephone,Red
        // PF,People's Front,Compass,Purple
        // NU,National Unity,Key,Orange

        switch (parties[i][0])
        {
        case 'B':
            color_text(4);
            printf("%d. %s - Blue Party\n", i + 1, parties[i]);
            party_color[i] = 4;
            break;
        case 'G':
            color_text(2);
            printf("%d. %s - Green Alliance\n", i + 1, parties[i]);
            party_color[i] = 2;
            break;
        case 'R':
            color_text(1);
            printf("%d. %s - Red Movement\n", i + 1, parties[i]);
            party_color[i] = 1;
            break;
        case 'P':
            color_text(5);
            printf("%d. %s - People's Front\n", i + 1, parties[i]);
            party_color[i] = 5;
            break;
        case 'N':
            color_text(3);
            printf("%d. %s - National Unity\n", i + 1, parties[i]);
            party_color[i] = 3;
            break;
        }
    }
    color_text(0);
}

void show_candidates(const char *party, const char *district, int p_choice)
{
    // printf("Candidates for party %s in district %s:\n", party, district);
    printf("Candidates:\n");
    lines(1);
    color_text(party_color[--p_choice]);
    for (int i = 0; i < candidate_count; i++)
    {
        if (strcmp(candidates[i].party, party) == 0)
            printf("%d. %s\n", candidates[i].id, candidates[i].name);
    }
    color_text(0);
}
// ----------------------------------------------------------------------------------------------------
//                           Function declarations - from bottom
// ----------------------------------------------------------------------------------------------------
void voter_details_section(int nic_status, char *nic, char *name, char *district, char *party);
char *find_candidate_name(int id);
void voted_details_section(char *district, char *party, int ids[3], char *names[3], int p_choice);
int try_again();
int is_candidate_in_party(int candidate_id, char *party);
// from file_handle_vote.c
int save_vote(char *voter_id, char *userName, int vote1, int vote2, int vote3, char *district, char **read_all_users, int u_count);

//--------------------------------------------------------------------------------------------
//                           Main vote function starts here
//--------------------------------------------------------------------------------------------
int vote_user(char *user_nic, char *user_name)
{
    int section = 0, d_choice, p_choice, nic_status = 1;
    // section 0 -> enter NIC
    // section 1 -> select district
    // section 2 -> select party
    // section 3 -> select candidates
    char *district = "", *party = "", *userName = ""; // section 1 & 2 choices
    int vote1, vote2, vote3;                          // candidate IDs for section 4
    // User *user;                                       // logged in user

    char voter_id[20];
    if (user_nic == NULL)
    {
        top_bar();
        printf("User NIC is not provided. \nPlease login first.\n");
        lines(1);
        exit_to();
        return 1;
    }
    strcpy(voter_id, user_nic);

    int result = load_users(user_nic);
    if (result == 1)
    {
        top_bar();
        lines(1);
        color_text(3);
        printf("User %s has already voted.\n", user_nic);
        color_text(0);
        lines(1);
        exit_to();
        return 0;
    }
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
            // printf("Enter your NIC: ");
            // scanf("%s", voter_id);
            if (user_nic == NULL || strlen(user_nic) < 12)
            {
                color_text(1);
                lines(1);
                printf("You are not logged in. Please login first.\n");
                lines(1);
                color_text(0);
                lines(1);
                exit_to();
                return 1;
            }
            userName = user_name;
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
                lines(1);
                printf("Invalid district.\n");
                if (try_again() == 1)
                {
                    return 1;
                }
                else
                {
                    continue;
                }
            }
            if (d_choice != 2 && d_choice > 0 && d_choice <= 8)
            {
                color_text(3);
                lines(1);
                printf("District boundaries matter.\n");
                lines(1);
                color_text(0);

                printf("Invalid district.\n");
                if (try_again() == 1)
                {
                    return 1;
                }
                else
                {
                    continue;
                }
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

                if (try_again() == 1)
                {
                    return 1;
                }
                else
                {
                    continue;
                }
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
            // color_text(parties[p_choice][1]);
            show_candidates(party, district, p_choice);
            color_text(0);
            lines(1);
            printf("Enter your 3 candidate votes:\n");
            color_text(2);
            printf("  - Use candidate IDs\n");
            printf("  - All must be from the same party\n");
            color_text(0);
            lines(1);
            printf("Vote 1: ");
            scanf("%d", &vote1);
            printf("Vote 2: ");
            scanf("%d", &vote2);
            printf("Vote 3: ");
            scanf("%d", &vote3);
            section = 5;
            continue;
        }
        // --------------------------------------------------------------------------------------------
        //                            section 5 - confirm & save vote
        // --------------------------------------------------------------------------------------------
        if (section == 5)
        {
            // filter votes
            if (!is_candidate_in_party(vote1, party) || !is_candidate_in_party(vote2, party) || !is_candidate_in_party(vote3, party))
            {
                lines(1);
                color_text(1);
                printf("    All votes must be for candidates\n");
                printf("         the selected party (%s).\n", party);
                color_text(0);
                if (try_again() == 1)
                {
                    return 1;
                }
                else
                {
                    section = 4; // go back to candidate selection
                    continue;
                }
            }
            //-------------- SAVING VOTE TO DB ------------------------
            save_vote(voter_id, userName, vote1, vote2, vote3, district, read_all_users, u_count);

            // complex function to show voted details --------------------------------------------------------
            voted_details_section(district, party, (int[3]){vote1, vote2, vote3}, (char *[3]){find_candidate_name(vote1), find_candidate_name(vote2), find_candidate_name(vote3)}, p_choice);
            // end of complex function ------------------------------------------------------------------------

            // Update user status to VOTED
            // user->status[0] = 'V'; // 'V' means VOTED
            lines(1);
            color_text(2);
            printf("      Vote declared successfully!\n");
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
    //-----------------------------------------
    // Name:                   district:
    // NIC:                       party:
    // ----------------------------------------

    lines(1);
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

void voted_details_section(char *district, char *party, int ids[3], char *names[3], int p_choice)
{
    //| YOUR VOTED DETAILS --------------------
    // district:           party:
    //   <candidate_id> - <candidate_name>
    //   <candidate_id> - <candidate_name>
    //   <candidate_id> - <candidate_name>
    // ----------------------------------------

    printf("| YOUR VOTED DETAILS -------------------\n");

    color_text(party_color[--p_choice]);
    printf("district: %-18s party: %s\n", district, party);

    for (int i = 0; i < 3; i++)
    {
        printf("  %-5d - %s\n", ids[i], names[i]);
    }

    color_text(0);
    lines(1);
}
char *find_candidate_name(int id)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].id == id)
        {
            return candidates[i].name;
        }
    }
    return "";
}

int is_candidate_in_party(int candidate_id, char *party)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].id == candidate_id && strcmp(candidates[i].party, party) == 0)
        {
            return 1;
        }
    }
    return 0;
}

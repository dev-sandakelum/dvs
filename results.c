#include <stdio.h>
#define MAX_CANDIDATES 30
#define MAX_PARTIES 10
// Global array to hold vote counts for 25 candidates (index 0 total votes)
int votes[MAX_CANDIDATES] = {};
char candidate_name[MAX_CANDIDATES][50] = {};
char get_parties[MAX_PARTIES][20] = {};    // party names
int party_candidates[MAX_PARTIES][2] = {}; // party index, number of candidates
int count_of_party = 0;                    // track number of parties
int order_of_party[MAX_PARTIES] = {};
int MostPopularCandidateIndex = 1;
int MostPopularPartyIndex = 0;

//-----------------------------------------------------------------------------------------------------
//              Reset results globals
//-----------------------------------------------------------------------------------------------------
void reset_results_globals()
{
    for (int i = 0; i < 25; i++)
    {
        votes[i] = 0;
        candidate_name[i][0] = '\0';
    }
    for (int i = 0; i < 10; i++)
    {
        get_parties[i][0] = '\0';
        party_candidates[i][0] = 0;
        party_candidates[i][1] = 0;
        order_of_party[i] = 0;
    }
    count_of_party = 0;
    MostPopularCandidateIndex = 1;
    MostPopularPartyIndex = 0;
}

int calculate_results();
int load_get_parties();

int view_results()
{

    if (check_results_status() == 0)
    {
        top_bar();
        printf("| ELECTION RESULTS --------------------\n");
        lines(1);
        color_text(5);
        printf("Election results are currently disabled \nby the administrator.\n");
        color_text(0);
        lines(1);
        exit_to();
        return 0;
    }
    else
    {
        while (1)
        {
            top_bar();
            load_get_parties();
            calculate_results();
            // printf("%s %d %s\n", get_parties[0], party_candidates[0][0] );
            printf("| ELECTION RESULTS --------------------\n");
            lines(1);
            printf("PARTY RESULTS:\n");
            lines(1);
            printf("|%-4s |%-23s |%-18s\n", "Rank", "Party", "Votes");
            lines(1);
            int total_votes = 0, c_num = 0;

            // Calculate total votes for each party ====================================
            for (int i = 0; i < count_of_party; i++)
            {
                total_votes = 0; // Reset for each party
                for (int j = 0; j < party_candidates[i][1]; j++)
                {
                    c_num++;
                    total_votes += votes[c_num];
                }
                order_of_party[i] = total_votes;

                // BP,Blue Party,Flower,Blue
                // GA,Green Alliance,Elephant,Green
                // RM,Red Movement,Telephone,Red
                // PF,People's Front,Compass,Purple
                // NU,National Unity,Key,Orange

                // Set color based on party initial
                if (get_parties[i][0] == 'B')
                {
                    color_text(4);
                    printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "Blue Party", total_votes);
                }
                else if (get_parties[i][0] == 'G')
                {
                    color_text(2);
                    printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "Green Alliance", total_votes);
                }
                else if (get_parties[i][0] == 'R')
                {
                    color_text(1);
                    printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "Red Movement", total_votes);
                }
                else if (get_parties[i][0] == 'P')
                {
                    color_text(5);
                    printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "People's Front", total_votes);
                }
                else if (get_parties[i][0] == 'N')
                {
                    color_text(3);
                    printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "National Unity", total_votes);
                }
                else
                {
                    color_text(0);
                    printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "Unknown", total_votes);
                }
                color_text(0);
            }
            for (int i = 1; i <= 25; i++)
            {
                if (votes[i] > votes[MostPopularCandidateIndex])
                {
                    MostPopularCandidateIndex = i;
                }
            }
            for (int i = 0; i < count_of_party; i++)
            {
                if (order_of_party[i] > order_of_party[MostPopularPartyIndex])
                {
                    MostPopularPartyIndex = i;
                }
            }

            lines(1);
            printf("Total votes cast: %d\n", votes[0] * 3);
            printf("Total voters: %d\n", votes[0]);
            lines(1);
            // ELECTION STATISTICS
            printf("ELECTION STATISTICS:\n");
            lines(1);
            printf("Most Popular Candidate: \n");
            color_text(6);
            printf("%s ", candidate_name[MostPopularCandidateIndex]);
            color_text(0);
            printf("with ");
            color_text(6);
            printf("%d", votes[MostPopularCandidateIndex]);
            color_text(0);
            printf(" votes\n");
            printf("Most Popular Party: \n");
            color_text(6);
            printf("%s ", get_parties[MostPopularPartyIndex]);
            color_text(0);
            printf("with ");
            color_text(6);
            printf("%d", order_of_party[MostPopularPartyIndex]);
            color_text(0);
            printf(" votes\n");
            // printf("Total parties: %d\n", count_of_party);

            lines(1);

            printf("1. Refresh \t");
            printf("0. Back to Main Menu\n");
            lines(1);
            char choice;
            printf("Enter your choice: ");
            scanf(" %c", &choice);
            if (choice == '0')
            {
                reset_results_globals();
                break;
            }
            else if (choice == '1')
            {
                reset_results_globals();
                continue;
            }
            else
            {
                printf("Invalid choice. Please try again.\n");
                reset_results_globals();
                continue;
            }
        }
    }
}
int calculate_results()
{
    FILE *votes_txt = fopen("data/votes.txt", "r");
    if (votes_txt == NULL)
    {
        return 2;
    }
    char line[256], voter_id[12], voter_name[50], vote_ids[30], district[20];
    int vote1, vote2, vote3;

    while (fgets(line, sizeof(line), votes_txt))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,]", voter_id, voter_name, vote_ids, district);
        sscanf(vote_ids, "%d|%d|%d", &vote1, &vote2, &vote3);
        votes[vote1]++;
        votes[vote2]++;
        votes[vote3]++;
        votes[0]++;
        // printf("%s - %s - %d - %d - %d - %s\n", voter_id ,voter_name, vote1 , vote2 , vote3 , district );
    }
    fclose(votes_txt);
    return 0;
}

int load_get_parties()
{
    FILE *candidates_txt = fopen("data/candidates.txt", "r");
    if (candidates_txt == NULL)
    {
        return 2;
    }
    char line[256], nic[12], name[50], password[30], party[20];
    int id, age, found;

    while (fgets(line, sizeof(line), candidates_txt))
    {
        sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%[^,]", &id, nic, name, password, &age, party);

        strcpy(candidate_name[id], name);
        found = 0;
        // Check if party already exists ================================
        for (int i = 0; i < count_of_party; i++)
        {
            if (strcmp(get_parties[i], party) == 0)
            {
                found = 1;
                break;
            }
        }
        // If not found, add new party ================================
        if (found == 0)
        {
            strcpy(get_parties[count_of_party], party);
            count_of_party++;

            // get_parties[0] -> Blue Party
            // get_parties[1] -> Green Alliance
            // get_parties[2] -> Red Movement
            // get_parties[3] -> People's Front
            // get_parties[4] -> National Unity
        }
        // Count candidates per party =================================
        for (int i = 0; i < count_of_party; i++)
        {
            if (strcmp(get_parties[i], party) == 0)
            {
                party_candidates[i][1]++;
                // party_candidates[i] = {[party_name],[number_of_candidates]}
                // party_candidates[0] = {Blue Party, 5}
                // party_candidates[1] = {Green Alliance, 4}

                // party_candidates[1][0] = Green Alliance
                // party_candidates[1][1] = 4
                break;
            }
        }
    }
    fclose(candidates_txt);
    return 0;
}

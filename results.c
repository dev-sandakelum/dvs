#include <stdio.h>
// Global array to hold vote counts for 25 candidates (index 0 total votes)
int votes[25] = {};
char candidate_name[25][50] = {};
char get_parties[10][20] = {}; // party names
int party_candidates[10][2] = {}; // party index, number of candidates
int count_of_party = 0; // track number of parties
int order_of_party[10] = {};
int MostPopularCandidateIndex = 1;
int MostPopularPartyIndex = 0;


void reset_results_globals() {
    for (int i = 0; i < 25; i++) {
        votes[i] = 0;
        candidate_name[i][0] = '\0';
    }
    for (int i = 0; i < 10; i++) {
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

int view_results(){

    while (1)
    {
        top_bar();
        load_get_parties();
        calculate_results();
        printf("| ELECTION RESULTS --------------------\n");
        lines(1);
        printf("PARTY RESULTS:\n");
        lines(1);
        printf("|%-4s |%-23s |%-18s\n", "Rank", "Party", "Votes");
        lines(1);
        int total_votes = 0;
        for (int i = 0; i < count_of_party; i++)
        {
            total_votes = 0; // Reset for each party
            for (int j = 0; j < party_candidates[i][1]; j++)
            {
                total_votes += votes[party_candidates[i][0] + j];
                order_of_party[i] += votes[party_candidates[i][0] + j];
            }

            // BP,Blue Party,Flower,Blue
        // GA,Green Alliance,Elephant,Green
        // RM,Red Movement,Telephone,Red
        // PF,People's Front,Compass,Purple
        // NU,National Unity,Key,Orange

            // Set color based on party initial
            if(get_parties[i][0] == 'B'){
                color_text(4);
                printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "Blue Party", total_votes);
            }else if(get_parties[i][0] == 'G'){
                color_text(2);
                printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "Green Alliance", total_votes);
            }else if(get_parties[i][0] == 'R'){
                color_text(1);
                printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "Red Movement", total_votes);
            }else if(get_parties[i][0] == 'P'){
                color_text(5);
                printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "People's Front", total_votes);
            }else if(get_parties[i][0] == 'N'){
                color_text(3);
                printf("%-4d %-3s - %-18s %6d\n", i + 1, get_parties[i], "National Unity", total_votes);
            }else{
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
        printf("Total votes cast: %d\n", votes[0]*3);
        printf("Total voters: %d\n", votes[0]);
        lines(1);
        //ELECTION STATISTICS
            printf("ELECTION STATISTICS:\n");
            lines(1);
            printf("Most Popular Candidate: \n"); 
            printf("%s with %d votes\n", candidate_name[MostPopularCandidateIndex] , votes[MostPopularCandidateIndex]);
            printf("Most Popular Party: \n");
            printf("%s with %d votes\n", get_parties[MostPopularPartyIndex] , order_of_party[MostPopularPartyIndex]);
            //printf("Total parties: %d\n", count_of_party);

        lines(1);
        for (int i = 0; i < 25; i++)
        {
            
            if (votes[i] > 0)
            {
                printf("Candidate: %-20s | Votes: %d\n", candidate_name[i], votes[i]);
            }
        }
        
        printf("1. Refresh \t");
        printf("0. Back to Main Menu\n");
        lines(1);
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if (choice == 0)
        {
            reset_results_globals();
            break;
        }
        else if (choice == 1)
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

int calculate_results(){
    FILE *votes_txt = fopen("data/votes.txt", "r");
    if (votes_txt == NULL)
    {
        return 2;
    }
    char line[256] , voter_id[12] , voter_name[50] , vote_ids[30] , district[20];
    int vote1 , vote2 , vote3;

    while (fgets(line, sizeof(line), votes_txt))
    {
        sscanf(line, "%[^,],%[^,],%[^,],%[^,]", voter_id ,voter_name, vote_ids , district );
        sscanf(vote_ids, "%d|%d|%d", &vote1 , &vote2 , &vote3 );
        votes[vote1]++;
        votes[vote2]++;
        votes[vote3]++;
        votes[0]++; 
        // printf("%s - %s - %d - %d - %d - %s\n", voter_id ,voter_name, vote1 , vote2 , vote3 , district );
    }
    fclose(votes_txt);
    return 0;
}

int load_get_parties(){
    FILE *candidates_txt = fopen("data/candidates.txt", "r");
    if (candidates_txt == NULL)
    {
        return 2;
    }
    char line[256] , nic[12] , name[50] , password[30] , party[20];
    int id , age ,found;

    while (fgets(line, sizeof(line), candidates_txt))
    {
        sscanf(line, "%d,%[^,],%[^,],%[^,],%d,%[^,]", &id ,nic, name , password , &age , party);

        strcpy(candidate_name[id], name);
        found = 0;
        for (int i = 0; i < count_of_party; i++)
        {
            if (strcmp(get_parties[i], party) == 0)
            {
                found = 1;
                break;
            }
        }
        if(found == 0){
            strcpy(get_parties[count_of_party], party);
            count_of_party++;
        }

        for (int i = 0; i < count_of_party; i++)
        {
            if (strcmp(get_parties[i], party) == 0)
            {
                if (party_candidates[i][1] == 0) {
                    party_candidates[i][0] = id; // Store first candidate ID
                }
                party_candidates[i][1]++;
            }
        } 

        
    }
    fclose(candidates_txt);
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 256
#define MAX_CANDIDATES 50
#define MAX_USERS 50
#define MAX_DISTRICTS 10
#define MAX_PARTY 10

typedef struct {
    char id[20];
    char name[50];
    char password[30];
    int age;
    char district[20];
    char status[10];
} User;

typedef struct {
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

void load_users() {
    FILE *f = fopen("users.txt", "r");
    if (!f) { printf("users.txt not found\n"); exit(1); }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), f)) {
        User u;
        sscanf(line, "%[^,],%[^,],%[^,],%d,%[^,],%s", u.id, u.name, u.password, &u.age, u.district, u.status);
        users[user_count++] = u;
        int found = 0;
        for (int i = 0; i < district_count; i++)
            if (strcmp(districts[i], u.district) == 0) found = 1;
        if (!found) strcpy(districts[district_count++], u.district);
    }
    fclose(f);
}

void load_candidates() {
    FILE *f = fopen("candidates.txt", "r");
    if (!f) { printf("candidates.txt not found\n"); exit(1); }
    char line[MAX_LINE];
    while (fgets(line, sizeof(line), f)) {
        Candidate c;
        sscanf(line, "%[^,],%[^,],%[^,],%d", c.id, c.name, c.party, &c.party_no);
        candidates[candidate_count++] = c;
        int found = 0;
        for (int i = 0; i < party_count; i++)
            if (strcmp(parties[i], c.party) == 0) found = 1;
        if (!found) strcpy(parties[party_count++], c.party);
    }
    fclose(f);
}

User* find_user_by_id(const char* id) {
    for (int i = 0; i < user_count; i++)
        if (strcmp(users[i].id, id) == 0)
            return &users[i];
    return NULL;
}

void show_districts() {
    printf("Districts:\n");
    for (int i = 0; i < district_count; i++)
        printf("%d. %s\n", i+1, districts[i]);
}

void show_parties() {
    printf("Parties:\n");
    for (int i = 0; i < party_count; i++)
        printf("%d. %s\n", i+1, parties[i]);
}

void show_candidates(const char* party, const char* district) {
    printf("Candidates for party %s in district %s:\n", party, district);
    for (int i = 0; i < candidate_count; i++) {
        if (strcmp(candidates[i].party, party) == 0)
            printf("%s. %s\n", candidates[i].id, candidates[i].name);
    }
}

int main() {
    load_users();
    load_candidates();

    char voter_id[20];
    printf("Enter your NIC: ");
    scanf("%s", voter_id);

    User* user = find_user_by_id(voter_id);
    if (!user) {
        printf("User not found.\n");
        return 1;
    }
    printf("Welcome %s!\n", user->name);

    show_districts();
    int d_choice;
    printf("Select your district (number): ");
    scanf("%d", &d_choice);
    if (d_choice < 1 || d_choice > district_count) {
        printf("Invalid district.\n");
        return 1;
    }
    char* district = districts[d_choice-1];

    show_parties();
    int p_choice;
    printf("Select your party (number): ");
    scanf("%d", &p_choice);
    if (p_choice < 1 || p_choice > party_count) {
        printf("Invalid party.\n");
        return 1;
    }
    char* party = parties[p_choice-1];

    show_candidates(party, district);

    char pref1[10], pref2[10], pref3[10];
    printf("Enter your 3 candidate preferences (IDs, same party):\n");
    printf("Preference 1: "); scanf("%s", pref1);
    printf("Preference 2: "); scanf("%s", pref2);
    printf("Preference 3: "); scanf("%s", pref3);

    FILE *f = fopen("votes.txt", "a");
    if (!f) { printf("votes.txt not found\n"); exit(1); }
    fprintf(f, "%s,%s,%s|%s|%s,%s\n", voter_id, user->name, pref1, pref2, pref3, district);
    fclose(f);

    printf("Vote declared successfully!\n");
    return 0;
}

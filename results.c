// election_no_structs.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "fun.h"

#define MAX_CANDIDATES 2000
#define MAX_PARTIES    1000

/* ------------ Parallel arrays replacing structs ------------ */
/* Candidates */
static int    cand_id[MAX_CANDIDATES];
static char   cand_name[MAX_CANDIDATES][256];
static char   cand_party_code[MAX_CANDIDATES][64];
static char   cand_party_name[MAX_CANDIDATES][256];
static char   cand_symbol[MAX_CANDIDATES][64];
static int    cand_first[MAX_CANDIDATES];
static int    cand_second[MAX_CANDIDATES];
static int    cand_third[MAX_CANDIDATES];
static int    numCandidates = 0;

/* Parties */
static char   party_code[MAX_PARTIES][64];
static char   party_name[MAX_PARTIES][256];
static char   party_symbol[MAX_PARTIES][64];
static int    party_first[MAX_PARTIES];
static int    party_second[MAX_PARTIES];
static int    party_third[MAX_PARTIES];
static int    numParties = 0;
int a;

/* Helper functions */
void End(char *text) {
    size_t len = strlen(text);
    while (len && (text[len-1]=='\n' || text[len-1]=='\r')) text[--len]='\0';
}
char* Spaces(char *text) {
    while (*text && isspace((unsigned char)*text)) text++;
    char *end = text + strlen(text);
    while (end > text && isspace((unsigned char)end[-1])) *--end = '\0';
    return text;
}
void split_Comma(char *line, char *columns[], int expectedCols) {
    int i=0;
    char *ptr=line;
    while (i<expectedCols) {
        columns[i++] = ptr;
        char *comma = strchr(ptr, ',');
        if (!comma) break;
        *comma = '\0';
        ptr = comma + 1;
    }
    while (i < expectedCols) columns[i++] = (char*)"";
}

/* Finders return -1 if not found */
int find_Party_Index(const char *code) {
    if (!code || !*code) return -1;
    for (int i=0;i<numParties;i++) if (strcmp(party_code[i], code)==0) return i;
    return -1;
}
int find_Candidate_Index(int id) {
    for (int i=0;i<numCandidates;i++) if (cand_id[i] == id) return i;
    return -1;
}

/* Add candidate votes into party totals */
void add_Votes_To_Party_fromCandidateIndex(int ci) {
    if (ci < 0 || ci >= numCandidates) return;
    int p = find_Party_Index(cand_party_code[ci]);
    if (p >= 0) {
        party_first[p]  += cand_first[ci];
        party_second[p] += cand_second[ci];
        party_third[p]  += cand_third[ci];
    }
}

/* ------------ File loaders (no structs) ------------ */
void load_Parties(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) { perror(filename); return; }
    char line[1000];
    numParties = 0;
    while (fgets(line, sizeof(line), file) && numParties < MAX_PARTIES) {
        End(line);
        char *col[4]; split_Comma(line, col, 4);
        snprintf(party_code[numParties], sizeof party_code[numParties], "%s", Spaces(col[0]));
        snprintf(party_name[numParties], sizeof party_name[numParties], "%s", Spaces(col[1]));
        snprintf(party_symbol[numParties], sizeof party_symbol[numParties], "%s", Spaces(col[2]));
        party_first[numParties] = party_second[numParties] = party_third[numParties] = 0;
        numParties++;
    }
    fclose(file);
}

void load_Candidates(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) { perror(filename); return; }
    char line[1000];
    numCandidates = 0;
    while (fgets(line, sizeof(line), file) && numCandidates < MAX_CANDIDATES) {
        End(line);
        char *col[7]; split_Comma(line, col, 7);
        cand_id[numCandidates] = atoi(Spaces(col[0]));
        snprintf(cand_name[numCandidates], sizeof cand_name[numCandidates], "%s", Spaces(col[2]));
        snprintf(cand_party_code[numCandidates], sizeof cand_party_code[numCandidates], "%s", Spaces(col[5]));
        cand_first[numCandidates] = cand_second[numCandidates] = cand_third[numCandidates] = 0;

        int pidx = find_Party_Index(cand_party_code[numCandidates]);
        if (pidx >= 0) {
            snprintf(cand_party_name[numCandidates], sizeof cand_party_name[numCandidates], "%s", party_name[pidx]);
            snprintf(cand_symbol[numCandidates], sizeof cand_symbol[numCandidates], "%s", party_symbol[pidx]);
        } else {
            cand_party_name[numCandidates][0] = cand_symbol[numCandidates][0] = '\0';
        }
        numCandidates++;
    }
    fclose(file);
}

long count_Registered_Voters(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) { perror(filename); return 0; }
    long count = 0; char line[1000];
    while (fgets(line, sizeof(line), file)) {
        char *t = Spaces(line);
        if (*t) count++;
    }
    fclose(file);
    return count;
}

/* Load votes and tally per-candidate counts, then fold into parties */
void load_Votes_And_Tally(const char *filename, long *totalBallots, long *validBallots, long *invalidBallots) {
    FILE *file = fopen(filename, "r");
    if (!file) { perror(filename); *totalBallots=*validBallots=*invalidBallots=0; return; }

    long ballots=0, valid=0, invalid=0;
    char line[1000];

    /* zero candidate and party totals before tally */
    for (int i=0;i<numCandidates;i++) cand_first[i]=cand_second[i]=cand_third[i]=0;
    for (int i=0;i<numParties;i++) party_first[i]=party_second[i]=party_third[i]=0;

    while (fgets(line, sizeof(line), file)) {
        End(line);
        char *col[4]; split_Comma(line, col, 4);
        char *pref_src = Spaces(col[2]); /* may point to literal "" */

        int hasValid = 0;
        int rank = 1;
        char prefs_copy[512] = "";
        if (pref_src && *pref_src) {
            strncpy(prefs_copy, pref_src, sizeof(prefs_copy)-1);
            prefs_copy[sizeof(prefs_copy)-1] = '\0';
        }

        char *rest = NULL;
        char *token = (prefs_copy[0]) ? strtok_r(prefs_copy, "|", &rest) : NULL;
        while (token && rank <= 3) {
            int cid = atoi(Spaces(token));
            int cidx = find_Candidate_Index(cid);
            if (cidx >= 0) {
                hasValid = 1;
                if (rank==1) cand_first[cidx]++;
                else if (rank==2) cand_second[cidx]++;
                else if (rank==3) cand_third[cidx]++;
            }
            rank++;
            token = strtok_r(NULL, "|", &rest);
        }

        if (hasValid) valid++; else invalid++;
        ballots++;
    }
    fclose(file);

    /* fold candidate totals into party totals */
    for (int i=0;i<numCandidates;i++) add_Votes_To_Party_fromCandidateIndex(i);

    *totalBallots = ballots;
    *validBallots = valid;
    *invalidBallots = invalid;
}

/* ------------ Sorting & Printing (no structs) ------------ */
/* We'll sort index arrays using qsort so we don't need structs. */

static int *cand_order = NULL;
static int *party_order = NULL;

int cand_cmp_idx(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    /* descending by first preference then name ascending */
    if (cand_first[ib] != cand_first[ia]) return cand_first[ib] - cand_first[ia];
    return strcmp(cand_name[ia], cand_name[ib]);
}
int party_cmp_idx(const void *a, const void *b) {
    int ia = *(const int*)a;
    int ib = *(const int*)b;
    if (party_first[ib] != party_first[ia]) return party_first[ib] - party_first[ia];
    return strcmp(party_name[ia], party_name[ib]);
}

void allocate_order_arrays(void) {
    if (cand_order) free(cand_order);
    if (party_order) free(party_order);
    cand_order = (int*)malloc(sizeof(int) * (numCandidates>0 ? numCandidates : 1));
    party_order = (int*)malloc(sizeof(int) * (numParties>0 ? numParties : 1));
    for (int i=0;i<numCandidates;i++) cand_order[i]=i;
    for (int i=0;i<numParties;i++) party_order[i]=i;
}

void printResults(void) {
     top_bar();
    printf("\n=== RESULT ===\n");

    if (numParties > 0) {
        int winIdx = party_order[0];
        printf("\n--- WINNING PARTY ---\n");
        printf("Party Name  : %s\n", party_name[winIdx]);
    }

    if (numCandidates > 0) {
        int winC = cand_order[0];
        printf("\n--- WINNING CANDIDATE ---\n");
        printf("Name        : %s\n", cand_name[winC]);
        printf("Party       : %s\n", cand_party_name[winC][0] ? cand_party_name[winC] : cand_party_code[winC]);
    }

    printf("\n--- PARTIES BY FIRST PREFERENCE ---\n");
    printf("%-4s | %-24s | %8s\n", "Rank", "Party", "1stVotes");
    printf("%.*s\n", 60, "------------------------------------------------------------");
    for (int i=0;i<numParties;i++) {
        int p = party_order[i];
        printf("%-4d | %-24.24s | %8d\n", i+1, party_name[p], party_first[p]);
    }

    printf("\n--- CANDIDATES BY FIRST PREFERENCE ---\n");
    printf("%-4s | %-4s | %-26s | %-22s | %-8s\n", "Rank","ID","Name","Party","1stVotes");
    printf("%.*s\n", 90, "------------------------------------------------------------------------------------------");
    for (int i=0;i<numCandidates;i++) {
        int c = cand_order[i];
        printf("%-4d | %-4d | %-26.26s | %-22.22s | %-8d\n",
               i+1, cand_id[c], cand_name[c],
               cand_party_name[c][0] ? cand_party_name[c] : cand_party_code[c],
               cand_first[c]);
    }
}

int view_results(void) {
    /* reset counts */
    numParties = 0;
    numCandidates = 0;
    if (cand_order) { free(cand_order); cand_order = NULL; }
    if (party_order) { free(party_order); party_order = NULL; }

    load_Parties("data/parties.txt");
    load_Candidates("data/candidates.txt");

    long registeredVoters = count_Registered_Voters("data/users.txt");

    long totalBallots = 0, validBallots = 0, invalidBallots = 0;
    load_Votes_And_Tally("data/votes.txt", &totalBallots, &validBallots, &invalidBallots);

    /* Prepare order arrays and sort them */
    allocate_order_arrays();
    if (numParties > 1) qsort(party_order, numParties, sizeof(int), party_cmp_idx);
    if (numCandidates > 1) qsort(cand_order, numCandidates, sizeof(int), cand_cmp_idx);

   

    printResults();
    scanf("%d", &a);
    return 0;
}


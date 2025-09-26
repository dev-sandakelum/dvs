#include <stdio.h>

int welcome_screen()
{
    int choice;
    top_bar();
    printf("Welcome to the\n");
    printf("  Digital Voting System (DVS)!\n");
    lines(1);
    printf("----------------------------------------\n");
    printf("This system enables you to:\n");
    printf("  - Register as a voter or candidate\n");
    printf("  - Cast your vote securely\n");
    printf("  - View election results\n");
    printf("\nPlease use the menu options to\n");
    printf("navigate through the system.\n");
    printf("----------------------------------------\n");
    printf("Would you like to skip instructions and\n");
    printf("proceed to the main menu?\n");
    printf("  (1. Yes  0. No): ");
    scanf("%d", &choice);
    if (choice == 1) {
        return 0;
    } else if (choice == 0) {
        instructions();
        return 3;
    }
    return 1;
}
int instructions() {
    top_bar();
    printf("INSTRUCTIONS ==========================\n");
    printf("General Instructions ------------------\n");
    printf(" - Exit any section: enter 0\n");
    printf(" - Provide accurate information\n");
    printf("Registration --------------------------\n");
    printf(" - Provide valid NIC, name, age,\n");
    printf("   and password\n");
    printf(" - Candidates select district and\n");
    printf("   party\n");
    printf(" - Must be at least 18 years old\n");
    printf(" - Each NIC can only register once\n");
    printf("Voting --------------------------------\n");
    printf(" - Select district and party\n");
    printf(" - Vote for up to 3 candidates from\n");
    printf("   the same party\n");
    printf("Results -------------------------------\n");
    printf(" - View election results\n");
    printf(" - Results are updated after voting\n");
    lines(3);
    printf("Press any key and then enter to\nproceed to the main menu: ");
    int temp;
    scanf("%d", &temp); 
    return 0;
}
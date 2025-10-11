#include <stdio.h>
#include <string.h>

#define DAYS 30

// Structure to store member details
struct Member {
    char name[50];
    int steps[DAYS];
};

// Function to analyze steps
void analyzeSteps(struct Member members[], int n) {
    for (int i = 0; i < n; i++) {
        int count = 0;
        int maxSteps = members[i].steps[0];

        // Count days exceeding 10,000 steps and find maximum step count
        for (int j = 0; j < DAYS; j++) {
            if (members[i].steps[j] > 10000)
                count++;
            if (members[i].steps[j] > maxSteps)
                maxSteps = members[i].steps[j];
        }

        // Print results for each member
        printf("\nMember Name: %s\n", members[i].name);
        printf("Days exceeding 10,000 steps: %d\n", count);
        printf("Maximum step count: %d\n", maxSteps);
    }
}

int main() {
    int n;
    printf("Enter number of members: ");
    scanf("%d", &n);

    struct Member members[n];

    for (int i = 0; i < n; i++) {
        printf("\nEnter member name: ");
        scanf("%s", members[i].name);

        printf("Enter step counts for 30 days:\n");
        for (int j = 0; j < DAYS; j++) {
            scanf("%d", &members[i].steps[j]);
        }
    }

    // Call the analysis function
    analyzeSteps(members, n);

    return 0;
}
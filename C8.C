#include<stdio.h>
#include<conio.h>

int max[100][100];
int alloc[100][100];
int need[100][100];
int avail[100];
int n, r;

void input();
void show();
void cal();

int main() {
    printf("********** Banker's Algorithm ************\n");
    input();
    show();
    cal();
    getch();
    return 0;
}

void input() {
    int i, j;
    printf("Enter the number of Processes: ");
    scanf("%d", &n);
    printf("Enter the number of resources instances: ");
    scanf("%d", &r);
    
    printf("Enter the Max Matrix\n");
    for (i = 0; i < n; i++) {
        printf("For Process P%d: ", i + 1);
        for (j = 0; j < r; j++) {
            scanf("%d", &max[i][j]);
        }
    }
    
    printf("Enter the Allocation Matrix\n");
    for (i = 0; i < n; i++) {
        printf("For Process P%d: ", i + 1);
        for (j = 0; j < r; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }
    
    printf("Enter the available Resources\n");
    for (j = 0; j < r; j++) {
        scanf("%d", &avail[j]);
    }
}

void show() {
    int i, j;
    printf("\nProcess\tAllocation\tMax\tAvailable\n");
    for (i = 0; i < n; i++) {
        printf("P%d\t", i + 1);
        for (j = 0; j < r; j++) {
            printf("%d ", alloc[i][j]);
        }
        printf("\t");
        for (j = 0; j < r; j++) {
            printf("%d ", max[i][j]);
        }
        printf("\t");
        if (i == 0) {
            for (j = 0; j < r; j++) {
                printf("%d ", avail[j]);
            }
        }
        printf("\n");
    }
}

void cal() {
    int finish[100], flag, k, c1 = 0;
    int work[100];
    int safe[100];
    int i, j;
    
    // Initialize finish array to all zeros
    for (i = 0; i < n; i++) {
        finish[i] = 0;
    }
    
    // Initialize work to available resources
    for (j = 0; j < r; j++) {
        work[j] = avail[j];
    }
    
    flag = 1;
    printf("\nSafe sequence is: ");
    while (flag) {
        flag = 0;
        for (i = 0; i < n; i++) {
            if (finish[i] == 0) {
                int c = 0;
                for (j = 0; j < r; j++) {
                    if (need[i][j] <= work[j]) {
                        c++;
                    }
                }
                if (c == r) {
                    for (j = 0; j < r; j++) {
                        work[j] += alloc[i][j];
                    }
                    printf("P%d -> ", i + 1);
                    safe[c1++] = i + 1;
                    finish[i] = 1;
                    flag = 1;
                }
            }
        }
    }
    printf("\n");

    if (c1 == n) {
        printf("\nThe system is in a safe state.\n");
        printf("Safe sequence: ");
        for (i = 0; i < n; i++) {
            printf("P%d", safe[i]);
            if (i != n - 1) {
                printf(" -> ");
            }
        }
        printf("\n");
    } else {
        printf("\nProcesses are in deadlock.\n");
        printf("System is in an unsafe state.\n");
    }
}

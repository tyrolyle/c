#include<stdio.h>
#include<conio.h>

int main() {
    int i = 0, j = 0, k = 0, i1 = 0, m, n, rs[30], flag = 1, p[30];

    clrscr(); // Clear screen

    printf("FIFO page replacement algorithm....\n");
    printf("Enter the number of frames: ");
    scanf("%d", &n);
    printf("Enter the reference string: ");

    while (1) {
        scanf("%d", &rs[i]);
        if (rs[i] == 0)
            break;
        i++;
    }
    m = i;

    for (j = 0; j < n; j++)
        p[j] = -1;

    for (i = 0; i < m; i++) {
        flag = 1;
        for (j = 0; j < n; j++) {
            if (p[j] == rs[i]) {
                printf("Data already in page...\n");
                flag = 0;
                break;
            }
        }
        if (flag == 1) {
            p[i1] = rs[i];
            i1++;
            if (i1 == n)
                i1 = 0;
            k++;
            for (j = 0; j < n; j++) {
                printf("\nPage %d: %d", j + 1, p[j]);
                if (j == i1)
                    printf("*");
            }
            printf("\n\n");
        }
    }
    printf("Total number of page faults = %d\n", k);
    
    getch(); // Wait for key press before exiting
    return 0;
}

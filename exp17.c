#include <stdio.h>

int main() {
    int n, m;
    printf("Enter processes and resources: ");
    scanf("%d %d", &n, &m);

    int alloc[n][m], max[n][m], need[n][m], avail[m];

    printf("Enter Allocation Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &alloc[i][j]);

    printf("Enter Max Matrix:\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            scanf("%d", &max[i][j]);
            need[i][j] = max[i][j] - alloc[i][j];
        }

    printf("Enter Available Resources:\n");
    for (int i = 0; i < m; i++)
        scanf("%d", &avail[i]);

    int finish[n], safe[n], k = 0;
    for (int i = 0; i < n; i++) finish[i] = 0;

    for (int count = 0; count < n; count++) {
        for (int i = 0; i < n; i++) {
            if (!finish[i]) {
                int j;
                for (j = 0; j < m; j++)
                    if (need[i][j] > avail[j])
                        break;

                if (j == m) {
                    for (int y = 0; y < m; y++)
                        avail[y] += alloc[i][y];
                    safe[k++] = i;
                    finish[i] = 1;
                }
            }
        }
    }

    printf("Safe Sequence: ");
    for (int i = 0; i < n; i++)
        printf("P%d ", safe[i]);

    return 0;
}

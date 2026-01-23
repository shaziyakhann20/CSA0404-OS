#include <stdio.h>
#include <string.h>

struct file {
    char name[20];
};

int main() {
    struct file dir[50];
    int n = 0, choice;
    char fname[20];
    int found;

    do {
        printf("\n--- Single Level Directory ---");
        printf("\n1. Create File");
        printf("\n2. Display Files");
        printf("\n3. Delete File");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter file name to create: ");
            scanf("%s", fname);

            found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(dir[i].name, fname) == 0) {
                    found = 1;
                    break;
                }
            }

            if (found)
                printf("File already exists!\n");
            else {
                strcpy(dir[n].name, fname);
                n++;
                printf("File created successfully.\n");
            }
            break;

        case 2:
            if (n == 0)
                printf("Directory is empty.\n");
            else {
                printf("Files in directory:\n");
                for (int i = 0; i < n; i++)
                    printf("%s\n", dir[i].name);
            }
            break;

        case 3:
            printf("Enter file name to delete: ");
            scanf("%s", fname);

            found = 0;
            for (int i = 0; i < n; i++) {
                if (strcmp(dir[i].name, fname) == 0) {
                    found = 1;
                    for (int j = i; j < n - 1; j++)
                        dir[j] = dir[j + 1];
                    n--;
                    printf("File deleted successfully.\n");
                    break;
                }
            }

            if (!found)
                printf("File not found.\n");
            break;

        case 4:
            printf("Exiting program.\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 4);

    return 0;
}

#include <stdio.h>
#include <string.h>

struct user {
    char uname[20];
    char files[10][20];
    int fcount;
};

int main() {
    struct user u[10];
    int ucount = 0, choice;
    char uname[20], fname[20];

    do {
        printf("\n--- Two Level Directory ---");
        printf("\n1. Create User");
        printf("\n2. Create File");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter user name: ");
            scanf("%s", u[ucount].uname);
            u[ucount].fcount = 0;
            ucount++;
            printf("User created.\n");
        }

        else if (choice == 2) {
            printf("Enter user name: ");
            scanf("%s", uname);
            for (int i = 0; i < ucount; i++) {
                if (strcmp(u[i].uname, uname) == 0) {
                    printf("Enter file name: ");
                    scanf("%s", fname);
                    strcpy(u[i].files[u[i].fcount], fname);
                    u[i].fcount++;
                    printf("File created.\n");
                }
            }
        }

        else if (choice == 3) {
            for (int i = 0; i < ucount; i++) {
                printf("\nUser: %s", u[i].uname);
                for (int j = 0; j < u[i].fcount; j++)
                    printf("\n  %s", u[i].files[j]);
            }
        }
    } while (choice != 4);

    return 0;
}

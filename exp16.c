#include <stdio.h>

struct emp {
    int id;
    char name[20];
    float salary;
};

int main() {
    FILE *fp;
    struct emp e;
    int choice, id;

    fp = fopen("emp.dat", "rb+");
    if (!fp)
        fp = fopen("emp.dat", "wb+");

    do {
        printf("\n1.Add  2.Display  3.Search  4.Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter id name salary: ");
            scanf("%d %s %f", &e.id, e.name, &e.salary);
            fwrite(&e, sizeof(e), 1, fp);
        }

        else if (choice == 2) {
            rewind(fp);
            while (fread(&e, sizeof(e), 1, fp))
                printf("\n%d %s %.2f", e.id, e.name, e.salary);
        }

        else if (choice == 3) {
            printf("Enter id: ");
            scanf("%d", &id);
            rewind(fp);
            while (fread(&e, sizeof(e), 1, fp)) {
                if (e.id == id)
                    printf("\nFound: %s %.2f", e.name, e.salary);
            }
        }
    } while (choice != 4);

    fclose(fp);
    return 0;
}

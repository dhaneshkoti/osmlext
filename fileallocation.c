#include <stdio.h>
#include <stdlib.h>

int main() {
    int f[50], index[50], i, n, st, len, j, c, k, ind, count = 0;

    for (i = 0; i < 50; i++)
        f[i] = 0;

    while (1) {
        printf("Enter the index block: ");
        scanf("%d", &ind);

        if (f[ind] != 1) {
            printf("Enter the number of blocks needed and number of files for the index %d on the disk:\n", ind);
            scanf("%d", &n);
        } else {
            printf("%d index is already allocated \n", ind);
            continue;
        }

        printf("Enter the blocks for the files:\n");
        count = 0;
        for (i = 0; i < n; i++) {
            scanf("%d", &index[i]);
            if (f[index[i]] == 0)
                count++;
        }

        if (count == n) {
            for (j = 0; j < n; j++)
                f[index[j]] = 1;
            f[ind] = 1; // Mark index block as used
            printf("Allocated\n");
            printf("File Indexed\n");
            for (k = 0; k < n; k++)
                printf("%d -> %d : %d\n", ind, index[k], f[index[k]]);
        } else {
            printf("One or more blocks are already allocated. Try again.\n");
            continue;
        }

        printf("Do you want to enter more files? (Yes - 1 / No - 0): ");
        scanf("%d", &c);
        if (c == 0)
            break;
    }

    return 0;
}

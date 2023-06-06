#include <stdio.h>
#include <string.h>

int main() {
    char a[30], fs[50] = "", sd, ed, s[2], d[2];
    printf("Enter characters to be stuffed:");
    scanf("%s", a);
    printf("\nEnter a character that represents starting delimiter:");
    scanf(" %c", &sd);
    printf("\nEnter a character that represents ending delimiter:");
    scanf(" %c", &ed);
    s[0] = sd;
    s[1] = '\0';
    d[0] = ed;
    d[1] = '\0';
    strcat(fs, s);
    for (int i = 0; i < strlen(a); i++) {
        if (a[i] == sd) {
            strcat(fs, s);
        } else if (a[i] == ed) {
            strcat(fs, d);
        }
        fs[strlen(fs)] = a[i];
        fs[strlen(fs) + 1] = '\0';
    }
    strcat(fs, d);
    printf("\n After stuffing:%s", fs);
    return 0;
}



#include <stdio.h>

int main() {
    int a[20], b[30], i, j = 0;
    int n, count = 0;

    printf("Enter frame length: ");
    scanf("%d", &n);

    printf("Enter input frame (0's & 1's only): ");
    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for (i = 0; i < n; i++) {
        b[j] = a[i];

        if (a[i] == 1) {
            count++;

            if (count == 5) {
                j++;
                b[j] = 0;
                count = 0;
            }
        } else {
            count = 0;
        }

        j++;
    }

    printf("After stuffing the frame is: ");
    for (i = 0; i < j; i++) {
        printf("%d", b[i]);
    }

    return 0;
}

#include<stdio.h>
#include<string.h>

void main()
{
    char a[50], fs[50] = "", sd, ed, s[2], d[2];
    printf("Enter The String\n");
    scanf("%s", &a);
    printf("Enter The Starting Delimiter\n");
    scanf("%s", &sd);
    printf("Enter The Ending Delimiter\n");
    scanf("%s", &ed);
    s[0] = sd;
    s[1] = '\0';
    d[0] = ed;
    d[1] = '\0';

    strcat(fs, s);

    for (int i = 0; i < strlen(a); i++)
    {
        if(a[i]==sd)
        {
            strcat(fs, s);
        }else if (a[i] == ed)
        {
            strcat(fs, d);
        }
        fs[strlen(fs)] = a[i];
        fs[strlen(fs) + 1] = '\0';
    }
    strcat(fs, d);
    printf("Stuffed String %s" ,fs);
}

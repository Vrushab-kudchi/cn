#include<stdio.h>
#include<stdlib.h>

void main()
{
    int i,opt;
    char message[100];
    printf("Enter The Message \n");
    scanf("%s" ,message);
    while (1)
    {
        printf("\nEnter a Choice \n");
        printf("1. Encrypt the data\n2. Decrypt the data\n3. Exit\n");
        scanf("%d" ,&opt);

        switch(opt)
        {
            case 1:
                for (i = 0; (i < 100 && message[i] != 0); i++)
                {
                    message[i] = message[i] + 3;
                }
                printf("Encrypted Message :  %s" ,message);
                break;

            case 2:
                for (i = 0; (i < 100 && message[i] != 0);i++)
                {
                    message[i] = message[i] - 3;
                }
                printf("Decrpted Message  :   %s" ,message);
                break;

            case 3:
                exit(0);
                break;
            }
    }
}

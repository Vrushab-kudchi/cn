#include<stdio.h>

void main()
{
    int i,j=0,a[50],b[50],count=0,n;
    printf("Enter the Size of Frame\n");
    scanf("%d" ,&n);
    for (i = 0; i < n;i++)
    {
        printf("Enter the Frame only 0 And 1 Allowed Frame:%d\n",i);
        scanf("%d", &a[i]);
    }
    for (i = 0; i < n; i++)
    {
        b[j] = a[i];

        if (a[i] == 1)
        {
            count++;
            if(count == 5)
            {
                j++;
                b[j] = 0;
                count = 0;
            }
        }
        else
        {
            count = 0;
        }
        j++;
    }
    printf("The Frame After Transmission Is : ");
    for (i = 0; i < j;i++)
    {
        printf("%d",b[i]);
    }
}

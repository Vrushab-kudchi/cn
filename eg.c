#include<stdio.h>

void main()
    {
       int a[50],b[50],n,j=0,count=0,i=0;
       printf("Enter the Size of Frame\n");
       scanf("%d" ,&n);
       printf("Enter Bits Only 0 And 1 \n");
       for(i=0; i<n ;i++)
       {
            scanf("%d" ,&a[i]);
       }
       for(i=0; i<n;i++)
       {
            b[j] = a[i];
            if (a[i] == 1)
            {
                count++;
                if(count == 5)
                {
                    j++;
                    b[j]=0;
                    count=0;
                }
            }
            else
            {
                count = 0;
            }
            j++;
       }
       for(i=0;i<n;i++)
       {
            printf("%d" ,b[i]);
       }
    }

#include<stdio.h>

void main()
{
    int frame[100], w, i,f;
    printf("Enter the size of window \n");
    scanf("%d" ,&w);
    printf("Enter the Number of Frames \n");
    scanf("%d" ,&f);
    printf("Enter Total No of %d \n",f);
    for (i = 1; i <=f;i++)
    {
        scanf("%d", &frame[i]);
    }
    printf("By Using Sliding window protocol you recieve a ack when %d Frames are send\n" ,w);
    for (i = 1; i <=f;i++)
    {
        if(i%w==0)
        {
            printf("%d \t", frame[i]);
            printf("\nAck Recieved after sending the Frames \n");
        }
        else
        {
            printf("%d \t" ,frame[i]);
        }
        if(f%w != 0)
        {
            printf("Ack  Recieved\n");
        }
    }
}

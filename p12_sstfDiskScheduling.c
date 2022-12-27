#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n,head;
    printf("\nEnter total no. of requests: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter requests: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);

    int count=0,move=0;

    printf("\nSeek Sequence:\n");

    while(count!=n)
    {
        int min=1000,diff,index;
        for(int i=0;i<n;i++)
        {
            diff=abs(arr[i]-head);
            if(min>diff)
            {
                min=diff;
                index=i;
            }
        }
        move+=min;
        head=arr[index];
        printf("%d\n",arr[index]);
        arr[index]=1000;
        count++;
    }
    printf("\nTotal Head Movement: %d\n\n",move);
    return 0;
}

/*
Enter total no. of requests: 8
Enter requests: 176 79 34 60 92 11 41 114
Enter initial head position: 50

Seek Sequence:
41
34
11
60
79
92
114
176

Total Head Movement: 204
*/
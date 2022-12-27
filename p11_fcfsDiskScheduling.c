#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n,head,move=0;
    printf("\nEnter total no. of requests: ");
    scanf("%d",&n);

    int arr[n];
    printf("Enter requests: ");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("Enter initial head position: ");
    scanf("%d",&head);
    
    for(int i=0;i<n;i++)
    {
        move+=abs(arr[i]-head);
        head=arr[i];
    }

    printf("\nTotal Head Movement: %d\n",move);
    
    return 0;
}
/*
Enter total no. of requests: 7
Enter requests: 82 170 43 140 24 16 190
Enter initial head position: 50

Total Head Movement: 642
*/
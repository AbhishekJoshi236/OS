#include <stdio.h>
#include <math.h>
int req[30], sreq[30];
int n, endrange;
int startpos, headpos;
int totst;
int i, j;

void sortRequest()
{
    for (i = 0; i < n; i++)
        sreq[i] = req[i];
    for (i = 0; i < n - 1; i++)
        for (j = i + 1; j < n; j++)
            if (sreq[i] > sreq[j])
            {
                int temp = sreq[i];
                sreq[i] = sreq[j];
                sreq[j] = temp;
            }
}

int main()
{
    printf("\nEnter no. of requests: ");
    scanf("%d", &n);
    printf("\nEnter the requests: ");
    for (i = 0; i < n; i++)
        scanf("%d", &req[i]);
    printf("\nEnter the max range: ");
    scanf("%d", &endrange);
    printf("\nEnter the initial position of head: ");
    scanf("%d", &startpos);
    
    totst = 0;
    headpos = startpos;
    printf("\n");
    printf("%d ", headpos);
    sortRequest();
    for (i = 0; i < n; i++)
    {
        if (headpos < sreq[i])
        {
            for (j = i - 1; j >= 0; j--)
            {
                totst += abs(headpos - sreq[j]);
                headpos = sreq[j];
                printf(" -> %d", headpos);
            }

            totst += abs(headpos - 0);
            headpos = 0;
            printf(" -> 0");
            totst += abs(endrange - 0);
            headpos = endrange;
            printf(" -> %d", headpos);
            break;
        }
    }
    for (j = n - 1; j >= i; j--)
    {
        totst += abs(headpos - sreq[j]);
        headpos = sreq[j];
        printf(" -> %d", headpos);
    }
    printf("\n\nTotal seek time is %d", totst);

    return 0;
}
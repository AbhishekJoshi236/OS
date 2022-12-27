#include<stdio.h>
#include<stdlib.h>

int main(){

    int n;
    printf("\n\nAssumed range(0-199)\nMovement: Towards lower value.\nTotal Requests: ");
    scanf("%d",&n);

    int req[n];
    printf("\nEnter req: ");
    for(int i=0;i<n;i++){
        scanf("%d",&req[i]);
    }

    int head;
    printf("\nHead pos: ");
    scanf("%d",&head);


    //sorting req array
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(req[j] > req[i]){
                int temp = req[i];
                req[i] = req[j];
                req[j] = temp;
            }
        }
    }

  

    int i,move=0;
    printf("\nMovement: %d",head);

    // MOVEMENT TOWARDS LOWER VALUE.
    for(i=0;i<n;i++){
        if(req[i] > head){

            for(int j=i-1;j>=0;j--){
                move+= abs(head-req[j]);
                head = req[j];
                printf(" -> %d",head);
            }

            move+=abs(head-0);
            head=0;
            printf(" -> %d",head);
            break;
        }
    }

    for(;i<n;i++){
        move += abs(head-req[i]);
        head = req[i];
        printf(" -> %d",head);
    }

    //MOVEMENT TOWARDS HIGHER VALUE.
    // for(i=0;i<n;i++){
    //     if(req[i] < head){

    //         for(int j=i-1;j>=0;j--){
    //             move += abs(head-req[j]);
    //             head = req[j];
    //             printf(" -> %d",head);
    //         }

    //         move += abs(head-199);
    //         head=199;
    //         printf(" -> %d",head);
    //         break;
    //     }
    // }

    // for(;i<n;i++){
    //     move += abs(head-req[i]);
    //     head = req[i];
    //     printf(" -> %d",head);
    // }

    printf("\n\nTotal MOVE: %d",move);

    return 0;
}

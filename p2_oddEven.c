#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(){

    int arr[10]={1,4,71,3,49,91,34,16,5,19};
    int even=0,odd=0;
    int x = fork();
    if(x!=0){
        for(int i=0;i<10;i++){
            if(arr[i]%2!=0){
                odd+=arr[i];
            }
        }
        printf("\nOdd sum: %d",odd);
    }
    else{
        for(int i=0;i<10;i++){
            if(arr[i]%2==0){
                even+=arr[i];
            }
        }
        printf("\nEven sum: %d",even);
    }
    return 0;
}
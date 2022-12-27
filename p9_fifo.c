#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool find (int b[],int ele,int s){
    for(int i=0;i<s;i++){
        if(b[i]==ele)
            return true;
    }
    return false;
}
void print(int b[],int s){
    for(int i=0;i<s;i++){
        printf("%d\t",b[i]);
    }
    printf("\n");
}
int main(){

    int n,s;
    printf("\nEnter no. of pages: ");
    scanf("%d",&n);

    int a[n];
    printf("\nEnter the page numbers: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    printf("\nEnter the frame size: ");
    scanf("%d",&s);

    int b[s];
    for(int i=0;i<s;i++){
        b[i]=-1;
    }

    printf("\n");
    int ptr=-1,count=0;
    for(int i=0;i<n;i++){

        int ele = a[i];

        if(!find(b,ele,s)){
            ptr = (ptr+1)%s;
            b[ptr] = ele;
            count++;
        }
        print(b,s);
    }

    printf("\nPage Fault: %d\n",count);
    return 0;
}
//5 6 5 4 1 6 10 4 12 0 1 20
#include <stdio.h>
#include<stdlib.h>
#include<stdbool.h>

bool find(int frame[],int ele,int s){
    for(int i=0;i<s;i++){
        if(ele == frame[i])
            return true;
    }
    return false;
}

int index(int frame[],int ele,int s){
    for(int i=0;i<s;i++){
        if(ele==frame[i])
            return i;
    }
    return 0;
}

void print(int frame[],int s){
    for(int i=0;i<s;i++){
        printf("%d  ",frame[i]);
    }
    printf("\n");
}
int main(){

    int n;
    printf("\nTotal no of pages: ");
    scanf("%d",&n);

    int a[n];
    printf("\nEnter pages: ");
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }

    int s;
    printf("\nEnter Frame Size: ");
    scanf("%d",&s);
    
    int frame[s];
    for(int i=0;i<s;i++){
        frame[i]=-1;
    }

    int ptr=0,fault=0;
    for(int i=0;i<n;i++){
        int ele = a[i];
        if(!find(frame,ele,s)){

            
            if(ptr<s){
                // printf("ptr: %d\n",ptr);
                frame[ptr] = ele;
                ptr++;
                fault++;
            }
            else{
                int vis[s];
                for(int k=0;k<s;k++){
                    vis[k]=0;
                }
                int count=0;
                for(int j=i-1;j>=0;j--){
                    int ch = a[j];
                    if(find(frame,ch,s) && vis[index(frame,ch,s)]==0){
                        count++;
                        vis[index(frame,ch,s)]=1;
                        if(count == s){
                            frame[index(frame,ch,s)]=ele;
                            fault++;
                            break;
                        }      
                    }
                }
            }
        }
        print(frame,s);
        
    }

    printf("\nFault: %d",fault);

    return 0;
}
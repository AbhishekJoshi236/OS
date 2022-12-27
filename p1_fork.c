#include<stdio.h>
#include<unistd.h>
int main(){

    fork();
    printf("\nProcess ID: %d",getpid());
    return 0;
}
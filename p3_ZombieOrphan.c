#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
//zombie
// int main(){

//     int x = fork();
//     if(x==0){
//         printf("Process Id: %d",getpid());
//         printf("Process ID: %d",getppid());
//     }
//     else{
//         sleep(5);
//         printf("Process ID: %d",getpid());
//     }

//     return 0;
// }

//orphan
int main(){

    int x = fork();
    if(x==0){
        sleep(5);
        printf("Child Id: %d",getpid());
        printf("Process ID: %d",getppid());
    }
    else{
        printf("Process ID: %d",getpid());
    }

    return 0;
}
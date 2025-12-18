/*37. Write a C program where the parent process sends a number to child process using PIPE and
child process computes the factors of that number*/

#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main(){
    int fd[2];
    pipe(fd);
    pid_t pid=fork();
    if(pid>0){
        close(fd[0]);
        int n;
        printf("ENter Number: ");
        scanf("%d",&n);
        write(fd[1],&n,sizeof(n));
    }
    else if(pid==0){
        close(fd[1]);
        int a;
        read(fd[0],&a,sizeof(a));
        for(int i=1;i<=a;i++){
            if(a%i==0) printf("%d ",i);
        }
        
    }
    
}
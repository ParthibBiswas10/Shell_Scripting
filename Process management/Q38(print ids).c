/*Write a C program that will create a child process by using the fork() system call , the parent
process will print the PID of itself, as well as the PID of the child. The child process will also
print the PID of its parent as well as the PID of itself*/\

#include <stdio.h>
#include<unistd.h>
#include<sys/types.h> //coz used pid_t
int main(){
pid_t pid=fork();
if(pid<0) printf("Error");
else if(pid==0){
    printf("Child Process\n");
    printf("Child Process id: %d\n",getpid());
    printf("Parent Process id: %d\n\n",getppid());

}
else if(pid>0){
    printf("Parent Process\n");
    printf("Parent Process id: %d\n",getpid());
    printf("Child Process id: %d\n",pid);

}
}
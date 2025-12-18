/*0. Write a C program where parent process send a number to child process using PIPE and child
process compute all the prime numbers from 1 to that number.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int isPrime(int a){
    if(a<=1) return 0;
    else{
        for(int i=2;i*i<=a;i++){
            if(a%i==0) return 0;
        }
        return 1;
    }
    
}
int main() {
    int fd[2];
    pipe(fd);

    pid_t pid = fork();

    if (pid < 0) {
        printf("Error\n");
    }
    else if(pid>0) {             
        int n;
        close(fd[0]);
        printf("Enter a Number: ");
        scanf("%d", &n);
        write(fd[1], &n, sizeof(n));
    }
    else if (pid == 0) {       
        int a;
        close(fd[1]);
        int size = read(fd[0], &a, sizeof(a));
        for(int i=1;i<=a;i++){
            if(isPrime(i))
                printf("%d ",i);
        }
        
    }
    return 0;
}


/*
    Explantion:

         “Put the number n into the pipe so the child can take it out.”

fd[1] — WHERE to send
fd[1] is the write end of the pipe
Means: “Send data into the pipe”

&n — WHAT to send
n = the number you entered
&n = address of that number in memory
Means: “Start sending data from here”
(Computer needs an address to know where the data is)

sizeof(n) — HOW MUCH to send
Tells the computer how many bytes



*/
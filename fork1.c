#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
int main()
{
pid_t p=fork();
if(p==0)
{
printf("Child process");
}
else
{
printf("Parent process");
wait(NULL);
printf("Child has terminated");
}
printf("BYE");
}

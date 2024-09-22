#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
int main()
{
char *command="ls";
char *arg_list[]={"ls","-l",NULL};
printf("before calling execvp()\n");
printf("creating another process using fork()\n");
pid_t p=fork();
int status=0;
if(p==0)
{
printf("child process\n");
status=execvp(command,arg_list);
if(status==-1)
{
printf("incorrect termination\n");
exit(1);
}
}
else
{
printf("parent process\n");
wait==NULL;
printf("now this line will be executed\n");
}
}

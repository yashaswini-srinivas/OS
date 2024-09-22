#include<stdio.h>
#include<unistd.h>
int main()
{
char *command="ls";
char *arg_list[]={"ls","-l",NULL};
printf("before calling execvp()\n");
printf("creating another process using fork() \n");
pid_t p=fork();
int status=0;
if(p==0)
{
status=execvp(command,arg_list);
if(status==-1)
{
printf("incorrect termination\n");
}
}
else
{
printf("parent process\n");
printf("status:%d\n",status);
printf("now this line will be executed\n");
}
}




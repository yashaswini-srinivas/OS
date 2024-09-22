#include<stdio.h>
#include<unistd.h>
int main()
{
char *command="ls";
char *arg_list[]={"ls","-l", NULL};
printf("before calling execvp()\n");
int status=execvp(command,arg_list);
printf("status:%d\n",status);
}

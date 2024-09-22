#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
int main()
{
pid_t p=fork();
if(p<0){
printf("fork fail");
exit(1);
}
else if(p==0){
printf("i am a child process with id:%d",getpid());
printf("my parent id is %d",getpid());
}
else
{
printf("i am a parent processwith id:%d",getpid());
printf("my child process is %d",p);
}
}

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define FIFO_NAME "mfifo"
#define SIZE 100
int main()
{
int fd;
char data[SIZE];
fd=open(FIFO_NAME,O_WRONLY);
if(fd==-1)
{
printf("Failure in opening the file");
exit(1);
}
printf("Enter the message:");
gets(data);
write(fd,data,strlen(data)+1);
close(fd);
}

#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>
#define FIFO_NAME "mfifo"
#define BUFFER_SIZE 100
int main()
{
int fd;
char data[BUFFER_SIZE];
fd=open(FIFO_NAME, O_RDONLY);
if(fd==-1)
{
printf("Error opening the FIFO for reading");
exit(0);
}
ssize_t bytes=read(fd,data,BUFFER_SIZE);
printf("Received:%s",data);
close(fd);
}

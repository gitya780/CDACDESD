#include<stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include<unistd.h>
#include<string.h>
#define size 64
int main(int argc, char const *argv[])
{
    unsigned char buff[size];
    int pfd[2];
    int pfdr[2];
pid_t id;
pipe(pfd);
pipe(pfdr);
id=fork();
if(id==0)
{
   printf("child\n");
    int fd;
    fd=open("file.txt",O_WRONLY|O_CREAT,S_IRUSR,S_IWUSR);
if (fd ==-1)
{
    perror("error opening the file");
    exit(EXIT_FAILURE);

}   
write(fd,"memory\n",7);
close(fd);
exit(EXIT_SUCCESS);

close(pfd[0]);
write(pfd[1],"mermory\n",7);
close(pfd[1]);
}
else
{
    printf("parent\n");
    close(pfd[1]);
    read(pfd[0],buff,size);
    printf("got the data:%s\n",buff);
    printf("got the data:%ld\n",strlen(buff));
    close(pfd[0]);
}
    
    return 0;
}

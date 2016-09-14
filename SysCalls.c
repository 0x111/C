#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    char *path1 = "lolka.txt";
    char *path2 = "allahuakbar.txt";
    
    int test = creat (path2, 0777); //Creating with 0777 permissions
    if (close(test) == -1) {
        return -2;
    }
    int fd = open(path1, O_RDONLY); //O_RDONLY, O_CREAT, OWRONLY, O_APPEND
    if (fd == -1) {
        return -1; //Testing openned succesfully
    }
    printf("Input num of bytes from lolka.txt ");
    int bufsize, temp;
    scanf("%d", &bufsize);
    char *buff = calloc(bufsize, sizeof(char));
    int diff = bufsize;
    while (diff > 0) {
        temp = read(fd, buff + sizeof(char) * (bufsize-diff), diff);
        diff -= temp;  
    }
    printf("%s", buff);
    int offset = lseek(fd, change, SEEK_SET); //SEEK_CUR, SEEK_END
    close(fd);
    
}

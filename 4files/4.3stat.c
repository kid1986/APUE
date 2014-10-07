#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[])
{
    int i;
    struct stat buf;
    char *ptr;

    for(i=1;i<argc;i++)
    {
        printf("%s: ",argv[i]);
        if(lstat(argv[i],&buf) < 0)
        {
            fprintf(stderr,"lstat error");
            continue;
        }
    } 
    
    if(S_ISREG(buf.st_mode))
        ptr = "regular";
    else if(S_ISDIR(buf.st_mode))
        ptr = "directory";
    else if(S_ISCHR(buf.st_mode))
        ptr = "character special";
    else if(S_ISBLK(buf.st_mode))
        ptr = "block special";
    else if(S_ISFIFO(buf.st_mode))
        ptr = "fifo";
    else if(S_ISLNK(buf.st_mode))
        ptr = "symbolic link";
    else if(S_ISSOCK(buf.st_mode))
        ptr = "socket";

    printf("%s\n",ptr);

    printf("UID:%d\nGID:%d\n",(unsigned int)buf.st_uid,(unsigned int)buf.st_gid);
    
    return 0;    
}

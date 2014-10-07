#include <stdio.h>

const int MAXLINE = 1024;

int main()
{
    char line[MAXLINE];
    FILE * fpin;

    if((fpin = popen("./10.13popen","r")) == NULL)
        fprintf(stderr,"popen error");
    for(;;)
    {
        fputs("prompt> ",stdout);
        fflush(stdout);
        if(fgets(line,MAXLINE,fpin) == NULL)
            break;
        if(fputs(line,stdout) == EOF)
            fprintf(stderr,"fputs error to pipe");
    }

    if(pclose(fpin) == -1)
        fprintf(stderr,"pclose error");
    putchar('\n');
    return 0;
}

#include <stdio.h>

int main()
{
    int c;

    while((c=getchar()) != EOF)
    {
        if(isupper(c))
            c = tolower(c);
        if(putchar(c) == EOF)
            fprintf(stderr,"output error");
        if(c == '\n')
            fflush(stdout);
    }
    return 0;
}

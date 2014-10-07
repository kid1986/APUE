#include "err_exit.h"


void err_exit(int err,char * errmsg)
{
    fprintf(stderr,"%s\n",errmsg);
    exit(err);
}

#include "minitalk.h"

int main(int argc,char **argv)
{
    kill(ft_atoi(argv[1]),SIGKILL);
}
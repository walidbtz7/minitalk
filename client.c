#include "minitalk.h"

int main(int argc,char **argv)
{
    int i;
    int j;
    int pid;

    pid = ft_atoi(argv[1]);
    i = 0;
    if(argc == 3)
        return (0);
    while (argv[2][i] != '\0')
    {
        j = 7;
        while (j >= 0)
        {
             if(argv[2][i] &  1 >> j)
                kill(pid,SIGUSR1);
             else
                kill(pid,SIGUSR2);
            j--;
        }
        i++;
    }
}

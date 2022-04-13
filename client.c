#include "minitalk.h"

int convert(int n)
{
    int b = 0;
    while(n >= 1)
    {
        b = (n % 2);
        ft_printf("%d",n % 2);
        n = n / 2;
    }
    return (b);
}
int main(int argc,char **argv)
{
    if(argc == 3)
        return (0);
    
    kill(ft_atoi(argv[1]),SIGUSR2);
}

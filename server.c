#include "minitalk.h"

int ft_pow(int pow)
{
    int i = 1;
    int n = 1;
    while (i <= pow)
    {
        n *= 2;
        i++;
    }
    return (n);
}

void sig_handler(int signum){
    static int i = 7;
    static int n = 0;

    if(signum == SIGUSR1)
        n += 1 * ft_pow(i);
    i--;
       
    if(i == -1)
    {
        i = 7;
        ft_printf("%c",n);
        n = 0;
    }
}

int main()
{
    ft_printf("%d\n",getpid());
    signal(SIGUSR2,sig_handler); 
    signal(SIGUSR1,sig_handler); 
    while (1)
        pause();
    return 0;
}

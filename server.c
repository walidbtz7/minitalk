#include "minitalk.h"

void sig_handler(int signum){
    if(signum == SIGUSR1)
        ft_printf("labas \n");
    else
        ft_printf("salam \n");
}
int main()
{
    ft_printf("%d\n",getpid());
    signal(SIGUSR2,sig_handler); // Register signal handler
    signal(SIGUSR1,sig_handler); // Register signal handler
    for(int i=1;;i++)
    {    //Infinite loop
        sleep(1);  // Delay for 1 second
    }
    return 0;
}
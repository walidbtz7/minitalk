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
void convert(char *str)
{
    int i;
    int n = 0;
    int x = 0;
    while(str[x] != '\0')
    {
        i = 7;
        while (i  >= 0)
        {
            n += (str[x]) * ft_pow(i); 
            ft_printf("%c\n",str[x]);
            i--;
            x++;
        }
    }
    ft_printf("%d",n);
}
void sig_handler(int signum){
    if(signum == SIGUSR1)
        ft_printf("labas \n");
    else
        ft_printf("salam \n");
}
// int main()
// {
//     ft_printf("%d\n",getpid());
//     signal(SIGUSR2,sig_handler); // Register signal handler
//     signal(SIGUSR1,sig_handler); //Register signal handler
//     for(int i=1;;i++)
//     {    //Infinite loop
//         sleep(1);  // Delay for 1 secondq
//     }
//     return 0;
//     ft_printf("%d",ft_pow());
// }
int main()
{
   convert("00001010");
}
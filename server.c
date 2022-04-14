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
    while (i >= 0)
    {
         if(signum == SIGUSR1)
            n += 1 * ft_pow(i);
        i--;
    }
    if(i == -1)
    {
        i = 7;
        n = 0;
    }
}
// void convert(char *str)
// {
//     int i;
//     int n = 0;
//     int x = 0;
//     while (str[x] != '\0')
//     {
//         i = 7;
//         n = 0;
//         while (i  >= 0)
//         {
//             if(str[x] == '1')
//                 n += 1 * ft_pow(i);
//             i--;
//             x++;
//         }
//         ft_printf("%c",n);
//     }
// }
int main()
{
    ft_printf("%d\n",getpid());
    signal(SIGUSR2,sig_handler); 
    signal(SIGUSR1,sig_handler); 
    while (1)
    {

    }
    return 0;
}

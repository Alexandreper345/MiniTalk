#include "minitalk.h"


void bitandbit(unsigned char octeto, int pid)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		ft_printf("%d", i);
		if ((octeto >> i) & 1)
			kill(pid,SIGUSR2);
		else
			kill(pid,SIGUSR1);
		i--;
		usleep(500);
	}
}

int	main(int argc, char **argv)
{
	bitandbit(42,atoi(argv[1]));
}

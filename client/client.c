#include "../minitalk.h"


void bitandbit(int pid, unsigned char octeto)
{
	int i;

	i = 7;
	while (i >= 0)
	{
		if ((octeto >> i) & 1)
			kill(pid,SIGUSR2);
		else
			kill(pid,SIGUSR1);
		i--;
		usleep(600);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
		{
			bitandbit(ft_atoi(argv[1]),argv[2][i]);
			i++;
		}
	}
}

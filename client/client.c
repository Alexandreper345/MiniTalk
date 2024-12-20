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
		usleep(200);
	}
}

void	send_msg(int id , char *mense)
{
	int	i;

	i = 0;

	while (mense[i])
	{
		bitandbit(id,mense[i]);
		i++;
	}
}

int	check_menseng(char *pid, char *msg)
{
	if (!msg)
		return(-1);
	while (*pid)
	{
		if (!ft_isdigit(*pid) || *pid < 0)
		{
			ft_printf("insira um pid valido\n");
			return (-1);
		}
		pid++;
	}
	return (0);

}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		if (check_menseng(argv[1], argv[2]) == -1)
			return (0);
		else
			send_msg(ft_atoi(argv[1]),argv[2]);
	}
	else
	{
		ft_printf("opa você esqueceu de insirir um pid :(\n");
		ft_printf("opa você esqueceu de insirir uma frase :(\n");
	}
}

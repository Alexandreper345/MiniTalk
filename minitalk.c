/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:18:13 by alda-sil          #+#    #+#             */
/*   Updated: 2024/12/17 18:21:15 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	signalhandler(int sig)
{
	static  int i;
	static  int c;
	
	if (!i)
		i = 0;
	if (!c)
		c = 0;

	if (sig == SIGUSR2)
	{
		c += (128 >> i);
	}

	i++;
	
	if (i == 8)
	{
		ft_printf("%c", c);
		c = 0;
		i = 0;
	}
}
int main(void)
{
	int pid;
	pid = getpid();
	ft_printf("%d\n",pid);
	signal(SIGUSR1, signalhandler);
	signal(SIGUSR2, signalhandler);
	if (pid == -1)
	{
		ft_printf("error\n");
		return (1);
	}
	while (1)
		pause();	
	return (0);
}

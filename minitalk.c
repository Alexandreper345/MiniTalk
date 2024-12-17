/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alda-sil <alda-sil@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 19:18:13 by alda-sil          #+#    #+#             */
/*   Updated: 2024/12/16 21:29:39 by alda-sil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"


void	signalhandler(int sig)
{
	ft_printf("RECEIVED SIGNAL %d\n",sig);
}
int main(int argc, char **argv)
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

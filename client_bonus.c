/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:13:14 by brolivei          #+#    #+#             */
/*   Updated: 2023/03/27 11:36:21 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_send_null(int pid, char c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if (c << i & 0b10000000)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(100);
	}
}

void	ft_sending_signals(int pid, char *str)
{
	int	i;
	int	j;
	int	c;

	i = 0;
	j = 0;
	while (str[j])
	{
		c = str[j];
		while (i < 8)
		{
			if (c << i & 0b10000000)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			i++;
			usleep(100);
		}
		i = 0;
		j++;
	}
	ft_send_null(pid, '\0');
}

void	ft_message_bonus(int sig)
{
	if (sig == SIGUSR1)
		ft_printf("Message received");
	exit(0);
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, &ft_message_bonus);
	if (argc != 3)
	{
		ft_printf("Invalid arguments");
		return (0);
	}
	else
		ft_sending_signals(ft_atoi(argv[1]), argv[2]);
	while (1)
		pause();
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 14:58:47 by brolivei          #+#    #+#             */
/*   Updated: 2023/03/27 12:02:58 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

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
		j++;
		i = 0;
	}
}

int	main(int argc, char **argv)
{	
	if (argc != 3)
	{
		ft_printf("Invalid arguments");
		return (0);
	}
	else
		ft_sending_signals(ft_atoi(argv[1]), argv[2]);
	return (0);
}

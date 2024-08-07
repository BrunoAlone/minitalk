/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 15:06:55 by brolivei          #+#    #+#             */
/*   Updated: 2023/03/27 12:09:54 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "minitalk.h"

void	ft_interpretation(int signal)
{
	static int	i;
	static int	c;

	if (signal == SIGUSR2)
		c = c << 1;
	else if (signal == SIGUSR1)
		c = (c << 1) | 0b00000001;
	i++;
	if (i == 8)
	{
		ft_printf("%c", c);
		i = 0;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("Process ID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR1, ft_interpretation);
		signal(SIGUSR2, ft_interpretation);
	}
	return (0);
}

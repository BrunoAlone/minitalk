/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printdec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:53:01 by brolivei          #+#    #+#             */
/*   Updated: 2023/01/10 16:40:30 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printdec(int n)
{
	static int	size;
	int			clone;

	size = 0;
	clone = n;
	if (n == -2147483648)
		return (write(1, "-2147483648", 11));
	else if (n == 0)
		return (write(1, "0", 1));
	else if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n > 0)
	{
		if (n > 9)
			ft_printdec(n / 10);
		size += write(1, &"0123456789"[n % 10], 1);
	}
	if (clone < 0)
		size += 1;
	return (size);
}

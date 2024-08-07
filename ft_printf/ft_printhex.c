/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:26:22 by brolivei          #+#    #+#             */
/*   Updated: 2023/01/10 16:51:13 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printhex(unsigned long int n, char x)
{
	static int	size;

	size = 0;
	if (n >= 16)
		ft_printhex((n / 16), x);
	if (x == 'x')
		size += write(1, &"0123456789abcdef"[n % 16], 1);
	if (x == 'X')
		size += write(1, &"0123456789ABCDEF"[n % 16], 1);
	return (size);
}

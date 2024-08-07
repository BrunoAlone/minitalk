/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:46:58 by brolivei          #+#    #+#             */
/*   Updated: 2023/01/10 16:46:27 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printptr(unsigned long long ptr)
{
	int	size;

	size = 0;
	if (ptr == 0)
		return (write(1, "(nil)", 5));
	else
	{
		size += write(1, "0x", 2);
		size += ft_printhex(ptr, 'x');
	}
	return (size);
}

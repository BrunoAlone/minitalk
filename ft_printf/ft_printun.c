/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printun.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 16:22:07 by brolivei          #+#    #+#             */
/*   Updated: 2023/01/10 16:51:52 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printun(unsigned int n)
{
	static int	size;

	size = 0;
	if (n == 0)
		return (write(1, "0", 1));
	else
	{
		if (n > 9)
			ft_printun(n / 10);
		size += write(1, &"0123456789"[n % 10], 1);
	}
	return (size);
}

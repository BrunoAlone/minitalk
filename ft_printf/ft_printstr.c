/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 14:39:57 by brolivei          #+#    #+#             */
/*   Updated: 2023/01/10 16:44:09 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printstr(char *s)
{
	int	size;

	size = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[size])
		size += write(1, &s[size], 1);
	return (size);
}

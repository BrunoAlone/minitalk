/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:57:23 by brolivei          #+#    #+#             */
/*   Updated: 2023/01/10 16:47:10 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_treatment(char c, va_list ptr)
{
	int	size;

	size = 0;
	if (c == 'c')
		size += ft_printchar(va_arg(ptr, int));
	else if (c == 's')
		size += ft_printstr(va_arg(ptr, char *));
	else if (c == 'p')
		size += ft_printptr(va_arg(ptr, unsigned long long));
	else if (c == 'd' || c == 'i')
		size += ft_printdec(va_arg(ptr, int));
	else if (c == 'u')
		size += ft_printun(va_arg(ptr, unsigned long));
	else if (c == 'x' || c == 'X')
		size += ft_printhex(va_arg(ptr, unsigned int), c);
	else if (c == '%')
		size += write(1, "%", 1);
	return (size);
}

int	ft_check(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
		|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int	ft_printf(const char *s, ...)
{
	va_list	ptr;
	int		size;
	int		i;

	size = 0;
	i = 0;
	if (!s)
		return (-1);
	va_start(ptr, s);
	while (s[i])
	{
		if (s[i] != '%')
			size += write(1, &s[i], 1);
		else if (s[i] == '%' && !ft_check(s[i + 1]))
			size += write(1, &s[i], 1);
		else if (s[i] == '%' && ft_check(s[i + 1]))
		{
			i++;
			size += ft_treatment(s[i], ptr);
		}
		i++;
	}
	va_end(ptr);
	return (size);
}

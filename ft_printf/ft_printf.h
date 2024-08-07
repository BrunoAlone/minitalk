/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brolivei <brolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 13:57:29 by brolivei          #+#    #+#             */
/*   Updated: 2023/01/10 16:52:23 by brolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <limits.h>

int	ft_printf(const char *s, ...);
int	ft_printchar(int c);
int	ft_printstr(char *s);
int	ft_printptr(unsigned long long ptr);
int	ft_printdec(int n);
int	ft_printun(unsigned int n);
int	ft_printhex(unsigned long int n, char x);

#endif

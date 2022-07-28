/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jechekao <jechekao@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/13 14:07:20 by jechekao          #+#    #+#             */
/*   Updated: 2022/02/13 14:07:38 by jechekao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

/*1 = str, 2 = char*/
int	ft_putstr(char *s, char c, int i);
int	ft_putnum(long ln);
int	ft_printhex(unsigned long long ln, char conver);
int	is_percent(va_list args, const char *conver);
int	ft_printf(const char *str, ...);
#endif
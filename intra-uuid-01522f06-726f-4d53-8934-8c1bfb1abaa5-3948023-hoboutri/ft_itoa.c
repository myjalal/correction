/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:55:03 by mac               #+#    #+#             */
/*   Updated: 2022/01/13 12:45:51 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <string.h>

int	len(int nb)
{
	int	len;

	len = 0;
	if (nb < 0)
		len++;
	while (nb / 10)
	{
		nb = nb / 10;
		len++;
	}
	return (len + 1);
}

void	ntoa(int n, char *s, int size)
{
	char	c;

	if (n < 0)
	{
		size--;
		*s++ = '-';
	}
	while (size >= 0)
	{
		c = n % 10;
		if (c < 0)
			c = c * -1;
		s[size--] = c + 48;
		n = n / 10;
	}
}

char	*ft_itoa(int n)
{
	int		size;
	char	*s;

	size = len(n);
	s = malloc(size + 1);
	if (s == NULL)
		return (NULL);
	s[size--] = 0;
	ntoa(n, s, size);
	return (s);
}

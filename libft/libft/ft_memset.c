/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 13:50:02 by hoboutri          #+#    #+#             */
/*   Updated: 2022/01/13 13:07:42 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

void	*ft_memset(void *src, int dest, size_t n)
{
	char	*str;

	str = src;
	while (n > 0)
	{
		*str++ = (unsigned char)dest;
		n--;
	}
	return (src);
}

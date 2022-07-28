/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/02 12:06:25 by hoboutri          #+#    #+#             */
/*   Updated: 2022/01/13 13:22:34 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	srclen;
	size_t	destlen;
	size_t	index;

	index = 0;
	srclen = ft_strlen(src);
	destlen = ft_strlen(dest);
	if (destlen > size)
		destlen = size;
	if (size == destlen)
		return (size + srclen);
	while (src[index] && (index + destlen) < (size - 1))
	{
		dest[index + destlen] = src[index];
		index++;
	}
	dest[index + destlen] = '\0';
	if (size > destlen)
		return (destlen + srclen);
	return (size + srclen);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 14:00:47 by hoboutri          #+#    #+#             */
/*   Updated: 2022/01/12 17:37:57 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)

{
	size_t	len;

	len = ft_strlen(str);
	if (c == '\0')
		return ((char *)str + len);
	while (len--)
	{
		if (str[len] == (char)c)
			return ((char *)str + len);
	}
	return (NULL);
}

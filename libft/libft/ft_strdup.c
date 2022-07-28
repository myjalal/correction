/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 14:00:10 by hoboutri          #+#    #+#             */
/*   Updated: 2022/01/12 17:11:12 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)

{
	size_t	size;
	char	*dup;

	size = ft_strlen(s) + 1;
	dup = ft_calloc(size, sizeof(char));
	if (!dup)
		return (NULL);
	ft_memcpy(dup, s, size * sizeof(char));
	return (dup);
}

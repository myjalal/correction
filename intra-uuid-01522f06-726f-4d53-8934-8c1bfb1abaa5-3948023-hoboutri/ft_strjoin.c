/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mac <mac@student.42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:54:43 by hoboutri          #+#    #+#             */
/*   Updated: 2022/01/13 12:45:46 by mac              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size1;
	size_t	size2;
	char	*str;

	size1 = ft_strlen(s1);
	size2 = ft_strlen(s2);
	str = malloc(sizeof(char) * (size1 + size2 + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, size1 + size2 + 1);
	ft_strlcpy(str + size1, s2, size2 + 1);
	return (str);
}

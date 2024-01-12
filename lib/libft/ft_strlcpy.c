/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluiz-de <lluiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:24:52 by lluiz-de          #+#    #+#             */
/*   Updated: 2024/01/05 17:54:27 by lluiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	int	i;

	if (!size)
		return (ft_strlen(src));
	i = -1;
	while (*(src + ++i) && --size)
	{
		*(dst + i) = *(src + i);
	}
	*(dst + i) = '\0';
	return (ft_strlen(src));
}

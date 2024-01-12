/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lluiz-de <lluiz-de@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 20:34:21 by lluiz-de          #+#    #+#             */
/*   Updated: 2024/01/05 18:09:10 by lluiz-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *s)
{
	if (errno)
		perror("Error");
	else
		ft_putendl_fd(s, STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/27 21:22:38 by mdiouf            #+#    #+#             */
/*   Updated: 2013/12/01 20:54:04 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*pts1;
	size_t	i;

	i = 0;
	pts1 = malloc(size);
	if (pts1 == NULL)
	{
		return (NULL);
	}
	else
	{
		while (i < size)
		{
			pts1[i] = 0;
			i++;
		}
		return ((void*)pts1);
	}
}

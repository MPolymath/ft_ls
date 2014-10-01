/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 19:37:48 by mdiouf            #+#    #+#             */
/*   Updated: 2013/12/01 18:22:21 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;
	char	*cpyb;

	cpyb = (char*)b;
	i = 0;
	while (i < len)
	{
		cpyb[i] = c;
		i++;
	}
	b = (void*)cpyb;
	return (b);
}

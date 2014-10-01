/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/24 20:39:42 by mdiouf            #+#    #+#             */
/*   Updated: 2013/12/01 18:05:15 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*cpyb;

	cpyb = (char*)s;
	i = 0;
	while (i < n)
	{
		cpyb[i] = 0;
		i++;
	}
	s = (void*)cpyb;
	return (s);
}
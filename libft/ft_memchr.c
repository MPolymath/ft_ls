/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 16:48:42 by mdiouf            #+#    #+#             */
/*   Updated: 2013/12/01 18:17:43 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void		*ptc;
	const char	*string;
	size_t		i;

	string = (const char*)s;
	i = 0;
	while (string[i] != '\0' && i < n)
	{
		if (string[i] == c)
		{
			ptc = (void*)&string[i];
			return (ptc);
		}
		i++;
	}
	return (NULL);
}

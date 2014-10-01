/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:15:39 by mdiouf            #+#    #+#             */
/*   Updated: 2013/12/01 18:39:24 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	if (*s2 == '\0')
	{
		return ((char*)s1);
	}
	while (s1[i] != '\0')
	{
		if (ft_comparestrings(s1, s2, i) == 1)
		{
			return ((char*)&s1[i]);
		}
		if (ft_comparestrings(s1, s2, i) == 0)
		{
			i++;
		}
	}
	return (NULL);
}

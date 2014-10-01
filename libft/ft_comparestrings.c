/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_comparestrings.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/22 19:56:56 by mdiouf            #+#    #+#             */
/*   Updated: 2013/12/01 18:05:43 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_comparestrings(const char *s1, const char *s2, int i)
{
	int	j;

	j = 0;
	while (s2[j] != '\0')
	{
		if (s1[i] == s2[j])
		{
			i++;
			j++;
		}
		else
		{
			return (0);
		}
	}
	return (1);
}

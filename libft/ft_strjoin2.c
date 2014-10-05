/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twallart <twallart@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/11/26 11:18:04 by twallart          #+#    #+#             */
/*   Updated: 2014/10/05 21:09:34 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char **s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*s3;

	i = 0;
	j = 0;
	if ((*s1 == NULL) || (s2 == NULL))
		return (NULL);
	s3 = (char *) malloc(sizeof(s3) * (ft_strlen(*s1) + ft_strlen(s2)));
	while (s1[0][i] != '\0')
	{
		s3[i] = s1[0][i];
		i++;
	}
	while (s2[j] != '\0')
	{
		s3[i] = s2[j];
		i++;
		j++;
	}
	s3[i] = '\0';
	free(*s1);
	return (s3);
}

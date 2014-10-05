/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 22:59:12 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/05 22:56:06 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			odr_prnt_r1(t_dir **vars, int **argc)
{
	while ((*vars)->files[(*vars)->i].nme != '\0')
		((*vars)->i)++;
	((*vars)->i)--;
	while (((*vars)->i) != -1)
	{
		ft_putstr((*vars)->files[(*vars)->i].nme);
		ft_putstr("\n");
		free((*vars)->files[(*vars)->i].path);
		((*vars)->i)--;
		((*vars)->j)++;
	}
	(**argc)--;
}

void			odr_prnt_r0(t_dir **vars)
{
	if ((*vars)->l == 1)
	{
		while ((*vars)->nbr_files != 0)
		{
			if ((*vars)->files[(*vars)->i].nme[0] != '.')
			{
				ft_print_rights(vars, (*vars)->i);
				ft_putstr((*vars)->files[(*vars)->i].nme);
				ft_putstr("\n");
			}
			free((*vars)->files[(*vars)->i].path);
			((*vars)->nbr_files)--;
			((*vars)->i)++;
			((*vars)->j)++;
		}
	}
	while ((*vars)->files[(*vars)->i].nme != '\0' && ((*vars)->nbr_files != 0))
	{
		ft_putstr((*vars)->files[(*vars)->i].nme);
		ft_putstr("\n");
		free((*vars)->files[(*vars)->i].path);
		((*vars)->i)++;
		((*vars)->j)++;
	}
	((*vars)->k)++;
}

void			order_print_files(t_dir *vars, int *argc, int r)
{
	if (vars->dir == NULL)
	{
		(vars->k)++;
		return ;
	}
	order_files(&(vars->files));
	(vars->i) = 0;
	if (r == 1)
		odr_prnt_r1(&vars, &argc);
	else if (r == 0)
		odr_prnt_r0(&vars);
	if ((vars->j) == 3)
	{
		ft_putstr("\n");
		(vars->j) = 0;
	}
	(vars->i) = 0;
	if (vars->dir != NULL)
		closedir(vars->dir);
}

void			ls_init(t_dir *vars)
{
	vars->i = 0;
	vars->j = 0;
	vars->k = 0;
}

void			ft_ls_chck_lst(t_dir *vars)
{
	while ((vars->files)[vars->i].nme != '\0')
		(vars->i)++;
}

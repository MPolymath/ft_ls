/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 22:59:12 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/02 05:11:30 by mdiouf           ###   ########.fr       */
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
		((*vars)->i)--;
		((*vars)->j)++;
	}
	(**argc)--;
}


void			ft_fix_time_str(char **time)
{
	int			i;
	int			j;
	i = 0;
	j = 0;
	while ((*time)[i] != ' ')
	{
		while ((*time)[j + 1] != '\0')
		{
			(*time)[j] = (*time)[j + 1];
			j++;
		}
		(*time)[j] = (*time)[j + 1];
		j = 0;
		i++;
	}
	i = 0;
	while ((*time)[i] != ':')
		i++;
	i = i + 3;
	while ((*time)[i] != '\0')
	{
		((*time)[i] = '\0');
		i++;
	}
}

void			ft_print_rights(t_dir **vars, int i)
{
	struct passwd	*pass;
	struct group	*grp;
	char			*time;

	time = ctime(&((*vars)->files[i].stats.st_mtime));
	ft_fix_time_str(&time);
	ft_putstr( (S_ISDIR((*vars)->files[i].stats.st_mode)) ? "d" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr( ((*vars)->files[i].stats.st_mode & S_IXOTH) ? "x" : "-");
	ft_putstr("  ");
	ft_putnbr((*vars)->files[i].stats.st_nlink);
	ft_putstr("  ");
	pass = getpwuid((*vars)->files[i].stats.st_uid);
	grp = getgrgid((*vars)->files[i].stats.st_gid);
	ft_putstr(pass->pw_name);
	ft_putstr("  ");
	ft_putstr(grp->gr_name);
	ft_putstr("  ");
	ft_putnbr((*vars)->files[i].stats.st_size);
	ft_putstr("  ");
	ft_putstr(time);
	ft_putstr("  ");
}

void			odr_prnt_r0(t_dir **vars)
{
	if ((*vars)->l == 1)
	{
		while ((*vars)->files[(*vars)->i].nme != '\0')
		{
			if ((*vars)->files[(*vars)->i].nme[0] != '.')
			{
				ft_print_rights(vars, (*vars)->i);
				ft_putstr((*vars)->files[(*vars)->i].nme);
				ft_putstr("\n");
			}
			((*vars)->i)++;
			((*vars)->j)++;
		}
	}
	while ((*vars)->files[(*vars)->i].nme != '\0')
	{
		ft_putstr((*vars)->files[(*vars)->i].nme);
		ft_putstr("\n");
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
//	if (vars->files[0].nme != '\0')
//		ft_putstr("\n");
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

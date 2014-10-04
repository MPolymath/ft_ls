/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/10/04 00:47:10 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/04 05:11:54 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			ft_fix_time_str2(char **time)
{
	int			i;

	i = 0;
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
	ft_fix_time_str2(time);
}

void			ft_print_rights2(t_dir **vars, int i, t_id *id_vars)
{
	ft_putstr("  ");
	ft_putnbr((*vars)->files[i].stats.st_nlink);
	ft_putstr("  ");
	id_vars->pass = getpwuid((*vars)->files[i].stats.st_uid);
	id_vars->grp = getgrgid((*vars)->files[i].stats.st_gid);
	ft_putstr(id_vars->pass->pw_name);
	ft_putstr("  ");
	ft_putstr(id_vars->grp->gr_name);
	ft_putstr("  ");
	ft_putnbr((*vars)->files[i].stats.st_size);
	ft_putstr("  ");
	ft_putstr(id_vars->time);
	ft_putstr("  ");
}

void			ft_print_rights(t_dir **vars, int i)
{
	t_id			id_vars;

	id_vars.time = ctime(&((*vars)->files[i].stats.st_mtime));
	ft_fix_time_str(&(id_vars.time));
	ft_putstr((S_ISDIR((*vars)->files[i].stats.st_mode)) ? "d" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IRUSR) ? "r" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IWUSR) ? "w" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IXUSR) ? "x" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IRGRP) ? "r" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IWGRP) ? "w" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IXGRP) ? "x" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IROTH) ? "r" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IWOTH) ? "w" : "-");
	ft_putstr(((*vars)->files[i].stats.st_mode & S_IXOTH) ? "x" : "-");
	ft_print_rights2(vars, i, &id_vars);
}

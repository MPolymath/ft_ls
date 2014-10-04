/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/20 22:58:05 by mdiouf            #+#    #+#             */
/*   Updated: 2014/10/04 04:48:46 by mdiouf           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	cpy_hash(t_hash *hash1, t_hash *hash2)
{
	hash1->i = hash2->i;
	hash1->argv = hash2->argv;
}

void	cr_tb_hash_init(t_main *vars, int argc, t_hash *tb_hash, char **argv)
{
	vars->i = 1;
	vars->j = 0;
	vars->good = 1;
	vars->argv_i = (int*)malloc(sizeof(int) * (argc - 1));
	while (vars->i != argc || argc == 1)
	{
		tb_hash[vars->i].i = vars->i;
		tb_hash[vars->i].argv = argv[vars->i];
		(vars->i)++;
		if (argc == 1)
			break;
	}
}

void	cr_tb_hash_main(t_main *vars, int argc, t_hash *tb_hash)
{
	(vars->i) = 1;
	while ((vars->i) != argc - 1 && argc != 1)
	{
		if (ft_strcmp(tb_hash[vars->i].argv, tb_hash[(vars->i)
			+ 1].argv) > 0)
		{
			vars->good = 0;
			cpy_hash(&vars->temp, &tb_hash[vars->i]);
			cpy_hash(&tb_hash[vars->i], &tb_hash[vars->i + 1]);
			cpy_hash(&tb_hash[vars->i + 1], &vars->temp);
		}
		(vars->i)++;
		if (vars->good == 0 && vars->i == (argc - 1))
		{
			vars->i = 1;
			vars->good = 1;
		}
	}
}

int		*cr_tb_hash(int argc, char **argv)
{
	t_hash	*tb_hash;
	t_main	vars;

	tb_hash = (t_hash*)malloc(sizeof(t_hash) * (argc));
	cr_tb_hash_init(&vars, argc, tb_hash, argv);
	cr_tb_hash_main(&vars, argc, tb_hash);
	vars.i = 1;
	while (vars.i != argc || argc == 1)
	{
		vars.argv_i[vars.j] = tb_hash[vars.i].i;
		(vars.j)++;
		(vars.i)++;
		if (argc == 1)
			break;
	}
	return (vars.argv_i);
}

void	order_files(t_files **files)
{
	int			good;
	int			i;
	t_files		temp;

	i = 0;
	good = 0;
	while (good == 0)
	{
		good = 1;
		while (files[0][i + 1].nme != '\0')
		{
			if (ft_strcmp(files[0][i].nme, files[0][i + 1].nme) > 0)
			{
				temp = files[0][i + 1];
				files[0][i + 1] = files[0][i];
				files[0][i] = temp;
				good = 0;
			}
			i++;
		}
		i = 0;
	}
}

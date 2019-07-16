/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:13:31 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/29 16:58:21 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int				main(int argc, char *argv[])
{
	if (argc < 2)
	{
		ft_putstr("Usage: file1 [file2...]\n");
		return (1);
	}
	if (set_terminal() < 0)
		return (1);
	g_term.argc = (argc - 1);
	g_term.argv = (argv + 1);
	display_files();
	listen_signals();
	ft_select();
	return (0);
}

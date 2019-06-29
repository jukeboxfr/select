/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:18:20 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/29 14:20:17 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static int		check_grid(int width)
{
	int	i;
	int	j;

	j = 0;
	g_term.grid.cols = 0;
	while (j < g_term.argc)
	{
		if ((width = width - g_term.grid.padding) < 0)
			return (0);
		g_term.grid.cols++;
		i = 0;
		while (j < g_term.argc && i++ < g_term.grid.rows)
			j++;
	}
	return (width >= 0);
}

static int		get_column_width(void)
{
	int		width;
	int		column_width;
	int		i;

	column_width = 1;
	i = 0;
	while (i < g_term.argc)
	{
		width = ft_strlen(g_term.argv[i]);
		if (width > column_width)
			column_width = width;
		i++;
	}
	return (column_width + 1);
}

static void		update_grid(void)
{
	struct winsize		w;

	ft_memset(&g_term.grid, '\0', sizeof(g_term.grid));
	ioctl(0, TIOCGWINSZ, &w);
	g_term.grid.padding = get_column_width();
	g_term.grid.rows = 1;
	while (g_term.grid.rows <= g_term.argc)
	{
		if (check_grid(w.ws_col))
			break ;
		g_term.grid.rows++;
	}
}

void			display_files(void)
{
	int		index;
	int		colors;
	int		padding;

	update_grid();
	index = 0;
	while (index < g_term.argc)
	{
		colors = get_colors(g_term.argv[index], index);
		display_color(colors);
		ft_putstr(g_term.argv[index]);
		if (colors)
			ft_putstr("\033[0m");
		padding = g_term.grid.padding - ft_strlen(g_term.argv[index]);
		index++;
		if (index == g_term.argc
			|| !(index % g_term.grid.cols))
		{
			ft_putchar('\n');
			continue ;
		}
		while (padding-- > 0)
			ft_putchar(' ');
	}
}

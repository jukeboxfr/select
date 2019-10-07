/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:18:20 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/29 16:59:07 by kesaint-         ###   ########.fr       */
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
	int		cols;
	int		i;

	cols = 0;
	column_width = 1;
	i = 0;
	while (i < g_term.argc)
	{
		width = ft_strlen(g_term.argv[i]);
		if (width > column_width)
			column_width = width;
		cols++;
		i++;
	}
	g_term.grid.cols = cols;
	return (column_width + 1);
}

static void		update_grid(void)
{
	struct winsize		w;

	ft_memset(&g_term.grid, '\0', sizeof(g_term.grid));
	ioctl(STDERR_FILENO, TIOCGWINSZ, &w);
	g_term.grid.padding = get_column_width();
	g_term.grid.rows = 1;
	while (g_term.grid.rows <= g_term.argc)
	{
		if (check_grid(w.ws_col))
			break ;
		g_term.grid.rows++;
	}
}

void
debugger(void) {
	fprintf(stderr, "[+] Cursor: %i\n", g_term.cursor);
	fprintf(stderr, "[+] Selected (%i): ", g_term.count);

	int	i = 0;
	while (i < g_term.count) {
		fprintf(stderr, "%i ", g_term.selected[i]);
		i++;
	}
	fprintf(stderr, "\n");
	fflush(stderr);
}

static void		set_conf(int *max_row, int *start_index)
{
	struct winsize	w;
	int				row;
	int				row_dsp;
	int				win_rows;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &w);
	win_rows = w.ws_row - 1;
	row = (g_term.cursor / g_term.grid.cols);
	if (g_term.grid.rows <= w.ws_row)
	{
		*start_index = 0;
		*max_row = g_term.grid.rows;
		return ;
	}
	row_dsp = (g_term.grid.rows - row);
	if (row_dsp < w.ws_row)
	{
		row = (g_term.grid.rows - win_rows);
		*max_row = (g_term.grid.rows - row);
	}
	else
		*max_row = win_rows;
	*start_index = (row * g_term.grid.cols);
}


void			display_files(void)
{
	int		index;
	int		colors;
	int		padding;
	struct  winsize	w;
	int		row;

	update_grid();
	if (!g_term.grid.cols)
		return (display_err_small());
	set_conf(&row, &index);
	while (index < g_term.argc && row)
	{
		colors = get_colors(g_term.argv[index], index);
		display_color(colors);
		ft_putstr_fd(g_term.argv[index], STDERR_FILENO);
		if (colors)
			ft_putstr_fd("\033[0m", STDERR_FILENO);
		padding = g_term.grid.padding - ft_strlen(g_term.argv[index]);
		index++;
		if (index == g_term.argc
			|| !(!g_term.grid.cols || (index % g_term.grid.cols)))
		{
			ft_putchar_fd('\n', STDERR_FILENO);
			row--;
			continue ;
		}
		while (padding-- > 0)
			ft_putchar_fd(' ', STDERR_FILENO);
	}
	//debugger();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:20:54 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/22 16:24:26 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void			stop(int sig)
{
	if (g_term.selected)
		free(g_term.selected);
	reset_terminal();
	exit(EXIT_SUCCESS);
}

void			move_cursor(long key)
{
	int		items;

	items = g_term.grid.cols * g_term.grid.rows;
	if (key == RIGHT_KEY)
		g_term.cursor = g_term.cursor + 1 < g_term.argc
			? (g_term.cursor + 1) : 0;
	if (key == LEFT_KEY)
		g_term.cursor = g_term.cursor - 1 > -1
			? (g_term.cursor - 1) : g_term.argc - 1;
	if (key == TOP_KEY)
		g_term.cursor -= g_term.cursor - g_term.grid.cols > -1
			? g_term.grid.cols : 0;
	if (key == DOWN_KEY)
		g_term.cursor = g_term.cursor + g_term.grid.cols < g_term.argc
			? (g_term.cursor + g_term.grid.cols)
			: (g_term.argc - g_term.cursor);
	clear_terminal();
	display_files();
}

static void		print_selected(void)
{
	int	i;

	i = 0;
	while (i < g_term.argc)
	{
		if (is_selected(i))
		{
			ft_putstr(g_term.argv[i]);
			if ((i + 1) < g_term.argc)
				ft_putchar(' ');
		}
		i++;
	}
	stop(0);
}

void			ft_select(void)
{
	long	key;

	while (42)
	{
		key = 0;
		read(STDIN_FILENO, &key, 8);
		if (!g_term.argc || key == ESCAPE_KEY)
			stop(0);
		if (key == DELETE_KEY || key == BACKSPACE_KEY)
			remove_args();
		if (key == LEFT_KEY || key == RIGHT_KEY
			|| key == TOP_KEY || key == DOWN_KEY)
			move_cursor(key);
		if (key == SPACE_KEY)
			on_select();
		if (key == ENTER_KEY)
			print_selected();
	}
}

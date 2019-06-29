/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 16:57:15 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/29 16:58:48 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

int			is_selected(int index)
{
	int		i;

	i = 0;
	while (i < g_term.count && g_term.selected[i] != index)
		i++;
	return (i < g_term.count);
}

static void			select_file(void)
{
	int		*list;
	int		*tab;
	int		i;

	list = g_term.selected;
	g_term.count++;
	if (!(tab = (int*)ft_memalloc(sizeof(int) * g_term.count)))
		return ;
	if (!list)
	{
		*tab = g_term.cursor;
		g_term.selected = tab;
		return ;
	}
	i = -1;
	while (++i < g_term.count - 1)
		tab[i] = g_term.selected[i];
	free(list);
	tab[g_term.count - 1] = g_term.cursor;
	g_term.selected = tab;
}

static void			deselect_file(int index)
{
	int	*tab;
	int	*ptr;
	int	i;

	if (g_term.count < 2)
	{
		free(g_term.selected);
		g_term.count = 0;
		g_term.selected = NULL;
		return ;
	}
	if (!(tab = (int*)ft_memalloc(sizeof(int) * (g_term.count - 1))))
		return ;
	i = -1;
	ptr = tab;
	while (++i < g_term.count)
	{
		if (g_term.selected[i] == index)
			continue ;
		*ptr = g_term.selected[i];
		ptr++;
	}
	free(g_term.selected);
	g_term.selected = tab;
	g_term.count--;
}

void				remove_args(void)
{
	int	i;

	if (is_selected(g_term.cursor))
		deselect_file(g_term.cursor);
	i = g_term.cursor;
	while (i < g_term.argc)
	{
		g_term.argv[i] = g_term.argv[i + 1];
		i++;
	}
	clear();
	g_term.argc--;
	display_files();
}

void				on_select(void)
{
	is_selected(g_term.cursor) ? deselect_file(g_term.cursor) : select_file();
	clear();
	display_files();
}

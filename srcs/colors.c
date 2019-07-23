/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:22:13 by kesaint-          #+#    #+#             */
/*   Updated: 2019/06/29 14:24:22 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void		print_color(int options)
{
	int		selected;

	selected = (options & OPT_RE_SCREEN) == OPT_RE_SCREEN;
	if ((options & OPT_RED) == OPT_RED)
		return (ft_putstr(selected ? "30;41m" : "31m"));
	if ((options & OPT_GREEN) == OPT_GREEN)	
		return (ft_putstr(selected ? "30;42m" : "32m"));
	if ((options & OPT_YELLOW) == OPT_YELLOW)
		return (ft_putstr(selected ? "30;43m" : "33m"));
	if ((options & OPT_BLUE) == OPT_BLUE)
		return (ft_putstr(selected ? "30;44m" : "34m"));
	if ((options & OPT_MAGENTA) == OPT_MAGENTA)
		return (ft_putstr(selected ? "30;45m" : "35m"));
	if ((options & OPT_CYAN) == OPT_CYAN)
		return (ft_putstr(selected ? "30;46m" : "36m"));
	ft_putstr("1m");
}

static void		print_weight(int options)
{
	if ((options & OPT_BOLD) == OPT_BOLD)
		return (ft_putstr("[1;"));
	if ((options & OPT_ITALIC) == OPT_ITALIC)
		return (ft_putstr("[3;"));
	if ((options & OPT_UNDERLINE) == OPT_UNDERLINE)
		return (ft_putstr("[4;"));
	ft_putstr("[0;");
}

int				get_colors(char *filename, int index)
{
	char	*extension;
	int		flags;

	flags = 0;;
	if (g_term.cursor == index)
		flags |= OPT_UNDERLINE;
	if (is_selected(index))
		flags |= OPT_RE_SCREEN;
	extension = NULL;
	while ((filename = ft_strchr(filename,'.')))
		extension = ++filename;
	if (!extension)
		return (flags | OPT_YELLOW);
	if (*extension == 'c' && !*(extension + 1))
		flags |= OPT_RED;
	else if (*extension == 'o' && !*(extension + 1))
		flags |= OPT_MAGENTA;
	else if (*extension == 'h' && !*(extension + 1))
		flags |= OPT_CYAN;
	else
		flags |= OPT_GREEN;
	return (flags);
}

void			display_color(int flags)
{
	if (!flags)
		return ;
	ft_putchar('\e');
	print_weight(flags);
	print_color(flags);
}
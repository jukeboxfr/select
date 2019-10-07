/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:23:30 by kesaint-          #+#    #+#             */
/*   Updated: 2019/10/07 15:23:39 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		display_err_small(void)
{
	struct winsize	w;

	ioctl(STDERR_FILENO, TIOCGWINSZ, &w);
	if (w.ws_col > 7 && w.ws_row > 5)
	{
		ft_putstr_fd("\n ____ \n||+ ||\n||__||\n|/__\\|\n", STDERR_FILENO);
		if (w.ws_row >= 7 && w.ws_col >= 21)
			ft_putstr_fd("Enlarge the window!\n", STDERR_FILENO);
		return ;
	}
	return (ft_putstr_fd("+.", STDERR_FILENO));
}

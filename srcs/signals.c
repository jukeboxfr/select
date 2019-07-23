/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:21:59 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/23 15:15:46 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	resize_handler(int sig)
{
	clear_terminal();
	display_files();
}

void		listen_signals(void)
{
	signal(SIGINT, stop);
	signal(SIGABRT, stop);
	signal(SIGSTOP, stop);
	signal(SIGKILL, stop);
	signal(SIGQUIT, stop);
	signal(SIGWINCH, resize_handler);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:21:59 by kesaint-          #+#    #+#             */
/*   Updated: 2019/10/08 12:14:04 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

static void	update_handler(int sig)
{
	clear_terminal();
	display_files();
}

static void	recover_handler(int sig)
{
	if (set_terminal() < 0)
		stop(0);
	update_handler(0);
	listen_signals();
}

static void	suspend_handler(int sig)
{
	reset_terminal();
	signal(SIGSTOP, SIG_DFL);
}

void		listen_signals(void)
{
	signal(SIGINT, stop);
	signal(SIGABRT, stop);
	signal(SIGSTOP, stop);
	signal(SIGKILL, stop);
	signal(SIGQUIT, stop);
	signal(SIGWINCH, update_handler);
	signal(SIGSTOP, suspend_handler);
	signal(SIGCONT, recover_handler);
}

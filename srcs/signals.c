/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 16:21:59 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/22 16:22:02 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void		listen_signals(void)
{
	signal(SIGINT, stop);
	signal(SIGABRT, stop);
	signal(SIGSTOP, stop);
	signal(SIGKILL, stop);
	signal(SIGQUIT, stop);
}

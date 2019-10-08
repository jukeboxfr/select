/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   terminal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:14:21 by kesaint-          #+#    #+#             */
/*   Updated: 2019/10/08 12:14:22 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_select.h"

void	clear_terminal(void)
{
	char	*str;

	str = tgetstr("cl", NULL);
	tputs(str, 1, ft_putc);
}

void	reset_terminal(void)
{
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	g_term.term.c_lflag |= (ICANON | ECHO);
	tcsetattr(STDIN_FILENO, TCSANOW, &g_term.term);
	ft_putstr_fd("\033[?1049l", STDERR_FILENO);
}

int		set_terminal(void)
{
	struct termios	term;
	char			*var;

	if (!(var = getenv("TERM")))
	{
		ft_putstr_fd("La variable d'environnement TERM est manquante\n", 2);
		return (ERROR);
	}
	if (tgetent(NULL, var) < 1)
	{
		ft_putstr_fd("The specified terminal type was not found\n", 2);
		return (ERROR);
	}
	ft_putstr_fd("\033[?1049h\033[H", STDERR_FILENO);
	tcgetattr(STDIN_FILENO, &g_term.term);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	return (SUCCESS);
}

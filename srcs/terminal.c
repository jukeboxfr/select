#include "ft_select.h"

void	clear_terminal(void)
{
	char *str;

	str = tgetstr("cl", NULL);
	tputs(str, 1, ft_putc);
}
void	reset_terminal(void)
{
	tcsetattr(STDIN_FILENO, TCSANOW, &g_term.term);
	tputs(tgetstr("ve", NULL), 1, ft_putc);
	tputs(tgetstr("te", NULL), 1, ft_putc);
}

int		set_terminal(void)
{
	struct termios	term;
	char			*var;

	if (!(var = getenv("TERM")))
	{
		ft_putstr("La variable d'environnement TERM est manquante\n");
		return (ERROR);
	}
	if (tgetent(NULL, var) < 1)
	{
		ft_putstr("The specified terminal type was not found\n");
		return (ERROR);
	}
	tcgetattr(STDIN_FILENO, &g_term.term);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
	tputs(tgetstr("ti", NULL), 1, ft_putc);
	tputs(tgetstr("vi", NULL), 1, ft_putc);
	return (SUCCESS);
}

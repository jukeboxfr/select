#include "ft_select.h"

void
clear(void)
{
	char *cl_cap;

	cl_cap = tgetstr("cl", NULL);
	tputs(cl_cap, 1, ft_putchar);
}

void
remove_args(void)
{
	int	i;

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

void			ft_select(void)
{
	long key;

	while (42)
	{
		key = 0;
		read(STDIN_FILENO, &key, 8);
		if (key == DELETE_KEY || key == BACKSPACE_KEY)
			remove_args();
		if (key == ESCAPE_KEY)
			stop(0);
	}
}

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

void			move_cursor(long key)
{
	if (key == RIGHT_KEY
		&& g_term.cursor + 1 < g_term.argc)
		g_term.cursor++;
	if (key == LEFT_KEY
		&& g_term.cursor - 1 < g_term.argc)
		g_term.cursor--;
	if (key == TOP_KEY
		&& g_term.cursor - g_term.grid.cols >= 0)
		g_term.cursor -= g_term.grid.cols;
	if (key == DOWN_KEY
		&& g_term.cursor + g_term.grid.cols < g_term.argc)
		g_term.cursor += g_term.grid.cols;
	clear();
	display_files();
}

void			select(void)
{
	move_cursor(RIGHT_KEY);
}

void			ft_select(void)
{
	long key;

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
			select();
	}
}

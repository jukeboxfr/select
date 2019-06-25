#include "ft_select.h"

static int
check_grid(int width, t_grid *grid)
{
	int	i;
	int	j;

	j = 0;
	grid->cols = 0;
	while (j < g_term.argc)
	{
		if ((width = width - grid->padding) < 0)
			return (0);
		grid->cols++;
		i = 0;
		while (j < g_term.argc && i++ < grid->rows)
			j++;
	}
	return (width >= 0);
}

static int
get_column_width(void)
{
	int		width;
	int		column_width;
	int		i;

	column_width = 1;
	i = 0;
	while (i < g_term.argc)
	{
		width = ft_strlen(g_term.argv[i]);
		if (width > column_width)
			column_width = width;
		i++;
	}
	return (column_width + 1);
}

static void
set_grid(struct winsize *w, t_grid *grid)
{
	grid->padding = get_column_width();
	grid->rows = 1;
	while (grid->rows <= g_term.argc)
	{
		if (check_grid(w->ws_col, grid))
			break ;
		grid->rows++;
	}
}

void
display_files(void) {
	t_grid	grid;
	struct 	winsize w;
	int		index;
	int 	colors;
	int 	padding;

	ioctl(0, TIOCGWINSZ, &w);
	set_grid(&w, &grid);
	index = 0;
	while (index < g_term.argc)
	{
		colors = get_colors(g_term.argv[index], index);
		display_color(colors);
		ft_putstr(g_term.argv[index]);
		if (colors)
			ft_putstr("\033[0m");
		padding = grid.padding - ft_strlen(g_term.argv[index]);
		index++;

		if (index == g_term.argc
			|| !(index % grid.cols)) {
			ft_putchar('\n');
			continue ;
		}
		while (padding-- > 0)
			ft_putchar(' ');
	}
}
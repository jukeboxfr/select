# include "ft_select.h"

static void
print_color(int options) {
	if ((options & OPT_RED) == OPT_RED)
		return ft_putstr("31m");
	if ((options & OPT_GREEN) == OPT_GREEN)
		return ft_putstr("32m");
	if ((options & OPT_YELLOW) == OPT_YELLOW)
		return ft_putstr("33m");
	if ((options & OPT_BLUE) == OPT_BLUE)
		return ft_putstr("34m");
	if ((options & OPT_MAGENTA) == OPT_MAGENTA)
		return ft_putstr("35m");
	if ((options & OPT_CYAN) == OPT_CYAN)
		return ft_putstr("36m");
	ft_putstr("0m");
}

static void
print_weight(int options) {
	if ((options & OPT_BOLD) == OPT_BOLD)
		return ft_putstr("[1;");
	if ((options & OPT_ITALIC) == OPT_ITALIC)
		return ft_putstr("[3;");
	if ((options & OPT_UNDERLINE) == OPT_UNDERLINE)
		return ft_putstr("[4;");
	ft_putstr("[");
}

void
display_color(int opts) {
	if (!opts)
		return ;
	ft_putchar('\033');
	print_weight(opts);
	print_color(opts);
}

static char*
get_ext(char *str) {
	char 	*ptr;
	char 	*ext;

	ext = NULL;
	ptr = str;
	while ((ptr = ft_strchr(ptr, '.')))
		ext = ++ptr;
	return (ext);
}

int
get_colors(char *filename, int index) {
	char 	*ext;
	int 	opts;

	opts = 0;
	ext = get_ext(filename);
	if (g_term.cursor == index)
		opts |= OPT_UNDERLINE;
	if (ext && !ft_strcmp(ext, "c"))
		opts |= OPT_YELLOW;
	if (ext && !ft_strcmp(ext, "o"))
		opts |= OPT_MAGENTA;
	if (ext && !ft_strcmp(ext, "h"))
		opts |= OPT_CYAN;
	return (opts);
}
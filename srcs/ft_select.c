#include "ft_select.h"

void 	exec(char *str) {
	char 	*chars;

	if (!(chars = tgetstr(str, NULL)))
		return (NULL);
	tputs(chars, 1, ft_putchar);
}
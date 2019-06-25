#include "ft_select.h"

void			ft_select(void)
{
	long key;

	while (42)
	{
		key = 0;
		read(STDIN_FILENO, &key, 8);
		printf("La clée est %i\n", key);
	}
}

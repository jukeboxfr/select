#include <stdlib.h>

#include <curses.h>
#include <term.h>

int	main(int argc, char **argv[])
{
	char 	*term;

	if (!(term = getenv("TERM")))
		return (1);
	if (tgetent(NULL, term) < 1)
		return (1);

}

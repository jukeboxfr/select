#ifndef FT_SELECT_H
# define FT_SELECT_H

#include <stdlib.h>
#include <termcap.h>
#include <sys/ioctl.h>

#include <signal.h>

#include <stdio.h> // Debug

#include "libft.h"

# define ERROR -1
# define SUCCESS 0

# define OPT_RED (1 << 1)
# define OPT_GREEN (1 << 2)
# define OPT_YELLOW (1 << 3)
# define OPT_BLUE (1 << 4)
# define OPT_MAGENTA (1 << 5)
# define OPT_CYAN (1 << 6)

# define OPT_UNDERLINE (1 << 7)
# define OPT_BOLD (1 << 8)
# define OPT_ITALIC (1 << 9)

typedef struct		s_grid {
	int		rows;
	int		cols;
	int 	padding;
}					t_grid;

typedef struct 		s_term {
	int 	cursor;
	int 	argc;
	char 	**argv;
}					t_term;

t_term 			g_term;

void
ft_select(t_term *term, int argc, char **argv);
void
display_files(void);

int
get_colors(char *filename, int index);
void
display_color(int opts);

#endif

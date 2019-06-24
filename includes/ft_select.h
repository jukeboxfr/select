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

typedef struct		s_grid {
	int		rows;
	int		cols;
	int 	padding;
}					t_grid;

typedef struct 		s_term {
	int 	argc;
	char 	**argv;
}					t_term;

t_term 			g_term;

void
ft_select(t_term *term, int argc, char **argv);
void
display_files(void);


#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kesaint- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/29 14:24:44 by kesaint-          #+#    #+#             */
/*   Updated: 2019/07/22 16:27:37 by kesaint-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <sys/ioctl.h>

# include <signal.h>

# include <termios.h>
# include <unistd.h>

# include <stdio.h>

# include "libft.h"

# define BUFF_SIZE 4096

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

# define OPT_RE_SCREEN (1 << 10)

# define SPACE_KEY 32
# define ESCAPE_KEY 27
# define ENTER_KEY 10
# define BACKSPACE_KEY 127
# define DELETE_KEY 2117294875L

# define LEFT_KEY 4479771
# define RIGHT_KEY 4414235
# define TOP_KEY 4283163
# define DOWN_KEY 4348699

typedef struct		s_grid {
	int		rows;
	int		cols;
	int		padding;
}					t_grid;

typedef struct		s_term {
	int				count;
	int				*selected;
	int				cursor;
	int				argc;
	char			**argv;
	t_grid			grid;
	struct termios	term;
}					t_term;

t_term				g_term;

void				listen_signals(void);

void				clear_terminal(void);
int					set_terminal(void);
void				reset_terminal(void);

int					is_selected(int index);
void				move_cursor(long key);
void				remove_args(void);
void				on_select(void);

void				stop(int sig);

void				ft_select(void);
void				display_files(void);

int					get_colors(char *filename, int index);
void				display_color(int opts);

#endif

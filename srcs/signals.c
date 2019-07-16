#include "ft_select.h"

void		listen_signals(void)
{
	signal(SIGINT, stop);
	signal(SIGABRT, stop);
	signal(SIGSTOP, stop);
	signal(SIGKILL, stop);
	signal(SIGQUIT, stop);
}
#include "ft_select.h"

void
stop(int sig) {
	ft_putstr("\033[?1049l");
	tcsetattr(STDIN_FILENO, TCSADRAIN, &g_term.term);
	exit(EXIT_SUCCESS);
}

static void
listen_signals(void) {
	signal(SIGINT, stop);
	signal(SIGABRT, stop);
	signal(SIGSTOP, stop);
	signal(SIGKILL, stop);
	signal(SIGQUIT, stop);
}

static int
init_term(void) {
	char			*var;
	int 			code;
	struct termios	term;

	if (!(var = getenv("TERM")))
	{
		ft_putstr("La variable d'environnement TERM est manquante\n");
		return (ERROR);
	}
	if ((code = tgetent(NULL, var)) < 1) {
		ft_putstr(code ? "Unable to read database\n" : "Le type de terminal spécifié est introuvable\n");
		return (ERROR);
	}
	tcgetattr(STDIN_FILENO, &g_term.term);
	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag &= ~(ICANON | ECHO);
    term.c_lflag &= ~(OPOST);
	term.c_cc[VMIN] = 1;
	term.c_cc[VTIME] = 0;
	tcsetattr(STDIN_FILENO, TCSADRAIN, &term);
	return (SUCCESS);
}

int
main(int argc, char *argv[]) {
	if (argc < 2)
	{
		ft_putstr("Usage: file1 [file2...]\n");
		return (1);
	}
	if (init_term() < 0)
		return (1);
	ft_memset(&g_term, 0, sizeof(g_term));
	g_term.argc = argc - 1;
	g_term.argv = argv + 1;
	ft_putstr("\033[?1049h\033[H");
	display_files();
	listen_signals();
	ft_select();
	return (0);
}

#include "ft_select.h"

static void
interrupt_program(void) {
	exit(EXIT_SUCCESS);
}

static void
listen_signals(void) {
	// signal(SIGINT, interrupt);
	// signal(SIGABRT, interrupt);
	// signal(SIGSTOP, interrupt);
	// signal(SIGKILL, interrupt);
	// signal(SIGQUIT, interrupt);
}

static int
init_term(void) {
	char	*var;
	int 	code;

	if (!(var = getenv("TERM")))
	{
		ft_putstr("La variable d'environnement TERM est manquante\n");
		return (ERROR);
	}
	if ((code = tgetent(NULL, var)) < 1) {
		ft_putstr(code ? "Unable to read database\n" : "Le type de terminal spécifié est introuvable\n");
		return (ERROR);
	}
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
	g_term.argc = argc - 1;
	g_term.argv = argv + 1;
	display_files();
	return (0);
}

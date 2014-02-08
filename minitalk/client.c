int		main(int argc, char **argv)
{
	int	pid;

	if (argc != 2)
		ft_fatal("Invalid number of argument.");
	pid = ft_atoi(argv[1]);
	prompt(pid);
	return (0);
}

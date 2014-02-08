void		prompt(int pid)
{
	int		i;
	char	*line;

	while (get_next_line(&line) > 0)
	{
		i = 0;
		while (line[i])
		{
			send(line[i]);
			i++;
		}
	}
}

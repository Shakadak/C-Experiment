void	binary_loop(void)
{
	char	*entry[2];
	int	k;

	k = 0;
	while (get_next_line(0, entry[k]) == 1)
	{
		if (k)
			ft_place_entry(&entry);
		else if (entry[k][0] == '\0')
			break ;
		k = (k ? 0 : 1);
	}
}

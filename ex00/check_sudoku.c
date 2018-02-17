int     ft_is_available_in_line(int line, int value, char **grid)
{
	int column;

	column = 0;
	while (column <= 8)
	{
		while (value != grid[line][column])
			column++;
		if (column == 8)
			return (1);
	}
	return (0);
}

int     ft_is_available_in_column(int column, int value, char **grid)
{
	int line;

	line = 1;
	while (line <= 9)
	{
		while(value != grid[line][column])
			line++;
		if (line == 9)
			return (1)
	}
	return (0);
}

int     *ft_limits_of_block(int column, int line)
{
	int limits[2];

	if (line <= 3 && line >= 1)
		limits[0] = 3;
	else if (line <= 6 && line >= 4)
		limits[0] = 6;
	else
		limits[0] = 9;
	if (column <= 3 && column >= 1)
		limits[1] = 3;
	else if (column <= 6 && column >= 4)
		limits[1] = 6;
	else
		limits[1] = 9;
}

int		ft_is_available_in_block(int *limits, int value, char **grid)
{
	int line;
	int column;

	line = 0;
	while (line <= limits[0])
	{
		column = 0;
		while (column <= limits[1])
		{
			if (value != grille[line][column])
				column++;
			else
				return (0);
		}
		line++;
	}
	return (1);
}

int		ft_check_availability(int value, int column,
		int line, char **grid)
{
	int	*limits;

	limits = ft_limits_of_block(column, line, grid);
	if (ft_is_available_in_line(line, value, grid)
				&& ft_is_available_in_column(column, value, grid)
				&& ft_is_available_in_block(limits, value, grid))
		return (1);
	else
		return (0);
}

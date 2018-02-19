/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sudoku_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luman <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:05:05 by luman             #+#    #+#             */
/*   Updated: 2018/02/18 22:54:36 by luman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_chars(char **str)
{
	int char_count;
	int i;
	int j;

	i = 1;
	char_count = 0;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (str[i][j] >= '1' && str[i][j] <= '9')
				char_count++;
			j++;
		}
		i++;
	}
	if (char_count >= 17)
		return (1);
	else
		return (0);
}

int		ft_strlen_check(char **str)
{
	int i;
	int j;

	i = 1;
	while (i <= 9)
	{
		j = 0;
		while (str[i][j])
		{
			if (j >= 9 || !((str[i][j] >= '1' && str[i][j] <= '9')
						|| str[i][j] == '.'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int		ft_check_li(int value, int grid[9][9], int line)
{
	int column;

	column = 0;
	while (column < 9)
	{
		if (value == grid[line][column])
			return (0);
		column++;
	}
	return (1);
}

int		ft_check_col(int value, int grid[9][9], int column)
{
	int line;

	line = 0;
	while (line < 9)
	{
		if (value == grid[line][column])
			return (0);
		line++;
	}
	return (1);
}

int		ft_check_block(int value, int grid[9][9], int line, int column)
{
	int line_2;
	int column_2;

	line_2 = line - (line % 3);
	column_2 = column - (column % 3);
	line = line_2;
	while (line < line_2 + 3)
	{
		column = column_2;
		while (column < column_2 + 3)
		{
			if (value == grid[line][column])
				return (0);
			column++;
		}
		line++;
	}
	return (1);
}

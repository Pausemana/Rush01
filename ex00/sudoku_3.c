/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luman <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/18 17:16:42 by luman             #+#    #+#             */
/*   Updated: 2018/02/18 23:08:50 by luman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int		ft_check_li(int value, int grid[9][9], int line);

int		ft_check_col(int value, int grid[9][9], int column);

int		ft_check_block(int value, int grid[9][9], int line, int column);

int		ft_count_chars(char **str);

int		ft_strlen_check(char **str);

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_fill_table(int grid[9][9], char **str)
{
	int i;
	int j;

	i = 1;
	while (i < 10)
	{
		j = 0;
		while (j < 9)
		{
			if (str[i][j] != '.')
				grid[i - 1][j] = str[i][j] - '0';
			else
				grid[i - 1][j] = 0;
			j++;
		}
		i++;
	}
}

void	ft_print_sudoku(int grid[9][9])
{
	int line;
	int column;

	line = 0;
	while (line < 9)
	{
		column = 0;
		while (column < 9)
		{
			ft_putchar('0' + grid[line][column]);
			if (column == 8)
				break ;
			else
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		line++;
	}
}

int		ft_solve_sudoku(int grid[9][9], int position)
{
	int li;
	int col;
	int val;

	if (position == 81)
		return (1);
	li = position / 9;
	col = position % 9;
	if (grid[li][col] != 0)
		return (ft_solve_sudoku(grid, position + 1));
	val = 1;
	while (val <= 9)
	{
		if (ft_check_li(val, grid, li) == 1 && ft_check_col(val, grid, col) == 1
				&& ft_check_block(val, grid, li, col) == 1)
		{
			grid[li][col] = val;
			if (ft_solve_sudoku(grid, position + 1) == 1)
				return (1);
		}
		val++;
	}
	grid[li][col] = 0;
	return (0);
}

int		main(int argc, char **argv)
{
	int grid[9][9];

	if (argc == 10)
	{
		if (ft_strlen_check(argv) && ft_count_chars(argv))
		{
			ft_fill_table(grid, argv);
			if (ft_solve_sudoku(grid, 0))
				ft_print_sudoku(grid);
			else
				write(1, "Error\n", 6);
		}
		else
			write(1, "Error\n", 6);
	}
	else
	{
		write(1, "Error\n", 6);
	}
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luman <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 16:24:17 by luman             #+#    #+#             */
/*   Updated: 2018/02/17 17:07:15 by luman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcheck_len(char *str)
{
	int i;

	i = 0;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
		i++;
	if (i == 8)
		return (1);
	else
		return (0);
}

void	ft_print_sudoku(char **grille)
{
	int i;
	int j;

	i = 1;
	while(i <= 9)
	{
		j = 0;
		while (j <= 8)
		{
			ft_putchar(grille[i][j]);
			ft_putchar(' ');
			j++;
		}
		i++;
		ft_putchar('\n');
	}
}

int		ft_is_available_in_line(int ligne, int value, char **grille)
{
	int colonne;

	colonne = 0;
	while (colonne <= 8)
	{
		while (value != grille[ligne][colonne])	
			colonne++;
		if (colonne == 8)
			return (1);
	}
	return (0);
}

int		ft_is_available_in_column(int colonne, int value, char **grille)
{
	int ligne;

	ligne = 1;
	while (ligne <= 9)
	{
		while(value != grille[ligne][colonne])
			ligne++;
		if (ligne == 9)
			return (1)
	}
	return (0);
}

int		*ft_limits_of_block(int column, int line, char **grille)
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

int		main(int argc, char **argv)
{
	int i;

	i = 1;
	if (argc == 10)
	{
		if (ft_strcheck_len(argv))
		{
			ft_print_sudoku(argv);
		}
		else
			write(1, "Error\n", 6);
	}
	else
		write(1, "Error\n", 6);
}

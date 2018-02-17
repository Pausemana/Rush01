/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luman <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/17 17:25:20 by luman             #+#    #+#             */
/*   Updated: 2018/02/17 17:34:39 by luman            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strcheck_len(char *str)
{
	int i;

	i = 1;
	while (str[i] && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.'))
		i++;
	if (i == 8)
		return (1);
	else
		return (0);
}

int		ft_all_is_filled(char **grid)
{
	int line;
	int column;
	int count_points;

	count_points = 0;
	line = 1;
	while (line <= 9)
	{
		column = 0;
		while (column <= 8)
		{
			if (grid[line][column] == '.')
				count_point++;
			column++;
		}
		line++;
	}
	if(count_points)
		return (0);
	return (1);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbeauman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:15:36 by tbeauman          #+#    #+#             */
/*   Updated: 2016/01/12 15:16:01 by tbeauman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int		main(int ac, char **av)
{
	int		fd;
	char	*line;
	int		i;

	if (ac > 2)
	{
		int		fd2;
		int		fd3;

		fd = open(av[1], O_RDONLY);
		fd2 = open(av[2], O_RDONLY);
		fd3 = open(av[3], O_RDONLY);
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd3, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd2, &line);
		ft_putstr(line);
		ft_putchar('\n');
		get_next_line(fd3, &line);
		ft_putstr(line);
		ft_putchar('\n');
		return (1);
	}
	i = 1;
	if (ac == 1)
	{
		while (get_next_line(0, &line) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
		return 1;
	}
	fd = open(av[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
	{
		if (i <= 9)
			ft_putchar('0');
		ft_putnbr(i);
		ft_putchar(' ');
		ft_putstr(line);
		ft_putchar('\n');
		i++;
	}
	close (fd);
	ft_putnbr(get_next_line(42, &line));
	ft_putchar('\n');
	return 0;
}

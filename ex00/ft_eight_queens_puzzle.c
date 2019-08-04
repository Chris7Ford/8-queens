/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_eight_queens_puzzle.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chford <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 09:53:32 by chford            #+#    #+#             */
/*   Updated: 2019/03/06 19:16:51 by chford           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"

#define BOARD_SIZE 8

int		count_queens(int **board)
{
	int		count;
	int		i;
	int		j;

	count = 0;
	i = 0;
	j = 0;
	while (i < BOARD_SIZE)
	{
		while (j < BOARD_SIZE)
		{
			if (board[i][j] == 1)
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

void	print_tab(int** board)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (i < BOARD_SIZE)
	{
		while (j < BOARD_SIZE)
		{
			ft_putnbr(board[i][j]);
			ft_putchar(' ');
			j++;
		}
		j = 0;
		i++;
		ft_putchar('\n');
	}
}

void	make_board(int ***board)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	(*board) = (int **)malloc(sizeof(int *) * (BOARD_SIZE));
	while (i < BOARD_SIZE)
	{
		(*board)[i] = (int *)malloc(sizeof(int) * (BOARD_SIZE));
		i++;
	}
	i = 0;
	while (i < BOARD_SIZE)
	{
		while (j < BOARD_SIZE)
		{
			(*board)[i][j] = 0;
			j++;
		}
		j = 0;
		i++;
	}
}

int		check_surroundings(int **board, int i, int j)
{
	int		index;
	int		copy;

	index = 0;
	if (board[i][j] == 1)
		return (0);
	while (index < BOARD_SIZE)
	{
		if (board[i][index] == 1)
			return (0);
		index++;
	}
	index = i;
	while (index >= 0)
	{
		if (board[index][j] == 1)
			return (0);
		index--;
	}
	index = i;
	copy = j;
	while (copy > 0 && index > 0)
	{
		copy--;
		index--;
		if (board[index][copy] == 1)
			return (0);
	}
	index = i;
	copy = j;
	while (copy < BOARD_SIZE - 1 && index > 0)
	{
		copy++;
		index--;
		if (board[index][copy] == 1)
			return (0);
	}
	index = i;
	copy = j;
	return (1);
}

int		fill_board(int ***board, int i, int *queens_placed, int *solution_count)
{
	int		j;

	j = 0;
	*queens_placed = count_queens(*board);
	if (*queens_placed == 8)
	{
		*solution_count += 1;
//		print_tab(*board);
/*			ft_putstr("\n\ni = ");
			ft_putnbr(i);
			ft_putchar('\n');
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putchar('\n');
			ft_putstr("\nqueens placed = ");
			ft_putnbr(*queens_placed);
			ft_putchar('\n');
*/		return (0);
	}
	if (i == BOARD_SIZE)
		return (0);
	while (j < BOARD_SIZE)
	{
		if (check_surroundings(*board, i, j))
		{
//			*queens_placed += 1;
			(*board)[i][j] = 1;
/*			ft_putstr("---------\n\n");
			ft_putstr("Adding queen:\n");
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putchar('\n');
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putchar('\n');
			ft_putstr("\nqueens placed = ");
			ft_putnbr(*queens_placed);
			ft_putchar('\n');
			print_tab(*board);
			ft_putstr("---------");
*/			if (fill_board(board, i + 1, queens_placed, solution_count))
				return (1);
			(*board)[i][j] = 0;
//			queens_placed -= 1;
/*			ft_putstr("---------\n\n");
			ft_putstr("Removing queen:\n");
			ft_putstr("i = ");
			ft_putnbr(i);
			ft_putchar('\n');
			ft_putstr("j = ");
			ft_putnbr(j);
			ft_putchar('\n');
			ft_putstr("\nqueens placed = ");
			ft_putnbr(*queens_placed);
			ft_putchar('\n');
			print_tab(*board);
			ft_putstr("---------");
*/		}
		j++;
	}
	return (0);
}

int		ft_eight_queens_puzzle(void)
{
	int		**board;
	int		solution_count;
	int		queens_placed;
	int		backtrack_row;

	make_board(&board);
	queens_placed = 0;
	backtrack_row = 0;
	solution_count = 0;
	fill_board(&board, 0, &queens_placed, &solution_count);
	return (solution_count);
}

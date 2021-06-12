#include <unistd.h>

int	sum_view(int **matriz, int direction, int position, int side)
{
	int i;
	int last_view;
	int qty;

	last_view = 0;
	qty = 0;
	if (direction == 0)
	{
		i = 0;
		while (i < side)
		{
			if (matriz[i][position] > last_view)
			{
				last_view = matriz[i][position];
				qty++;
			}
			i++;
		}
	}
	else if (direction == 1)
	{
		i = side - 1;
		while (i >  -1)
		{
			if (matriz[i][position] > last_view)
			{
				last_view = matriz[i][position];
				qty++;
			}
			i--;
		}
	}
	else if (direction == 2)
	{
		i = 0;
		while (i < side)
		{
			if (matriz[position][i] > last_view)
			{
				last_view = matriz[position][i];
				qty++;
			}
			i++;
		}
	}
	else if (direction == 3)
	{
		i = side - 1;
		while (i >  -1)
		{
			if (matriz[position][i] > last_view)
			{
				last_view = matriz[position][i];
				qty++;
			}
			i--;
		}
	}
	return (qty);
}

int	check_matriz(int **rules, int **matriz, int side)
{
	int direction;
	int position;

	direction = 0;
	while (direction < side)
	{
		position = 0;
		while (position < side)
		{
			if (rules[direction][position] != sum_view(matriz, direction, position, side))
				return (0);
			position++;
		}
		direction++;
	}
	return (1);
}

void	write_matriz(int **matriz, int side)
{
	int row;
	int column;
	char c;

	row = 0;
	while (row < side)
	{
		column = 0;
		while (column < side)
		{
			c = '0' + matriz[row][column];
			write(1, &c, 1);
			write(1, " ", 1);
			column++;
		}
		row++;
		write(1, "\n", 1);
	}
}

void	next_matriz(int **matriz, int side)
{
	int		row;
	int		column;
	char	c;

	row = side - 1;
	while (row > 0)
	{
		column = side - 1;
		while (column > 0)
		{
			if (matriz[row][column] < side)
			{
				matriz[row][column]++;
				column++;
				while (row < side)
				{
					while (column < side)
					{
						matriz[row][column] = 1;
						column++;
					}
					row++;
					column = 0;
				}
				return ;
			}
			column--;
		}
		row--;
	}
}

void	rush(int **rules, int **matriz, int side)
{
	int row;
	int column;

	row = 0;
	while (row < side)
	{
		column = 0;
		while (column < side)
		{
			matriz[row][column] = column + 1;
			column++;
		}
		row++;
	}
	while (!check_matriz(rules, matriz, side))
		next_matriz(matriz, side);
	write_matriz(matriz, side);
}
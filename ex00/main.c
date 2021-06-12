#include <stdio.h>
#include <stdlib.h>

void	rush(int **rules, int **matriz, int side);

int	str_to_vetor_int(char *arg, int *data)
{
	int	i;

	i = 0;
	data[i] = 0;
	while (*arg)
	{
		if (*arg == ' ')
		{
			i++;
			data[i] = 0;
		}
		else
			data[i] = (data[i] * 10) + *arg - 48;
		arg++;
	}
	return (i + 1);
}

int	main(int argc, char **argv)
{
	int	data[20];
	int	side;
	int	i;
	int	j;

	argc = str_to_vetor_int(argv[1], data);
	side = argc / 4;
	int	**rules = (int **)malloc(side * 8);
	for(int i = 0; i < side; i++)
		rules[i] = (int *)malloc(side * 4);
	int	**matriz = (int **)malloc(side * 8);
	for(int i = 0; i < side; i++)
		matriz[i] = (int *)malloc(side * 4);
	i = 0;
	while (i < side)
	{
		j = 0;
		while (j < side)
		{
			rules[i][j] = data[(i * side) + j];
			j++;
		}
		i++;
	}
	rush(rules, matriz, side);
}

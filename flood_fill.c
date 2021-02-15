#include <stdio.h>

void	print_map(char *map_p, int y, int x)
{
	int i = 0;
	int j = 0;

	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%c", map_p[i * x + j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	check_fill(char *map_p, int y, int x, int p_y, int p_x, int *false_checker)
{
	if (map_p[p_y * x + p_x] == '3' || map_p[p_y * x + p_x] == '1' || *false_checker == 1)
		return ;
	print_map(map_p, y, x);
	if (map_p[p_y * x + p_x] == 'X')
	{
		*false_checker = 1;
		return ;
	}
	if (map_p[p_y * x + p_x] == '0' || map_p[p_y * x + p_x] == 's')
		map_p[p_y * x + p_x] = '3';
	check_fill(map_p, y, x, p_y - 1, p_x, false_checker);
	check_fill(map_p, y, x, p_y, p_x + 1, false_checker);
	check_fill(map_p, y, x, p_y + 1, p_x, false_checker);
	check_fill(map_p, y, x, p_y, p_x - 1, false_checker);
}

void	put_grid_to_container(char *map_p, char *cont_p, int y, int x)
{
	int i = 0, j = 0;
	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			if (i == 0 || i == y - 1 || j == 0 || j == x - 1)
				cont_p[i * x + j] = 'X'; // X = edge
			else if (i > 9 || j > 18)
				cont_p[i * x + j] = 's'; // s = space out of wall (should be)
			else
				cont_p[i * x + j] = map_p[(i - 1) * 18 + (j - 1)]; // copy map to container
			j++;
		}
		i++;
	}
}

int main()
{
	char map[9][18] = {
		{'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0'}
			};
	char *map_p = (char *)map;
	int y = sizeof(map) / sizeof(map[0]) + 2;
	int x = sizeof(map[0]) / sizeof(map[0][0]) + 2;
	char *cont_p = malloc(sizeof(char) * y * x);
	int false_checker = -1;
	put_grid_to_container(map_p, cont_p, y, x);
	print_map(cont_p, y, x);
	check_fill(cont_p, y, x, 4, 9, &false_checker);
	print_map(cont_p, y, x);
	if (false_checker == 1)
		printf("\nError: Map is not sorrounded by wall.\n");
	return (0);
}

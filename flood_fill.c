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
	print_map(map_p, 25, 25);
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

void	put_grid_to_container(char *map_p, char *cont_p)
{
	int i = 0, j = 0;
	while (i < 25)
	{
		j = 0;
		while (j < 25)
		{
			if (i == 0 || i == 24 || j == 0 || j == 24)
				cont_p[i * 25 + j] = 'X'; // X = edge
			else if (i > 9 || j > 18)
				cont_p[i * 25 + j] = 's'; // s = space out of wall (should be)
			else
				cont_p[i * 25 + j] = map_p[(i - 1) * 18 + (j - 1)]; // copy map to container
			j++;
		}
		i++;
	}
}

int main()
{
	char map[9][18] = {
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '2', '0', '0', '0', '0', '0', '0', '1', '0', '0'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '1'},
		{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
		{'1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1'},
		{'1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
		{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
			};
	char container[25][25];
	char *map_p = (char *)map;
	char *cont_p = (char *)container;
	int false_checker = -1;
	put_grid_to_container(map_p, cont_p);
	print_map(cont_p, 25, 25);
	check_fill(cont_p, 25, 25, 4, 9, &false_checker);
	print_map(cont_p, 25, 25);
	if (false_checker == 1)
		printf("\nError: Map is not sorrounded by wall.\n");
	return (0);
}

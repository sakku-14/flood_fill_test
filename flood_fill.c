#include <stdio.h>

void	print_map(int *map, int y, int x)
{
	int i = 0;
	int j = 0;

	while (i < y)
	{
		j = 0;
		while (j < x)
		{
			printf("%d", map[i * x + j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

void	check_fill(int *map, int y, int x, int p_y, int p_x, int *false_checker)
{
	if (map[p_y * x + p_x] == 3 || map[p_y * x + p_x] == 1 || *false_checker == 1)
		return ;
//	print_map(map, 9, 18);
	if (map[p_y * x + p_x] == -1)
	{
		*false_checker = 1;
		return ;
	}
	if (map[p_y * x + p_x] == 0)
		map[p_y * x + p_x] = 3;
	check_fill(map, y, x, p_y - 1, p_x, false_checker);
	check_fill(map, y, x, p_y, p_x + 1, false_checker);
	check_fill(map, y, x, p_y + 1, p_x, false_checker);
	check_fill(map, y, x, p_y, p_x - 1, false_checker);
}

/*
void	put_grid_to_container(int *map, int *cont_p)
{
	int i = 0, j = 0;
	int flag_y = -1, flag_x = -1;
	while (i < 100)
	{
		j = 0;
		flag_x = -1
		while (j < 100)
		{
			if (map[] )
			cont_p[i * 100 + j] 
			j++;
		}
		i++;
	}
}
*/

int main()
{
	int grid[9][18] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 0, 1},
		{1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
		{1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
			};
//	int container[100][100];
	int *map = (int *)grid;
//	int *cont_p = (int *)container;
	int false_checker = -1;
//	put_grid_to_container(map, cont_p);
	print_map(map, 9, 18);
	check_fill(map, 9, 18, 3, 8, &false_checker);
	print_map(map, 9, 18);
	if (false_checker == 1)
		printf("\nError: Map is not sorrounded by wall.\n");
	return (0);
}

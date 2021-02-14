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

void	check_fill(int *map, int y, int x, int p_y, int p_x)
{
	if (map[p_y * x + p_x] == 3 || map[p_y * x + p_x] == 1)
		return ;
	print_map(map, 8, 18);
	if (map[p_y * x + p_x] == -1)
	{
		printf("error");
		return ;
	}
	if (map[p_y * x + p_x] == 0)
		map[p_y * x + p_x] = 3;
	check_fill(map, y, x, p_y - 1, p_x);
	check_fill(map, y, x, p_y, p_x + 1);
	check_fill(map, y, x, p_y + 1, p_x);
	check_fill(map, y, x, p_y, p_x - 1);
	
}

int main()
{
	int grid[8][18] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 0, 1, 1, 0, 1, 1, 2, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
			};
	int *map = (int *)grid;
	print_map(map, 8, 18);
	check_fill(map, 8, 18, 4, 8);
	print_map(map, 8, 18);
	return (0);
}

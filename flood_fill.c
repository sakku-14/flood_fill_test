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
}

int main()
{
	int grid[7][10] = {
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 2, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
		{1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
			};
	int *map = (int *)grid;
	print_map(map, 7, 10);
	return (0);
}

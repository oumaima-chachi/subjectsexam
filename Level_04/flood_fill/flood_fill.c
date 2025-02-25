#include <stdlib.h>
#include <stdio.h>

typedef struct s_point
{
    int x;
    int y;
} t_point;

void flood_fill(char **tab, t_point size, t_point begin)
{
    // Check bounds to ensure that we don't access outside the array
    if (begin.x < 0 || begin.x >= size.x || begin.y < 0 || begin.y >= size.y)
        return;

    char target = tab[begin.y][begin.x];
    
    // If the target is already 'F', no need to fill further
    if (target == 'F')
        return;

    // Stack-based DFS approach (iterative) to avoid stack overflow from recursion
    tab[begin.y][begin.x] = 'F';

    // Directions for moving up, down, left, right
    t_point directions[] = {
        {0, 1}, // down
        {0, -1}, // up
        {1, 0}, // right
        {-1, 0}  // left
    };

    for (int i = 0; i < 4; i++)
    {
        t_point next = {begin.x + directions[i].x, begin.y + directions[i].y};

        // Ensure the next point is within bounds and matches the target character
        if (next.x >= 0 && next.x < size.x && next.y >= 0 && next.y < size.y && tab[next.y][next.x] == target)
        {
            flood_fill(tab, size, next); // Recursive call to fill adjacent points
        }
    }
}
#include <stdlib.h>
#include <stdio.h>
 

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}

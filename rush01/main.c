#include <stdlib.h>
#include <unistd.h>

void	generate_permutations(int *array, int start, int end, int **output,
			int *count);
int		check_clues(int **grid, int *clues);
int		**allocate_2D_array(int rows, int cols);
void	deallocate_2D_array(int **array, int rows);
void	copy_array(int *src, int *dest, int n);
void	print_solution(int **grid);
int		find_solution(int **grid, int **permutations, int permutation_count,
			int *clues);
void	copy_arrays(int **permutations, int **grid, int i, int j, int k, int l);
int		check_clue(int **grid, int *clues, int i, int *row, int *col);
int		check_row_clue(int **grid, int *clues, int i, int *row);

int	main(void)
{
	int	clues[] = {2, 2, 1, 3, 2, 2, 3, 1, 2, 2, 1, 3, 2, 2, 3, 1};
	int	numbers[] = {1, 2, 3, 4};
	int	permutation_count;
	int	**grid;
	int	solution_found;
	int	**permutations;

	permutation_count = 0;
	permutations = allocate_2D_array(24, 4);
	generate_permutations(numbers, 0, 3, permutations, &permutation_count);
	grid = allocate_2D_array(4, 4);
	solution_found = find_solution(grid, permutations, permutation_count,
			clues);
	if (!solution_found)
	{
		write(1, "Error\n", 6);
	}
	deallocate_2D_array(grid, 4);
	deallocate_2D_array(permutations, 24);
	return (0);
}

void	print_solution(int **grid)
{
	int		m;
	int		n;
	char	c;

	m = 0;
	while (m < 4)
	{
		n = 0;
		while (n < 4)
		{
			c = grid[m][n] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			n++;
		}
		write(1, "\n", 1);
		m++;
	}
}

int	find_solution(int **grid, int **permutations, int permutation_count,
		int *clues)
{
	int	i;
	int	j;
	int	k;
	int	l;

	i = 0;
	while (i < permutation_count)
	{
		j = 0;
		while (j < permutation_count)
		{
			k = 0;
			while (k < permutation_count)
			{
				l = 0;
				while (l < permutation_count)
				{
					copy_arrays(permutations, grid, i, j, k, l);
					if (check_clues(grid, clues))
					{
						print_solution(grid);
						return (1);
					}
					l++;
				}
				k++;
			}
			j++;
		}
		i++;
	}
	return (0);
}

void	copy_arrays(int **permutations, int **grid, int i, int j, int k, int l)
{
	copy_array(permutations[i], grid[0], 4);
	copy_array(permutations[j], grid[1], 4);
	copy_array(permutations[k], grid[2], 4);
	copy_array(permutations[l], grid[3], 4);
}

void	swap(int *x, int *y)
{
	int	temp;

	temp = *x;
	*x = *y;
	*y = temp;
}

void	generate_permutations(int *array, int start, int end, int **output,
		int *count)
{
	int	i;

	if (start == end)
	{
		i = 0;
		while (i <= end)
		{
			output[*count][i] = array[i];
			i++;
		}
		(*count)++;
		return ;
	}
	i = start;
	while (i <= end)
	{
		swap(&array[start], &array[i]);
		generate_permutations(array, start + 1, end, output, count);
		swap(&array[start], &array[i]);
		i++;
	}
}

int	is_unique(int *array, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (array[i] == array[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_clues(int **grid, int *clues)
{
	int	i;
	int	row[4];
	int	col[4];

	i = 0;
	while (i < 4)
	{
		if (!check_clue(grid, clues, i, row, col))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_clue(int **grid, int *clues, int i, int *row, int *col)
{
	int	view;
	int	max_height;
	int	j;

	view = max_height = 0;
	j = 0;
	while (j < 4)
	{
		if (grid[j][i] > max_height)
		{
			max_height = grid[j][i];
			view++;
		}
		col[j] = grid[j][i];
		j++;
	}
	if (clues[i] != view || !is_unique(col, 4))
	{
		return (0);
	}
	view = max_height = 0;
	j = 3;
	while (j >= 0)
	{
		if (grid[j][i] > max_height)
		{
			max_height = grid[j][i];
			view++;
		}
		col[3 - j] = grid[j][i];
		j--;
	}
	if (clues[i + 4] != view || !is_unique(col, 4))
	{
		return (0);
	}
	return (check_row_clue(grid, clues, i, row));
}

int	check_row_clue(int **grid, int *clues, int i, int *row)
{
	int	view;
	int	max_height;
	int	j;

	view = max_height = 0;
	j = 0;
	while (j < 4)
	{
		if (grid[i][j] > max_height)
		{
			max_height = grid[i][j];
			view++;
		}
		row[j] = grid[i][j];
		j++;
	}
	if (clues[i + 8] != view || !is_unique(row, 4))
	{
		return (0);
	}
	view = max_height = 0;
	j = 3;
	while (j >= 0)
	{
		if (grid[i][j] > max_height)
		{
			max_height = grid[i][j];
			view++;
		}
		row[3 - j] = grid[i][j];
		j--;
	}
	if (clues[i + 12] != view || !is_unique(row, 4))
	{
		return (0);
	}
	return (1);
}

int	**allocate_2D_array(int rows, int cols)
{
	int	**array;
	int	i;

	array = (int **)malloc(rows * sizeof(int *));
	i = 0;
	while (i < rows)
	{
		array[i] = (int *)malloc(cols * sizeof(int));
		i++;
	}
	return (array);
}

void	deallocate_2D_array(int **array, int rows)
{
	int	i;

	i = 0;
	while (i < rows)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	copy_array(int *src, int *dest, int n)
{
	int i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		i++;
	}
}

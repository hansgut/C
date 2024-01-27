/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcielesz <jcielesz@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 19:39:44 by jcielesz          #+#    #+#             */
/*   Updated: 2024/01/28 00:54:33 by jcielesz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void generate_permutations(int *array, int start, int end, int **output, int *count);
bool check_clues(int **grid, int *clues);
int **allocate_2D_array(int rows, int cols);
void deallocate_2D_array(int **array, int rows);
void copy_array(int *src, int *dest, int n);

int main() {
	int clues[] = {2, 2, 1, 3, 2, 2, 3, 1, 2, 2, 1, 3, 2, 2, 3, 1};
	int numbers[] = {1, 2, 3, 4};
	int permutation_count = 0;
	int **permutations = allocate_2D_array(24, 4); // Max 24 permutations for 4 numbers

	generate_permutations(numbers, 0, 3, permutations, &permutation_count);

	int **grid = allocate_2D_array(4, 4);
	bool solution_found = false;

	for (int i = 0; i < permutation_count && !solution_found; i++) {
		for (int j = 0; j < permutation_count && !solution_found; j++) {
			for (int k = 0; k < permutation_count && !solution_found; k++) {
				for (int l = 0; l < permutation_count && !solution_found; l++) {
					copy_array(permutations[i], grid[0], 4);
					copy_array(permutations[j], grid[1], 4);
					copy_array(permutations[k], grid[2], 4);
					copy_array(permutations[l], grid[3], 4);

					if (check_clues(grid, clues)) {
						solution_found = true;
						for (int m = 0; m < 4; m++) {
							for (int n = 0; n < 4; n++) {
								printf("%d ", grid[m][n]);
							}
							printf("\n");
						}
					}
				}
			}
		}
	}

	if (!solution_found) {
		printf("Error\n");
	}

	deallocate_2D_array(grid, 4);
	deallocate_2D_array(permutations, 24);
	return 0;
}

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void generate_permutations(int *array, int start, int end, int **output, int *count) {
	if (start == end) {
		for (int i = 0; i <= end; i++) {
			output[*count][i] = array[i];
		}
		(*count)++;
		return;
	}

	for (int i = start; i <= end; i++) {
		swap(&array[start], &array[i]);
		generate_permutations(array, start + 1, end, output, count);
		swap(&array[start], &array[i]); // backtrack
	}
}

bool is_unique(int *array, int size) {
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (array[i] == array[j]) {
				return false;
			}
		}
	}
	return true;
}

bool check_clues(int **grid, int *clues) {
	int view, max_height, col[4];

	for (int i = 0; i < 4; i++) {
		view = max_height = 0;
		for (int j = 0; j < 4; j++) {
			if (grid[j][i] > max_height) {
				max_height = grid[j][i];
				view++;
			}
			col[j] = grid[j][i];
		}
		if (clues[i] != view || !is_unique(col, 4)) {
			return false;
		}

		view = max_height = 0;
		for (int j = 3; j >= 0; j--) {
			if (grid[j][i] > max_height) {
				max_height = grid[j][i];
				view++;
			}
			col[3 - j] = grid[j][i];
		}
		if (clues[i + 4] != view || !is_unique(col, 4)) {
			return false;
		}
	}

	int row[4];
	for (int i = 0; i < 4; i++) {
		view = max_height = 0;
		for (int j = 0; j < 4; j++) {
			if (grid[i][j] > max_height) {
				max_height = grid[i][j];
				view++;
			}
			row[j] = grid[i][j];
		}
		if (clues[i + 8] != view || !is_unique(row, 4)) {
			return false;
		}

		view = max_height = 0;
		for (int j = 3; j >= 0; j--) {
			if (grid[i][j] > max_height) {
				max_height = grid[i][j];
				view++;
			}
			row[3 - j] = grid[i][j];
		}
		if (clues[i + 12] != view || !is_unique(row, 4)) {
			return false;
		}
	}

	return true;
}

int **allocate_2D_array(int rows, int cols) {
	int **array = (int **)malloc(rows * sizeof(int *));
	for (int i = 0; i < rows; i++) {
		array[i] = (int *)malloc(cols * sizeof(int));
	}
	return array;
}

void deallocate_2D_array(int **array, int rows) {
	for (int i = 0; i < rows; i++) {
		free(array[i]);
	}
	free(array);
}

void copy_array(int *src, int *dest, int n) {
	for (int i = 0; i < n; i++) {
		dest[i] = src[i];
	}
}

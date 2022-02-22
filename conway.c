#include <stdio.h>
#include <stdlib.h>
#include "board.h"

int main(void) {
	//Declares the board.
	Board *game;
	game = (Board *) malloc(sizeof(Board));

	//Reads in the rows and columns
	scanf("%d %d", &game->nrows, &game->ncols);

	//Reads in the number of iterations.
	int iterations;
	scanf("%d", &iterations);

	//Allocates memory to the grid.
	game->grid = (char *) malloc((game->nrows+2) * (game->ncols+2) * sizeof(char));
	game->mat = (char **) malloc((game->nrows+2) * sizeof(char *));

	//Turns it into [][] notation.
	for (int i = 0; i < game->nrows+2; i++) {
		game->mat[i] = game->grid + i * (game->ncols+2);
	}

	//Reads in the grid.
	for (int i = 1; i < game->nrows+1; i++) {
		for (int j = 1; j < game->ncols+1; j++) {
			scanf("%c", &game->mat[i][j]);
			if ((game->mat[i][j]) != 'x' && (game->mat[i][j]) != 'g' && (game->mat[i][j]) != 'r') {
				if (j > 0) {
					j--;
				} else {
					i--;
					j = game->ncols+1;
				}
			}	
		}
	}

	//Plays the game.
	for (int i = 0; i < iterations; i++) {
		//Fills in the upper and lower edge.
	        for (int j = 1; j < game->ncols+1; j++) {
			game->mat[0][j] = game->mat[game->nrows][j];
		        game->mat[game->nrows+1][j] = game->mat[1][j];
		}
		
		//Fills in the left and right edge.
		for (int i = 1; i < game->nrows+1; i++) {
			game->mat[i][0] = game->mat[i][game->ncols];
		        game->mat[i][game->ncols+1] = game->mat[i][1];
		}
		
		//Fills in the corners.
		game->mat[0][0] = game->mat[game->nrows][game->ncols];
		game->mat[game->nrows+1][game->ncols+1] = game->mat[1][1];
                game->mat[0][game->ncols+1] = game->mat[game->nrows][1];
		game->mat[game->nrows+1][0] = game->mat[1][game->ncols];

		//Updates the grid;
		game = update_board(game);
	}

	//Counts the number of green and red cells.
	int green = 0;
	int red = 0;
	
	for (int i = 1; i < game->nrows+1; i++) {
		for (int j = 1; j < game->ncols+1; j++) {
			if ((game->mat[i][j]) == 'g') {
				green++;
			} else if ((game->mat[i][j]) == 'r') {
				red++;
			}
		}
	}

	//Frees the memory
	free(game->grid);
	free(game->mat);
	free(game);

	//Outputs the score.
	printf("green: %d, red: %d\n", green, red);

	return 0;
}

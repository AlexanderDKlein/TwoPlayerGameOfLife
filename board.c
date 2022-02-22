#include <stdlib.h>
#include "board.h"

Board* update_board(Board *gameb) {
	//Creates a new board for simultaneous updating purposes.
	char *upgrd = (char *) malloc((gameb->nrows+2) * (gameb->ncols+2) * sizeof(char));
	char **upmat = (char **) malloc((gameb->nrows+2) * sizeof(char *));
	for (int i = 0; i < gameb->nrows+2; i++) {
		upmat[i] = upgrd + i * (gameb->ncols+2);
	}	

	//Updates the board.
	for (int i = 1; i < gameb->nrows+1; i++) {
		for (int j = 1; j < gameb->ncols+1; j++) {
			//Variables that see how many red and green there are.
			int green = 0;
			int red = 0;

			//Checks around the current cell.
			if (gameb->mat[i+1][j+1] == 'r') {
				red++;
			} else if (gameb->mat[i+1][j+1] == 'g') {
				green++;
			}

			if (gameb->mat[i-1][j-1] == 'r') {
				red++;
			} else if (gameb->mat[i-1][j-1] == 'g') {
				green++;
			}

			if (gameb->mat[i-1][j+1] == 'r') {
				red++;
			} else if (gameb->mat[i-1][j+1] == 'g') {
				green++;
			}
			
			if (gameb->mat[i+1][j-1] == 'r') {
				red++;
			} else if (gameb->mat[i+1][j-1] == 'g') {
				green++;
			}

			if (gameb->mat[i][j+1] == 'r') {
				red++;
			} else if (gameb->mat[i][j+1] == 'g') {
				green++;
			}

			if (gameb->mat[i][j-1] == 'r') {
				red++;
			} else if (gameb->mat[i][j-1] == 'g') {
				green++;
			}

			if (gameb->mat[i+1][j] == 'r') {
				red++;
			} else if (gameb->mat[i+1][j] == 'g') {
				green++;
			}

			if (gameb->mat[i-1][j] == 'r') {
				red++;
			} else if (gameb->mat[i-1][j] == 'g') {
				green++;
			}
			
			//Performs the logic of conway's game.
			int total = red + green;

			//Checks if the cell dies.
			if (gameb->mat[i][j] != 'x') {
				if (total >= 4 || total <= 1) {
					upmat[i][j] = 'x';
				} else {
					upmat[i][j] = gameb->mat[i][j];
				}
			} else {
				//Checks for cell birth.
				if (total == 3) {
					if (red > green) {
						upmat[i][j] = 'r';
					} else {
						upmat[i][j] = 'g';
					}
				} else {
					upmat[i][j] = gameb->mat[i][j];
				}
			}
		}
	}

	for (int i = 1; i < gameb->nrows+1; i++) {
		for (int j = 1; j < gameb->ncols+1; j++) {
			gameb->mat[i][j] = upmat[i][j];
		}
	}

	free(upmat);
	free(upgrd);
	
	return gameb;
}

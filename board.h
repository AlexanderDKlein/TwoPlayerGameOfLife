#ifndef BOARD_H
#define BOARD_H

typedef struct Board {
	char *grid;
	char **mat;
	int nrows;
	int ncols;
} Board;

#endif

#ifndef UPDATE_BOARD_H
#define UPDATE_BOARD_H

Board* update_board(Board *);

#endif

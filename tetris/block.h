#pragma once
#include "board.h"
#include <ctime>
#include <conio.h>


class block : public board {
private:
	int block_frame_size;
	static short t_block_[7][4][5][5];
	board board;
public:
	void init_members(const short x_max, const short y_max);
	bool paint_check(const short x, const short y, const short b, const short l);
	void paint_block(const short x, const short y, const short b, const short l);
	void block_insert(const short x, const short y, const short b, const short l);
	void clear_block(const short x, const short y, const short b, const short l);
	short get_x_max();
	void out_put();
	void remove_check();
	//void move_block();
	//void to_down();
};
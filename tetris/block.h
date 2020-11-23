#pragma once
#include "board.h"
#include "game_info.h"
#include <ctime>
#include <conio.h>

class block : public board {
private:
	board board__;
public:
	static short block_frame_size;
	static short t_block_[7][4][5][5];
	void init_members(const short x_max, const short y_max);
	bool paint_check(const short x, const short y, const short b, const short l);
	void paint_block(const short x, const short y, const short b, const short l, const short color);
	void paint_block(const short x, const short y, const short b, const short l, const int color);
	void predict_block(const short x, const short y, const short b, const short l, const short color);
	void clear_block(const short x, const short y, const short b, const short l);
	void key_input_check(short &x, short &y, short &b, short &l, short &predict_idx, const char ch, int &sleep_time, bool &stop_check, game_info language_mode, std::string &language);
	void floor_check(short& x, short& y, short& b, const short l, const int sleep_time, short& color, const short init_y, const short init_x, const char ch, game_info* language_mode);
	short get_x_max();
	void out_put();
	void remove_check();
	short get_block_frame_size();
};
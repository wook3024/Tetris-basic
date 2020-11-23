#pragma once
#include "util.h"


class board : public util {
private:
	int x_max;
	int y_max;
	short line_[100][100];
public:
	void init_members(short x_max, short y_max);
	void set_line(const short x, const short y, const short state);
	short get_line(const short x, const short y);
	short get_x_max();
	void out_put();
	void theme();
	void remove_check();
	std::string select_mode();
};

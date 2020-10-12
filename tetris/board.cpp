#include <iostream>
#include <Windows.h>
#include "board.h"


void board::init_members(short x_max, short y_max) {
	for (short i = 0; i < y_max; i++) {
		for (short j = 0; j < x_max; j++) {
			if (j == 0 || j == x_max - 1 || i == 0 || i == y_max - 1) {
				this->line_[i][j] = 1;
			}
			else {
				this->line_[i][j] = 0;
			}
		}
	}
	this->x_max = x_max;
	this->y_max = y_max;
}

void board::set_line(const short x, const short y, const short state) {
	this->line_[y][x] = state;
}

short board::get_line(const short x, const short y) {
	return this->line_[y][x];
}

short board::get_x_max() {
	return this->x_max;
}

void board::out_put() {
	for (auto j = 0; j < y_max; j++) {
		for (auto k = 0; k < x_max; k++)
			if (this->line_[j][k] == 1)
				std::cout << "в╠";
			else if (this->line_[j][k] == 2)
				std::cout << "бр";
			else if (this->line_[j][k] == 0)
				std::cout << "  ";
		std::cout << "\n";
	}
	theme();
}

void board::theme() {
	set_color(14, 0);
	goto_xy(45, 5);
	std::cout << "T E T R I S";
	goto_xy(40, 8);
	std::cout << "left: a";
	goto_xy(45, 10);
	std::cout << "falling: s";
	goto_xy(52, 8);
	std::cout << "right: d";
	goto_xy(45, 13);
	std::cout << "rotation: x";
	goto_xy(7, 0);
}


void board::remove_check() {
	for (auto y = 0; y < this->y_max; y++) {
		auto count = 0;
		for (auto x = 0; x < this->x_max; x++)
			if (this->line_[y][x] == 2)
				count++;
		if (count < this->x_max - 2)
			continue;
		goto_xy(2, y);
		for (auto x = 1; x < this->x_max - 1; x++) {
			this->line_[y][x] = 0;
			if (x >= this->x_max - 1)
				continue;
			std::cout << "  ";
			Sleep(30);
		}
	}
}


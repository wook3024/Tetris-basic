#include <iostream>
#include <Windows.h>
#include "board.h"
#include "block.h"

int score = 0;
int sleep_time = 100;


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
	this->set_color(15, 0);
	this->goto_xy(0, 0);
	for (auto j = 0; j < y_max; j++) {
		for (auto k = 0; k < x_max; k++)
			if (this->line_[j][k] == 1)
				std::cout << "в╠";
			else if (this->line_[j][k] >= 2)
				this->set_color(this->line_[j][k] + 6, 0), std::cout << "бс";
			else if (this->line_[j][k] == 0)
				std::cout << "  ";
		std::cout << "\n";
	}
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


std::string board::select_mode() {
	bool flag = false;
	std::string language;

	while (true) {
		this->set_color(15, 0);
		this->goto_xy(10, 3);
		std::cout << "Select language";
		this->goto_xy(10, 4);
		std::cout << "hangul or english :";
		this->goto_xy(10, 6);

		std::cin >> language;
		if (language != "hangul" && language != "english") { 
			this->set_color(13, 0);
			this->goto_xy(10, 5);
			std::cout << "invalid value!!";
			this->set_color(15, 0);
		} else {
			system("cls");
			break;
		}

		this->goto_xy(10, 6);
		std::cout << "                                                   ";
	}

	return language;
}


void board::remove_check() {
	for (auto y = 0; y < this->y_max; y++) {
		auto count = 0;
		for (auto x = 0; x < this->x_max; x++)
			if (this->line_[y][x] >= 2)
				count++;
		if (count < this->x_max - 2)
			continue;
		score += 200;
		goto_xy(2, y);
		for (auto x = 1; x < this->x_max - 1; x++) {
			this->line_[y][x] = 0;
			if (x >= this->x_max - 1)
				continue;
			std::cout << "  ";
			Sleep((200 - sleep_time) / 3);
		}
		for (auto move_y = y; move_y > 1; move_y--) {
			goto_xy(2, move_y);
			for (auto move_x = 1; move_x < this->x_max - 1; move_x++) {
				set_line(move_x, move_y, this->line_[move_y - 1][move_x]);
				short cur_state = get_line(move_x, move_y);
				if (cur_state == 0) {
					std::cout << "  ";
				}
				else if (cur_state >= 2) {
					this->set_color(cur_state, 0);
					std::cout << "бс";
				}
			}
		}

	}
}
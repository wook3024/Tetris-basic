#include "block.h"


short  block::t_block_[7][4][5][5] = {
		{
			{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},    //네모
			{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,1,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}
		},{
			{{1,1,1,1,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},    //직선
			{{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,0,0}},
			{{1,1,1,1,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,0,0}}
		},{
			{{1,0,0,0,0},{1,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},    //큐
			{{1,1,1,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{0,1,0,0,0},{1,1,0,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{0,1,0,0,0},{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}
		},{
			{{1,1,1,0,0},{0,0,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},    //기억
			{{0,1,0,0,0},{0,1,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,0,0,0,0},{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,1,0,0,0},{1,0,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}
		},{
			{{1,1,0,0,0},{0,1,0,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},    //기억
			{{0,0,1,0,0},{1,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,0,0,0,0},{1,0,0,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,1,1,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}
		},{
			{{0,1,1,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},    //지렁이
			{{1,0,0,0,0},{1,1,0,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{0,1,1,0,0},{1,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,0,0,0,0},{1,1,0,0,0},{0,1,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}
		},{
			{{1,1,0,0,0},{0,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},    //지렁이
			{{0,1,0,0,0},{1,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{1,1,0,0,0},{0,1,1,0,0},{0,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}},
			{{0,1,0,0,0},{1,1,0,0,0},{1,0,0,0,0},{0,0,0,0,0},{0,0,0,0,0}}
		}
};

short block::block::block_frame_size = 5;


void block::init_members(const short x_max, const short y_max) {
	this->board__.init_members(x_max, y_max);
}


bool block::paint_check(const short x, const short y, const short b, const short l) {
	for (short k = 0; k < block::block_frame_size; k++) {
		for (short u = 0; u < block::block_frame_size; u++) {
			if (block::t_block_[b][l][k][u]) {
				if (this->board__.get_line(x / 2 + u, y - k)) {
					return false;
				}
			}
		}
	}
	return true;
}


void block::paint_block(const short x, const short y, const short b, const short l, const short color) {
	for (short k = 0; k < block::block_frame_size; k++) {
		goto_xy(x, static_cast<short>(y - k));
		for (short u = 0; u < block::block_frame_size; u++) {
			short cur_state = this->board__.get_line(x / 2 + u, y - k);
			if (x / 2 + u >= this->board__.get_x_max()) {
				break;
			}
			else if (block::t_block_[b][l][k][u]) {
				this->set_color(color, 0);
				std::cout << "■";
			}
			else if (cur_state == 0) {
				std::cout << "  ";
			}
			else if (cur_state >= 2) {
				this->set_color(cur_state, 0);
				std::cout << "■";
			}
		}
	}
}


void block::predict_block(const short x, const short y, const short b, const short l, const short color) {
	for (short k = 0; k < block::block_frame_size; k++) {
		goto_xy(x, static_cast<short>(y - k));
		for (short u = 0; u < block::block_frame_size; u++) {
			short cur_state = this->board__.get_line(x / 2 + u, y - k);
			if (x / 2 + u >= this->board__.get_x_max()) {
				break;
			}
			else if (block::t_block_[b][l][k][u]) {
				this->set_color(15, 0);
				std::cout << "□";
			}
			else if (cur_state == 0) {
				std::cout << "  ";
			}
			else if (cur_state >= 2) {
				this->set_color(cur_state, 0);
				std::cout << "■";
			}
		}
	}
}


void block::paint_block(const short x, const short y, const short b, const short l, const int color) {
	for (short k = 0; k < block::block_frame_size; k++) {
		goto_xy(x, static_cast<short>(y - k));
		for (short u = 0; u < block::block_frame_size; u++) {
			short cur_state = this->board__.get_line((x) / 2 + u, y - k);
			if (x / 2 + u >= this->board__.get_x_max()) {
				break;
			} if (block::t_block_[b][l][k][u]) {
				this->set_color(color, 0);
				std::cout << "■";
				this->board__.set_line(x / 2 + u, y - k, color);
			}
			else if (cur_state >= 2) {
				this->set_color(cur_state, 0);
				std::cout << "■";
			} else if (cur_state == 0) {
				std::cout << "  ";
			}
		}
	}
}


void block::clear_block(const short x, const short y, const short b, const short l) {
	for (short k = 0; k < block::block_frame_size; k++) {
		goto_xy(x, static_cast<short>(y - k));
		for (short u = 0; u < block::block_frame_size; u++) {
			short cur_state = this->board__.get_line(x / 2 + u, y - k);
			if (x / 2 + u >= this->board__.get_x_max()) {
				break;
			}
			else if (block::t_block_[b][l][k][u]) {
				std::cout << "  ";
			}
			else if (cur_state == 0) {
				std::cout << "  ";
			}
			else if (cur_state >= 2) {
				this->set_color(cur_state, 0);
				std::cout << "■";
			}
		}
	}
}


void block::out_put() {
	this->board__.out_put();
}


short block::get_x_max() {
	return this->board__.get_x_max();
}


void block::remove_check() {
	this->board__.remove_check();
}


short block::get_block_frame_size() {
	return block::block_frame_size;
}


void block::key_input_check(short &x, short &y, short &b, short &l, short &predict_idx, const char ch, int &sleep_time, bool &stop_check, game_info language_mode, std::string &language) {
	switch (ch) {
	case 'a':
		if (this->paint_check(x - 2, y, b, l)) x -= 2;
		break;
	case 'd':
		if (this->paint_check(x + 2, y, b, l)) x += 2;
		break;
	case 's':
		while (this->paint_check(x, y++ + 1, b, l)) {}
		y--;
		break;
	case 'x':
		if (this->paint_check(x, y, b, (l + 1) % 4)) l = (l + 1) % 4;
		break;
	case '[':
		if (sleep_time <= 20)
			break;
		sleep_time -= 20;
		language_mode.print_cur_speed();
		break;
	case ']':
		if (sleep_time >= 180)
			break;
		sleep_time += 20;
		language_mode.print_cur_speed();
		break;
	case 'p':
		stop_check = stop_check ? false : true;
		break;
	// toggle language
	case 't':
		if (language == "hangul") {
			language = "english";
		} else if (language == "english") {
			language = "hangul";
		}
		break;
	case 'q':
		exit(0);
	default:
		break;
	}
}


void block::floor_check(short& x, short& y, short& b, const short l, const int sleep_time, short& color, const short init_y, const short init_x, const char ch, game_info* language_mode) {
	if (!this->paint_check(x, y + 1, b, l)) {
		if (y == init_y) {
			language_mode->print_game_over();
		}

		Sleep(200 - sleep_time);
		this->paint_block(x, y, b, l, static_cast<int>(color));
		srand(time(nullptr));
		this->remove_check();
		b = static_cast<int>(rand()) % 7;
		color = b + 6;
		this->set_color(color, 0);
		x = init_x, y = init_y;
		if (ch == 's')
			score += 50;
		language_mode->print_score();
	}
}
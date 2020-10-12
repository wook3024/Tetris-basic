#include "block.h"
#include "board.h"


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

void block::init_members(const short x_max, const short y_max) {
	this->board.init_members(x_max, y_max);
	this->block_frame_size = 5;
}

bool block::paint_check(const short x, const short y, const short b, const short l) {
	for (short k = 0; k < block_frame_size; k++) {
		for (short u = 0; u < block_frame_size; u++) {
			if (block::t_block_[b][l][k][u]) {
				if (this->board.get_line(x / 2 + u, y - k)) {
					return false;
				}
			}
		}
	}
	return true;
}

void block::paint_block(const short x, const short y, const short b, const short l) {
	for (short k = 0; k < block_frame_size; k++) {
		goto_xy(x, static_cast<short>(y - k));
		for (short u = 0; u < block_frame_size; u++) {
			if (x / 2 + u >= this->board.get_x_max()) {
				break;
			}
			else if (block::t_block_[b][l][k][u]) {
				std::cout << "■";
			}
			else if (this->board.get_line(x / 2 + u, y - k) == 0) {
				std::cout << "  ";
			}
			else if (this->board.get_line(x / 2 + u, y - k) == 2) {
				std::cout << "□";
			}
		}
	}
}

void block::block_insert(const short x, const short y, const short b, const short l) {
	for (short k = 0; k < block_frame_size; k++) {
		goto_xy(x, static_cast<short>(y - k));
		for (short u = 0; u < block_frame_size; u++) {
			if (x / 2 + u >= this->board.get_x_max()) {
				break;
			} if (block::t_block_[b][l][k][u] || this->board.get_line((x) / 2 + u, y - k) == 2) {
				std::cout << "□";
				this->board.set_line(x / 2 + u, y - k, 2);
			}
			else if (this->board.get_line(x / 2 + u, y - k) == 0) {
				std::cout << "  ";
			}
		}
	}
}

void block::clear_block(const short x, const short y, const short b, const short l) {
	for (short k = 0; k < block_frame_size; k++) {
		goto_xy(x, static_cast<short>(y - k));
		for (short u = 0; u < block_frame_size; u++) {
			if (x / 2 + u >= this->board.get_x_max()) {
				break;
			}
			else if (block::t_block_[b][l][k][u]) {
				std::cout << "  ";
			}
			else if (this->board.get_line(x / 2 + u, y - k) == 0) {
				std::cout << "  ";
			}
			else if (this->board.get_line(x / 2 + u, y - k) == 2) {
				std::cout << "□";
			}
		}
	}
}

void block::out_put() {
	this->board.out_put();
}

short block::get_x_max() {
	return this->board.get_x_max();
}
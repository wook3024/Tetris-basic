#include "board.h"
#include "block.h"
//#include "util.h"

/*
전역변수 x
block에서 board 사용
클래스만 재사용가능하도록
*/

int main() {
	board board;
	block block;
	block.init_members(13, 23);
	short init_x = block.get_x_max() - 1, init_y = 5;

	block.out_put();
	block.CursorView(0);

	char ch;
	short x = init_x, y = init_y;
	auto b = 4, l = 0;
	block.paint_block(x, y, b, l);
	while (true) {
		ch = '0';
		if (_kbhit())
			ch = static_cast<char>(_getch());

		switch (ch) {
		case 'a':
			if (block.paint_check(x - 2, y, b, l)) x -= 2;
			break;
		case 'd':
			if (block.paint_check(x + 2, y, b, l)) x += 2;
			break;
		case 's':
			while (block.paint_check(x, y++ + 1, b, l)) {}
			y--;
			break;
		case 'x':
			if (block.paint_check(x, y, b, (l + 1) % 4)) l = (l + 1) % 4;
			break;
		case 'q':
			exit(0);
		default:
			break;
		}

		block.paint_block(x, y, b, l);

		if (!block.paint_check(x, y + 1, b, l)) {
			Sleep(300);
			block.block_insert(x, y, b, l);
			srand(time(nullptr));
			//block.remove_check();
			b = static_cast<int>(rand()) % 7;
			x = init_x, y = init_y;
		}

		Sleep(100);
		block.clear_block(x, y, b, l);
		y++;
	}
	
	return 0;
}
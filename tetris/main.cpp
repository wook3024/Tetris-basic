#include "board.h"
#include "block.h"


void run() {
	block block;
	block.init_members(13, 23);

	game_info *language_mode;
	std::string language;
	language = block.select_mode();
	if (language == "hangul") {
		hangul_mode hangul_mode;
		language_mode = &hangul_mode;
	} else if (language == "english") {
		english_mode english_mode;
		language_mode = &english_mode;
	}
	language_mode->print_key_sheet(0);

	block.out_put();
	block.CursorView(0);

	extern int score;
	char ch;
	extern int sleep_time;
	bool stop_check = false;
	short init_x = block.get_x_max() - 1, init_y = 5;
	short x = init_x, y = init_y;
	short b = 4, l = 0;
	short color = b + 6;
	short predict_idx = y;
	short pre_x, pre_y, pre_l, pre_idx;
	std::string cur_language = language;

	block.paint_block(x, y, b, l, color);
	block.set_color(color, 0);
	language_mode->print_score();
	while (true) {
		for (int i = 0; i < 10; i++) {
			ch = '0';

			pre_x = x;
			pre_y = y;
			pre_l = l;
			pre_idx = predict_idx;

			if (_kbhit())
				ch = static_cast<char>(_getch());

			// switch case
			block.key_input_check(x, y, b, l, predict_idx, ch, sleep_time, stop_check, *language_mode, language);
			if (cur_language != language) {
				if (language == "hangul") {
					hangul_mode hangul_mode;
					language_mode = &hangul_mode;
				}
				else if (language == "english") {
					english_mode english_mode;
					language_mode = &english_mode;
				}
				language_mode->print_clear();
				language_mode->print_key_sheet(score);
				/*language_mode->print_score();
				language_mode->print_cur_speed();*/
				cur_language = language;
			}

			if (ch != '0') {
				block.clear_block(pre_x, pre_y, b, pre_l);
				block.clear_block(pre_x, pre_idx, b, pre_l);
			}

			// arrive floor
			block.floor_check(x, y, b, l, sleep_time, color, init_y, init_x, ch, language_mode);

			if (ch != '0' || i == 0) {
				predict_idx = y;
				while (block.paint_check(x, predict_idx + 1, b, l)) { predict_idx++; }
			}
			if (predict_idx != y) {
				block.predict_block(x, predict_idx, b, l, static_cast<short>(color));
			}
			block.paint_block(x, y, b, l, color);

			Sleep(200 - sleep_time);
		}

		if (!stop_check) {
			y++;
		}
	}
}


int main() {
	run();
	return 0;
}
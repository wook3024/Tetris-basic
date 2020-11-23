#include "game_info.h"

extern int sleep_time;

void game_info::print_key_sheet(int score) {}
void game_info::print_score() {}
void game_info::print_game_over() {}
void game_info::print_cur_speed() {}


void game_info::print_clear() {
	this->goto_xy(50, 3);
	std::cout << "                                     ";
	this->set_color(7, 0);
	this->goto_xy(50, 5);
	std::cout << "                                     ";
	this->goto_xy(50, 8);
	std::cout << "                                     ";
	this->goto_xy(50, 11);
	std::cout << "                                     ";
	this->goto_xy(50, 14);
	std::cout << "                                     ";
	this->goto_xy(50, 17);
	std::cout << "                                     ";
	this->goto_xy(50, 20);
	this->set_color(12, 0);
	std::cout << "                                     ";
}

void english_mode::print_key_sheet(int score) {
	this->set_color(14, 0);
	this->goto_xy(50, 3);
	std::cout << "score : " << score << "        ";
	this->set_color(7, 0);
	this->goto_xy(50, 5);
	std::cout << "T E T R I S";
	this->goto_xy(50, 8);
	std::cout << "left[a]  *  right[d]";
	this->goto_xy(50, 11);
	std::cout << "falling[s]  *  rotation[x]";
	this->goto_xy(50, 14);
	std::cout << "start or stop[p]";
	this->goto_xy(50, 17);
	std::cout << "speed_up[]]  *  speed_down[[]";
	this->goto_xy(50, 20);
	this->set_color(12, 0);
	std::cout << "current_speed: " << (sleep_time / 20) << "       ";
}

void english_mode::print_score() {
	this->set_color(14, 0);
	this->goto_xy(50, 3);
	std::cout << "score : " << score << "        ";
}

void english_mode::print_game_over() {
	this->goto_xy(50, 3);
	this->set_color(15, 7);
	std::cout << "final score : " << score;
	this->set_color(0, 0);
	this->goto_xy(0, 23);
	exit(0);
}

void english_mode::print_cur_speed() {
	this->goto_xy(50, 20);
	this->set_color(12, 0);
	std::cout << "current_speed: " << (sleep_time / 20) << "       ";
}

void hangul_mode::print_key_sheet(int score) {
	this->set_color(14, 0);
	this->goto_xy(50, 3);
	std::cout << "점수 : " << score << "        ";
	this->set_color(7, 0);
	this->goto_xy(50, 5);
	std::cout << "테트리스";
	this->goto_xy(50, 8);
	std::cout << "왼쪽[a]  *  오른쪽[d]";
	this->goto_xy(50, 11);
	std::cout << "강하[s]  *  회전[x]";
	this->goto_xy(50, 14);
	std::cout << "시작, 정지[p]";
	this->goto_xy(50, 17);
	std::cout << "속도 증가[]]  *  속도 감소[[]";
	this->goto_xy(50, 20);
	this->set_color(12, 0);
	std::cout << "현재 속도: " << (sleep_time / 20) << "       ";
}

void hangul_mode::print_score() {
	this->set_color(14, 0);
	this->goto_xy(50, 3);
	std::cout << "점수 : " << score << "        ";
}

void hangul_mode::print_game_over() {
	this->goto_xy(50, 3);
	this->set_color(15, 7);
	std::cout << "최종 점수 : " << score;
	this->set_color(0, 0);
	this->goto_xy(0, 23);
	exit(0);
}

void hangul_mode::print_cur_speed() {
	this->goto_xy(50, 20);
	this->set_color(12, 0);
	std::cout << "현재 속도: " << (sleep_time / 20) << "       ";
}
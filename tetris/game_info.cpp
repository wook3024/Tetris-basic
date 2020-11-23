#include "game_info.h"

extern int sleep_time;

void game_info::print_key_sheet(int score) {}
void game_info::print_score() {}
void game_info::print_game_over() {}
void game_info::print_cur_speed() {}


void game_info::print_clear() {
	this->goto_xy(50, 2);
	std::cout << "                                     ";
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
	std::cout << "                                     ";
}

void english_mode::print_key_sheet(int score) {
	this->set_color(14, 0);
	this->goto_xy(50, 2);
	std::cout << "score : " << score << "        ";
	this->set_color(7, 0);
	this->goto_xy(50, 5);
	std::cout << "tetris";
	this->goto_xy(50, 8);
	std::cout << "left[A]  *  right[D]";
	this->goto_xy(50, 11);
	std::cout << "falling[S]  *  rotation[X]";
	this->goto_xy(50, 14);
	std::cout << "start or stop[P]";
	this->goto_xy(50, 17);
	std::cout << "speed_up[]]  *  speed_down[[]";
	this->goto_xy(50, 20);
	std::cout << "languge change[T]";
	this->goto_xy(50, 23);
	this->set_color(12, 0);
	std::cout << "current_speed: " << (sleep_time / 20) << "       ";
}

void english_mode::print_score() {
	this->set_color(14, 0);
	this->goto_xy(50, 2);
	std::cout << "score : " << score << "        ";
}

void english_mode::print_game_over() {
	this->goto_xy(50, 2);
	this->set_color(15, 7);
	std::cout << "final score : " << score;
	this->set_color(0, 0);
	this->goto_xy(0, 23);
	exit(0);
}

void english_mode::print_cur_speed() {
	this->goto_xy(50, 23);
	this->set_color(12, 0);
	std::cout << "current_speed: " << (sleep_time / 20) << "       ";
}

void hangul_mode::print_key_sheet(int score) {
	this->set_color(14, 0);
	this->goto_xy(50, 2);
	std::cout << "점수 : " << score << "        ";
	this->set_color(7, 0);
	this->goto_xy(50, 5);
	std::cout << "테트리스";
	this->goto_xy(50, 8);
	std::cout << "왼쪽[A]  *  오른쪽[D]";
	this->goto_xy(50, 11);
	std::cout << "강하[S]  *  회전[X]";
	this->goto_xy(50, 14);
	std::cout << "시작, 정지[P]";
	this->goto_xy(50, 17);
	std::cout << "속도 증가[]]  *  속도 감소[[]";
	this->goto_xy(50, 20);
	std::cout << "언어 변경[T]";
	this->goto_xy(50, 23);
	this->set_color(12, 0);
	std::cout << "현재 속도: " << (sleep_time / 20) << "       ";
}

void hangul_mode::print_score() {
	this->set_color(14, 0);
	this->goto_xy(50, 2);
	std::cout << "점수 : " << score << "        ";
}

void hangul_mode::print_game_over() {
	this->goto_xy(50, 2);
	this->set_color(10, 7);
	std::cout << "최종 점수 : " << score;
	this->set_color(0, 0);
	this->goto_xy(0, 23);
	exit(0);
}

void hangul_mode::print_cur_speed() {
	this->goto_xy(50, 23);
	this->set_color(12, 0);
	std::cout << "현재 속도: " << (sleep_time / 20) << "       ";
}
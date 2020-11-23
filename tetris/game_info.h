#include "util.h"

extern int score;


class game_info : public util {
private:
public:
	virtual void print_key_sheet(int score);
	virtual void print_score();
	virtual void print_game_over();
	virtual void print_cur_speed();
	void print_clear();
};


class english_mode : public game_info {
private:
public:
	void print_key_sheet(int score);
	void print_score();
	void print_game_over();
	void print_cur_speed();
};


class hangul_mode: public game_info {
private:
public:
	void print_key_sheet(int score);
	void print_score();
	void print_game_over();
	void print_cur_speed();
};
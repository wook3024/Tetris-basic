#pragma once
#include <iostream>
#include <Windows.h>
#include <string>


class util {
private:
public:
	void goto_xy(const short x, const short y);
	void set_color(const unsigned short text, const unsigned short back);
	void CursorView(char show);
};
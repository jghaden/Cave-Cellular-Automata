#pragma once

#include "PCH.h"

void gotoXY(int x, int y);

template<typename T>
inline void WriteAt(int x, int y, T data)
{
	gotoXY(x, y);
	std::cout << data;
}

void ClearScreen();
void ShowConsoleCursor(bool showFlag);

void SetWindowSize(int w, int h);
void SetFontSize(int w, int h);
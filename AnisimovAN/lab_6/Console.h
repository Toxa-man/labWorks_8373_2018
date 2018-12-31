#ifndef CONSOL_H
#define CONSOL_H
#pragma once

const int map_size_width = 22;
const int map_size_height = 21;

class Console
{
public:
	Console();
	~Console();

	void move(int V, int H);
};

extern char map[map_size_height][map_size_width];
extern int x;
extern int y;
extern int hp;
extern int score;
extern int heal;

#endif

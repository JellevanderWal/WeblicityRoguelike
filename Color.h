#pragma once

#define BLACK Color(0, 0, 0)
#define WHITE Color(255, 255, 255)
#define BLUE Color(0, 0, 255)
#define RED Color(255, 0, 0)
#define GREEN Color(0, 255, 0)

struct Color {
	unsigned char r;
	unsigned char g;
	unsigned char b;
	unsigned char a;

	Color() : r(255), g(255), b(255), a(255) {};
	Color(int r, int g, int b) : r(r), g(g), b(b), a(255) {};
	Color(int r, int g, int b, int a) : r(r), g(g), b(b), a(a) {};
};
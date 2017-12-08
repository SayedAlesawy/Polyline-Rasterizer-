#pragma once
#include<fstream>
using namespace std;

class Color
{
	private:
		unsigned int R, G, B;
	public:
		Color(unsigned int r, unsigned int g, unsigned int b);
		friend ofstream& operator<< (std::ofstream &out, const Color &color);
};
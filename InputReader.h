#pragma once
#include<vector>
#include<utility>
#include<string> 
#include<fstream>
#include<sstream>
#include <algorithm> 
#include <cctype>
#include <locale>

using namespace std;

class InputReader
{
	private:
		vector<vector<pair<long double, long double>>> m_Ploylines;
		void TrimString(string& str);

	public:
		InputReader();
		void ParseFile(string FileName);
		vector<vector<pair<long double, long double>>> GetPloylines();
		~InputReader();
};
#include "InputReader.h"

InputReader::InputReader()
{
	//Empty constructor
}

void InputReader::TrimString(string& s)
{
	s.erase(s.begin(), find_if(s.begin(), s.end(), [](int ch) {return !isspace(ch);}));
	s.erase(find_if(s.rbegin(), s.rend(), [](int ch) {return !isspace(ch);}).base(), s.end());
}

void InputReader::ParseFile(string FileName)
{
	ifstream InputFile;
	InputFile.open(FileName, ios::in);

	vector<pair<long double, long double>>Shape;
	string input; long double x, y;

	while (getline(InputFile, input)){
		TrimString(input);

		if (input.empty() && !Shape.empty()) {
			m_Ploylines.push_back(Shape);
			Shape.clear();
			continue;
		}
		if (input == "polyline") continue;
		else {
			stringstream ss(input);
			ss >> x; ss >> y;
			Shape.push_back(make_pair(x, y));
		}
	}

	InputFile.close();
}

vector<vector<pair<long double, long double>>> InputReader::GetPloylines()
{
	return m_Ploylines;
}

InputReader::~InputReader()
{
	//Empty destructor
}
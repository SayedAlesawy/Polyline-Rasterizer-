#pragma once
#include<string> 
#include<fstream>
#include"Color.h"
#include<vector>
using namespace std;

class ImageGenerator
{
	private:
		string m_OutputFile, m_mode;
		int m_Xres, m_Yres, m_MaxIntensity;

	public:
		ImageGenerator(string OutputFile, string mode, int Xres, int Yres, int MaxIntensity);
		void OutputImage(vector<Color>Image);
		void ConfigureImage();
};
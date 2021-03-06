#pragma once
#include<vector>
#include<utility>
#include<cmath>
#include "Color.h"

using namespace std;

class Rasterizer
{
	private:
		double Xmin, Xmax, Ymin, Ymax; int Xres, Yres;
		vector<Color>m_FinalOutput;
		vector<pair<long double, long double>> m_InputPolyline;
		vector<pair<long double, long double>> m_ConvertedPolyline;
		void ConvertToPixels();
		vector<vector<bool>> m_Image;
		void RasterizeLine(int x0, int y0, int x1, int x2);
		
	public:
		Rasterizer(double xmin, double ymin, double xmax, double ymax, int xres, int yres);
		void RasterizePolyline();
		void SetPolyline(vector<pair<long double, long double>> InputPolyline);
		void ColorizePolyline();
		vector<Color>GetFinalImage();
		~Rasterizer();
};
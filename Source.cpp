#include<iostream>
#include<sstream>
#include<vector>
#include<utility>
#include"InputReader.h"
#include"Rasterizer.h"
#include"ImageGenerator.h"

using namespace std;

int main(int argc, char** argv)
{
	InputReader reader; string IOFile = argv[7];
	reader.ParseFile(IOFile + ".2d");
	vector<vector<pair<long double, long double>>> Polylines = reader.GetPloylines();

	double params[6];
	for (int i = 1; i < argc; i++) {
		stringstream ss(argv[i]);
		ss >> params[i - 1];
	}

	ImageGenerator image_generator(IOFile + ".ppm", "P3", params[4], params[5], 255);
	Rasterizer rasterizer(params[0], params[1], params[2], params[3], params[4], params[5]);

	for (int i = 0; i < Polylines.size(); i++) {
		rasterizer.SetPolyline(Polylines[i]);
		rasterizer.RasterizePolyline();
	}

	rasterizer.ColorizePolyline();
	image_generator.OutputImage(rasterizer.GetFinalImage());
}
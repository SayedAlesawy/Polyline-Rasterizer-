#include"Rasterizer.h"

Rasterizer::Rasterizer(int xmin, int ymin, int xmax, int ymax, int xres, int yres)
{
	Xmin = xmin; Ymin = ymin; Xmax = xmax; Ymax = ymax; Xres = xres; Yres = yres;
	m_Image.resize(Xres);
	for (int i = 0; i < m_Image.size(); i++) m_Image[i].resize(Yres,0);
}

void Rasterizer::SetPolyline(vector<pair<long double, long double>> InputPolyline)
{
	m_InputPolyline = InputPolyline;
}

void Rasterizer::ConvertToPixels()
{
	m_ConvertedPolyline.resize(m_InputPolyline.size());

	for (int i = 0; i < m_InputPolyline.size(); i++) {

		long double xRaw = m_InputPolyline[i].first, yRaw = m_InputPolyline[i].second;
		long double xConverted = floor(((long double)(xRaw - Xmin) / (long double)(Xmax - Xmin))*(Xres - 0.5));
		long double yConverted = floor(((long double)(yRaw - Ymin) / (long double)(Ymax - Ymin))*(Yres - 0.5));

		m_ConvertedPolyline[i] = make_pair(xConverted, yConverted);
	}
}

void Rasterizer::RasterizeLine(int x0, int y0, int x1, int y1)
{
	int dx = abs(x1 - x0), dy = abs(y1 - y0), p, inc1, inc2, xstep, ystep;
	long double m = (long double)dy / (long double)dx;

	xstep = x1 > x0 ? 1 : -1;
	ystep = y1 > y0 ? 1 : -1;

	if (m < 1) {
		p = 2 * dy - dx, inc1 = 2 * dy, inc2 = 2 * dy - 2 * dx;
		
		m_Image[y0][x0] = 1;

		while (x0 != x1) {
			if (p < 0) x0 += xstep, p += inc1;
			else x0 += xstep, y0 += ystep, p += inc2;
			m_Image[y0][x0] = 1;
		}
	}
	else {
		p = 2 * dx - dy, inc1 = 2 * dx, inc2 = 2 * dx - 2 * dy;
		
		m_Image[y0][x0] = 1;

		while (y0 != y1) {
			if (p < 0) y0 += ystep, p += inc1;
			else x0 += xstep, y0 += ystep, p += inc2;
			m_Image[y0][x0] = 1;
		}
	}
}

void Rasterizer::RasterizePolyline()
{
	ConvertToPixels();

	for (int i = 0; i < m_ConvertedPolyline.size()-1; i++) {
		int x0 = m_ConvertedPolyline[i].first, y0 = m_ConvertedPolyline[i].second;
		int x1 = m_ConvertedPolyline[i+1].first, y1 = m_ConvertedPolyline[i+1].second;

		RasterizeLine(x0, y0, x1, y1);
	}
}

void Rasterizer::ColorizePolyline()
{
	for (int i = 0; i < m_Image.size(); i++) {
		for (int j = 0; j < m_Image[i].size(); j++) {
			if (m_Image[i][j]) m_FinalOutput.push_back(Color(255, 255, 255));
			else m_FinalOutput.push_back(Color(0, 0, 0));
		}
	}
}

vector<Color> Rasterizer::GetFinalImage()
{
	return m_FinalOutput;
}

Rasterizer::~Rasterizer()
{
	//Empty destructor
}
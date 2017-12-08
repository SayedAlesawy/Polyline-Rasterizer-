#include"ImageGenerator.h"

ImageGenerator::ImageGenerator(string OutputFile, string mode, int Xres, int Yres, int MaxIntensity)
{
	m_OutputFile = OutputFile;
	m_Xres = Xres, m_Yres = Yres, m_MaxIntensity = MaxIntensity, m_mode = mode;

	ConfigureImage();
}

void ImageGenerator::ConfigureImage()
{
	ofstream OutputFile;
	OutputFile.open(m_OutputFile, ios::out);

	OutputFile << m_mode << endl;
	OutputFile << m_Xres << "  " << m_Yres << endl;
	OutputFile << m_MaxIntensity << endl;
}

void ImageGenerator::OutputImage(vector<Color>Image)
{
	ofstream OutputFile;
	OutputFile.open(m_OutputFile, ios::app);

	for (int i = 0; i < Image.size(); i++) {
		OutputFile << Image[i] << endl;
	}

	OutputFile.close();
}
#include <fstream>
#include <chrono>
#include <ctime>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <sstream>
#include <numeric>
#include <thread>


const auto imageHeight = 512;
const auto imageWidth = 512;
const auto maxN = 256;
const auto minR = -1.5;
const auto maxI = 1.0;
const auto maxR = 0.5;
const auto minI = -1.0;
const double SERIAL_AVERAGE = 2.151;
static std::stringstream image;
static int timesRan = 0;
static std::vector<decltype(std::chrono::steady_clock::duration())> times;


struct color
{
	int red;
	int green;
	int blue;
};

static std::vector<color> c1;

double mapToReal(int x, int imageWidth, double minR, double maxR) {
	double range = maxR - minR;
	return x * (range / imageWidth) + minR;
}

double mapToImaginary(int y, int imageHeight, double minI, double maxI) {
	double range = maxI - minI;
	return y * (range / imageHeight) + minI;
}

int findMandelbrot(double cr, double ci, int max_iterations) {
	int i = 0;
	double zr = 0.0, zi = 0.0;
	while (i < max_iterations && zr *zr + zi * zi < 4.00) {
		double temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	return i;
}

//code to be used for our project
void writeMandelbrotRegular() {
	std::ofstream fout("output_image.ppm");
	image << "P3" << std::endl;
	image << imageWidth << " " << imageHeight << std::endl;
	image << maxN << std::endl;

	for (int i = 0; i < imageHeight; i++) {
		for (int j = 0; j < imageWidth; j++) {
			double cr = mapToReal(i, imageWidth, minR, maxR);
			double ci = mapToImaginary(j, imageHeight, minI, maxI);

			int n = findMandelbrot(cr, ci, maxN);

			int r = n * n % 256;
			int g = n * n % 256;
			int b = n * n % 256;

			image << r << " " << g << " " << b << " ";

		}
		image << std::endl;
	}

	fout << image.rdbuf();
	fout.close();

}

void timeFunction() {
	auto start = std::chrono::steady_clock::now();

	writeMandelbrotRegular();

	auto end = std::chrono::steady_clock::now();
	auto time = end - start;
	timesRan++;
	times.push_back(time);
}

void regularStrategy() {
	timeFunction();

	std::cout << "Finished! Time taken:" << std::chrono::nanoseconds(times[0]).count() << " nanoseconds" << std::endl;
}

int main()
{
	regularStrategy();

	return 0;
}
#include <iostream>
#include <vector>
#include <cmath> 
#include <fstream>

using namespace std;

double function(int i, double t, double f, double T, int q, double A) {
	double pi = 3.14;
	int i1 = i / sqrt(q);
	int i2 = i % (int)sqrt(q);
	double si1 = A * (1 - 2 * i1 / (sqrt(q) - 1));
	double si2 = A * (1 - 2 * i2 / (sqrt(q) - 1));
	double res = (si1*sqrt(2/T) * cos(2 * pi * f * t)) + (si2 * sqrt(2/T) * sin(2 * pi * f * t));
	return res;
}

int main() {
	int q = 16;
	double T = 1.0 / 600.0;
	double dt = T / 1000.0;
	int f = 2400;
	double A = 1;
	ofstream out("in.txt");

	vector<vector<double>> arr(q);
	for (auto i = 0; i < q; ++i) {
		arr[i].resize(1000);
	}
	for (int i = 0; i < q; i++)
	{
		int j = 0;
		for (double t = 0, j = 0; t < T; t += dt, j++)
		{
			arr[i][j] = function(i, t, f, T, q, A);
		}
	}

	for (auto j = 0; j < arr[0].size(); ++j) {
		out << dt * j << ' ';
		for (auto i = 0; i < arr.size(); ++i) {
			out << arr[i][j] << ' ';
		}
		out << endl;
	}
	out.close();
}
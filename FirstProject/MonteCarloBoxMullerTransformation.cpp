#include<iostream>
#include<cmath>
#include<ctime>
#include<fstream>

using namespace std;

#include "BoxMullerTransformation.h";

void static MonteCarloBoxMullerTransformation() {
	srand((unsigned)time(NULL));
	// Seed the random number generator with the current time
	//
	// srand(...)              ? Sets the starting point (seed) for rand()
	// (unsigned)              ? Casts the result of time() to an unsigned int
	// time(NULL)              ? Gets the current calendar time in seconds since Jan 1, 1970 (Unix Epoch)
	//                         ? NULL means we are not storing the time in a variable, just getting the current time
	//
	// Overall:
	// This line ensures the rand() function will generate different sequences of pseudo-random numbers
	// on each program run, depending on the current time.
	//
	// Without this, rand() would produce the same sequence every time you run the program.

	ofstream print;

	print.open("results_MC_BMT.xls");

	long N = 1000;

	double
		asset = 100,
		IR = 0.05,
		vol = 0.2;

	double dt = 1.0 / N;

	print << 0 << '\t' << asset << endl;

	for (unsigned short int i = 1; i <= N; i++) {
		double time = i* dt;
		double phi = BoxMullerTransformation(1.0, 0.0);
		double dX = phi * sqrt(dt);
		double dS = asset * (IR * dt + vol * dX);
		asset += dS;

		print << time << '\t' << asset << endl;
	}

	print.close();

	cout << "Monte Carlo simulation is complete. Please check the output file! " << endl;

}
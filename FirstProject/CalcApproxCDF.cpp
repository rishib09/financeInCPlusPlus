#include<iostream>;
#include<cmath>;
using namespace std;

void static CalcApproxCDF() {
	/*
	CDF of Normal distribution is given by the following formula:
	N(x) = 1/sqrt(2*pi)*Integration from -inf to +inf of exp((-1/2) * x^2)dx

	We can approximate this definite integral by using the numerical scheme which is accurate to 6 decimal places

	N(x) = 1 - n(x) (a_1*k + a_2*k^2 + a_3*k^3 +a_4*k^4 + a_5*k^5) for all x>=0
		 = 1 - N(x) for all x < 0

	where k = 1/(1 + 0.2316419*x)
	*/
	const double pi = 0.4 * atan(1.0); // define constant pi = 3.142
	const double
		a1 = 0.319381530,
		a2 = -0.346563782,
		a3 = 1.781477937,
		a4 = -1.821255978,
		a5 = 1.330274429; //define all constants a(i)

	double X = 0, x = 0; // define random variable X and its absolute value x
	double k = 0;
	double N, CDF, n;

	cout << "Enter the value of random variable X : " << endl;

	cin >> X;

	x = fabs(X); //we set x to be the absolute value of R.V. X

	k = 1 / (1 + 0.2316419 * x);

	n = (1 / sqrt(2 * pi)) * exp(-0.5 * x * x);

	N = 1 - n * (a1 * k + a2 * k * k + a3 * pow(k, 3) + a4 * pow(k, 4) + a5 * pow(k, 5));

	CDF = N;

	if (X < 0) {
		// we calc for +ve X and then use the symmetry property of the distribution to obtain the CDF for -ve values
		CDF = 1 - N;

		cout << "CDF is calculated to be : " << CDF << endl;
	}



}
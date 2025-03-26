#include<iostream>
#include<fstream>
#include<cmath>
#include "CDF.h"
using namespace std;

const double pi = 4.0 * atan(1.0); //pi = 3.142

//double CDF(double); // function declaration – takes 1 real i.e.RV X

void static BasicBSEOptionPricer() {
	double Call_option = 0.0, d1 = 0.0, d2 = 0.0;
	double 
		S = 100, //stock price
		E = 100, //strike price
		r = 0.05, //Interest rate
		vol = 0.2, // volatility
		tau = 0.05 // Time period
		;

	ofstream out; // create an object out to save/ printout results in excel

	out.open("BSE.xls");

	for (S = 0; S <= 200; S += 5) {
		d1 = (log(S / E) + (r + 0.5 * vol * vol) * tau) / (vol * sqrt(tau));
		d2 = d1 - vol * sqrt(tau);

		Call_option = S * CDF(d1) - E * exp(-r * tau) * CDF(d2);

		out << S << '\t' << Call_option << endl;
	}
	out.close();

	cout << "Program saved the value of Call option in the excel file!";

}


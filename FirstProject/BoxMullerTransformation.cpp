#include<cmath>

double BoxMullerTransformation(double std, double mean) {
	/*
	
	A transformation which transforms from a two-dimensional continuous uniform distribution to a two-dimensional bivariate normal distribution (or complex normal distribution).
	If x_1 and x_2 are uniformly and independently distributed between 0 and 1, then z_1 and z_2 as defined below have a normal distribution with mean mu=0 and variance sigma^2=1.

	This transformation is analytically derived and computationally efficient, especially when vectorized

	Many models in quantitative finance (like Black-Scholes, risk metrics, and stochastic differential equations) assume returns or other variables follow a normal distribution. 
	However, most programming environments only provide uniform random number generators. Box-Muller bridges this gap.

	*/

	static int iset = 0;
	static double gset = 0.0;
	double fac = 0.0, r = 0.0, v1 = 0.0, v2 = 0.0;

	if (iset == 0) {
		r = 0;
		do {
			v1 = 2.0 * rand() / RAND_MAX - 1.0;
			v2 = 2.0 * rand() / RAND_MAX - 1.0;

			r = v1 * v1 + v2 * v2; //compute radius

		} while (r >= 1.0 || r == 0.0); //keep computing for v1 and v2 untill radius falls in the unit circle
		
		//box muller transformation
		fac = sqrt((-2 * log(r)) / r);
		gset = (v1 * fac);
		iset = 1;
		v2 = v2 * fac * std + mean;
		return v2;
		
	}
	else {
		iset = 0;
		return (gset * std) + mean;
	}

}
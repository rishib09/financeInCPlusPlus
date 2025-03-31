#include <iostream>
#include<cmath>

using namespace std;
#include "BasicMeanStdCalcUtil.h";

const unsigned int MAX = 100;

void static BasicMeanStdCalc() {

	int size;
	double a[MAX];

	fill_up(a, size);
	display(a, size);
	double mean = average(a, size);
	stan_dev(a, size, mean);

}
	/*double A[MAX] = { 0.0 };
	double average = 0.0, ans=0.0, st_dev=0.0;
	int i=0, N=0;
	
	cout << "Enter the number of values (up to 10) for which you wish to calculate " << endl;
	cout << " the standard deviation" << endl;
	cin >> N;

	cout << "Enter the " << N << " values seperated by return after each \n";

	for (i = 1; i <= N;i++) {
		cin >> A[i - 1];
	}

	for (i = 1; i < N;i++) {
		average += A[i - 1] / N;
	}
	cout << "average: " << average << endl;

	for (i = 1; i <= N; i++) {
		ans += ((A[i - 1] - average) * (A[i - 1] - average));
	}

	st_dev = sqrt(ans / double(N));

	cout << "Standard Deviation : " << st_dev << endl;
}*/


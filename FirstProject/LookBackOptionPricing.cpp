#include<iostream>
#include<algorithm>
#include "max_min.h";

using namespace std;

void static LookBackOptionPricing() {
	int A[dimen] = { 5,67,2098,3,23,43,98,12,3,12 };
	cout << "The largest element is " << Maximum(A) << endl;
	cout << "The smallest element is " << Minimum(A) << endl;
}
#include<iostream>
using namespace std;

#include "findQuadRoots.cpp";
#include "CalcApproxCDF.cpp";

int main() {

	string func = "";
	cout << "Please enter the following command to run a specific function : " << endl;
	cout << "==============================================" << endl;
	cout << "QUADROOTS \n";
	cout << "CALCCDF \n";
	cout << "============================================== \n" << endl;
	cin >> func;

	if (func == "QUADROOTS") {
		findQuadRoots();
	}
	else {
		if (func == "CALCCDF") {
			CalcApproxCDF();
		}
	}
}


#include<iostream>
using namespace std;

#include "findQuadRoots.cpp";
#include "CalcApproxCDF.cpp";
#include "EuclidAlgoToFindGCD.cpp";
#include "FindPrime.cpp";

enum EXECFUNC
{
	QUADROOTS,
	CALCCDF,
	FINDGCD,
	FINDPRIME,

	INVALID
};

EXECFUNC getExecFuncFromInput(const string& input) {
	if ((input == "1") || (input == "QUADROOTS")) return EXECFUNC::QUADROOTS;
	if ((input == "2") || (input == "CALCCDF")) return EXECFUNC::CALCCDF;
	if ((input == "3") || (input == "FINDGCD")) return EXECFUNC::FINDGCD;
	if ((input == "4") || (input == "FINDPRIME")) return EXECFUNC::FINDPRIME;

	return EXECFUNC::INVALID;
}

int main() {
	
	string func = "";
	cout << "Please enter the number following command to run a specific function : " << endl;
	cout << "==============================================" << endl;
	cout << "1. QUADROOTS " << endl ;
	cout << "2. CALCCDF " << endl;
	cout << "3. FINDGCD " << endl;
	cout << "4. FINDPRIME" << endl;
	cout << "============================================== \n" << endl;
	cin >> func;

	EXECFUNC function = getExecFuncFromInput(func);
	switch (function) {
		case EXECFUNC::QUADROOTS:
			findQuadRoots();
			break;
		case EXECFUNC::CALCCDF:
			CalcApproxCDF();
			break;
		case EXECFUNC::FINDGCD:
			EuclidAlgoToFindGCD();
			break;
		case EXECFUNC::FINDPRIME:
			FindPrime();
			break;
		case EXECFUNC::INVALID:
				cout << "Please enter the valid number or function name (ALL CAPS) from the list to execute the function!";
				break;

	};
	
	
}


#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>

//Finish up this code
using namespace std;

int main()
{
	string input;
	getline(cin, input);
	int nN = count(input.begin(), input.end(), 'N'),
		nW = count(input.begin(), input.end(), 'W'),
		nE = count(input.begin(), input.end(), 'E'),
		nS = count(input.begin(), input.end(), 'S');
	int xTarget = nE - nW,
	yTarget = nS - nN;

	cout << (abs(xTarget) + abs (yTarget)) << endl;

	cin.get();

	return 0;
}

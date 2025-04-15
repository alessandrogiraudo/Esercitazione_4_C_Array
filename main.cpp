#include <iostream>
#include <fstream>
#include "Utils.hpp"
#include <iomanip>

using namespace std;

int main()
{
	string ifile = "./data.txt";
	string ofile = "./results.txt";
	
	double S = 0.0;
	double* w = nullptr;
	double* r = nullptr;
	unsigned int n = 0;
	
	if(!ImportData(ifile,S,n,w,r))
	{
		return 1;
	}
	
	double V = finalValue(S,n,w,r);
	
	if(!ExportResult(ofile,S,n,w,r,V))
	{
		return 1;
	}
	
	delete[] w;
	delete[] r;
	
	
	
    return 0;
}


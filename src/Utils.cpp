#include "Utils.hpp"

#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

bool ImportData(const string& importFilePath,
				double& S,
				unsigned int& n,
				double*& w,
				double*& r)
{
	ifstream file(importFilePath);
	if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }
	
	// Leggo S, n e ignoro la linea w;r
	string _;
	getline(file, _, ';');
	file >> S;
	file.ignore();
	
	getline(file, _, ';');
	file >> n;
	file.ignore();
	
	getline(file,_);
	
	w = new double[n];
	r = new double[n];
	for(unsigned int i = 0; i<n; i++)
	{
		getline(file, _, ';') ;
		w[i] = stod(_);
		file >> r[i];
		file.ignore();
	}
	
	cout << "S = " << fixed << setprecision(2) << S << defaultfloat << ", n = " << n << endl;

	cout << "w = [";
	for(unsigned int i = 0; i<n; i++) {
		cout << w[i] << " ";
	}
	cout << " ]" << endl;
	cout << "r = [";
	for(unsigned int i = 0; i<n; i++) {
		cout << r[i] << " ";
	}
	cout << " ]" << endl;
	
	double rate = 0.0;
	for(unsigned int i = 0; i < n; i++)
	{
		rate += w[i] * r[i];
	}

    cout << "Rate of return of the portfolio: " << rate << endl;
    cout << "V: " << fixed << setprecision(2) << (1 + rate) * S << defaultfloat << endl;;
	
	return true;
};
	

bool ExportResult(const string& outputFilePath,
				  const double& S,
				  const unsigned int &n,
				  double* const& w,
				  double* const& r,
				  const double& finalValue)
{
    ofstream file(outputFilePath);
	
	if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }
	
	file << "S = " << fixed << setprecision(2) << S << defaultfloat << ", n = " << n << endl;
	
	file << "w = [";
	for(unsigned int i = 0; i<n; i++) {
		file << w[i] << " ";
	}
	file << " ]" << endl;
	file << "r = [";
	for(unsigned int i = 0; i<n; i++) {
		file << r[i] << " ";
	}
	file << " ]" << endl;
	
	double rate = 0.0;
	for(unsigned int i = 0; i < n; i++)
	{
		rate += w[i] * r[i];
	}

    file << "Rate of return of the portfolio: " << rate << endl;
    file << "V: " << fixed << setprecision(2) << finalValue << defaultfloat << endl;

    return true;
}

double finalValue(const double& S,
				  const unsigned int& n,
				  const double* const& w,
				  const double* const& r)
{
	double rate = 0.0;
	for(unsigned int i = 0; i < n; i++) 
	{
		rate = rate + w[i] * r[i];
	}
	return (1 + rate) * S;
}

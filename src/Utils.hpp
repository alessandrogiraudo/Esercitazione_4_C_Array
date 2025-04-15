#pragma once

#include <iostream>

using namespace std;

	
bool ImportData(const string& importFilePath,
				double& S,
				unsigned int& n,
				double*& w,
				double*& r);
				  

bool ExportResult(const string& outputFilePath,
				  const double& S,
				  const unsigned int &n,
				  double* const& w,
				  double* const& r,
				  const double& finalValue);
				  
double finalValue(const double& S,
				  const unsigned int& n,
				  const double* const& w,
				  const double* const& r);
				  			  

#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include <sstream>

using std::string;
using std::vector;
using std::setw;
using std::setprecision;
using std::cout;
using std::cin;
using std::endl;
using std::fixed;
using std::left;
using std::ifstream;
using std::cerr;
using std::istringstream;

struct Studentas {
        string vardas;
        string pavarde;
        vector<int> paz;
        int egzam;
        double vidurkis;
        double vidurkis2;
    };

double Mediana(const vector<int>& pazymiai);
bool vardlyg(const Studentas& a, const Studentas& b);
#endif // MYLIB_H_INCLUDED

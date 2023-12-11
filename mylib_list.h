#ifndef MYLIB_H_INCLUDED
#define MYLIB_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <time.h>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <random>
#include <chrono>
#include <list>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::setw;
using std::setprecision;
using std::fixed;
using std::left;
using std::right;
using std::end;
using std::begin;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::swap;
using std::getline;
using std::stoi;
using std::cerr;
using std::numeric_limits;
using std::streamsize;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;
using std::istringstream;
using std::to_string;
using std::list;
using std::advance;
using std::prev;


struct Studentas {
        string vardas;
        string pavarde;
        list<int> paz;
        int egzam;
        double vidurkis;
        double mediana;
        double balasvid;
        double balasmed;
    };

int ivesk_skaiciu(int x1, int x2);
void duomenu_ivedimas (Studentas &stud, int i, int &n, int &sum, int m);
void Skaityti(list <Studentas> &studentai, int &m, string failas);
void VidurkisIrMediana (Studentas &stud, int &n, int &sum, list <Studentas> &studentai);
bool vardlyg(const Studentas& a, const Studentas& b);
bool pavardlyg(const Studentas &a, const Studentas &b);
bool bal_vid_lyg(const Studentas &a, const Studentas &b);
bool bal_med_lyg(const Studentas &a, const Studentas &b);
void Rusiavimas2(list <Studentas> &studentai);
int atsitiktinaspaz(int min, int max);
void file_gen(int &m, int &n);
void Rusiuoti(list <Studentas> &studentai, list <Studentas> &vargsiukai, list <Studentas> &kietiakai);
void isvedimas_i_faila(list <Studentas> studentai, string pavadinimas);
#endif // MYLIB_H_INCLUDED

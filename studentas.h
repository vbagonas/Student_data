#ifndef STUDENTAS_H_INCLUDED
#define STUDENTAS_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <limits>
#include <random>
#include <chrono>

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



class Studentas {
private:
        string vardas_;
        string pavarde_;
        vector<int> paz;
        int egzam_;
        double vidurkis_;
        double mediana_;
        double balasvid_;
        double balasmed_;
public:
    Studentas() : egzam_(0), vidurkis_(0), mediana_(0), balasvid_(0), balasmed_(0) {}
    ~Studentas() {}

    string getVardas() const {return vardas_;};
    string getPavarde() const {return pavarde_;};
    const vector<int> getPaz() const {return paz;}
    int getEgzam() const {return egzam_;}
    double getVidurkis() const {return vidurkis_;}
    double getMediana() const {return mediana_;}
    double getBalasvid() const {return balasvid_;}
    double getBalasmed() const {return balasmed_;}

    void clearPaz();

    void setVardas(string);
    void setPavarde(string);
    void setEgzam(int);
    void setPazym(int);
    void setMediana(double);
    void setVidurkis(double);
    void setBalasVid(double);
    void setBalasMed(double);

};


int ivesk_skaiciu(int x1, int x2);
void duomenu_ivedimas (Studentas &stud, int i, int &n, int &sum, int m);
void Skaityti(vector <Studentas> &studentai, int &m, string failas);
void VidurkisIrMediana (Studentas &stud, int &n, int &sum, vector <Studentas> &studentai);
bool vardlyg(const Studentas& a, const Studentas& b);
bool pavardlyg(const Studentas &a, const Studentas &b);
bool bal_vid_lyg(const Studentas &a, const Studentas &b);
bool bal_med_lyg(const Studentas &a, const Studentas &b);
void Rusiavimas2(vector <Studentas> &studentai);
int atsitiktinaspaz(int min, int max);
void file_gen(int &m, int &n);
void Rusiuoti(vector <Studentas> &studentai, vector <Studentas> &vargsiukai, vector <Studentas> &kietiakai);
void isvedimas_i_faila(vector <Studentas> studentai, string pavadinimas);


#endif // STUDENTAS_H_INCLUDED


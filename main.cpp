#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
#include <algorithm>
#include <random>
using namespace std;

 struct Studentas {
        string vardas;
        string pavarde;
        vector<int> paz;
        int egzam;
        double vidurkis;
        double vidurkis2;
    };
double Mediana(const vector<int>& pazymiai) {
    vector<int> rus_pazym = pazymiai;
    sort(rus_pazym.begin(), rus_pazym.end());

    size_t size = rus_pazym.size();
    if (size % 2 == 0) {
        // If even number of elements, return the average of the middle two
        return (rus_pazym[size / 2 - 1] + rus_pazym[size / 2]) / 2.0;
    } else {
        // If odd number of elements, return the middle element
        return rus_pazym[size / 2];
    };
}
double atsitiktinaspaz(double min, double max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> distribution(min, max);
    return distribution(gen);
}
int main()
{
    vector<Studentas> studentai;
    int stud_sk;
    cout<<"iveskite studentu skaiciu: ";
    cin>>stud_sk;

    for(int i=0; i<stud_sk; i++){
        Studentas studentas;
        cout<<"Studentas nr."<<i+1<<" - Ivesk varda: ";
        cin>>studentas.vardas;
        cout<<"Studentas nr."<<i+1<<" - Ivesk pavarde: ";
        cin>>studentas.pavarde;
        int pazym;
        string pasirinkimas;
        cout<<"Ar norite, kad pazymiai butu generuojami atsitiktinai? (taip/ne)"<<endl;
        cin>>pasirinkimas;
        if (pasirinkimas == "taip"){
            for (int j = 0; j < 5; ++j) {
                int pazym = atsitiktinaspaz(1, 10);
                studentas.paz.push_back(pazym);
            }
            studentas.egzam = atsitiktinaspaz(1, 10);
        } else if (pasirinkimas == "ne") {
            cout << "Iveskite namu darbu pazymi (paspauskite raide ir enter, kad sustabdyti: ";
            while (cin >> pazym) {
                studentas.paz.push_back(pazym);
            }
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout<<"ivesk egzamino pazymi: ";
            cin>>studentas.egzam;
        }
        double nd_vid = 0.0;
        double nd_med = 0.0;
        for (int pazym : studentas.paz) {
            nd_vid += pazym;
        }
        if(!studentas.paz.empty()){
                nd_vid /= studentas.paz.size();
            }
        nd_med = Mediana(studentas.paz);
        studentas.vidurkis = 0.4 * nd_vid + 0.6 * studentas.egzam;
        studentas.vidurkis2 = 0.4 * nd_med + 0.6 * studentas.egzam;
        studentai.push_back(studentas);
    }

    cout<<setw(15)<<left<<"Vardas"<<setw(15)<<"Pavarde"<<setw(20)<<"Galutinis (Vid.)"<<"Galutinis (Med.)"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    for (const Studentas& studentas : studentai) {
        cout<<setw(15)<<left<<studentas.vardas<<setw(15)<<studentas.pavarde<<setw(20)<<fixed<<setprecision(2)<<studentas.vidurkis<<fixed<<setprecision(2)<<studentas.vidurkis2<<endl;
    }

    return 0;
}






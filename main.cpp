#include "mylib.h"
#include "mylib.cpp"

int main() {
    ifstream file("kursiokai.txt");
    if(!file.is_open()){
        cerr<<"Nepavyko atidaryti failo."<<endl;
        return 1;
    }
    string eile;
    vector<Studentas> studentai;
    bool skaitytind = false;
    int skND = 0;

    if (getline(file, eile)) {
        istringstream titleLine(eile);
        string stulpav;
        while (titleLine >> stulpav) {
            if (stulpav == "Vardas") {
                continue;
            } else if (stulpav == "Pavarde") {
                continue;
            } else if (stulpav == "Egz.") {
                skaitytind = false;
                break;
            } else {
                skaitytind = true;
                skND++;
            }
        }
    } else {
        cerr << "Error: Empty input file." << endl;
        return 1;
    }

    while(getline(file, eile)){
        istringstream iss(eile);
        Studentas studentas;
        iss>>studentas.vardas>>studentas.pavarde;
        int balas;

        for(int i = 0; i<skND; i++) {
            if(iss>>balas) {
                studentas.paz.push_back(balas);
            } else {
                cerr << "Klaida. Nera ND pazymio" << endl;
            }
        }
        if (iss>>studentas.egzam) {
            studentai.push_back(studentas);
        } else {
            cerr << "Klaida. Nera egzamino pazymio" << endl;
        }
    }

    for (Studentas& studentas : studentai) {
        double ndSuma = 0, ndMed = 0;
        for (int balas : studentas.paz) {
            ndSuma += balas;
        }
        double ndVid = ndSuma / skND;
        studentas.vidurkis = 0.4 * ndVid + 0.6 * studentas.egzam;
        ndMed = Mediana(studentas.paz);
        studentas.vidurkis2 = 0.4 * ndMed + 0.6 * studentas.egzam;
    }
    sort(studentai.begin(), studentai.end(), vardlyg);
    cout<<setw(15)<<left<<"Vardas"<<setw(15)<<"Pavarde"<<setw(20)<<"Galutinis(Vid.)"<<"Galutinis(Med.)"<<endl;
    cout<<"------------------------------------------------------------------"<<endl;
    for(const Studentas& studentas : studentai){
          cout<<setw(15)<<left<<studentas.vardas<<setw(15)<<studentas.pavarde<<setw(20)<<fixed<<setprecision(2)<<studentas.vidurkis<<fixed<<setprecision(2)<<studentas.vidurkis2<<endl;
    }
    return 0;
}





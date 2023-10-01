#include <iostream>
#include <iomanip>
#include <vector>
#include <limits>
using namespace std;

 struct Studentas {
        string vardas;
        string pavarde;
        vector<int> paz;
        int egzam;
        double vidurkis;
    };
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
        cout<<"Ivesk namu darbu ivertinimus (paspausk bet kokia raide, kad sustabdyti): ";
        int pazym;
        while(cin>>pazym){
            studentas.paz.push_back(pazym);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"ivesk egzamino pazymi: ";
        cin>>studentas.egzam;
        double nd_vid = 0.0;
        for(int pazym: studentas.paz){
            nd_vid +=pazym;
        }
        if(!studentas.paz.empty()){
            nd_vid /= studentas.paz.size();
        }
        studentas.vidurkis = 0.4 * nd_vid + 0.6 * studentas.egzam;
        studentai.push_back(studentas);
    }

    cout<<setw(15)<<left<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis vid"<<endl;
    cout<<"-------------------------------------------"<<endl;
    for (const Studentas& studentas : studentai) {
        cout<<setw(15)<<left<<studentas.vardas<<setw(15)<<studentas.pavarde<<fixed<<setprecision(2)<<studentas.vidurkis<<endl;
    }

    return 0;
}






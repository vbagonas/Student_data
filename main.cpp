#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    string vard;
    string pav;
    int namdarb, namdarb2, namdarb3, egz, n = 3;
    double vid, ndvid;
    cout<<"iveskite varda: ";
    cin>>vard;
    cout<<"iveskite pavarde: ";
    cin>>pav;
    cout<<"iveskite ND1 gauta pazymi: ";
    cin>>namdarb;
    cout<<"iveskite ND2 gauta pazymi: ";
    cin>>namdarb2;
    cout<<"iveskite ND3 gauta pazymi: ";
    cin>>namdarb3;
    cout<<"iveskite egzamino pazymi: ";
    cin>>egz;
    ndvid = (namdarb+namdarb2+namdarb3)/3.0;
    vid =(0.40*ndvid) + (0.60*egz);
    cout<<setw(15)<<left<<"Vardas"<<setw(15)<<"Pavarde"<<"Galutinis (Vid.)"<<endl;
    cout<<"----------------------------------------------"<<endl;
    cout<<setw(15)<<left<<vard<<setw(15)<<pav<<setprecision(3)<<vid<<endl;
    return 0;
}

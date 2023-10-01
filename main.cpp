#include <iostream>

using namespace std;

int main()
{
    string vard;
    string pav;
    int namdarb, egz;
    double vid;
    cout<<"iveskite varda: ";
    cin>>vard;
    cout<<"iveskite pavarde: ";
    cin>>pav;
    cout<<"iveskite ND gauta pazymi: ";
    cin>>namdarb;
    cout<<"iveskite egzamino pazymi: ";
    cin>>egz;
    vid =0.4*namdarb + 0.6*egz;
    cout<<vard<<" "<<pav<<" "<<vid<<endl;
    return 0;
}

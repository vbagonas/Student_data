#include "mylib.h"
#include "mylib.cpp"
int main ()
{
    Studentas stud;
    vector <Studentas> studentai;
    int m = 0, n = 0, n1, skaicius;
    int sum = 0;
    string t;

    cout<<"Kaip ivesite duomenis? (1-ranka, 2-is failo)"<<endl;

    skaicius = ivesk_skaiciu(1, 2);

    if (skaicius == 1)
    {
        cout<<"Iveskite studentu skaiciu"<<endl;
        cin>>m;
        for(int i = 0; i < m; i++)
        {
            duomenu_ivedimas(stud, i, n, sum, m);
            VidurkisIrMediana(stud, n, sum, studentai);
        }
    }
    else
    {
        Skaityti(studentai, m);
    }

    sort(studentai.begin(), studentai.end(), vardlyg);
    cout << "------------------------------------------------------------------------" << endl;
    cout << setw(15) << left << "Vardas" << setw(15) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)";
    cout << setw(20) << right << "Galutinis (Med.)" << endl;

    cout << "------------------------------------------------------------------------" << endl;
    for (auto &a: studentai)
    {
        cout << setw(15) << left << a.vardas << setw(15) << right << a.pavarde;
        cout << setw(20) << right << setprecision(2) << fixed << a.vidurkis*0.4 + a.egzam*0.6;
        cout << setw(20) << right << setprecision(2) << fixed << a.mediana*0.4 + a.egzam*0.6 << endl;
    }
    return 0;
}










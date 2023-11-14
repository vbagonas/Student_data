#include "mylib.h"
#include "mylib.cpp"
int main ()
{
    Studentas stud;
    vector <Studentas> studentai, vargsiukai, kietiakai;
    int skaicius, m = 0, n = 0;
    int sum = 0;
    string t;

    cout<<"Kaip ivesite duomenis? (1-ranka, 2-is failo) Jeigu norite generuoti faila, spauskite (3)"<<endl;

    skaicius = ivesk_skaiciu(1, 3);

    if (skaicius == 1)
    {
        cout<<"Iveskite studentu skaiciu"<<endl;
        cin>>m;
        for(int i = 0; i < m; i++)
        {
            duomenu_ivedimas(stud, i, n, sum, m);
            VidurkisIrMediana(stud, n, sum, studentai);
        }
        Rusiavimas2(studentai);
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
    }
    else if(skaicius == 2)
    {
        string failas;
        cout<<"Koks failo pavadinimas?"<<endl;
        cin>>failas;

        auto start = std::chrono::high_resolution_clock::now();

        Skaityti(studentai, m, failas);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << m << " studentu failo skaitymas uztruko: "<< diff.count() << " s;" << endl;

        Rusiavimas2(studentai);

        start = std::chrono::high_resolution_clock::now();

        Rusiuoti(studentai, vargsiukai, kietiakai);

        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end-start;
        cout << m << " studentu failo rusiavimas uztruko: "<< diff1.count() << " s;" << endl;

        start = std::chrono::high_resolution_clock::now();
        isvedimas_i_faila(vargsiukai, "Vargsiukai");
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end-start;
        cout << m << " studentu failu isvedimas uztruko: "<< diff2.count() << " s;" << endl;

        start = std::chrono::high_resolution_clock::now();
        isvedimas_i_faila(kietiakai, "Kietiakai");
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff3 = end-start;
        cout << m << " studentu failu isvedimas uztruko: "<< diff3.count() << " s;" << endl;

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
    }
    else
    {
        cout<<"kiek studentu kurse? "<<endl;
        cin>>m;
        file_gen(m, n);
    }
    return 0;
}












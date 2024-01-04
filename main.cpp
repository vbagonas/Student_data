#include "studentas.h"
#include "functions.cpp"
int main ()
{
    Studentas stud;
    vector <Studentas> studentai, vargsiukai, kietiakai;
    int skaicius, m = 0, n = 0;
    int sum = 0;
    string t;

    cout<<"Kaip ivesite duomenis? (1-ranka, 2-is failo) Jeigu norite generuoti faila, spauskite (3)"<<endl;

    skaicius = ivesk_skaiciu(1, 4);

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
            cout << setw(15) << left << a.getVardas() << setw(15) << right << a.getPavarde();
            cout << setw(20) << right << setprecision(2) << fixed << a.getVidurkis()*0.4 + a.getEgzam()*0.6;
            cout << setw(20) << right << setprecision(2) << fixed << a.getMediana()*0.4 + a.getEgzam()*0.6 << endl;
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

        Rusiavimas2(studentai);
        cout << m << " studentu failo skaitymas uztruko: "<< diff.count() << " s;" << endl;
        start = std::chrono::high_resolution_clock::now();

        Rusiuoti(studentai, vargsiukai, kietiakai);

        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff1 = end-start;
        cout << m << " studentu failo rusiavimas uztruko: "<< diff1.count() << " s;" << endl;

        start = std::chrono::high_resolution_clock::now();
        isvedimas_i_faila(kietiakai, "Kietiakai");
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff3 = end-start;
        cout <<"Kietiaku failo isvedimas uztruko: "<< diff3.count() << " s;" << endl;

        start = std::chrono::high_resolution_clock::now();
        isvedimas_i_faila(vargsiukai, "Vargsiukai");
        end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff2 = end-start;
        cout <<"Vargsiuku failo isvedimas uztruko: "<< diff2.count() << " s;" << endl;

    }
    else if(skaicius == 3)
    {
        cout<<"kiek studentu kurse? "<<endl;
        cin>>m;
        file_gen(m, n);
    }
    else
    {
        Studentas stud;
        stud.setVardas("Vardenis");
        stud.setPavarde("Pavardenis");
        stud.setBalasVid(8);
        stud.setBalasMed(4);
        Studentas stud_copy{stud};
        Studentas stud_prisk = stud;
        cout << "Sukurtas studentas: " << endl;
        cout << stud << endl;
        cout << "Nukopijuotas studentas: " << endl;
        cout << stud_copy << endl;
        cout << "Priskirtas studentas: " << endl;
        cout << stud_prisk << endl;
    }
    return 0;
}

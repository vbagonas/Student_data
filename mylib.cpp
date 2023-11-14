#include "mylib.h"

int ivesk_skaiciu(int x1, int x2)
{
    string t;
    int skaicius;
    bool validInput = false;

    while(!validInput)
    {
        try
        {
            cin>>t;
            skaicius = stoi(t);
            if (skaicius < x1 || skaicius > x2)
            {
                throw std::out_of_range("");
            }
            validInput = true;
        }
        catch (const std::invalid_argument& e)
        {
            cerr << "Ivedete ne skaiciu. Bandykite dar karta. (" << e.what() << ")" << std::endl;
        }
        catch (const std::out_of_range& e)
        {
            cerr << "Netinkamas skaicius. Iveskite skaiciu tarp " << x1 << " ir " << x2 << ":" << e.what() << std::endl;
        }
    }
    return skaicius;
}

void duomenu_ivedimas (Studentas &stud, int i, int &n, int &sum, int m)
{
    string t;
    cout<<"Studentas nr."<<i+1<<" - Ivesk varda: ";
    cin>>stud.vardas;
    cout<<"Studentas nr."<<i+1<<" - Ivesk pavarde: ";
    cin>>stud.pavarde;
    cout<<"Ar generuoti pazymius? (1-taip, 2-ne)" <<endl;
    int skaic = ivesk_skaiciu(1, 2);
    int pazym;
    if(skaic == 1)
    {
        cout<<"iveskite pazymiu skaiciu: "<<endl;
        cin>>n;
        for (int j = 0; j < n; ++j) {
            int pazym = atsitiktinaspaz(1, 10);
            stud.paz.push_back(pazym);
            sum += pazym;
        }
        stud.egzam = atsitiktinaspaz(1, 10);
    }
    else
    {
        cout << "Iveskite namu darbu pazymi (paspauskite raide ir enter, kad sustabdyti: ";
        while (cin >> pazym) {
            stud.paz.push_back(pazym);
            sum += pazym;
            n++;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"ivesk egzamino pazymi: ";
        cin>>stud.egzam;
    }
}
void Skaityti(vector <Studentas> &studentai, int &m, string failas)
{
    ifstream file(failas);
    string ignor, eile;
    Studentas stud;
    int pazym, sum = 0, n = 0;
    bool skaitytind = false;
    int skND = 0;

    if(!file.is_open())
    {
    cerr << "Klaida. Failas nerastas." << endl;
    }

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
    }
    while (getline(file,eile))
    {
        istringstream iss(eile);
        iss>>stud.vardas>>stud.pavarde;
        int balas;
        for(int i = 0; i < skND; i++)
        {
            if(iss>>balas){
                stud.paz.push_back(balas);
                sum += balas;
                n++;
            }
            else
            {
                cerr<<"Error: Empty input file." << endl;
            }
        }
        iss>>stud.egzam;
        VidurkisIrMediana(stud, n, sum, studentai);
        m++;
        }
    file.close();
}
void VidurkisIrMediana(Studentas &stud, int &n, int &sum, vector <Studentas> &studentai) {
    stud.vidurkis = static_cast<float>(sum)/n;
    sort(stud.paz.begin(), stud.paz.end());
    int dyd = stud.paz.size();
    if (dyd % 2 == 0)
    {
        stud.mediana = static_cast<float>(stud.paz[(dyd - 1) / 2] + stud.paz[dyd / 2]) / 2;
    }
    else
    {
    stud.mediana = stud.paz[dyd / 2];
    }
    stud.balasmed = static_cast<float>(stud.mediana*0.4 + stud.egzam*0.6);
    stud.balasvid = static_cast<float>(stud.vidurkis*0.4 + stud.egzam*0.6);
    studentai.push_back(stud);
    stud.paz.clear();
    sum = 0;
    n=0;
}
bool vardlyg(const Studentas &a, const Studentas &b) {
    return a.vardas < b.vardas;
}
bool pavardlyg(const Studentas &a, const Studentas &b) {
    return a.pavarde < b.pavarde;
}
bool ballyg(const Studentas &a, const Studentas &b) {
    return a.balasvid < b.balasvid;
}
void Rusiavimas2(vector <Studentas> &studentai)
{
    int pasirinkimas;
    cout<<"Pagal kuri parametra rusiuoti studentus? (1-Varda, 2-Pavarde, 3-Vidurki): "<<endl;
    cin>>pasirinkimas;
    if(pasirinkimas == 1)
    {
        sort(studentai.begin(), studentai.end(), vardlyg);
    }
    else if(pasirinkimas == 2)
    {
        sort(studentai.begin(), studentai.end(), pavardlyg);
    }
    else
    {
        sort(studentai.begin(), studentai.end(), ballyg);
    }
}
int atsitiktinaspaz(int min, int max)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}
void file_gen(int &m, int &n)
{
    ofstream fr ("Studentai" + to_string(m) + ".txt");
    Studentas stud;
    int sum;

    cout<<"Kiek pazymiu generuoti kiekvienam studentui? "<<endl;
    cin>>n;
    fr<<setw(15)<<left<<"Vardas"<<setw(16)<<left<<"Pavarde";
    for(int i = 0; i<n; i++)
    {
        fr<<setw(5)<<"ND" + to_string(i+1);
    }
    fr<<setw(7)<<right<<"Egz."<<endl;
    for(int i=0; i<m; i++)
    {
        stud.vardas = "Vardas" + to_string(i+1);
        stud.pavarde = "Pavarde" + to_string(i+1);
        fr<<setw(15)<<left<<stud.vardas<<setw(16)<<left<<stud.pavarde;
        for(int i=0; i<n; i++)
        {
            fr<<setw(5)<<atsitiktinaspaz(2, 10);
        }
        fr<<setw(4)<<right<<atsitiktinaspaz(2, 10)<<endl;
    }
    fr.close();
}
void Rusiuoti(vector <Studentas> &studentai, vector <Studentas> &vargsiukai, vector <Studentas> &kietiakai)
{
    for(auto &a: studentai)
    {
        if (a.balasvid < 5)
        {
            vargsiukai.push_back(a);
        }
        else
        {
            kietiakai.push_back(a);
        }
    }
}
void isvedimas_i_faila(vector <Studentas> studentai, string pavadinimas)
{
    ofstream fr("Rezultatai" + pavadinimas + ".txt");
    fr << setw(15) << left << "Vardas" << setw(16) << right << "Pavarde" << setw(20) << right << "Galutinis (Vid.)";
    fr << setw(20) << right << "Galutinis (Med.)" << endl;

    for (auto &a: studentai)
    {
        fr << setw(15) << left << a.vardas << setw(16) << right << a.pavarde;
        fr << setw(20) << right << setprecision(2) << fixed << a.balasvid;
        fr << setw(20) << right << setprecision(2) << fixed << a.balasmed << endl;
    }
    fr.close();
}



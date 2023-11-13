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
/*void Skaityti(vector <Studentas> studentai, int &m)
{
    ifstream file("student_data.txt");
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
        iss>>studentai.vardas>>studentai.pavarde;
        int balas;
        for(int i = 0; i < skND, i++)
        {
            if(iss>>balas){
                studentai.paz.push_back(balas);
                sum += balas;
            } else {
                cerr<<"Error: Empty input file." << endl;
            }
        }
        if(iss>>studentai.egzam){
            studentai.push_back(studentas);
        } else {
            cerr << "Klaida. Nera egzamino pazymio" << endl;
        }
        VidurkisIrMediana(stud, n, sum, studentai);
        }
    file.close();
}*/
void VidurkisIrMediana(Studentas &stud, int &n, int &sum, vector <Studentas> &studentai) {
    stud.vidurkis = static_cast<float>(sum)/n;
        //----------------------skaiciuojam mediana---------------------------
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
    //---------------------------------------------------------------------
    studentai.push_back(stud);
    stud.paz.clear();
    sum = 0;
    n = 0;
}
bool vardlyg(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}
double atsitiktinaspaz(double min, double max)
{
    static random_device rd;
    static mt19937 gen(rd());
    uniform_real_distribution<double> distribution(min, max);
    return distribution(gen);
}



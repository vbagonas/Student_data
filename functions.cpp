#include "studentas.h"

void Studentas::setVardas(string vardas) {
    vardas_ = vardas;
}
void Studentas::setPavarde(string pavarde) {
    pavarde_ = pavarde;
}
void Studentas::setEgzam(int egzam) {
    egzam_ = egzam;
}
void Studentas::setMediana(double mediana) {
    mediana_ = mediana;
}
void Studentas::setVidurkis(double vidurkis) {
    vidurkis_ = vidurkis;
}
void Studentas::setPazym(int pazym)
{
    paz.push_back(pazym);
}
void Studentas::setBalasVid(double balasvid) {
    balasvid_ = balasvid;
}
void Studentas::setBalasMed(double balasmed) {
    balasmed_ = balasmed;
}
void Studentas::clearPaz() {
    paz.clear();
}

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
    int exam;
    cout<<"Studentas nr."<<i+1<<" - Ivesk varda: ";
    cin>>t;
    stud.setVardas(t);
    cout<<"Studentas nr."<<i+1<<" - Ivesk pavarde: ";
    cin>>t;
    stud.setPavarde(t);
    cout<<"Ar generuoti pazymius? (1-taip, 2-ne)" <<endl;
    int skaic = ivesk_skaiciu(1, 2);
    int pazym;
    if(skaic == 1)
    {
        cout<<"iveskite pazymiu skaiciu: "<<endl;
        cin>>n;
        for (int j = 0; j < n; ++j) {
            int pazym = atsitiktinaspaz(1, 10);
            stud.setPazym(pazym);
            sum += pazym;
        }
        exam = atsitiktinaspaz(1, 10);
        stud.setEgzam(exam);
    }
    else
    {
        cout << "Iveskite namu darbu pazymi (paspauskite raide ir enter, kad sustabdyti: ";
        while (cin >> pazym) {
            stud.setPazym(pazym);
            sum += pazym;
            n++;
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout<<"ivesk egzamino pazymi: ";
        cin>>exam;
        stud.setEgzam(exam);
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
    string tempVardas, tempPavarde;
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
        iss>>tempVardas>>tempPavarde;
        stud.setVardas(tempVardas);
        stud.setPavarde(tempPavarde);
        int balas;
        int exam;
        for(int i = 0; i < skND; i++)
        {
            if(iss>>balas){
                stud.setPazym(balas);
                sum += balas;
                n++;
            }
            else
            {
                cerr<<"Error: Empty input file." << endl;
            }
        }
        iss>>exam;
        stud.setEgzam(exam);
        VidurkisIrMediana(stud, n, sum, studentai);
        m++;
        }
    file.close();
}
void VidurkisIrMediana(Studentas &stud, int &n, int &sum, vector <Studentas> &studentai) {
    double avg = static_cast<float>(sum)/n;
    vector<int> pazymiai = stud.getPaz();

    sort(pazymiai.begin(), pazymiai.end());
    double mediana;
    size_t size = pazymiai.size();
    if (size % 2 == 0)
    {
        mediana = (pazymiai[size / 2 - 1] + pazymiai[size / 2]) / 2.0;
    }
    else
    {
        mediana = pazymiai[size / 2];
    }
    stud.setMediana(mediana);

    double balasvid = avg * 0.4 + stud.getEgzam() * 0.6;
    stud.setBalasVid(balasvid);
    double balasmed = stud.getMediana() *0.4 + stud.getEgzam()*0.6;
    stud.setBalasMed(balasmed);

    studentai.push_back(stud);
    stud.clearPaz();
    sum = 0;
    n=0;
}
bool vardlyg(const Studentas &a, const Studentas &b) {
    return a.getVardas() < b.getVardas();
}
bool pavardlyg(const Studentas &a, const Studentas &b) {
    return a.getPavarde() < b.getPavarde();
}
bool bal_vid_lyg(const Studentas &a, const Studentas &b) {
    return a.getBalasvid() < b.getBalasvid();
}
bool bal_med_lyg(const Studentas &a, const Studentas &b) {
    return a.getBalasmed() < b.getBalasmed();
}
void Rusiavimas2(vector <Studentas> &studentai)
{
    int pasirinkimas;
    cout<<"Pagal kuri parametra rusiuoti studentus? (1-Varda, 2-Pavarde, 3-Vidurki, 4-Mediana): "<<endl;
    cin>>pasirinkimas;
    if(pasirinkimas == 1)
    {
        sort(studentai.begin(), studentai.end(), vardlyg);
    }
    else if(pasirinkimas == 2)
    {
        sort(studentai.begin(), studentai.end(), pavardlyg);
    }
    else if(pasirinkimas == 3)
    {
        sort(studentai.begin(), studentai.end(), bal_vid_lyg);
    }
    else
    {
        sort(studentai.begin(), studentai.end(), bal_med_lyg);
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
        fr<<setw(15)<<left<<"Vardas" + to_string(i+1)<<setw(16)<<left<<"Pavarde" + to_string(i+1);
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
        if (a.getBalasvid() < 5)
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
        fr << setw(15) <<  left << a.getVardas() << setw(16) << right << a.getPavarde();
        fr << setw(20) << right << setprecision(2) << fixed << a.getBalasvid();
        fr << setw(20) << right << setprecision(2) << fixed << a.getBalasmed() << endl;
    }
    fr.close();
}

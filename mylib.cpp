#include "mylib.h"

double Mediana(const vector<int>& pazymiai) {
    vector<int> rus_pazym = pazymiai;
    sort(rus_pazym.begin(), rus_pazym.end());

    size_t size = rus_pazym.size();
    if (size % 2 == 0) {
        return (rus_pazym[size / 2 - 1] + rus_pazym[size / 2]) / 2.0;
    } else {
        return rus_pazym[size / 2];
    }
};
bool vardlyg(const Studentas& a, const Studentas& b) {
    return a.vardas < b.vardas;
}

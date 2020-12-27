#include <iostream>
#include <vector>
#include <string>


using namespace std;

// стандартные операции
double UMNOJENIE(double a, double b) {
    return a * b;
}

double DELENIE(double a, double b) {
    return a / b;

}

double SUMMA(double a, double b) {
    return a + b;
}

double VICHETANIE(double a, double b) {
    return a - b;
}

int main() {
    unsigned int s = 0;
    string str;
    string chislo;
    vector<char> znak;
    vector<double> c;
    vector<char> primer;
    cin >> str;
    unsigned int o = 0;
    copy(str.begin(), str.end(), back_inserter(primer));
    if (primer[0] == '-') {
        o = 1;
        primer.erase(primer.cbegin());
    }
    for (unsigned int i = 0; i < primer.size(); i++) {
        if ((primer[i] == '+') || (primer[i] == '-') || (primer[i] == '*') || (primer[i] == '/')) {
            znak.push_back(primer[i]);
        }
        else {
            chislo = chislo + primer[i];
            if (i != primer.size() - 1) {
                if ((primer[i + 1] == '+') || (primer[i + 1] == '-') || (primer[i + 1] == '*') || (primer[i + 1] == '/')) {
                    double f = atof(chislo.c_str());
                    c.push_back(f);
                    chislo.clear();
                }
                else {
                    chislo = chislo;
                }
            }
            else {
                double f = atof(chislo.c_str());
                c.push_back(f);
                chislo.clear();
            }
        }
    }
    if (o == 1) {
        c[0] = -c[0];
    }
    vector<int> s_znak;
    vector<int> f_znak;
    for (unsigned int i = 0; i < znak.size(); i++) {
        if ((znak[i] == '*') || (znak[i] == '/')) {
            f_znak.push_back(i);
        }
        else {
            s_znak.push_back(i);
        }
    }
    for (unsigned int i = 0; i < f_znak.size(); i++) {
        unsigned int m = f_znak[i];
        if (znak[m] == '*') {
            double r = UMNOJENIE(c[m], c[m + 1]);
            c[m] = r;
            c.erase(c.begin() + m + 1);
            for (unsigned int j = 0; j < s_znak.size(); j++) {
                if (m < s_znak[j]) {
                    s_znak[j] = s_znak[j] - 1;
                }
            }
            for (unsigned int p = 0; p < f_znak.size(); p++) {
                f_znak[p] = f_znak[p] - 1;
            }
        }

        if (znak[m] == '/') {
            double r = DELENIE(c[m], c[m + 1]);
            c[m] = r;
            c.erase(c.begin() + m + 1);
            for (unsigned int d = 0; d < s_znak.size(); d++) {
                if (m < s_znak[d]) {
                    s_znak[d] = s_znak[d] - 1;
                }
            }
            for (unsigned int v = 0; v < f_znak.size(); v++) {
                f_znak[v] = f_znak[v] - 1;
            }
        }

        znak.erase(znak.cbegin() + m);
    }
    for (unsigned int i = 0; i < s_znak.size(); i++) {
        unsigned int e = s_znak[i];
        if (znak[e] == '+') {
            double r = SUMMA(c[e], c[e + 1]);
            c[e] = r;
            c.erase(c.begin() + e + 1);
            for (unsigned int y = 0; y < s_znak.size(); y++) {
                s_znak[y] = s_znak[y] - 1;
            }

        }
        if ((znak[e] == '-') && (znak.size() != 0)) {
            double r = VICHETANIE(c[e], c[e + 1]);
            c[e] = r;
            c.erase(c.begin() + e + 1);
            for (unsigned int u = 0; u < s_znak.size(); u++) {
                s_znak[u] = s_znak[u] - 1;

            }
        }
        znak.erase(znak.cbegin() + e);
    }
    for (unsigned g = 0; g < c.size(); g++) {
        cout << c[g] << endl;
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

long double f(long double n) {
    // Implement the function for which the root has to be found here
    long double result = (n * n * n * n * n * n) - n - 1;
    return result;
}

void BisectionMethod(long double a, long double b, int* itr, long double e,
                     vector<vector<long double>>& table) {
    if (b - a < 2 * e) return;
    long double m = a + (b - a) / 2;
    long double fm = f(m);
    table[*itr][0] = *itr;
    table[*itr][1] = a;
    table[*itr][2] = b;
    table[*itr][3] = m;
    table[*itr][4] = fm;
    table[*itr][5] = (b - a) / 2;
    *itr = (*itr + 1);
    if (fm == 0) {
        return;
    } else if (fm > 0) {
        BisectionMethod(m, b, itr, e, table);
    } else {
        BisectionMethod(a, m, itr, e, table);
    }
}

int main() {
    // enter the maximum number of iterations you need to perform (may not be
    // achieved due to precision condition)
    int MAX_ITR = 1000;
    // set the precision you need
    long double e = 0.0000000001;
    vector<vector<long double>> table(MAX_ITR + 1, vector<long double>(6, 0));
    int itr = 1;

    BisectionMethod(0, 2, &itr, e, table);
    /*
        cout << left << setw(5) << "n" << setw(18) << "a" << setw(18) << "b"
             << setw(18) << "m" << setw(18) << "f(m)" << setw(18) << "b-m" <<
       "\n"; cout << fixed << setprecision(15);  // choose precision you want

        for (int i = 1; i < itr; i++) {
            cout << left << setw(5) << i;
            for (int j = 0; j < 6; j++) {
                cout << setw(18) << table[i][j];
            }
            cout << "\n";
        }
    */
    cout << "\nResult:\n";
    cout << "Number of Iterations: " << itr - 1 << "\n";
    cout << "Approx Value of Root: " << table[itr - 1][3] << "\n";
    cout << "Percentage Upper bound on Error: "
         << (table[itr - 1][5] / table[itr - 1][3]) * 100 << "\n";
    return 0;
}


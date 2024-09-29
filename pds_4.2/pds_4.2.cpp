#include <iostream>

using namespace std;

void lexicographicCombinations(int n, int r) {
    int* combination = new int[r];
    for (int i = 0; i < r; ++i) {
        combination[i] = i + 1;
    }

    cout <<  "combination = {";
    for (int i = 0; i < r; ++i) {
        cout << combination[i] << (i < r - 1 ? ", " : "");
    }
    cout << "}" << endl;

    while (true) {
        int i = r - 1;
        while (i >= 0 && combination[i] == n - r + i + 1) {
            --i;
        }

        if (i < 0) {
            break;
        }

        ++combination[i];
        for (int j = i + 1; j < r; ++j) {
            combination[j] = combination[j - 1] + 1;
        }

        cout << "combination = {";
        for (int i = 0; i < r; ++i) {
            cout << combination[i] << (i < r - 1 ? ", " : "");
        }
        cout << "}" << endl;
    }

    delete[] combination;
}

int main() {
    int n, r;
    cout << "Enter n = ";
    cin >> n;
    cout << "Enter r = ";
    cin >> r;
    lexicographicCombinations(n, r);
    return 0;
}
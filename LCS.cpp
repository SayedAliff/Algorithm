#include <iostream>
#include <cstring>
using namespace std;

int L[100][100]; 

void lcs(char *X, char *Y, int m, int n) {
    int i, j;

    for (i = 0; i <= m; i++) {
        for (j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else {
                if (L[i - 1][j] > L[i][j - 1])
                    L[i][j] = L[i - 1][j];
                else
                    L[i][j] = L[i][j - 1];
            }
        }
    }

    cout << "Length of LCS is: " << L[m][n] << endl;

    int index = L[m][n];
    char lcsAlgo[index + 1];
    lcsAlgo[index] = '\0';

    i = m;
    j = n;
    
    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcsAlgo[index - 1] = X[i - 1];
            i--; 
            j--; 
            index--;
        }
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "LCS String is: " << lcsAlgo << endl;
}

int main() {
    char X[100], Y[100];
    
    cout << "Enter first string: ";
    cin >> X;
    cout << "Enter second string: ";
    cin >> Y;

    int m = strlen(X);
    int n = strlen(Y);

    lcs(X, Y, m, n);

    return 0;
}
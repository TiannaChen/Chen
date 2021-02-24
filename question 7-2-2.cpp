// question : Coordinates-to-index & Index-to-coordinates

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    //input file
    ifstream input; 
    input.open("Question 7\\Question 7.2\\input_index_7_2.txt");

    //output file
    ofstream output;
    output.open("Question 7\\Question 7.2\\output_coordinates_7_2.txt");

    int n = 50, m = 57;
    string s;
    input >> s;

    output << "x1\tx2\tx3\tx4\tx5\tx6" << endl;
    int tot = 6, a[tot] = { 4,5,8,9,6,7 }, ans[tot];
    ll q;
    while (input >> q) {
        ll mu = 1;
        for (int i = 0; i < tot - 1; i++) {
            mu *= a[i];
        }
        int kk = tot;
        for (int i = tot - 2; i >= 0; i--) {
            ans[--kk] = (q) / mu;
            q %= mu;
            mu /= a[i];
        }
        ans[--kk] = q;
        for (int i = 0; i < 6; i++) {
            output << ans[i] << "\t";
        }
        output << endl;
    }

    output.close();
    input.close();

    return 0;
}
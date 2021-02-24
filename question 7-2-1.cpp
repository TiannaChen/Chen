// question : Coordinates-to-index & Index-to-coordinates

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    //input file
    ifstream input;
    input.open("Question 7\\Question 7.2\\input_coordinates_7_2.txt");

    //output file
    ofstream output; 
    output.open("Question 7\\Question 7.2\\output_index_7_2.txt");

    int n = 50, m = 57;
    string s;
    input >> s; input >> s; input >> s;
    input >> s; input >> s; input >> s;
    int tot = 6, a[tot] = { 4,5,8,9,6,7 };
    int ind[tot];
    output << "index" << endl;
    while (input >> ind[0]) {
        for (int i = 1; i < tot; i++) {
            // scanf("%d",&ind[i]);
            input >> ind[i];
        }

        ll mu = 1;
        for (int i = 0; i < tot - 1; i++) {
            mu *= a[i];
        }
        ll ans = ind[0];
        for (int i = tot - 1; i > 0; i--) {
            ans += mu * ind[i];
            mu /= a[i - 1];
        }
        output << ans << endl;
    }
    output.close();
    input.close();

    return 0;
}
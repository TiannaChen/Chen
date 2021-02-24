// question : Coordinates-to-index & Index-to-coordinates

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    //input file
    ifstream input;
    input.open("Question 7\\Question 7.1\\input_coordinates_7_1.txt");

    //output file
    ofstream output;
    output.open("Question 7\\Question 7.1\\output_index_7_1.txt");

    int n = 50, m = 57;
    string s;
    input >> s;
    input >> s;
    int a, b;
    output << "index" << endl;
    while (input >> a >> b) {
        output << b * n + a << endl;
    }
    output.close();
    input.close();

    return 0;
}
// question : Coordinates-to-index & Index-to-coordinates

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
    //input file
    ifstream input;
    input.open("Question 7\\Question 7.1\\input_index_7_1.txt");

    //output file
    ofstream output;
    output.open("Question 7\\Question 7.1\\output_coordinates_7_1.txt");
    
    int n = 50, m = 57;
    string s;
    input >> s;
    output << "x1\tx2" << endl;
    int q;
    while (input >> q) {
        output << q % n << "\t" << q / n << endl;
    }

    output.close();
    input.close();

    return 0;
}
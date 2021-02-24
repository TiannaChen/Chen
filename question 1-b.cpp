// question : operation for the right sum

// idea: DFS + road record

// Problem to be solved£ºthe matrix in question 1.b is 90000*100000 which is too large to run in my computer
// output£ºBecause the same sum can correspond to different paths£¬the output may be more then one path.All paths are preserved here.

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
vector<vector<int> > arr;
vector<char>path;
ofstream stdcout;
int m, n;
ll sum;

void init() {
    for (int i = 0; i < arr.size(); i++) {
        arr[i].clear();
    }
    path.clear();
    arr.clear();
}
//dirctor array
int dir[2][2] = { 1,0,0,1 };
// dfs
void dfs(int x, int y, ll s) {
    // find answer 
    if (x == n - 1 && y == m - 1 && s == sum) {
        stdcout << sum << " ";
        for (int i = 0; i < path.size(); i++) {
            stdcout << path[i];
        }
        stdcout << endl;
    }
    for (int i = 0; i < 2; i++) {
        int nx = x + dir[i][0], ny = y + dir[i][1];
        if (nx < n && ny < m && s + arr[nx][ny] <= sum) {
            path.push_back(i ? 'R' : 'D');
            dfs(nx, ny, s + arr[nx][ny]);
            path.pop_back();
        }

    }
}

int main() {
    // open file 
    stdcout.open("output_question_1b.txt");
    ll sumarr[2] = { 87127231192, 5994891682 };
    m = 90000, n = 100000;
    for (int i = 0; i < 4; i++) {
        sum = sumarr[i];
        swap(n, m); init(); int num;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < m; j++) {
                v.push_back(i + 1);
            }
            arr.push_back(v);
        }
        dfs(0, 0, arr[0][0]);
    }
    // close file stream
    stdcout.close();
    return 0;
}


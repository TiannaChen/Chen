// question : points inside/outside polygon

// idea: determine the position relationship between points and polygons.
// arc length methor£ºmake the unit circle with the judgment point,if the algebraic sum is 0, then the point is outside the polygon; 
//                    if the algebraic sum is 2¦Ð, then the point is inside the polygon;
//                    if the algebraic sum is ¦Ð, then the point is on the polygon.


#include <bits/stdc++.h>
using namespace std;

const int maxn = 100 + 7;
typedef struct {
    double x;
    double y;
}point;
point p1[maxn];
point p[maxn];
point b;
int  n, m; // n is the number of vertices; m is the number of test point
int inpolygon(point t, int n)
{
    int t1, t2, sum, f;
    for (int i = 0; i <= n; i++) {   // move the origin point to t point
        p[i].x = p1[i].x - t.x;
        p[i].y = p1[i].y - t.y;
    }
    t1 = p[0].x >= 0 ? (p[0].y >= 0 ? 0 : 3) : (p[0].y >= 0 ? 1 : 2);  //quadrant judgment;
    sum = 0;
    int i;
    for (i = 1; i <= n; i++) {
        if (!p[i].x && !p[i].y) break;  // a point that coincides with a polygon
        f = p[i].y * p[i - 1].x - p[i].x * p[i - 1].y;
        if (!f && p[i].x * p[i - 1].x <= 0 && p[i].y * p[i - 1].y <= 0) break;  //a point is on an edge of a polygon
        t2 = p[i].x >= 0 ? (p[i].y >= 0 ? 0 : 3) : (p[0].y >= 0 ? 1 : 2); //determine the quadrant of a point
        if (t2 == (t1 + 1) % 4) sum += 1;  //next quadrant
        else if (t2 == (t1 + 3) % 4) sum -= 1; // last quadrant
        else if (t2 == (t1 + 2) % 4) {  //diagonal quadrant
            if (f > 0) sum += 2;
            else sum -= 2;
        }
        t1 = t2;
    }
    if (i <= n || sum) return 1;
    else return 0;
}

int main()
{
    // n is the number of vertices; m is the number of test point
    n = 10, m = 10;

    //input file
    ifstream input;
    input.open("Question 6\\Question 6\\input_question_6_polygon.txt");
    for (int i = 0; i < n; i++) input >> p1[i].x >> p1[i].y;
    p1[n] = p1[0];
    input.close();
    ifstream input2;
    input2.open("Question 6\\Question 6\\input_question_6_points.txt");

    //output file
    ofstream output;
    output.open("Question 6\\Question 6\\output_question_6.txt");
    for (int i = 0; i < m; i++) {
        input2 >> b.x >> b.y;
        if (inpolygon(b, n)) output << b.x << " " << b.y << " inside" << endl;
        else  output << b.x << " " << b.y << " outside" << endl;
    }
    input2.close();
    output.close();

    return 0;
}
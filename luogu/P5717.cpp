#include <bits/stdc++.h>
using namespace std;

int main()
{
    array<int,3> edge;
    bool triangle, Right, Acute, Obtuse, Isosceles, Equilateral;
    cin >> edge.at(0) >> edge.at(1) >> edge.at(2);
    sort(edge.begin(), edge.end());
    int a = edge.at(0), b = edge.at(1), c = edge.at(2);
    triangle = a + b > c;
    Right = (a * a + b * b == c * c);
    Acute = (a * a + b * b > c * c);
    Obtuse = (a * a + b * b < c * c);
    Isosceles = (a == b || b == c);
    Equilateral = (a == b && b == c);
    if (!triangle)
        cout << "Not triangel";
    else{
        if(Right)
            cout << "Right triangle" << endl;
        else if (Acute)
            cout << "Acute triangle" << endl;
        else if (Obtuse)
            cout << "Obtuse triangle" << endl;
        if (Isosceles)
            cout << "Isosceles triangle" << endl;
        if (Equilateral)
            cout << "Equilateral triangle" << endl;
    }
}
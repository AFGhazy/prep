#include<bits/stdc++.h>
using namespace std;

// our precision for getting higher positive numbers
// change if you want more precision
const double EPS = 1e-15;

double closestToZero(const vector<double> & temperatures) {
    if(temperatures.size() == 0) throw invalid_argument("The number of elements is 0 while it should be greater than 0");

    double mn = temperatures[0];
    for(auto tmp: temperatures) {
        if(fabs(mn) > fabs(tmp) || (tmp > EPS && mn < -EPS && fabs(fabs(mn) - tmp) < EPS)) {
            mn = tmp;
        }
    }
    return mn;
}

int main() {
    cout.precision(17);
    cout << closestToZero({-4, 4}) << endl;
    cout << closestToZero({-10, -20, -5, 7}) << endl;
    cout << closestToZero({numeric_limits<int>::min()}) << endl;
    cout << closestToZero({numeric_limits<int>::max()}) << endl;
    cout << closestToZero({numeric_limits<int>::max(), numeric_limits<int>::min()}) << endl;
    cout << closestToZero({numeric_limits<int>::max(), numeric_limits<int>::min() + 2}) << endl;
    cout << closestToZero({numeric_limits<int>::min() + 1, numeric_limits<int>::max()}) << endl;
    cout << closestToZero({0}) << endl;
    cout << closestToZero({-1, 0}) << endl;
    cout << closestToZero({1, 0}) << endl;
    try {
        cout << closestToZero({}) << endl;
    } catch(const exception & e) {
        cerr << e.what() << endl;
    }
    cout << closestToZero({-1.7, 1.7}) << endl;
    cout << closestToZero({-1.7}) << endl;
    cout << closestToZero({-1.69999999999999999997, 1.7}) << endl;
    cout << closestToZero({-1.699999999997, 1.7}) << endl;
    cout << closestToZero({1.699999999997, 1.69999997, 1.699997}) << endl;
    cout << closestToZero({-.00000000000000000001,.000000000000000001}) << endl;
    cout << closestToZero({-.00000000000001,.00000000000001}) << endl;
    cout << closestToZero({-.000000000000001,.000000000000001}) << endl;
    cout << closestToZero({-.0000000000000012,.0000000000000012}) << endl;
    cout << closestToZero({7, -10, 13, 8, 4, -7.2, -12, -3.7, 3.5, -9.6, 6.5, -1.7, -6.2, 7}) << endl;
    cout << closestToZero({0,.0000000000000012}) << endl;
    cout << closestToZero({-5, 5}) << endl;
    cout << closestToZero({5, -5}) << endl;
}
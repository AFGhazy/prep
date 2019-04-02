#include <random>
#include<bits/stdc++.h>
using namespace std;

// 49

// using folding
short parity(unsigned long long x) {
    for(int i = 5; i >= 0; --i) x ^= (x >> (1 << i));
    return x &= 1;
}

void test() {
//    cout << numeric_limits<float>::max() << endl;
//    cout << numeric_limits<float>::min() << endl;
//    default_random_engine engine;
//    uniform_int_distribution<int> dist(1,6);
//    cout << dist(engine) << endl;
//    cout << dist(engine) << endl;
//    cout << dist(engine) << endl;
//    cout << dist(engine) << endl;
//
//    uniform_int_distribution<unsigned long long> dist2(numeric_limits<unsigned long long>::min(), numeric_limits<unsigned long long>::max());
//    cout << dist2(engine) << endl;
//    cout << parity(4) << endl;
//    cout << parity(5) << endl;


}

int main() {
    test();
}

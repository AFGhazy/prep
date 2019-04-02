
#include <random>
#include<bits/stdc++.h>
using namespace std;

// 57


bool isPalindrome(int x) {
        if(x < 0) return false;
        if(x == 0) return true;

        int nOfDigits = floor(log10(x));
        int top = 1;
        while(nOfDigits--) top *= 10;
        while(x) {
            if(x / top != x % 10) return false;
            x = x % top / 10;
            top /= 100;
        }
        return true;
    }

// using folding
short parity(unsigned long long x) {
    for(int i = 5; i >= 0; --i) x ^= (x >> (1 << i));
    return x &= 1;
}



unsigned long long add(unsigned long long a, unsigned long long b) {
    unsigned long long sum = 0, carryin = 0, k = 1, temp_a = a, temp_b = b;
    while(temp_a || temp_b) {
        int ak = a & k, bk = b & k;
        unsigned long long carryout = (ak & bk) | (ak & carryin) | (bk & carryin);
        sum |= (ak ^ bk ^ carryin);
        carryin = carryout << 1, temp_a >>= 1, temp_b >>= 1, k <<= 1;
    }
    return sum | carryin;
}

unsigned long long multiply(unsigned long long x, unsigned long long y) {
    unsigned long long sum = 0;
    while(x) {
        if(x & 0x1) sum = add(sum, y);
        x >>= 1, y <<= 1;
    }
    return sum;
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

    cout << multiply(10, 11) << endl;
}

int main() {
    test();
}

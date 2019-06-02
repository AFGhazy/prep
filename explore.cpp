#include<bits/stdc++.h>
using namespace std;

int main() {
    
    // char * buff = new char[8];
    // cout << sizeof buff << endl;
    // memset(buff, 'a', 8);
    // cout << buff << endl;
    

    // char ** ptrbuff = &buff;

    // cout << (*ptrbuff) << endl;

    // delete[] buff;

    // int val = 5;
    // void * ptr = &val;
    // long long * a = (long long *)ptr;
    // cout << (*a) << endl;


    // int ref = val;
    // int ref2 = val;
    // cout << &ref << endl;
    // cout << &val << endl;
    // cout << &ref2 << endl;
    // cout << &ptr << endl;

    int a[8] = {0};
    int * ptr = a;
    *((char * ) ptr + 12) = 6;
    for(auto b: a) cout << b << endl;

    array<int, 5> t;
    t[3] = 0;
    cout << t.size() << endl;
}
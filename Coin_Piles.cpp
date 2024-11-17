#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
    int p;
    cin >> p;

    while(p--){
        int a, b;
        cin >> a >> b;
        cout << ((a + b)%3 == 0 && 2*a >= b && 2*b >= a? "YES": "NO") << "\n";
    }
}
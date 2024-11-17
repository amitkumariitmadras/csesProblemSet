#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define ll long long

int main() {
   ll n, s =1;
   cin >> n;
   for(int i = 0; i < n; ++i){
    s = 2*s%((int)1e9+7);
   }
   cout << s;
}
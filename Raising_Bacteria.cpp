#include<bits/stdc++.h>
using namespace std;
int bases_2(long long n){
    return (n==1)? 1: n%2 + bases_2(n/2);
}
int main(){
    long long n; cin >> n;
    cout << bases_2(n);
}

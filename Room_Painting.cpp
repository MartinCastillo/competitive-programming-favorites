#include <bits/stdc++.h>
using namespace std;
int main(){
    long n,m;
    cin >> n >> m;
    vector<long> N;
    vector<long> M;
    long aux;
    for(long i = 0; i<n ; i++){
        cin >> aux;
        N.push_back(aux);
    }
    for(long i = 0; i<m ; i++){
        cin >> aux;
        M.push_back(aux);
    }
    sort(N.begin(),N.end());
    long sum=0;
    for(auto a: M){
        sum += (*lower_bound(N.begin(),N.end(),a)-a);
    }
    cout << sum;
}

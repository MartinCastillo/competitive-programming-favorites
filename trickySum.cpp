#include<iostream>
#include<cmath>
#include<queue>
using namespace std;

long long sum_pow(long long n){
    long long sum = 0;
    for(auto i = 0 ;i<=floor(log2(n));i++){
        sum+=pow(2,i);
    }
    return sum;
}

int main()
{
    int t; cin>>t;
    queue<long long> resolutions;
    for(auto tj = 0; tj < t; ++tj ){
        long long  n; cin>>n;
        resolutions.push(n * (n + 1) / 2 - 2 * sum_pow(n));
        
    }
    while(!resolutions.empty()){
        cout << resolutions.front()<<"\n";
        resolutions.pop();
    }
}

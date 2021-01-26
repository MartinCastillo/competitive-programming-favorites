#include <iostream>
#include<cmath>
using namespace std;
int main(){
    long long a,b,c;
    cin >> a >> b >> c;
    if(c!=0){
        if(!((b-a)%c) && ((b-a)/c >= 0)) cout << "YES";
        else cout << "NO";
    }
    else cout << ((a==b)?"YES":"NO");
}

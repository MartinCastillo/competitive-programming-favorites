#include<bits/stdc++.h>
using namespace std;
bool revisar(int r, int n, int exp,int digitos_n){
    cout << r;
    if((exp<=digitos_n)&&(r<=n)){
        int r4 = r+4*pow(10,exp);
        int r7 = r+7*pow(10,exp);
        if(n % r4 ==0 || n % r7 ==0 ){
            return true;//Si el número divide
        }
        else if(revisar(r4,n,exp+1,digitos_n)){
            return true;
        }
        else if(revisar(r7,n,exp+1,digitos_n)){
            return true;
        }
    }
    return false; //Si todos los casos llegan al límite sin solución
}
int main(){
    int n; cin >> n;
    int digitos = log10(n)+1;//digitos
    cout << revisar(0,n,0,digitos);
    return 0;
}

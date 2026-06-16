#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9 + 7;
struct matrix{
    long long a[2][2];
    // constructor
    matrix(){
        a[0][0] = 0;
        a[0][1] = 0;
        a[1][0] = 0;
        a[1][1] = 0;
    }
};

// nhan ma tran
matrix multi(matrix A, matrix B){
    matrix C;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            for(int k = 0; k < 2; k++){
                C.a[i][j] = (C.a[i][j] + (A.a[i][k]*B.a[k][j]))%MOD;
            }
        }
    }
    return C;
}

// luy thua
matrix power(int n){
    matrix base;
    base.a[0][0] = base.a[0][1] = base.a[1][0] = 1;
    base.a[1][1] = 0;
    matrix res;
    res.a[0][0] = res.a[1][1] = 1;
    res.a[0][1] = res.a[1][0] = 0;

    while(n > 0){
        if(n % 2 == 1)res = multi(res, base);
        base = multi(base, base);
        n/=2;
    }
    return res;
}

// tinh fibonacci
long long fibo(int n){
    matrix tmp = power(n-1);
    return tmp.a[0][0];
}

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        cout<<fibo(n)<<endl;
    }
}
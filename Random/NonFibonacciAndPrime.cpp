#include <iostream>       
using namespace std;
int main(){
    int n = 10;
    int m1[n], m2[n], k, t, sk=0;
    bool pirm = true, fib = false;
    for(int i=0; i<n; i++) cin>>m1[i];
    for(int i=0; i<n; i++){
        pirm=true;
        fib=true;
        if(m1[i]==1){
            m2[sk]=m1[i];
            sk++;
        }
        for(int j=2; j<m1[i]; j++){
            if(m1[i]==2){
                m2[sk]=m1[i];
                sk++;
                break;
            }
            else if(m1[i]%j==0 && m1[i]!=2){
                pirm=false;
                m2[sk]=m1[i];
                sk++;
                break;
            }
        }
        if(pirm){
            int s = 0, k=1, t=1;
            while (k<m1[i],t<m1[i]) {
                if(s%2==0){
                    k+=t;
                    if(m1[i]==k){
                        m2[sk]=m1[i];
                        sk++;
                        break;
                    }
                }
                else{
                    t+=k;
                    if(m1[i]==t){
                        m2[sk]=m1[i];
                        sk++;
                        break;
                    }
                }
                s++;
            }
        }
    }
    for(int i = 0; i<sk; i++) cout<<m2[i] <<" ";
}

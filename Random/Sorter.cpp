#include <iostream>       
using namespace std;
int main(){
    n=10;
    int numbers[n], temp;
    bool ok = false;
    for(int i=0; i<n; i++) cin>>sk[i];
    if(n<2) cout<<"Not enough numbers";
    else{
        while (!ok){
            ok=true;
            for(int i=0; i<n; i++){
                if(sk[i]>sk[i+1]){
                    temp=sk[i];
                    sk[i]=sk[i+1];
                    sk[i+1]=temp;
                    ok=false;
                }
            }
        }
    }
}

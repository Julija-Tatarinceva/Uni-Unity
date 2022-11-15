#include <iostream>             
#include <vector>//Used a vector to store the open ones and in case one is closed but doesn't match the currently opened one, it's wrong.
using namespace std;
int main(){
    char arr[21];
    int i = 0;
    vector <char> rn;
    cin>>arr;
    // ([)] ok (-); (([)]) ok (-); ([((]))) ok (-); ((([[]()][]))) ok (+); [()][][[()()]()]  ok (+)
    while(arr[i] != '\0'){
        if(rn.empty() && (arr[i]==']' || arr[i]==')')) {cout << "Wrong! Incorrect order!" << endl; break;}
        if((arr[i]==']' && rn.back() == '(')||(arr[i]==')'&&rn.back()=='[')){
            cout<<"Wrong! Open is "<< rn.back() << ", whereas I get "<<arr[i]<<endl;
            break;
        }
        if((arr[i]==']' && rn.back() == '[')||(arr[i]==')'&&rn.back()=='(')) rn.pop_back();
        if(arr[i]=='(') rn.push_back('(');
        if(arr[i] == '[') rn.push_back('[');
        i++;
    }
    if(rn.empty()) cout << "It's fine!"<<endl;
}

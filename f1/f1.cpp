/* Jūlija Tatarinceva, jt22005
F1. Dots teksta fails f. Uzrakstīt programmu, kura atrod failā f visus vārdus, kas ir apakšvirkne dotajai virknei m. 
Izvadīt šos vārdus failā f1. Par vārdu uzskatīt patvaļīgu simbolu virkni, kas atdalīta ar tukšumiem vai pieturas zīmēm (punkts, komats, 
apaļās iekavas, izsaukuma zīme, jautājuma zīme). Drīkst uzskatīt, ka vārda garums nepārsniedz 40.
Programma izveidota: 2023/02/16 */
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream f ("f.txt", ios::in), f1 ("f1.txt", ios::out);
    char c;
    string word, m;
    cout<<"Ievadiet virkni m: ";
    getline(cin, m);
    f.get(c);
    while (f) {
        if(c!=' ' && c!='.' && c!=',' && c!='(' && c!=')' && c!='!' && c!='?' && c!='\n') word+=c;
        else{
            for(int j = 0; j < m.length(); j++) 
                if(m[j]==word[0])
                    for(int k = 0; k < word.length(); k++){
                        if(k==word.length()-1 && m[j+k]==word[k]){
                            f1<<word<<endl; 
                            word = "";
                        }
                        else if(m[j+k]!=word[k]) break;
                    }
            word = "";
        }
        f.get(c);
    }
    cout<<endl<<"Programma nostradaja."<<endl;
    f.close(); f1.close();
    return 0;
}
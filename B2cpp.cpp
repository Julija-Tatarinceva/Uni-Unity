/*  Jūlija Tatarinceva, jt22005
  B2. Dots naturāls skaitlis n < 1000. Izdrukāt doto skaitli romiešu pierakstā.
  Programma izveidota: 2022/09/18*/
#include <iostream>
#include <string>
using namespace std;
string romanNumber[3]; //this will be filled with roman symbols
string useSymbols[3], RomanSymbols[3][3] = {{"C", "D", "M"}, {"X", "L", "C"}, {"I","V", "X"}}; //symbols for hundreds/dozens/units
int n, i, s, startPoint, redo = 0;
int main(){
    do{
        do{
            cout << "Please enter a natural number:" << endl;
            cin >> n;
            if(n>0 && n<1000) break; //protection against incorrect input
            else cout << "Can not convert.";
        }while (true);
        #pragma region Analysis of the input
        int numberOfChars = to_string(n).length();
        int chars[3];
        chars[0] = n/100; //separating hudreds
        chars[1] = (n / 10)%10; //separating dozens
        chars[2] = n % 10; //separating units
        if (numberOfChars == 2) startPoint = 1; //skipping hudreds/dozens if needed
        else if(numberOfChars == 1) startPoint = 2;
        else startPoint = 0; 
        #pragma endregion
        for(i=startPoint; i<3; i++){ //cycle works 1 to 3 times for each symbol separately
            for(s=0; s<3; s++){ //preparing for conversion
                useSymbols[s] = RomanSymbols[i][s]; //preparing roman symbols
                romanNumber[s] = ""; //clearing the array before converting next part
            }
            if(chars[i] == 5) cout << (romanNumber[i] = useSymbols[1]);
            else if(chars[i] == 4) cout << (romanNumber[i] = useSymbols[0] + useSymbols[1]);
            else if(chars[i] == 9) cout << (romanNumber[i] = useSymbols[0] + useSymbols[2]);
            else if(chars[i] < 5) for (s=0; s<chars[i]; s++) cout << (romanNumber[s] = romanNumber[s] + useSymbols[0]);
            else if(chars[i] > 5){
                romanNumber[i] = useSymbols[1];
                for (s=0; s<chars[i]-5; s++) romanNumber[i] = romanNumber[i] + useSymbols[0];
                cout << romanNumber[i];
            }
        }
        cout << endl << "Would you like to continue(1) or stop(any key) testing?";
        cin >> redo;
    }while (redo==1);
    return 0; 
}/*                  Testa plāns
_________________________________________________
|Ievads|      Rezultāts       |Vai pareizs rez.?|
-------|----------------------|-----------------|
|  0   | can not convert      |        +        |
-------|----------------------|-----------------|
|  7   | VII                  |        +        |
-------|----------------------|-----------------|
|  83  | LXXXIII              |        +        |
-------|----------------------|-----------------|
| 901  | CMI                  |        +        |
¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯*/
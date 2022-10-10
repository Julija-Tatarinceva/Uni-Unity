/* Jūlija Tatarinceva, jt22005
C23. Dots veselu skaitļu masīvs A(n,n). Noskaidrot, vai tas ir latīņu kvadrāts. n-kārtas latīņu kvadrāts ir tāda kvadrātiska matrica,
kuras katra rinda un katra kolonna satur visus skaitļus no 1 līdz n.
Programma izveidota: 2022/10/03 */
#include <iostream>
#include <algorithm>    //random_shuffle
#include <vector>
#include <ctime>
using namespace std;
  int n, i, s, k, shuffled, identicalNum, redo;
  char runUntil;
  vector<int> preA;
  vector<vector<int>> A;
int Shuffler(){
  srand(time(0));
    do{ //cycle for restarting only the shuffling
    identicalNum = 0; //for correct calculations
    random_shuffle (preA.begin(), preA.end()); //attempt to randomly create a latin square
    A.clear();
    for(i=0; i<n; i++, cout << endl){ //converting 1d array to 2d array
      A.push_back(vector<int>());
      for(s = 0; s<n; s++){ 
        A[i].push_back(preA[s+n*i]);
        cout<<A[i][s]<<" ";
      }
    }
    for(i=0; i<n; i++){ //determines row to check for identical values
      for(s=0; s<n; s++){//determines element of the row to compare values to
        int numToCheck = A[i][s]; //this is checked for identical values in the next cycle
        for(k=0; k<n; k++){ //cycles through every element of the previously determined column and row
          if(s!=k) if(numToCheck==A[i][k]) identicalNum++;
          if(i!=k) if(numToCheck==A[k][s]) identicalNum++;
        }
      }
    }
    #pragma region Output //separating all the output 
    if(identicalNum==0){
      cout << "This is a latin square, had to shuffle " << shuffled << " times.";
      runUntil = 's';
      shuffled = 0;
    } 
    else if(shuffled==150){
      runUntil = 's';
      cout << "Shuffled 150 times. Stopped to avoid infinite loop.";
      shuffled = 0;
    }
    else{
      cout << "Not a latin square, has " << identicalNum/2 << " instances of repeating" << endl;
      shuffled++;
    } 
    if(runUntil != 'y'){
      cout << endl << "Enter 1 to keep A(" << n << "," << n << "), 2 to restart everything, anything else to stop." ;
      cin >> redo;
    }
    #pragma endregion
    }while (redo==1);
  return(0);
}
int main(){
  do{ //cycle for restarting the entire code
    redo = 1;//for the cycle in Shuffler
    while (true){ //cycle for checking input
      cout << "Enter number";
      cin >> n;
      if(n>1) break;
      else cout << "Can't create a proper square.";
    }
    shuffled = 0;//for correct calculations
    cout << "Would you like the code to run until hitting a latin square? y/n";
    cin >> runUntil;
    cout<<endl;
    preA.clear();
    for(i=0; i<n; i++) for(s = 0; s<n; s++) preA.push_back(s+1); //creating values to use for the square
    Shuffler();//is called only in the beginning and in case of changing n
  }while (redo==2);
  return 0;
}/*              Testa plāns
 _____________________________________________________________
 |Ievads|  Rezultāts                   |Vai pareizs rezultāts?|
 -------|------------------------------|----------------------|
 |  1   |Can't create a proper square. |          +           |
 -------|------------------------------|----------------------|
 |      |           3 3 2              |                      |
 |  3   |           3 1 1              |          +           |      
 |      |           1 2 2 isn't latin  |                      |
 -------|------------------------------|----------------------|
 |  -1  |Can't create a proper square. |          +           |
 |------|------------------------------|----------------------|*/

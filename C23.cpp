/* 
Jūlija Tatarinceva, jt22005
C23. Dots veselu skaitļu masīvs A(n,n). Noskaidrot, vai tas ir latīņu kvadrāts. n-kārtas latīņu kvadrāts ir tāda kvadrātiska matrica,
kuras katra rinda un katra kolonna satur visus skaitļus no 1 līdz n.
Programma izveidota: 2022/10/03
*/
#include <iostream>     // std::cout
#include <algorithm>    // std::random_shuffle
#include <vector>       // std::vector
#include <ctime>        // std::time
using namespace std;

int main(){
  int n, i, s, k, shuffled = 0, identicalNum, redo = 1;
  char runUntil;
  int **A = new int*[n];
  int *matrix = new int[n];
  vector<int> newVector;
  srand(time(0));

  do{ //cycle for restarting the entire code
    while (true){ //cycle for checking input
      cout << "Enter number";
      cin >> n;
      if(n>1) break;
      else cout << "Can't create a proper square.";
    }
    cout << "Would you like the code to run until hitting a latin square? y/n";
    cin >> runUntil;

    for(i=0; i<n; i++) A[i] = new int[n]; //each row is a new array
    for(i=0; i<n; i++){
      for(s = 0; s<n; s++) newVector.push_back(s+1); //these values will be used for the square
    }
    do{
      identicalNum = 0;
      random_shuffle (newVector.begin(), newVector.end()); //attempt to randomly  create a latin square
      copy(newVector.begin(), newVector.end(), matrix); //1d array is easy co convert to 2d array
      for(i=0; i<n; i++){
        cout << endl;
        for(s = 0; s<n; s++){ //converting 1d array to 2d array
          A[i][s] = matrix[s+n*i];
          cout << A[i][s] << " ";
        }
      }
      cout<<endl;
      for(i=0; i<n; i++){ //determines row to check for identical values
        for(s=0; s<n; s++){//determines element of the row to compare values to
          int numToCheck = A[i][s]; //this is checked for identical values in the next cycle
          for(k=0; k<n; k++){ //cycles through every element of the previously determined column and row
            if(s!=k){
              if(numToCheck==A[i][k]) identicalNum++;
            }
            if(i!=k){
              if(numToCheck==A[k][s]) identicalNum++;
            }
          }
        }
      }
      #pragma region Output
      if(identicalNum==0){
        cout << "This is a latin square, had to shuffle " << shuffled << " times.";
        runUntil = 't';
      } 
      else{
        cout << "Not a latin square, has " << identicalNum/2 << " instances of repeating" << endl;
        shuffled++;
      } 
      if(runUntil != 'y'){
        cout << endl << "Enter 1 to keep A(" << n << "," << n << "), 2 to restart everything." ;
        cin >> redo;
      }
      #pragma endregion
    }while (redo==1);
  }while (redo==2);
}
/*              Testa plāns
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
 |------|------------------------------|----------------------|
 */
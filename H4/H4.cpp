//Jūlija Tatarinceva, jt22005

//H4. Dots teksta fails. Saskaitīt tekstā vārdu biežumu (nešķirojot reģistru). 
//Programmas rezultātā iegūt failu, kurā izdrukāti visi failā sastaptie vārdi pēc to sastapšanas reižu skaita dilstošā secībā 
//(piemēram, the 147, and 101, a 63, he 60, ..., as 18, but 18, utt.). 
//Informācijas glabāšanai pirms izdrukas failā izmantot vārdnīcu (STL) map, kur pēc to sastapšanas biežuma glabājas virknes ar vārdiem (STL list).
//Par vārdu tiek uzskatīta latīņu alfabēta burtu virkne.

#include <fstream>
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main(){
    fstream f1 ("maps.txt", ios::in), f2("mapscount.txt", ios::out);
    map<string, int> vardnica;
    char c; //fails ir nolasīts pa simboliem
    int max = 0, wordCount = 0; string max_str; //izmantots drukāšanai
    string word; //izmantots lasīšanai
    f1.get(c);
    while(f1){ //no faila uz vārdnīcu
        if(!ispunct(c) && !isspace(c)) word+=tolower(c);
        else{
            if(word!=""){
                vardnica[word]++;
                if(vardnica[word]==1) wordCount++;
                word="";
            }
        }
        f1.get(c);
    }
    if(wordCount==0)f2<<"Tukšs ievads!"<<endl;
    for(int j=0; j<wordCount; j++){//mēklējam lielāko vērtību tik reizes, cik ir vārdu vārdnīcā
        int words = wordCount;
        for(auto i: vardnica) {
            words--;
            if(i.second >= max) {//mēklējam lielāko vērtību starp vārdu biežumiem
                max = i.second;
                max_str = i.first;
            }
            if(words==0) { //kad vārdnīca beidzas, tiek izdrukāts viens pāris no vārdnīcas 
                f2<<max_str<<" "<<max<< endl;
                vardnica[max_str] = 0; //lai neizdrukātu šo informāciju atkārtoti, "nonullējam" vārda biežumu
                max = 0;
            }
        }
    }
    cout<<"Viss nolasiits, vaardu biezums izdrukaats failaa!"<<endl;
    if(wordCount==0)cout<<"Pat ja sis biezums ir neeksistejoss... :("<<endl;
    f1.close(); 
    f2.close();
}
 /*                                              Testa plāns
                                ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
______________________________________________________________________________________________________________________________
|                   Ievads                     |                    Rezultāts                         |Vai pareizs rezultāts?|
|______________________________________________|______________________________________________________|______________________|
| The quick brown fox jumped over the lazy dog.|the 4 was 2 fox 2 dog 2 thought 1 quick 1 over 1 not 1|                      |
|The dog was not impressed. The fox thought    |lazy 1 jumped 1 it 1 impressed 1 hilarious 1 brown 1  |           +          |
|it was hilarious.                             |                                                      |                      |
|______________________________________________|______________________________________________________|______________________|
|                                              |Tukšs ievads!                                         |           +          |
|______________________________________________|______________________________________________________|______________________|
|55 44 333 876 fd46 55 333 33 876 8766         |876 2 55 2 333 2 fd46 1 44 1 33 1                     |           +          |
|______________________________________________|______________________________________________________|______________________|

 */

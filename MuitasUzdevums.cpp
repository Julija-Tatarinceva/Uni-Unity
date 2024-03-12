#include <iostream>
#include <fstream>

using namespace std;
class Iebraucejs{
    public:
    Iebraucejs* next = nullptr;
    char tips;
    int ID_inLaiks;
    int outLaiks;
    int muitnieksID;
    Iebraucejs(int id, char type){
        outLaiks = 0;
        muitnieksID = 0;
        ID_inLaiks = id;
        tips = type;
    }
};
class Muitnieks{
    public:
    int ID;
    int darbaLaiks;
    int freeAt = 0;
    Muitnieks* next = nullptr;
    Muitnieks(int id, int laiks){
        ID = id;
        darbaLaiks = laiks;
    }
};

void ChangeDefaultTime(Muitnieks*& first, int id, int newLaiks){
    Muitnieks* curr = first;
    while(true){
        if(curr->ID == id){
            curr->darbaLaiks = newLaiks;
            break;
        }
        else if(curr->next != nullptr) curr=curr->next;
    }
}

void CreateDefaultMuitniekus(Muitnieks*& first, char tips, int amount, int defaultLaiks){
    Muitnieks* curr = nullptr;
    for(int i = 1; i<= amount; i++){
        Muitnieks* created = new Muitnieks(i, defaultLaiks);
        if(curr==nullptr) { 
            curr=created;
            first = curr;
        }
        else{
            curr->next = created;
            curr = created;
        }
    }
}

void HandleGuest(Muitnieks* first, Iebraucejs*& guest){
    Muitnieks* curr = first;
    while(curr != nullptr){
        if(curr->freeAt <= guest->ID_inLaiks){
            curr->freeAt = guest->ID_inLaiks + curr->darbaLaiks;
            guest->outLaiks = guest->ID_inLaiks+curr->darbaLaiks; 
            guest->muitnieksID = curr->ID; 
            return;
        }
        else curr=curr->next;
    }
        int shortest = first->freeAt; 
        Muitnieks* soonerAvailable = first;
        curr = first->next;
        while(curr){
            if(curr->freeAt < shortest){
                shortest = curr->freeAt;
                soonerAvailable = curr;
            }
            curr=curr->next;
        }
        soonerAvailable->freeAt = soonerAvailable->freeAt + soonerAvailable->darbaLaiks;
        guest->outLaiks = soonerAvailable->freeAt;
        guest->muitnieksID = soonerAvailable->ID; 
}

void InsertNewIebr(Iebraucejs*& newOne, Iebraucejs*& first){
    if(first == nullptr) first = newOne;
    else{
        Iebraucejs* previous = nullptr; 
        Iebraucejs* next = first;
        if(newOne->outLaiks < next->outLaiks){ 
            newOne->next = first;
            first = newOne;
        }          
        if(next->next == nullptr){
            next->next = newOne;
            return;
        }       
        while(next != nullptr){
            if(newOne->outLaiks > next->outLaiks || 
                (newOne->outLaiks == next->outLaiks && newOne->tips == 'N' && next->tips == 'P') || 
                (newOne->outLaiks == next->outLaiks && newOne->tips == next->tips && newOne->muitnieksID >= next->muitnieksID)){
                if(previous != nullptr) previous->next = next;
                previous = next; 
                next = next->next;
                previous->next = newOne;
                newOne->next = next;
            }
            else return;
        }
    }
}

int main(){
    ifstream fin("customs.in");
    fstream fout("customs.out", ios::out);
    char c;
    int mPsk, mNsk, mPdefL, mNdefL, num;
    fin>>mPsk; fin>>mNsk; fin>>mPdefL; fin>>mNdefL;
    Muitnieks* firstP = nullptr;
    Muitnieks* firstN = nullptr;
    Iebraucejs* first = nullptr;
    CreateDefaultMuitniekus(firstP,'P', mPsk, mPdefL);
    CreateDefaultMuitniekus(firstN,'N', mNsk, mNdefL);
    fin>>c;
    while(c=='T'){
        fin.get(c); fin.get(c);
        if(c=='P'){
            fin>>c; fin>>num; 
            ChangeDefaultTime(firstP, c-'0', num);
        }
        if(c=='N'){
            fin>>c; fin>>num;
            ChangeDefaultTime(firstN, c-'0', num);
        }
        fin.get(c); fin.get(c);
    }
    while(c!='X'){
        fin>>num; 
        if(c=='P'){
            Iebraucejs* created = new Iebraucejs(num, 'P');
            HandleGuest(firstP, created);
            InsertNewIebr(created, first);
        }
        if(c=='N'){
            Iebraucejs* created = new Iebraucejs(num, 'N');
            HandleGuest(firstN, created);
            InsertNewIebr(created, first);
        }
        fin>>c;
    }
    if(first == nullptr)fout<<"nothing"<<endl;
    else  
        while(first != nullptr){
            fout<<first->ID_inLaiks<<" "<<first->outLaiks<<" "<<endl;
            first = first->next;
        }
    delete first; delete firstN; delete firstP;
}
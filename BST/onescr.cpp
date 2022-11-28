/* Uzdevums 21.: uzrakstīt programmu, kas saskaita vārdu lietojuma biežumu failā, izmantojot bināru meklēšanas koku,
kura mezglos glabājas vārds un tā sastapšanas biežums. Izdrukāt failā sastaptos vārdus alfabētiskā secībā
un to lietojuma biežumu. Par vārdu uzskatīt simbolu virkni, kas sastāv no latīņu alfabēta burtiem.
Jūlija Tatarinceva jt22005 */

#include <iostream>
#include <string>
#include <strings.h>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <stdio.h>
using namespace std;

struct Node{
    char *data;
    Node* left;
    Node* right;
    int biezums;
};
Node* GetNewNode(char *data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = 0;
    newNode->biezums = 1;
    //cout<<"Created node: " << data<<endl;
    return newNode;
}
Node* Insert(Node* root, char *data){
    if(root==0) root = GetNewNode(data);
    else if(strcmp(data, root->data)==0) root->biezums++;
    else if(strcmp(data, root->data)<0) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}
bool Searchh(Node* root, char *data){
    if(root == 0){cout<<"Root not set"<<endl; return false;}
    else if(root->data[0]==data[0]) return true;
    else if (data[0] <= root->data[0]) {cout<<"Lesser"<<endl;return Searchh(root->left, data);}
    else {cout<<"Bigger"<<endl;return Searchh(root->right, data);}
}

bool printAll(Node* root){
    if(root->left != NULL){
            printAll(root->left); // kad šī rinda beidz izpildīties, visi kreisie no šī punkta mezgli būs izdrukāti
            cout<<root->data<<"("<<root->biezums<<"), "; //tikai kad visi kriesie ir izdrukāti, var izdrukāt arī šo
            if(root->right !=NULL) printAll(root->right); //kad ir izdrukāts viss no krieisas puses un pats mezgls, var drukāt visu kas ir labāk no tā
    }
    else if(root->left == NULL){
        cout<<root->data<<"("<<root->biezums<<"), ";
        if(root->right !=NULL) printAll(root->right);
    }
    return false;
}

int main(){
    fstream file;
    char *lookfor;
    int notAWord = 0;
    Node* root = 0;
    file.open("tpoint.txt",ios::in);
    string tp;
    vector<string> dats;
    while(getline(file, tp, ' ')) dats.push_back(tp);
    file.close();
    for(int i=0;i<dats.size();i++){
        for(int j=0;j<dats[i].size(); j++){
            if(dats[i][j]>64 && dats[i][j]<90) dats[i][j]=dats[i][j]+32; //A = a, cits burtu lielums != cits vārds
            if(dats[i][dats[i].length() - 1]==44 || dats[i][dats[i].length() - 1]==33 ||     //ja ar šo vārdu beidzas teikums un pēc tā seko '!',
               dats[i][dats[i].length() - 1]==46 || dats[i][dats[i].length() - 1]==58 ||     //'.' vai cits līdzīgs simbols, tad to vajadzēs ignorēt.
               dats[i][dats[i].length() - 1]==59 || dats[i][dats[i].length() - 1]=='?') dats[i].pop_back();
            if(dats[i][j]<65 || (dats[i][j]>90&&dats[i][j]<97)||dats[i][j]>122){ //vārds satur tikai ASCII burtus
                notAWord++;
                if(i<dats.size()-1) i++;
                else{
                    cout<<"Printing everything in alfabetical order:"<<endl;
                    printAll(root);
                    return 1; //
                }
                j=0;
            }
        }
        root = Insert(root,(char*)dats[i].c_str());
    }
    cout<<"Printing everything in alfabetical order:"<<endl;
    printAll(root);
    while (0){
        cout<<"search for: ";
        cin>>lookfor;
        cout<<endl<<Searchh(root, lookfor);
    }
    return 1;
}

#include <iostream>
#include <string>
#include <strings.h>
#include <ctype.h>
#include <vector>
#include <fstream>
#include <stdio.h>
#include "prgrm.h"
using namespace std;

BST::BST(){
    fstream file;
    int i = 0;
    file.open("tpoint.txt",ios::in);
    string tp;
    vector<string> dats;
    while(getline(file, tp, ' ')){
         dats.push_back(tp);
    }
    file.close();
    for(i=0;i<dats.size();i++){
            if(dats[i][0]>64 && dats[i][0]<90) dats[i][0]=dats[i][0]+32;
            if(dats[i][dats[i].length() - 1]==44 || dats[i][dats[i].length() - 1]==33 ||
               dats[i][dats[i].length() - 1]==46 || dats[i][dats[i].length() - 1]==68 ||
               dats[i][dats[i].length() - 1]==59 || dats[i][dats[i].length() - 1]=='('||
               dats[i][dats[i].length() - 1]==')'|| dats[i][dats[i].length() - 1]=='['||
               dats[i][dats[i].length() - 1]==']'|| dats[i][dats[i].length() - 1]=='?') dats[i].pop_back();
            root = Insert(root,(char*)dats[i].c_str());
    }
    cout<<"Fails izlasiits!"<<endl;
}
BST::~BST(){
    cout<<"Finished executing."<<endl;
}
BST::Node* BST::GetNewNode(char *data){
    Node* newNode = new Node();
    newNode->data = data;
    newNode->left = newNode->right = 0;
    newNode->biezums = 1;
    //cout<<"Created node: " << data<<endl;
    return newNode;
}
BST::Node* BST::Insert(Node* root, char *data){
    if(root==0) root = GetNewNode(data);
    else if(strcmp(data, root->data)==0) root->biezums++;
    else if(strcmp(data, root->data)<0) root->left = Insert(root->left, data);
    else root->right = Insert(root->right, data);
    return root;
}
bool BST::Searchh(Node* root, char *data){
    if(root == 0){cout<<"Root not set"<<endl; return false;}
    else if(root->data[0]==data[0]) return true;
    else if (data[0] <= root->data[0]) {cout<<"Lesser"<<endl;return Searchh(root->left, data);}
    else {cout<<"Bigger"<<endl;return Searchh(root->right, data);}
}
BST::printA(){
    printAll(root);
}
BST::printAll(Node* root){
    if(root->left != NULL){
            printAll(root->left);
            cout<<root->data<<"("<<root->biezums<<"), ";
            if(root->right !=NULL){
            printAll(root->right);
        }
    }
    else if(root->left == NULL){
        cout<<root->data<<"("<<root->biezums<<"), ";
        if(root->right !=NULL){
            printAll(root->right);
        }
    }
}

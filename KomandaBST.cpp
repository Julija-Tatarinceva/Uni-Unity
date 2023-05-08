#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int trust;
    int id;
};
Node* GetNewNode(int num){
    Node* newNode = new Node();
    newNode->id = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int leastTrust = 0;
Node* Insert(Node *root, int num){
    if(!root) {cout<<"inserting-"<<num; root = GetNewNode(num); root->trust=0;}
    else if(root->left) {
        cout<<"woman is, going down to "<<root->id; 
        root->right = Insert(root->right, num); 
        root->right->trust=root->trust+1;
        if(root->right->trust>leastTrust)leastTrust=root->right->trust;
    }
    else {
        cout<<"man is, going down to "<<root->id; 
        root->left = Insert(root->left, num); 
        root->left->trust=root->trust+1;
        if(root->left->trust>leastTrust)leastTrust=root->left->trust;
    }
    return root;
}

Node* FindingNemo(Node* root, int num){
    if(root == NULL)
		return NULL;
	if(root->id == num)
		return root;
    Node *node1, *node2;
    node1 = FindingNemo(root->left, num);
	if(node1)
		return node1;
	node2 = FindingNemo(root->right, num);
    return node2;
}

bool printAll(Node* root){
    if(root->left != NULL){
            printAll(root->left); // kad šī rinda beidz izpildīties, visi kreisie no šī punkta mezgli būs izdrukāti
            cout<<"["<<root->id<<"-"<<root->trust<<"]"; //tikai kad visi kriesie ir izdrukāti, var izdrukāt arī šo
            if(root->right !=NULL) printAll(root->right); //kad ir izdrukāts viss no krieisas puses un pats mezgls, var drukāt visu kas ir labāk no tā
    }
    else if(root->left == NULL){
        cout<<"["<<root->id<<"-"<<root->trust<<"]";
        if(root->right !=NULL) printAll(root->right);
    }
    return false;
}

bool printAll(Node* root, int level){
    if(root->left != NULL){
        printAll(root->left, level); // kad šī rinda beidz izpildīties, visi kreisie no šī punkta mezgli būs izdrukāti
        if(root->trust==level)cout<<root->id<<" "; //tikai kad visi kriesie ir izdrukāti, var izdrukāt arī šo
        if(root->right !=NULL) printAll(root->right, level); //kad ir izdrukāts viss no krieisas puses un pats mezgls, var drukāt visu kas ir labāk no tā
    }
    else if(root->left == NULL){
        if(root->trust==level)cout<<root->id<<" ";
        if(root->right !=NULL) printAll(root->right,level);
    }
    return false;
}

int main(){
    fstream file("teamin.txt", ios::in);
    int num;
    Node* root = NULL;
    Node* first = NULL;
    file>>num;
    root = Insert(root, num);
    first = root;
    root->trust = 0;
    file>>num;
    Insert(root, num);
    file>>num;
    Insert(root, num);
    file>>num;
    while (file){
        root = FindingNemo(first, num);
        file>>num;
        Insert(root, num);
        file>>num;
        Insert(root, num);
        file>>num;
    }
    cout<<leastTrust;
    for(int i=leastTrust; i>=0; i--){
        cout<<endl<<"Level "<<i<<": ";
        printAll(first, i);
    }
}

#include <iostream>
#include <fstream>
using namespace std;

struct Node{
    Node* left;
    Node* right;
    int trust = 0;
    int id;
};

struct HangedNode{
    Node* hanged;
    HangedNode* next;
};

fstream fout("teamout.txt", ios::out);
Node* GetNewNode(int num){
    Node* newNode = new Node();
    newNode->id = num;
    newNode->left = newNode->right = NULL;
    return newNode;
}
int leastTrust = 0;
Node* Insert(Node *root, int num){
    if(!root) {root = GetNewNode(num); root->trust=0;}
    else if(root->left) {
        root->right = Insert(root->right, num); 
        root->right->trust=root->trust+1;
        if(root->right->trust>leastTrust)leastTrust=root->right->trust;
    }
    else {
        root->left = Insert(root->left, num); 
        root->left->trust=root->trust+1;
        if(root->left->trust>leastTrust)leastTrust=root->left->trust;
    }
    return root;
}

Node* FindingInviter(Node* root, int num){
    if(root == NULL)
		return NULL;
	if(root->id == num)
		return root;
    Node *node1, *node2;
    node1 = FindingInviter(root->left, num);
	if(node1)
		return node1;
	node2 = FindingInviter(root->right, num);
    return node2;
}

bool printAll(Node* root, int level){
    if(root->left != NULL){
        printAll(root->left, level); // kad šī rinda beidz izpildīties, visi kreisie no šī punkta mezgli būs izdrukāti
        if(root->trust==level)fout<<root->id<<" "; //tikai kad visi kriesie ir izdrukāti, var izdrukāt arī šo
        if(root->right !=NULL) printAll(root->right, level); //kad ir izdrukāts viss no kreisas puses un pats mezgls, var drukāt visu kas ir labāk no tā
    }
    else if(root->left == NULL){
        if(root->trust==level)fout<<root->id<<" ";
        if(root->right !=NULL) printAll(root->right,level);
    }
    return false;
}

bool printAllF(Node* root){
    if(root->left){
            if(root->left->trust == root->trust){if(leastTrust==root->left->trust) leastTrust=root->left->trust+1; root->left->trust++;}
            printAllF(root->left); // kad šī rinda beidz izpildīties, visi kreisie no šī punkta mezgli būs izdrukāti
            cout<<"["<<root->id<<"-"<<root->trust<<"]"; //tikai kad visi kriesie ir izdrukāti, var izdrukāt arī šo
            if(root->right !=NULL) {
                if(root->right->trust == root->trust){if(leastTrust==root->right->trust) leastTrust=root->right->trust+1; root->right->trust++;}
                printAllF(root->right);
        }  //kad ir izdrukāts viss no krieisas puses un pats mezgls, var drukāt visu kas ir labāk no tā
    }
    else if(!root->left){
        cout<<"["<<root->id<<"-"<<root->trust<<"]";
        if(root->right !=NULL){
            if(root->right->trust == root->trust){if(leastTrust==root->right->trust) leastTrust=root->right->trust+1; root->right->trust++;}
            printAllF(root->right);
        } 
    }
    return false;
}


HangedNode* firstHanged = NULL;
Node* hangingNode(int num){
    Node* newNode = GetNewNode(num);
    if(!firstHanged){
        firstHanged = new HangedNode();
        firstHanged->hanged = newNode;
    }
    else{
        HangedNode* temp = firstHanged;
        while(1){
            if(temp->next)temp=temp->next;
            else {
                temp->next=new HangedNode();
                temp->next->hanged = newNode;
                break;
            }
        }
    }
    //cout<<"hanged "<<newNode->id<<endl;
    return newNode;
}


Node* FindingInvited(int num){
    HangedNode* temp = firstHanged;
    if(!temp) return NULL;
    while(temp){
        //cout<<"looking for hanged "<<num;
        Node* itIsHanged = FindingInviter(temp->hanged, num);
        if(itIsHanged) return itIsHanged;
        else if(temp->next)temp=temp->next;
        else return NULL;
    }
    return NULL;
}

Node* LookingForFirst(Node* root, int num){
    if(root == NULL)
		return NULL;
        //cout<<"looking for first lost "<<num<<" in "<<root->id<<endl;
	if(root->left){
        if(root->left->id==num) return root;
    }
    if(root->right){
        if(root->right->id==num) return root;
    }
    Node *node1, *node2;
    node1 = FindingInviter(root->left, num);
	if(node1)
		return node1;
	node2 = FindingInviter(root->right, num);
    return node2;
}

Node* FindFirst(int num){
    HangedNode* temp = firstHanged;
    Node* itIsHanged = NULL;
    if(!temp) return NULL;
    while(temp){
        //cout<<"looking for first in hanged "<<num;
        if(temp->hanged->left || temp->hanged->left) itIsHanged = LookingForFirst(temp->hanged, num);
        if(itIsHanged){ return itIsHanged;}
        else if(temp->next)temp=temp->next;
        else return NULL;
    }
    return NULL;
}

int main(){
    fstream file("teamin.txt", ios::in);
    int num;
    Node* root = NULL;
    Node* first = NULL;
    file>>num;
    while (file){
        root = FindingInvited(num);
        if(!root) root=hangingNode(num);
        if(!first) first = root;
        file>>num;
        if(num!=0){
            Node* nodeTemp = FindingInvited(num);
            if(nodeTemp){
                if(nodeTemp==first){
                    first=root;
                }
                root->left = nodeTemp;
                root->left->trust = root->trust+1;
            }
            else Insert(root, num);
        }
        file>>num;
        if(num!=0){
            Node* nodeTemp = FindingInvited(num);
            if(nodeTemp){
                //cout<<nodeTemp->id<<" already invited, connecting to "<<root->id<<endl;
                if(nodeTemp==first){
                    first=root;
                }
                root->right = nodeTemp;
                root->right->trust = root->trust+1;
                //cout<<nodeTemp->id<<" already invited, connected as "<<root->right->id<<" to "<<root->id<<endl;
            }
            else Insert(root, num);
        }
        file>>num;
        if(num==0) break;
    }
    Node* temp = FindFirst(first->id);
    while(temp){
        first=temp;
        temp = FindFirst(first->id);
    }
    printAllF(first);
    cout<<leastTrust;
    for(int i=leastTrust; i>=0; i--){
        fout<<i<<": ";
        printAll(first, i);
        fout<<endl;
    }
}

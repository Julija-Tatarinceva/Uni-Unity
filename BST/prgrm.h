#ifndef PRGRM_H
#define PRGRM_H
using namespace std;

class BST{
    private:
        struct Node{
        char *data;
        Node* left;
        Node* right;
        int biezums;
        };
        Node* root = 0;
    public:
        BST();
        ~BST();
        printA();
        printAll(Node* root);
        Node* GetNewNode(char *data);
        Node* Insert(Node* root, char *data);
        bool Searchh(Node* root, char *data);
        bool printAll();
};
#endif

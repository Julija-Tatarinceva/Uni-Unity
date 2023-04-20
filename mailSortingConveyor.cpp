#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

struct elem{
	elem* next;
	string vieta;
};
bool flag = false;
void sorter(elem *&root, elem *&first){
	if(root->next){
		if(tolower(root->vieta[0])<=tolower(root->next->vieta[0])){sorter(root->next, first); return;}
		flag = true;
		if(root == first){
			elem *p = first; elem *p1 = root->next;
			first = p1;
			p->next = p1->next;
			first->next = p;
			sorter(first->next, first);
		}
		else{
			elem *p = root; elem *p1 = root->next;
			root = p1;
			p->next = p1->next;
			root->next = p;
			sorter(root->next, first);
		}
	}
	else if(flag){flag = false; sorter(first, first);}
}

int main()
{
	fstream fin("post.in", ios::in), fout("post.out", ios::out);
	char c; string word = "";
	elem *last,  *first = NULL;
	fin.get(c);
	while(fin){
		while(fin && c!=' ' && c!='\n'){
			word+=c;
			fin.get(c);
		}
		if((c==' '|| c=='\n' || !fin) && word!=""){
			elem* p = new elem;
			p->vieta = word;
			if(!first) {
				first = p;
				last = first;
			}
			else if(first == last){
				first = p;
				first->next=last;
				last->next = NULL;
			}
			else{
				elem *k = first;
				first = p;
				first->next = k;
			}
			word = "";
		}
		fin.get(c);
	}
	if(!first) fout<<"nothing";
	else{
		sorter(first, first);
		elem *pir=first;
		pir=first;
		fout<<pir->vieta<<" ";
		while(pir->next){
			pir=pir->next;
			fout<<pir->vieta<<" ";
		}
	}
	fin.close(); fout.close();
}

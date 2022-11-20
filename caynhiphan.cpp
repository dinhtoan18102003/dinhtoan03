#include <iostream>
using namespace std;

struct tNode{
	int data;
	tNode *pLeft, *pRight;
};

tNode *root;

tNode *newNode(int data){
	tNode *node = new tNode;
	node->data = data;
	node->pLeft = NULL;
	node->pRight = NULL;
	return node;
}

void insertNode(tNode *p, int value){
	tNode *node = newNode(value);
	if (p->pLeft == NULL){
		p->pLeft = node;
	}else if (p->pRight == NULL) {
		p->pRight = node;
	}else{
		node->pLeft = p->pLeft;
		p->pLeft = node;
	}
}

void insertNewRoot(int value){
	tNode *node = newNode(value);
	node->pLeft = root;
	root = node;
}

void NLR(tNode *root){
	if(root!=NULL){
			if(root!=NULL){
				cout<<root->data<<" ";
			}
			NLR(root->pLeft);
			NLR(root->pRight);
	}
}

void LNR(tNode *root){
	if(root!=NULL){
		LNR(root->pLeft);
		if(root!=NULL){
			cout<<root->data<<" ";
		}
		LNR(root->pRight);
	}
}

void LRN(tNode *root){
	if(root!=NULL){
		LRN(root->pLeft);
		LRN(root->pRight);
		if(root!=NULL){
			cout<<root->data<<" ";
		}
	}
}

int main()
{

	root = newNode(1);
	tNode *node2 = newNode(2);
	tNode *node3 = newNode(3);
	tNode *node4 = newNode(4);
	tNode *node5 = newNode(5);
	tNode *node6 = newNode(6);
	tNode *node7 = newNode(7);
	root->pLeft = node2;
	root->pRight = node3;
	node2->pLeft = node4;
	node2->pRight = node5;
	node5->pLeft = node6;
	node5->pRight = node7;
	cout<<"duyet thu tu NLR:";
	NLR(root);
	cout<<"\nduyet thu tu LNR:";
	LNR(root);
	cout<<"\nduyet thu tu LRN:";
	LRN(root);
	insertNode(node2, 9);
	cout<<"\nduyet thu tu NLR:";
	NLR(root);
	system("pause");
}

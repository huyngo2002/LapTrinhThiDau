#include <iostream>
struct node {
	int data;
	node *pLeft, *pRight;
};
int n;
int a[105];
node *root;

node *createNode(int data) {
	node *ret = new node();
	ret->data = data;
	ret->pLeft = NULL;
	ret->pRight = NULL;
	return ret;
}

void addNode(int data) {
	node *p = root;
	while (p != NULL) {
		if (data < p->data) {
			if (p->pLeft == NULL) {
				p->pLeft = createNode(data);
				return;
			} else {
				p = p->pLeft;
			}
		} else {
			if (p->pRight == NULL) {
				p->pRight = createNode(data);
				return;
			} else {
				p = p->pRight;
			}
		}
	}
}

bool findNode(int data) {
	node *p = root;
	while (p != NULL) {
		if (data == p->data) {
			return true;
		} else if (data < p->data) {
			p = p->pLeft;
		} else {
			p = p->pRight;
		}
	}
	return false;
}



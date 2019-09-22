#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
	int key;
	node *right;
	node *left;
	node(int key){
		this->key = key;
		left = NULL;
		right = NULL;
	}
};

class tree
{
public:
	node *root;
	node *insert(node *n, int key){
		if(n == NULL){
			n = new node(key);
			return n;
		}else if(n->key >= key){
			n->left = insert(n->left, key);
		}else{
			n->right = insert(n->right, key);
		}
		return n;
	}
	tree(){
		root = NULL;
	}
	tree(node *root){
		this->root = root;
	}
};

int main(int argc, char const *argv[])
{
	tree *t = new tree();
	int n;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		int q;
		cin>>q;
		t->root = t->insert(t->root, q);
	}
	int k, cnt = 0;
	cin>>k;
	node *target = t->root;
	while(target!=NULL){
		if(target->key < k){
			if(cnt!=0){
				break;
			}
			target = target->right;
		} else
			if(target->key > k){
				if(cnt!=0){
					break;
				}
				target = target->left;
			} else 
				if(target->key == k){
					cnt++;
					target = target->left;
				}
	}
	cout<<cnt;
}
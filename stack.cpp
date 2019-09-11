#include <iostream>
using namespace std;

template <typename T>
class node{
public:
	node *next;
	node *prev;
	T value;
	node(T x){
		next = NULL;
		prev = NULL;
		value = x;
	}
};

template <typename T>
class stack{
	
	public:
		node<T> *head, *tail;
		int size;
		stack(){
		size = 0;
		head = NULL;
		tail = NULL;
		}
		void push(T x){
			node<T> *n = new node<T>(x);
			if(head==NULL){
				head = tail = n;
			} else{
				tail->prev = n;
				n->next = tail;
				tail = n;
			}
			size++;
		}
		bool isEmpty(){
			return size==0;
		}
		void pop(){
			if(head!=NULL){
				tail = tail->next;
				size--;
			}
		}
		void print(){
			node<T> *n = tail;
			while(n!=NULL){
				cout<<n->value<<endl;
				n = n->next;
			}
		}
		void clear(){
			head = NULL;
			tail = NULL;
			size = 0;
			cout<<"ok"<<endl;
		}
};

int main(){
	stack<int> *s = new stack<int>();
	string ask;
	while(cin>>ask){
		if(ask=="push"){
			int a;
			cin>>a;
			s->push(a);
			cout<<"ok"<<endl;
		}
		if(ask=="pop"){
			if(s->tail != NULL)
			cout<<s->tail->value<<endl;

			s->pop();
		}
		if(ask=="back"){
			if(s->tail != NULL)
			cout<<s->tail->value<<endl;
		}
		if(ask == "size"){
			cout<<s->size<<endl;
		}
		if(ask=="clear"){
			s->clear();
			cout<<"ok"<<endl;
		}
		if(ask=="exit"){
			cout<<"bye"<<endl;
			exit(0);
		}
	}
}
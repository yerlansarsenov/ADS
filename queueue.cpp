#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

template <typename T>
class node{
public:
	node *next;
	node *prev;
	T value;
	node(T x){
		value = x;
		next = NULL;
		prev = NULL;
	}
};

template <typename T>
class queue{
public:
	node<T> *head, *tail;
	int size;
	queue(){
		head = NULL;
		tail = NULL;
		size = 0;
	}
	bool isEmpty(){
		return size==0;
	}
	void push_back(T x){
		node<T> *n = new node<T>(x);
		if(head==NULL){
			head = tail = n;
		} else{
			n->next = tail;
			tail->prev = n;
			tail = n;
		}
		size++;
	}
	void pop(){
		if(head!=NULL){
			head = head->prev;
			size--;
		}
	}
	void print(){
		node<T> *n = head;
		while(n != NULL){
			cout<<n->value<<endl;
			n = n->prev;
		}
	}
	void push_front(T x){
		node<T> *n = new node<T>(x);
		if(head==NULL){
			head = tail = n;
		} else{
			head->next = n;
			n->prev = head;
			head = n;
		}
		size++;
	}
	void clear(){
		head = NULL;
		tail = NULL;
		size = 0;
		cout<<"ok"<<endl;
	}
};

int main(){
	queue<int> *q = new queue<int>();
	string ask;
	while(cin>>ask){
		if(ask=="push"){
			int a;
			cin>>a;
			q->push_back(a);
			cout<<"ok"<<endl;
		}
		if(ask=="pop"){
			if(q->head != NULL)
			cout<<q->head->value<<endl;

			q->pop();
		}
		if(ask=="front"){
			if(q->head != NULL)
			cout<<q->head->value<<endl;
		}
		if(ask == "size"){
			cout<<q->size<<endl;
		}
		if(ask=="clear"){
			q->clear();
			cout<<"ok"<<endl;
		}
		if(ask=="exit"){
			cout<<"bye"<<endl;
			exit(0);
		}
	}
}
#include<iostream>
using namespace std;
//QUEUE AS AN CIRCULAR ARRAY IMPLEMENTATION
struct Node{					//QUEUE AS CIRCULAR ARRAY ADT
	int data;
	struct Node *next;
};
struct Queue{
	struct Node *f,*r;
};
Queue *Create(int size){		//RETURNS QUEUE POINTER
	struct Queue *q;			//TC : O(1)
	q=(Queue*)malloc(sizeof(Queue));
	q->f=q->r=nullptr;
	return q;
}
int isEmpty(Queue *q){			//RETURNS TRUE IF QUEUE IS EMPTY
	if(q->r==nullptr)			//TC : O(1)
		return 1;
	else 
		return 0;
}
void EnQueue(Queue *q,int data){	//ADDS ELEMENT TO REAR OF QUEUE
	struct Node *curr;				//TC : O(1)
	curr=(Node*)malloc(sizeof(Node));
	curr->data=data;
	curr->next=nullptr;
	if(q->f==nullptr)
		q->f=q->r=curr;
	else {
		q->r->next=curr;
		q->r=curr;
	}
}
int DeQue(Queue *q){			//REMOVES ELEMENT FROM FRONT
	if(isEmpty(q)){				// TC : O(1)
		cout<<"UnderFlow";
		return 0;
	}
	int k;
	struct Node *temp;
	temp=(Node*)malloc(sizeof(Node));
	temp=q->f;
	if(q->f==q->r)
		q->f=q->r=nullptr;
	else 
		q->f=q->f->next;
	k=temp->data;
	free(temp);
	return k;
}
int Qsize(Queue *q){			//RETURNS SIZE OF QUEUE
	struct Node *temp;			// TC : O(N)
	temp=(Node*)malloc(sizeof(Node));
	if(isEmpty(q))
		return 0;
	else {
		int i=0;
		temp=q->f;
		while(temp!=nullptr){
			i++;
			temp=temp->next;
		}
		return i;
	}
}
void print_all(Queue *q){		//PRINTS ALL ELEMENTS OF QUEUE
	struct Node *temp;			// TC : O(N)
	temp=(Node*)malloc(sizeof(Node));
	if(!isEmpty(q)){
		temp=q->f;
		cout<<"FRONT : ";
		while(temp!=nullptr){
			cout<<temp->data<<"->";
			temp=temp->next;
		}
		cout<<"REAR\n";
	}
}
void delQ(Queue *q){			//DEALLOCATES QUEUE
	struct Node *temp=(Node*)malloc(sizeof(Node));
	while(q->f){				//TC : O(1)
		temp=q->f;
		q->f=q->f->next;
		free(temp);
	}
	free(q->f);
	free(q->r);
	free(q);
}

int main(){
	struct Queue *q;
	q=Create(5);
	EnQueue(q,1);
	EnQueue(q,2);
	EnQueue(q,3);
	EnQueue(q,4);
	EnQueue(q,6);
	print_all(q);
	DeQue(q);
	DeQue(q);
	DeQue(q);
	print_all(q);
	EnQueue(q,3);
	EnQueue(q,4);
	EnQueue(q,5);
	print_all(q);
	return 0;
}
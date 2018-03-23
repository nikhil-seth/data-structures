#include<iostream>
using namespace std;
//DOUBLY LINKED LIST TRAVERSEL, INSERTION, DELETITION 
struct DLL{
	int data;
	struct DLL *next;
	struct DLL *prev;
};

void ins_beg(struct DLL **head,int data){			//INSERTS DATA AT STARTING
	struct DLL *a;									//TIME COMPLEXITY : O(1)
	a=(DLL*)malloc(sizeof(DLL));
	a->data=data;
	a->next=*head;
	a->prev=nullptr;
	*head=a;
}
void print_all(struct DLL *head){					//PRINTS ALL ELEMENTS IN LIST
	struct DLL *curr=head;							//TIME COMPLEXITY : O(N)
	while(curr!=NULL){
		cout<<curr->data<<"-> ";
		curr=curr->next;
	}
}
int traverse(struct DLL *head){					//PRINTS ALL ELEMENTS IN LIST
	struct DLL *curr=head;							//TIME COMPLEXITY : O(N)
	int count=0;
	while(curr!=NULL){
		curr=curr->next;
		count++;
	}
	return count;
}
void ins_end(struct DLL **head,int data){		//INSERTS THE VALUE AT END OF LIST
	struct DLL *a,*curr;						//TIME COMPLEXITY : O(N)
	curr=*head;
	if(head==nullptr){
		ins_beg(head,data);
	}
	else {
		a=(DLL*)malloc(sizeof(DLL));
		a->data=data;
		while(curr->next!=nullptr){
				curr=curr->next;
		}
		a->prev=curr;
		a->next=nullptr;
		curr->next=a;
	}
}
DLL * NthNode(struct DLL *head,int posn){		//RETURNS NTH NODE
	struct DLL *curr;							//TIME COMPLEXITY :O(N)
	curr=head;
	while(posn>1){
		posn--;
		curr=curr->next;
	}
	return curr;
}
void ins_posn(struct DLL **head,int posn,int data){		//INSERTS ELEMENT AT SPECIFIED POSITION
	struct DLL *a,*curr,*curr2;							//TIME COMPLEXITY : O(N)
	a=(DLL*)malloc(sizeof(DLL));
	if(posn==1){
		ins_beg(head,data);
	}
	else {
		curr=NthNode(*head,posn-1);
		curr2=curr->next;
		a->data=data;
		a->next=curr2;
		a->prev=curr;
		curr->next=a;
		curr2->prev=a;
	}
}
void del_beg(struct DLL **head){				//DELETES AT STARTING
	*head=(*head)->next;						//TIME COMPLEXITY :O(1)
	(*head)->prev=nullptr;
}
void del_end(struct DLL **head){				//DELETE ELEMENT AT END
	struct DLL *curr=*head;						//TIME COMPLEXITY : O(N)
	while(curr->next->next!=NULL)
		curr=curr->next;
	curr->next=nullptr;
}
void del_posn(struct DLL **head,int posn){		//DELETES ELEMENT AT NTH POSITION
	if(posn==1){								//TIME COMPLEXITY :O(N)
		del_beg(head);
	}
	else {
		struct DLL *curr;
		curr=NthNode(*head,posn-1);
		curr->next=curr->next->next;
		curr->next->prev=curr;
	}
}
int main(){
	struct DLL *head=nullptr;
	print_all(head);
	system("pause");
}
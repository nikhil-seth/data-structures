#include<bits/stdc++.h>
using namespace std;

struct LL{									//ADT FOR SINGLELY LINKED LIST
	int data;
	struct LL *link;
	};
void print_all(struct LL *head){			//PRINTS ALL ELEMENTS
	struct LL *curr=head;					//TIME COMPLEXITY :O(N)
	while(curr!=NULL){
		cout<<curr->data<<"->";
		curr=curr->link;
	}
	cout<<"NULL\n";
}
int count(struct LL *head){					//TRAVERSAL FUNCTION ,RETURNS NO OF OBJECTS
	struct LL *curr=head;					//TIME COMPLEXITY : O(N)
	if(curr==NULL){
		return 0;
	}
	while(curr!=NULL){
		return 1+count(curr->link);
	}
}

LL* end_Obj(struct LL *head){				//RETURNS END OBJECT's POINTER.
	struct LL *curr=head;					//TIME COMPLEXITY : O(N)
	while(curr->link!=NULL){
		curr=curr->link;
	}
	return curr;
}

LL *ins_beg(struct LL *head,int data){					//INSERTS AT HEAD POSITION
	struct LL *a=(struct LL*)malloc(sizeof(struct LL)); //TIME COMPLEXITY : O(1)
	a->data=data;
	a->link=head;
	head=a;
	cout<<"Inserted Successfully\n";
	return head;
}

LL *ins_end(struct LL *head,int data){					//INSERTS THE DATA AT END of the list 
	struct LL *a,*b;									//TIME COMPLEXITY : O(N)
	a=(LL*)malloc(sizeof(LL));
	a->data=data;
	a->link=NULL;
	b=end_Obj(head);
	b->link=a;
	cout<<"Entered Successfully\n";
	return head;
}
LL *Nth_Node(struct LL *head,int n){					//RETURNS NTH NODE
	struct LL *curr=head;								//TIME COMPLEXITY : O(N)
	while(n>1&&curr!=NULL){
		n--;
		curr=curr->link;
	}
	if(n>1){
		return nullptr;
	}
	else{
	return curr;
	}
}
LL *ins_middle(struct LL *head,int data,int posn){		//INSERTS AT SPECIFIED POSITON
	struct LL *a,*b;									//TIME COMPLEXITY :O(N)
	a=(LL*)malloc(sizeof(LL));
	a->data=data;
	b=Nth_Node(head,posn-1);
	a->link=b->link;
	b->link=a;
	cout<<"Inserted Successfully at : "<<posn<<endl;
	return head;
}
LL* del_beg(struct LL *head){						//DELETES FROM BEGINNING
	head=head->link;								//TIME COMPLEXITY :O(!)
	return head;
}
LL *del_end(struct LL *head){						//DELETES FROM END
	struct LL *curr=head;							//TIME COMPLEXITY : O(N)
	while(curr->link->link!=NULL){
		curr=curr->link;
	}
	curr->link=NULL;
	return head;
}
LL *del_middle(struct LL *head,int posn){			//DELETES FROM BETWEEN
	struct LL *curr;								//TIME COMPLEXITY : O(N)
	curr=Nth_Node(head,posn-1);
	curr->link=curr->link->link;
	return head;
}
int main(){
	struct LL* head=NULL;
	
	system("pause");

	return 0;
}

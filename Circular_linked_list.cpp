#include<iostream>
using namespace std;

struct CLL{											//STRUCTURE ADT DEFINATION FOR CIRCULAR LINKED LIST
	int data;
	struct CLL *link;
};
int traverse(struct CLL *head){						//RETURNS TOTAL ELEMENTS IN LINKED LIST
	int count=1;									//TIME COMPLEXITY : O(N)
	struct CLL *curr=head;
	if(head==nullptr)
		return 0;
	while(curr->link!=head)
		count++;
	return count;
}
void ins_front(struct CLL **head,int data){			//ADDS ELEMENT AT HEAD POSITION
	struct CLL *curr,*a;							//TIME COMPLEXITY : O(N)
	curr=*head;
	a=(CLL*)malloc(sizeof(CLL));
	a->data=data;
	a->link=a;
	if(*head==nullptr)
		*head=a;
	else{
		a->link=*head;
		while(curr->link!=*head)
			curr=curr->link;
		curr->link=a;
		*head=a;
	}
}
void ins_end(struct CLL **head,int data){			//ADDS ELEMENT AT END OF CLL
	struct CLL *curr,*a;							//TIME COMPLEXITY : O(N)
	a=(CLL*)malloc(sizeof(CLL));
	curr=*head;
	a->data=data;
	a->link=a;
	if(*head==nullptr){
		*head=a;
	}
	else {
		while(curr->link!=*head){
				curr=curr->link;
			}
		a->link=*head;
		curr->link=a;
		}
}
CLL *NthNode(struct CLL *head,int posn){			//RETURNS NTH NODE OF CLL
	struct CLL *curr;								// TIME COMPLEXITY : O(N)
	curr=head;
	while(posn>1&& curr->link!=head){
		curr=curr->link;
	}
	return curr;
}
void ins_posn(struct CLL **head,int data,int posn){	//INSERTS ELEMENT AT POSN SPECIFIED	
	struct CLL *curr,*a;							//TIME COMPLEXITY :O(N)
	a=(CLL*)malloc(sizeof(CLL));
	a->data=data;
	a->link=a;
	if(posn==1){
		ins_front(head,data);
	}
	else{
		curr=NthNode(*head,posn-1);
		a->link=curr->link;
		curr->link=a;
	}
}
void print_all(struct CLL *head){					//PRINTS ALL THE ELEMENTS IN CLL
	struct CLL *curr;								//TIME COMPLEXITY :O(N)
	curr=head;
	if(head!=nullptr){
		do {
			cout<<curr->data<<"->";
			curr=curr->link;
			}while(curr!=head);
		cout<<endl;
	}
}
void del_first(struct CLL **head){					//DELETES HEAD ELEMENT
	struct CLL *curr,*temp;							//TIME COMPLEXITY :O(N)
	if(*head==nullptr)
		return;
	temp=*head;
	curr=*head;
	if(curr->link==curr){
		*head=nullptr;
		return;
	}
	while(curr->link!=*head)
		curr=curr->link;
	curr->link=(*head)->link;
	*head=(*head)->link;
	free(temp);
	return;
}
void del_end(struct CLL **head){				//DELETES LAST ELEMENT FROM CLL
	struct CLL *curr,*temp;						//TIME COMPLEXITY: O(N)
	if(*head==nullptr){
		return;
	}
	if((*head)->link==*head)
		{temp=*head;
		free(*head);
		*head=nullptr;
		return;
}
	while(curr->link->link!=*head){
		curr=curr->link;
	}
	temp=curr->link;
	curr->link=temp->link;
	free(temp);
}
void del_list(struct CLL **head){				//FREES ALL SPACE & HENCE DELETES CLL
	struct CLL *temp,*curr=*head;				//TIME COMPLEXITY : O(n)
	if(*head==nullptr){
		return;
	}
	while(curr->link!=*head){
		temp=curr;
		curr=curr->link;
		free(temp);
	}
	*head=nullptr;
}
 int main(){
 	struct CLL *head;
 	head=nullptr;
 	ins_end(&head,1); 	
 	
 	print_all(head);
 	del_end(&head);system("pause"); 	
 	print_all(head);
 	system("pause");
 	del_list(&head);

 }
 
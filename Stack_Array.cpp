#include<iostream>
using namespace std;
#define MAXSIZE 100
struct StackArray{								//STRUCTURE OF STACK ARRAY
	int size;
	int top;
	int *array;
};

StackArray *Create(){							//FUNCTION WHICH ALLOCATES MEMORY FOR STACK
	struct StackArray *S;
	S=(StackArray*)malloc(sizeof(StackArray));
		S->size=MAXSIZE;
		S->top=-1;
		S->array=(int*)malloc(MAXSIZE*sizeof(int));
	return S;
}
void Push(struct StackArray *S,int data){		//PUSH FUNCTION INSERTS ELEMENT TO STACK
	if(S->top+1>=MAXSIZE){
		cout<<"overFlow";
		return;
	}
	S->array[++(S->top)]=data;
	cout<<"ADDED SUCCESSFULLY\n";
}
int Pop(struct StackArray *S){					//POP ELEMENT DELETES TOP ELEMENT FROM STACK
	if(S->top==-1){
		cout<<"UnderFlow\n";
		return 0;
	}
	return S->array[S->top--];
}
void DelStack(struct StackArray *S){			//FREES MEMORY FROM STACK
	if(S){
		if(S->array)
			free(S->array);
		free(S);
	}
}
void viewStack(struct StackArray *S){			//PRINTS ALL ELEMENTS OF STACK
	int i=S->top;
	if(i==-1)
		cout<<"UnderFlow\n";
	else{
		while(i>-1){
			cout<<S->array[i]<<"\n";
			i--;
		}

	}
}
int main(){
	//struct StackArray *S;
	//S=Create();
	//DelStack(S);
	return 0;
}
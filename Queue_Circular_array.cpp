#include<iostream>
using namespace std;
//QUEUE AS AN CIRCULAR ARRAY IMPLEMENTATION
struct Queue{					//QUEUE AS CIRCULAR ARRAY ADT
	int f,r;
	int size;
	int *array;
};
Queue *Create(int size){		//RETURNS QUEUE POINTER
	struct Queue *q;			//TC : O(1)
	q=(Queue*)malloc(sizeof(Queue));
	q->size=size;
	q->f=q->r=-1;
	q->array=(int*)malloc(sizeof(int)*q->size);
	return q;
}
int isEmpty(Queue *q){			//RETURNS TRUE IF QUEUE IS EMPTY
	if(q->r==q->f&&q->r==-1)	//TC : O(1)
		return 1;
	else return 0;
}
int isfull(Queue *q){			//RETURNS TRUE IF QUEUE IS FULL
	if((q->r+1)%q->size==q->f)		//TC : O(1)		//other cond  : (r+1+f)/size==1
		return 1;
	else 
		return 0;
}
void EnQueue(Queue *q,int data){	//ADDS ELEMENT TO REAR OF QUEUE
	if(isfull(q)){					//TC : O(1)
		cout<<"OverFlow\n";
		return;
	}
	else {
		q->r=(q->r+1)%q->size;
		if(q->f==-1)
			q->f=q->r;
		q->array[q->r]=data;
	}
}
int DeQue(Queue *q){			//REMOVES ELEMENT FROM FRONT
	if(isEmpty(q)){				// TC : O(1)
		cout<<"UnderFlow";
		return 0;
	}
	else{
		int temp;
		temp=q->array[q->f];
		if(q->f==q->r)
			q->f=q->r=-1;
		else
			q->f=(q->f+1)%q->size;
		return temp;
	}
}
int Qsize(Queue *q){			//RETURNS SIZE OF QUEUE
	if(isEmpty(q))				// TC : O(N)
		return 0;
	else 
		return (q->size - q->f + q->r +1)%q->size;
}
void print_all(Queue *q){		//PRINTS ALL ELEMENTS OF QUEUE
	if(isEmpty(q)){				// TC : O(N)
		cout<<"UnderFlow";
		return;
	}
	int i=q->f;
	cout<<"FRONT->";
	while(i!=q->r){
		cout<<q->array[i]<<"->";
		i=(i+1)%q->size;
	}
	cout<<q->array[i]<<"->REAR\n";
}
void delQ(Queue *q){			//DEALLOCATES QUEUE
	if(q){						//TC : O(1)
		free(q->array);
	}
	free(q);

}

int main(){
	return 0;
}
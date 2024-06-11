#include<iostream>
using namespace std;
class Stack{
	private:
		int size;
		int top;
		int arr[100];
		public:
		Stack(){
			size = 0;
			top=-1;
		}
		void push(){
			if(top<99){
				int num;
				cout<<"Enter the number: ";
				cin>>num;
				top =top+1;
				arr[top]=num;
				size++;
			}
			else{
				cout<<"Stack full!"<<endl;
			}
		}
		void pop(){
			if(top>=0){
				top=top-1;
			    size=size-1;
			    cout<<"Element poped!"<<endl;
			}
			else{
				cout<<"Empty!"<<endl;
			}
		}
		void display(){
			int i;
			for(i=0;i<size;i++){
				cout<<" "<<arr[i];
			}
		}
};
class Queue{
	private:
		int size;
		int low;
		int high;
		int arr[100];
		public:
		Queue(){
			size=0;
			low=0;
			high=-1;
		}
		
		void enqueue(){
			if(high<99){
				int element;
				cout<<"Enter element to enqueue: ";
				cin>>element;
				high=high+1;
				arr[high]=element;
				size=size+1;
			}
			else {
				cout<<"Queue is full !"<<endl;
			}
		}
		void dequeue(){
			if(low<=high){
				low=low+1;
				size=size-1;
				cout<<"Element dequed "<<endl;
			}
			else{
				cout<<"Empty!"<<endl;
			}
		}
		void display(){
			int i;
			if(low<=high){
				for(i=low;i<=high;i++){
				cout<<" "<<arr[i];
			}
		}
			else{
				cout<<"empty!";
			}
			
		}
};
int main(){
	Stack s;
	Queue q;
	int choice, choice1,choice2;
	cout<<"1.Stack"<<endl<<"2.Queue"<<endl;
	cin>>choice;
	if(choice==1){
		do{
			cout<<endl<<"1.PUSH"<<endl;
			cout<<"2.POP"<<endl;
			cout<<"3.DISPLAY"<<endl;
			cout<<"4.EXIT"<<endl;
			cin>>choice1;
			if(choice1==1){
				s.push();
			}
			else if(choice1==2){
				s.pop();
			}
			else if(choice1==3){
				s.display();
			}
		}
		while(choice1!=4);
	}
	else if(choice=2){
		do{
			cout<<endl<<"1.ENQUEUE"<<endl;
			cout<<"2.DEQUEUE"<<endl;
			cout<<"3.DISPLAY"<<endl;
			cout<<"4.EXIT"<<endl;
			cin>>choice2;
			if(choice2==1){
				q.enqueue();
			}
			else if(choice2==2){
				q.dequeue();
			}
			else if(choice2==3){
				q.display();
			}
		}
		while(choice2!=4);
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct Staff {
	int id;
	string name;
	string faculty;
	int age;
};

class Stack {
private:
	int size;
	int idx;
	Staff *staffs;

public:
	Stack(int size) {
		this->size = size;
		idx = 0;
		staffs = new Staff[size];
	}

	bool isEmpty() {
		if(idx-1<0) return true;
		else return false;
	}

	bool isFull() {
		if(idx==size) return true;
		else return false;
	}

	void Push(int id, string name, string faculty, int age) {
		if(isFull()) cout<<"STACK IS FULL"<<endl;
		else {
			Staff staff;
			staff.id = id;
			staff.name = name;
			staff.faculty = faculty;
			staff.age = age;

			staffs[idx] = staff;
			idx++;
			cout<<"PUSH COMPLETE"<<endl;	
		}		
	}

	Staff Pop() {
		if(isEmpty()) cout<<"STACK IS EMPTY"<<endl;
		else return staffs[idx--];
	}

	Staff Top() {
		if(isEmpty()) cout<<"STACK IS EMPTY"<<endl;
		else return staffs[idx];
	}

	void DisplayStack() {
		cout<<"top-->";
		for (int i = idx; i >= 0; i--) {
			cout<<"\t|"<<staffs[i].name<<" "<<staffs[i].id<<" "<<staffs[i].faculty<<" "<<staffs[i].age<<"|"<<endl;
		}
		cout<<"\t|---------BOTTOM STACK---------|"<<endl;
	}
};

int main() {
	Stack s(3);
	if(!s.isEmpty()) cout<<"Stack is not empty"<<endl;
	else cout<<"Stack is empty"<<endl;
	s.Push(149,"Zulfakar","Law",50);
	s.Push(637,"Ooi Ji Woo","Agriculture",42);
	s.Push(721,"Abdullah","Economics",26);
	s.DisplayStack();
	s.Pop();
	s.Top();
	s.DisplayStack();
	return 0;
}
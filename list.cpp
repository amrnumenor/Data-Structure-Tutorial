#include<bits/stdc++.h>
using namespace std;
const int MAX = 10;

struct Staff {
	string name;
	int staffID;
	string faculty;
	int age;
};

class StaffArray {
private:
	int index;
	Staff list[MAX];

public:
	StaffArray() {                 //constructor
		this->index = 0;
	}
	void Insert(int staf, string nam, string fac, int ag);
	void Delete(int i);
	void PrintList();
	void DeleteID(int id);
	int FindID(int id);
	// void Insert(int staf, string nam, string fac, int ag) {
	// 	if(index == MAX) cout<<"ARRAY IS FULL"<<endl;
	// 	else {
	// 		this->list[index].staffID = staf;
	// 		this->list[index].name = nam;
	// 		this->list[index].faculty = fac;
	// 		this->list[index].age = ag;
	// 		index++;
	// 		cout<<"INSERTED"<<endl;
	// 	}
	// }
};

void StaffArray::Insert(int staf, string nam, string fac, int ag) {
	if(index == MAX) cout<<"ARRAY IS FULL"<<endl;
	else {
		this->list[index].staffID = staf;
		this->list[index].name = nam;
		this->list[index].faculty = fac;
		this->list[index].age = ag;
		index++;
		cout<<"INSERTED"<<endl;
	}
}

void StaffArray::Delete(int i) {
	if (i >=MAX && i<0) {
		cout<<"INDEX OUT OF BOUNDS"<<endl;
	}

	else {
		for(int pos=i; pos<index-1; pos++) {
			this->list[pos].name = list[pos+1].name;
			this->list[pos].staffID = list[pos+1].staffID;
			this->list[pos].faculty = list[pos+1].faculty;
			this->list[pos].age = list[pos+1].age;
		}
		index--;
		cout<<"DELETED"<<endl;
	}
}

void StaffArray::DeleteID(int id) {
	int pos;
	bool flag;

	for(int i=0; i<index-1; i++) {
		if(list[i].staffID == id) {
			pos = i;
			flag = true;
			break;
		}
	}

	if (flag) {
		for (int i=0; i<index-1; i++) {
			list[i].name = list[i+1].name;
			list[i].staffID = list[i+1].staffID;
			list[i].faculty = list[i+1].faculty;
			list[i].age = list[i+1].age;
		}
		cout<<"DELETED"<<endl;
		--index;
	}
	else cout<<"NOT FOUND"<<endl;
}

void StaffArray::PrintList() {
	cout<<"Staff details: "<<endl;
	for (int i=0; i<index; i++) {
		cout<< "\tID: " <<list[i].staffID<<endl;
		cout<< "\tName: " <<list[i].name<<endl;
		cout<< "\tFaculty: " <<list[i].faculty<<endl;
		cout<< "\tAge: " <<list[i].age<<endl;
		cout<<"---------------------------"<<endl;
	}
	cout<<endl;
}

int StaffArray::FindID(int id) {
	int pos;
	bool flag;

	for(int i=0; i<index-1; i++) {
		if(list[i].staffID == id) {
			pos = i;
			flag = true;
			break;
		}
	}

	if(flag) return pos;
	else -1;
}
int main() {
	StaffArray sa;
	sa.Insert(143,"Min Ho","Medicine",30);
	sa.Insert(437,"Ji Woo","Agriculture",42);
	sa.Insert(321,"Fattah","Aeronautic",26);
	sa.PrintList();
	sa.Delete(1);
	sa.DeleteID(143);
	sa.PrintList();
	sa.FindID(321)!=-1 ? cout<<"Found at index "<<sa.FindID(321)<<endl :
				cout<<"Employee ID is not valid"<<endl;

	// Staff list[3] = {{"Min Ho",143,"Medicine",30},
	// 	   			 {"Ji Woo",437,"Agriculture",42},
	// 				 {"Fattah",321,"Aeronautic",26}};
 
	// for (int i=0; i<3; i++)
	// 	cout<<list[i].name<<" "
	// 	    <<list[i].faculty<<endl;
}
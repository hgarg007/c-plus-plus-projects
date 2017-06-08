#include"ui.h"
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<iomanip>
using namespace std;

void UI::displayMainMenu() {
	cout<<"\n\t\t\t\tEmployee Management System";
	cout<<"\n\t\t1. Add employee details";
	cout<<"\n\t\t2. View employee details";
	cout<<"\n\t\t3. Update employee details";
	cout<<"\n\t\t4. Delete employee details";
	cout<<"\n\t\t5. Backup/View of details";
	cout<<"\n\t\t6. Search employee from backup";
	cout<<"\n\n\n\t>>Enter 0 for exit.";
}

int UI:: getInitiateOption() {
	int x;
	cout<<"\n\tEnter your choice:";
	cin>>x;
	return x;
}

int UI::getId(){ 
	int id,c=1;
	do {
		if(c==1) {
		cout<<"\n Enter Employee's Id :";
		cin>>id;
		}
		else {
		cout<<"\nInvalid id.Enter again.";
		cin>>id;
		}
		c=validateId(id);
	}while(c==-1);
	return id;
}

int UI::validateId(int id){ 
	if (id>=1000&&id<=2000)
		return 1;
	else 
		return -1;
}

int UI::validateAge(int age){

	if ((age>=18) && (age<=60))
		return 1;
	else 
		return -1;
}

int UI::validateName(string name){
	for(int i=0;name[i]!='\0';i++){ 
		if(!((name[i]>='a'&&name[i]<='z')||(name[i]>='A'&&name[i]<='Z')||(name[i]==' ')))
		return -1;
	}
	return 1;
}


int UI::validateAddress(string address){
	for(int i=0;address[i]!='\0';i++){ 
		if(!((address[i]>='a'&&address[i]<='z')||(address[i]>='A'&&address[i]<='Z')||(address[i]==' ') || (address[i]>='0' && address[i] <='9') ))
		return -1;
	}
	return 1;
}


int UI::validateDesignation(string designation){
	if((designation=="manager")||(designation=="worker") || (designation=="Manager")||(designation=="Worker")) {
	/*	if((designation[0]=='m') || (designation[0]=='w'))
			designation[0]+= 32;*/
		return 1;
	}
	else 
		return -1;
}


int UI::validateContactNumber(string num){ 
	if(num.length()==10) {
		if((num[0]>'6')&&(num[0]<='9')) {
			for(int i=1;i<10; i++){
				if(!((num[i]>='0')&&(num[i]<='9')))
					return -1;
			}	
		}
		else
			return -1;
	}
	else
		return -1;
	
	return 1;
}

int UI::validateGender(char h) {
	if ((h=='m')||(h=='M')||(h=='f')||(h=='F'))
		return 1;
	else
		return -1;	
}

int UI::validateViewOption(int i) {
	if((i==1)||(i==2))
		return 1;
	else
		return -1;
}

void UI::displayEmpDetails(Employee emp) {
	
	cout<<"\n\t\t\t\tEmployee Details\n\n\n";
	cout<<setw(10)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Age"<<setw(20)<<"Designation"<<setw(30)<<"Address"<<setw(15)<<"Mob No."<<setw(10)<<"Gender"<<endl;
	cout<<setw(10)<<emp.getEmpId()<<setw(15)<<emp.getEmpName()<<setw(10)<<emp.getEmpAge()<<setw(20)<<emp.getEmpDesignation()<<setw(30)<<emp.getEmpAddress()<<setw(15)<<emp.getEmpContactNumber()<<setw(10)<<emp.getEmpGender()<<endl;
}

void UI::displayErrorId() {
	cout<<"\nInvalid Id.\nEnter again :";
}

void UI::displayErrorIdMismatch() {
	cout<<"\nEmployee does not exist.";
}

void UI::displayAllEmpDetails(vector<Employee> empList) {
	cout<<"\n\t\t\t\tEmployee Details\n\n\n";
	cout<<setw(10)<<"ID"<<setw(15)<<"Name"<<setw(10)<<"Age"<<setw(20)<<"Designation"<<setw(30)<<"Address"<<setw(15)<<"Mob No."<<setw(10)<<"Gender"<<endl;
	
	for(int i=0;i<empList.size();i++) {
		cout<<setw(10)<<empList[i].getEmpId()<<setw(15)<<empList[i].getEmpName()<<setw(10)<<empList[i].getEmpAge()<<setw(20)<<empList[i].getEmpDesignation()<<setw(30)<<empList[i].getEmpAddress()<<setw(15)<<empList[i].getEmpContactNumber()<<setw(10)<<empList[i].getEmpGender()<<endl;
	}
}
int UI::getViewOption() {
	int option,flag;
	cout<<"\n\t1.View Employee Details by entering Id.";
	cout<<"\n\t2.View all Employees' Details.";
	cout<<"\n\tEnter your choice :";
	do {
		cin.clear();
		cin.ignore();
		cin>>option;
		flag=1;
		if(validateViewOption(option)==-1) {
			flag=0;
			displayErrorOption();
		}
	}while(flag==0);
	return option;
}
void UI::displayErrorOption() {
	cout<<"\nInvalid Option.\nEnter again :";
}

void UI::displayEmpSearchBackupSuccess(Employee emp1) {
	displayEmpDetails(emp1);
}

struct EmployeeStruct UI::getEmpDetails() {
	int age;
	string name,address,designation,number;
	char gender;
	
	int c=1;
	cout<<"\n\tEnter details of an employee :";
	do {	
		if(c==1) {
		
			cout<<"\n\tName :";
			cin.ignore();
			getline(cin,name);
		}
		else {
			cout<<"\n\tInvalid name.\n\tEnter again :";
			cin.ignore();
			getline(cin,name);
		}
		c=validateName(name);
	}while(c== -1);

	c=1;
	do {	
		if(c==1) {
		
			cout<<"\n\tAge :";
			cin>>age;
		}
		else {
			cout<<"\n\tInvalid age.\n\tEnter again  :";
			cin>>age;
		}
		c=validateAge(age);
	}while(c== -1);

	c=1;	
	do {	
		if(c==1) {
		
			cout<<"\n\tGender(M/F) :";
			cin>>gender;
		}
		else {
			cout<<"\n\tInvalid gender.\n\tEnter again(M/F):";
			cin>>gender;
		}
		c=validateGender(gender);
	}while(c== -1);

	c=1;	
	do {	
		if(c==1) {		
			cout<<"\n\tDesignation :";
			cin.ignore();
			getline(cin,designation);
		}
		else {
			cout<<"\n\tInvalid designation.\n\tEnter again :";
			//cin.ignore();
			getline(cin,designation);
		}
		c=validateDesignation(designation);
	}while(c==-1);
	
	c=1;
	do {	
		if(c==1) {
		
			cout<<"\n\tAddress :";
			cin.ignore();
			getline(cin,address);
		}
		else {
			c=1;
			cout<<"\n\tInvalid address.\n\tEnter again :";
			cin.ignore();
			getline(cin,address);
		}
		c=validateAddress(address);
	}while(c==-1);

	c=1;	
	do {	
		if(c==1) {
		
			cout<<"\n\tContact Number :";
			cin>>number;
		}
		else {
			c=1;
			cout<<"\n\tInvalid number.\n\tEnter again :";
			cin>>number;
		}
		c=validateContactNumber(number);
	}while(c==-1);

	struct EmployeeStruct empStruct;	
	empStruct.name=name;
	empStruct.age=age;
	empStruct.designation=designation;
	empStruct.address=address;
	empStruct.gender=gender;
	empStruct.contactNumber=number;
		
	return empStruct;
}

void UI::displayAddEmpSuccess(int id) {
	cout<<"\n\tEmployee with ID "<<id<<" added successfully.";
}

void UI::displayErrorDetails() {
	cout<<"\n\tInvalid Data provided.\n";
}

void UI::displayErrorEmpRepeat() {
	cout<<"\nEmployee already exists.\n";
}

void UI::displayDeleteEmpSuccess() {
	cout<<"\n\tEmployee details deleted successfully.";
}

void UI::displayUpdateSuccess() {
	cout<<"\n\tEmployee details updated successfully.";
}
int UI::getBackupOption() {
	int choice,c=1;
	cout<<"\n\t1. Manual Backup";
	cout<<"\n\t2. View details from backup";
	do {
		if(c==1) {
			cout<<"\n\tEnter your choice :";
			cin>>choice;
		}
		else {
			cout<<"\n\tInvalid choice.\nEnter again :";
			cin>>choice;
		}	
		c=validateViewOption(choice);
	}while(c==-1);
	
	return choice;
}
void UI::displayBackupSuccess() {
	cout<<"\n\tBackup Successful.";
}

struct EmployeeStruct UI:: getUpdateDetails() {
	int x,age=-1;
	string name="@" ;
	string address="@";
	string designation="@";
	string number="@";
	char gender ='@';
	int c;
	
	while(1) {
		cout<<"\n\t1. Name";
		cout<<"\n\t2. Age";
		cout<<"\n\t3. Gender";
		cout<<"\n\t4. Designation";
		cout<<"\n\t5. Contact Number";
		cout<<"\n\t6. Address";
		cout<<"\n\t7. Exit";
		cout<<"\n\n\n\t>>Enter your choice to update corresponding details :";
		cin>>x; 
		
		switch(x) {
			case 1: {
					c=1;
					do {	
						if(c==1) {
				
							cout<<"\n\tEnter name :";
							cin.ignore();
							getline(cin,name);
						}
						else {
							cout<<"\n\tInvalid name.\n\tEnter again :";
							cin.ignore();
							getline(cin,name);
						}
						c=validateName(name);
					}while(c==-1);
				}
				break;

			case 2:	{
					c=1;
					do {	
						if(c==1) {
				
							cout<<"\n\tEnter Age :";
							cin>>age;
						}
						else {
							cout<<"\n\tInvalid age.\n\tEnter again  :";
							cin>>age;
						}
						c=validateAge(age);
					}while(c==-1);
				}
				break;	

			case 3: {
					c=1;	
					do {	
						if(c==1) {
			
							cout<<"\n\tEnter Gender(M/F) :";
							cin>>gender;
						}
						else {
							cout<<"\n\tInvalid gender.\n\tEnter again(M/F):";
							cin>>gender;
						}
						c=validateGender(gender);
					}while(c==-1);
				}
				break;
			
			case 4:	{
					c=1;	
					do {	
						if(c==1) {
			
							cout<<"\n\tEnter Designation :";
							cin.ignore();
							getline(cin,designation);
						}
						else {
							cout<<"\n\tInvalid designation.\n\tEnter again :";
							cin.ignore();
							getline(cin,designation);
						}
						c=validateDesignation(designation);
					}while(c==-1);
				}
				break;
		
			case 6: {
					c=1;
					do {	
						if(c==1) {
			
							cout<<"\n\tEnter Address :";
							cin.ignore();
							getline(cin,address);
						}
						else {
							cout<<"\n\tInvalid address.\n\tEnter again :";
							cin.ignore();
							getline(cin,address);
							cin.ignore();
						}
						c=validateAddress(address);
					}while(c==-1);
				}
				break;

			case 5: {
					c=1;	
					do {	
						if(c==1) {
			
							cout<<"\n\tEnter Contact Number :";
							cin.ignore();
							cin>>number;
						}
						else {
							cout<<"\n\tInvalid number.\n\tEnter again :";
							cin.ignore();
							cin>>number;
						}
						c=validateContactNumber(number);
					}while(c==-1);
				}
				break;
			case 7: 
					break;
			default:
				cout<<"\nInvalid choice.";
				break;
				
		}
		if(x==7)
			break;
	}

		struct EmployeeStruct empStruct;
		empStruct.name=name;
		empStruct.age=age;
		empStruct.gender=gender;
		empStruct.designation=designation;
		empStruct.contactNumber=number;
		empStruct.address=address;
		return empStruct;
}	

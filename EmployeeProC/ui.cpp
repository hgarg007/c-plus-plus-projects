#include"ui.h"
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<cctype>
#include<iomanip>
#include<cstdlib>
#include<iomanip>


using namespace std;

void UI::displayMainMenu() {


	system("clear");
	cout<<"\n";
	cout<<"+------------------------------------------------------+\n";
	cout<<"|                                                      |\n";
	cout<<"|\tEmployee Management System                     |\n";
	cout<<"|                                                      |\n";
	cout<<"+------------------------------------------------------+\n\n\n";
	
	cout<<"+------------------------------------------------------+\n";
	cout<<"|\t\t1. Add employee details      \t \t|";
	cout<<"\n|\t\t2. View employee details     \t \t|";
	cout<<"\n|\t\t3. Update employee details   \t \t|";
	cout<<"\n|\t\t4. Delete employee details   \t \t|";
	cout<<"\n|\t\t5. Backup/View of details    \t \t|";
	cout<<"\n|\t\t6. Search employee from backup\t\t|\n";
	cout<<"+------------------------------------------------------+\n";
	cout<<"\n\n\n\t>>Enter 0 for exit.\n";
	cout<<"\n---------------------------------------------------";
	
	
	
}

void UI::takeEnter() {
	cout<<"\n\n\t>>Press enter to continue.";
	cin.get();
	cin.ignore(256,'\n');
}

int UI:: getInitiateOption() {
	int x;


	cout<<"\n\n\tEnter your choice: ";
	cin>>x;
	return x;
}

int UI::getId(){ 
	int id,c=1;
	do {
		if(c==1) {
		cout<<"\n\n\t Enter Employee's Id :\t\t";
		cin>>id;
		}
		else {
		cout<<"\n\tInvalid id.Enter again.\t\t";
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
		if(!((address[i]>='a'&&address[i]<='z')||(address[i]>='A'&&address[i]<='Z')||(address[i]==' ') || (address[i]>='0' && address[i] <='9')) )
		return -1;
	}
	return 1;
}


int UI::validateDesignation(string designation){
	if((designation=="manager")||(designation=="worker") || (designation=="Manager")||(designation=="Worker")) {
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
	if((i==1)||(i==2)||(i==3))
		return 1;
	else
		return -1;
}

string UI::getName() {
string name;
cout<<"\n\tEnter Name :";
cin>>name;
return name;
}

void UI::displayEmpDetails(Employee emp)
	{
	cout<<"\n\t\t\t\tEmployee Details\t\t \n";
       	cout<<"+----------------------------------------------------------------------------------------------------------------+\n";


 cout<<"|"<<"ID"<<setw(10)<<"Name"<<setw(25)<<"Age"<<setw(15)<<"Designation"<<setw(25)<<"Address"<<setw(15)<<"Mob No."<<setw(15)<<"Gender  \t |"<<endl;
cout<<"+----------------------------------------------------------------------------------------------------------------+\n";
cout<<"|                                                                                                                |\n"; 
cout<<"|"<<emp.getEmpId()<<" "<<emp.getEmpName()<<emp.getEmpAge()<<"  "<<emp.getEmpAddress()<<""<<emp.getEmpDesignation()<<" "<<emp.getEmpContactNumber()<<" "<<emp.getEmpGender()<<"\t\t |"<<endl;
cout<<"+----------------------------------------------------------------------------------------------------------------+\n";

takeEnter();
}

void UI::displayErrorId() {
	cout<<"\nInvalid Id.\n\nEnter again :";
	takeEnter();
}

int UI::askConfirmation() {
int x;
cout<<"\n\t1. Confirm.";
cout<<"\n\t2. Abort.";
cout<<"\n\n\t>>Enter choice : ";
cin>>x;
return x;

}





void UI::displayErrorIdMismatch() {
	cout<<"\n\tEmployee does not exist.";
	takeEnter();
}

void UI::displayAllEmpDetails(vector<Employee> empList) {
int x;
cout<<"\n\t\t\t\tEmployee Details\n\n\n";
cout<<"+----------------------------------------------------------------------------------------------------------------+\n";

cout<<"|"<<"ID"<<setw(10)<<"Name"<<setw(25)<<"Age"<<setw(15)<<"Designation"<<setw(25)<<"Address"<<setw(15)<<"Mob No."<<setw(15)<<"Gender  \t |"<<endl;
cout<<"+----------------------------------------------------------------------------------------------------------------+\n";
cout<<"|                                                                                                                |\n"; 
for(int i=1;i<=empList.size();i++) {

cout<<"|"<<empList[i-1].getEmpId()<<" "<<empList[i-1].getEmpName()<<empList[i-1].getEmpAge()<<"  "<<empList[i-1].getEmpAddress()<<""<<empList[i-1].getEmpDesignation()<<" "<<empList[i-1].getEmpContactNumber()<<" "<<empList[i-1].getEmpGender()<<"\t\t |"<<endl;
cout<<"+----------------------------------------------------------------------------------------------------------------+\n";

	if(i%2==0 || i==empList.size()) {
			if(i==2) {
			cout<<"\nPress 1 for next and 3 for exit:";
			cin>>x;
		}
		
		
		 else if(i!=2 && i!=empList.size()) {
			cout<<"\nPress 1 for next, 2 for back and 3 for exit:";
			cin>>x;
			if(x==2)
				i=i-4;
		}
		else if (i==empList.size()) {
			cout<<"\nPress 2 for back and 3 for exit:";
			cin>>x;
			if(x==2)
				i=i-(4-i%2);
			}
		
		if(x==3)
			break;
		else {
			system("clear");
			cout<<"\n\t\t\t\tEmployee Details\n\n\n";
			cout<<"+----------------------------------------------------------------------------------------------------------------+\n";
			cout<<"|"<<"ID"<<setw(10)<<"Name"<<setw(25)<<"Age"<<setw(15)<<"Designation"<<setw(25)<<"Address"<<setw(15)<<"Mob No."<<setw(15)<<"Gender  \t |"<<endl;
			cout<<"+----------------------------------------------------------------------------------------------------------------+\n";
			cout<<"|                                                                                                                |\n"; 
		}
		
	}
	
}
takeEnter();

}

int UI::getViewOption() {
	int option,flag;
	cout<<"\n\n\t1.View Employee Details by Id.";
	cout<<"\n\n\t2.View all Employees' Details.";
	cout<<"\n\n\t3.View Employee Details by name.\n";
	cout<<"\n\tEnter your choice:";
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
	cout<<"\nInvalid Option.\n\n\t";
	takeEnter();
}

void UI::displayEmpSearchBackupSuccess(Employee emp1) {
	displayEmpDetails(emp1);
	takeEnter();
}

void UI::displayLimitExceeded() {
	cout<<"\n\tInvalid data entry limit exceeded.\n";
	
}

struct EmployeeStruct UI::getEmpDetails() {
	int age;
	string name,address,designation,number;
	char gender;
	
	int c=1;
	int count=0;
	cout<<"\n\tEnter details of an employee :\n";
	do {	
		count++;
		if(count==4) {
				displayLimitExceeded();
				exit(0);
			}
		if(c==1) {
		
			cout<<"\n\tName           :\t\t";
			cin.ignore();
			getline(cin,name);
		}
		else {
			cout<<"\n\tInvalid name.\n\n\tEnter again    :\t\t";
			getline(cin,name);
			
		}
		
		c=validateName(name);
	}while(c== -1);

	c=1;
	count=0;
	do {	
			int count1=0;
		if(c==1) {
			
				cout<<"\n\tAge            :\t\t";
				cin>>age;
				while(1) {
					count1++;
				
					if(cin.fail()){
						cin.clear();
						cin.ignore(245,'\n');
						cout<<"\n\tInvalid Age.\n\n\tEnter again     :\t\t";	
						cin>>age;
					if(count1==3) {
					displayLimitExceeded();
					exit(0);
					}
					if(count==3) {
					displayLimitExceeded();
					exit(0);
					}
					
				}
				else 
						break;
				}	
		}
		else {
			while(1) {
					count1++;
				
				if(cin.fail()){
					cin.clear();
					cin.ignore(245,'\n');
					cout<<"\n\tInvalid Age.\n\n\tEnter again     :\t\t";	
					cin>>age;
					
					if(count1==3) {
					displayLimitExceeded();
					exit(0);
					}	
					if(count==3) {
					displayLimitExceeded();
					exit(0);
					}	
				}
				else 
					break;
			}
			cout<<"\n\tInvalid age.\n\n\tEnter again    :\t\t";
			cin>>age;
			
			if(count==3) {
				displayLimitExceeded();
				exit(0);
				}
		}
		count++;
		c=validateAge(age);
	}while(c== -1);

	c=1;
		count=0;
	do {	
		if(count==4) {
				displayLimitExceeded();
				exit(0);
			}
		if(c==1) {
		
			cout<<"\n\tGender(M/F)    :\t\t";
			cin>>gender;
			cin.ignore(256,'\n');
		}
		else {
			cout<<"\n\tInvalid gender.\n\n\tEnter again(M/F):\t\t";
			cin>>gender;
			cin.ignore(256,'\n');
			
		}
		count++;
		c=validateGender(gender);
	}while(c== -1);

	c=1;	
	count=0;
	do {	
		count++;
		if(count==4) {
				displayLimitExceeded();
				exit(0);
				}
		if(c==1) {
		
			cout<<"\n\tDesignation    :\t\t";
			getline(cin,designation);
		}
		else {
			cout<<"\n\tInvalid designation.\n\n\tEnter again    :\t\t";
			getline(cin,designation);
			
		}
		c=validateDesignation(designation);
	}while(c==-1);
	
	c=1;
	count=0;
	do {	
		count++;
		if(count==4) {
				displayLimitExceeded();
				exit(0);
				}
		if(c==1) {
		
			cout<<"\n\tAddress        :\t\t";
			//cin.ignore();
			getline(cin,address);
		}
		else {
			c=1;
			cout<<"\n\tInvalid address.\n\n\tEnter again    :\t\t";
			//cin.ignore();
			getline(cin,address);
			
		}
		c=validateAddress(address);
	}while(c==-1);

	c=1;	
	count=0;
	do {
		count++;
		if(count==3) {
				displayLimitExceeded();
				exit(0);
				}
		
		if(c==1) {
			
		
			cout<<"\n\tContact Number :\t\t";
			cin>>number;
		}
		else {
			c=1;
			cout<<"\n\tInvalid number.\n\n\tEnter again    :\t\t";
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
	cout<<"\n\tEmployee with ID "<<id<<" added successfully.\n\n\t";
	takeEnter();
}

void UI::displayErrorDetails() {
	cout<<"\n\n\tInvalid Data provided.\n\n\t";
	takeEnter();
}

void UI::displayErrorEmpRepeat() {
	cout<<"\n\n\tEmployee already exists.\n\n\t";
	takeEnter();
}

void UI::displayDeleteEmpSuccess() {
	cout<<"\n\n\tEmployee details deleted successfully.\n\n\t";
	takeEnter();
}

void UI::displaySuccessRetrieve() {
	cout<<"\n\n\tEmployee details retrieved successfully.\n\n\t";
	takeEnter();
}

void UI::displayUpdateSuccess() {
	cout<<"\n\n\tEmployee details updated successfully.\n\n\t";
	takeEnter();
}
int UI::getBackupOption() {
	int choice,c=1;

	cout<<"\n\n\t1. Manual Backup.";
	cout<<"\n\n\t2. View all details from database.";
	cout<<"\n\n\t3. View all details from updated backup.";
	cout<<"\n\n\t4. Make File Backup.";
	cout<<"\n\n\t5. Retrieve File Backup.";
	
	do {
		if(c==1) {
			cout<<"\n\tEnter your choice:";
			cin>>choice;
		}
		else {
			cout<<"\n\n\tInvalid choice.\nEnter again    :";
			cin>>choice;
		}	
		c=validateViewBackupOption(choice);
	}while(c==-1);
	
	return choice;
}


int UI::validateViewBackupOption(int i) {
	if((i==1)||(i==2)||(i==3)||(i==4)||(i==5))
		return 1;
	else
		return -1;
}

void UI::displayBackupSuccess() {
	cout<<"\n\n\tBackup Successful.\n\n\t";
	takeEnter();
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
		cout<<"\n\n\t1. Name";
		cout<<"\n\n\t2. Age";
		cout<<"\n\n\t3. Gender";
		cout<<"\n\n\t4. Designation";
		cout<<"\n\n\t5. Contact Number";
		cout<<"\n\n\t6. Address";
		cout<<"\n\n\t7. Exit";
		cout<<"\n\n\n\t>>Enter your choice to update corresponding details :";
		cin>>x; 
		
		switch(x) {
			case 1: {
					c=1;
					do {	
						if(c==1) {



							cout<<"\n\tEnter name     :\t\t";
							cin.ignore();
							getline(cin,name);
						}
						else {
							cout<<"\n\tInvalid name.\n\tEnter again    :\t\t";
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
				
							cout<<"\n\tEnter Age      :\t\t";
							cin>>age;
						}
						else {
							cout<<"\n\tInvalid age.\n\tEnter again    :\t\t";
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
			
							cout<<"\n\tEnter Gender(M/F):\t\t";
							cin>>gender;
						}
						else {
							cout<<"\n\tInvalid gender.\n\tEnter again(M/F):\t\t";
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
			
							cout<<"\n\tEnter Designation:\t\t";
							cin.ignore();
							getline(cin,designation);
						}
						else {
							cout<<"\n\tInvalid designation.\n\tEnter again    :\t\t";
						//	cin.ignore();
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
			
							cout<<"\n\tEnter Address  :\t\t";
							cin.ignore();
							getline(cin,address);
						}
						else {
							cout<<"\n\tInvalid address.\n\tEnter again    :\t\t";
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
			
							cout<<"\n\tEnter Contact Number:\t\t";
							cin.ignore();
							cin>>number;
						}
						else {
							cout<<"\n\tInvalid number.\n\tEnter again    :\t\t";
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
				cout<<"\n\nInvalid choice.";
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

void UI::taskAborted() {
	cout<<"\n\t\tTask aborted.\n";
	takeEnter();
}
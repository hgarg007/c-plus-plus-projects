#include<string>
#include<vector>
#include"customer.h"
#include"account.h"
#include"bank.h"
#include<iostream>

using namespace std;

int main() {
	std::string name, phone;
	int accno, id, bal;
	int ch;
	Customer *c;
	Account *a;
	Bank mybank;

	while (1) {

	cout<<"1. Add account"<<endl;
	cout<<"2. Find Balance"<<endl;
	cout<<"Enter -ve for exit..."<<endl;
	cin>>ch;

	switch(ch) {
		case 1:
			cout<<"Enter name"<<endl;
			cin>>name;
			cout<<"enter phone"<<endl;
			cin>>phone;
			id=Customer::generateId();
			c= new Customer(id, name, phone);
			accno=Account::generateAccNo();
			a= new Account(c, accno);
			
			mybank.addAccount(a);
			cout<<"Account added..."<<endl;
			break;
			

		case 2:
			cout<<"Eneter acc no"<<endl;

			cin>>accno;
			bal=mybank.findBal(accno);
			if(bal!=-1)
				cout<<"Your Balance: "<<bal<<endl;
			else
				cout<<"No Account"<<endl;
			break;
		default:
			cout<<"Wrong Input";
			break;


	}
	if(ch<0) {
	cout<<"Exiting/............"<<endl;
	break;
		
	}
}
return 0;	
}

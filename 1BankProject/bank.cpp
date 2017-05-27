//#include<cstring>
#include<vector>
//#include"customer.h"
//#include"account.h"
#include"bank.h"
//#include<iostream>

#ifndef Bank_CPP
#define Bank_CPP

Bank::Bank() {}
void Bank:: addAccount(Account *a) {
	accounts.push_back(*a);
}

int Bank:: findBal(int accno) {
	//vector<Account>:: iterator i;
	for(int i=0; i<accounts.size(); i++) {
		if(accounts[i].getAccNo()==accno) {
			return accounts[i].getBal();
		}
		if(i==accounts.size()-1)	
			return -1;
	}

}

#endif


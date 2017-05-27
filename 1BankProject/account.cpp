//#include<string>
//#include<vector>
//#include"customer.h"
#include"account.h"
//#include"bank.h"
//#include<iostream>

#ifndef Account_CPP
#define Account_CPP

int Account:: taccno=1000;

Account::Account() {}
Account:: Account(Customer *c, int accno) {
	this->c= c;
	this->accno= accno;
	this->bal=0;
}

int Account:: generateAccNo() {
	return ++taccno;
}

void Account:: addBal(int bal) {
	this->bal=this->bal+ bal;
}

int Account:: getBal() {
	return bal;
}

int Account:: getAccNo() {
	return accno;
}

#endif

#include "sguard.h"
#include <string>

int Sguard::tid=1000;

Sguard::Sguard() {
}


Sguard::Sguard(int sid,std::string sname,std::string sphone,std::string saddress) {
	this->sid=sid;
	this->sname=sname;
	this->saddress=saddress;
	this->sphone=sphone;
}

int Sguard::generateSid() {
	return ++tid;
}

void Sguard::setSname(std::string sname) {
	this->sname=sname;
}

void Sguard::setSaddress(std::string saddress) {
	this->saddress=saddress;
}

void Sguard::setSphone(std::string sphone) {
	this->sphone=sphone;
}

int  Sguard::getSid() {
	return sid;
}

std::string Sguard::getSname() {
	return sname;
}

std::string Sguard::getSphone() {
	return sphone;
}

std::string Sguard::getSaddress() {
	return saddress;
}


#include "securitysystem.h"
#include <vector>
#include <string>


using namespace std;

// cout, setw



SecuritySystem:: SecuritySystem() {
}

void SecuritySystem:: addSguard(Sguard *s) {
	
		sguards.push_back(*s);
}

void SecuritySystem:: updateSguard(int sid, char op, string str) {
	
	for(int i=0; i<sguards.size(); i++) {

		if(sguards[i].getSid()==sid) {
			if(op=='1')
				sguards[i].setSname(str);
			else if(op=='2')
				sguards[i].setSaddress(str);
			else
				sguards[i].setSphone(str);
		
			
		}
		
	}
	
}
int SecuritySystem::getNumberG() {
	return sguards.size();
} 

Sguard * SecuritySystem:: displaySguard(int index) {
	
	return &sguards[index];
}

void SecuritySystem:: addSchedule(Schedule *s) {

	scheduling.push_back(*s);
}

void SecuritySystem:: updateSchedule(int day, char op, int sid) {

	for(int i=0; i<scheduling.size(); i++) {

		if(scheduling[i].getDay()==day) {
			if(op=='1')
				scheduling[i].setMShift(sid);
			else if(op=='2')
				scheduling[i].setEShift(sid);
			else
				scheduling[i].setNShift(sid);
			
		}
		
	}
	
	
}

Schedule * SecuritySystem:: displaySchedule(int index) {

	return &scheduling[index];
}

int SecuritySystem::getNumberS() {
	return scheduling.size();
} 

int SecuritySystem:: validatePhone(string phone) {
	int flag=0;

	if(phone.length()==10) {
		for(int i=0; i<10; i++) {
			if(!(phone.at(i)>='0' && phone.at(i)<='9')) {
				return -1;
			}
		}
		
	} else 
		return -1;
	return 1;
}

int SecuritySystem:: validateName(string name) {
	for(int i=0; i<name.length(); i++) {
		if(!((name.at(i)>=65 && name.at(i)<=90) || (name.at(i)>=97 && name.at(i)<=122) || name.at(i)==' ')) {
			return -1;
		}
	}
	
	return 1;
}

int SecuritySystem:: validateAddress(string address) {
	if(address.length()<10)
		return -1;
	return 1;
}

int SecuritySystem:: validateSid(int id) {
	for(int i=0; i<sguards.size(); i++) {
		if(id==sguards[i].getSid())
			return 1;
	}
	return -1;
}

int SecuritySystem:: validateDay(int day) {
	for(int i=0; i<scheduling.size(); i++) {
		if(scheduling[i].getDay()==day)
			return 1;
	}
	return -1;
}
#include "schedule.h"


Schedule::Schedule(){
}

Schedule::Schedule(int day, int mshift,int eshift,int nshift) {
	this->day=day;
	this->mshift=mshift;
	this->eshift=eshift;
	this->nshift=nshift;
}

void Schedule::setMShift(int mshift) {
	this->mshift=mshift;
}

void Schedule::setEShift(int eshift) {
	this->eshift=eshift;
}

void Schedule::setNShift(int nshift) {
	this->nshift=nshift;
}

int Schedule::getDay() {
	return day;
}

int Schedule::getMShift() {
	return mshift;
}

int Schedule::getEShift() {
	return eshift;
}

int Schedule::getNShift() {
	return nshift;
}

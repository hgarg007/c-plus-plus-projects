
#ifndef Schedule_H
#define Schedule_H

class Schedule {

int day;
int mshift,eshift,nshift;

public:
   
	Schedule();
	Schedule(int, int, int, int);
	void setMShift(int);
	void setEShift(int);
	void setNShift(int);
	int getDay();
	int getMShift();
	int getEShift();
	int getNShift();
};

#endif

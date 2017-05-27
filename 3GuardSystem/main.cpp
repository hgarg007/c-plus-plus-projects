#include <iostream>
#include <string>
#include<cstdlib>
#include <vector>
#include "sguard.h"
#include "schedule.h"
#include "securitysystem.h"
#include <iomanip>

using namespace std;

void printStar() {
	for(int i=0;i<97;i++)
		cout<<"*";
}

int main() {
	char ch, cho;
	int sid, day,i;
	int mshift, eshift, nshift;
	string sname, saddress, sphone, str;
		

	Sguard *s;
	Schedule *ss;
	SecuritySystem mysys;
	
	while(1) {
	system("clear");
	printStar();
	cout<< "\n\t\t\t\tSECURITY GUARD SYSTEM\n";
	printStar();

	cout<<"\n\n\n\t1. Register a Security Guard."<<endl;
	cout<<"\n\t2. View all details of Security Guards."<<endl;
	cout<<"\n\t3. Update Security Guard details."<<endl;
	cout<<"\n\t4. Enter Schedule for the day."<<endl;
	cout<<"\n\t5. View schedule."<<endl;
	cout<<"\n\t6. Update schedule details."<<endl;
	cout<<"\n\tEnter choice(Enter 0 for exit): ";
	cin>>ch;
	system("clear");

	switch(ch) {
	
	case '1': 
                cout<<"\n\n";
	       	printStar();
	    	cout<< "\n\t\t\t\tNEW SECURITY GUARD ENTRY\n";
		printStar();
		cout<<"\n\n\n\tEnter Details: \n";
		getline(cin, sname);

		while(1) {
			cout<<"\n\tName: ";
			getline(cin, sname);
			if(mysys.validateName(sname)==-1)
				cout<<"Name invalid. Numbers not allowed in name. Try again"<<endl;
			else 
				break;
		}
		if(sname.at(0)<=122 && sname.at(0)>=97)	
			sname.at(0)-= 32;
		while(1) {
			cout<<"\n\tAddress: ";
			getline(cin,saddress);
			if(mysys.validateAddress(saddress)==-1)
				cout<<"Address invalid. Address should contain altleast 10 characters.Try  again"<<endl;
	
			else 
				break;
		}
		while(1) {
			cout<<"\n\tPhone no.: ";
			getline(cin,sphone);
			if(mysys.validatePhone(sphone)==-1)
				cout<<"Phone number invalid.Try again!"<<endl;
	
			else 
				break;
		}
		
		
		sid= Sguard::generateSid();
		s= new Sguard(sid, sname, sphone, saddress);
		mysys.addSguard(s);
		cout<<"\n\n\tGenerated Security ID: "<<sid;
		cout<<"\n\n\tRecord created!\n";


		cout<<"\n\nPress ENTER to return to menu.";
		//cin.get();
		cin.ignore(256, '\n');
		system("clear");
		break;

	case '2': 
		cout<<"\n\n";
		printStar();	
		cout<< "\n\t\t\t\tSECURITY GUARD DETAILS\n";
		printStar();
		cout<<"\n\n\n";
		cout<<setw(15)<<"SECURITY ID"<<setw(25)<<"NAME"<<setw(15)<<"PHONE NO."<<setw(20)<<"ADDRESS"<<endl;
		cout<<"\n\n";
		
		if(mysys.getNumberG()>0)
		for(i=0; i<mysys.getNumberG(); i++) {
			s= mysys.displaySguard(i);
			cout<<setw(15)<<right<<(*s).getSid()<<setw(25)<<left<<(*s).getSname()<<setw(15)<<right<<(*s).getSphone()<<setw(20)<<left<<(*s).getSaddress()<<endl;
		}
		else
			cout<<"\n\n\n\n\t\t\t\tNo security guard registered"<<endl;

		cout<<"\n\n\n\n\n\n\nPress ENTER to return to menu.";

		cin.get();
		cin.ignore(256, '\n');
		system("clear");
		break;
	case '3':
		cout<<"\n\n";		
		printStar();
		cout<< "\n\t\t\t\tSECURITY GUARD DETAILS UPDATION \n";
		printStar();
		cout<<"\n\n\n";

		while(1) {
			cout<<"\tEnter Security ID of guard to update: ";
			cin>>sid;
			if(mysys.validateSid(sid)==-1) {
				cout<<"\n ID invalid. Try again!"<<endl;
				continue;
			}
			else
				break;
		}
		
				
				while(1) {
				cout<<"\tEnter update entity"<<endl;
				cout<<"\t1. Name"<<endl;
				cout<<"\t2. Address"<<endl;
				cout<<"\t3. Phone"<<endl;

				cout<<"\n\tEnter your choice(0 FOR EXIT): "<<endl;
				cin>>cho;

				if(cho=='0') {
					break;
				}
				else if(cho>'3' || cho<'0') {
					cout<<"Choice invalid Try again"<<endl;
					continue;
				}
					

				cout<<"\tEnter new value";
				getline(cin, str);
				// one getline is used for buffer input
	
				getline(cin,str);

				if(cho=='1' && (mysys.validateName(str)==-1)) {
					cout<<"\t Name invalid. Try again"<<endl;
					continue;
				}
				if(cho=='2' && (mysys.validateAddress(str)==-1)) {
					cout<<"\tAddress invalid. Try again"<<endl;
					continue;
				}
				if(cho=='3' && (mysys.validatePhone(str)==-1)) {
					cout<<"\tPhone invalid...Try again"<<endl;
					continue;
				}
	
				// For Uppercasing First letter

				if(cho==1 && str.at(0)<=122 && str.at(0)>=97)	
					str.at(0)-= 32;	
				mysys.updateSguard(sid, cho, str);
				cout<<"\n\nRecord updated"<<endl;
				
				}
		cout<<"\n\n\tPress ENTER  to return to menu.";	

		cin.get();			
		cin.ignore(256, '\n');
		system("clear");
		break;
	case '4': 
		cout<<"\n\n";
		printStar();
		cout<< "\n\t\t\t\tSCHEDULING SYSTEM\n";
		printStar();
		cout<<"\n\n";
		while(1) {		
			cout<<"\tEnter the Day no. for scheduling: ";
			cin>>day;
			if(day<=0 || day>=32){
				cout<<"\nDay invalid\n";
				continue;
			}
			if(mysys.validateDay(day)!=-1) {
				cout<<"\nDay "<<day<<" is already scheduled."<<endl;
				continue;
			}
			else
				break;
		}
		
		while(1) {
			cout<<"\tEnter sid of the guard for morning shift: ";
			cin>>mshift;
			if(mysys.validateSid(mshift)==-1) {
				cout<<"\tID invalid. Try again"<<endl;
				continue;
			}
			else 
				break;
		}
		while(1) {
			cout<<"\tEnter sid of the guard for evening shift: ";
			cin>>eshift;
			if(mysys.validateSid(eshift)==-1) {
				cout<<"\tID invalid. Try again"<<endl;
				continue;
			}
			else 
				break;
		}
		while(1) {
			cout<<"\tEnter sid of the guard for night shift: ";
			cin>>nshift;
			if(mysys.validateSid(nshift)==-1) {
				cout<<"\tID invalid. Try again"<<endl;
				continue;
			}
			else 
				break;
		}
		
		
		
		ss= new Schedule(day, mshift, eshift, nshift);
		mysys.addSchedule(ss);
			cout<<"\n\n"<<"\tScheduling for the day "<<day<<" Completed"<<endl;
		
			

		cout<<"\n\n\tPress ENTER to return to menu.";
			
		cin.get();
		cin.ignore(256, '\n');
		system("clear");
		break;

	case '5': 
		cout<<"\n\n";
		printStar();
		cout<< "\n\t\t\t\tSCHEDULE DETAILS\n";
		printStar();
		cout<<"\n\n";
		cout<<setw(15)<<"DAY"<<setw(15)<<"MORNING"<<setw(15)<<"EVENING"<<setw(15)<<"NIGHT"<<endl;
		if(mysys.getNumberS()>0)
		for(i=0; i<mysys.getNumberS(); i++) {
			ss=mysys.displaySchedule(i);
			cout<<setw(15)<<(*ss).getDay()<<setw(15)<<(*ss).getMShift()<<setw(15)<<(*ss).getEShift()<<setw(15)<<(*ss).getNShift()<<endl;
		}
		else
			cout<<"\n\n\n\t\t\tSchedule not available\n";
		cout<<"\n\n\n\n\n\n\n\tPress ENTER to return to menu.";

		cin.get();
		cin.ignore(256, '\n');
		system("clear");
		break;
	case '6': 
		cout<<"\n\n";
		printStar();
		cout<< "\n\t\t\t\t\tSCHEDULE UPDATION\n";
		printStar();
		cout<<"\n\n";
		while(1) {
			cout<<"\tEnter day to update: ";
			cin>>day;
			if(mysys.validateDay(day)==-1) {
				cout<<"\tDay does not exist. Try again"<<endl;
				continue;
			}
			else 	
				break;		
		}
		while(1) {
			cout<<"\n\tEnter the shift to update: ";
			cout<<"\n\t1. Morning."<<endl;
			cout<<"\n\t2. Evening."<<endl;
			cout<<"\n\t3. Night."<<endl;
			cout<<"\t\tPress 0 to exit."<<endl;
			cin>>cho;
			if(cho=='0') {
				break;
			}
			else if(cho>'3' || cho<'0') {
				cout<<"Choice invalid. Try  Again!"<<endl;
				continue;
			}
			
			cout<<"\n\tEnter sid of the guard: ";
			cin>>sid;
			if(mysys.validateSid(sid)==-1) {
				cout<<"Invalid ID. Try again"<<endl;
				continue;
			}
			mysys.updateSchedule(day, cho, sid);
			cout<<"\n\nUpdation Done!"<<endl;
				
		}
		cout<<"\n\n\tPress ENTER to return to menu.";
		cin.get();
		cin.ignore(256, '\n');
		system("clear");
		break;

	default:
		if(ch!='0')
		cout<<"\n\n\tChoice invalid"<<endl;
		break;
	}
	if(ch=='0') {
		cout<<"\n\tEXITING!"<<endl;
		break;
	}	
		
	
	}
	
return 0;
}


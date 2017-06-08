#include"controller.h"
#include"empstruct.h"
#include<string>
#include<vector>
using namespace std;

void Controller:: initiateAll(WonderlandModel &w,UI &u) {
	while(1) {
		u.displayMainMenu();
		int option=u.getInitiateOption();
		switch(option) {
			case 1:
					initiateAddEmp(w,u);
					break;
			case 2:
					initiateViewDetails(w,u);
					break;
			case 3:
					initiateUpdateDetails(w,u);
					break;
			case 4:
					initiateDeleteEmp(w,u);
					break;
			case 5:
					initiateManualBackupView(w,u);
					break;
			case 6:
					initiateSearchEmp(w,u);
					break;
			case 0:
					break;
			default:
					u.displayErrorOption();
					break;
		}
		if(option==0)
			break;
		
	}
}

void initiateAddEmp(WonderlandModel &w,UI &u) {
	int temp= w.addEmp(u.getEmpDetails());
	if(temp)
		u.displayAddEmpSuccess(temp);
	else
		u.displayErrorEmpRepeat();
}

void initiateDeleteEmp(WonderlandModel &w,UI &u) {
	if(w.deleteEmp(u.getId()))
		u.displayDeleteEmpSuccess();
	else
		u.displayErrorIdMismatch();
}

void initiateManualBackupView(WonderlandModel &w,UI &u) {
	switch(u.getBackupOption()) {
		case 1:
				w.makeEmployeeBackup();
				u.displayBackupSuccess();
				break;
		case 2:
				u.displayAllEmpDetails(w.getEmpBackupList());
				break;
	}
}

void initiateViewDetails(WonderlandModel &w,UI &u) {
	switch(u.getViewOption()) {
		case 1: {
				int index=w.isEmpIdExist(u.getId());
				if(index!=-1)
					u.displayEmpDetails(w.viewEmpDetails(index));
				else
					u.displayErrorIdMismatch();
				break;
				}
		case 2: {
				u.displayAllEmpDetails(w.getEmpList());
				break;
				}
	}
}

void initiateUpdateDetails(WonderlandModel &w,UI &u) {
	int x=u.getId();//edited
	if(w.updateEmpDetails(u.getUpdateDetails(),x))//edited 
		u.displayUpdateSuccess();
	else
		u.displayErrorIdMismatch();
}

void initiateSearchEmp(WonderlandModel &w,UI &u) {
	int index= w.isEmpIdExistBackup(u.getId());
	if (index!=-1)
		u.displayEmpDetails(w.viewEmpDetailsBackup(index));
	else
		u.displayErrorIdMismatch();
}
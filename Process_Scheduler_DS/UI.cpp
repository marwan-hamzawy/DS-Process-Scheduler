#include<iostream>
using namespace std;
#include "UI.h"
#include"FCFSProcessor.h"
#include"Process.h"
#include <conio.h>
#include<list>

void UI::PrintMode() {
	FCFSProcessor p1;
	FCFSProcessor p2;
	list <FCFSProcessor> LList;
	LList.push_back(p1);
	LList.push_back(p2);
	int mode;
	cout << "-------------*Process Scheduler*--------------" << endl;
	cout << "For Interactive Mode press ->>>> 1 " << endl;
	cout << "For Step-by-Step Mode press ->>>> 2 " << endl;
	cout << "For Silent Mode press ->>>> 3 " << endl;
	cin >> mode;
	if (mode == 1) {
		cout << "----------- RDY Processes ------------" << endl;

		cout << "----------- BLK Processes ------------" << endl;
		cout << "----------- RUN Processes ------------" << endl;
		cout << "----------- TRM Processes ------------" << endl;
		cout << "PRESS ANY KEY TO MOVE TO NEXT STEP !" << endl;
		cin.ignore();
	}

}

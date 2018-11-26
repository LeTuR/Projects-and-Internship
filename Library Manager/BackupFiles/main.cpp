//
//  main.cpp
//  LibraryManager
//
//  Created by MagicLetur on 12/04/2018.
//  Copyright © 2018 Cesare-Herriau. All rights reserved.
//

#include <iostream>

using namespace std;


int main(int argc, const char * argv[]) {
	string input;
	cout << "Welcome to the Library Manager:\n";
	cout << "Please enter a command, to see the list of commands type HELP, if you want to exit type EXIT\n"<<"\n";
	for(;;){
		cin>>input;
		if (input == "HELP"){
			cout << "--------------------\n";
			cout << "List of commands:\n";
			cout << "BYE   ADD     LOAD\n";
			cout << "SAVE  SEARCH  CLEAR\n";
			cout << "LIST  SHOW    DELETE\n";
			cout << "RESET HELP    EXIT\n";
			cout << "--------------------\n"<<"\n";
			cout << "Please enter a command, to see the list of commands type HELP, if you want to exit type EXIT\n";


		}
	}
	return 0;
}

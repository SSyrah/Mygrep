#include "mygrep.h"

int main(int argc, char *argv[]) {
	char BigString[200];
	char SearchString[200];
	int position = NULL;
	int* pos = &position;
	int count = 0;
	//test print how many arguments there is and what kind of
	for (int i = 0; i < argc; i++) {
		// cout << "argc[" << i << "] is: " << argv[i] << endl;
		count++;
	}

	// cout << "\ntesting count-number: " << count << endl;		// just for testing
	// if there is just one or two command line arguments, it goes here
	if (count <=2) {
		// Asks user two strings:
		cout << "Give a string from which to search for: ";
		cin.getline(BigString, 200);
		cout << "\nGive search string: ";
		cin.getline(SearchString, 200);
		// create a pointer where to save possible match string
		char* ptr;
		// call a function to investigate is there a match, also send int pointer where to save position.
		ptr = FindString(BigString, SearchString, pos);
		if (ptr != NULL) {
			cout << SearchString << " found in \"" << BigString << "\" in position " << position << ".";
		}
		else {
			cout << SearchString << " NOT found in \"" << BigString << "\"";
		}
	} 


	// if there is 3 command line arguments it goes here
		
	else if (count == 3) {
		fstream inFile;
		if (isFileOpen(inFile, argv[2])) {
			cout << "File Success!" << endl;
			printUserWord(1, inFile, argv[1]);		// searching substring without any extra specifications (-ol -oo etc.)
		}
		else
			cout << "Failed to open the file, couldn't regognize the name of the file. ";
		inFile.close();
		}

	else if (count == 4) {
		fstream inputFile;
		char* test = argv[1];
		bool option1 = false, option2 = false, option3 = false, option4 = false, option5=false, option6=false;
		 // testing can file be opened
		if (isFileOpen(inputFile, argv[3])) {
			cout << "File opened successfully!" << endl;			
		
		// testing what command line argument user is adding 
		if (test[0] == '-' && test[1] == 'o' &&  test[2] == 'l' && test[3] == '\0') {
			option1 = true, option2 = true, option3 = true;
		}
		else if (test[0] == '-' && test[1] == 'o' && test[2] == 'o') {
			option1 = true, option2 = true;
		}
		else if (test[0] == '-' && test[1] == 'o' && test[2] == 'l' && test[3] == 'o' && test[4] == '\0') {
			option1 = true, option2 = true, option3 = true, option4 = true;
		}
		else if (test[0] == '-' && test[1] == 'o' && test[2] == 'l' && test[3] == 'o' && test[4] == 'r' && test[5] == 'i') {
			option1 = true, option2 = true, option3 = true, option4 = true, option5 = true, option6 = true;
		}
		else if (test[0] == '-' && test[1] == 'o' && test[2] == 'r') {
			option1 = true, option2 = true, option5 = true;
		}
		else if (test[0] == '-' && test[1] == 'o' && test[2] == 'i') {
			option1 = true, option2 = true, option5 = true, option6 = true;
		}
		else {}


			// executes using condition -ol , prints only number of rows
		if (option1 == true && option2 == true && option3 == true && option4 == false)
			printUserWord(2, inputFile, argv[2]);
			// exexutes using condition - oo, prints only number of founded rows with substring
		else if (option1 == true && option2 == true && option3 == false && option5 == false)
			printUserWord(3, inputFile, argv[2]);
			// exexutes using condition - olo, prints number of rows where to find substring along with substring
		else if (option1 == true && option2 == true && option3 == true && option4 == true && option5 == false && option6 == false)
			printUserWord(4, inputFile, argv[2]);
			// exexutes using condition - olori, 
		else if (option1 == true && option2 == true && option3 == true && option4 == true && option5 == true && option6 == true)
			printUserWord(5, inputFile, argv[2]);
			// exexutes using condition - or,		
		else if (option1 == true && option2 == true && option5 == true && option6 == false)
			printUserWord(6, inputFile, argv[2]);
			// exexutes using condition - oi,		
		else if (option1 == true && option2 == true && option5 == true && option6 == true)
			printUserWord(7, inputFile, argv[2]);
		else{
			cout << "Couldn't regognize type of option, try again." << endl;
			}
		}
	else {
			cout << "An exception occurred. Exception Nr. -1. Could not find out the size of file \"" << argv[3] << "\". The correct filename is: \"man_grep_plain_ASCII.txt\"" << endl;
		}
	}
return 0;
} 
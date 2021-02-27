#include "mygrep.h"

char* FindString(const char* x, const char* y, int* place) {

	char* temp = NULL;
	char* tempstring = new char[strlen(x)+1] ;
	char* tempstring2 = new char[strlen(y)+1];
	strcpy(tempstring, x);
	strcpy(tempstring2, y);

	
	int count = 0;
	while (*(tempstring+count) != '\0') {
		tempstring[count] = tolower(tempstring[count]);
		count++;
	}
	count = 0;
	while (*(tempstring2+count) != '\0') {
		tempstring2[count] = tolower(tempstring2[count]);
		count++;
	}
	
	if (strstr(tempstring, tempstring2)){
		temp = strstr(tempstring, tempstring2);
		*place = strlen(x) - strlen(temp) + 1;
		}
	else{}
	
	return temp;
}

bool isFileOpen(fstream& file, string name) {
	//trying to open the file
	file.open(name, ios::in);
	if (file.fail())		//return false, if cannot open the file, otherwise true
		return false;
	else
		return true;
}

void printUserWord(int option , fstream& file, string searchstring) {
	string line;
	if (option == 1) {
		while (!file.eof()) {
			getline(file, line);
			if (line.find(searchstring) != string::npos) {
				cout << line << endl;
			}
			else {}
		}
	}
	else if (option == 2) {
		int count = 0, found = 0;
		while (!file.eof()) {
			getline(file, line);
			count++;
			if (line.find(searchstring) != string::npos) {
				cout << count << ":" << endl;
				}
			else {}
		}
	}
	else if (option == 3) {
		int count = 0, found = 0;
		while (!file.eof()) {
			getline(file, line);
			count++;
			if (line.find(searchstring) != string::npos) {
				found++;
			}
			else {}
		}
		cout << "\nOccurrences of lines containing \"following\" : " << found << endl;
	}
	else if (option == 4) {
		int count = 0, found = 0;
		while (!file.eof()) {
			getline(file, line);
			count++;
			if (line.find(searchstring) != string::npos) {
				cout << count << ":\t" << line << endl;
				found++;
			}
			else {}
		}
		cout << "\nOccurrences of lines containing \"following\" : " << found << endl;
	}
	else if (option == 5) {				
		int count = 0, found = 0;
		string userWord = searchstring;
		while (!file.eof()) {
			getline(file, line);
			count++;
			for (int i = 0; i < line.length(); i++) {
				line[i] = tolower(line[i]);
			}
			for (int j = 0; j < searchstring.length(); j++) {
				searchstring[j] = tolower(searchstring[j]);
			}
			if (line.find(searchstring) != string::npos) {}
			else {
				cout << count << ":\t" << line << endl;
				found++;
			}
		}
		cout << "\nOccurrences of lines NOT containing \"" << userWord <<"\" : " << found << endl;
	}
	else if (option == 6) {
		int count = 0;
		while (!file.eof()) {
			getline(file, line);
			count++;
			if (line.find(searchstring) != string::npos) {}
			else {
				cout << line << endl;
			}
		}
	}
	else if (option == 7) {
			while (!file.eof()) {
				getline(file, line);
				for (int i = 0; i < line.length(); i++) {
					line[i] = tolower(line[i]);
				}
				for (int j = 0; j < searchstring.length(); j++) {
					searchstring[j] = tolower(searchstring[j]);
				}
				// cout << "pituus: " << line.length() << "\n\n" << line <<  endl;
				if (line.find(searchstring) != string::npos) {
					cout << line << endl;
				}
				else {  }
			}
		}
}
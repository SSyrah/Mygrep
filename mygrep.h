#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

// this function is for finding substring without any added command line parameters
char* FindString(const char*, const char*, int* );

// tests can file opened
bool isFileOpen(fstream&, string);

// function which executes all different added command  line parameters
void printUserWord(int , fstream&, string);



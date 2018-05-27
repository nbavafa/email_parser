

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

//prototyping
void findEmails();

//A concise main
int main () {
	findEmails();

}

//Check to make sure each character is a valid email char
bool isValidEmailCharacter(char c) {

	if (c >='A' && c <='Z') return true;
	else if (c >='a' && c <='z') return true;
	else if (c >='0' && c <='9') return true;
	else if (c =='.') return true;
	else if (c =='-') return true;
	else if (c =='+') return true;
	else if (c =='@') return true;
	else return false;

}

//Append each grabbed char to the temporary string
string getEmail (string s, char c ) {
	s = s + c;
	return s;
}

//Grabs input file containing emails
string getIn() {
	string inFilename = "fileContainingEmails.txt";

	cout <<"Please enter the input file name [Default: "<<inFilename<<"]: ";
	getline(cin, inFilename);
	if (inFilename == "")
		inFilename = "fileContainingEmails.txt";
	return inFilename;
}

//Prompt for output file for emails
string getOut(string s) {
	string outFilename;
	string userInput;
	//Passes input file here because output is dependent on input file
	if (s == "fileContainingEmails.txt")
			outFilename = "copyPasteMyEmails.txt";
	else
		 outFilename = s;
	cout <<"Please enter the output file name [Default: "<<outFilename<<"]: ";
	getline(cin, userInput);
	cout <<endl;
	if (userInput == "")
		userInput = outFilename;

	cout <<"Input file: "<<s <<endl;
	cout <<"Output file: "<<outFilename <<endl;
	return outFilename;

}

//logic for finding the '@' and printing the emails
void findEmails() {

	string tempEmail;
	string inFilename = getIn();
	string outFilename = getOut(inFilename);

	ifstream fin;

	fin.open(inFilename.c_str());
	if (!fin.good()) throw "I/O error";
	int count = 0;
	int j = 0;
	string temp = "holder";
	getline(fin, temp);
	cout <<endl;
		//Grabs code line by line
		while (std::getline(fin, temp)) {
			//Checks every character in each line
			for (int i = 0; i < temp.length(); i++) {
				tempEmail= "";
				//Looks for @ symbol
				if (temp[i] == '@') {
					j = i;
					int n = 0;
					int grab = 0;
					//Runs until an invalid email character is found
					while (true) {
						n--;
						if (!isValidEmailCharacter(char(temp[i+n]))) {
							grab = i + n + 1;
							while (isValidEmailCharacter(char(temp[grab]))) {
									tempEmail = getEmail(tempEmail, temp[grab]);
									grab++; }
							break;
						}
						else continue;
					}
					count ++;
					cout <<count<<": "<<tempEmail<<endl;
				}
			}
		}
		cout <<endl;
}


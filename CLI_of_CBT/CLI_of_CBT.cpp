// Hackerrank_project.cpp : Defines the entry point for the console application.
//


#include<iostream>
#include<conio.h>
#include<stdio.h>
#include<string>
#include<string.h>
#include<iomanip>
#include<Windows.h>
#include<fstream>

using namespace std;

//All the function declarations
void print();
void clearcin();
int logged();
int nread(const char str[100]);
int countline(const char str[100]);
void read(const char str[100]);
void testcreated(const char x[100]);
void testcase(const char x[100]);
void selectorS();
void submissions();
void csvwrite(const char filename[100],double reg, const char name[50], int tp);
void csvread(const char filename[100]);
void ctest();
void student();
int admin();
void logfile(const char filename[100]);
int studentarea();
void selecttest(int x);
int write(string file, int x);
int compareFile(string str1, string str2);
inline int
stringLength(char *String);
inline int
stringToInt(char *String);


int main()
{
	char take;
	cout << "Do you want to create a new Database ? \n";
	cin >> take;
	if (take == 'y' || take == 'Y')
	{
		cout << "creating new database : ";
		logfile("usera.csv"); //admin database
		logfile("users.csv"); //user databse
	}
	cout << "\nTo create a new student ID enter 'y'.";
	cout << endl << "To continue to login page enter anything except(y/Y) ...\n";
	char y;
	cin >> y;
	if (y == 'y' || y == 'Y')
	{
		system("cls");
	createagain:
		logfile("users.csv");
		string temp;
		getline(cin, temp);
		cout << "Created the new user want to add another user ?   ";
		char ch;
		cin >> ch;
		if (ch == 'y' || ch == 'Y')
			goto createagain;
		return 0;
	}
	system("cls");
	string temp;
	getline(cin, temp);
	int x;
	x = logged();
	if (x == 1)
		admin();
	else if (x == (-1))
		studentarea();
	else
	{
		cout << "\n Sorry you have no access .";
		_getch();
	}
	_getch();
	return 0;
}

// Function for the admins
int admin()    
{
	system("cls");
	cout << "entered admin\n";
	print();
start:
	system("cls");
	int choice, ichoice; int chance = 2; char ch;
	cout << setw(20) << "Welcome to the program : ";
	cout << endl << "Enter your choice : \n ";

	cout << "\n1) Create a new test. \n2) View an existing test. \n3) check results of the student. " << endl;
	cin >> choice;
	switch (choice)
	{
	case 1: ctest();
		break;
	case 2:nread("test.txt");
		cout << "\n" << "Enter the corresponding number to view the test: \n";
		cin >> ichoice;
		selecttest(ichoice);
		cout << "\n Press anything to continue... ";
		_getch();
		break;
	case 3:
		system("cls");
		cout << "showing you the result :" << endl;
		csvread("result.csv");
		cout << "press anything to continue... ";
		break;
	default: cout << "Invalid input! please try again and enter only the option number...";
		if (chance > 1)
		{
			cout << "\n You have " << chance << " tries left.";
		}
		else if (chance == 1)
		{
			cout << "\n You have only 1 try left!!!";
		}
		if (chance > 0)
		{
			Sleep(2000);
			system("cls");
			chance--;
			goto start;
		}
		else
		{
			cout << "\n You exceeded the number of attemps! program will quit.";
			Sleep(3000);
			exit(-1);
		}
		break;
	}
	cout << "\nDo you want to continue ?? (y/n) \n";
	cin >> ch;
	if (ch == 'y')
		goto start;
	else
		return 0;
}

// Function for creating a new test
void ctest()
{
	string x; int chance = 2; char cases[100] = "cases";
	cout << "Enter the unique test name (without spaces) : ";
	cin >> x;
	write(x.c_str(), 1);
	testcase(x.c_str());
}

void student()     
{
	system("cls");
	print();
	cout << "you are a student !!!";
	_getch();
	return;
}


void logfile(const char filename[100])				//function to be used to create admin or student
{
	//variables
	char username[50], pass[50];
	//file writing
	cout << "please enter the username  : ";
	cin >> username;
	cout << "please enter the password  : ";
	cin >> pass;
	fstream ofile;
	ofile.open(filename, ios::out | ios::_Nocreate);
	if (!ofile)
	{
		cout << "creating new file\n";
		ofile.open(filename, ios::out);
		if (!ofile)
		{
			cout << "FATAL ERROR!! cannot create file.";
			return;
		}
		ofile << username << "," << pass << "," << "\n"; // Runs if the csv file is new for inserting the header
	}
	ofile.close();
	return;
}


void clearcin()  //Function for clearing the input buffer
{
	string temp;
	getline(cin, temp);
}


int logged()    //Function for the login page to check the user is admin or user
{
	char user[50], userS[50], pass[50], passS[50];
	//clearcin();
	cout << "\n please enter the username : ";
	cin.getline(user, 50);
	cout << "\n please enter the password : ";
	cin.getline(pass, 50);
	fstream fin, fout;
	fin.open("usera.csv", ios::in);

	while (!fin.eof())
	{
		fin.getline(userS, 100, ',');
		{
			if (strcmp(user, userS) == 0)
			{
				fin.getline(passS, 100, ',');
				if (strcmp(pass, passS) == 0)
				{
					cout << "test case passed :";
					goto admin;
				}
				else
				{
					cout << " you are no admin!!!";
					goto usercheck;
				}

			}
		}
	}

usercheck:

	fout.open("users.csv", ios::in);
	while (!fout.eof())
	{
		fout.getline(userS, 100, ',');
		{
			if (strcmp(user, userS) == 0)
			{
				fout.getline(passS, 100, ',');
				if (strcmp(pass, passS) == 0)
				{
					cout << "student testcase passed !";
					goto student;
				}
			}
		}
	}

	fin.close();
	fout.close();
	return 0;


student:
	return (-1);

admin:
	return 1;
}

void gtest()
{
	string name, filename; char com[100] = "g++ "; char regn[100], compiledfile[100] = "\0", textfile[100] = "\0";
	int x = 0; int check = 0, marks = 0; double reg;
	string temp;
	getline(cin, temp);
	cout << "Enter your name: ";
	getline(cin,name);
	cout << "Enter your registration id : ";
	cin >> regn;
	reg = stringToInt(regn); 
	cout << "Enter the test name : ";
	cin >> filename;
	string examname = "case" + filename + ".txt";
	strcat_s(regn, filename.c_str());
	filename += ".txt";
	strcat_s(compiledfile, regn);
	strcat_s(regn, ".cpp");
	cout << regn <<endl;
	fstream ofile;
	ofile.open(regn, ios::out);
	if (!ofile)
	{
		cout << "FATAL ERROR: file cannot be opened!!";
		return;
	}
	char program[10000];
	clearcin();
	cout << "write the program : \n Enter \'$\' to end it" << endl;
	cin.getline(program, 10000, '$');
	ofile << program;
	cout << "your submission was successful! \n";
	ofile.close();
	strcat_s(textfile, compiledfile);
	strcat_s(compiledfile, ".exe");
	strcat_s(com, regn);
	strcat_s(com, " -o ");
	strcat_s(com, compiledfile);
	system(com);
	strcat_s(compiledfile, " < ");
	strcat_s(compiledfile, examname.c_str());
	strcat_s(compiledfile, " > ");
	strcat_s(compiledfile, textfile);
	strcat_s(compiledfile, ".txt");
	strcat_s(textfile, ".txt");
	x = countline(filename.c_str());
	cout << x << " showing the number of lines:\n";
	Sleep(1000);
	while (x > 0)
	{
		char c = '1';
		system(compiledfile);
		cout << "File compiled till here!\n";
		string temp = "wow";
		cout << temp << endl;
		string fc = "output";
		cout << fc << endl;
		string cf = fc +c + examname;
		cout << cf;
		cout << endl << textfile;
		_getch();
		check = compareFile(cf, textfile);
		nread(cf.c_str());
		cout << endl;
		nread(textfile);
		cout << endl;
		if (check == 1)
		{
			cout << "Test case is passed nice work! wait 1 sec... \n";
			Sleep(1000);
			marks++;
		}
		cout << "\nLOOP RUN";
		c++;
		x--;
		cout << c;
		cout << marks;
	}
	csvwrite("result.csv", reg, name.c_str(), marks);
	return;
}

int nread(const char str[100])				// Function to read from a file
{
	system("cls");
	int count = 0;
	fstream fin(str, ios::in);
	if (!fin)
	{
		cout << "Sorry the file does not exists in our database or cannot be opened!";
		_getch();
		return 0;
	}
	char ques[1000];
	while (!fin.eof())
	{
		fin.getline(ques, 1000);
		cout << ques << "\n";
	}
	fin.close();
	return 1;
}

int countline(const char str[100])			// function to count lines
{
	system("cls");
	int count = 0;
	fstream fin(str, ios::in | ios::_Nocreate);
	if (!fin)
	{
		cout << "Sorry the file does not exists in our database or cannot be opened!";
		_getch();
		return (-1);
	}
	char ques[1000];
	while (!fin.eof())
	{
		fin.getline(ques, 1000);
		count++;
	}
	fin.close();
	return (count);
}


//function to write questions in a file
int write(string file, int x)		
{
	string temp;
	cout << "the file name is : " << file << endl;
	ofstream fin;
	file += ".txt";
	fin.open(file, ios::out);
	if (!fin)
	{
		cout << "FATAL ERROR: file cannot be opened!!";
		return 1;
	}
	char ques[1000];
	getline(cin, temp);
	cout << "write the question : \n Enter \'?\' to end the question " << endl;
	while (x>0)
	{

		cin.getline(ques, 1000, '?');
		strcat_s(ques, "?");
		fin << ques;
		x--;
	};
	cout << "your test is successfully created!";
	testcreated(file.c_str());
	fin.close();
	return 0;
}


// function to read questions from a file
void read(const char str[100])
{
	system("cls");
	int count = 0;
	fstream fin(str, ios::in | ios::_Nocreate);
	if (!fin)
	{
		cout << "Sorry the file does not exists in our database or cannot be opened!";
		_getch();
		return;
	}
	char ques[1000];
	while (!fin.eof())
	{
		fin.getline(ques, 1000, '?');
		cout << ques << "?";
		count++;
	}
	cout << endl << "File name = " << str << "\nNumber of questions in this file = " << count - 1;
	cout << endl;
	fin.close();
}


void testcreated(const char x[100])			// After a test has been created this function will register the value to the test file
{
	int t;
	cout << "\n Entered in testcraeted : ";
	fstream ofile;
	ofile.open("test.txt", ios::out | ios::app | ios::_Nocreate);
	if (!ofile)
	{
		ofile.open("test.txt", ios::out);
		if (!ofile)
		{
			cout << "Sorry the test could not be filed.";
			return;
		}
		else
		{
			ofile << "1)" << x << "\n";
			cout << "re-wrote";
			_getch();
		}
	}
	else
	{
		ofile.seekp(ios::end);
		t = countline("test.txt");
		ofile << t << ")" << x << "\n";
		cout << "written";

	}
	ofile.close();
	return;
}



void selecttest(int x) // This function will surf through the test.txt and will extract the filename corresponding the entered number
{
	system("cls");
	int count = 1;
	fstream fin("test.txt", ios::in | ios::_Nocreate);
	if (!fin)
	{
		cout << "Sorry the file does not exists in our database or cannot be opened!";
		_getch();
		return;
	}
	char ques[1000];
	while (!fin.eof())
	{
		if (count > x)
		{
			cout << "Invalid input!!";
			goto end;
		}
		else if (count == x)
		{
			fin.getline(ques, 1000, ')');
			fin.getline(ques, 1000);
			cout << ques;
			nread(ques);
			break;
		}
		else
		{
			fin.getline(ques, 1000);
			count++;
		}

	}
	fin.close();
	return;
end:
	fin.close();
	return;
}


void testcase(const char f[100])
{

	// The argument is the filename of the exam itself at the time of creation
	char x[100] = "case";
	strcat_s(x, f);
	strcat_s(x, ".txt");
	string temp1;
	char ch = 'y';
	fstream file;
	file.open(x, ios::out);
	if (!file) //If the file cannot be created in during runtime
	{
		cout << "FATAL ERROR: file cannot be opened!!";
		return;
	}
	char cases[1000];
	getline(cin, temp1);
	cout << "write the test case each test case in a new line and then enter $ to exit and save :\n" << endl;
	while (ch == 'y' || ch == 'Y')		// Loop for taking the inout from the testcases from the admin and save them in a file
	{
		cin.getline(cases, 1000, '$');
		file << cases;
		cout << "want to enter more test cases ? (y/n)";
		cin >> ch;
	};
	cout << "Testcases successfully saved... "; // This will be displayed when the file is successfully created and saved in the database
	file.close();
	Sleep(2000);		// 1 second timer
	system("cls");      // Screen Cleared
	int n; string temp;
	n = countline(x);
	cout << "Your file contains " << n - 1 << "no. of testcases so please enter the expected output for each testcase..(text sensitive) \n";
	string ocases = "test";
	char c = '1';
	for (int i = 0; i < n - 1; i++)
	{	// This loop will run exactly the same number of times as the lines in testcases file
		// loop for taking the input of the testcases session 
		// The file names are separated by the filename pattern that is governed by the ocases concatenation and ocases already contains the text test and then 
		// one character is added ito it and that character is the number of the time that particular loop was run hence for the first the exact name of the file
		// should be test1 and the filename which was passed by the function parameter hence the filename becomes test1compare.txt

		//system("cls");
		ocases = "output";
		ocases += c;
		ocases += x;
		file.open(ocases, ios::out);
		if (!file)
		{
			cout << "FATAL ERROR: file cannot be opened!!";
			return;
		}
		char cases[1000]; getline(cin, temp);
		cout << "write the expected output of the file: \n" << endl;
		cin.getline(cases, 1000, '$');
		file << cases;
		if (i == 0)
			c = '2';
		else if (i == 1)
			c = '3';
		file.close();
	};
	cout << "\nYour file was successfully created and stored... Thanks for creating the test.\n";
}


int studentarea()
{
	selectorS();

	return 0;
}

void selectorS()
{
start:
	char ch;
	system("cls");
	print();
	int choice, ichoice;
	cout << "\nPlease select from the following \n1) List the exams \n2) View your submissions \n3) View Rankings\n";
	cout << "\nplease enter your choice : ";
	cin >> choice;
	switch (choice)
	{
	case 1: nread("test.txt");
		cout << "\n" << "Enter the corresponding number to give the test.";
		cin >> ichoice;
		selecttest(ichoice);
		cout << "Please enter (y/Y) for giving the test or enter anything to exit the panel : \n";
		gtest();
		break;
	case 2: cout << "view submissions ";
		submissions();
		break;
	case 3: cout << "Your ranking can be found in the given result:";
		Sleep(1000);
		system("cls");
		cout << "showing you the result :" << endl;
		csvread("result.csv");
		cout << "press anything to continue... ";
		break;
	default: cout << "invalid input";
	}
	cout << "Do you want to continue the program?? (y/n)";
	cin >> ch;
	if (ch == 'y' || ch == 'Y')
		goto start;
	return;
}


void submissions()
{
	system("cls");
	cout << "Please enter your registration no. : ";
	char reg[100], name[100];
	cin >> reg;
	nread("test.txt");
	cout << endl << "Please enter the name of the test : ";
	cin >> name;
	strcat_s(reg, name);
	strcat_s(reg, ".cpp");
	nread(reg);
	cout << endl << "you have this submission..";
	_getch();
}

void print()
{
	cout << " __                __  ________.  __.          _______.       ____     ____        ___.   ________.   " << endl; Sleep(250);
	cout << " \\ \\      /\\      / /  | ._____|  | |         /  ____  \\     / __ \\    |   \\      /   |   | ._____|   " << endl; Sleep(250);
	cout << "  \\ \\    /  \\    / /   | |___.    | |        /  /    |__|   / /  \\ \\   | |\\ \\    / /| |   | |___.     " << endl; Sleep(250);
	cout << "   \\ \\  / /\\ \\  / /    |  ___|    | |       |  |     ___.  | |    | |  | | \\ \\  / / | |   |  ___|     " << endl; Sleep(250);
	cout << "    \\ \\/ /  \\ \\/ /     |  |____.  | |_____.  \\  \\ ___|  |   \\ \\__/ /   | |  \\ \\/ /  | |   |  |____.   " << endl; Sleep(250);
	cout << "     \\__/    \\__/      |_______|  |_______|   \\________/     \\____/    |_|   \\__/   |_|   |_______|   " << endl; Sleep(250);
	cout << " to my CSE 202 project!! ";
	Sleep(1000);
	system("cls");
}

// Function for writing in a csv file
void csvwrite(const char filename[100], double reg, const char name[50] = NULL, int tp = NULL)
{
	//variables
	unsigned int mg = (tp * 5);
	float pc = float(mg) * 10;
	cout << pc << endl;

	//file writing
	fstream ofile;
	ofile.open(filename, ios::out | ios::_Nocreate);
	ofile.seekp(0, ios::end);
	if (!ofile)
	{
		cout << "creating new file\n";
		ofile.open(filename, ios::out);
		if (!ofile)
		{
			cout << "FATAL ERROR!! cannot create file.";
			return;
		}
		ofile << "Registration ID,Name of the student,testcases passed,marks gained,percentage completion,\n"; // Runs if the csv file is new for inserting the header
	}
	else {
		cout << "appending the result in existing file... \n";
	}
	ofile <<reg << "," << name << "," << tp << "," << mg << "," << pc << "," << "\n";  // Inserting the data
	ofile.close();
}

// Function for reading from a csv file

void csvread(const char filename[100])
{
	int count = 0; int l = 0;
	fstream ifile;
	ifile.open(filename, ios::in);
	if (!ifile)
	{
		cout << "Sorry the file does not exists or could not be opened";
		return;
	}
	char ch[100];
	while (!ifile.eof())
	{
		ifile.getline(ch, 100, ',');
		{
			cout << setw(20) << ch << "\t";
		}
	}
	cout << endl;
	ifile.close();
}

int compareFile(string str1, string str2)
{
	fstream file1(str1), file2(str2);
	char string1[1000], string2[1000];
	int j; j = 0;

	while (!file1.eof() || !file2.eof())
	{
		file1.getline(string1, 1000);
		file2.getline(string2, 1000);
		if (strcmp(string1, string2) != 0)
		{
			return 0;
		}
	}
	return 1;
}

inline int
stringLength(char *String)
{
	int Count = 0;
	while (*String++) ++Count;
	return Count;
}

inline int
stringToInt(char *String)
{
	int Integer = 0;
	int Length = stringLength(String);
	for (int Caret = Length - 1, Digit = 1; Caret >= 0; --Caret, Digit *= 10)
	{
		if (String[Caret] == '-') return Integer * -1;
		Integer += (String[Caret] - '0') * Digit;
	}

	return Integer;
}
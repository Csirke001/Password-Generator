#include <iostream>
#include <cstdlib>
#include <time.h>

//Namespaces
using std::string;

//Global variables
const string abc_LowerCase = "abcdefghijklmnopqrstuvwxyz";
const string abc_UpperCase = "ABCDEFGHIJKLMNOPGRSTUVWXYZ";
const string nums = "0123456789";
const string specialCH = "!#$%&'()*+,-./:;<=>?@[]^_`{|}~";

//Function declarations
string PasswordGenerate(const int& lenght, const int& num, const int& special, const int& upCaseLet);

//Main
int main()
{
	//Getting preferences from the user
	std::cout << "****PASSWORD GENERATOR PROGRAM****\n";

	int* length = new int;
	std::cout << "Enter how many character password you want:";
	std::cin >> *length;

	int* input = new int[3];
	std::cout << "Type 0 if you want upper case letters in your password or 1 if you dont want:";
	std::cin >> input[0];

	std::cout << "Type 0 if you want numbers in your password or 1 if you dont want:";
	std::cin >> input[1];

	std::cout << "Type 0 if you want special characters in your password or 1 if you dont want special characters:";
	std::cin >> input[2];

	//Returning password
	std::cout << "Your password:" << PasswordGenerate(*length, input[1], input[2], input[0]);

	//Ending the program & freeing up memory
	delete length;
	delete[] input;
	return 0;
}

//Function definiton
string PasswordGenerate(const int& lenght, const int& num, const int& special, const int& upCaseLet)
{	
	srand((unsigned)time(NULL));
	string ABC = abc_LowerCase;
	
	//Setting the options by the preferences
	if (upCaseLet == 0)
	{
		ABC.append(abc_UpperCase);
		if (num == 0)
		{
			ABC.append(nums);
			if (special == 0)
			{
				ABC.append(specialCH);
			}
		}
	}
	else if (num == 0)
	{
		ABC.append(nums);
		if (special == 0)
		{
			ABC.append(specialCH);
		}
	}
	else if (special == 0)
	{
		ABC.append(specialCH);
	}

	//Generate password
	string password;
	for (int i = 0; i < lenght; i++)
	{
		int randNum = rand() % ABC.length();
		password += ABC[randNum];
	}

	return password;
}
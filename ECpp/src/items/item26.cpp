/** Item 26: Postpone variable definitions as long as possible. */

#include <iostream>
#include <string>

int MinimumPasswordLength = 10;

void encrypt(std::string& s);

std::string encryptPassword(const std::string& password)
{
	using namespace std;

	//string encrypted; // may use or not

	if (password.length() < MinimumPasswordLength)
	{
		throw logic_error("Password is too short");
	}

	//string encrypted; // 1 constructor

	//encrypted = password; // 1 assignment operator

	string encrypted(password); // 1 copy constructor
	encrypt(encrypted);

	return encrypted;
}

//

void loop1()
{
	int n = 10;
	int s;
	for(int i = 0; i < n; ++i)
	{
		s = i;
	}
}

void loop2()
{
	int n = 10;
	for (int i = 0; i < n; ++i)
	{
		int s(i);
	}
}

// 1 assignment is less expensive than a contructor-destructor pair
// 2 dealing with a performance-sensitive part
// use loop1
// or default loop2

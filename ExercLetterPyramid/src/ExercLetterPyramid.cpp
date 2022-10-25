//Write a C++ program that displays a Letter Pyramid from a user - provided std::string.
//Prompt the user to enter a std::string and then from that string display a Letter Pyramid as follows :
//It's much easier to understand the Letter Pyramid given examples.
//If the user enters the string "ABC", then your program should display :
//
//   A
//  ABA
// ABCBA
//
//If the user enters the string, "12345", then your program should display :
//
//     1
//    121
//   12321
//  1234321
// 123454321
//
//If the user enters 'ABCDEFG', then your program should display :
//
//       A
//      ABA
//     ABCBA
//    ABCDCBA
//   ABCDEDCBA
//  ABCDEFEDCBA
// ABCDEFGFEDCBA

#include <iostream>
#include <string>

using namespace std;

int main()
{
	cout << "Please enter a word or text to get a pyramid of letters: ";
	string inputString{};
	getline(cin, inputString);
	string tempString{};
	string tempStringReverse {};
	for (size_t i = 0, k = inputString.length() - 1; i < inputString.length(); i++, k--)
	{
		string spaces{};
		if (i == 0)
		{
			tempString = inputString.at(i);
			tempStringReverse = tempString;
			spaces.insert(0, k, ' ');
			cout << spaces + tempString << endl;
		}
		else
		{
			tempStringReverse = tempString;
			spaces.insert(0, k, ' ');
			reverse(tempStringReverse.begin(), tempStringReverse.end());
			cout << spaces + tempString + inputString.at(i);
			cout << tempStringReverse << endl;
			tempString += inputString.at(i);
		}
	}
}
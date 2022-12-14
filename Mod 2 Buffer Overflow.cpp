// BufferOverflow.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iomanip>
#include <iostream>

int main()
{
	std::cout << "Buffer Overflow Example" << std::endl;

	// TODO: The user can type more than 20 characters and overflow the buffer, resulting in account_number being replaced -
	//  even though it is a constant and the compiler buffer overflow checks are on.
	//  You need to modify this method to prevent buffer overflow without changing the account_order
	//  varaible, and its position in the declaration. It must always be directly before the variable used for input.

	const std::string account_number = "CharlieBrown42";
	char user_input[20];
	std::cout << "Enter a value: ";

	// Replaced std::cin with std::cin.getline()
	// This way, we can set the limit to match the limit defined with char user_input[20]
	// https://cplusplus.com/reference/istream/istream/getline/
	
	// I the user_input was within the lenght limit, it will output as normal and show what was entered
	if (std::cin.getline(user_input, 20)) {
		std::cout << "You entered: " << user_input << std::endl;
	}
	// Otherwise, it will output that the character length limit was exceeded and abort the program
	// to prevent from accessing things it shouldn't via buffer overflow exploit
	// https://cplusplus.com/reference/cstdlib/abort/
	else {
		std::cout << "Character length limit exceeded" << std::endl;
		abort();
	}
	std::cout << "Account Number = " << account_number << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

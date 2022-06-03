#include <iostream>

#include "Phrase.h"


int main() 
{
	std::cout << "COMMAND MENU" << std::endl << std::endl;
	std::cout << "New Phrase" << '\t' << '-' << "Enter a new phrase to be manipulated." << std::endl;
	std::cout << "Reverse" << '\t' << '\t' << '-' << "Reverses the order of the entered phrase." << std::endl;
	std::cout << "Sort Words" << '\t' << '-' << "Sorts words in ascending order." << std::endl;
	std::cout << "Rot13 Encoding" << '\t' << '-' << "Encrypts phrase using Rot13 conversion" << std::endl;
	std::cout << "Quit" << '\t' << '\t' << '-' << "Exit program" << std::endl << std::endl;
	std::cout << "Command: ";
	std::string command;
	std::getline(std::cin, command);
	std::cin.clear();
	Phrase phrase;
	std::vector<std::string> parsed;
	while (command != "Quit")
	{
		if (command == "New Phrase")
		{
			std::cout << "Please enter phrase to be evaluated" << std::endl;
			std::string text;
			std::getline(std::cin, text);
			if (text == "")
			{
				std::cout << "Invalid entry. Please enter new phrase: " << std::endl;
				std::getline(std::cin, text);
			}
			phrase.set_value(text);

			std::cout << "Enter next command: " << std::endl;
			std::getline(std::cin, command);
			std::cin.clear();
			parsed.clear();
			phrase.parse_phrase(phrase.get_phrase(), parsed);
		}
		else if (command == "Reverse")
		{
			std::cout << phrase.reverse(parsed) << std::endl;

			std::cout << "Enter next command: " << std::endl;
			std::getline(std::cin, command);
			std::cin.clear();
		}
		else if (command == "Sort Words")
		{
			std::cout << phrase.sort(parsed) << std::endl;

			std::cout << "Enter next command: " << std::endl;
			std::getline(std::cin, command);
			std::cin.clear();
		}
		else if (command == "Rot13 Encoding")
		{
			std::cout << phrase.rot13(phrase.get_phrase()) << std::endl;

			std::cout << "Enter next command: " << std::endl;
			std::getline(std::cin, command);
			std::cin.clear();
		}
		else if (command == "Quit")
		{
			// Nothing needed will exit program.
		}
		else
		{
			std::cout << "Invalid command. Please try again: ";
			std::cin.clear();
			std::getline(std::cin, command);
		}
	}
	std::cout << "The end." << std::endl;
	return 0;
}
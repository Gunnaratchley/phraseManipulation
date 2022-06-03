#pragma once

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

class Phrase
{
private:
	// Data Declaration
	std::string mPhrase;

public:
	/*!
	* Constant delim is the delimiter used to parse the phrase
	*/
	static char const delim = ' ';
	/*!
	* Constant base is the int value to rotate the char value in rot13
	*/
	static int const base = 13;

	// Constructors
	Phrase();

	// Destructor
	~Phrase();

	// Setter
	void set_value(const std::string& phrase);

	// Getter
	std::string get_phrase() const;

	/*!
	*\Splits the phrase into its individual words.
	*\param phrase is the string to be split.
	*\param token is the vector to store the word tokens.
	*\return void
	*/
	void parse_phrase(std::string phrase, std::vector<std::string>& token);

	/*!
	*\Reverses the order of the words in the vector.
	*\param parsed is the vector of parsed words to be arranged.
	*\return string of the reversed phrase.
	*/
	std::string reverse(std::vector<std::string> parsed);

	// Sort
	/*!
	*\Sorts the words in ascending order.
	*\param parsed is the vector of parsed words to be arranged.
	*\return string of the sorted phrase.
	*/
	std::string sort(std::vector<std::string> parsed);

	/*!
	*\Encrypts the phrase using Rot13 cypher.
	*\param phrase is the input that will be encrypted.
	*\return string of the encrypted phrase.
	*/
	std::string rot13(std::string phrase);

};


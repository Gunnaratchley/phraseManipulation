#include "Phrase.h"

// Constructors
Phrase::Phrase()
{
	std::string mPhrase;
}

// Destructor
Phrase::~Phrase()
{
	// No action required here
}

// Setter
void Phrase::set_value(const std::string& phrase)
{
	mPhrase = phrase;
}

// Getter
std::string Phrase::get_phrase() const
{
	return mPhrase;
}

/*!
*\Splits the phrase into its individual words.
*\param phrase is the string to be split.
*\param token is the vector to store the word tokens.
*\return void
*/void Phrase::parse_phrase(std::string phrase, std::vector<std::string>& token)
{
	size_t start = phrase.find_first_not_of(delim), end = start;

	while (start != std::string::npos) 
	{
		// Find next occurence of delimiter
		end = phrase.find(delim, start);
		// Push back the token found into vector
		token.push_back(phrase.substr(start, end - start));
		// Skip all occurences of the delimiter to find new start
		start = phrase.find_first_not_of(delim, end);
	}
}

/*!
*\Reverses the order of the words in the vector.
*\param parsed is the vector of parsed words to be arranged.
*\return string of the reversed phrase.
*/
std::string Phrase::reverse(std::vector<std::string> parsed)
{
	std::reverse(parsed.begin(), parsed.end());
	std::string reverse;
	for (auto const& word : parsed)
	{
		reverse += (word + " ");
	}
	return reverse;
}

// Sort
/*!
*\Sorts the words in ascending order.
*\param parsed is the vector of parsed words to be arranged.
*\return string of the sorted phrase.
*/
std::string Phrase::sort(std::vector<std::string> parsed)
{
	std::sort(parsed.begin(), parsed.end());
	std::string sorted;
	for (auto const& word : parsed)
	{
		sorted += (word + " ");
	}
	return sorted;
}

/*!
*\Encrypts the phrase using Rot13 cypher.
*\param phrase is the input that will be encrypted.
*\return string of the encrypted phrase.
*/
std::string Phrase::rot13(std::string phrase) 
{

	for (std::string::size_type len = phrase.length(), index = 0; index != len; ++index)
	{
		if (phrase[index] >= 'a' && phrase[index] <= 'm')
		{
			phrase[index] = phrase[index] + base;
		}
		else if (phrase[index] >= 'n' && phrase[index] <= 'z')
		{
			phrase[index] = phrase[index] - base;
		}
		else if (phrase[index] >= 'A' && phrase[index] <= 'M') 
		{
			phrase[index] = phrase[index] + base;
		}
		else if (phrase[index] >= 'N' && phrase[index] <= 'Z') 
		{
			phrase[index] = phrase[index] - base;
		}
	}
	return phrase;
}
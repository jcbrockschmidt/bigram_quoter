#ifndef QUOTER_H
#define QUOTER_H

#include <exception>
#include <iostream>
#include <random>
#include <string>
#include <vector>

class QuoterError: public std::exception {
public:
	QuoterError(std::string m);
	virtual const char* what() const throw();
private:
	std::string msg;
};

class Quoter {
public:	
	Quoter();
	
	/* Feed a stream of coherent text into quoter for it to mimic.
	 *
	 * @param in Stream of coherent text.
	 */
	void feed_stream(std::istream& in);
		  
	/* Feeds a file containing coherent text into a quoter for it to mimic.
	 *
	 * @param filePath Path to file containing coherent text.
	 */
	void feed_file(std::string filePath);

	/* Feed a string of coherent text into a quoter for it to mimic.
	 *
	 * @in String of coherent text.
	 */
	void feed_string(std::string text);

	/* Builds a sentence based on the text fed into a quoter.
	 *
	 * @return A single sentence.
	 */
	std::string buildSentence();

	/* Prints out a character representation of a quoter's bigram array.
	 */
	void emitArray();
private:
	enum struct Markers: unsigned int {
		START,
	        END,
	        NUM_ITEMS
	};

	std::default_random_engine randGen;
	std::vector<std::vector<int>> bigram_array;
	std::vector<int> bigram_rowSums;
	std::vector<std::string> bigram_words;

	std::string filterWord(std::string& word);
};

#endif //QUOTER_H

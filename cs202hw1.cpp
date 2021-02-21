//Captain-Price-TF-141

/*

* Description: Unigram Bigram Extractor.
* Input: gutenberg-the-time-machine.txt.
* Output: Expected to output unigram (count and print to txt, single unique words)
*			and unigram (count and print to txt, sets of two unique words).
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cctype>


using namespace std;

const int ArrayMax = 50000;

struct unigram
{
	string word;
	int frequency;
};

struct bigram
{
	string word1;
	string word2;
	int frequency;
};

/*
* function_identifier: Reads data from file.
* parameters: word[], int& wordCount, string infile
* return value: Returns word count and stored string word array.
*/
int readdata(string word[], int& wordCount, string infile) //read in data from file
{
	
	wordCount = 0;
	ifstream fin;
	do
	{
		
		fin.open("/home/pricec3/cs202/gutenberg-the-time-machine.txt"); //opens the file for reading, 
		//NOTE TO GRADER, please RENAME "fin.open" to point to the correct file path.

		if (!fin)//checks if the file unable to open for reading display's error message and stop
		{
			fflush(stdin);
			continue;
		}
		else//otherwise valid file name come out of the loop

			break;

	} while (1);
	
	while (!fin.eof())//loops till end of the file for reading
	{
		fin >> word[wordCount];//reads word

		wordCount++;
	}
	return wordCount;
}

/*
* function_identifier: Identifies longest word and displays longest word.
* parameters: string w[]
* return value: Expected to return longest word, algorithm is incomplete.
*/
/*
int getlongestword(string w[])
{
	//for (int i = 0; i < ; i++)
	{
		

	}
	//for (int j = 0; j < ; j++)
	{

	}


}
*/

/*
* function_identifier: brief description of what the function does.
* parameters: what to pass into the function
* return value: It is expected to log all words with lower case and no punctuation. Does not remove punctuation, lower cases all letters,
*				does not log to file, displays lower case letters. 
*				NOTE TO GRADER: This is not looping, please allow it to finsh outputting
*				all letters, output takes a few seconds to finish, menu will be presented on complete.
*/
void cleanup (string word[], int wordCount) //another way to do array
{

	char answer;
	
	cout << "Log cleanup? Y/n:" << endl; //prompts user to save Clean Up Log to file
	cin >> answer;

	if (answer == 'y' || answer == 'Y')//Acknowledges the user wants to save log file
	{
		for (int i = 0; i < wordCount; i++)//reads words to characters
		{
			int j;
			string cw;
			cw = word[i][j];

			for (int j = 0; j < word[i].length(); j++)//reads characters to lower case
			{
				string cw;
				ofstream outFile;
				
				cw = tolower(word[i][j]);
				cout << cw << endl;
				/*outFile.open("ast1log.txt"); //Unable to log to file
				
				outFile << cw;*/
				
			}
		}
	}
	
	
	
}

/*
* function_identifier: Checks if word already exists in our array, if it does it returns the index.
* parameters: string word, struct Unigram list[], int count
* return value: Returns unigram list and word count, algorithm is incomplete.
*/
/*
int inList(string word, struct Unigram list[], int count) //Good practice for function overloading
{


}
*/
/*
* function_identifier: Checks if word already exists in our array, if it does it returns the index.
* parameters: string word, struct bigram list[], int count
* return value: Returns bigram list and word count, algorithm is incomplete.
*/
/*
int inList (string word, struct bigram list[], int count) //Good practice for function overloading
{


}
*/
/*
* function_identifier: Will sort the unigrams and bigrams alphabetically and by count.
* parameters: 
* return value: Returns sorted unigrams or bigrams, algorithm is incomplete.
*/
/*
void sortgms () //function to sort unigrams and function to sort bigrams
{


}
*/
/*
* function_identifier: Will generate array of unigrams.
* parameters: struct Unigram unigram[], int& unigramCount, string word[], int wordCount
* return value: Array of sorted unigrams for log, algorithm is incomplete.
*/
/*
void generate_unigrams (struct Unigram unigram[], int& unigramCount, string word[], int wordCount) //Unigram Extractor
{


}
*/
/*
* function_identifier: Will generate array of bigrams.
* parameters: struct bigram bigram[], int& bigramCount, string word[], int wordCount
* return value: Array of sorted bigrams for log, algorithm is incomplete.
*/
/*
void generate_bigrams (struct bigram bigram[], int& bigramCount, string word[], int wordCount) //Bigram Extractor
{


}
*/
/*
* function_identifier: Creates log file for unigrams.
* parameters: 
* return value: Creates log file for unigrams.
*/
/*
void write1gmslog ()
{
outFile.open("1gmslog"); //Unable to log to file

				outFile << ;

}
*/
/*
* function_identifier: Creates log file for bigrams.
* parameters:
* return value: Creates log file for bigrams.
*/
/*
void write2gmslog ()
{
/outFile.open("2gmslog.txt"); //Unable to log to file

				outFile << ;

}
*/



int main(int argc, char* argv[])
{
	
	string word[ArrayMax]; //Declared ArrayMax set to 50000

	int wordCount; 
	string infile;
	int menu; //integer driven menu variable
	
	cout << "Array Size: " << ArrayMax << endl; // displays array size

	int count = 0;
	count = readdata(word, wordCount, infile); // calls readdata function and displays word count
	cout << "Finished Reading " << count << " words." << endl;

	cleanup(word, wordCount); // calls clean up function

	do //Menu Driven Do-While Loop, using numbers to navigate.
	{
	

		cout << "Commands " << endl;

		cout << "(1): Unigram: search for unigram " << endl;

		cout << "(2): Bigram : search for bigram " << endl;

		cout << "(3): Save : save 1gms.txt and 2gms.txt " << endl;

		cout << "(4): Index : print index of unigram or bigram " << endl;

		cout << "(5): Quit / q : terminate program " << endl;
		cin >> menu;
		
			if (menu == 1)
			{
				cout << "unigram" << endl;
				//generate_unigrams(struct Unigram unigram[], int& unigramCount, string word[], int wordCount) //Unigram Extractor
			}
			else if (menu == 2)
			{
				cout << "bigram" << endl;
				//generate_bigrams(struct bigram bigram[], int& bigramCount, string word[], int wordCount) //Bigram Extractor
			}
			else if (menu == 3)
			{
				cout << "save" << endl;
				//write1gmslog()
				//write2gmslog()
			}
			else if (menu == 4)
			{
				cout << "index" << endl;
				//sortgms() //function to sort unigrams and function to sort bigrams
			}
			else if (menu == 5)//terminates program
			{
				cout << "quit" << endl; 
				exit(1);
			}
			
			
	
		} while (menu != 5 && menu <= 1 && menu >= 5); //loops until "5" is entered to terminate program
		

	return 0;
}

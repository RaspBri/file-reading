
/*
 This program reads the file specified by the user and finds and displays: the number of words in the file,
 the number of long words in the file, and the percentage of the words that are long words.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

int main()
{
    string filename, word; // Declare variables.
    
    cout << "Enter the name of the file to be read." << endl; // Prompt user for filename.
    cin >> filename;
    cout << endl;
    
    ifstream inputFile(filename); // Open file
    
    if(inputFile) // If file is valid/found
    {
        int wordLength = 0, wordCount = 0, longWord = 0; // Declare variables
        double percent;
        
        while(inputFile >> word) // Read every "word" in file.
        {
            if(word != "--") // As long as string is an actual word
            {
                wordCount++; // Add to total word count
                wordLength = word.length(); // Find current word's word length
                
                if(wordLength >= 7) // Check length of string
                {
                    // cout << "WORD: " << word << endl; // Debug Statement
                    
                    if(word.at(wordLength - 1) == ',' || word.at(wordLength - 1) == '.' || word.at(0) == '"' || word.at(wordLength - 2) == 44) // Check for invalid characters
                    {
                        if((wordLength - 1) >= 7) // Check string length without invalid characters
                        {
                            longWord++; // Add to longWord count
                            
                            // cout << "VALID LONGWORD: " << word << endl; // Debug Statement
                        }
                    }
                    else
                    {
                        longWord++; // Add to longWord count
                        
                        // cout << "VALID LONGWORD: " << word << endl; // Debug Statement
                    }
                    
                } // End of If loop
            } // End of If loop
        } // End of While loop
        
        inputFile.close(); // Close file.
        
        if(wordCount == 0) // If file has no words
        {
            cout << filename << " was empty." << endl;
        }
        else // If file contains content
        {
            percent = (static_cast<double>(longWord) / static_cast<double>(wordCount)) * 100; // Find percentage of longWords
            
            // Print statements
            
            cout << wordCount << " words were found." << endl;
            cout << longWord << " long words were found." << endl;
            cout << setprecision(2) << fixed << percent << "% of the words were considered long." << endl;
        }
        
    }
    else // If file is not found
    {
        cout << filename << " could not be read." << endl;
    }
    
}

// Aidan Burmester //
// read pokedex //

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// main //
int main()
{
    // file and line variables //
    ifstream inputFile;
    string line;

    cout << "Pokedex Reader" << endl << endl;

    // open file to read //
    inputFile.open("pokedex.txt");

    if (!inputFile)
    {
        cout << "Could not open pokedex.txt" << endl;
        cout << "Run 01_write_pokedex first or the pokedex is empty like my brain rn." << endl;
        return 1;
    }

    // read the whole file line by line //
    while (getline(inputFile, line))
    {
        cout << line << endl;
    }

    // close file //
    inputFile.close();

    return 0;
}

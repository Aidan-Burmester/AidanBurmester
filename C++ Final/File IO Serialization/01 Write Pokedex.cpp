// Aidan Burmester //
// write pokedex //

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// main //
int main()
{
    // file object //
    ofstream outputFile;

    cout << "Pokedex Writer" << endl << endl;

    // open file to write //
    outputFile.open("pokedex.txt");

    if (!outputFile)
    {
        cout << "Error opening pokedex.txt" << endl;
        return 1;
    }

    // write pokedex stuff //
    outputFile << "POKEDEX FILE" << endl;
    outputFile << "Pikachu Electric 25" << endl;
    outputFile << "Charmander Fire 4" << endl;
    outputFile << "Bulbasaur Grass 1" << endl;
    outputFile << "Squirtle Water 7" << endl;

    // close file //
    outputFile.close();

    cout << "pokedex.txt was created." << endl;
    cout << "Go catch em all!" << endl;

    return 0;
}

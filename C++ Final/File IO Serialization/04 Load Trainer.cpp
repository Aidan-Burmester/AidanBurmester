// Aidan Burmester //
// trainer load file //

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// trainer class //
class Trainer
{
private:
    string name;
    int badges;
    int money;
    string starter;

public:
    void load(ifstream& inputFile)
    {
        getline(inputFile, name);
        inputFile >> badges;
        inputFile >> money;
        inputFile.ignore();
        getline(inputFile, starter);
    }

    void print()
    {
        cout << "Trainer: " << name << endl;
        cout << "Badges: " << badges << endl;
        cout << "Money: " << money << endl;
        cout << "Starter: " << starter << endl;
    }
};

// main //
int main()
{
    // file and trainer objects //
    ifstream inputFile;
    Trainer player;

    cout << "Load Trainer File" << endl << endl;

    // open save file //
    inputFile.open("trainer_save.txt");

    if (!inputFile)
    {
        cout << "Could not open trainer_save.txt" << endl;
        cout << "Run 03_save_trainer first." << endl;
        return 1;
    }

    // load data from file //
    player.load(inputFile);
    inputFile.close();

    // print loaded data //
    cout << "Loaded trainer from file." << endl << endl;
    player.print();

    return 0;
}

// Aidan Burmester //
// trainer save file //

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
    void setTrainer(string n, int b, int m, string s)
    {
        name = n;
        badges = b;
        money = m;
        starter = s;
    }

    void save(ofstream& outputFile)
    {
        outputFile << name << endl;
        outputFile << badges << endl;
        outputFile << money << endl;
        outputFile << starter << endl;
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
    ofstream outputFile;
    Trainer player;

    cout << "Save Trainer File" << endl << endl;

    // set up trainer data //
    player.setTrainer("Aidan", 3, 420, "Pikachu");

    // open save file //
    outputFile.open("trainer_save.txt");

    if (!outputFile)
    {
        cout << "Error opening trainer_save.txt" << endl;
        return 1;
    }

    // save trainer to file //
    player.save(outputFile);
    outputFile.close();

    player.print();
    cout << endl;
    cout << "Trainer saved to trainer_save.txt" << endl;

    return 0;
}

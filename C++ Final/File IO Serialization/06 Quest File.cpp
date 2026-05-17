// Aidan Burmester //
// pokemon command file //

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
using namespace std;

// commands //
enum Commands
{
    CATCH_POKEMON = 1,
    TRAIN_POKEMON,
    BATTLE_RIVAL,
    PRINT_TEAM,
    HEAL_TEAM
};

// main //
int main()
{
    // file objects //
    ifstream inputFile;
    ofstream outputFile;

    // quest variables //
    int command;
    string pokemon;
    int level;
    int teamCount = 0;
    int battlesWon = 0;

    cout << "Pokemon Quest File" << endl << endl;

    // open command and report files //
    inputFile.open("Pokemon Commands.txt");
    outputFile.open("pokemon_report.txt");

    if (!inputFile)
    {
        cout << "Error opening Pokemon Commands.txt" << endl;
        return 1;
    }

    if (!outputFile)
    {
        cout << "Error opening pokemon_report.txt" << endl;
        return 1;
    }

    // write report title //
    outputFile << "Pokemon Command Report" << endl << endl;

    // get first command //
    inputFile >> command;

    while (command != -1)
    {
        // run command //
        switch (command)
        {
        case CATCH_POKEMON:
            inputFile >> pokemon >> level;
            teamCount++;
            outputFile << "Caught " << pokemon << " at level " << level << "." << endl;
            break;

        case TRAIN_POKEMON:
            inputFile >> pokemon;
            outputFile << pokemon << " trained really hard for like 12 seconds." << endl;
            break;

        case BATTLE_RIVAL:
            battlesWon++;
            outputFile << "Battled rival and somehow won." << endl;
            break;

        case PRINT_TEAM:
            outputFile << "Pokemon on team: " << teamCount << endl;
            outputFile << "Battles won: " << battlesWon << endl;
            break;

        case HEAL_TEAM:
            outputFile << "Team healed. We hope to see you again!." << endl;
            break;

        default:
            outputFile << "Unknown command. Team Rocket probably typed it." << endl;
        }

        // get next command //
        inputFile >> command;
    }

    // close files //
    inputFile.close();
    outputFile.close();

    cout << "Check pokemon_report.txt" << endl;

    return 0;
}

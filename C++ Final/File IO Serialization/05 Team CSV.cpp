// Aidan Burmester //
// pokemon team csv //

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

// pokemon struct //
struct Pokemon
{
    string name;
    string type;
    int level;
};

// save team //
void saveTeam(vector<Pokemon>& team)
{
    ofstream outputFile;

    // open csv file //
    outputFile.open("team.csv");

    if (!outputFile)
    {
        cout << "Error opening team.csv" << endl;
        return;
    }

    // header row //
    outputFile << "name,type,level" << endl;

    // write each pokemon //
    for (int i = 0; i < team.size(); i++)
    {
        outputFile << team[i].name << "," << team[i].type << "," << team[i].level << endl;
    }

    outputFile.close();
}

// print team //
void printTeam(vector<Pokemon>& team)
{
    // write each pokemon //
    for (int i = 0; i < team.size(); i++)
    {
        cout << team[i].name << " | " << team[i].type << " | Level " << team[i].level << endl;
    }
}

// main //
int main()
{
    // make team vector //
    vector<Pokemon> team;

    cout << "Pokemon Team CSV" << endl << endl;

   // add pokemon to team //
Pokemon p1;
p1.name = "Charmander";
p1.type = "Fire";
p1.level = 16;
team.push_back(p1);

Pokemon p2;
p2.name = "Snorlax";
p2.type = "Normal";
p2.level = 30;
team.push_back(p2);

Pokemon p3;
p3.name = "Magikarp";
p3.type = "Water";
p3.level = 99;
team.push_back(p3);

    cout << "Team before saving:" << endl;
    printTeam(team);

    // save team as csv //
    saveTeam(team);

    cout << endl;
    cout << "team.csv was created." << endl;
    cout << "Yes Magikarp is level 99. Hes just built like that." << endl;

    return 0;
}

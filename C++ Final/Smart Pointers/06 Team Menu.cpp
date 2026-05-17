// Aidan Burmester //
// pokemon team builder with smart pointers //

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// pokemon class //
class Pokemon
{
private:
    string name;
    string type;
    int level;

public:
    Pokemon(string n, string t, int l)
    {
        name = n;
        type = t;
        level = l;
        cout << name << " joined the team." << endl;
    }

    ~Pokemon()
    {
        cout << name << " was removed from memory." << endl;
    }

    void train()
    {
        level++;
        cout << name << " trained to level " << level << "." << endl;
    }

    void print()
    {
        cout << name << " | " << type << " | Level " << level << endl;
    }
};

// print team //
void printTeam(vector<unique_ptr<Pokemon>>& team)
{
    cout << endl;
    cout << "Current Team" << endl;

    if (team.size() == 0)
    {
        cout << "No pokemon. This is just sad." << endl;
    }

    for (int i = 0; i < team.size(); i++)
    {
        cout << i + 1 << ". ";
        team[i]->print();
    }
}

// main //
int main()
{
    // team owns the pokemon //
    vector<unique_ptr<Pokemon>> team;
    int choice;

    cout << "Pokemon Team Builder" << endl;

    do
    {
        // menu choices //
        cout << endl;
        cout << "1. Add Pikachu" << endl;
        cout << "2. Add Charmander" << endl;
        cout << "3. Add Bulbasaur" << endl;
        cout << "4. Train everyone" << endl;
        cout << "5. Print team" << endl;
        cout << "6. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        // do the menu choice //
        switch (choice)
        {
        case 1:
            team.push_back(make_unique<Pokemon>("Pikachu", "Electric", 5));
            break;

        case 2:
            team.push_back(make_unique<Pokemon>("Charmander", "Fire", 5));
            break;

        case 3:
            team.push_back(make_unique<Pokemon>("Bulbasaur", "Grass", 5));
            break;

        case 4:
            // train every pokemon //
            for (int i = 0; i < team.size(); i++)
            {
                team[i]->train();
            }
            break;

        case 5:
            // print the whole team //
            printTeam(team);
            break;

        case 6:
            cout << "Leaving the team builder." << endl;
            break;

        default:
            cout << "That is not a choice. Professor Oak is disappointed." << endl;
        }

    } while (choice != 6);

    return 0;
}

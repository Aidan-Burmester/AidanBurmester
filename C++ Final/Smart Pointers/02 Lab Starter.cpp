#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Pokemon
{
private:
    string name;
    int level;

public:
    Pokemon(string n, int l)
    {
        name = n;
        level = l;
    }

    void showStats()
    {
        cout << name << " is level " << level << endl;
    }

    void train()
    {
        level++;
        cout << name << " trained to level " << level << endl;
    }
};

int main()
{
    cout << "unique_ptr Professor Lab" << endl << endl;

    // make pokemon with unique_ptr
    unique_ptr<Pokemon> starter = make_unique<Pokemon>("Charmander", 5);

    // show and train starter
    starter->showStats();
    starter->train();
    starter->train();

    // explain the point
    cout << endl;
    cout << "No delete is written in main." << endl;
    cout << "unique_ptr will clean it up when main ends." << endl;

    return 0;
}
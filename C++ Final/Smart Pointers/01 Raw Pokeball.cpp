// Aidan Burmester //
// raw pointer pokeball problem //

#include <iostream>
#include <string>
using namespace std;

// pokemon class //
class Pokemon
{
private:
    string name;
    string type;

public:
    Pokemon(string n, string t)
    {
        name = n;
        type = t;
        cout << name << " popped out of the pokeball." << endl;
    }

    ~Pokemon()
    {
        cout << name << " went back in the pokeball." << endl;
    }

    void attack()
    {
        cout << name << " used a very serious " << type << " move." << endl;
        cout << "It was probably super effective but I am not checking the chart." << endl;
    }
};

// main //
int main()
{
    cout << "Raw Pointer Pokeball Problem" << endl << endl;

    // make pokemon the old way (This dosnt sound weird at all) //
    Pokemon* starter = new Pokemon("Pikachu", "Electric");

    // use the pokemon (Neither does this)//
    starter->attack();

    cout << endl;
    cout << "Now I have to remember to delete the pokemon." << endl;
    cout << "If I forget this, the pokemon is just wandering RAM forever." << endl;

    // clean up the pokemon myself //
    delete starter;
    // make pointer point at nothing now //
    starter = nullptr;

    cout << endl;
    cout << "Pointer set to nullptr so I do not accidentally battle a som that dont exist." << endl;

    return 0;
}

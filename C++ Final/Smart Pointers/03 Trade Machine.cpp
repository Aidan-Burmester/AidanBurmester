// Aidan Burmester //
// unique pointer trade machine //

#include <iostream>
#include <memory>
#include <string>
#include <utility>
using namespace std;

// pokemon class //
class Pokemon
{
private:
    string name;
    string trainer;

public:
    Pokemon(string n, string t)
    {
        name = n;
        trainer = t;
        cout << name << " belongs to " << trainer << "." << endl;
    }

    ~Pokemon()
    {
        cout << name << " left the program safely." << endl;
    }

    void setTrainer(string t)
    {
        trainer = t;
    }

    void print()
    {
        cout << name << " is owned by " << trainer << "." << endl;
    }
};

// main //
int main()
{
    cout << "unique_ptr Trade Machine" << endl << endl;

    // make my pokemon //
    unique_ptr<Pokemon> myPokemon = make_unique<Pokemon>("Squirtle", "Aidan");

    cout << endl;
    cout << "Trading Squirtle to Brock cus I want an onix." << endl;

    // trade ownership with move //
unique_ptr<Pokemon> brocksPokemon = std::move(myPokemon);    brocksPokemon->setTrainer("Brock");

    cout << endl;

    // check if my pointer is empty //
    if (myPokemon == nullptr)
    {
        cout << "myPokemon is empty now. The trade actually happened." << endl;
    }

    // show new owner //
    brocksPokemon->print();

    cout << endl;
    cout << "unique_ptr can move ownership, but it cannot copy ownership." << endl;

    return 0;
}

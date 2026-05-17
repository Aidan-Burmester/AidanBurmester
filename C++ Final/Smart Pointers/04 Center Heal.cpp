// Aidan Burmester //
// shared pointer pokemon center //

#include <iostream>
#include <memory>
#include <string>
#include <vector>
using namespace std;

// healing machine class //
class HealingMachine
{
private:
    string name;

public:
    HealingMachine(string n)
    {
        name = n;
        cout << name << " turned on. Nurse Joy is locked in." << endl;
    }

    ~HealingMachine()
    {
        cout << name << " turned off. Time for a smoke break." << endl;
    }

    void heal(string pokemon)
    {
        cout << pokemon << " was healed by " << name << "." << endl;
    }
};

// trainer class //
class Trainer
{
private:
    string name;
    shared_ptr<HealingMachine> machine;

public:
    Trainer(string n, shared_ptr<HealingMachine> m)
    {
        name = n;
        machine = m;
    }

    void healPokemon(string pokemon)
    {
        cout << name << " walks up to the counter." << endl;
        machine->heal(pokemon);
    }
};

// main //
int main()
{
    cout << "shared_ptr Pokemon Center" << endl << endl;

    // make one shared healing machine //
    shared_ptr<HealingMachine> centerMachine = make_shared<HealingMachine>("Machine 1");

    cout << "Use count after making machine: " << centerMachine.use_count() << endl << endl;

    {
        // three trainers share it //
        Trainer ash("Ash", centerMachine);
        Trainer misty("Misty", centerMachine);
        Trainer brock("Brock", centerMachine);

        cout << "Use count while trainers are using it: " << centerMachine.use_count() << endl;

        // everybody heals their pokemon //
        ash.healPokemon("Pikachu");
        misty.healPokemon("Staryu");
        brock.healPokemon("Onix");

        cout << "Everybody is crowding the same machine." << endl << endl;
    }

    // count goes back down //
    cout << "Use count after trainers leave: " << centerMachine.use_count() << endl;
    cout << "The machine still exists because centerMachine still owns it." << endl;

    return 0;
}

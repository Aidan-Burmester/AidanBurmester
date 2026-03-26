#include <iostream>
#include <string>
using namespace std;

// CLASS DEFINITION //
class Rock {
public:

    // MELEE ATTACK //
    void attack() {
        cout << "Rock uses a melee attack ahh!" << endl;
    }

    // DAMAGE //
    void attack(int damage) {
        cout << "Rock attacks and deals some" << damage << " damage!" << endl;
    }

    // Spell ATTACK //
    void attack(string spell, int damage) {
        cout << "Rock casts" << spell << " and deals "
             << " special magic damage!" << endl;
    }
};

// MAIN FUNCTION //
int main() {

    // OBJECT CREATION //
    Rock myRock;

    // FUNCTION CALLS //
    myRock.attack();
    myRock.attack(25);
    myRock.attack(" ice beam", 50);

    return 0;
}
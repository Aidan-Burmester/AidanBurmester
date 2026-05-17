// Aidan Burmester //
// weak pointer rival problem //

#include <iostream>
#include <memory>
#include <string>
using namespace std;

class Rival;

// trainer class //
class Trainer
{
private:
    string name;

public:
    shared_ptr<Rival> rival;

    Trainer(string n)
    {
        name = n;
        cout << name << " entered the route." << endl;
    }

    ~Trainer()
    {
        cout << name << " left the route." << endl;
    }

    string getName()
    {
        return name;
    }
};

// rival class //
class Rival
{
private:
    string name;
    weak_ptr<Trainer> trainer;

public:
    Rival(string n)
    {
        name = n;
        cout << name << " appeared and said something rude." << endl;
    }

    ~Rival()
    {
        cout << name << " stopped blocking the path." << endl;
    }

    void setTrainer(shared_ptr<Trainer> t)
    {
        trainer = t;
    }

    void talkTrash()
    {
        shared_ptr<Trainer> temp = trainer.lock();

        if (temp)
        {
            cout << name << " says: Your starter didnt bond with you. It developed Stockholm Syndrome, " << temp->getName() << "!" << endl;
        }
        else
        {
            cout << name << " has nobody to annoy." << endl;
        }
    }
};

// main //
int main()
{
    cout << "weak_ptr Rival Problem" << endl << endl;

    // make player and rival //
    shared_ptr<Trainer> player = make_shared<Trainer>("Aidan");
    shared_ptr<Rival> rival = make_shared<Rival>("Gary");

    // connect them together //
    player->rival = rival;
    rival->setTrainer(player);

    // use weak_ptr safely //
    rival->talkTrash();

    // explain why weak_ptr matters //
    cout << endl;
    cout << "The rival uses weak_ptr so he does not keep the trainer alive forever." << endl;
    cout << "That is good because Gary is annoying enough already and I hate him." << endl;

    return 0;
}

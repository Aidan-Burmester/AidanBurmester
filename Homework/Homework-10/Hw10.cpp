#include <iostream>
#include <string>
using namespace std;

// Aidan Burmester

// base class //
class Pokemon {
protected:
    string name;
    int level;
    string type;

public:
    Pokemon(const string& name, int level, const string& type)
        : name(name), level(level), type(type) {}

    virtual ~Pokemon() {
        cout << name << " has fainted!" << endl;
    }

    // display info //
    void display() const {
        cout << "Name: " << name
             << ", Level: " << level
             << ", Type: " << type << endl;
    }

    // polymorphism functions //
    virtual void attack() const = 0;
    virtual void defend() const = 0;
    virtual void evolve() = 0;
};

// type classes //
class ElectricPokemon : public Pokemon {
public:
    ElectricPokemon(const string& name, int level)
        : Pokemon(name, level, "Electric") {}
};

class FirePokemon : public Pokemon {
public:
    FirePokemon(const string& name, int level)
        : Pokemon(name, level, "Fire") {}
};

class GrassPokemon : public Pokemon {
public:
    GrassPokemon(const string& name, int level)
        : Pokemon(name, level, "Grass") {}
};

// pikachu //
class Pikachu : public ElectricPokemon {
public:
    Pikachu(int level) : ElectricPokemon("Pikachu", level) {}

    void attack() const override {
        cout << name << " uses Thunderbolt!" << endl;
    }

    void defend() const override {
        cout << name << " Attack missed!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Raichu!" << endl;
        name = "Raichu";
    }

    ~Pikachu() {
        cout << name << ", you put up a good fight. come back!" << endl;
    }
};

// charmander //
class Charmander : public FirePokemon {
public:
    Charmander(int level) : FirePokemon("Charmander", level) {}

    void attack() const override {
        cout << name << " uses Flamethrower!" << endl;
    }

    void defend() const override {
        cout << name << " blocks the attack!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Charmeleon!" << endl;
        name = "Charmeleon";
    }
};

// bulbasaur //
class Bulbasaur : public GrassPokemon {
public:
    Bulbasaur(int level) : GrassPokemon("Bulbasaur", level) {}

    void attack() const override {
        cout << name << " uses Vine Whip!" << endl;
    }

    void defend() const override {
        cout << name << " used Protect!" << endl;
    }

    void evolve() override {
        cout << name << " evolves into Ivysaur!" << endl;
        name = "Ivysaur";
    }
};

// main //
int main() {
    Pikachu pikachu(10);
    Charmander charmander(12);
    Bulbasaur bulbasaur(8);

    Pokemon* pokemons[] = { &pikachu, &charmander, &bulbasaur };

    cout << "=== Pokemon Battle ===" << endl;

    for (Pokemon* p : pokemons) {
        p->display();
        p->attack();
        p->defend();
        p->evolve();
        p->display();
        cout << endl;
    }

    return 0;
}
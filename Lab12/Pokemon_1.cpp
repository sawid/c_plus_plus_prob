#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

class Pokemon {
protected:
    std::string name;
    std::string sound;
    std::string type;
    int power;
    int speed;

public:
    Pokemon(const std::string& name, const std::string& sound, const std::string& type, int power, int speed)
        : name(name), sound(sound), type(type), power(power), speed(speed) {}

    std::string getName() const {
        return name;
    }

    std::string getSound() const {
        return sound;
    }

    std::string getType() const {
        return type;
    }

    int getPower() const {
        return power;
    }

    int getSpeed() const {
        return speed;
    }
};

class WildPokemon : public Pokemon {
private:
    int catchRate;

public:
    WildPokemon(const std::string& name, const std::string& sound, const std::string& type, int power, int speed, int catchRate)
        : Pokemon(name, sound, type, power, speed), catchRate(catchRate) {}

    int getCatchRate() const {
        return catchRate;
    }

    bool attemptEscape() const {
        return rand() % 2 == 0; // Simulating escape behavior
    }
};

class PalPokemon : public Pokemon {
public:
    PalPokemon(const std::string& name, const std::string& sound, const std::string& type, int power, int speed)
        : Pokemon(name, sound, type, power, speed) {}
};

class Pokeball {
private:
    std::string name;
    int efficiency;

public:
    Pokeball(const std::string& name, int efficiency) : name(name), efficiency(efficiency) {}

    const std::string& getName() const {
        return name;
    }

    int getEfficiency() const {
        return efficiency;
    }

    bool catchPokemon(const WildPokemon& pokemon) const {
        int catchProbability = rand() % 100 + 1;
        return catchProbability <= efficiency * pokemon.getCatchRate();
    }
};

class Berry {
private:
    std::string name;
    int effectiveness;

public:
    Berry(const std::string& name, int effectiveness) : name(name), effectiveness(effectiveness) {}

    const std::string& getName() const {
        return name;
    }

    int getEffectiveness() const {
        return effectiveness;
    }
};

class Player {
private:
    std::vector<Pokeball> pokeballs;
    Berry berry;

public:
    Player() : berry("Default Berry", 0) {}

    void addPokeball(const Pokeball& pokeball) {
        pokeballs.push_back(pokeball);
    }

    bool catchPokemon(const WildPokemon& pokemon) {
        if (pokeballs.empty()) {
            std::cout << "No pokeballs available. Can't catch Pokemon." << std::endl;
            return false;
        }

        Pokeball& selectedPokeball = pokeballs.back();
        bool caught = selectedPokeball.catchPokemon(pokemon);

        if (caught) {
            pokeballs.pop_back();
            std::cout << "Caught " << pokemon.getName() << "!" << std::endl;
        } else {
            std::cout << "The Pokemon escaped." << std::endl;
        }

        return caught;
    }

    void setBerry(const Berry& berry) {
        this->berry = berry;
    }

    const Berry& getBerry() const {
        return berry;
    }
};

class World {
private:
    std::vector<WildPokemon> wildPokemons;

public:
    void addWildPokemon(const WildPokemon& pokemon) {
        wildPokemons.push_back(pokemon);
    }

    WildPokemon& getRandomWildPokemon() {
        int index = rand() % wildPokemons.size();
        return wildPokemons[index];
    }
};

class GameTester {
public:
    static void testCatchMechanics(Player& player, World& world) {
        std::cout << "Encountered a wild Pidgey!" << std::endl;
        WildPokemon& wildPidgey = world.getRandomWildPokemon();

        if (player.catchPokemon(wildPidgey)) {
            std::cout << "The player successfully caught a Pokemon." << std::endl;
        }
    }

    static void testEscapeMechanics(Player& player, World& world) {
        std::cout << "Encountered a wild Abra!" << std::endl;
        WildPokemon& wildAbra = world.getRandomWildPokemon();

        if (wildAbra.attemptEscape()) {
            std::cout << "The Pokemon escaped." << std::endl;
        }
    }
};

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    // Create wild Pokemons
    WildPokemon pidgey("Pidgey", "Pidgey sound", "Normal", 30, 60, 50);
    WildPokemon abra("Abra", "Abra sound", "Psychic", 40, 80, 70);

    // Create pokeballs
    Pokeball greatBall("Great Ball", 20);

    // Create player
    Player player;

    // Add pokeball to the player's collection
    player.addPokeball(greatBall);

    // Create world
    World world;
    world.addWildPokemon(pidgey);
    world.addWildPokemon(abra);

    // Run tests
    GameTester::testCatchMechanics(player, world);
    std::cout << "------------------------------" << std::endl;
    GameTester::testEscapeMechanics(player, world);

    return 0;
}

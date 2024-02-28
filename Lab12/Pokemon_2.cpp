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
    std::vector<PalPokemon> caughtPokemon;
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
            caughtPokemon.push_back(PalPokemon(pokemon.getName(), pokemon.getSound(), pokemon.getType(), pokemon.getPower(), pokemon.getSpeed()));
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

    void listPokeballs() const {
        std::cout << "Player’s Pokeballs:\n";
        for (const auto& pokeball : pokeballs) {
            std::cout << pokeball.getName() << " (Efficiency: " << pokeball.getEfficiency() << ")\n";
        }
    }

    void listCaughtPokemon() const {
        std::cout << "Caught Pokémon:\n";
        for (const auto& pokemon : caughtPokemon) {
            std::cout << pokemon.getName() << "\n";
        }
    }

    void stockPokeballs() {
        // Logic to stockpile five random pokeballs to inventory
        for (int i = 0; i < 5; ++i) {
            int efficiency = rand() % 50 + 1; // Random efficiency between 1 and 50
            std::string ballName = "Random Pokeball"; // You can modify this based on your requirement
            pokeballs.push_back(Pokeball(ballName, efficiency));
        }
        std::cout << "Added five random pokeballs to your inventory.\n";
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

    bool allWildPokemonCaptured() const {
        return wildPokemons.empty();
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

    while (true) {
        std::cout << "Choose an action:\n"
                  << "1. Add Pokéballs to stock\n"
                  << "2. Walk\n"
                  << "3. List Pokeballs\n"
                  << "4. List caught Pokemon\n"
                  << "5. Exit\n";

        int choice;
        std::cin >> choice;

        switch (choice) {
            case 1: {
                player.stockPokeballs();
                break;
            }
            case 2: {
                if (!world.allWildPokemonCaptured()) {
                    // Logic for walking and encountering wild Pokémon
                    WildPokemon& wildPokemon = world.getRandomWildPokemon();
                    std::cout << "Encountered a wild " << wildPokemon.getName() << "!\n";

                    // Implement logic to attempt to catch the wild Pokémon
                    if (player.catchPokemon(wildPokemon)) {
                        // std::cout << "Caught " << wildPokemon.getName() << "!\n";
                        if (world.allWildPokemonCaptured()) {
                            std::cout << "All wild Pokémon in the world have been captured. Game over!\n";
                            return 0;
                        }
                    } else {
                        std::cout << "No Pokeballs left or the Pokémon escaped.\n";
                    }
                } else {
                    std::cout << "No more wild Pokémon in the world. Game over!\n";
                    return 0;
                }
                break;
            }
            case 3: {
                player.listPokeballs();
                break;
            }
            case 4: {
                player.listCaughtPokemon();
                break;
            }
            case 5: {
                std::cout << "Exiting the game. Goodbye!\n";
                return 0;
            }
            default: {
                std::cout << "Invalid choice. Please try again.\n";
            }
        }
    }

    return 0;
}

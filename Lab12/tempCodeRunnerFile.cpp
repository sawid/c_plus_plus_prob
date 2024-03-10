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

    void applyEffect(Pokeball& pokeball) const {
        pokeball.setEfficiency(pokeball.getEfficiency() + effectiveness);
    }

    void applyEffect(WildPokemon& pokemon) const {
        pokemon.setCatchRate(pokemon.getCatchRate() - effectiveness);
    }
};

class Player {
private:
    std::vector<Pokeball> pokeballs;
    Berry berry;

public:
    Player() {}

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
};
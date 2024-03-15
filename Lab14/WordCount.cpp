#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class Mapper {
public:
    std::vector<std::pair<std::string, int>> map(const std::string& line) {
        std::vector<std::pair<std::string, int>> pairs;
        std::string word;
        for (char c : line) {
            if (isalpha(c)) {
                word += tolower(c);
            } else if (!word.empty()) {
                pairs.emplace_back(word, 1);
                word.clear();
            }
        }
        if (!word.empty()) {
            pairs.emplace_back(word, 1);
        }
        return pairs;
    }
};

class Reducer {
public:
    std::vector<std::pair<std::string, int>> reduce(std::vector<std::pair<std::string, int>>& pairs) {
        std::vector<std::pair<std::string, int>> counts;
        std::sort(pairs.begin(), pairs.end());
        for (auto it = pairs.begin(); it != pairs.end(); /* empty */) {
            auto word = it->first;
            int count = 0;
            while (it != pairs.end() && it->first == word) {
                count += it->second;
                ++it;
            }
            counts.emplace_back(word, count);
        }
        return counts;
    }
};

int main() {
    std::string filename;
    std::cout << "Enter the name of the text file: ";
    std::cin >> filename;
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error opening file: " << filename << std::endl;
        return 1;
    }

    Mapper mapper;
    Reducer reducer;
    std::vector<std::pair<std::string, int>> pairs;
    std::string line;
    while (std::getline(file, line)) {
        auto mapped_pairs = mapper.map(line);
        pairs.insert(pairs.end(), mapped_pairs.begin(), mapped_pairs.end());
    }

    auto counts = reducer.reduce(pairs);

    std::string output_filename = filename + "_mr.txt";
    std::ofstream output_file(output_filename);
    if (!output_file) {
        std::cerr << "Error creating output file: " << output_filename << std::endl;
        return 1;
    }

    for (const auto& [word, count] : counts) {
        std::cout << word << " " << count << std::endl;
        output_file << word << " " << count << std::endl;
    }

    return 0;
}

#include <iostream>
#include <string>

class QuizQuestion {
private:
    std::string question;
    std::string choices[3];
    char correctAnswer;

public:
    QuizQuestion(const std::string& q, const std::string& c1, const std::string& c2, const std::string& c3, char correct)
        : question(q), correctAnswer(correct) {
        choices[0] = c1;
        choices[1] = c2;
        choices[2] = c3;
    }

    void displayQuestion() const {
        std::cout << question << std::endl;
        for (int i = 0; i < 3; ++i) {
            std::cout << static_cast<char>('a' + i) << ") " << choices[i] << std::endl;
        }
    }

    bool checkAnswer(char userAnswer) const {
        return userAnswer == correctAnswer;
    }
};

int main() {
    int score = 0;
    QuizQuestion questions[] = {
        {"What is the capital of France?", "Berlin", "Paris", "London", 'b'},
        {"Which planet is known as the Red Planet?", "Mars", "Jupiter", "Saturn", 'a'},
        {"What is the largest mammal?", "Elephant", "Blue Whale", "Giraffe", 'b'},
        {"Who wrote 'Hamlet'?", "Mark Twain", "Charles Dickens", "William Shakespeare", 'c'},
        {"What is the chemical symbol for water?", "H2O", "CO2", "O2", 'a'}
    };

    for (int i = 0; i < 5; ++i) {
        questions[i].displayQuestion();

        char userAnswer;
        std::cout << "Your answer (a, b, or c): ";
        std::cin >> userAnswer;

        switch (userAnswer) {
            case 'a':
            case 'b':
            case 'c':
                if (questions[i].checkAnswer(userAnswer)) {
                    std::cout << "Correct!\n";
                    score++;
                } else {
                    std::cout << "Wrong answer.\n";
                }
                break;
            default:
                std::cout << "Invalid input. Please enter a, b, or c.\n";
                i--;  // Repeat the same question
        }
    }

    std::cout << "Quiz completed! Your total score: " << score << "/5\n";

    return 0;
}

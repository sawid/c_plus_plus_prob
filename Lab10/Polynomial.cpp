#include <iostream>
#include <vector>
#include <algorithm>

class Term {
public:
    int coefficient;
    int exponent;

    Term(int coeff, int exp) : coefficient(coeff), exponent(exp) {}
};

class Polynomial {
private:
    std::vector<Term> terms;

public:
    // Constructor
    Polynomial() {}

    // Destructor
    ~Polynomial() {}

    // Set coefficients and exponents
    void setPoly(int coeff, int exp) {
        terms.push_back(Term(coeff, exp));
        sortTerms();
        combineLikeTerms();
    }

    // Operator Overloading for Addition
    Polynomial operator+(const Polynomial& other) const {
        Polynomial result = *this;
        for (const auto& term : other.terms) {
            result.terms.push_back(term);
        }
        result.sortTerms();
        result.combineLikeTerms();
        return result;
    }

    // Operator Overloading for Subtraction
    Polynomial operator-(const Polynomial& other) const {
        Polynomial result = *this;
        for (const auto& term : other.terms) {
            result.terms.push_back(Term(-term.coefficient, term.exponent));
        }
        result.sortTerms();
        result.combineLikeTerms();
        return result;
    }

    // Operator Overloading for Multiplication
    Polynomial operator*(const Polynomial& other) const {
        Polynomial result;
        for (const auto& term1 : terms) {
            for (const auto& term2 : other.terms) {
                result.terms.push_back(Term(term1.coefficient * term2.coefficient, term1.exponent + term2.exponent));
            }
        }
        result.sortTerms();
        result.combineLikeTerms();
        return result;
    }

    // Sort terms in descending order of exponents
    void sortTerms() {
        std::sort(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
            return a.exponent > b.exponent;
        });
    }

    // Combine like terms
    void combineLikeTerms() {
        auto it = std::unique(terms.begin(), terms.end(), [](const Term& a, const Term& b) {
            return a.exponent == b.exponent;
        });
        terms.erase(it, terms.end());
    }

    // Display the polynomial
    friend std::ostream& operator<<(std::ostream& os, const Polynomial& poly) {
        for (const auto& term : poly.terms) {
            if (term.coefficient > 0) {
                os << "+" << term.coefficient;
            } else {
                os << term.coefficient;
            }
            os << "x^" << term.exponent << " ";
        }
        return os;
    }
};

int main() {
    Polynomial p1, p2, p3, p4, p5;

    p1.setPoly(2, 3);
    p1.setPoly(4, 1);

    p2.setPoly(3, 2);
    p2.setPoly(5, 0);

    p3 = p1 + p2;
    p4 = p1 - p2;
    p5 = p1 * p2;

    std::cout << "Polynomial p1: " << p1 << std::endl;
    std::cout << "Polynomial p2: " << p2 << std::endl;
    std::cout << "Polynomial p3 (p1 + p2): " << p3 << std::endl;
    std::cout << "Polynomial p4 (p1 - p2): " << p4 << std::endl;
    std::cout << "Polynomial p5 (p1 * p2): " << p5 << std::endl;

    return 0;
}

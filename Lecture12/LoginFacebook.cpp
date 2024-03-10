#include <iostream>
#include <string>

class LoginProcessor {
public:
    virtual bool login(const std::string& email, const std::string& password) const = 0;
};

class FacebookLoginProcessor : public LoginProcessor {
public:
    bool login(const std::string& email, const std::string& password) const override {
        // Simulating the login process (checking if the credentials are valid).
        if (isValidCredentials(email, password)) {
            displayProfile();
            return true;
        } else {
            std::cout << "Login error: Invalid credentials. Please re-enter Email ID and Password." << std::endl;
            return false;
        }
    }

private:
    bool isValidCredentials(const std::string& email, const std::string& password) const {
        // Check if the credentials are valid (simplified logic).
        return (email == "example@email.com" && password == "password123");
    }

    void displayProfile() const {
        // Display the Facebook profile (simplified logic).
        std::cout << "Welcome to your Facebook profile!" << std::endl;
    }
};

int main() {
    // Create an instance of LoginProcessor (polymorphic behavior).
    LoginProcessor* loginProcessor = new FacebookLoginProcessor();

    // Simulate the Facebook login process.
    std::string email, password;
    std::cout << "Enter your Email ID: ";
    std::cin >> email;
    std::cout << "Enter your Password: ";
    std::cin >> password;

    // Perform the login.
    loginProcessor->login(email, password);

    // Clean up allocated memory.
    delete loginProcessor;

    return 0;
}

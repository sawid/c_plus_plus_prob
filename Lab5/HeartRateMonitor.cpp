#include <iostream>
#include <string>
#include <ctime>

using namespace std;

class Date {
public:
    int year, month, day;

    Date(int y, int m, int d) : year(y), month(m), day(d) {}
};

class HeartRateMonitor
{
private:
    string firstName;
    string lastName;
    Date birthDate;
    int age;
    int maxHeartRate;
    int targetHeartRateMin;
    int targetHeartRateMax;
public:
    HeartRateMonitor(const string& fName, const string& lName, const Date& bDate)
        : firstName(fName), lastName(lName), birthDate(bDate)
    {
        calculateAge();
        calculateHeartRates();
    }

    void calculateAge() {
        Date currentDate(2023, 12, 28);

        age = currentDate.year - birthDate.year;

        if (currentDate.month < birthDate.month ||
            (currentDate.month == birthDate.month && currentDate.day < birthDate.day)) {
            age--;
        }
    }

    void calculateHeartRates() {
        maxHeartRate = 220 - age;
        targetHeartRateMin = static_cast<int>(0.5 * maxHeartRate);
        targetHeartRateMax = static_cast<int>(0.85 * maxHeartRate);
    }

    void displayInformation() {
        cout << "Name: " << firstName << " " << lastName << endl;
        cout << "Age: " << age << " years" << endl;
        cout << "Max Heart Rate: " << maxHeartRate << " bpm" << endl;
        cout << "Target Heart Rate Range: " << targetHeartRateMin << " to "
                  << targetHeartRateMax << " bpm" << endl;
    }

};

int main()
{
    string firstName, lastName;
    int birthYear, birthMonth, birthDay;

    cout << "Enter your first name: ";
    cin >> firstName;
    cout << "Enter your last name: ";
    cin >> lastName;
    cout << "Enter your birth year: ";
    cin >> birthYear;
    cout << "Enter your birth month: ";
    cin >> birthMonth;
    cout << "Enter your birth day: ";
    cin >> birthDay;

    HeartRateMonitor userMonitor(firstName, lastName, Date(birthYear, birthMonth, birthDay));

    userMonitor.displayInformation();
    return 0;
}

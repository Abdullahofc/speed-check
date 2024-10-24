#include <iostream>
#include <vector>
#include <string>

class Car
{
    public:
    Car(std::string licensePlate) : licensePlate(licensePlate) { }

    void checkSpeed(int speed, int speedLimit)
    {
        speedRecords.push_back(speed);
        if (speed > speedLimit)
        {
            int fine = calculateFine(speed, speedLimit);
            std::cout << "Car " << licensePlate << " is fined $" << fine
                      << ". Speed: " << speed << " km/h (Limit: " << speedLimit << " km/h)" << std::endl;
        }
        else
        {
            std::cout << "Car " << licensePlate << " is within the speed limit. Speed: "
                      << speed << " km/h (Limit: " << speedLimit << " km/h)" << std::endl;
        }
    }

    void displaySpeedRecords() const {
        std::cout << "Speed records for car " << licensePlate << ": ";
        for (int speed : speedRecords) {
            std::cout << speed << " ";
        }
std::cout << std::endl;
    }

private:
    std::string licensePlate;
std::vector<int> speedRecords;

int calculateFine(int speed, int speedLimit)
{
    int excessSpeed = speed - speedLimit;
    return excessSpeed * 10;
}
};

int main()
{
    const int speedLimit = 60;
    std::vector<Car> cars;
    cars.emplace_back("ABC123");
    cars.emplace_back("XYZ456");
    std::vector<int> carSpeeds = { 70, 50, 80, 55 };

    for (size_t i = 0; i < cars.size() && i < carSpeeds.size(); ++i)
    {
        cars[i].checkSpeed(carSpeeds[i], speedLimit);
    }

    for (const auto&car : cars) {
        car.displaySpeedRecords();
    }

    return 0;
}

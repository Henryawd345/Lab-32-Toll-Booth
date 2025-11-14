#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_SIZE = 2;

void printQueue(const deque<Car> &lane){
    cout << "Queue: \n";
    if (lane.empty()){
        cout << "   Empty\n";
        return;
    }

    for (Car c : lane){
        cout << "    ";
        c.print();
    }

}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    deque<Car> lane;

    for (int i = 0; i < INITIAL_SIZE; i++){
        lane.push_back(Car());
    }

    cout << "Initial queue:\n";
    printQueue(lane);
    cout << endl;

    int timeStep = 1;

    while (!lane.empty()){
        int roll = rand() % 100;

        if (roll < 55 && !lane.empty()){
            Car payingCar = lane.front();
            lane.pop_front();

            cout << "Time: " << timeStep << " Operation: Car paid: ";
            cout << "[" << payingCar.getYear()
                 << " " << payingCar.getMake()
                 << " (" << payingCar.getTransponder() << ")]\n";
        } else {
            Car newCar;
            lane.push_back(newCar);

            cout << "Time: " << timeStep << " Operation: Joined lane: ";
            cout << "[" << newCar.getYear()
                 << " " << newCar.getMake()
                 << " (" << newCar.getTransponder() << ")]\n";
        }

        printQueue(lane);
        cout << endl;

        timeStep++;

    }

    return 0;
}

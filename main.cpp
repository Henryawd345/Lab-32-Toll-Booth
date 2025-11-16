#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_SIZE = 2;
const int NR_LANES = 4;

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

    deque<Car> lanes[NR_LANES];

    for (int i = 0; i < NR_LANES; i++){
        lanes.push_back(Car());
    }

    cout << "Initial queue:\n";
    printQueue(lanes);
    cout << endl;

    int timeStep = 1;

    while (!lanes.empty()){
        int roll = rand() % 100;

        if (roll < 55 && !lanes.empty()){
            Car payingCar = lanes.front();
            lanes.pop_front();

            cout << "Time: " << timeStep << " Operation: Car paid: ";
            cout << "[" << payingCar.getYear()
                 << " " << payingCar.getMake()
                 << " (" << payingCar.getTransponder() << ")]\n";
        } else {
            Car newCar;
            lanes.push_back(newCar);

            cout << "Time: " << timeStep << " Operation: Joined lane: ";
            cout << "[" << newCar.getYear()
                 << " " << newCar.getMake()
                 << " (" << newCar.getTransponder() << ")]\n";
        }

        printQueue(lanes);
        cout << endl;

        timeStep++;

    }

    return 0;
}

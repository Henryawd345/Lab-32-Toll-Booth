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

void printInitialQueues(deque<Car> lanes[], int nrlanes){
    cout << "Initial Queue:\n";

}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    deque<Car> lanes[NR_LANES];

    for (int i = 0; i < NR_LANES; i++){
        lanes[i].push_back(Car());
    }

    cout << "Testing lane: \n\n";
    for (int i = 0; i< NR_LANES; i++)
    {
        cout << "Lane " << i + 1 << ":\n";
        printQueue(lanes[i]);
        cout << endl;
    }

    printInitialQueues(lanes, NR_LANES);

    return 0;
}

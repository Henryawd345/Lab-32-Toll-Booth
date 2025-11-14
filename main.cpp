#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

int INITIAL_SIZE = 2;

void printQueue(const deque<Car> &lane){
    cout << "Queue: \n";
    if (lane.empty()){
        cout << "   Empty\n";
        return;
    }

    for (const Car &c : lane){
        cout << "    ";
        c.print();
    }

}

int main() {
    

    return 0;
}

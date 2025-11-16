#include <iostream>
#include <deque>
#include <cstdlib>
#include <ctime>
#include "Car.h"

using namespace std;

const int INITIAL_SIZE = 2;
const int NR_LANES = 4;
const int TOTAL_TIME   = 20;

const int PROB_PAY    = 46; 
const int PROB_JOIN   = 39; 
const int PROB_SWITCH = 15;


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
    for (int i = 0; i < nrlanes; i++)
    {
        cout << "Lane " << i+1 << ":\n";
        printQueue(lanes[i]);
    }
    cout << endl;

}

int main() {
    srand(static_cast<unsigned int>(time(nullptr)));

    deque<Car> lanes[NR_LANES];

    for (int i = 0; i < NR_LANES; i++){
        for (int j = 0; j < INITIAL_SIZE; j++)
        {
            lanes[i].push_back(Car());
        }
    }

    printInitialQueues(lanes, NR_LANES);

    for (int timeStep = 1; timeStep <= TOTAL_TIME; timeStep++){
        cout << "Time: " << timeStep << "\n";

        for (int i = 0; i < NR_LANES; i++)
        {
            cout << "Lane: " << i+1 << " ";

            int roll = rand() % 100;
            if(lanes[i].empty()){
                if (roll < 50)
                {
                    Car newCar;
                    lanes[i].push_back(newCar);
                    cout << "Joined: ["
                         << newCar.getYear() << " "
                         << newCar.getMake() << " ("
                         << newCar.getTransponder() << ")]\n";
                } else {
                    cout << "No action ";
                }
            } else{
                if (roll < PROB_PAY){
                    Car payingCar = lanes[i].front();
                    lanes[i].pop_front();
                    cout << "Paid: ["
                         << payingCar.getYear() << " "
                         << payingCar.getMake() << " ("
                         << payingCar.getTransponder() << ")]\n";
                }
                
            }
        }
        for (int i = 0; i < NR_LANES; i++)
        {
            cout << "Lane " << i + 1 << " Queue:\n";
            printQueue(lanes[i]);
        }
        
        cout << endl;
    }
    

    return 0;
}

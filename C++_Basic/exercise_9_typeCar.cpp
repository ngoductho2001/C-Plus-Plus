#include<stdio.h>
#include<stdint.h>
#include<string>

using namespace std;

class Car{
    private:
        string color;
        string engine;
        int distance;
    public:
        Car();
        void setCar();
        void maintenanceCost();
        void checkDistance();
        void showInformationCar();
};

Car::Car(){
    this -> color = " ";
    this -> engine= " ";
    this -> distance = 0;
}

void Car::setCar(){
    printf("Enter color of your car:");
    scanf("%s", &(this -> color));
    printf("Enter engine of your car:");
    scanf("%s", &(this -> engine));
    printf("Enter the distance your car ha traveled:");
    scanf("%d", &(this -> distance));
}

void Car::maintenanceCost(){
    
}
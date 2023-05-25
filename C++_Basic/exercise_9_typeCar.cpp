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
        int maintenanceCost();
        void checkDistance();
        void showInformationCar();
        void setCar();
};

Car::Car(){
    this->color = "";
    this->engine= "";
    this->distance = 0;
}

void Car::setCar(){
    printf("Enter color of your car:");
    scanf("%s", &(this->color));
    printf("Enter engine of your car:");
    scanf("%s", &(this->engine));
    printf("Enter the distance your car ha traveled:");
    scanf("%d", &(this->distance));
    
}

int Car::maintenanceCost(){
    return distance * 12;
}

void Car::checkDistance(){
    printf("Current kilometer: %d",this->distance);
}

void Car::showInformationCar(){
    printf("Color: %s\n", this->color.c_str());
    printf("Engine: %s\n", this->engine.c_str());
    printf("Kilometer: %d\n", this->distance);
}

int main(){
    Car car;
    car.setCar();
    car.showInformationCar();
    car.checkDistance();
}

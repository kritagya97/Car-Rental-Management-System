#ifndef CAR_H_INCLUDED
#define CAR_H_INCLUDED

#include<iostream>
#include<fstream>
#include<ctime>
using namespace std;
class Car{
private:
    int carID;
    string NID,phone;
    char brand[50],model[50],name[60],address[100];
    float rentPerDay;
    bool isAvailable;
    char carNumber[20];
    int startDay = 0;
    int startMonth = 0;
    int startYear = 0;
public:
void displayCar();
void readAllCars();
void addCar();
void reserveCar();
void cancelReservation();
void deleteCar();
void updateCar();
void applyDiscount();
void returnCar();


};


#endif // CAR_H_INCLUDED

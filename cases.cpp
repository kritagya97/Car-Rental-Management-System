#include"cases.h"

//for admin operations.
int Cases::switch_cases(int choice){
switch(choice){
case 2:
    car.addCar();
    break;
case 3:
    car.readAllCars();
    break;
case 4:
    car.reserveCar();
    break;
case 5:
    car.cancelReservation();
    break;
case 6:
    car.returnCar();
    break;
case 7:
    car.updateCar();
    break;
case 8:
    car.deleteCar();
    break;
case 9:
    car.applyDiscount();
    break;
case 99:
    return 0;
    break;
default:
    cout<<"\t\t\t choose correct operation:"<<endl;
}
return 0;
}


//for employee operations.
int Cases::emp_cases(int choice){
switch(choice){
case 1:
    car.readAllCars();
    break;
case 2:
    car.reserveCar();
    break;
case 3:
    car.cancelReservation();
    break;
case 4:
    car.returnCar();
    break;
case 99:
    return 0;
    break;
default:
    cout<<"\t\t\t choose correct operation:"<<endl;
    }

    return 0;
}

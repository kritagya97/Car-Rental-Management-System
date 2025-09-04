#include "car.h"

int daysBetween(int sDay, int sMonth, int sYear, int rDay, int rMonth, int rYear) {
    int daysInMonth[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
    int startDays = sYear * 365 + sDay;
    for (int i = 0; i < sMonth - 1; i++) startDays += daysInMonth[i];

    int returnDays = rYear * 365 + rDay;
    for (int i = 0; i < rMonth - 1; i++) returnDays += daysInMonth[i];

    int diff = returnDays - startDays;
    return (diff > 0) ? diff + 1 : 1;
}

bool isValidDate(int day, int month, int year) {
    time_t now = time(0);
    tm* localTime = localtime(&now);

    int currentDay = localTime->tm_mday;
    int currentMonth = localTime->tm_mon + 1;
    int currentYear = localTime->tm_year + 1900;

    if (year < currentYear) return false;
    if (year == currentYear && month < currentMonth) return false;
    if (year == currentYear && month == currentMonth && day < currentDay) return false;

    return true;
}


void Car::addCar() {
    cout << "\t\t\tEnter Car ID: ";
    cin >> carID;
    cout << "\t\t\tEnter Brand (no spaces): ";
    cin >> brand;
    cout << "\t\t\tEnter Model (no spaces): ";
    cin >> model;
    cout << "\t\t\tEnter Car Number: ";
    cin >> carNumber;
    cout << "\t\t\tEnter Rent per Day: ";
    cin >> rentPerDay;
    isAvailable = true;
    startDay = 0;
    startMonth = 0;
    startYear = 0;
    displayCar();

    ofstream fout("cars.txt", ios::app);
    fout << carID << " " << brand << " " << model << " " << carNumber << " "<< rentPerDay << " " << isAvailable << " " << startDay << " " << startMonth << " " << startYear << " "<< name <<" "<< address << " " << phone << " " << NID <<endl;
    fout.close();
    cout << "\t\t\tCar added.\n";
}

void Car::displayCar() {
    cout << "\n\t\t\t------------------------------\n";
    cout << "\t\t\tCar ID           : " <<carID<< endl;
    cout << "\t\t\tBrand            : " <<brand<< endl;
    cout << "\t\t\tModel            : " <<model<< endl;
    cout << "\t\t\tCar Number       : " <<carNumber<< endl;
    cout << "\t\t\tRent/Day         : Rs." <<rentPerDay<< endl;
    cout << "\t\t\tAvailable        : " <<(isAvailable ? "Yes" : "No") << endl;
    if (!isAvailable) {
    cout << "\t\t\tReserved From    : " <<startDay << "/" << startMonth << "/" << startYear << endl;
    cout << "\t\t\tReserved by      : " <<name<<endl;
    cout << "\t\t\tAddress          : " <<address<<endl;
    cout << "\t\t\tPhone_no         : " <<phone<<endl;
    cout << "\t\t\tNID Card number  : " <<NID<<endl;
    }
}

void Car::readAllCars() {
    ifstream fin("cars.txt");
    cout << "\n\t\t\t--- All Cars from File ---\n";
    while (fin >> carID >> brand >> model >> carNumber >> rentPerDay >> isAvailable >> startDay >> startMonth >> startYear >> name >> address >> phone >> NID) {
        displayCar();
    }
    fin.close();
}

void Car::returnCar() {
    int id;
    cout << "\t\t\tEnter Car ID to return: ";
    cin >> id;

    ifstream fin("cars.txt");
    ofstream fout("temp.txt");
    bool found = false;

    while (fin >> carID >> brand >> model >> carNumber >> rentPerDay >> isAvailable >> startDay >> startMonth >> startYear >> name >> address >> phone >> NID ) {
        if (carID == id) {
            found = true;
            displayCar();
            if (!isAvailable) {
                int rDay, rMonth, rYear;
                cout << "\n\t\t\tEnter return date (DD MM YYYY)"<<endl;
                cout << "\t\t\tEnter the Day   : ";
                cin >> rDay;
                cout << "\t\t\tEnter the Month : ";
                cin >> rMonth;
                cout << "\t\t\tEnter the Year  : ";
                cin >> rYear;

                int daysRented = daysBetween(startDay, startMonth, startYear, rDay, rMonth, rYear);
                float totalAmount = daysRented*rentPerDay;
                cout << "\t\t\tTotal rent for " << daysRented << " days is: Rs. " << totalAmount << endl;

                isAvailable = true;
                startDay = startMonth = startYear = 0;
            } else {
                cout << "\t\t\tThis car is already available.\n";
            }
        }
        fout << carID << " " << brand << " " << model << " " << carNumber << " "
             << rentPerDay << " " << isAvailable << " " << startDay << " " << startMonth << " " << startYear << " "<< name <<" "<< address << " " << phone << " " << NID <<endl;
    }
    fin.close();
    fout.close();
    remove("cars.txt");
    rename("temp.txt", "cars.txt");

    if (!found){
            cout << "\t\t\tCar ID not found.\n";
    }
}


void Car::deleteCar() {
    int id;
    cout << "\t\t\tEnter car ID to delete: ";
    cin >> id;

    ifstream fin("cars.txt");
    ofstream fout("temp.txt");
    bool found = false;

    while (fin >> carID >> brand >> model >> carNumber >> rentPerDay >> isAvailable >> startDay >> startMonth >> startYear >> name >> address >> phone >> NID) {
        if (carID == id) {
            found = true;
            cout << "\t\t\tCar ID " << id << " deleted.\n";
            continue;
        }
        fout << carID << " " << brand << " " << model << " " << carNumber << " " << rentPerDay << " " << isAvailable << " " << startDay << " " << startMonth << " " << startYear << " " << name <<" "<< address << " " << phone << " " << NID << endl;
    }
    fin.close();
    fout.close();
    remove("cars.txt");
    rename("temp.txt", "cars.txt");

    if (!found)
        cout << "\t\t\tCar ID " << id << " not found.\n";
}





void Car::updateCar() {
    int id;
    cout << "\t\t\tEnter car ID to update: ";
    cin >> id;

    ifstream fin("cars.txt");
    ofstream fout("temp.txt");
    bool found = false;

    while (fin >> carID >> brand >> model >> carNumber >> rentPerDay >> isAvailable >> startDay >> startMonth >> startYear >> name >>address >> phone >> NID) {
        if (carID == id) {
            cout << "\t\t\tEnter new brand: ";
            cin >> brand;
            cout << "\t\t\tEnter new model: ";
            cin >> model;
            cout << "\t\t\tEnter new car number: ";
            cin >> carNumber;
            cout << "\t\t\tEnter new rent per day: ";
            cin >> rentPerDay;
            found = true;
        }

        fout << carID << " " << brand << " " << model << " " << carNumber << " " << rentPerDay << " " << isAvailable << " "<< startDay << " " << startMonth << " " << startYear << " " << name <<" "<< address << " " << phone << " " << NID << endl;
    }

    fin.close();
    fout.close();
    remove("cars.txt");
    rename("temp.txt", "cars.txt");

    if (found)
        cout << "\t\t\tCar updated.\n";
    else
        cout << "\t\t\tCar ID not found.\n";
}


void Car::applyDiscount() {
    int id;
    cout << "\t\t\tEnter car ID to apply discount: ";
    cin >> id;
    float discount;
    bool found = false;

    ifstream fin("cars.txt");
    ofstream fout("temp.txt");

    while (fin >> carID >> brand >> model >> carNumber >> rentPerDay >> isAvailable >> startDay >> startMonth >> startYear >> name >> address >> phone >> NID) {
        if (carID == id) {
            cout << "\t\t\tEnter discount percentage: ";
            cin >> discount;
            rentPerDay = rentPerDay - (rentPerDay * discount / 100.0);
            found = true;
        }

        fout << carID << " " << brand << " " << model << " " << carNumber << " "<< rentPerDay << " " << isAvailable << " " << startDay << " " << startMonth << " " << startYear << " "<< name <<" "<< address << " " << phone << " " << NID << endl;
    }

    fin.close();
    fout.close();
    remove("cars.txt");
    rename("temp.txt", "cars.txt");

    if (found)
        cout << "\t\t\tDiscount applied.\n";
    else
        cout << "\t\t\tCar ID not found.\n";
}


//cancel reservation

void Car::cancelReservation() {
    int id;
    cout << "\t\t\tEnter car ID to cancel reservation: ";
    cin >> id;

    ifstream fin("cars.txt");
    ofstream fout("temp.txt");
    bool found = false;

    while (fin >> carID >> brand >> model >> carNumber >> rentPerDay >> isAvailable >> startDay >> startMonth >> startYear >> name >> address >> phone >> NID ) {
        if (carID == id) {
            if (isAvailable) {
                cout << "\t\t\tCar is already available. No reservation to cancel.\n";
            } else {
                isAvailable = 1;
                startDay = startMonth = startYear = 0;
                found = true;
                cout << "\t\t\tReservation cancelled. Car is now available.\n";
            }
        }

        // Always write the updated (or unmodified) car info back
        fout << carID << " " << brand << " " << model << " "<< carNumber << " " << rentPerDay << " " << isAvailable << " " << startDay << " " << startMonth << " " << startYear << " " << name <<" "<< address << " " << phone << " " << NID << endl;
    }

    fin.close();
    fout.close();

    // Replace old file with updated one
    remove("cars.txt");
    rename("temp.txt", "cars.txt");

    if (!found) {
        cout << "\t\t\tCar ID not found.\n";
    }
}



void Car::reserveCar() {
    int id;
    cout <<"\t\t\tEnter Car ID to reserve: ";
    cin >> id;

    ifstream fin("cars.txt");
    ofstream fout("temp.txt");
    bool found = false;

    while (fin >> carID >> brand >> model >> carNumber >> rentPerDay >> isAvailable >> startDay >> startMonth >> startYear >> name >> address >> phone >> NID) {
        if (carID == id) {
            found = true;
            displayCar();
            if (isAvailable) {
                cout << "\n\t\t\tEnter reservation start date (DD MM YYYY)" << endl;
                cout << "\t\t\tEnter the Day   : ";
                cin >> startDay;
                cout << "\t\t\tEnter the Month : ";
                cin >> startMonth;
                cout << "\t\t\tEnter the Year  : ";
                cin >> startYear;

                // Validate the entered date
                if (!isValidDate(startDay, startMonth, startYear)) {
                    cout << "\t\t\tBackdate not allowed. Reservation cancelled.\n";
                    // Keep car info unchanged
                    fout << carID << " " << brand << " " << model << " " << carNumber << " " << rentPerDay << " " << isAvailable << " "
                         << startDay << " " << startMonth << " " << startYear << " " << name << " " << address << " " << phone << " " << NID << endl;
                    continue;
                }

                cout << "\t\t\tEnter Customer Name    : ";
                cin >> name;
                cout << "\t\t\tEnter Address          : ";
                cin >> address;
                cout << "\t\t\tEnter Phone_Number     : ";
                cin >> phone;
                cout << "\t\t\tEnter customer NID_no  : ";
                cin >> NID;
                isAvailable = false;
                cout << "\t\t\tCar reserved from " << startDay << "/" << startMonth << "/" << startYear << endl;
            } else {
                cout << "\t\t\tSorry, this car is already reserved!\n";
            }
        }

        fout << carID << " " << brand << " " << model << " " << carNumber << " "
             << rentPerDay << " " << isAvailable << " " << startDay << " " << startMonth
             << " " << startYear << " " << name << " " << address << " " << phone << " " << NID << endl;
    }

    fin.close();
    fout.close();
    remove("cars.txt");
    rename("temp.txt", "cars.txt");

    if (!found) {
        cout << "\t\t\tCar ID not found.\n";
    }
}



#include"layout.h"


   int Decorate::heading_layout()
        {
            cout<<"\t\t\t _______________________________________________________________________________"<<endl;
            cout<<"\t\t\t|                                                                               |"<<endl;
            cout<<"\t\t\t|                     Car Rental Management System                              |"<<endl;
            cout<<"\t\t\t|_______________________________________________________________________________|"<<endl;
            return 0;
        }
    int Decorate::admin_layout(){
            cout<<"\t\t\t _______________________________________________________________________________"<<endl;
            cout<<"\t\t\t|                                                                               |"<<endl;
            cout<<"\t\t\t|                     Car Rental Management System                              |"<<endl;
            cout<<"\t\t\t|                             Admin Login                                       |"<<endl;
            cout<<"\t\t\t|_______________________________________________________________________________|"<<endl;
            return 0;
    }
    int Decorate::admin_account_layout(){
            cout<<"\t\t\t _______________________________________________________________________________"<<endl;
            cout<<"\t\t\t|                                                                               |"<<endl;
            cout<<"\t\t\t|                     Car Rental Management System                              |"<<endl;
            cout<<"\t\t\t|                             Admin Dashboard                                   |"<<endl;
            cout<<"\t\t\t|_______________________________________________________________________________|"<<endl;
            return 0;
    }
    int Decorate::admin_operation(){
            cout<<"\t\t\t1.Create Employee Account\n";
            cout<<"\t\t\t2.Add\n";
            cout<<"\t\t\t3.Car Information\n";
            cout<<"\t\t\t4.Reserve\n";
            cout<<"\t\t\t5.Cancel Reservation\n";
            cout<<"\t\t\t6.Return Car\n";
            cout<<"\t\t\t7.Update\n";
            cout<<"\t\t\t8.Delete\n";
            cout<<"\t\t\t9.Discount\n";
            cout<<"\t\t\t99.Return Main-Menu\n"<<endl;
            return 0;
    }
    int Decorate::emp_layout(){
            cout<<"\t\t\t _______________________________________________________________________________"<<endl;
            cout<<"\t\t\t|                                                                               |"<<endl;
            cout<<"\t\t\t|                     Car Rental Management System                              |"<<endl;
            cout<<"\t\t\t|                           Employee Login                                      |"<<endl;
            cout<<"\t\t\t|_______________________________________________________________________________|"<<endl;
            return 0;
    }
    int Decorate::emp_account_layout(){
            cout<<"\t\t\t _______________________________________________________________________________"<<endl;
            cout<<"\t\t\t|                                                                               |"<<endl;
            cout<<"\t\t\t|                     Car Rental Management System                              |"<<endl;
            cout<<"\t\t\t|                           Employee Dashboard                                  |"<<endl;
            cout<<"\t\t\t|_______________________________________________________________________________|"<<endl;
            return 0;
    }
    int Decorate::employee_operation(){
            cout<<"\t\t\t1.Car Information\n";
            cout<<"\t\t\t2.Reserve\n";
            cout<<"\t\t\t3.Cancel Reservation\n";
            cout<<"\t\t\t4.Return Car\n";
            cout<<"\t\t\t99.Return Main-Menu\n"<<endl;
            return 0;
    }



    int Decorate::options()
    {
        cout<<"\v"<<endl;
        cout<<"\t\t\t 1.Login as Admin \n";
        cout<<"\t\t\t 2.Login as Employee \n";
        cout<<"\t\t\t 99.Exits \n "<<endl;
        return 0;
    }


   int Decorate::line(){
            cout<<"\t\t\t|_______________________________________________________________________________|"<<endl;
            return 0;
   }

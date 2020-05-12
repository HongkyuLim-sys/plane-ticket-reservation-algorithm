#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

int main(){
    int choice;
    Ticket T;
    string name;
    string flight;
    
    T.addFlight("TO123");
    T.addFlight("YA909");
    T.addFlight("GA344");
    T.addFlight("AU243");
    
LOOP:
    cout<<"---------------------------------"<<endl;
    cout<<"-------------MENU--------------"<<endl;
    cout<<"1. Reserve a ticket"<<endl;
    cout<<"2. Cancel a reservation"<<endl;
    cout<<"3. Check tickets"<<endl;
    cout<<"4. display passengers"<<endl;
    cout<<"Make a selection : ";
    cin>>choice;
    cout<<"---------------------------------"<<endl;
    cout<<"---------------------------------"<<endl;
    
    switch(choice){
        case 1:
            cout<<"Enter your name : ";
            cin>>name;
            T.checkFlight();
            cout<<"Enter flightNum you want : ";
            cin>>flight;
            T.addTicket(name, flight);
            cout<<name<<", your flight ticket has been successfuly reserved."<<endl;
        goto LOOP;
            break;
        
        case 2:
            cout<<"Enter your name : ";
            cin>>name;
            T.checkFlight();
            cout<<"Enter flightNum you want : ";
            cin>>flight;
            T.delTicket(name, flight);
            cout<<name<<", your flight ticket has been successfuly canceled."<<endl;
        goto LOOP;
            break;
        
        case 3:
            cout<<"Enter your name : ";
            cin>>name;
            T.checkFlight();
            cout<<"Enter flightNum you want : ";
            cin>>flight;
            T.checkTicket(name, flight);
            goto LOOP;
            break;
        
        case 4:
        T.displayPassenger();
        goto LOOP;
            break;

        default:
        exit(1);
        ;
        
    }
    
    
    
    return 0;
}

#include <iostream>
#include <string>
#include "Header.h"

using namespace std;

void Ticket::addFlight(string flightNum){
    nodeFlit n = new flightNode;
    n->flightNumber = flightNum;
    n->next = NULL;
    n->p = NULL;
    
    if(FHead != NULL){
        FCurr=FHead;
        while(FCurr->next!=NULL){
            FCurr=FCurr->next;
        }
        FCurr->next = n;
    }
    else{
        FHead = n;
    }
}



void Ticket::delFlight(string flightNum){
    nodeFlit delNode = new flightNode;
    
    if(FHead != NULL){
        if(FHead->flightNumber!=flightNum){
            FCurr=FHead;
            while(FCurr!=NULL&&FCurr->flightNumber!=flightNum){
                FTemp = FCurr;
                FCurr=FCurr->next;
            }
            
            if(FCurr->next == NULL){
                delNode = FCurr;
                FTemp->next=NULL;
                delete delNode;
            }
            else{
                delNode=FCurr;
                FTemp->next = FCurr->next;
                delete delNode;
            }
        }
        
        else{
            delNode = FHead;
            FHead=FHead->next;
            delete delNode;
        }
    }
    else{
        cout<<"No flight has been created."<<endl;
    }
}

void Ticket::displayFlights(){
    if(FHead != NULL){
        FCurr=FHead;
        cout<<"---------------------------------"<<endl;
        while(FCurr!=NULL){
            cout<<FCurr->flightNumber<<endl;
            FCurr=FCurr->next;
        }
         cout<<"---------------------------------"<<endl;
    }
    else{
        cout<<"There's no flight created."<<endl;
    }
}

void Ticket::checkFlight(){
    if(FHead!=NULL){
        FCurr=FHead;
        cout<<"Following flights below exist."<<endl;
        cout<<"-----------------------------"<<endl;
        while(FCurr!=NULL){
            cout<<FCurr->flightNumber<<endl;
            FCurr=FCurr->next;
        }
        cout<<"-----------------------------"<<endl;
    }
    else{
        cout<<"No flight exists. Please add a flight."<<endl;
    }
}

void Ticket::addTicket(string name, string flightNum){
    nodePas n = new passengerNode;
    n->Name = name;
    n->flightNumber = flightNum;
    n->next=NULL;
    
    if(PHead!=NULL){
        PCurr=PHead;
        while(PCurr!=NULL){
            if(PCurr->Name.at(0)>n->Name.at(0)){
                break;
            }
            PTemp=PCurr;
            PCurr=PCurr->next;
        }
        
        if(PCurr==PHead){
            n->next=PCurr;
            PHead=n;
            
            FCurr=FHead;
            while(FCurr->next!=NULL){
                if(FCurr->flightNumber==n->flightNumber){
                    break;
                }
                FCurr=FCurr->next;
            }
            FCurr->p=PHead;

        }
        else{
            PTemp->next=n;
            n->next=PCurr;
        }
    }
    else{
        PHead=n;
        
        FCurr=FHead;
        while(FCurr->next!=NULL){
            if(FCurr->flightNumber==n->flightNumber){
                break;
            }
            FCurr=FCurr->next;
        }
        FCurr->p=PHead;
    }
}

void Ticket::delTicket(string name, string flightNum){
    nodePas delPtr = new passengerNode;
    
    if(PHead!=NULL){
        PCurr=PHead;
        while(PCurr->next!=NULL){
            if(PCurr->Name==name&&PCurr->flightNumber==flightNum){
                break;
            }
            PTemp = PCurr;
            PCurr=PCurr->next;
        }
        
        if(PCurr==PHead){
            delPtr=PCurr;
            PHead = PCurr->next;
            
            FCurr=FHead;
            while(FCurr->next!=NULL){
                if(FCurr->flightNumber==flightNum){
                    break;
                }
                FCurr=FCurr->next;
            }
            FCurr->p=PHead;
            delete delPtr;
        }
        
        else{
            delPtr=PCurr;
            PTemp->next=PCurr->next;
            delete delPtr;
        }
        
    }
    else{
        cout<<"There's no passenger in '"<<flightNum<<"'."<<endl;
    }
}

void Ticket::checkTicket(string name, string flightNum){
    PCurr=PHead;
    FCurr=FHead;
    
    while(FCurr!=NULL){
        if(FCurr->flightNumber==flightNum){
            while(PCurr!=NULL){
            
                if(PCurr->Name==name){
                    cout<<"-----------------------------------------------------------------"<<endl;
                    cout<<PCurr->Name<<" reserved a seat in plane '"<<flightNum<<"'."<<endl;
                    cout<<"-----------------------------------------------------------------"<<endl;
                    break;
                }

                PCurr=PCurr->next;
            }
            break;
        }
        FCurr=FCurr->next;
    }
}





void Ticket::displayPassenger(){
    PCurr=PHead;
    FCurr=FHead;
    cout<<"----------------------------"<<endl;
    cout<<"Passenger list"<<endl;
    cout<<"----------------------------"<<endl;
    while(FCurr!=NULL){
        while(PCurr!=NULL){
            cout<<"Name : "<<PCurr->Name<<endl;
            cout<<"Flight No  : "<<PCurr->flightNumber<<endl;
            cout<<"----------------------------"<<endl;
            PCurr=PCurr->next;
        }
        FCurr=FCurr->next;
    }
    cout<<"----------------------------"<<endl; 
}






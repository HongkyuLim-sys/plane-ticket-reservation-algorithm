
#ifndef Header_h
#define Header_h

using namespace std;

typedef class passengerNode{
    public:
    string Name;
    string flightNumber;
    passengerNode*next;
}* nodePas;

typedef class flightNode{
    public:
    string flightNumber;
    flightNode* next;
    passengerNode* p;
}* nodeFlit;

class Ticket{
public:
    
    nodeFlit FHead;
    nodeFlit FTemp;
    nodeFlit FCurr;
    
    nodePas PHead;
    nodePas PTemp;
    nodePas PCurr;
    
    void addFlight(string flightNum);
    void delFlight(string flightNum);
    void addTicket(string name, string flightNum);
    void delTicket(string name, string flightNum);
    void checkTicket(string name, string flightNum);
    void displayFlights();
    void displayPassenger();
    void checkFlight();
};




#endif /* Header_h */

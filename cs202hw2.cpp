//Captain-Price-TF-141

/*
* Description: Elevator, Classes.
* Input: 1 10 11 4 2 3 and tested 1 10 11 6 2 3.
* Output: Move elevators, check status, and decide which elevator is closest to the requested floor.
*/

#include <iostream>
#include <cstdlib> //For Absolute value use abs() ie: abs(-5) will return 5
using namespace std;


class myElevator {
private:
	static int count; //keeps track of how many elevators there are
	int id; //elevator id gets increased every time an elevator is added
	int currentFloor; //location of elevator
	int maxFloor; //Maximum Floor of Elevator
	bool inUse; //Whether elevator is in service
public:
	myElevator(int = 1, int = 50); //constructor
	int getElevatorID() const;
	int getElevatorCurrentFloor() const;
	int getCount() const;
	bool canReach(int) const;
	void ToggleElevator(); //Toggle elevator on or off
	void printElevator() const; //Print information on elevator
	void moveElevator(int); //Moves elevator to the requested floor
};
//Class Implementation



int myElevator::count = 0;

/*
* function_identifier: Elevator Stats
* parameters: int floor, int max
* return value: Elevator id for each elevator, current floor, and in use value.
*/
myElevator::myElevator(int floor, int max) {
	this->id = count++;
	this->currentFloor = floor;
	this->inUse = false;
	this->maxFloor = max;
}

/*
* function_identifier: Elevator id
* parameters: constant
* return value: Returns elevator id when called.
*/
int myElevator::getElevatorID() const {
	return id;
}

/*
* function_identifier:Elevator current floor
* parameters: constant
* return value: Returns elevator current floor when called.
*/
int myElevator::getElevatorCurrentFloor() const {
	return currentFloor;
}

/*
* function_identifier: Elevator id store and counter.
* parameters: constant
* return value: Stores and returns the id count for each elevator.
*/
int myElevator::getCount() const {
	return myElevator::count;
}

/*
* function_identifier: Elevator Reach
* parameters: int floor
* return value: Returns the max floor the elevator can reach
*/
bool myElevator::canReach(int floor) const {
	if (maxFloor >= floor) return true;
	else return false;
}


/*
* function_identifier: Toogles Elevator
* parameters: inUse
* return value: Returns the elevator to "not in service if it is not being used.
*/
void myElevator::ToggleElevator() {
	cout << "Toggled Elevator" << endl;
	if (!inUse)
	{
		inUse = true;
		
	}
	else {
		inUse = false;
	}

	
}
//Toogles the elevator to the requested floor if available( Elevator 0 , 1 , 2);

/*
* function_identifier: Print Elevator
* parameters: constant
* return value: Displays the elevator status
*/
void myElevator::printElevator() const {
	cout << "Elevator: " << id << " is";
	if (!inUse) cout << " not";

	//else  (inUse); cout << " out";

	cout << " in service." << endl;
	cout << "Floor Location: " << currentFloor << endl;
	cout << "Max Floor for Elevator: " << maxFloor << endl;
}
//Displays current elevator status

/*
* function_identifier: Move Elevator
* parameters: int floor
* return value: Returns moved elevator and checks which one can reach the floor
*/
void myElevator::moveElevator(int floor) {

	if (canReach(floor))
	{
		if (inUse)
		{
			cout << "Elevator Request Received for Elevator " << id << "." << endl;
			cout << "Moving from Floor " << currentFloor << " to floor " << floor << "." << endl;
			cout << "Arrived at Floor " << floor << "." << endl;
			currentFloor = floor;
		}
		else
		{
			cout << "Elevator " << id << " is out of serivce." << endl;
		}
		
		
	}
	
	else
	{
		cout << "Error: Elevator Cannot Reach Floor " << floor << "!" << endl;
	}

	
	
	
}
// Moves elevator and checks which one can reach the floor( Elevator 0 , 1 , 2)


//Non-Member Functions

/*
* function_identifier: Closest Elevator
* parameters: myElevator A, myElevator B, int floor
* return value: Returns the ID of the closest elevator.
*/
int closestElevatorID(myElevator A, myElevator B, int floor) {
	int x;
	int a;
	int b;

	a = abs(A.getElevatorCurrentFloor() - floor);
	b = abs(B.getElevatorCurrentFloor() - floor);

	if (a < b)
	{
		return A.getElevatorID();
	}
		else if (b < a)
	{
		return B.getElevatorID();

	}
			else if(a == b)
	{
			return A.getElevatorID() || B.getElevatorID();
	}
	
	
	//return x;
} 
//Returns closest elevators. If equal it just picks the first one


/*
* function_identifier: Elevator Distance
* parameters: myElevator A, myElevator B
* return value: Returns the distance between the elevator.
*/
int elevatorDistance(myElevator A, myElevator B) {
	int d;
	 
	d = abs(A.getElevatorCurrentFloor() - B.getElevatorCurrentFloor()); //find the diistance between the elevators
	
	

	
	return d;
} 
//Returns floor distance between both elevators



// Client Code to test the functionality of the class myElevator
int main() {
	// Input: 1, 10, 11, 4, 2, 3



	int a, b, c, d, e, f;
	cin >> a; cin >> b; cin >> c; cin >> d; cin >> e; cin >> f;



	myElevator A; // declare 1 object of type Elevator
	myElevator B;
	myElevator C(a, b); //a=1,b=10
	C.printElevator();
	C.ToggleElevator();
	C.moveElevator(c);//c=11
	A.ToggleElevator();
	A.moveElevator(d);//d=4
	B.moveElevator(e);//e=2
	B.ToggleElevator();
	A.printElevator();
	B.printElevator();



	cout << "Closest Elevator to Floor " << f << " is Elevator ID: "
		<< closestElevatorID(A, B, f) << endl; //f=3
	cout << "Elevator Distance between Elevator " << A.getElevatorID()
		<< " and " << B.getElevatorID() << " is "
		<< elevatorDistance(A, B) << " Floors." << endl;
	cout << "Total Elevators in Existence: " << A.getCount() << endl;



	return 0;
}
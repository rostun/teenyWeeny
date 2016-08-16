/*
	A car rental company wants to keep track of its cars. 
	
	Each vehicle has a license plate and a brand. (eg. BWM). 
	
	Currently the company has SUVs and Sedans. 
		SUV-s have an optional third row seat that increases the passenger capacity by three
		sedans have an optional sport package. 
		
	Each car can be queried to inquire the number of passengers it can carry.
*/

#include <iostream>
#include <vector>
#include <map>
#include <string>

using namespace std;

class Car{
	protected:
		string license;
		int capacity;
		bool extra; //extra seats or no
	public:
		Car(string license="", int capacity=0, bool extra=false){
			this->license = license;
			this->capacity = capacity;
			this->extra = extra;
		}
		virtual string getType()=0;
		string getLicense(){
			return license;
		}

		virtual int numPassengers(){
			//cout << "car class" << endl;
			return capacity;
		}

};

class Sedan: public Car{
	public:
		Sedan(string license="123Ab", int capacity=0, bool extra=false):Car(license, capacity, extra){}
		string getType(){
			return "Sedan";
		}
		string getLicense(){
			return license;
		}
		int numPassengers(){
			if (extra == false){
				return capacity;
			} else {
				return (capacity+3);
			} 
		}
};

//assuming sports package means you can add another seat...
class SUV: public Car{
	public:
		SUV(string license="123Ab", int capacity=0, bool extra = false):Car(license, capacity, extra){}
		string getType(){
			return "SUV";
		}
		string getLicense(){
			return license;
		}
		int numPassengers(){
			if(extra == false){
				return capacity;
			} else {
				return (capacity+1);
			}
		}
};

class CarRental{
	private:
		vector <Car*> lot;
	public:
		CarRental(vector <Car*> lot){
			this->lot = lot;
		}
		void addCar(Car* vehicle){
			lot.push_back(vehicle);
		}
		void seeCars(){
			for(int i = 0; i < lot.size(); i++){
				cout << lot[i]->getType() << endl;
				cout << lot[i]->getLicense() << endl;
				cout << lot[i]->numPassengers() << endl;
			}
		}
};


/*destructor is the function that is called when an object is deleted*/
int main()
{
	Car *car;
	
	vector <Car*> vehicles;
	CarRental shop(vehicles);

	Sedan sed("1234", 5, true); //originally starts off with 5 seats
	SUV suv("4321", 2, false); //originall starts off with 2 seats

	car = &suv;
	shop.addCar(car);

	car = &sed;
	shop.addCar(car);

	shop.seeCars();

	cin.get();
	return 0;
}
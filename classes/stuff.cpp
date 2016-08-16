/*
	Inheritance permits code reusability, which saves time in program development.
	You can reuse proven and debugged high quality software, reduing problems after 
	a system becomes functional 
*/

/*
	Inline functions can save you time at the cost of space. So putting the 'inline' 
	keyword in front of the function will cause the compiler to replace the function 
	call with the actual code from the function.
*/

/*
	private members can't be accessed outside of the class (exception with friend classes)
	protected member are available to derived classes 
*/

/*
	Function declaration is what goes before main, definition goes after main (if you've 
	declared it properly before main! or you could just defin it before main too)
*/

/*
	c and c++ haven't much difference in memory management. they have following differences 
	1) c++ is Procedural, OOP, Generic Programming while C is only Procedural 
	2) In C++ references along with pointers are available but no references in C 
	3) In c++ Character arrays and Character objects are supported but no Character Objects in C 
	4) C++ Complex data types Include Structures, unions, classes but no classes in C 
	5) Multiple Class inheritance in C++ but no Inheritance in C
*/

/*
	https://www.tutorialcup.com/cplusplus-interview-questions
*/

/*
	static: static variables in classes will only ever allow one copy of the variable to be 
	created, (static in age will stay the same value no matter how many people objects)
*/

/*
	const: variables declared with const cannot be altered by the program no matter what 
*/

/*
	Conceptually, an interface is a pure virtual class, with no implementation whatsoever. 
	You can't create instances of that class, but you can have implementation in it, that 
	is shared with the derived classes.
	
	An abstract class is a class that has at least a pure virtual method. 
*/

/*
	function overloading is when you use the same function name but with different parameters
*/

/*
	operator overloading allows you to add two objects (box + box)
*/

/*
	What is the main difference between "dynamic_cast<T>" and "(T)" cast syntax?
	-dynamic cast checks type casting in runtime, T does not
*/

/*difference between vector and dequeue*/

/*what does placement operator new mean?*/

/*	what is the order of static variable initialization across one program */

/*
	Suppose that a class allocates memory dynamically in its constructor.  
	Which of the following techniques best prevents memory leaks in case an exception is thrown?

	--use smart pointer?
*/

/*what's value of all the variables? (3, 3, 5)*/

int x, y;
int a=(y=(x=5)*2+7)/4
what's the alue of a? (4)

int i = 2;
int j = 2;
int s=(i++)+(++j);

/*what prints to the screen?*/

int a = 5;
int b = 0;
int &r = a;

r = b++;

cout << a << r << b;
	
/*what prints to the screen?*/

unsigned int a = 20;
unsigned int b = 14;
int c = a ^ b;

cout << c << endl;
	
/*
	we want to print an instance of a user defined class to stdout
	which of the following is the correct operator declration for this purpose
*/	
	
class A {
public:

ostream& operator << (ostream&, const A&);

ostream& operator<<(ostream&);

friend ostream& operator << (ostream&, const A&);

/*
	We want to define a prefix operator ++ for a user-defined class:
	Which operator declaration is the best?
*/

class A {

public:

	A operator++();     //a

	A& operator++();    //b

	A operator++(int);  //c

	A& operator++(int); //d

};

int main(){
	A a;
	++a;
}

/*what will be printed*/

class A {

public:

	virtual ~A() { f(); }

	virtual void f() { cout << "A::f" << endl; }

};

class B: public A {

	public:

		~B() { }

		virtual void f() { cout << "B::f" << endl; }

};

int main(){	
	A* a = new B;
	delete a;		
}
	
/*what will happen?*/

struct A 
{ 
    ~A() 
    { 
        std::cout << "~A"; 
    }
}; 
 
struct B: public A 
{ 
    virtual ~B() 
    { 
        std::cout << "~B"; 
    }
};

int main(){
	A* a = new B;
	delete a;
}

/*what prints?*/

struct Base { 
    virtual void print( int x = 1 ) {
        std::cout << "Base:" << x; 
    }

}; 
 
struct Derived : Base { 
    virtual void print( int x = 2) { 
        std::cout << "Derived:" << x; 
    }
};

	Base * B = new Derived; 
	B->print();

/*deletion code choice*/

std::map<K, V>::iterator itr = myMap.begin();

while (itr != myMap.end()) {
	if (needDelete(*itr)) {
		// deletion code choice
		//myMap.erase(itr++);
	} else {
		++itr;
	}

}

/*what results in compilation error*/

struct A { void f(); };
struct B { int f(); };
struct C : A, B { };

int main() {
   C* pc; 

   pc->A();     // statement 1
   pc->A::f();    // statement 2
   pc->B::f();    // statement 3
   pc->A::B::f();    // statement 4

   return 0;
}

/*what does it print*/

class Animal
{
private:
   std::string m_strName;

protected:
   Animal(const std::string& strName):  m_strName(strName)
   {
   }
public:
   const std::string& GetName() { return m_strName; }
   const char* Speak() { return "???"; }
};

class Cat: public Animal
{
public:
   Cat(const std::string& strName): Animal(strName)
   {
   }
   const char* Speak() { return "Meow"; }
};

class Dog: public Animal
{
public:
   Dog(const std::string& strName) : Animal(strName)
   {
   }
   const char* Speak() { return "Woof"; }
};

int main()
{
   Cat cCat("Fred");
   Animal *pAnimal = &cCat;
   cout << "Animal is named " << pAnimal->GetName() << ", and it says " << pAnimal->Speak() <<
	  endl;
   cin.get();
   return 0;
}

/*
	Last month a certain music club offered a discount to preferred customers. 
	After the first compact disc purchased, preferred customers paid $3.99 for 
	each additional compact disc purchased. If a preferred customer purchased a 
	total of 6 compact discs and paid $15.95 for the first compact disc, which 
	of the following expressions evaluates to the correct dollar amount that the 
	customer paid for the 6 compact discs?
*/

/*what prints*/

double a = 52.0562;
float b = 14.25;
int c ;
c = (int) a;
a = (double) b;
cout << c << " " << a << endl ;

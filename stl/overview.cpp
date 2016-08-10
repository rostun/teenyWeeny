/* * * * * * *
	Vector
 * * * * * * */

#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {

	//vector contructors
	vector<int> testVector; // empty vector capable of storing the integer datatype
	vector<long> testVector(10); //vector with storage space for 10 long integers
	vector<float> testVector(5,1.0); //vector with storate for 5 floats, each initialized to 1.0
	
	//2D vector (vector of vectors)
	vector<int> vectorOne(10,5); 
	vector<int> vectorTwo(vectorOne);
	
	/*  run through the vector and display each element, if possible */
	for (long index=0; index<vectorOne.size(); ++index) {
		try {
			cout << "Element " << index << ": " << vectorOne.at(index) << endl;
		}
		catch (exception& e) {
			cout << "Element " << index << ": index exceeds vector dimensions." << endl;
		}
	}
	
	/*  Change size of vector - element removal */
    vectorOne.resize(7);
	/* change capacity of vector - depending on what declaration you made */
	vectorOne.reserve(40);
	cout << "Capacity of vectorOne is: " << vectorOne.capacity() << " elements." << endl;
	
	/*  unsafe access version */
	for (int index=0; index<vectorOne.size(); ++index) {
		cout << vectorOne[index] << endl;
	}
	return EXIT_SUCCESS;
}

/* * * * * * *
	List
 * * * * * * */
 
#include <iostream>
#include <list>
using namespace std;

template <typename Container>
void print(const Container& cntn) {
	typename Container::const_iterator i = cntn.begin(); //when initializing an object of a member type of the template, you have to use typename like this
	for(; i != cntn.end(); ++i) { //iterate through the container
		cout<<*i<<endl; //print each element
	}
}

bool compare(const int& left, const int& right) {
    return left>right;
}

bool condition(const int& a) {
    return a>100; //returns true if a is bigger than 13
}

int main() {
    list<int> list1; //an empty list of integers
    list<int> list2(3, 7); //a list containing 3 integers with value of 7
    list<int> list3(list2); //a list which has all members list2 has
    list<int> list4(list3.begin(), list3.end()); //a list containing elements of list3 from its beginning to its end
	
	print(list4); //prints 7 three times
	
	list1.assign(2, 13);
	print(list1); //prints 13 two times

	list<int> list5 = list2; //list5 will contain three 7s like list2
	
	list1.push_back(5);
	list1.push_back(2);
	list1.push_front(40);
	print(list1); //prints 40 13 13 5 2

	list1.pop_back();
	print(list1); //prints 40 13 13 5
    list1.pop_front();
    print(list1); //prints 13 13 5
	
	list<int>::iterator it = list1.begin(); // it points to number 13
	it++; //it points to number 13 still 
	list1.insert(it, 1); //insert in place where number 13 is 
	print(list1); //13 1 13 5 
	
	list1.insert(it, 2); //still insert in same place
	print(list1); //13 1 2 13 5
	
	it--; //now points to 2
	list<int>::iterator it2 = it;
    advance(it2, 2); //it2 points to 5 now 
	list1.erase(it, it2); //erase 2 and 13, doesn't erase it2?
	print(list1); //prints 13 1 5
	
	list1.sort();
	print(list1); //prints 1 5 13
	
	list1.sort(compare); 
	print(list1); //prints 13 5 1
	
	list1.remove(1); //remove all elements which have a value of 1
	print(list1); //prints 13 5
	
	list1.remove_if(condition);
	print(list1); //nothign happens
	
	cout<<list1.size()<<endl; //prints 2
	cout<<list1.max_size()<<endl; //list cannot contain more than this number

	return 0;
}
 
/* * * * * * *
	Stack
 * * * * * * */

#include <iostream>
#include <stack>

using namespace std;

int main ()
{
    stack <string> cards; /* Simple enough to create a stack */
    cards.push("King of Hearts"); /* push() will add a value, think of queues */
    cards.push("King of Clubs");  /* adding some cards to the deck */
    cards.push("King of Diamonds");
    cards.push("King of Spades");
    cout << "There are " << cards.size () << " cards in the deck" << endl;
    cout << "The card on the top of the deck is " << cards.top() << endl;
    /* Will output King of Spades, since this was the last one to be added */
    cards.pop();
    cout << "The top card is now " << cards.top() << endl;
    cout << cards.size();

    cin.get ();
    return EXIT_SUCCESS;
}

/* * * * * * *
	Queue
 * * * * * * */

#include <iostream>
#include <queue>

using namespace std;

int main ()
{
    queue <string> names; /* Declare a queue */
    names.push ("Danny"); /* Add some values to the queue */
    names.push ("Kayleigh"); /* Much like vectors */
    names.push ("Joe"); /* This basically does the same thing */

    cout << "There are currently " << names.size () << " people in the queue" << endl
         << "The person at the front of the queue is " << names.front () << endl
         << "The person at the back of the queue is " << names.back () << endl << endl;

    cout << names.front () << " has been served!" << endl;
    names.pop ();
    cout << "There are currently " << names.size () << " people in the queue" << endl
         << "The person at the front of the queue is " << names.front () << endl
         << names.back () << " is still at the back!" << endl;
    cin.get ();
    return EXIT_SUCCESS;
}

/* * * * * * 
	Maps
 * * * * * */

#include <iostream>
#include <iomanip>
#include <map>

using namespace std;

void display (map <string,char> grades)
{
    cout << "\tTotal size: " << grades.size() << endl; /* Output the size */
    /* Create an iterator, much like vector iterators */
    map <string, char>::iterator it;
    for (it = grades.begin(); it != grades.end(); ++it)
        /* Output first (which is the string) and second (which is the char) */
        cout << setw(10) << it->first << setw(5) << it->second << endl;

    cout << endl; /* Print a new line */
}

int main ()
{
    cout << "Populating map..." << endl;
    map <string, char> grades; /* Create a map with string as a referencer and char as the storage */
    grades["Danny"] = 'A'; /* This is how we add values to a map */
    grades["Kayleigh"] = 'A'; /* Basically, it is like an array, but cooler */
    grades["Joe"] = 'F'; /* We get to use any data type we like as the access key */
    grades["Brad"] = 'C'; /* As opposed to using 'int' all the time wih an array */

    cout << "Before any modifications:" << endl;
    display (grades); /* Call my function to display the map */

    /* erase() will delete the member of the map that is being passed */
    /* find() will find the data being stored under the key, and return the iterator position */
    grades.erase (grades.find("Joe"));
    cout << "After deleting a value:" << endl;
    display (grades); /* Call my function to display the map */

    /* Perform a couple of checks to see what is in the map */
    if (grades.count("Danny")) /* if "Danny" is in the map */
         cout << "Danny is a member of grades" << endl;
    else cout << "Danny is not a member of grades" << endl;
    if (grades.count("Joe")) /* remember we deleted him! */
         cout << "Joe is a member of grades" << endl;
    else cout << "Joe is not a member of grades" << endl;

    cout << endl; /* Add a bit of white space */

    /* clear() does exactly what it says on the tin. It completely clears all data from the map */
    grades.clear ();
    cout << "After clearing the map:" << endl;
    display (grades);

    cin.get ();
    return EXIT_SUCCESS;
}

//unordered_map insert and access is O(N) *uses linked lists as buckets*, look up O(1) vs maps O(N) generally better
//BUT maps and sets use less memory 
//map and set is implemented internally as balance search tree while unordered_map + unordered_set by hashing
//a set is a collection of things (pairs) while a map is a mapping of keys to pairs

//Map Template
map <key_type, data_type>

//Declaration
map <string, int> m; //Creates a map m where key_type is of type string and data_type is of type int.

//Size
int length = m.size(); //Gives the size of the map.

//Insert log(n)
m.insert(make_pair("hello",9)); //Here the pair is inserted into the map where the key is "hello" and the value associated with it is 9.

//Erasing an element
m.erase(val); //Erases the pair from the map where the key_type is val.

//Finding an element log(n)
map<string,int>::iterator itr = m.find(val); //Gives the iterator to the element val if it is found otherwise returns m.end().

#include <iostream>
#include <map>
using namespace std;

int main() {
    int numQueries;
    string name;
    
    int queryType, addValue;
    map <string, int> m; 
    map <string, int>::iterator it;
    
    cin >> numQueries;
    
    for(int i = 0; i < numQueries; i++){
        cin >> queryType;
        cin >> name;
        
        it = m.find(name); //should either find it or be m.end()
        
        if(queryType == 1){
            cin >> addValue;
            if(it == m.end()){
                m.insert(make_pair(name, addValue));
            }
            it->second = it->second + addValue;
            
        }
        else if(queryType == 2){
            if(it != m.end()){
                m.erase(name);
            }
        }
        else { //type 3
            if(it == m.end()){
                cout << "0" << endl;
            } else {
                cout << it->second << endl;
            }
        }
    }
    
    return 0;
}

/* * * * * * * * * *
	unordered_maps
 * * * * * * * * * */
 
// unordered_map::begin/end example
#include <iostream>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,std::string> mymap;
  mymap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};

  std::cout << "mymap contains:";
  for ( auto it = mymap.begin(); it != mymap.end(); ++it )
    std::cout << " " << it->first << ":" << it->second;
  std::cout << std::endl;

  std::cout << "mymap's buckets contain:\n";
  for ( unsigned i = 0; i < mymap.bucket_count(); ++i) {
    std::cout << "bucket #" << i << " contains:";
    for ( auto local_it = mymap.begin(i); local_it!= mymap.end(i); ++local_it )
      std::cout << " " << local_it->first << ":" << local_it->second;
    std::cout << std::endl;
  }

  return 0;
}

// unordered_map::insert
#include <iostream>
#include <string>
#include <unordered_map>

int main ()
{
  std::unordered_map<std::string,double>
              myrecipe,
              mypantry = {{"milk",2.0},{"flour",1.5}};

  std::pair<std::string,double> myshopping ("baking powder",0.3);

  myrecipe.insert (myshopping);                        // copy insertion
  myrecipe.insert (std::make_pair<std::string,double>("eggs",6.0)); // move insertion
  myrecipe.insert (mypantry.begin(), mypantry.end());  // range insertion
  myrecipe.insert ( {{"sugar",0.8},{"salt",0.1}} );    // initializer list insertion

  std::cout << "myrecipe contains:" << std::endl;
  for (auto& x: myrecipe)
    std::cout << x.first << ": " << x.second << std::endl;

  std::cout << std::endl;
  return 0;
}
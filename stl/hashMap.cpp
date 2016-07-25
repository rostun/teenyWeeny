//Maps Overview, unordered_map insert and access is O(N) *uses linked lists as buckets*
//http://stackoverflow.com/questions/13799593/how-to-choose-between-map-and-unordered-map
//map is implemented internally as balance search tree while unordered_map by hashing

//need hash table use multimap instead of map, will allow you to do ordered or unordered multiple keys

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

//Accessing the value stored in the key
//To get the value stored of the key "MAPS" we can do m["MAPS"] or we can get the iterator using the find function and then by itr->second we can access the value.

/*
	1 X Y: add marks Y to student whose name is X
	2 X: Erase the marks of the students whose name is X
	3 X: Print the marks of the students whose name is X (if X didn't get any marks print 0)
	Sample Input
		7
		1 Jesse 20
		1 Jess 12
		1 Jess 18
		3 Jess
		3 Jesse
		2 Jess
		3 Jess
	
	Sample Output
		30
		20
		0	
*/

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <set>
#include <map>
#include <algorithm>
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


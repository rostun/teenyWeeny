/*
	stl containers c++
	http://en.cppreference.com/w/cpp/container
*/

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 Sequence Containers: 
	implement data structures, can be accessed sequentially.
		array* 			=> static contiguous array
		vector 			=> dynamic contiguous array 
		dequeue 		=> double-ended queue 
		forward_list* 	=> singly-linked list
		list 			=> doubly-linked list
 Associative containers: 
	implement sorted data structures that can be quickly searched (O(log n) complexity).
		set 		=> collection of unique keys, sorted by keys 
		map 		=> collection of key-value pairs, sorted by keys, keys are unique 
		multiset 	=> collection of keys, sorted by keys 
		multimap 	=> collection of key-value pairs, sorted by keys 
 Unordered associative containers: 
	implement unsorted (hashed) data structures that can be quickly searched (O(1) 
	amortized, O(n) worst-case complexity).
		unordered_set* 		=> collection of unique keys, hashed by keys 
		unordered_map*		=> collection of key-value pairs, hashed by keys, keys are unique 
		unordered_multiset*	=> collection of keys, hashed by keys 
		unordered_multimap*	=> collection of key-value pairs, hashed by keys 
 Container Adapters: 
	Container adaptors provide a different interface for sequential containers.
		stack 			=> adapts a container to provide stack (LIFO data structure) 
		queue			=> adapts a container to provide queue (FIFO data structure) 
		priority_queue 	=> adapts a container to provide priority queue 
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

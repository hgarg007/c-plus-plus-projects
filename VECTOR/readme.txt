### Vector class implementaion

Classes -
	vector : used this class as a dynamic array of objects.
			 contains functions to manipulate data and contructors to initialize with different forms.
	contructors :
		vector<T>() - default
        ~vector<T>() - default
        vector<T>(int ) - initialize with given capacity
		vector<T>(vector &) - initialize with given vector
		
	member functions :
        T at(int ) - returns element at specified position(throw exception)
		T back() - returns last element (throw exception)
		T front() - returns first element (throw exception)
		int max_size() - returns current capacity of vector
		bool empty() - checks its empty or not.
		void clear() - delete sll space inside vector.
		void erase(int ) - erase any element (throw exception)
		void insert(int , T ) - insert at custom index (throw exception)
		void push_back(T ) - push new element to vector
		T pop_back() - return last element with removal
		int size() - returns current size
		void resize(int ) - to resize the current capacity
		T& operator[] (int ) - overloaded subscript operator []
		
	data members :
		T *value - contains actual data
        int capacity - maintain current capacity
        int top - maintain last element's index
        static const int max_capacity=1000000 - fixed max capacity of container
main - 
	main function is used to perform test cases.
	
	Exceptions:
		1. size underflow
		2. size overflow
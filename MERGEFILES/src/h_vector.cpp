/** Description:    A class which can be used as dynamic array.
 *  Author:         Himanshu Garg
 *  Please go through readme file for better understanding.
 */

#include <iostream>

template<class T>
class h_vector
{
    public:
        h_vector<T>();
        ~h_vector<T>();
        h_vector<T>(int );
        h_vector<T>(h_vector &);
        T at(int );
		T back();
		T front();
		int max_size();
		bool empty();
		void clear();
		void erase(int );
		void insert(int , T );
		void push_back(T );
		T pop_back();
		int size();
		void resize(int );
		T& operator[] (int );
    protected:

    private:
        T *value;
        int capacity;
        int top;
        static const int max_capacity=1000000;

};

template<class T>
h_vector<T>::h_vector() {
    capacity=0;
    top=-1;
}

template<class T>
h_vector<T>::h_vector(int cap) {
    if(cap> max_capacity)
        throw "Memory Overflow";
    capacity=cap;
    top=-1;
    value=new T[capacity];
}

template<class T>
h_vector<T>::h_vector(h_vector &data) {
    if(data.size()> max_capacity)
        throw "Memory Overflow";
    capacity=data.size();
    top=-1;
    value=new T[capacity];
    for(int i=0; i<data.size(); i++) {
        value[++top]=data.at(i);
    }
}

template<class T>
h_vector<T>::~h_vector() {
    delete []value;
}

template<class T>
T h_vector<T>::at(int pos) {
    if(pos>=size())
        throw "No Element Found.";
	return this->value[pos];
}

template<class T>
T h_vector<T>::back() {
    if(size()==0)
        throw "No Element Found.";
	return value[top];
}

template<class T>
T h_vector<T>::front() {
    if(size()==0)
        throw "No Element Found.";
	return value[0];
}

template<class T>
int h_vector<T>::size() {
	return top+1;
}

template<class T>
int h_vector<T>::max_size() {
	return capacity;
}

template<class T>
bool h_vector<T>::empty() {
	return (top==-1)?true:false;
}

template<class T>
void h_vector<T>::clear() {
	delete []value;
	capacity=0;
	top=-1;
}

template<class T>
void h_vector<T>::push_back(T val) {
	if(capacity>(top+1)) {
		value[++top]=val;
	} else {
		capacity=(capacity==0)?1:2*capacity;
		resize(capacity);
		value[++top]=val;
	}
}

template<class T>
T h_vector<T>::pop_back() {
    if(size()==0)
        throw "No Element Found.";
    top--;
    if(top+1<(capacity/2))
        resize(capacity/2);
	return value[top];

}

template<class T>
void h_vector<T>::resize(int new_size) {
    if(new_size> max_capacity)
        throw "Memory Overflow";
	T *temp=new T[new_size];
	for(int i=0; i<this->size(); i++) {
		temp[i]=value[i];
	}
	this->capacity=new_size;
	if(top!=-1)
		delete []value;
	value=temp;
}

template<class T>
void h_vector<T>::erase(int index) {
    if(index>=top+1)
        throw "No Element Found.";
	for(int i=index+1; i<size(); i++) {
		value[i-1]=value[i];
	}
	top--;
	if(top+1<(capacity/2))
        resize(capacity/2);
}

template<class T>
void h_vector<T>::insert(int index,  T element) {
	if(capacity==size())
		resize((capacity==0)?1:2*capacity);
	for(int i=size()-1; i>=index; i--) {
		value[i+1]=value[i];
	}
	value[index]=element;
	top++;
}

template<class T>
T& h_vector<T>::operator[](int pos) {
	if(pos>=size())
        throw "No Element Found.";
	return value[pos];
}

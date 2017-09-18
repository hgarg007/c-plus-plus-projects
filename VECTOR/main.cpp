#include <iostream>
#include "src/vector.cpp"
using namespace std;

int main()
{
    // TESTING STARTS.

    cout<<"------1------"<<endl;

    // Test Case - 1. Use Default Constructor.
    vector<int > data;
    for(int i=0; i<5; i++)
        data.push_back(i);
    for(int i=0; i<5; i++)
        cout<<data[i]<<" ";
    cout<<endl;
    cout<<"Size: "<<data.size()<<endl;
    cout<<"Capacity: "<<data.max_size()<<endl;

    cout<<endl<<"------2------"<<endl;

    // Test Case - 2. Use Parametrized Constructor.
    vector<int > data2(data);
    for(int i=0; i<5; i++)
        cout<<data[i]<<" ";
    cout<<endl;
    cout<<"Size: "<<data2.size()<<endl;
    cout<<"Capacity: "<<data2.max_size()<<endl;
    cout<<"Front: "<<data2.front()<<endl;
    cout<<"Back: "<<data2.back()<<endl;
    cout<<"At index 3: "<<data2.at(3)<<endl;
    cout<<"data2[3]: "<<data2[3]<<endl;


    data2.pop_back();
    data2.pop_back();
    data2.pop_back();
    data2.pop_back();
    cout<<"After popping out 2 elements."<<endl;
    cout<<"Size: "<<data2.size()<<endl;
    cout<<"Capacity: "<<data2.max_size()<<endl;
    // vector length changed to half when no more spaces needed.

    data2.erase(0);
    cout<<"After erasing all elements."<<endl;
    cout<<"Size: "<<data2.size()<<endl;
    cout<<"Capacity: "<<data2.max_size()<<endl;
    cout<<"Checking null exceptions."<<endl;
    try {
        data2[0]++;
        cout<<data[0];
    } catch(const char* ex) {
        cout<<ex<<endl;
    }
    cout<<"data2 is empty?: "<<data2.empty()<<endl;

    cout<<endl<<"------3------"<<endl;

    data.insert(2, 9);
    for(int i=0; i<data.size(); i++)
        cout<<data[i]<<" ";
    cout<<endl;
    data.erase(2);
    for(int i=0; i<data.size(); i++)
        cout<<data[i]<<" ";
    cout<<endl;

    cout<<endl<<"------4------"<<endl;

    vector<int> data3(10);
    data3.push_back(11);
    cout<<"Size: "<<data3.size()<<endl;
    cout<<"Capacity: "<<data3.max_size()<<endl;
    cout<<"data3 is empty?: "<<data3.empty()<<endl;
    data3.erase(0);
    cout<<"Size: "<<data3.size()<<endl;
    cout<<"Capacity: "<<data3.max_size()<<endl;
    cout<<"data3 is empty?: "<<data3.empty()<<endl;

    cout<<endl<<"------5------"<<endl;

    try {
         vector<int> data4(1000001);
    } catch(const char* ex) {
        cout<<ex<<endl;
    }

    return 0;
}

/** Description:    A program used to merge files using multi-threading.
 *  Author:         Himanshu Garg
 *  Please go through readme file for better understanding.
 */

#include <iostream>
#include <fstream>
#include <string>
#include <thread>
#include <cstdio>
#include "Producer.h"
#include "Consumer.h"
#include "Buffer.h"
#include "src\helper.cpp"
#include "src\h_vector.cpp"

using namespace std;

int main()
{
    string output, tpath;
    h_vector<string> paths;
    char proceed;

    cout<<"Enter Complete File path for Output: ";
    cin>>output;
    cout<<endl;


    for(int i=1; ; i++) {
        if(i>1) {
            cout<<"Want to add more files. Press y/n :";
            cin>>proceed;
            if(proceed=='n')
                break;
        }

        cout<<"Enter file path for "<<i<<":";
        cin>>tpath;

        if(!checkFileExists(tpath)) {
            i--;
            cout<<"Wrong Path. Enter Again."<<endl;
            continue;
        }
        paths.push_back(tpath);

        try {
            appendAtAtAt(paths[i-1]);
            Buffer *b=new Buffer();
            Producer *p=new Producer(b, paths[i-1]);
            Consumer *c=new Consumer(b, output);

            std::thread *p_thread=new thread(&Producer::run, p);
            std::thread *c_thread=new thread(&Consumer::run, c);

            p_thread->join();
            c_thread->join();

        } catch(const char *ex) {
            std::cout<<ex<<std::endl;
        }
    }
    // removing input files
    cout<<"File Merged Successfully."<<endl;
    for(int i=0; i<paths.size(); i++) {
        remove(paths[i].c_str());
    }
    return 0;
}

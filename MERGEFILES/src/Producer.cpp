#include "Producer.h"
#include <fstream>
#include <iostream>


Producer::Producer(Buffer *buffer_, std::string file_) {
    buffer=buffer_;
    file=file_;
}

Producer::~Producer() {

}

void Producer:: run() {
    std::ifstream inputFile;
    std::string locBuffer;

    inputFile.open(file);
    if(!inputFile)
        throw "File Not Found.";


    while(getline(inputFile, locBuffer)) {
        //std::cout<<"Producer: "<<locBuffer<<std::endl;
        buffer->put(locBuffer);
        if(locBuffer.length()>=3 && locBuffer.substr(locBuffer.length()-3, 3).compare("@@@")==0)
            break;
    }
    inputFile.close();
}



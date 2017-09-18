#include "Consumer.h"
#include <fstream>
#include <iostream>
#include <ios>

Consumer::Consumer(Buffer *buffer_, std::string file_) {
    buffer=buffer_;
    file=file_;
}

Consumer::~Consumer() {
}

void Consumer:: run() {
    std::ofstream outputFile;
    outputFile.open(file,  std::ios_base::app);
    if(!outputFile)
        throw "File Not Found.";

     while(true) {
        std::string *locBuffer= buffer->get();
        if(locBuffer->length()>=3 && locBuffer->substr(locBuffer->length()-3, 3).compare("@@@")==0)
            break;
        outputFile<<*locBuffer<<std::endl;
        delete locBuffer;
    }
    outputFile.close();
}


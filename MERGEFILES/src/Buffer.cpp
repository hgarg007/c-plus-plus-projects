#include "Buffer.h"
#include <cstring>
#include <iostream>

Buffer::Buffer() {
}
Buffer::~Buffer() {
}

void Buffer::put(std::string locBuffer) {
    std::unique_lock<std::mutex> locker(mu);
    while(data.size()==10)  {
            cond.wait(locker);
    }
    data.push(locBuffer);
    locker.unlock();
    cond.notify_all();
}

std::string* Buffer::get() {
    std::unique_lock<std::mutex> locker(mu);
    while(data.size()==0) {
            cond.wait(locker);
    }
    std::string* temp=new std::string(data.front());
    data.pop();
    cond.notify_all();
    locker.unlock();
    return temp;

}

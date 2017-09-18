#include <mutex>
#include <chrono>
#include <condition_variable>
#include <string>
#include <queue>

#ifndef BUFFER_H
#define BUFFER_H


class Buffer
{
    public:
        Buffer();
        virtual ~Buffer();
        void put(std::string);
        std::string* get();

    protected:

    private:
        std::queue<std::string> data;
        std::mutex mu;
        std::condition_variable cond;
};

#endif // BUFFER_H

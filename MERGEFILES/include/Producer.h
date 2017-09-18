#include <string>
#include "Buffer.h"


#ifndef PRODUCER_H
#define PRODUCER_H


class Producer
{
    public:

        Producer(Buffer * , std::string );
        virtual ~Producer();
        void run();
    protected:

    private:
        Buffer *buffer;
        std::string file;
};

#endif // PRODUCER_H

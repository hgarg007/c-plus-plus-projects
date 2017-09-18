#include "Buffer.h"
#include <string>

#ifndef CONSUMER_H
#define CONSUMER_H


class Consumer
{
    public:

        Consumer(Buffer *, std::string );
        virtual ~Consumer();
        void run();

    protected:

    private:
        Buffer *buffer;
        std::string file;
};

#endif // CONSUMER_H

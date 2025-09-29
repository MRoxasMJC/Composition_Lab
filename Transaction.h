#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>


class Transaction {
    public:
        std::string type;
        double amount;      
        std::string timestamp;
};

#endif

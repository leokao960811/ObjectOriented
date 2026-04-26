#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
using namespace std;

class Customer {
protected:
    string name;
    string type;

public:
    Customer(string name, string type);
    virtual ~Customer();

    string getName() const;
    string getType() const;

    virtual int getRentalDays() const = 0;
    virtual int getRentalLimit() const = 0;
};

class BreezyCustomer : public Customer {
public:
    BreezyCustomer(string name);

    int getRentalDays() const override;
    int getRentalLimit() const override;
};

class RegularCustomer : public Customer {
public:
    RegularCustomer(string name);

    int getRentalDays() const override;
    int getRentalLimit() const override;
};

class HoarderCustomer : public Customer {
public:
    HoarderCustomer(string name);

    int getRentalDays() const override;
    int getRentalLimit() const override;
};

#endif
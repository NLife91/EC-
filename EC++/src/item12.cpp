/** Item 12: Copy all parts of an object. */

#include <iostream>
#include <string>

void logCall(const std::string& funcName)
{
	std::cout << funcName << std::endl;
}


/** 1. Copy all local data members 
    2. Invoke the appropriate copying function in all base classes */
class Customer
{
public:
	Customer(const Customer& rhs)
		: name(rhs.name)
		//, lastTransaction(rhs.lastTransaction) 1.
	{
		logCall("Customer copy constructor");
	}

	Customer& operator=(const Customer& rhs)
	{
		logCall("Customer copy assignment operator");
		
		name = rhs.name;
		//lastTransaction = rhs.lastTransaction; 1.

		return *this;
	}

private:
	std::string name;
	//std::string lastTransaction; 1.
};

class PriorityCustomer : public Customer
{
public:
	PriorityCustomer(const PriorityCustomer& rhs)
		: Customer(rhs) // 2.
		, priority(rhs.priority)
	{
		logCall("Priority Customer copy constructor");
	}

	PriorityCustomer& operator=(const PriorityCustomer& rhs)
	{
		logCall("Priority Customer copy assignment operator");

		Customer::operator=(rhs); // 2.

		priority = rhs.priority;

		return *this;
	}

private:
	int priority;
};
/** Item 9: Never call virtual functions during construction or destruction. */

#include <iostream>
#include <string>

/** Never call virtual function during construction. */
// derived class data members have not been initialized when base class constructors run.
// During base class contruction of a derived class object, the type of the object is that of the base class.
// The same reasoning applies during destruction.

class Transaction1
{
public:
	Transaction1()
	{
		longTransaction();
	}

	virtual ~Transaction1()
	{
		longTransaction();
	}

	virtual void longTransaction() const
	{
		std::cout << "Transaction1" << std::endl;
	}
};

class BuyTransaction1 : public Transaction1
{
public:
	BuyTransaction1()
		: Transaction1()
	{}

	~BuyTransaction1()
	{}

	virtual void longTransaction() const override
	{
		std::cout << "BuyTransaction1" << std::endl;
	}
};

// call virtual function in non-virtual function
class Transaction2
{
public:
	Transaction2()
	{
		init();
	}

	virtual void longTransaction() const
	{
		std::cout << "Transaction2" << std::endl;
	}

private:
	void init()
	{
		longTransaction();
	}
};

/** One problem solve. */

class Transaction3
{
public:
	// explicit constructor
	explicit Transaction3(const std::string& logInfo)
	{
		longTransaction(logInfo);
	}

	// non-virtual function
	void longTransaction(const std::string& logInfo)
	{
		std::cout << logInfo << std::endl;
	}
};

class BuyTransaction3 : public Transaction3
{
public:
	BuyTransaction3(const std::string& param1, const std::string& param2)
		: Transaction3(createLogString(param1, param2))
	{
	}

private:
	static std::string createLogString(const std::string& param1, const std::string& param2)
	{
		return param1 + param2;
	}
};
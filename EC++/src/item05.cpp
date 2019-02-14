/** Item 5: Know what functions C++ silently writes and calls */
#include <string>

/** Compliler's own versions code if don't declare */
class Empty 
{
public:
	Empty() {}							// default constructor

	Empty(const Empty& rhs) {}			// copy constructor

	~Empty() {}							// destructor

	Empty& operator=(const Empty& rhs)  // copy assignment operator
	{
		return const_cast<Empty&>(rhs);
	}
};

void generate()
{
	Empty e1;		// default constructor, destructor generate
	Empty e2(e1);	// copy constructor generate
	e2 = e1;		// copy assignment operator generate
}

/** the generated destructor is non-virtual unless it's for a class inheriting from a base class that itself declares a virtual destructor */

template<class T>
class NamedObject
{
public:
	// NamedObject() {} complier won't generate a default constructor.
	NamedObject(std::string& name, const T& value) 
		: nameValue(name)
		, objectValue(value)
	{}

private:
	std::string& nameValue;
	const T objectValue;
};

void refuse()
{
	std::string newDog("Persephone");
	std::string oldDog("Satch");

	NamedObject<int>(newDog, 2);
	NamedObject<int>(oldDog, 36);

	// p = s; Compiler refuse. because reference and const value.
}

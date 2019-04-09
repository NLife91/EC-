/** Item 4: Make sure that objects are initialized before they're used. */
#include <iostream>
#include <string>
#include <list>

/** built-in type init */
void bitype()
{
	int x = 0;

	const char* text = "A C-style string";

	double d;
	std::cin >> d;
}


/** Constructor: Assignment and Initialization */
class PhoneNumber {};

class ABEntry
{
public:
	ABEntry()
		: theName()
		, theAddress()
		, thePhones()
		, numTimesConsulted(0)
	{
	}

	ABEntry(const std::string& name, const std::string& address, const std::list<PhoneNumber>& phones)
		// Initialization
		// Initialization list
		: theName(name)
		, theAddress(address)
		, thePhones(phones)
		, numTimesConsulted(0)

	{
		// Assignment
		theName = name;
		theAddress = address;
		thePhones = phones;
		numTimesConsulted = 0;
	}

private:
	std::string theName;
	std::string theAddress;
	std::list<PhoneNumber> thePhones;
	int numTimesConsulted;
};

/** Object's data initialization order */
// 1. Base classes are initialized before derived classes
// 2. Data members are initialized in the order in which they are declared.

/** The order of Initialization of "Non-local" "Static" objects defined in different "Translation Units" */
// Non-local Static - global, at namespace scope, static in a class, at file scope
// Local Static - static in function
// Translation Unit - the source code giving rise to a single object file

// the relative order of initialization of non-local static objects defined in different translation units is 
// Undefined.

class FileSystem1
{
public:
	std::size_t numDisks() const
	{}
};

extern FileSystem1 tfs; // init

class Directory1
{
public:
	Directory1()
	{
		std::size_t disks = tfs.numDisks(); // Use FileSystem object
	}
};

Directory1 tempDir(); // init


// non-local static to local static
class FileSystem2 
{
public:
	std::size_t numDisks() const
	{}
};

FileSystem2& ftfs()
{
	static FileSystem2 fs; // local static
	return fs;
}

class Directory2
{
public:
	Directory2()
	{
		std::size_t disks = ftfs().numDisks();
	}
};

Directory2& ftempDir()
{
	static Directory2 td; // local static
	return td;
}

/** Things to Remember
	 * Manually initialize objects of built-in type, because C++ only sometimes initializes them itself.
       
	 * In a constructor, prefer use of the member initialization list to assignment inside the body of the constructor.
       List data members in the initialization list in the same order they're declared in the class.
       
	 * Avoid initialization order problems across translation units by replacing non-local static objects with local
       static objects.
*/

/** Item 18: Make interfaces easy to use correctly and hard to use incorrectly. */

#include <iostream>
#include <list>
#include <vector>

class Date1
{
public:
	Date1(int month, int day, int year);
};

void errors()
{
	Date1 d1(30, 3, 1995);

	Date1 d2(3, 40, 1995);
}

/** 1. Prevent errors : new types. */
struct Day
{
	explicit Day(int d);
};

struct Month
{
	explicit Month(int m);
};

struct Year
{
	explicit Year(int y);
};

/** 2. Prevent errors : constraining object values. */
class Month2
{
public:
	static Month2 Jan() { return Month2(1); }
	static Month2 Feb() { return Month2(2); }
	static Month2 Mar() { return Month2(3); }

	static Month2 Dec() { return Month2(12); }

private:
	explicit Month2(int m);
};

class Date2
{
public:
	Date2(const Month& m, const Day& d, const Year& y);
	Date2(const Month2& m, const Day& d, const Year& y);
};

void types()
{
	// Date2 d1(30, 3, 1995); // error
	
	// Date2 d2(Day(30), Month(3), Year(1995)); // error

	Date2 d3(Month(3), Day(30), Year(1995));
}

void types2()
{
	Date2 d(Month2::Mar(), Day(30), Year(1995));
}

/** 3. Prevent errors : restricting operations on types. */
/** behavioral compatibility with built-in types. */
class AsInt
{
public:
	const AsInt& operator*(const AsInt& rhs);
};

void doAsInt()
{
	int a, b, c;


	if (a * b = c) {}

	AsInt aa, bb, cc;

	if (aa * bb = c);
}

/** consistency in interfaces and behavioral compatibility with built-in types. */
void stl()
{
	std::list<int> intList;
	std::vector<int> intVector;

	intList.push_back(1);
	intList.push_back(2);
	intVector.push_back(1);
	intVector.push_back(2);

	intList.size();
	intVector.size();
}

class Investment {};

void getRidOfInvestment(Investment* investment);

// Avoid resource leaks 
// Investment* createInvestment();
// shared_ptr's custom deleter prevents the cross-DLL problem.
std::shared_ptr<Investment> createInvestment()
{
	std::shared_ptr<Investment> retVal(static_cast<Investment*>(0), getRidOfInvestment);

	retVal = std::shared_ptr<Investment>(new Investment());

	return retVal;
}

/** Things to Remember
	 * Good interfaces are easy to use correctly and hard to use incorrectly. Your should strive for these
       characteristics in all your interfaces.
     
	 * Ways to facilitate correct use include consistency in interfaces and behavioral compatibility with
       built-in types.
     
	 * Ways to prevent errors include creating new types, restricting operations on types, constraining
       object values, and eliminating client resource management responsibilities.
       
	 * TR1::shared_ptr supports custom deleters. This prevents the cross-DLL problem, can be used
       to automatically unlock mutexes (see Item 14), etc.
*/

/** Item 7: Declare destructors virtual in polymorphic base classes. */
#include <string>

class TimeKeeper
{
public:
	TimeKeeper();
	virtual ~TimeKeeper(); // Virtual destructor.

	virtual void getCurrentTime(); // Virtual function.
};

class AtomicClock : public TimeKeeper { ~AtomicClock(); };
class WarterClock : public TimeKeeper { ~WarterClock(); };
class WristWatch : public TimeKeeper { ~WristWatch(); };

TimeKeeper* getTimeKeeper()
{
	return new AtomicClock();
}

void destructor()
{
	TimeKeeper* ptk = getTimeKeeper();

	delete ptk;
}

/** vptr(virtual table pointer) & vtbl(virtual table) */
class Point
{
public:
	Point(int x, int y);
	~Point();			// vptr & vtbl X
	virtual ~Point();	// vptr & vtbl O
};

/** not designed to be base classes or not designed to be used polymorphically. */
class SpecialString : public std::string
{
public:
	SpecialString(std::string newStr) : std::string(newStr) {};
	~SpecialString();
};

void notDesigned()
{
	SpecialString* pss = new SpecialString("test");
	std::string* ps;

	ps = pss;

	delete ps; // ~SpecialString() is not called;
}

/** abstract class */
class AWOV
{
public:
	virtual ~AWOV() = 0; // virtual function for abstract class & virtual destructor for polymorphic base class
};

AWOV::~AWOV() {}
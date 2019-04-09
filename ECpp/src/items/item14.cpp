/** Item 14: Think carefully about copying behavior in resource-managing classes. */

#include <iostream>

class Mutex {};

/** Prohibit copying. */
class Lock1
{
private:
	Lock1(const Lock1& rhs);
	Lock1& operator=(const Lock1& rhs);
};

/** Reference-count the underlying resource. */
class Lock2
{
public:
	explicit Lock2(Mutex* pm)
		: mutexPtr(pm)
	{
		lock(mutexPtr.get());
	}

	void lock(Mutex* pm) {}

private:
	std::shared_ptr<Mutex> mutexPtr;
};

/** Copy the underlying resource. */
// deep copy : the resource-managing object & resource object copy.
// std::string.

/** Transfer ownership of the underlying resource. */
// auto_ptr.
void transfer()
{
	std::auto_ptr<Lock2> pLock1(new Lock2(new Mutex()));
	
	std::auto_ptr<Lock2> pLock2(pLock1); // pLock1 -> nullptr | pLock2 -> object.

	pLock1 = pLock2;					 // pLock1 -> object  | pLock2 -> nullptr.
}

/** Things to Remember
	 * Copying an RAII object entails copying the resource it manages, so the copying behavior of the
       resource determines the copying behavior of the RAII object.
       
	 * Common RAII class copying behaviors are disallowing copying and performing reference counting,
       but other behaviors are possible.
*/
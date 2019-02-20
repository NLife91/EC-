/** Item 13: Use objects to manage resources. */

#include <iostream>

class Investment {};

Investment* createInvestment()
{
	return new Investment();
}

void f()
{
	Investment* pInv1 = createInvestment();

	// return, exception, etc.

	delete pInv1; // Release object. but maybe can't reach delete

	
	std::auto_ptr<Investment> pInv2(createInvestment()); 
	// RAII : Resource Acquision Is Initialization.
	// Resources are acquired and immediately turned over to resource-managing objects.
	// Resource-managing objects use their destructors to ensure that resources are released.
	// delete in auto_ptr<Investment> destructor
	// c++11 std::unique_ptr<Investment> pInv2(createInvestment());

	std::shared_ptr<Investment> pInv3(createInvestment()); 
	std::shared_ptr<Investment> pInv4(pInv3); // shared_ptr can share object. but auto_ptr can't

	std::auto_ptr<std::string> aps(new std::string[10]); 
	// auto_ptr call delete not delete [].
}

/** Item 30: Understand the ins and outs of inlining. */

/** implicit way */
// a fucntion inside a class definition
class Person
{
public:
	int age() const { return theAge; }

private:
	int theAge;
};

/** explicit way */
template<typename T>
inline const T& max(const T& a, const T& b)
{
	return a < b ? b : a;
}

/** calls to an inline function may or may not be inlined,
    depending on how the calls are made */
inline void f() {} // assume inlined.

void depending()
{	
	void(*pf)() = f;

	f(); // inlined.

	pf(); // not inlined.
}

/** inline function is impossible to provide binary upgrades. must recomplie.*/

/** Things to Remember 
     * Limit most inline to small, frequently called functions. This fac */
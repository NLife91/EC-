/** Item 21: Don't try to return a reference when you must return an object. */

/** Wrong */
class Rational
{
public:
	Rational(int numerator = 0, int denominator = 1);

private:
	int n, d;
	
	friend const Rational& operator*(const Rational& lhs, const Rational& rhs);
	friend bool operator==(const Rational& lhs, const Rational& rhs);
};

const Rational& operator*(const Rational& lhs, const Rational& rhs)
{
	// Stack
	// local object are destroyed when function exits.
	Rational result1(lhs.n * rhs.n, lhs.d * rhs.d);
	return result1;

	// Heap
	// new & delete pair problem
	Rational* result2 = new Rational(lhs.n * rhs.n, lhs.d * rhs.d);
	return *result2;

	// Static
	static Rational result3;

	return result3;
}

void staticTest()
{
	Rational a, b, c, d;

	if ((a * b) == (c * d))
	{
		// (a * b) == Rational static
		// (c * d) == Rational static 
	}
}

/** Correct */
class Rational2
{
public:
	Rational2(int numerator = 0, int denominator = 1);

private:
	int n, d;

	friend inline const Rational2 operator*(const Rational2& lhs, const Rational2& rhs)
	{
		// RVO (return value optimization)
		return Rational2(lhs.n * rhs.n, lhs.d * rhs.d); 
	}
};

/** Things to Remember
	 * Never return a pointer or reference to a local stack object, a reference to a heap-allocated object, or
       a pointer or reference to a local static object if there is a chance that more than one such object will
       be needed. (Item 4 provides an example of a design where returning a reference to a local static is
       reasonable, at least in single-threaded environments.)
*/
/** Item 6: Explicitly disallow the use of compiler-generated fucntions you do not want */

/** Prevent use copy constructor and copy assignment operator */

// private, can use in member and friend
class HomeForSale1
{
public:
	HomeForSale1() {}
	void prevent() 
	{
		HomeForSale1 h11;
		HomeForSale1 h12;

		HomeForSale1 h13(h11);
		h11 = h12;
	}

private:
	HomeForSale1(const HomeForSale1&);
	HomeForSale1& operator=(const HomeForSale1&);
};

// Prevented.
class Uncopyable
{
protected:
	Uncopyable() {}
	~Uncopyable() {}

private:
	Uncopyable(const Uncopyable&);
	Uncopyable& operator=(const Uncopyable&);
};

class HomeForSale2 : private Uncopyable
{
public:
	void prevent()
	{
		HomeForSale2 h21;
		HomeForSale2 h22;

		//HomeForSale2 h23(h21);
		//h21 = h22;
	}
};

// Prevented. C++ 11 delete keyword. Not in book.
class HomeForSale3
{
public:
	HomeForSale3() {}
	void prevent()
	{
		HomeForSale3 h31;
		HomeForSale3 h32;

		//HomeForSale3 h33(h31);
		//h31 = h32;
	}

private:
	HomeForSale3(const HomeForSale3&) = delete;
	HomeForSale3& operator=(const HomeForSale3&) = delete;
};

void prevent()
{
	HomeForSale1 h11;
	HomeForSale1 h12;

	//HomeForSale1 h13(h11);
	//h11 = h12;

	HomeForSale2 h21;
	HomeForSale2 h22;

	//HomeForSale2 h23(h21);
	//h21 = h22;

	HomeForSale3 h31;
	HomeForSale3 h32;

	//HomeForSale3 h33(h31);
	//h31 = h32;
}
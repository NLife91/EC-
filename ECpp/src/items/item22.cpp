/** Item 22: Declare data memebers private. */

/** Syntactic consistency (item 18). */
/** Precise control over the accessiblility of data memebers. */

// control of data member's accesslevel.
class AccesLevels
{
public:
	int getReadOnly() const { return readOnly; }

	void setReadWrite(int value) { readWrite = value; }
	int getReadWrite() const { return readWrite; }

	void setWriteOnly(int value) { writeOnly = value; }

private:
	int noAccess;

	int readOnly;

	int readWrite;

	int writeOnly;
};

/** Encapsulation */

// Keeping average.
class SpeedDataCollection1
{
public:
	void addValue(int speed)
	{
		totalSpeed += speed;
		++valueCount;

		currentAverage = static_cast<double>(totalSpeed) / valueCount;
	}

	inline double averageSoFar() const { return currentAverage; }

private:
	double currentAverage;
	int totalSpeed;
	int valueCount;
};

// Calculate average when function called.
class SpeedDataCollection2
{
public:
	void addValue(int speed)
	{
		totalSpeed += speed;
		++valueCount;
	}

	double averageSoFar() const
	{
		if (valueCount == 0) return 0;

		return static_cast<double>(totalSpeed) / valueCount;
	}

private:
	int totalSpeed;
	int valueCount;
};

// Hiding data members is flexible.
// protected data memebers are similar.
// If public or protected data members are changed,
// an unknowably large amount of client code is broken.
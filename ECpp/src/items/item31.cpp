/** Item 31: Minimize compilation dependencies between files. */

#include <string>
#include <memory>
#include "date.h"

/** Compilation dependency */
class Person1
{
public:
	std::string name() const;

private:
	std::string theName; // implementation detail.
	Date theBirthDate;   // implementation detail.
};

// If any of these header files is changed, or if any of the header files they depend on changes, 
// the file containing the Person class must be recomplied, as must any files that use Person.

/** 2 Problems if interface and implementation separate. */
// 1. string is typedef. basic_string<char> = string.
// 2. compilers to know the size of objects during compilation.

/** Handle class. */
// replacement of dependencies on definitions with dependencies on declarations.
class PersonImpl;
class Date2;

class Person2
{
public:
	Person2(const std::string& name, const Date2& birthday);
	std::string name() const;
	std::string birthDate() const;

private:
	std::shared_ptr<PersonImpl> pImpl; // pointer to implementation.
};

/** Strategies that minimize compilation dependencies. */
// * Avoid using objects when object references and pointers will do.
// * Depend on class declarations instead of class definitions whenever you can.
// * Provide separate header files for declarations and definitions.

/** Interface class. */
class Person3
{
public:
	virtual ~Person3();

	virtual std::string name() const = 0;
	virtual std::string birthDate() const = 0;

	static std::shared_ptr<Person3> create(const std::string& name, const Date2& birthday);
};

class RealPerson : public Person3
{
public:
	RealPerson(const std::string& name, const Date2& birthday)
		: theName(name)
		, theBirthDate(birthday)
	{}

	virtual ~RealPerson() {}

	std::string name() const override;
	std::string birthDate() const override;

private:
	std::string theName;
	Date2 theBirthDate;
};

std::shared_ptr<Person3> Person3::create(const std::string& name, const Date2& birthDay)
{
	return std::shared_ptr<Person3>(new RealPerson(name, birthDay));
}

/** Things to Remember
	 * The general idea behind minimizing compilation dependencies is to depend on declarations instead of 
	   definitions. Two approaches based on this idea are Handle classes and Interface classes.

	 * Library header files should exist in full and declaration-only forms. This applies regardless of whether
	   templates are involved.
*/

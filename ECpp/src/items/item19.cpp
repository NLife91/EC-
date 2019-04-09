/** Item 19: Treat class design as type design */

/** How should objects of your new type be created and destroyed? */
// influences the design constructors and destructor, 
// memory allocation and deallocation function. (operator new...)

/** How should object initialization differ from object assignment? */
// the behavior of and the differences costructor and assignment operator

/** What does it mean for objects of your new type to be passed by value? */
// The copy constructor.

/** What are the restrictions on legal values for your new type? */
// some combinations of values for a class's data memebers are valid.
// the invariants.
// especially constructors, assignment operators, setter functions.
// also affect the exceptions.

/** Does your new type fit into an inheritance graph? */
// from base class's virtual and non-virtual functions
// for bass class, functions decalre are virtual especially destructor.

/** What kind of type conversions are allowed for your new type? */
// implicit conversion : operator T2 or non-explicit constructor T2(T1)
// explicit conversion : write the conversion function. do not write implicit conversion.

/** What operators and functions make sense for the new type? */
// some functions will be memeber functions, but some will not.

/** Whta standard functions should be disallowed? */
// private

/** Who should have access to the members of your new type? */
// whitch members are public, protected, private
// whitch functions should be friends
// whitch class is inside another to nest.

/** What is the "undeclared interface" of your new type? */
// guarantees : performance, exception safety, resource usage.

/** How general is your new type? */
// family of types. template.

/** Is a new type really what you need? */
// perhaps better. non-member functions or templates.

/** Things to Remember
	 * Class design is type design. Before defining a new type, be sure to consider all the issues discussed in
       this Item.
*/

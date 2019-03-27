/** Item 29: Strive for exception-safe code. */

#include <iostream>

class Mutex {};

class Image { public: Image(std::istream& imgSrc); };

void lock(Mutex* pm) {}
void unlock(Mutex* pm) {}

class PrettyMenu
{
public:
	void changeBackground(std::istream& imgSrc);

private:
	Mutex mutex;
	Image* bgImage;
	int imageChanges;
};

void PrettyMenu::changeBackground(std::istream& imgSrc)
{
	lock(&mutex);

	delete bgImage;
	++imageChanges;
	bgImage = new Image(imgSrc); // Leak resources. if exception don't unlock;
							     // data corrupted. bgImage deleted and imageChanges counted;
	unlock(&mutex);
}

// Exception-safe functions
// Leak no resources.
// Don't allow data structures to become corrupted.

// Solution leak resources.
class PrettyMenu2
{
public:
	void changeBackground(std::istream& imgSrc);

private:
	Mutex mutex;
	Image* bgImage;
	int imageChanges;
};

class Lock
{
public:
	explicit Lock(Mutex* pm)
		: mutexPtr(pm)
	{
		lock(mutexPtr.get());
	}

private:
	void lock(Mutex* pm) {}

	std::shared_ptr<Mutex> mutexPtr;
};

void PrettyMenu2::changeBackground(std::istream& imgSrc)
{
	Lock m1(&mutex); // shared ptr auto unlock.

	delete bgImage;
	++imageChanges;
	bgImage = new Image(imgSrc);
}

// Exception-safe functions offer one of three guarantees
// 1. the basic guarantee : if exception is thrown, everthing remains in a valid state.
// 2. the strong guarantee : if succeed, succeed. if fail, state that never been called.
// 3. the nothrow guarantee : never throw exceptions.

// the basic guarantee PrettyMenu
class PrettyMenu3
{
public:
	void changeBackground(std::istream& imgSrc);

private:
	Mutex mutex;
 	std::shared_ptr<Image> bgImage;
	int imageChanges;
};

void PrettyMenu3::changeBackground(std::istream& imgSrc)
{
	Lock m1(&mutex);
	bgImage.reset(new Image(imgSrc)); // can exception in new Image so not strong basic.

	++imageChanges;
}

// try strong guarantee using copy-and-swap
struct PMImpl
{
	std::shared_ptr<Image> bgImage;
	int imageChanges;
};

class PrettyMenu4
{
public:
	void changeBackground(std::istream& imgSrc);

private:
	Mutex mutex;
	std::shared_ptr<PMImpl> pImpl;
};

// doesn't guarantee that the overall functions is strongly exception-safe.
// The strong guarantee can often be implemented via copy-and-swap, but the strong guarantee is not practical for all functions.
// A function can usually offer a guarantee no stronger than the weakest guarantee of the functions it calls.
void PrettyMenu4::changeBackground(std::istream& imgSrc)
{
	using std::swap;

	Lock m1(&mutex);

	std::shared_ptr<PMImpl> pNew(new PMImpl(*pImpl));

	pNew->bgImage.reset(new Image(imgSrc)); 
	++pNew->imageChanges;

	swap(pImpl, pNew);
}

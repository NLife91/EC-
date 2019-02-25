/** Item 2: Prefer consts, enums, and inlines to #defines. */

#include <iostream>
#include <string>

/** Prefer consts to #defines.*/
#define ASPECT_RATIO 1.653

const double AspectRatio = 1.653;

#define AUTHOR_NAME "Scott Meyers"

const char *const authorName = "Scott Meyers";
const std::string authorNameStr("Scott Meyers");

/** Prefer enums to #defines.*/
#define NUM_TURNS 5
class GamePlayer1
{
private:
	int scores[NUM_TURNS];
};

// an initial value for a static class member.
// standard compiler
class GamePlayer2
{
private:
	static const int NumTurns = 5; // declaration.
	int scores[NumTurns];
};

const int GamePlayer2::NumTurns; // definition.

// older compiler
class CostEstimate
{
private:
	static const double FudgeFactor;
};

const double CostEstimate::FudgeFactor = 1.35;

// enum hack for standard and older
class GamePlayer3
{
private:
	enum { NumTurns = 5 };
	int socres[NumTurns];
};

/** Prefer inlines to #defines */
#define CALL_WITH_MAX(a, b) f((a) > (b) ? (a) : (b))

template<typename T>
inline void callWithMax(const T& a, const T& b)
{
	f(a > b ? a : b);
}

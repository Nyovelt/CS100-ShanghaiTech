// All #include lines that may be used in homework 6.
#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <string>
#include <memory>
#include <random>
#include <time.h>
#include <algorithm>

// Predefined constants for problem 2.
#define LOTTO6 6
#define LOTTO7 7

using namespace std;

/*****************************************************************\
|                            Problem 1                            |
\*****************************************************************/
template <typename T>
class CustomSet
{
public:
// Constructors and destructor:
	CustomSet();
	// Default constructor
	
	CustomSet(const CustomSet& other); 
	// Copy constructor. Should construct a copy of "other".
	
	CustomSet(T arr[], int size);								
	// Constructor using an array. 
	// Note that if there are duplicates in the array, you should ignore them.
	// And then the size of your "CustomSet" will be different from the "size" given!
	
	~CustomSet();
	// Destructor. Pay attention to memory leaks!
	
// Other member functions:
	int size();
	// Returns the size of the set.

	bool add(const T& item);
	// If "item" is already in the set, return false. 
	// Otherwise, add it to the set and return true.

	T* find(const T& item);
	// If an object in the set equals "item", return a pointer to it.
	// If "item" is not found, return nullptr(NULL).
 
	bool erase(const T& item);
	// If "item" is not in the set, return false.
	// Otherwise, erase it from the set and return true.

	CustomSet intersection(const CustomSet& other);
	// This function returns the intersection of two sets (*this and other).
	// In other words, the set of all objects that is in both *this and other.
	// If there is no intersection, just return an empty set.

	void sortSet();
	// This function sorts the objects in the set in ascending order.
	// Directly using (std::)sort is enough, if you are using an STL container.

	void printSet();
	// This function prints the set, seperating elements by { , , , }.
	// It's safe to assume that it supports operator<< of ostream (cout).
	// For example, Assume you've added 2, 4, -2, and 800 to the set, in this order.
	// This function will print: "{2, 4, -2, 800}\n"
	// Note that there are spaces between a comma(,) and the next object.
	// Print a newline at the end. (indicated by the '\n' above)

// Operators:
	CustomSet operator+ (const T& item);
	CustomSet operator+ (const CustomSet& that);
	CustomSet& operator+= (const T& item);
	CustomSet& operator+= (const CustomSet& that);
	// The operator+ and operator += are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "plus" an item means adding in the item. 
	// A set "plus" a set means taking the union of two sets.
	// However, the difference between + and += is not written here.
	// Try to figure out on your own!

	CustomSet operator- (const T& item);
	CustomSet operator- (const CustomSet& that);
	CustomSet& operator-= (const T& item);
	CustomSet& operator-= (const CustomSet& that);
	// The operator- and operator -= are overloaded.
	// They can be understood intuitively, or consider this:
	// A set "minus" an item means erasing the item. 
	// A set A "minus" a set B means subtracting B from A, or namely, A\B.
	// However, the difference between - and -= is not written here.
	// Try to figure out on your own!
	
	
	CustomSet<std::pair<T, T>> operator* (const CustomSet& that);
	// This function returns the Cartesian product of two sets (*this and that).
	// The Cartesian product of two sets is the set of all ordered pairs that satisfy:
	//		The first element of the ordered pair belongs to first set (*this);
	//		The second element of the ordered pair belongs the second set (that).
	// The (std::)pair (in header <utility>) helps representing the object in it.
	// If you have any question with Cartesian products or std::pair, just look up on Internet!

private:
	
};



/*****************************************************************\
|                            Problem 2                            |
\*****************************************************************/
class LotteryTicket
{
public:
	LotteryTicket();
	LotteryTicket(const CustomSet<int>& numbers, int round);
	virtual ~LotteryTicket();

	int getRound();
	int getCost();
	virtual int getTicketType() = 0;
	void setCost(const int& cost);
	virtual int claimPrize(const CustomSet<int>& prizeNumbers, int round) = 0;
	
private:
	CustomSet<int> m_numbers;
	int m_round; // The valid round of a ticket. An outdated ticket is invalid.
	int m_cost; // The amount of money spent on this ticket.
};


class LotteryStation
{
public:
	LotteryStation();
	~LotteryStation();

	LotteryTicket* buy(CustomSet<int> numbers, int tickettype);
	// Represents buying a ticket of "tickettype" with "numbers" at round "m_round".
	// "tickettype" is either LOTTO6 or LOTTO7 (predefined).
	// If succeeds, output a message: 
	// "Bought a (??) ticket for (??) Yuan at round (??).\n", then return a pointer to it.
	// See examples for more details.
	// If the numbers are not enough, or some numbers are out of bound for the ticket,
	//   output "Failed.\n" and return nullptr(NULL).
	
	void claimPrize(LotteryTicket* ticket);
	// Claims prize for a given ticket.
	// You should use the claimPrize() function of the ticket.
	// However, you should check the type of the ticket first,
	//   as you need to pass the right prize numbers as parameter.
	// Output a message in the end:
	// "This ticket wins (??) Yuan.\n"
	// You should not claim a ticket that's already claimed or with wrong rounds.
	// In either case above, simply print: "This ticket wins 0 Yuan.\n"

	void newRound();
	// Begins a new round, generating new prize numbers for Lotto7 and Lotto6.
	// You may use the randInt() function given. 

	bool setPrizeNumbers(CustomSet<int> numbers, int tickettype);
	// This function simply serves for the purpose of:
	// Making it easier for you to debug, and also easier for us to check your results.
	// It sets the prize numbers of the type given as the "numbers".
	// "tickettype" is either LOTTO6 or LOTTO7 (predefined).
	// If "numbers" are invalid (not enough/out of bounds), do nothing and return false.
	// If succeeded, return true.

private:
	int m_round; // Should be initialized to 0. 
	// Other private variables...
};

int randInt(int min, int max)
{
    if (max < min)
	swap(max, min);
    return rand() % (max - min + 1) + min;
}




/*****************************************************************\
|                            Problem 3                            |
\*****************************************************************/
class GechatUser
{
public:
	// Assume using namespace std;
	GechatUser();	
	GechatUser(string username);
	GechatUser(const GechatUser& other);
	~GechatUser();
	
	int numFriends();
	void setUsername(string username);
	bool haveFriend(shared_ptr<GechatUser> user); // return true if user is a friend to *this.
	bool addFriend(shared_ptr<GechatUser> user); // return false only if user is invalid or already a friend.
	bool singleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool singleDelete(string username); // return false only if username not found in friends.
	bool doubleDelete(shared_ptr<GechatUser> user); // return false only if user is invalid or not a friend.
	bool doubleDelete(string username); // return false only if username not found in friends.

	// Not complete...
private:

};

// relearning C++ because all the stuff i learnt was outdated
// as you now know, // are comments
/* for multiline comments */

// not explaining basic programming concepts such as scope, operators, and comparisons
// also namespaces

// basic imports/includes
#include <iostream>
#include <array>
#include <vector>
#include <string>
#include <cassert>
#include <string_view>
#include <random>
#include <chrono>

// define macros
// constants that get replaced on compile time (i think)
#define CONST_MACRO 10

// function prototype
// useful if you want to format your code with the main function on top
void variables(); 
void operators(int a, int b); // forward declaration with parameters
// main function
// first function to run when you open the program
int main() {
    // return 0 is implicit 
}

// function declaration.
// also variable declaration
// all variables are allocated at stack automatically
// functions are camelCase btw
void variables() {
    // auto keyword for type deductions/inference
    auto a {5}; // will be int

    int x = 5; // integer, this syntax uses copy initialization, copying the value of right to left
    int x1 {5}; // "brace initialization", this is the "modern" way to initialize variables in c++
    // do mind that changing variables you still have to use equal
    double xd; // double float
    float xf; // float
    char y {'a'}; // char
    bool z {true}; // bool either true or false
    std::string str {"oh"}; // strings, these are vectors of chars

    // there are also special variable declaration syntax
    // string_view is for constant read only strings
    // constexpr also works for functions btw
    const std::string cstr {"This is constant"}; // constant, cannot be changed, set at runtime
    constexpr std::string_view cxprStr {"This is a constant, but better."}; // constexpr are defined at compile time

    // static is a bit of a weird one
    // using it on functions causes internal linkage
    // using it on variables make it so that it wont get destroyed when the function ends
    static int sx {1}; 

    // variables for data sizes
    // sizeof returns this type
    size_t size{};

    // signed and unsigned
    // unsigned = only positive integers
    // signed int overflow leads to UB
    // unsigned causes it to wrap around

    // theres also long and short if SOMEHOW what you're doing is still not enough
}

// parameters
// you can also set default parameters
void operators(int a, int b = 4) {
    // do i still have to explain this one
    // compiler follows PEMDAS
    
    // not gonna show the other operators
    std::cout << a + b << std::endl;
    return; // return statement, nothing returned because void function
    // return statements are however, implicit in void functions
}

// strings
// they're pretty complex as they're simply not char arrays or char pointers
// im pretty sure they inherit the vector class
// more on that in a bit
void strings(std::string s) {
    s.length(); // get string length
    s.append("a"); // append to string
    s.c_str(); // returns a C-style string, const char* to be specific
}

// compound statements
// used in if statements most of the time
// huh
void compoundBlocks() {
    int val{};
    {
	int val2{};
    }
}

// aliases for types
// structs are pretty much primitive classes
void aliasesAndStructs() {
    // same thing
    // first one is more encouraged
    using diffLong = long int;
    typedef long int diffLong1;

    struct type_s {
	int a {};
	int b {};
    };
    type_s ab {5, 8};
    ab.a = 4;
    ab.b = 6;
    ab = {4, 5}; // this also works

    // while the dot operator works fine for most cases
    // you would have to use -> when using structs in pointers
}

// templates
// templates are templates for making functions
// nice alternative to overloading
// o no
template <typename T> // define template param
T add(T x, T y) {
    return x + y;
}
// to call, it's TempFuncName<type>(params)
// C++ will also try its best to guess what type you passed, so you can just do
// TempFuncName(params)
// this will instantiate then create the function

// enums
// constant variables
// often used to represent states and such
enum enumExample {
    ENUM1,
    ENUM2,
};

// arrays and vectors
void arraysAndVecs() {
    // C-style arrays
    // not gonna explain multidimensional arrays just because
    // these arrays have fixed length and such
    // type arrayName[size] {};
    // also std::sort works with these lol
    // std::sort uses quicksort non descending order by default
    int arr[20] {};

    // get length
    int len = sizeof(arr) / sizeof(arr[0]);

    // while this may seem to represent the array. it actually
    // represents a pointer to the first element of the array.
    // hence, we could add to it to find the position we are looking for.
    // (i. e. arr + 1 will be equal to arr[1] and so on)
    printf("%d", *arr);

    // std::arrays
    // arrays but better and modern
    // just like c-style arrays, they have fixed sizes and etc
    // std::array<type, length> arrname;
    std::array<int, 5> arr1;
    // passing std::arrays to functions require the parameter to include their length
    
    // std::find() for finding elements
    // requires parameters beginning, end, and element to search
    // if it cant find the element to search, it returns the end of the array
    //
    // theres also find_if for conditional (i.e. if string in string)

    // get length but modern
    int len1 = arr1.size();
    // also includes checking for OOB with .at()
    
    // vectors
    // arrays but better BUT better
    // length doesnt need to be specified
    // can also initialize them like arrays
    std::vector<int> vec;
    vec.push_back(9); // insert
    vec.pop_back(); // pop
    vec.resize(5); // set length to 5
    // resizing however is expensive.
    // also has .size() like arrays
}

// pointers
// pointers hold a reference to the variable they are holding
// this can be used to increase performance since you dont have to 
// copy large objects to functions and such in specific scenarios
// :D
void pointers() {
    // there are many types of pointers in c++
    // maybe too many for its own good
    
    // the trick for me to understanding pointers is treating them as a separate type
    // int and int* are not the same, the other one signals that its a pointer to a variable of type int
    int r {0};
    
    // raw pointers, considered "outdated" and "unsafe"
    int* rp {&r}; 
    // reference, a more modern alternative, wont cause as much issues as raw pointers
    // references require to be initialized at declaration
    // references are also constant, and cant change "referrents", unlike raw pointers
    int& rr {r}; 

    // void pointers
    // void pointers are a special case.
    // since they have no predefined type, they can hold variables of any type
    // as long as we typecast them back to their original forms at use, void pointers will work fine
    // one thing however, we cannot use pointer arithmetic with void pointers, making them useless for arrays.
    
    // too lazy to write down function pointers
}

// while this should be at pointers
// i think it should have a section of its own
void memoryAllocation() {
    // there are different types of memory allocation
    // static = kept for the entire lifetime (i.e. globals and statics)
    // automatic = on the stack, kept for the entire block lifetime (i.e. local variables)
    // dynamic = kept on the heap, have to manually deallocate such variables
    
    // let's look at an example
    int* ptr = { nullptr }; // this pointer will point to nothing
    ptr = { new int }; // now it will point to an empty integer
    *ptr = 9; // change the value of our newly allocated int

    delete ptr; // delete the int we've allocated after we have used it.
    // failing to deallocate "leaks" the memory, and leaves the system in charge to clean it up
    // depending on your situation, this could lead to a simple "oh, my OS already fixed it" or "oh, oh no."
    ptr = nullptr; // set pointers to null after to avoid dangling pointer

    // knowing this, we can make dynamic arrays and more.
}

// typecasting
// most cases c++ handle this implicitly, but for the sake of learning
void typeCast(){
    // while C has the ol' (type) for typecasting, c++
    // uses static_cast to handle such
    double x {4.5};
    int y {static_cast<int>(x)};
    // do keep in mind static cast can cause UB if you're typecasting something stupid
}


// namespaces
// foo::something()
// you can also nest namespaces, for some reason.
// you can also use these to share global vars across files
namespace foo {
    constexpr int bar { 4 };
    void something() {
	std::cout << "foo";
    }
}

// control flow and loops
void controlFlow() {
    // as long as the if condition returns a non zero value, its seen as true
    if (2 > 3) {
	// do thing
    } else if (2 < 3) {
	// do other thing
    } else {
	// do thing
    }

    int x {9};

    // switch case
    // preferred over if else chains
    switch (x) {
	case 9:
	    // thing
	    // theres extra syntax called "fallthroughs that tell the compiler to simply put, shut up 
	    // for not placing break statements.
	    break;
	case 10:
	    break;
	default:
	    break;
    }

    // loops
    for (int i {0}; i < 10; i++){
	break;
    } 

    while (true) {
	break;
    }

    // this type of loop is guaranteed to run atleast once
    do {
	// while we're on the topic of control flow
	// exit statement, takes status code as parameter
	std::exit(0);
	// now i know this portion doesnt run, but if you were to specify a
	// function to call before exiting (i.e. cleanup), you could use atexit() instead
	// might as well bundle in a lambda function declaration
	std::atexit([] () {
	    std::cout << "Exiting.." << std::endl;
	});

	// std::abort() also exits, but signals a runtime error
	// std::terminate() for exceptions
    } while (true);

    // there's also a more modern for each
    int arr[] = {2, 4, 5, 7};
    for (int i : arr) {
	std::cout << i << std::endl;
    }
}

// This will go over the basic input and output in c++
// might as well include std functions
// I, myself recommend I, myself to find another library for i/o
void stdLibs() {
    std::string input{};

    std::cout << "Hello World!" << std::endl; // output, std::endl is newline, \n is also used
    std::cin >> input; // input
    // one thing about cin, it doesnt work for strings with spaces
    // this however does
    std::getline(std::cin >> std::ws, input); // how weird.

    // error handling 
    if (!std::cin){
	std::cin.clear();
	// do something
    }

    std::cerr << "something went wrong";

    // asserts
    // guard clauses with extra info
    // static asserts are evaluated at compile time.
    assert(4 > 2); // asserts
    static_assert(sizeof(int) == 4, "How did that happen");
}

void randomness() {
    // dont use rand() it's outdated™
    // this will instead, use mersenne twister, provided by <random>
    // mersenne twister will generate a random 32 bit unsigned int
    
    std::mt19937 mt { static_cast<unsigned int>(
	std::chrono::steady_clock::now().time_since_epoch().count()
	) }; // instantiate object and set seed, here we use system time

    // or, instantiate a mt using the OS random syscall or something idk
    std::mt19937 mt1 { std::random_device{}() };

    std::cout << mt() << std::endl; // produce random number

    // but what if a random number between two numbers is what you want?
    std::uniform_int_distribution<> between {1, 6};
    std::cout << between(mt) << std::endl;

    // apparently MT has issues due to underseeding
    // this can be resolved using seed_seq, but im not gonna go into it because lol.
}


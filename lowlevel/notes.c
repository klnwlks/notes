/* 
 C is a comfy language.

 alright so basics first, you declare the main function via
 */
int main(int argc, char *argv[]){
    // code goes here
    return 0; // optional, but still good practice.
}
/*
   let's do this piece by piece:
   
   >int = the return type function will return
   while you could get away with making main() return void, it's still
   good practice to return ints

   >main = the function name, if function name is main then will
   be the first function to run

   >int arg, char *argv[] = notice how they're inside a parentheses, 
   these are function parameters, aka what is passed to the function
   in this case, these are the number of arguments and an array of 
   strings of arguments, respectively.
*/

/*
 you can declare variables like this
*/
int a = 9;
int b = 2;
/*
it goes like this:
type variable_name = value;
never forget the semicolon.
 */

int arr[] = {1, 2, 3, 4, 5};
/*
 This is an array.
 Arrays exist for grouping same types of variables together under one name
 you could access each member of array like this
 * arr[2] will point to the third element (3)
 * arr[0] will point to the first element (1)
 * and so on
 remember that arrays begin on 0.
*/

/* There are multiple types in C to choose from, these are 
 * int = 4 bytes
 * char = 1 byte
 * double = 8 bytes
 * float = 4 bytes
 * void = none unless specified, we'll talk about pointers later
 
 but there's also more, such as "signed" "unsigned" "short" and "long"
 here's a fast rundown.
 * signed = guaranteed to be able to be negative or positive
 * unsigned = only positive.
 * short = shorter datatype, less bytes
 
 to add, there are const and static types, fast rundown
 * const = value cannot be changed
 * static = variable won't be destroyed when function ends
*/

/* 
 Functions are the most fundamental way of reusing your code.
 */
int function(int param){ return param; }
// type functionName(type parameter_name){
// 	// code
// 	return variable
// }

/*
 if your function doesn't return anything, change the type to void.
 functions are great for reusing code you don't wanna write again and again
 for example

 int c = addNumbers(a, b);
 int d = addNumbers(c, b);
 */

/* arithmetic, a must have knowledge
  it's easy
  * + = add
  * - = subtract
  * / = divide
  * * = multiply
  * % = modulo (gets the remainder)
  
  but there's also more
  * += = basically a = a + b
  * -= = basically a = a - b
  * /= = basically a = a / b
  * *= = basically a = a * b
  * %= = basically a = a % b
  * ++ = increment by one
  * -- = decrement by one
  * ** = exponent
  
  comparisons also exist
  * > = greater than
  * < = less than
  * == = is equal
  * >= = is equal or greater than
  * <= = is equal or lesser than
  comparisons return 1 if it's true, and 0 if not.
*/

/*
 enums are data types that consist of int constants.
 */
enum var{
    thing = 0,
    thing2 = 2
}testvar1;

// you can declare an enum var like this
enum var testvar2; // or like this

/* structs are C's answer to OOP */
struct structName{
    int a;
    int b;
    char* string;
    float flt;
}; // basically declaring a class
// declaring struct vars is the same as enums but with keyword differences

/* now, basic program logic */
void example(int a, int b){ // you dont have to make a function for 
			       // logic, i just made a function so you can
			       //  compile this
    if (a > b){
	// do code
    } else if (a < b) {
	// do code
    } else {
	// do code
    }

    // orr
    switch(a){
	case 1: // is equal to 1
	    // code
	    break; // break means to end the ongoing loop
	case 2: // is equal to 2
	    // code
	    break;
	default: // if not in above cases
	    // code
	    break;
    }

    /* loops
     the basic way of doing a repetitive task, you can use
     for or while loops.
     */
    for (int i = 0; i < 10; i++){
	// for i = 0, i is less than 10, keep the loop going
	// code
    }

    int i = 0;
    while (i != 10){
	// while i is not equal to 10
	// code
	i++; // increment i by 1 each loop
    }
    // if you want, you can make an infinite loop
    while(1){ // while true
	// but make sure to add a break when you're done 
	// so your program doesnt freeze
	break;
    }
}

/*
 Pointers, they're great, useful, and confusing.
 */
int *c = &b;
// type *pointer_name = &value;

/*
 pretty confusing, correct?
 don't fret, it's pretty simple
 first, the ampersand (&) operator holds the memory adress of the variable
 it's like a label that shows the computer where to find said variable
 second, we must keep note that a pointer variable only holds a memory address, not the value.

 so what does it do?
 basically, holds the address of a variable (it doesnt' even have to be a variable!), and once that's done, you can do alot of things with it.
 */

/* you can change the value of what variable a pointer is holding via */
void change(){ // also dont need a function, but the compiler wont shut up
    *c = 8;
    // now the value of b will also change to 8
}
// the (*) operator can dereference a pointer, so that the program will read the value instead of the address.

/* so what can you do with pointers? 
  alot! since C doesn't have strings, you could do
*/
char *str = "this is a string";
// this is a valid string, but you could also do
char str2[] = "this is also a string";
// fun fact about arrays, if you pass the array name only, it will pass
// a pointer to the first element of the array, leading to be able to do stuff like this

// str2 + 2;
// this will now point to the third element of the array
// this also works for a char pointer string

// pointers are also useful for keeping your program efficient
// say you want to pass a big data to a function
// but passing the variable itself will lead to a copy, which is a waste
// instead, you can pass a pointer to the variable, which is more efficient

/* to add, void pointers can hold any type of variable aslong as they are a pointer */
void *p = &b;

/*
function pointers

returntype (*functionpointername)(args) { &function };
functionpointername(args)
 */

int e = (int)'a';
// variable = (type)other_variable;

/*
 this is typecasting, when you change the data type of something for an operation, in this case, we are converting the character "a" into an int, which should be 95 according to ascii codes.

 you can also type cast a variable into a pointer that holds the address of the variable like this
 (*e)
 */

/*
    Next is dynamic memory allocation
    keep in mind of these functions
    * malloc() = alloc a single block
    * calloc() = alloc multiple blocks
    * realloc() = reallocate block
    * free() = free dynamically allocated mem
    all these return a void pointer, you can typecast these or not
    remember to call free() when you're done with dynamically allocated vars
*/

// functions are used like this
void memalloc(){ // fnn
    int *n = malloc(sizeof(int)); // you will require <stdlib.h> for this, will discuss later.
    int* c = calloc(4, sizeof(int));
    int* d = realloc(d, 7 * sizeof(int)); // useful for dynamic arrays
    free(n);
    free(c);
    free(d);
}

// that's only the basics, now, you couldn't do much with these unless you plan to reinvent the wheel, so there's libraries (header files) for your needs
#include <stdio.h> // basic i/o
#include <stdlib.h> // c standard library
#include <string.h> // c string library
#include <math.h> // c math lib

/* stdio will provide you with
 * printf()
 * fgets()
 which will be useful for output and input operations
 printf("%format\n", var);
 fgets(string, maxlen, stdin);
*/

/* 
 stdlib will provide you with many useful functions such as
  *dynamic memory alloc functions
  *rand() = random number
  *atoi() = string to int
  *itoa() = int to string
  *system() = run system commands
  *exit() = stop program
  *getenv() = get environment variable, useful.
 */

/*
 string will provide you with functions such as

 * strcmp() = string comparison
 * strchr() = get if char exists in string
 * strcat() = concat strings
 * strcpy() = string copy
 * strlen() = gets length of string
 * memset() = fills a string with a set character
 */

/*
 math will provide you with
 unfortunately i have not reached trigo yet so you guys figure that out
 I SHOULD HAVE LISTENED 

 * pow(x, y) power of x to the yth
 * log(x) natural logarithm of x
 * sin() cos() tan() get respective stuff from a radian angle
 * btw radian to degree - 1rad * 180/pi
 * floor() round down
 * ceil() round up
 * exp() exponential aka f(x) = 2^x
 */

// theres also libraries for stuff such as terminal user interfaces (ncurses.h), x applications (Xlib.h) and graphics libraries (cairo.h)

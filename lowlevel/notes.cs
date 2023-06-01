// c# notes
// strongly typed, OOP centered,

//basics of the program

using System;
using System.IO; // files

namespace ProgramName {
    class Notes {
	public static void syntax() { // also function declaration

	    // types
	    // pretty basic in it's own regard, you should understand easily.
	    int a = 1;
	    double b = 2.0;
	    char c = 'c';
	    string d = "this is a string";
	    bool e = True;
	    // there is also const for constant vars

	    // type casting
	    // works the same way as C/C++
	    // type var = (newType) oldvar;
	    int.Parse("24"); // atoi;
	    int newInt;
	    newInt.ToString(); // itoa

	    // Structures
	    // Arrays
	    int[] intArr = {1, 2, 3, 4}; // syntax is more like js 
	    // or
	    int[] intArr2 = new int[10]; // initializing array size
	    // or
	    int [, ] intArr3 = new int[10, 4] // multidimensional array

	    // Lists
	    // apparently more efficient arrays
	    // List<type> varList = new List<type>();
	    List<int> intList = new List<int>{20, 20, 20};
	    intList.add(24);

	    // Operators
	    // you already know these but for good measure
	    1 + 2;
	    2 - 1; 
	    2 * 4;
	    4 / 2;
	    2 > 1;
	    2 < 1;
	    2 => 2;
	    2 <= 2;
	    1 == 3;
	    ++2;
	    2++;
	    --2;
	    2--;

	    // if statements
	    // c-like syntax, should be good
	    if (2 > 10) {
		Console.WriteLine("2 is greater than 10");
	    } else if (3 < 10) {
		Console.WriteLine("3 is less than 10");
	    } else {
		Console.WriteLine("2 is not greater than 10");
	    }

	    // loop statements
	    // also c-like
	    do {
		// code
	    } while(1 > 10); // will only run once

	    // classic for loop
	    for (int i = 0; i < 10; i++) {
		// code
	    }

	    // foreach loop, for each thing in thing
	    foreach (char c in "hi".ToCharArray()){ // also apparently strings arent char arrays by default
		// code
	    }

	    // switch
	    // already know this
	    // switch(thing) {
	    // case 1:
	    // 	code;
	    // 	break;
	    // case 2:
	    // 	code;
	    // 	break;
	    // default:
	    // 	code;
	    // 	break;
	    // }

	    // stdio
	    //
	    Console.WriteLine("basic output");
	    Console.WriteLine(d + b); // char addition
	    string input = Console.ReadLine(); // user input

	}

	public static void Classes() {
	    // this should have been in the syntax part but whatever
	    // Object var = new Object();
	    // var.objectProperty;
	    // var.objectFunc();
	    
	    // stuff for OOP
	    public // visibility
	    private // only accessible within the class
	    protected // only accessible within the same class or an inherited class
	    static // calls class without object


	}

	static void Main(string[] args) { // main function, required
	    Console.WriteLine("Hello World!"); // basic stdio
	}
    }
}

// class definitions
//
class ClassName {
    // 	objects
    public string pubVar { get; set; }
    public ClassName(string paramVar) => (pubVar) = (paramVar);

    public virtual void functionName() { return }
}

class Class2 : ClassName { // inheritance
    // code
    public override void functionName() { return } // allows polymorphism
}

// enums
// special classes that contain constants
enum Difficulty {
    Low, Average, Hard
}

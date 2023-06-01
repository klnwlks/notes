// lol. lmao.
// importing libs
use std::io;


fn funcParam(x: i32) -> i32 { // function declaration with param and return type
    return x;
}


fn main(){ // main function
    let x = 3; // variable declaration, note that this is immutable, in simple terms, a constant variable
    let y: i32 = 4; // type, most of the time rust can to type inference
    let mut z = 5; // mutable variable, value can be changed
    let mut str = String::new();

    // types
    let si: i32; // signed, 32 bits int, can go from 8-128
    let ui: u32; // unsigned, same as above
    let fi: f32; // floats
    let bv: bool; // boolean
    let cv: char; // char
    let sv = String::new(); // why is it like this
    let sv2: &str;

    // arrays/vectors

    let arrayI: [i32; 5] = [1, 2, 3, 4, 5]; // let var: [type, size]
    arrayI.len() // get array length
    let vectorI: Vec<i32> = vec![1, 2]; // vectors, arrays but better
    let slice: &[i32] = &arrayI; // pointer to array?

    struct Point { // structs
        x: i32,
        y: i32,
    }

    struct Point2(i32, i32); // tuple struct

    // enums
    enum Compass {
        North,
        West,
        South,
        East,
    }

    // generic
    // templates
    struct Foo<T>{ bar: T }

    // functions
    impl<T> Foo<T>{
        fn bar(&self) -> &T {
            &self.bar
        }
    }

    // traits
    // interfaces / typeclasses
    // read more later
    trait Frobnicate<T>{
        fn frobnicate(self) -> Option<T>;
    }

    println!("{}", x); // output
    println!("{:?}", slice); // debug style output

    io::stdin().read_line(&mut str) // reading user input
        .expect("fail lol");

    println!("input: {}", str);

    // control flow

    if x == 3 {
        println!("yea");
    } else {
        println!("lol");
    }

    // loops

    for i in arrayI {
        println!("{}", i);
    }

    // range bassed
    for i in 0u32..10 {
        println!("{}", i);
    }

    // while loops
    // infinite loop
    while 1 == 1 {
        break;
    }

    loop {
        break;
    }

    // pointers
    // just go read your c notes its the same except automatic dealloc
    let pa = 3; // this will be immutable
    let pb: &i32 = &pa;
    *pb; // dereference 

    let mut pa2 = 5; // mutable reference
    let pb2: &mut i32 = &mut pa2; 
    *pb2 = 9 // change value
}

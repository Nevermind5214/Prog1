/*
g++ Ch14Drill.cpp -o Ch14Drill
*/

#include "std_lib_facilities.h"

// 1. Define a class B1 with a virtual function vf() and a non-virtual function f() .
// Define both of these functions within class B1 . Implement each function
// to output its name (e.g., B1::vf() ). Make the functions public . Make a B1
// object and call each function.
class B1 {
public:
    virtual void vf() { cout << "B1::vf()\n"; }
    void f() { cout << "B1::f()\n"; }

    // 5. Add a pure virtual function called pvf() to B1 and try to repeat 1–4. Ex-
	// plain the result.

    // virtual void pvf() =0;

    // error: cannot declare variable ‘b1’ to be of abstract type ‘B1’
	// because the following virtual functions are pure within ‘B1’:
	// error: cannot declare variable ‘d1’ to be of abstract type ‘D1’
	// because the following virtual functions are pure within ‘D1’
};

// 2. Derive a class D1 from B1 and override vf() . Make a D1 object and call vf()
// and f() for it.
class D1 : public B1 {
public:
    void vf() { cout << "D1::vf()\n"; }
    
    // 4. Now define a function called f() for D1 and repeat 1–3. Explain the results.
    void f() { cout << "D1::f()\n"; }
};

// 6. Define a class D2 derived from D1 and override pvf() in D2 . Make an
// object of class D2 and invoke f() , vf() , and pvf() for it.
class D2 : public D1 {
public:
    void pvf() { cout << "D2::pvf()\n"; }
};

// 7. Define a class B2 with a pure virtual function pvf() . Define a class D21
// with a string data member and a member function that overrides pvf() ;
// D21::pvf() should output the value of the string . Define a class D22 that
// is just like D21 except that its data member is an int . Define a function f()
// that takes a B2& argument and calls pvf() for its argument. Call f() with a
// D21 and a D22 .
class B2 {
public:
    virtual void pvf() =0;
};

class D21 : public B2 {
public:
    void pvf() { cout << s << endl; }
    string s;
};

class D22 : public B2 {
public:
    void pvf() { cout << n << endl;}
    int n;
};

void f(B2& b2)
{
    b2.pvf();
}


int main() try{		// 4. előtt		4. után
    B1 b1;
    b1.vf();		// B1::vf()		B1::vf()
    b1.f();			// B1::f()		B1::f()

    D1 d1;
    d1.vf();		// D1::vf()		D1::vf()
    d1.f();			// B1::f()		D1::f()  azért mert mostmár van definiálva f() a D1-ben

    // 3. Define a reference to B1 (a B1& ) and initialize that to the D1 object you
	// just defined. Call vf() and f() for that reference.
    B1& b1ref = d1;
    b1ref.vf();		// D1::vf()		D1::vf()
    b1ref.f();		// B1::f()		B1::f()

    D2 d2;
    d2.f();			// D1::f()
    d2.vf();		// D1::vf()
    d2.pvf();		// D2::pvf()

    D21 d21;
    d21.s = "d21.s";
    D22 d22;
    d22.n = 22;		// 
    f(d21);			// d21.s
    f(d22);			// 22
}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}
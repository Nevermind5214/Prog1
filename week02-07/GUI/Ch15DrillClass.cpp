/*
g++ Ch15DrillClass.cpp -o Ch15DrillClass
*/

#include "std_lib_facilities.h"

// 1. Define a struct Person containing a string name and an int age.
// 9. Change the representation of Person to have first_name and second_name
// instead of name . Make it an error not to supply both a first and a second
// name. Be sure to fix >> and << also. Test.
struct Person {
	Person() : first_nme(""), second_nme(""), ag(0) { }
	Person(string fn, string sn, int age) :first_nme(fn), second_nme(sn), ag(age)
	{
		// 7. Modify the constructor to check that age is [0:150) and that name doesn’t
		// contain any of the characters ; : " ' [ ] * & ^ % $ # @ ! . Use error() in case
		// of error. Test.
		const string ill_chars = ";:\"'[]*&^%$#@!";
		for (int i = 0; i<fn.size(); ++i)
		{
			for (int j = 0; j<ill_chars.size(); ++j)
			{
				if (fn[i]==ill_chars[j]) error("illegal character: ",string(1,fn[i]));
			}
		}

		for (int i = 0; i<sn.size(); ++i)
		{
			for (int j = 0; j<ill_chars.size(); ++j)
			{
				if (sn[i]==ill_chars[j]) error("illegal character: ",string(1,sn[i]));
			}
		}

		if (ag<0 || ag>=150) error("age must be in range [0,150]");
	}

	// 5. Make the representation of Person private, and provide const member
	// functions name() and age() to read the name and age.
	string first_name() const { return first_nme; }
	string second_name() const { return second_nme; }
	int age() const { return ag; }
private:
	string first_nme;
	string second_nme;
	int ag;
};

// 3. Define an input ( >> ) and an output ( << ) operator for Person ; read in a
// Person from the keyboard ( cin ) and write it out to the screen ( cout ).

// 6. Modify >> and << to work with the redefined Person .
istream& operator>>(istream& is, Person& p)
{
	string fname, sname;
	int age;
	is >> fname >> sname >> age;
	if (!is) return is;
	p = Person(fname,sname,age);
	return is;
}

ostream& operator<<(ostream& os, const Person& p)
{
	return os << "Name: " << p.first_name() << ' ' << p.second_name() << ", age: " << p.age();
}

int main()
try {
	// 2. Define a variable of type Person , initialize it with “Goofy” and 63, and
	// write it to the screen ( cout ).
	/*
		Person goofyperson;
	goofyperson.n = "Goofy";
	goofyperson.a = 63;
	cout << "Name: " << goofyperson.n << ", age: " << goofyperson.a << endl;

	// 3.
	cout << "Enter name and age: ";
	Person harmadik;
	cin >> harmadik;
	cout << harmadik << endl;

	//8. Read a sequence of Person s from input ( cin ) into a vector<Person> ;
	// write them out again to the screen ( cout ). Test with correct and errone-
	// ous input.*/
	vector<Person> persons;
	Person ujperson;
	cout << "Please enter 3 persons!" << endl;
	for (int i = 0; i < 3; ++i)
	{
		cin >> ujperson;
		persons.push_back(ujperson);
	}
	
	for (int i = 0; i < persons.size(); ++i) cout << persons[i] << endl;

}

catch (exception& e) {
	cerr << "Oopsie doopsie wtf happened, exception: " << e.what() << endl;
}

catch (...) {
	cerr << "cerr everything else exception\n";
}
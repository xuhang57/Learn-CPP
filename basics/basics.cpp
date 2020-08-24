#include <iostream>
#include <array>

// Functions
bool isEven(int number) {
    auto res = (number % 2) == 0;
    return res;
}

// Basic Types
void cpp_BasicTypes() {
    int messageId = 123456;          // usually 32-bit signed
    std::string name = "Lucas";      // 8-bit character std::string
    bool isViewer =  true;           // 8 bits boolean type
    char middleInitial;              // 8 bit signed
    short editCount = 9;             // usually 16-bit signed
    double createdTime = 123.45;     // 64 bit signed
    long double deleteTime = 9.1;    // 128-bit signed
    unsigned flags = 0x0;            // unsigned?
    const unsigned maxFriend = 20;   // compile time constant
    std::array<std::string, maxFriend> friends; // array
}

// Standard Constants
void cpp_StandardConstants() {
    auto saved = true;            // type inferred to be bool by compile
    auto dirty = false;           // type inferred to be bool by compile
    std::shared_ptr<char> buffer = nullptr;  // null pointer value
}

// Arithmetic Operations
void cpp_Arithmetic() {
    std::cout << (9 + 30) << std::endl;         // addition
    std::cout << (30 - 9) << std::endl;         // substraction
    std::cout << -(9 * 30) << std::endl;        // unary negation
    std::cout << 30 / 10 << std::endl;          // division
    std::cout << 9 % 2 << std::endl;            // modulus
    auto a = 9;
    ++a;
    std::cout << a << std::endl;                // pre increment
    a++;
    std::cout << a << std::endl;                // post increment
    --a;
    a--;
 }

 // Comparison Operations
 void cpp_Comparison() {
     std::cout << (9 == 8) << std::endl;        // equality comparison
     std::cout << (9 != 8) << std::endl;        // inequality comparison
     std::cout << !true << std::endl;           // negation
     std::cout << (7 < 8) << std::endl;         // less than
     std::cout << (7 <= 8) << std::endl;        // less than or equal
     std::cout << (7 > 8) << std::endl;         // greater than
     std::cout << (1 >= 9) << std::endl;        // greater than or equal
 }

 // Logical Operation
void cpp_Logical() {
    std::cout << (true && false) << std::endl;  // logical And
    std::cout << (false || true) << std::endl;  // logical Or
}

// Bitwise Operation
void cpp_Bitwise() {
    std::cout << std::hex << (0xf1 & 0x01) << std::endl;  // bitwise And
    std::cout << std::hex << (0xf0 | 0x01) << std::endl;  // bitwise Or
    std::cout << std::hex << (0xf0 ^ 0xf0) << std::endl;  // bitwise xor
    std::cout << std::hex << ~0xf0f0f0 << std::endl;      // bitwise complement
}

// Variables and Scope
void cpp_VariablesAndScopes() {
    auto initialized = true;         // compiler type inferred to be bool
    int readCount = 0;               // explicit type declaration
    int likeCount;                   // declared but uninitialized

    if (initialized) {
        auto readCount = 10;         // block variable shadows local readCount;
        std::cout << readCount << std::endl; // 10;
    } 
    std::cout << readCount << std::endl;  // 0
}

// References
void cpp_ReferenceGood(int& r) {  // reference to an integer
  r = 40;                         // modify the referenced object
}

// void cpp_ReferrenceBad(const int& r) { // constant reference to message
//     r = 20; // compile error
// }

void cpp_References() {
    int x = 10;
    cpp_ReferenceGood(x);
    std::cout << std::dec << x << std::endl;         // ensure std::cout not still in std::hex mode
}

// Condition and Control Flow
void cpp_ConditionAndControlFlow() {
    int unreadCount = 20;
    if (unreadCount) {
        std::cout << "Has Unread" << std::endl;
    }
    if (unreadCount) {
        std::cout << "Has Unread" << std::endl;
    } else {
        std::cout << "All Read" << std:: endl;
    }

    if (unreadCount > 99) {
        std::cout << "Many unread" << std::endl;
    } else if (unreadCount > 0) {
        std::cout << unreadCount << " Unread" << std::endl;
    } else {
        std::cout << "All Read" << std::endl;
    }
}

// Switch Statement
void cpp_SwitchStatement() {
    const int TypeNormal = 0;
    const int TypeAdmin = 1;
    const int TypeOther = 2;
    int type = TypeAdmin;

    switch(type) {
        case TypeNormal: {
            std::cout << "Normal" << std::endl;
        }
        break;

        case TypeAdmin: {
            std::cout << "Admin" << std::endl;
        }
        break;

        default: {
            std::cout << "Other" << std::endl;
        }
        break;
    }
}

// Loops
void cpp_Loops() {
    std::array<std::string, 4> messages = {"hello", "world", "lucas", "xu"};

    for (int i = 0; i < messages.size(); i++) {
        std::string& m = messages[i];
        if (m == "lucas") {
            std::cout << "will break" << std::endl;
            break;
        }
        if (m == "hello") {
            std::cout << "will continue" << std::endl;
            continue;
        }

        std::cout << "message: " << m << std::endl;
    }
}

// Structs
struct Person {
    std::string name;
    int age;
};

// Construct
void cpp_StructConstruct() {
    Person lucas{"lucas xu", 22};
    std::cout <<lucas.name << " is" << lucas.age << " old" << std::endl;
}

// Pass by Reference
void makeOlder(Person& p) {
    p.age += 1;
}

void cpp_StructByRef() {
    Person lucas{"lucas xu", 22};
    makeOlder(lucas);
    std::cout << lucas.name << " is " << lucas.age << " old" << std::endl;
}

// Return as Value
Person makePerson(std::string first, std::string last, int age) {
    std::string name = first + " " + last;
    return Person{name, age};
}

void cpp_StructRetAsValue() {
	// this is uniform initialization, an effective replacement
    Person lucas = makePerson("lucas", "xu", 22);
    std::cout << lucas.name << " is " << lucas.age << std::endl;
}

// Classes

// Typically, you would separate the declaration of a class in a header(.h) file and the
// implementation in a (.cpp) file. Future work on C++ 17 introduces modules which will allow
// the declaration and implementation of a class to be united into a single file with the compiler
// being able to prduce importatble declarations into other modules.

class Message {
public:
    Message(std::string from, std::string to, std::string subj);  // constructor method
private:
    std::string from_;
    std::string to_;
    std::string subj_;
};

// Note: it would have been fine to initialize all members inside he function body
// However, some members such as const must be initialized using member initializer
Message::Message(std::string f, std::string t, std::string s)  // Method impl
: from_{f}, to_{t}, subj_{s} { // Member initializer
    std::cout << "message created" << std::endl; // Method bday
}

// Enumeration
using namspance std;
void cpp_EnumClass() {
	enum class ValType { Number, Bool, String};
	auto t = ValType::Sring;

	switch (t) {
		case ValType::Number:
		    cout << "number" << endl;
			break;
		case ValType::Bool:
		    cout << "boolean" << endl;
			break;
		case ValType::String
		    cout << "string" << endl;
			break;
	}
}

// Namespaces
#pragma once
namespace People {
	class Friend {
	public:
	    Friend(string name) : name_(name) {}
	private:
	    string name_;
	};
}

void cpp_NamespaceExplicit() {
	People::Friend kathy{"kathy Ga"}
}

void cpp_NamespaceImplicit() {
	using namespace People;
	Friend adam{"adam grey"}
}

// Exception
#include <stdexcept>
void cpp_ExceptionThrow() {
	auto x = 200;
	if (x > 20) {
		throw out_of_range("a too large");
	}
}

// common exceptions: out_of_range, std::length_error, std::bad_alloc
void cpp_ExceptionsTryCatch() {
	try {
		cpp_ExceptionsThrow();
	} catch(out_of_range) {
		cout << "exception out of range" << endl;
	}
}

void cpp_ExceptionReThrow() {
	try {
		capp_ExceptionsThrow();
	} catch(out_of_range) {
		cout << "exception out of range" << endl;
		throw;
	}
}

// Methods
class Animal {
public:
    Animal(string name, float weight): name_{name}, weight_{weight} {}
	string getName() const { return name_; }
	string getWeight() const { return to_string(weight_) + "lbs"; }
private:
    string name_;
	float weight_;
};

void cpp_Methods() {
	Animal duck("donald", 8.6};
	cout << duck.getName() << " is " << duck.getWeight() << endl;
}

// Static Methods
class Entity {
public:
    Entity(string name): name_{name} {}
	static Entity MakeAnEntity(string name);
	string name);
};

Entity Entity::MakeAnEntity(string name) {
	return Entity{"Static " + name};
}

// Static methods operate at the class level (as global functions) rather than individual obj instances
void cpp_StaticMethods() {
	auto ent = Entity::MakeAnEntity("gizmo");
	cout << ent.name_ << endl;
}

// Class Containment
struct Attachment {
	string content;
};

struct ModularMessage {
	string from;
	string to;
	Attachment attachment;
	ModularMessage(string f, string t, string c) : from{f}, to{t}, attachment{c} {}
};

void cpp_ClassContainment() {
	ModularMessage mm{"lucas", "luke", "Hi"};
	cout << mm.from << " send " << mm.attachment.content << " to " << mm.to << endl;
}

// Class Destructors
// Sometimes, classes contain values that are handles to other types of resources (files, network
// sockets, operating system bitmaps, locks ...etc). These require explicit cleanup and the class
// author needs to know when the object is being destructed so tey ca nfree or close the resources
#include <stdio.h>
class File {
public:
    File(Stirng name) {
		file_ = fopen(name.c_str(), "w");
		cout << "opened" << name << endl;
	}

	~File() {
		fclose(file_);
		cout << "closed file" << endl;
	}

private:
    FILE* file_;
};

// Destuctors are called when objects are no longer needed. If stack allocated, when the execution
// leaves the scope block. If explicitly allocated, when delete is called When using unique_ptr, when
// the owning object is destructed. When using shared_ptr, when the last reference is removed
void cpp_Destructors() {
	{   // block scoped but typically function scoped
		File f{"foo"};
	}
	cout << "the file should be closed now"} << endl;
}

// Virtual Functions and Inheritance
// Only virtual can be overridden by a subclass
// Contact is an abstract class and cannot be instantiated
struct Contact {
	Contact(string n) : name{n} {}
	virtual bool canVideoCall() { return false; };
	virtual bool canBeInGroups() = 0;
	string name;
};

struct PersonContact : public Contact {
	PersonContact(string n, string p) : Contact{n}, phone{p} {}
	virtual bool canVideoCall() override { return true; }
	virtual bool canBeInGroups() override { return true; }
	string phone;
};

struct PageContact : public Contact {
	PageContact(string n) : Contact(n) {}
	virtual bool canBeInGroups() override { return false; }
};

// Avoid multiple inheritance. Except for inheriting from pure vrtual (interface) classes
void cpp_Inheritance() {
	PersonContact lucas{"lucas", "123-456"};
	PageContact sccer{"soccer"};
	cout << lucas.name << " calls: " << lucas.canVideoCall() << " group: " << lucas.canBeInGroups() << endl;
}

// Strings
string to_lower(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::tolower);
	return s;
}
string to_upper(string s) {
	std::transform(s.begin(), s.end(), s.begin(), ::toupper);
	return s;
}

// short strings use built-in storage and are very efficient when stack allocated or contained in class
// longer strings will use heap allocated character arrays
void cpp_Strings() {
	string s = "hello";
	s += ", world";
	cout << s << endl;
	cout << s.substr(1) << endl;
	cout << s.substr(1,4) << endl;

	cout << to_lower(s) << endl;
	cout << to_upper(s) << endl;
	cout << (s == "hello, world") << endl;
}

// Vectors
// sequence of elemetns of any type, can be pre-allocated with capacity
// grows dynamically, efficient index access, efficient iterator access, expensive element removal
#include <vector>
void cpp_Vectors() {
	vector<Person> contacts = {
		{ "Lucas", 12 },
		{ "Luke", 34},
		{ "Luka", 56}
	};

	cout << contacts.size << endl;
	contacts.reserve(90); // capacity 90, size 3
	contacts.push_back({"Lukas", 78});
	cout << contacts.size() << endl; // 4
	cout << contacts[0].name << endl;
	try {
		cout << contacts.at(9).name << endl; // out of range exception
	} catch(exception e) {
		cout << "exception" << endl;
	}
	contacts.erase(contacts.begin() + 2); // remove Luka
}	

// Iterators
void cpp_Iterators() {
	vector<Person> contacts = {
		{ "Lucas", 12},
		{ "Luke", 34},
	};
	// The acutal type is vector<Person>::iterator
	for (const auto& c: contacts) {
		cout << c.name << ", " << c.age << endl; // print contact
	}
	// Avoid using [index] operators to index into the vector unless bounds checks have already been performed and you are
	// confident there are no out-of-bounds conditions. Otherwise, always use .at(index} and handle any resulting out_of_range exception
	// Always use auto& for getting a reference instead of a pointer of each element
	// Always use const auto& for getting a read only reference of each element
}

// Arrays
#include <array>

struct Node {
	array<float, 3> translation;
	array<float, 3> rotation;
	array<float, 3> scaling;

	vector<Node> children;
};

void cpp_Arrays() {
	Node n{ {1,2,3}, {4,5,6}, {7,8,9}, {} };
	cout << "x0: " << n.translation[0] << ", r1: " << n.rotation[1] << endl;
}

// Lambdas
void cpp_Lambdas() {
	auto d = 90;
	auto c = 100;

	auto no_capture = [](int z) {
		return z*3;
	};

	auto capture_all_by_ref = [&](int z) {
		d = z;
		c = z;
	};

    auto capture_one_by_ref = [&d](int z) {
		d = z * d;
	};

	auto capture_all_by_copy = [=](int z) {
		// d = z * 3;  // compile error => cannot change d
	};

	auto capture_d_by_ref_c_by_copy = [&d,c]() {
		d = c*d;
	};

	auto print_copy_captured_values = [=]() {
		std::cout << "print_copy_captured_values: d = " << d << ", c = " << std::endl;
	};
}











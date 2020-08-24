# Basic Concepts

## Constructors

Every class should have an initialization function that resets new variables before they are used.

Constructor overloading --> YOur class can have many different constructors and the only requirement is that each one has different parameters and/or types.

If you don't define any, C++ generates an implicit default constructor for you.

Reserves memory using the new command.

The auto added default constructor won't initialize your primitive member variable (int, bool, float, double, etc.).

## Destructors

Every class also has a destructor function (it may have only one of these). It is to de-initialize or destruct a class variable when it goes away.

Destructors must not have any parameters. And it looks just like a constructor function except for the tilde (~).

Destructors must not return a value either.

If you don't define your own destructor for a class, C++ will define an implicit one.

Frees the allocated memory with the delete command.

## Class Composition

Class composition is when a class contains one or more member variables that are objects.

## Composition with Initializer List

We use initializer list to initialize an embedded object. It can be also used to initialize your primitive member variables.

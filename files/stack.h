#ifndef _Stack_
#define _Stack_
#include "list.h"


namespace cop4530 {

	template <typename T>
	class Stack {
	private:
		List<T> list;
	public:
		Stack(); //defualt constructor

		~Stack(); //destructor, clears list

		Stack(const Stack& stack); //copy constructor. copies the given stack

		Stack(Stack&& stack); //move constructor. moves the data from the given stack to the new one

		Stack& operator= (const Stack& stack); //check if one stack equals another

		Stack& operator=(Stack&& stack); //move version

		bool empty() const; //checks if stack is empty

		void clear(); //clears the stack

		void push(const T& x); //pushes x to top of stack

		void push(T&& x); //move version of push

		void pop(); //discards the top item on the stack

		T& top(); //returns the top value of the stack

		const T& top() const; //const version of top

		int size() const; //returns the size

		void print(std::ostream& os, char ofc = ' ') const; //prints thge stack
	};

	template <typename T>
	std::ostream& operator<< (std::ostream& os, const Stack<T>& a); //calls the print function of the stack

	template <typename T>
	bool operator== (const Stack<T>& lhs, const Stack<T>& rhs); // checks if stacks are equal

	template <typename T>
	bool operator!= (const Stack<T>& lhs, const Stack<T>& rhs); // checks if stacks are not equal

	template <typename T>
	bool operator<= (const Stack<T>& a, const Stack<T>& b); //returns true if each data value of a is less than b

#include "stack.hpp"
}

#endif
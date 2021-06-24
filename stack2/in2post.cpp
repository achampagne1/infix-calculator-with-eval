#include "stack.h"
#include <sstream>

using namespace cop4530;

int precidence(char input) {//returns the precidence of operator (lower number is higher precidence)
	if (input == '*')
		return 0;
	if (input == '/')
		return 1;
	if (input == '+')
		return 2;
	if (input == '-')
		return 3;
}

template <typename T>
T operate(std::string operation, T a, T b) { //returns the operation done on a and b
	if (operation == "+")
		return a + b;
	if (operation == "-")
		return b - a;
	if (operation == "*")
		return a * b;
	if (operation == "/")
		return b / a;
} 

void inToPost();

int main() {
	Stack<int> stack;
	Stack<int> stack2;
	stack.push(2);
	stack2.push(3);
	std::cout << (stack <= stack2) << std::endl;
	inToPost();
	return 0;
}

void inToPost() {
	while (1) { //infinite loop unless broken out of
	top: //label to return to top
		std::string input = "";
		std::string output = "";
		Stack<std::string> operators;
		std::cout << "Enter an expression:" << std::endl;
		getline(std::cin, input);
		if (input == "end" || input == "End") //checks if input is end. breaks out of loop if so
			return;

		std::istringstream buf(input);
		for (std::string s; buf >> s; ) { //goes through ech character of string delimited by spaces
			if (s != "+" && s != "*" && s != "-" && s != "/" && s != "(" && s != ")") //checks if char is not operator
				output.append(s + " "); //appends s to output if its not an operator
			else {
				if (s == "(") //checks if char is open parenthesis
					operators.push(s); //pushes it to the stack
				else if (s == ")") { //checks if char is closing parenthesis
					while (!operators.empty() && operators.top() != "(") { //looks until stack is empty, or opening parenthesis is found
						output.append(operators.top() + " "); //appends top to output
						operators.pop(); //pops top value
					}
					if (operators.empty()) { //checks stack is empty
						std::cout << "Unbalanced parenthesis" << std::endl;
						goto top; //returns to top if an open parenthesis is found withot a closer
					}
					operators.pop(); //pops the last opening parenthesis
				}
				else if (operators.empty() || precidence(s[0]) < precidence(operators.top()[0]))  //pushes operator to stack if the precidence is lower than the top 
					operators.push(s);
				else {
					while (!operators.empty()) { //loops until operators is empty
						if (precidence(s[0]) >= precidence(operators.top()[0])) { //appends to output if presidence is higher than the top
							output.append(operators.top() + " "); 
							operators.pop();
						}
						else
							break; //breaks otherwise
					}
					operators.push(s); //pushes the operator
				}
			}
		}

		while (!operators.empty()) { //loops until stack is empty
			if (operators.top() == "(") { //checks if there are any unclosed parenthesis
				std::cout << "Unbalanced parenthesis" << std::endl;
				goto top; //jumps to top
			}
			output.append(operators.top() + " "); //appends remaining operators to output
			operators.pop();
		}
		std::cout << output << std::endl;

		bool type = 0;
		std::istringstream buf2(output);
		for (int i = 0; i < output.size(); i++) { //loops through output
			if (int(output[i]) > 64) { //breaks if variable is found
				std::cout << "Can not compute, equation has variables" << std::endl;
				goto top;
			}
			if (output[i] == '.') { //sets type to float(1) if data is float
				type = 1;
			}
		}

		Stack<std::string> stack;
		std::istringstream buf3(output);
		for (std::string s; buf3 >> s; ) { //loops through all of output
			if (s != "+" && s != "*" && s != "-" && s != "/" && s != "(" && s != ")") //checks for oeprators
				stack.push(s); //pushes to stack if not an operator
			else {
				if (type == 0) { //int stuff
					auto a = stoi(stack.top()); 
					stack.pop(); //sets a to int and pops from stack
					auto b = stoi(stack.top());
					stack.pop(); //sets b to int and pops from stack
					stack.push(std::to_string(operate(s, a, b))); //computes operation
				}
				else { //float stuff
					auto a = stof(stack.top());
					stack.pop(); //sets a to float and pops from stack
					auto b = stof(stack.top());
					stack.pop(); //sets b to float and pops from stack
					stack.push(std::to_string(operate(s, a, b))); //computes operation
				}
			}
		}
		std::cout << stack.top() << std::endl; //prints the top, which is the final value
	}
}
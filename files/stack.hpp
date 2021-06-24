

template<typename T>
cop4530::Stack<T>::Stack() {

}

template<typename T>
cop4530::Stack<T>::~Stack() {
	list.clear();
}

template<typename T>
cop4530::Stack<T>::Stack(const Stack& stack) {
	list = stack.list;
}

template<typename T>
cop4530::Stack<T>::Stack(Stack&& stack) {
	list = stack.list;
}

template<typename T>
typename cop4530::Stack<T>::Stack& cop4530::Stack<T>::operator= (const Stack& stack) {
	list = stack.list;
	return *this;
}

template<typename T>
typename cop4530::Stack<T>::Stack& cop4530::Stack<T>::operator=(Stack&& stack) {
	list = stack.list;
	return *this;
}

template<typename T>
bool cop4530::Stack<T>::empty() const {
	return list.empty();
}

template<typename T>
void cop4530::Stack<T>::clear() {
	list.clear();
}

template<typename T>
void cop4530::Stack<T>::push(const T& x) {
	list.push_front(x);
}

template<typename T>
void cop4530::Stack<T>::push(T&& x) {
	list.push_front(x);
}

template<typename T>
void cop4530::Stack<T>::pop() {
	list.pop_front();
}

template<typename T>
T& cop4530::Stack<T>::top() {
	return list.front();
}

template<typename T>
const T& cop4530::Stack<T>::top() const {
	return list.front();
}

template<typename T>
int cop4530::Stack<T>::size() const {
	return list.size() + 1;
}

template<typename T>
void cop4530::Stack<T>::print(std::ostream& os, char ofc) const {
	list.print(os, ofc);
}

template <typename T>
typename std::ostream& operator<< (std::ostream& os, const Stack<T>& a) {
	a.print(os, ' ');
}

template <typename T>
bool operator== (const Stack<T>& lhs, const Stack<T>& rhs) {
	return (lhs == rhs);
}

template <typename T>
bool operator!= (const Stack<T>& lhs, const Stack<T>& rhs) {
	return !(lhs == rhs);
}

template <typename T>
bool operator<= (const Stack<T>& a, const Stack<T>& b) {
	if (a.size() != b.size())
		return false;
	Stack<T> aCopy = a;
	Stack<T> bCopy = b;

	while (!(aCopy.empty())) {
		if (aCopy.top() > bCopy.top())
			return false;
		aCopy.pop();
		bCopy.pop();
	}

	return true;
}
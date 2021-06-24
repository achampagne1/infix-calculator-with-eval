#include <initializer_list>

template <typename T>
cop4530::List<T>::const_iterator::const_iterator() { //constructor: sets current to  nullptr
	current = nullptr;
}

template <typename T>
const T& cop4530::List<T>::const_iterator::operator*() const { //*operator: returns the data from retrieve function
	return retrieve();
}

template <typename T>
typename cop4530::List<T>::const_iterator& cop4530::List<T>::const_iterator::operator++() { //++operator: increments the iterator
	current = current->next;
	return *this;
}

template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::const_iterator::operator++(int) { //++operator: increments the iterator
	current = current->next;
	return *this;
}

template <typename T>
typename cop4530::List<T>::const_iterator& cop4530::List<T>::const_iterator::operator--() { //++operator: decrements the iterator
	current = current->prev;
}

template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::const_iterator::operator--(int) { //++operator: decrements the iterator
	current = current->prev;
}

template <typename T>
bool cop4530::List<T>::const_iterator::operator==(const const_iterator& rhs) const { //==operator: checks if the iterators are the same
	return current == rhs.current;
}

template <typename T>
bool cop4530::List<T>::const_iterator::operator!=(const const_iterator& rhs) const { //==operator: checks if the iterators are not the same
	return !(current == rhs.current);
}

template <typename T>
T& cop4530::List<T>::const_iterator::retrieve() const { //retrives: returns the data at the current node
	return current->data;
}

template <typename T>
cop4530::List<T>::const_iterator::const_iterator(Node* p) { //constructor: sets the iterator to a certain node
	current = p;
}

template <typename T>
cop4530::List<T>::iterator::iterator() { //default constructor

}

template <typename T>
T&  cop4530::List<T>::iterator::operator*() { //*operator: returns the retrieve function
	return const_iterator::retrieve();
}

template <typename T>
const T&  cop4530::List<T>::iterator::operator*() const { //*operator: returns the retrieve function
	return *const_iterator::retrieve();
}

template <typename T>
typename cop4530::List<T>::iterator&  cop4530::List<T>::iterator::operator++() { //++operator: increments the iterator
	const_iterator::current = const_iterator::current->next;
	return *this;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::iterator::operator++(int) { //++operator: increments the iterator
	const_iterator::current = const_iterator::current->next;
	return *this;
}

template <typename T>
typename cop4530::List<T>::iterator& cop4530::List<T>::iterator::operator--() { //++operator: decrements the iterator
	const_iterator::current = const_iterator::current->prev;
	return *this;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::iterator::operator--(int) { //++operator: decrements the iterator
	const_iterator::current = const_iterator::current->prev;
	return *this;
}

template <typename T>
cop4530::List<T>::iterator::iterator(Node* p) { //constructor: sets the iterator to a given node
	const_iterator::current = p;
}

template <typename T>
cop4530::List<T>::List() { //default constructor
	init();
}

template <typename T>
cop4530::List<T>::List(const List& rhs) { //constructor: sets the list to the values of another
	init();
	auto itr = rhs.begin();
	for (; itr != rhs.end(); ++itr)
		push_back(itr.current->data);
	push_back(rhs.end().current->data);
	rhs.clear();
}

template <typename T>
cop4530::List<T>::List(List&& rhs) { //constructor: sets the list to the values of another
	init();
	auto itr = rhs.begin();
	for (; itr != rhs.end(); ++itr)
		push_back(itr.current->data);
	push_back(rhs.end().current->data);
	rhs.clear();
}

// num elements with value of val
template <typename T>
cop4530::List<T>::List(int num, const T& val) { //constructor: creates a list with num nodes of val value
	init();
	for (int i = 0; i < num + 1; i++) {
		push_back(val);
	}
}

// constructs with elements [start, end)
template <typename T>
cop4530::List<T>::List(const_iterator start, const_iterator end) { //constructor: creates a list from the the given start to the given end
	init();
	auto itr = start;
	for (; itr != end; ++itr)
		push_back(itr.current->data);
	push_back(end.current->data);
}

// constructs with a copy of each of the elements in the initalizer_list
template <typename T>
cop4530::List<T>::List(std::initializer_list<T> iList) { //constructor: creates a list from the given Ilist
	init();
	for (int i = 0; i < iList.size(); i++){
		push_back(iList.begin()[i]);
	}
}

template <typename T>
cop4530::List<T>::~List() { //destructor: calls clear
	clear();
}

// copy assignment operator
template <typename T>
const cop4530::List<T>&  cop4530::List<T>::operator=(const List& rhs) { //=operator: returns the given list
	clear();
	auto itr = rhs.begin();
	for (int i = 0; i <= rhs.size(); i++) {
		push_back(*itr);
		itr++;
	}

	return *this;
}

// move assignment operator
template <typename T>
cop4530::List<T>& cop4530::List<T>::operator=(List&& rhs) { //=operator: returns the given list
	clear();
	auto itr = rhs.begin();
	for (int i = 0; i <= rhs.size(); i++) {
		push_back(*itr);
		itr++;
	}
	return *this;
}

// sets list to the elements of the initializer_list
template <typename T>
cop4530::List<T>& cop4530::List<T>::operator= (std::initializer_list<T> iList) { //=operator: returns the given Ilist
	clear();
	for (int i = 0; i < iList.size(); i++) {
		push_back(iList.begin()[i]);
	}
	return *this;
}


// member functions
template <typename T>
int cop4530::List<T>::size() const { //size: returns size
	return theSize-1;
}

template <typename T>
bool cop4530::List<T>::empty() const { //empty: checks if the size is 0
	return theSize == 0;
}

template <typename T>
void cop4530::List<T>::clear() { //clear: removes all the elements from the list and sets size to 0
	for (int i = 0; i <= theSize;i++) {
		pop_back();
	}
	theSize = 0;
}

template <typename T>
void cop4530::List<T>::reverse() { //reverse: reverses the list
	auto itr = begin();
	List<T> tempList;
	for (int i = 0; i <= theSize;i++) {
		tempList.push_front(itr.current->data);
		++itr;
	}
	clear();
	itr = tempList.begin();
	for (; itr != tempList.end(); ++itr)
		push_back(*itr);
}

template <typename T>
T& cop4530::List<T>::front() { //returns the data from the front of the list
	return head->data;
}

template <typename T>
const T& cop4530::List<T>::front() const { //returns the data from the front of the list
	return head->data;
}

template <typename T>
T& cop4530::List<T>::back() { //returns the data from the back of the list
	return tail->data;
}

template <typename T>
const T& cop4530::List<T>::back() const { //returns the data from the back of the lsit
	return tail->data;
}

template <typename T>
void cop4530::List<T>::push_front(const T& val) { //pushes a given value to the front of the list
	insert(begin(), val);
}

template <typename T>
void cop4530::List<T>::push_front(T&& val) { //pushes a given value to the front of the list
	insert(begin(), val);
}

template <typename T>
void cop4530::List<T>::push_back(const T& val) { //pushes a given value to the back of the list
	insert(end(), val);
}

template <typename T>
void cop4530::List<T>::push_back(T&& val) {  //pushes a given value to the back of the list
	insert(end(), val);
} 

template <typename T>
void cop4530::List<T>::pop_front() { //removes the front item of the list
	erase(begin());
}

template <typename T>
void cop4530::List<T>::pop_back() { //removes the last item of the list
	erase(end());
}

template <typename T>
void cop4530::List<T>::remove(const T& val) { //searches the list, and removes the node if the data matches the given value
	auto itr = begin();
	for (; itr != end(); ++itr) {
		if (itr.current->data == val) {
			erase(itr);
		}
	}
}

template <typename T>
template <typename PREDICATE>
void cop4530::List<T>::remove_if(PREDICATE pred) { //takes in an argument, and if the argument returns true for the given node, it is removed
	auto itr = begin();
	for (; itr != end(); ++itr) {
		if (pred(itr.current->data))
			erase(itr);
	}
}

template <typename T>
void cop4530::List<T>::print(std::ostream& os, char ofc) const { //prints the list
	auto itr = begin();
	for (; itr != end(); itr++) {
		os<< *itr<<" ";
	}
	os<< *end()<<std::endl;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::begin() { //returns an iterator pointing to the head of the list
	iterator itr(head);
	return itr;
}

template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::begin() const { //returns an iterator pointing to the head of the list
	iterator itr(head);
	return itr;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::end() { //returns an iterator pointing to the rear of the list
	iterator itr(tail);
	return itr;
}

template <typename T>
typename cop4530::List<T>::const_iterator cop4530::List<T>::end() const { //returns an iterator pointing to the rear of the list
	iterator itr(tail);
	return itr;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::insert(iterator itr, const T& val) { //inserts an element at a given iterator value
	Node* newNode = new Node{ val};
	if (empty()) { //checks if the list is empty
		head = newNode;
		tail = newNode;
	}
	else {
		if (itr==begin()) { //checks if the iterator is the head
			newNode->next = head;
			head->prev = newNode;
			head = newNode;
		}
		else if (itr == end()) { //checks if the iterator is the tail
			newNode->prev = tail;
			tail->next = newNode;
			tail = newNode;
		}
		else { //all of the other cases
			itr.current->next = newNode;
			itr.current->next->prev = newNode;
			newNode->prev = itr.current;
			newNode->next = itr.current->next;
		}
	}
	theSize++;
	return itr;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::insert(iterator itr, T&& val) { //inserts an element at a given iterator value
	Node newNode(val);
	if (empty()) { //makes the new node the head and tail if the lisst is empty
		tail = &newNode;
		head = tail;
		theSize++;
		return itr;
	}

	if (itr.current->prev == nullptr) {
		newNode.next=itr.current;
		itr.current->prev = &newNode;
		head = &newNode;
	}
	else if (itr.current->next == nullptr) { //checks if the item being inserted is the last item
		newNode.prev = itr.current;
		itr.current->next = &newNode;
		tail = &newNode;
	}
	else { //used for anything in between
		newNode.prev = itr.current;
		newNode.next = itr.current->next;
		itr.current->next = &newNode;
		itr.current->next->prev = &newNode;
	}
	theSize++;
	return itr;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::erase(iterator itr) { //erases the node at a given iterator
	if (empty()) //checks if empty
		return itr;

	Node* tempNode = itr.current;
	if (itr == begin()) { //checks the iterator is at the beginning
		head = tempNode->next;
	}
	else if (itr == end()) { //checks if the iterator is at the end
		tail = tempNode->prev;
	}
	else { //all other cases
		tempNode->prev->next = tempNode->next;
		tempNode->next->prev = tempNode->prev;
	}
	tempNode = nullptr;
	delete tempNode;
	theSize--;
	return itr;
}

template <typename T>
typename cop4530::List<T>::iterator cop4530::List<T>::erase(iterator start, iterator end) { //erases the elements from a start point to an end point
	auto itr = start;
	for (; itr != end; ++itr)
		erase(itr);
	return itr;
}

template <typename T>
void cop4530::List<T>::init() { //initializes values
	head = nullptr;
	tail = nullptr;
	theSize = 0;
}

template <typename T>
bool operator==(const List<T>& lhs, const List<T>& rhs) { //cheks if two lists are the same
	if (lhs.size() != rhs.size())
		return 0;

	auto itr = lhs.begin();
	auto itr2 = rhs.begin();
	for (int i = 0; i < lhs.size(); i++) {
		if (*itr != *itr2)
			return 0;
	}
	return 1;
}

template <typename T>
bool operator!=(const List<T>& lhs, const List<T>& rhs) { //checls if two lists are not the same
	return !(lhs == rhs);
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const List<T>& l) { //prints the list
	l.print(os,' ');
	return os;
}


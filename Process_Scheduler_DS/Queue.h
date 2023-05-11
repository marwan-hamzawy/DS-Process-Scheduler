#pragma once
template<typename T>
class Node1
{
private:
	T item;	// A data item (can be any complex sturcture)
	Node1<T>* next;	// Pointer to next Node1
public:

	Node1() //default constructor
	{
		next = nullptr;
	}

	Node1(T newItem) //non-default constructor
	{
		item = newItem;
		next = nullptr;

	}

	void setItem(T newItem)
	{
		item = newItem;
	} // end setItem

	void setNext(Node1<T>* nextNode1Ptr)
	{
		next = nextNode1Ptr;
	} // end setNext

	T getItem() const
	{
		return item;
	} // end getItem

	void getItem(T& temp) const
	{
		temp = item;
		return;
	} // end getItem

	Node1<T>* getNext() const
	{
		return next;
	}
}; // end Node1
template <typename T>
class Queue
{
private:
	Node1<T>* Front;
	Node1<T>* Rear;
	int Counter;		// counter variable to keep track of number of elements in queue
public:


	Queue()
	{
		Front = nullptr;
		Rear = nullptr;
		Counter = 0;
	}


	bool IsEmpty()
	{
		if (Front == nullptr && Rear == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}

	}
	void EnQueue(T item)
	{
		Node1<T>* newNode1 = new Node1<T>(item);
		newNode1->setItem(item);
		if (IsEmpty())
		{
			Front = newNode1;
			Rear = newNode1;

		}
		else
		{
			Rear->setNext(newNode1);
			Rear = newNode1;
		}
		Counter++;

	}

	T DeQueue()
	{
		if (IsEmpty())
		{
			//cout << "The Queue is Empty";
		}
		else if (Front == Rear)
		{
			T ff = Front->getItem();
			delete Front;
			Front = Rear = nullptr;
			Counter--; // decrement counter
			return ff;
		}
		else
		{
			Node1<T>* delptr = Front;
			T ff = Front->getItem();
			Front = Front->getNext();
			delete delptr;
			Counter--; // decrement counter
			return ff;
		}
	}
	void Display()
	{
		Node1<T>* temp = Front;
		while (temp != nullptr)
		{
			cout << temp->getItem() << " ";
			temp = temp->getNext();
		}
		//cout << endl;
	}
	
	
	T FRONT() {
		if (IsEmpty())
		{
			return 0;
		}
		else {
			return Front->getItem();
		}
	}

	void FRONT(T &temp)
	{
		Front->getItem(temp);
		return;
	}


	int Size() { // new function to return number of elements in queue
		return Counter;
	}
};


template <class T>
class Node
{

private:
	Node<T>* next;
	Node<T>* prev;
	T* data;

public:


	//ctor
	Node(T* _data = nullptr) : data(_data), next(nullptr), prev(nullptr)
	{
	}

	//dtor
	~Node()
	{
		delete data;
		delete next;
	}

	//setter
	void setNext(Node* _next) { next = _next; }
	void setPrev(Node* _prev) { prev = _prev; }
	void setData(T* _data) { data = _data; }


	//getter:
	T* getData() const { return data; }
	Node<T>* getNext() { return next; }
	Node<T>* getPrev() { return prev; }
	



};
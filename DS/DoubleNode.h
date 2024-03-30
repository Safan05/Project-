#ifndef _DoubleNode
#define _DoubleNode
template <typename T>
class DoubleNode
{
private:
	T item; // A data item
	DoubleNode<T>* next; // Pointer to next DoubleNode
	DoubleNode<T>* previous; //Pointer to the previous DoubleNode
public:
	DoubleNode();
	DoubleNode(const T& r_Item);
	DoubleNode(const T& r_Item, DoubleNode<T>* nextDoubleNodePtr);
	void setPrevious(DoubleNode<T>* prevDoubleNodePtr);
	void setItem(const T& r_Item);
	void setNext(DoubleNode<T>* nextDoubleNodePtr);
	T getItem() const;
	DoubleNode<T>* getNext() const;
	DoubleNode<T>* getPrevious() const;

}; // end DoubleNode
#endif

template < typename T>
DoubleNode<T>::DoubleNode()
{
	next = nullptr;
	previous = nullptr;
}

template < typename T>
DoubleNode<T>::DoubleNode(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
	previous = nullptr;
}

template < typename T>
DoubleNode<T>::DoubleNode(const T& r_Item, DoubleNode<T>* nextDoubleNodePtr)
{
	item = r_Item;
	next = nextDoubleNodePtr;
}

template<typename T>
void DoubleNode<T>::setPrevious(DoubleNode<T>* prevDoubleNodePtr)
{
	previous = prevDoubleNodePtr;
}

template < typename T>
void DoubleNode<T>::setItem(const T& r_Item)
{
	item = r_Item;
}

template < typename T>
void DoubleNode<T>::setNext(DoubleNode<T>* nextDoubleNodePtr)
{
	next = nextDoubleNodePtr;
}

template < typename T>
T DoubleNode<T>::getItem() const
{
	return item;
}

template < typename T>
DoubleNode<T>* DoubleNode<T>::getNext() const
{
	return next;
}

template<typename T>
DoubleNode<T>* DoubleNode<T>::getPrevious() const
{
	return previous;
}


#ifndef _NODE
#define _NODE
template < typename T,typename P>
class Node
{
private:
	T item; // A data item
	Node<T,P>* next; // Pointer to next node
	P Priority;
public:
	Node();
	Node(const T& r_Item);
	Node(const T& r_Item, Node<T>* nextNodePtr,P p);
	void setItem(const T& r_Item);
	void setNext(Node<T,P>* nextNodePtr);
	T getItem() const;
	P getPrior() const;
	Node<T,P>* getNext() const;
}; 
#endif

template <typename T,typename P>
Node<T,P>::Node()
{
	next = nullptr;
}

template <typename T,typename P>
Node<T,P>::Node(const T& r_Item)
{
	item = r_Item;
	next = nullptr;
}

template < typename T,typename P>
Node<T,P>::Node(const T& r_Item, Node<T,P>* nextNodePtr,P p)
{
	item = r_Item;
	next = nextNodePtr;
	Priority = p;
}
template <typename T, typename P>
void Node<T,P>::setItem(const T& r_Item)
{
	item = r_Item;
}

template <typename T,typename P>
void Node<T,P>::setNext(Node<T,P>* nextNodePtr)
{
	next = nextNodePtr;
}

template <typename T,typename P>
T Node<T,P>::getItem() const
{
	return item;
}

template<typename T, typename P>
inline P Node<T, P>::getPrior() const
{
	return Priority;
}

template <typename T, typename P>
Node<T,P>* Node<T,P>::getNext() const
{
	return next;
}

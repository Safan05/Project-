#pragma once
template <class T>
class node
{
private:
	T data;
	node* next;
public:
	T GetData()
		return data;
	node* GetNext()
		return next;
	void SetData(T d)
		data = d;
	void SetNext(Node* n)
		next = n;
};


#pragma once

template <class T>
class BSTSetNode {
	template <class U>
	friend class DoublyLinkedList;

	BSTSetNode(T aValue);
	~BSTSetNode() {};

	T myValue;
	BSTSetNode<T>* myRightNode;
	BSTSetNode<T>* myLeftNode;
};

template<class T>
inline BSTSetNode<T>::BSTSetNode(T aValue)
{
	myValue = aValue;
	myRightNode = nullptr;
	myLeftNode = nullptr;
}

template <class T>
class BSTSet
{
public:
	BSTSet();
	~BSTSet();
	//Returnerar true om elementet finns i mängden, och false annars.
	bool HasElement(const T& aValue);
	//Stoppar in elementet i mängden, om det inte redan finns där. Gör
	//ingenting annars.
	void Insert(const T& aValue);
	//Plockar bort elementet ur mängden, om det finns. Gör ingenting annars.
	void Remove(const T& aValue);
private:
	BSTSetNode<T>*myRootNode;	
};

template<class T>
inline BSTSet<T>::BSTSet()
{
	myRootNode = nullptr;
}

template<class T>
inline BSTSet<T>::~BSTSet()
{
}

template<class T>
inline bool BSTSet<T>::HasElement(const T& aValue)
{
	BSTSetNode<T>* Node = myRootNode;
	while (myRootNode)
	{

	}
	return false;
}

template<class T>
inline void BSTSet<T>::Insert(const T& aValue)
{

}

template<class T>
inline void BSTSet<T>::Remove(const T& aValue)
{
}


#pragma once

template <class T>
class BSTSetNode {
	template <class U>
	friend class BSTSet;

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
	BSTSetNode<T>* myRootNode;
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
	while (Node != nullptr)
	{
		if (!(Node->myValue < aValue) && !(aValue < Node->myValue))
		{
			return true;
		}
		else if (Node->myValue < aValue)
		{
			Node = Node->myLeftNode;
		}
		else
		{
			Node = Node->myRightNode;
		}
	}
	return false;
}

template<class T>
inline void BSTSet<T>::Insert(const T& aValue)
{
	BSTSetNode<T>* Node = myRootNode;
	while (!(Node->myValue < aValue) && !(aValue < Node->myValue))
	{
		if (Node->myValue < aValue)
		{
			if (Node->myLeftNode==nullptr)
			{
				Node->myLeftNode = new BSTSetNode<T>(aValue);
			}
			Node = Node->myLeftNode;
		}
		else if(aValue < Node->myValue)
		{
			if (Node->myLeftNode == nullptr)
			{
				Node->myLeftNode = new BSTSetNode<T>(aValue);
			}
			Node = Node->myRightNode;
		}	
	}
	
}

template<class T>
inline void BSTSet<T>::Remove(const T& aValue)
{
	while (!(Node->myValue < aValue) && !(aValue < Node->myValue))
	{

	}
}


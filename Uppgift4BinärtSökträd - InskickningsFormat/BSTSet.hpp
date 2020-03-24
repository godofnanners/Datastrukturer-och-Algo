#pragma once
namespace CommonUtilities
{
	template <class T>
	class BSTSetNode
	{
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
		//Returnerar true om elementet finns i m�ngden, och false annars.
		bool HasElement(const T& aValue);
		//Stoppar in elementet i m�ngden, om det inte redan finns d�r. G�r
		//ingenting annars.
		void Insert(const T& aValue);
		//Plockar bort elementet ur m�ngden, om det finns. G�r ingenting annars.
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
			else if (aValue < Node->myValue)
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

		if (myRootNode == nullptr)
		{
			myRootNode = new BSTSetNode<T>(aValue);
		}
		else
		{
			BSTSetNode<T>* Node = myRootNode;
			while (!(!(Node->myValue < aValue) && !(aValue < Node->myValue)))
			{
				if (aValue < Node->myValue)
				{
					if (Node->myLeftNode == nullptr)
					{
						Node->myLeftNode = new BSTSetNode<T>(aValue);
					}
					Node = Node->myLeftNode;
				}
				else if (Node->myValue < aValue)
				{
					if (Node->myRightNode == nullptr)
					{
						Node->myRightNode = new BSTSetNode<T>(aValue);
					}
					Node = Node->myRightNode;
				}
			}
		}
	}

	template<class T>
	inline void BSTSet<T>::Remove(const T& aValue)
	{
		if (myRootNode == nullptr)
			return;
		BSTSetNode<T>* prevNode = nullptr;
		BSTSetNode<T>* steppingNode = myRootNode;
		BSTSetNode<T>* removeValueNode = nullptr;
		//Find Node
		while (!(!(steppingNode->myValue < aValue) && !(aValue < steppingNode->myValue)))
		{
			if (steppingNode->myValue < aValue)
			{
				if (steppingNode->myRightNode != nullptr)
				{
					prevNode = steppingNode;
					steppingNode = steppingNode->myRightNode;
				}
				else
				{
					return;
				}
			}
			else
			{
				if (steppingNode->myLeftNode != nullptr)
				{
					prevNode = steppingNode;
					steppingNode = steppingNode->myLeftNode;
				}
				else
				{
					return;
				}
			}
		}
		removeValueNode = steppingNode;

		//Delete Node
		if (steppingNode->myLeftNode == nullptr && steppingNode->myRightNode == nullptr)
		{
			//if both nodes below are empty
			if (removeValueNode != myRootNode)
			{
				if (prevNode->myLeftNode == removeValueNode)
				{
					delete removeValueNode;
					prevNode->myLeftNode = nullptr;
				}
				else
				{
					delete removeValueNode;
					prevNode->myRightNode = nullptr;
				}
			}
			else
			{
				delete myRootNode;
				myRootNode = nullptr;
			}
		}
		else if (steppingNode->myLeftNode != nullptr && steppingNode->myRightNode == nullptr)
		{
			//if only right node is empty
			if (removeValueNode != myRootNode)
			{
				if (prevNode->myLeftNode == removeValueNode)
				{
					prevNode->myLeftNode = steppingNode->myLeftNode;
				}
				else
				{
					prevNode->myRightNode = steppingNode->myLeftNode;
				}
			}
			else
			{
				myRootNode = steppingNode->myLeftNode;
			}
			delete removeValueNode;
		}
		else if (steppingNode->myLeftNode == nullptr && steppingNode->myRightNode != nullptr)
		{
			//if only left node is empty
			if (removeValueNode != myRootNode)
			{
				if (prevNode->myLeftNode == removeValueNode)
				{
					prevNode->myLeftNode = steppingNode->myRightNode;
				}
				else
				{
					prevNode->myRightNode = steppingNode->myRightNode;
				}				
			}
			else
			{
				myRootNode = steppingNode->myRightNode;
			}
			delete removeValueNode;
		}
		else
		{
			//if both nodes are occupied

			//step right once and then find the most left node in the branch of the node that is to be deleted
			prevNode = steppingNode;
			steppingNode = steppingNode->myRightNode;

			while (steppingNode->myLeftNode != nullptr)
			{
				prevNode = steppingNode;
				steppingNode = steppingNode->myLeftNode;
			}

			removeValueNode->myValue = steppingNode->myValue;

			if (steppingNode->myRightNode != nullptr)
			{
				if (prevNode->myLeftNode == steppingNode)
				{
					prevNode->myLeftNode = steppingNode->myRightNode;
					delete steppingNode;
				}
				else
				{
					prevNode->myRightNode = steppingNode->myRightNode;
					delete steppingNode;
				}				
			}
			else
			{
				if (prevNode->myLeftNode == steppingNode)
				{
					delete steppingNode;
					prevNode->myLeftNode = nullptr;
				}
				else
				{
					delete steppingNode;
					prevNode->myRightNode = nullptr;
				}
			}
		}
	}
}



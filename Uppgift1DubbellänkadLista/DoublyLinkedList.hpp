#pragma once
namespace CommonUtilities
{
	template <class T>
	class DoublyLinkedList
	{
	public:
		// Skapar en tom lista
		DoublyLinkedList();
		// Frig�r allt minne som listan allokerat
		~DoublyLinkedList();
		// Returnerar antalet element i listan
		int GetSize() const;
		// Returnerar f�rsta noden i listan, eller nullptr om listan �r tom
		DoublyLinkedListNode<T>* GetFirst();
		// Returnerar sista noden i listan, eller nullptr om listan �r tom
		DoublyLinkedListNode<T>* GetLast();
		// Skjuter in ett nytt element f�rst i listan
		void InsertFirst(const T& aValue);
		// Skjuter in ett nytt element sist i listan
		void InsertLast(const T& aValue);
		// Skjuter in ett nytt element innan aNode
		void InsertBefore(DoublyLinkedListNode<T>* aNode, const T& aValue);
		// Skjuter in ett nytt element efter aNode
		void InsertAfter(DoublyLinkedListNode<T>* aNode, const T& aValue);
		// Plockar bort noden ur listan och frig�r minne. (Det �r ok att anta att
		// aNode �r en nod i listan, och inte fr�n en annan lista)
		void Remove(DoublyLinkedListNode<T>* aNode);
		// Hittar f�rsta elementet i listan som har ett visst v�rde. J�mf�relsen
		// g�rs med operator==. Om inget element hittas returneras nullptr.
		DoublyLinkedListNode<T>* FindFirst(const T& aValue);
		// Hittar sista elementet i listan som har ett visst v�rde. J�mf�relsen
		// g�rs med operator==. Om inget element hittas returneras nullptr.
		DoublyLinkedListNode<T>* FindLast(const T& aValue);
		// Plockar bort f�rsta elementet i listan som har ett visst v�rde.
		// J�mf�relsen g�rs med operator==. Om inget element hittas g�rs ingenting.
		// Returnerar true om ett element plockades bort, och false annars.
		bool RemoveFirst(const T& aValue);
		// Plockar bort sista elementet i listan som har ett visst v�rde.
		// J�mf�relsen g�rs med operator==. Om inget element hittas g�rs ingenting.
		// Returnerar true om ett element plockades bort, och false annars.
		bool RemoveLast(const T& aValue);

	};

}
#pragma once
template<class T>
class Heap
{
public:
	int GetSize() const; //returnerar antal element i heapen
	void Enqueue(const T& aElement);	  //l�gger till elementet i heapen
	const T& GetTop() const;	  //returnerar det st�rsta elementet i heapen
	T Dequeue(); 	  //tar bort det st�rsta elementet ur heapen och returnerar det
private:
};

template<class T>
inline int Heap<T>::GetSize() const
{
	return 0;
}

template<class T>
inline void Heap<T>::Enqueue(const T& aElement)
{
}

template<class T>
inline const T& Heap<T>::GetTop() const
{
	// TODO: insert return statement here
}

template<class T>
inline T Heap<T>::Dequeue()
{
	return T();
}

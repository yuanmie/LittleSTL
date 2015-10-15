#ifndef _VECTOR_H
#define _VECTOR_H
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <memory>




template <class T>
class vector
{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector(): elements(0), first_free(0), end(0) { }
		vector( vector&);
		vector(iterator b, iterator e);
		//vector(int n, T& t);
		//vector(int n);

		void push_back(const T&);
		void erase(iterator p);
		void erase(iterator b, iterator e);
		void reserve(std::size_t size);
		void resize(std::size_t size);
		void clear();
		std::ptrdiff_t size() { return first_free - elements; }
		std::ptrdiff_t capacity() { return end - elements; }
		iterator begin() { return elements; }
		iterator End() { return elements + size(); }
		const_iterator const begin() const { return elements; }
		const_iterator const End() const { return elements + size(); }
		
		T& operator[](std::size_t index);
		const T& operator[](std::size_t index) const;
	
	private:
		static std::allocator<T> alloc;
		void reallocate();
		T* elements;
		T* first_free;
		T* end;
};

template <class T>
std::allocator<T> vector<T>::alloc;

template <class T>
vector<T>::vector(vector<T>& v)
{
	std::ptrdiff_t cap = v.capacity();
	elements = alloc.allocate(cap);
	std::uninitialized_copy(v.elements, v.end, elements);
	first_free = elements + v.size();
	end = elements + cap;	
	
}

template <class T>
vector<T>::vector(iterator b, iterator e)
{
	std::ptrdiff_t gap = e - b + 1;
	std::ptrdiff_t cap = gap * 2;
	elements = alloc.allocate(cap);
	std::uninitialized_copy(b, e, elements);
	first_free = elements + gap;
	end = elements + cap;
}
/* error 
template <class T>
vector<T>::vector(int n , T& t)
{
	std::size_t cap = n * 2;
	elements = alloc.allocate(cap);
	std::uninitialized_fill(elements, elements + n, t);
	first_free = elements + n;
	end = elements + cap;
}

template <class T>
vector<T>::vector(int n)
{
	T t;
	vector<T>(n, t);
}
*/

template <class T>
void vector<T>::push_back(const T& t)
{
	if (first_free == end)
		reallocate();

	alloc.construct(first_free, t);
	++first_free;
}

template <class T>
void vector<T>::erase(iterator p)
{
	std::ptrdiff_t index = p - elements;
	std::ptrdiff_t s = size();
	std::ptrdiff_t cap = capacity();
	T* newelements = alloc.allocate(cap);
	std::uninitialized_copy(elements, p , newelements);
	std::uninitialized_copy((p + 1), end, newelements + index);
	clear();
	elements = newelements;
	first_free = elements + s - 1;
	end = elements + cap;
}

template <class T>
void vector<T>::erase(iterator b, iterator e)
{
	std::ptrdiff_t gap = e - b + 1;
	std::ptrdiff_t index = b - elements;
	std::ptrdiff_t s = size();
	std::ptrdiff_t cap = capacity();
	T* newelements = alloc.allocate(cap);
	std::uninitialized_copy(elements, b , newelements);
	std::uninitialized_copy(e + 1 , end, newelements + index);
	clear();
	elements = newelements;
	first_free = elements + s - gap;
	end = elements + cap;
}
	
template <class T>
void vector<T>::clear()
{
	for (T* p = first_free; p != elements;)
		alloc.destroy(--p);
}

template <class T>
void vector<T>::reallocate()
{
	std::ptrdiff_t size = first_free - elements;
	std::ptrdiff_t newcapacity = 2 * std::max(size, 1l);

	//allocate space to hold newcapacity number of elements of type T
	T* newelements = alloc.allocate(newcapacity);

	//construct copies of the existing elements in  the new space
	std::uninitialized_copy(elements, first_free, newelements);

	for (T *p = first_free; p != elements;)
		alloc.destroy(--p);

	if (elements)
		alloc.deallocate(elements, end - elements);

	elements = newelements;
	first_free = elements + size;
	end = elements + newcapacity;
} 

template <class T>
T& vector<T>::operator[](std::size_t index)
{
	return *(elements + index);
}

template <class T>
void vector<T>::reserve(std::size_t Size)
{
	std::ptrdiff_t s = size();
	if (Size < (end - elements) )
		throw std::runtime_error("size is two small!");

	std::size_t newcapacity = Size;
	
	T* newelements = alloc.allocate(newcapacity);

	std::uninitialized_copy(elements, first_free, newelements);

	for (T *p = first_free; p != elements;)
		alloc.destroy(--p);

	elements = newelements;
	first_free = elements + s;
	end = elements + newcapacity;
}

template <class T>
void vector<T>::resize(size_t Size)
{
	if (Size > size())
		return ;

	for (T *p = first_free; p != (elements + Size);)
		alloc.destroy(--p);

	first_free = elements + Size;
}
#endif

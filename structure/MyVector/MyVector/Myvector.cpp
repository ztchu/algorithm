#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class MyVector
{
public:
	explicit MyVector(int size);
	MyVector(const MyVector &vec);
	~MyVector();
	
	const MyVector &operator= (const MyVector &vec);
	void Resize(int size);
	void Reserve(int cap);
	T &operator[] (int index);
	
	void Push_back(const T &val);
	void Pop_back();
	const T &Back();
	
	size_t Size() const;
	size_t Capacity() const;
	bool Empty() const;
	void Clear() ;
	
	typedef T* iterator ;
	typedef const T* const_iterator;
	
	iterator begin();
	const_iterator begin() const;
	iterator end();
	const_iterator end() const;
	
	enum {
		SPARE_CAPACITY = 16
	};
	
private:
	size_t m_theSize;
	size_t m_capacity;
	T *m_pVec;	
};

template <typename T>
MyVector<T>::MyVector(int size):m_theSize(size), m_capacity(size + SPARE_CAPACITY)
{
	m_pVec = new T[m_capacity];
}       
template <typename T>           
MyVector<T>::MyVector(const MyVector &vec)
{
	m_theSize = vec.Size();
	m_capacity = vec.Capacity();
	m_pVec = new T[m_capacity];
	for (int i = 0; i < m_theSize; ++i)
	{
		m_pVec[i] = vec.m_pVec[i];
	}
} 
template <typename T>               
MyVector<T>::~MyVector()
{
	delete [] m_pVec;
}                                   
template <typename T>                                               
const MyVector<T> &MyVector<T>::operator= (const MyVector &vec)
{
	if (this != &vec)
	{
		MyVector temp(vec);
		swap(m_pVec, temp.m_pVec);
	}
	
	return *this;
}
template <typename T>
void MyVector<T>::Resize(int size)
{
	if (size > m_capacity)
	{
		Reserve( 2 * size + 1);
	}
	m_theSize = size;
} 
template <typename T>                     
void MyVector<T>::Reserve(int cap)
{
	if (cap < m_theSize)
	{
		return;
	}
	
	
	T *p = new T[cap];
	if (p != NULL)
	{
		for (int i = 0; i < m_theSize; ++i)	
		{
			p[i] = m_pVec[i];
		}
		m_capacity = cap;
		
		delete [] m_pVec;
		m_pVec = p;
	}
	
} 
template <typename T>                     
T &MyVector<T>::operator[] (int index)
{
	return m_pVec[index];
}                     
template <typename T>                                               
void MyVector<T>::Push_back(const T &val)
{
	if (m_theSize >= m_capacity)
	{
		Reserve(m_capacity * 2 + 1);
	}
	
	m_pVec[m_theSize++] = val;	
}  
template <typename T>               
void MyVector<T>::Pop_back()
{
	--m_theSize;
} 
template <typename T>                              
const T &MyVector<T>::Back()
{
	return m_pVec[m_theSize - 1];
}                               
template <typename T>                                               
size_t MyVector<T>::Size() const
{
	return m_theSize;
} 
template <typename T>                          
size_t MyVector<T>::Capacity() const
{
	return m_capacity;
}  
template <typename T>                     
bool MyVector<T>::Empty() const
{
	if (m_theSize == 0)
	{
		return true;
	}
	return false;
} 
template <typename T>                           
void MyVector<T>::Clear()
{                               
 	delete [] m_pVec;
 	m_pVec = NULL;
}
template <typename T>
typename MyVector<T>::iterator MyVector<T>::begin()
{
	return &m_pVec[0];
}   
template <typename T>        
typename MyVector<T>::const_iterator MyVector<T>::begin() const
{
	return &m_pVec[0];
}
template <typename T>
typename MyVector<T>::iterator MyVector<T>::end()
{
	return &m_pVec[m_theSize];
}   
template <typename T>        
typename MyVector<T>::const_iterator MyVector<T>::end() const
{
	return &m_pVec[m_theSize];
}

int main()
{
	MyVector<int> vec(10);
	MyVector<int> v(vec);
	
	cout << v.Size() << endl;
	
	
	for (int i = 0; i < 10; ++i)
	{
		//vec.Push_back(i + 1);
		vec[i] = i + 1;
	}
	vec.Pop_back();
	
	MyVector<int>::iterator iter = vec.begin();
	for (; iter != vec.end(); ++iter)
	{
		cout << *iter << endl;
	}
	
	cout << vec.Size() << endl;
	cout << vec.Capacity() << endl;
}
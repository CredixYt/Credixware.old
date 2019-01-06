// Author: Valve Corporation
// Licence: https://github.com/ValveSoftware/source-sdk-2013/blob/master/LICENSE
#ifndef UTLVECTOR_H
#define UTLVECTOR_H

template< class T, class I = int >
class CUtlMemory
{
public:
	CUtlMemory(int nGrowSize = 0, int nInitSize = 0);
	CUtlMemory(T* pMemory, int numElements);
	CUtlMemory(const T* pMemory, int numElements);
	~CUtlMemory();
	void Init(int nGrowSize = 0, int nInitSize = 0);
	class Iterator_t
	{
	public:
		Iterator_t(I i) : index(i) {}
		I index;

		bool operator==(const Iterator_t it) const { return index == it.index; }
		bool operator!=(const Iterator_t it) const { return index != it.index; }
	};
	Iterator_t First() const { return Iterator_t(IsIdxValid(0) ? 0 : InvalidIndex()); }
	Iterator_t Next(const Iterator_t &it) const { return Iterator_t(IsIdxValid(it.index + 1) ? it.index + 1 : InvalidIndex()); }
	I GetIndex(const Iterator_t &it) const { return it.index; }
	bool IsIdxAfter(I i, const Iterator_t &it) const { return i > it.index; }
	bool IsValidIterator(const Iterator_t &it) const { return IsIdxValid(it.index); }
	Iterator_t InvalidIterator() const { return Iterator_t(InvalidIndex()); }
	T& operator[](I i);
	const T& operator[](I i) const;
	T& Element(I i);
	const T& Element(I i) const;
	bool IsIdxValid(I i) const;
	static I InvalidIndex() { return -1; }
	T* Base();
	const T* Base() const;
	void SetExternalBuffer(T* pMemory, int numElements);
	void SetExternalBuffer(const T* pMemory, int numElements);
	void AssumeMemory(T *pMemory, int nSize);
	void Swap(CUtlMemory< T, I > &mem);
	void ConvertToGrowableMemory(int nGrowSize);
	int NumAllocated() const;
	int Count() const;
	void Grow(int num = 1);
	void EnsureCapacity(int num);
	void Purge();
	void Purge(int numElements);
	bool IsExternallyAllocated() const;
	bool IsReadOnly() const;
	void SetGrowSize(int size);
protected:
	void ValidateGrowSize()
	{

	}
	enum
	{
		EXTERNAL_BUFFER_MARKER = -1,
		EXTERNAL_CONST_BUFFER_MARKER = -2,
	};
	T* m_pMemory;
	int m_nAllocationCount;
	int m_nGrowSize;
};


template< class T, class A = CUtlMemory<T> >
class CUtlVector
{
	typedef A CAllocator;
public:
	typedef T ElemType_t;
	typedef T* iterator;
	typedef const T* const_iterator;
	explicit CUtlVector(int growSize = 0, int initSize = 0);
	explicit CUtlVector(T* pMemory, int allocationCount, int numElements = 0);
	~CUtlVector();
	CUtlVector<T, A>& operator=(const CUtlVector<T, A> &other);
	T& operator[](int i);
	const T& operator[](int i) const;
	T& Element(int i);
	const T& Element(int i) const;
	T& Head();
	const T& Head() const;
	T& Tail();
	const T& Tail() const;
	T& Random();
	const T& Random() const;
	iterator begin() { return Base(); }
	const_iterator begin() const { return Base(); }
	iterator end() { return Base() + Count(); }
	const_iterator end() const { return Base() + Count(); }
	T* Base() { return m_Memory.Base(); }
	const T* Base() const { return m_Memory.Base(); }
	int Count() const;
	int Size() const;
	inline bool IsEmpty(void) const
	{
		return (Count() == 0);
	}
	bool IsValidIndex(int i) const;
	static int InvalidIndex();
	int AddToHead();
	int AddToTail();
	int InsertBefore(int elem);
	int InsertAfter(int elem);
	int AddToHead(const T& src);
	int AddToTail(const T& src);
	int InsertBefore(int elem, const T& src);
	int InsertAfter(int elem, const T& src);
	int AddMultipleToHead(int num);
	int AddMultipleToTail(int num, const T *pToCopy = NULL);
	int InsertMultipleBefore(int elem, int num, const T *pToCopy = NULL);
	int InsertMultipleAfter(int elem, int num);
	void SetSize(int size);
	void SetCount(int count);
	void SetCountNonDestructively(int count);
	void CopyArray(const T *pArray, int size);
	void Swap(CUtlVector< T, A > &vec);
	int AddVectorToTail(CUtlVector<T, A> const &src);
	int Find(const T& src) const;
	bool HasElement(const T& src) const;
	void EnsureCapacity(int num);
	void EnsureCount(int num);
	void FastRemove(int elem);
	void Remove(int elem);
	bool FindAndRemove(const T& src);
	bool FindAndFastRemove(const T& src);
	void RemoveMultiple(int elem, int num);
	void RemoveMultipleFromHead(int num);
	void RemoveMultipleFromTail(int num);
	void RemoveAll();
	void Purge();
	void PurgeAndDeleteElements();
	void Compact();
	void SetGrowSize(int size) { m_Memory.SetGrowSize(size); }
	int NumAllocated() const;
	void Sort(int(__cdecl *pfnCompare)(const T *, const T *));
	void Shuffle(class IUniformRandomStream* pSteam = NULL);
protected:
	void GrowVector(int num = 1);
	void ShiftElementsRight(int elem, int num = 1);
	void ShiftElementsLeft(int elem, int num = 1);
	CAllocator m_Memory;
	int m_Size;
	T *m_pElements;
	inline void ResetDbgInfo()
	{
		m_pElements = Base();
	}
private:
	CUtlVector(CUtlVector const& vec);
};

#endif
#pragma once

template<class ContainerType,typename ElementType>
class TIndexedContainerIterator
{
public:
	typedef TIndexedContainerIterator<ContainerType, ElementType> TIterator;

	//构造
	TIndexedContainerIterator(ContainerType &InContainer,int InIndex = 0)
		:Container(InContainer)
		,Index(InIndex)
	{}

	//
	TIndexedContainerIterator(const TIterator &InIterator)
		:Container(InIterator.Container)
		, Index(InIterator.Index)
	{}

//	for (; It != AAA.End();) {}
	bool operator!=(const TIterator& InIterator)
	{
		return Container[Index] != InIterator.Container[InIterator.Index];
	}

	TIterator& operator++(int)
	{
		++Index;
		return *this;
	}

	TIterator& operator--(int)
	{
		--Index;
		return *this;
	}

	//auto dd = TArray<int>::i
	TIterator &operator=(const TIterator& InIterator)
	{
		Index = InIterator.Index;
		Container = InIterator.Container;

		return *this;
	}

	ElementType& operator*()
	{
		return *Container[Index];
	}

protected:
	ContainerType& Container;
	int Index;
};

template<typename ElementType>
class TArray
{
public:
	typedef TIndexedContainerIterator<TArray<ElementType>, ElementType> TIterator;

	TArray()
		:Data(nullptr)
		,Size(0)
		,Allocation(10)
	{
		Data = (ElementType**)malloc(sizeof(int) * Allocation);//分配下标
		memset(Data, 0, sizeof(int) * Allocation);
		for (int i = 0;i < Allocation;i++)
		{
			Data[i] = (ElementType*)malloc(sizeof(ElementType));
			memset(Data[i], 0, sizeof(ElementType));
		}
	}

	int Num()
	{
		return Size;
	}
	
	void Add(ElementType&& InType)
	{
		Add(InType);
	}

	void Add(ElementType &InType)
	{
		if (Size >= Allocation)
		{
			//内存不够了 不够就分配		
			int LastAllocation = Allocation;
			Allocation += 10;
			Data = (ElementType**)realloc(Data, sizeof(int) * Allocation);
			for (int i = LastAllocation; i < Allocation; i++)
			{
				Data[i] = (ElementType*)malloc(sizeof(ElementType));
				memset(Data[i], 0, sizeof(ElementType));
			}
		}
		memcpy(Data[Size], &InType, sizeof(ElementType));
		Size++;
	}

	void RemoveAt(int Index)
	{
		for (int i = Index + 1; i <= Size;i++)
		{
			memcpy(Data[i - 1], Data[i], sizeof(ElementType));
		}

		memset(Data[Size], 0, sizeof(ElementType));
	
		Size--;
	}

	ElementType *operator[](int Index)
	{
		return Data[Index];
	}

	TIterator Begin()
	{
		return TIterator(*this,0);
	}

	TIterator End()
	{
		return TIterator(*this, Size);
	}

	~TArray()
	{
		for (int i = 0 ;i < Allocation;i++)
		{
			free(Data[i]);
		}

		free(Data);
	}

protected:
	ElementType** Data;
	int Size;
	int Allocation;
};
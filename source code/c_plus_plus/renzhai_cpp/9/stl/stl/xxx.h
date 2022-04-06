#pragma once

template<typename InElementType> class TArray;

template<typename ContainerType, typename ElementType>
class TIndexedContainerIterator
{
public:
	typedef TIndexedContainerIterator<ContainerType, ElementType> TIterator;

	TIndexedContainerIterator(ContainerType& InContainer, int InIndex = 0)
		:Container(InContainer)
		, Index(InIndex)
	{}

	TIndexedContainerIterator(const TIterator& Iterator)
		:Container(Iterator.Container)
		, Index(Iterator.Index)
	{}

	bool operator!=(const TIterator& InContainer)
	{
		return Container[Index] != InContainer.Container[InContainer.Index];
	}

	TIterator& operator++(int)
	{
		++Index;
		return *this;
	}

	TIterator& operator=(const TIterator& InIterator)
	{
		this->Index = InIterator.Index;
		this->Container = InIterator.Container;

		return *this;
	}

	TIterator& operator--(int)
	{
		--Index;
		return *this;
	}

	ElementType& operator*()
	{
		return *Container[Index];
	}

	int GetIndex()
	{
		return Index;
	}

	int SetToEnd()
	{
		Index = Container.Num();
	}

protected:
	ContainerType& Container;
	int Index;
};

template<typename InElementType>
class TArray
{
public:
	typedef TIndexedContainerIterator<TArray<InElementType>, InElementType> TIterator;

	TArray()
		:Data(nullptr)
		, Size(0)
		, Allocation(10)
	{
		Data = (InElementType**)malloc(sizeof(int) * Allocation);
		for (int i = 0; i < Allocation; i++)
		{
			Data[i] = (InElementType*)malloc(sizeof(InElementType));
		}
	}

	~TArray()
	{
		for (int i = 0; i < Allocation; i++)
		{
			free(Data[i]);
		}

		free(Data);
	}

	TIterator Begin()
	{
		TIterator Iterator(*this, 0);
		return Iterator;
	}

	TIterator End()
	{
		TIterator Iterator(*this, Num());
		return Iterator;
	}

	int Add(InElementType& InType)
	{
		if (Size >= Allocation)
		{
			int LastAllocation = Allocation;
			Allocation *= 2;
			Data = (InElementType**)realloc(Data, sizeof(int) * Allocation);
			for (int i = LastAllocation; i < Allocation; i++)
			{
				Data[i] = (InElementType*)realloc(Data[i], sizeof(InElementType));
			}
		}

		memcpy(Data[Size], &InType, sizeof(InElementType));
		Size++;

		return Size;
	}

	int Num()
	{
		return Size;
	}

	void RemoveAt(int Index)
	{
		for (int i = Index + 1; i <= Size; i++)
		{
			memcpy(Data[i - 1], Data[i], sizeof(InElementType));
		}
		memset(&Data[Size], 0, sizeof(InElementType));

		Size--;
	}

	InElementType* operator[](int Index)
	{
		return Data[Index];
	}

private:
	InElementType** Data;
	int Size;
	int Allocation;
};

int main()
{
	struct FTestA
	{
		FTestA() {}
		FTestA(int InA)
			:a(InA)
		{

		}

		bool operator!=(const FTestA& A)
		{
			return A.a != a;
		}

		int GetA() const
		{
			return a;
		}
	protected:
		int a;
	};
	TArray<FTestA> AAA;
	FTestA cc(100);
	AAA.Add(cc);
	FTestA cc1(1001);
	AAA.Add(cc1);
	FTestA cc3(1003);
	AAA.Add(cc3);
	FTestA cc4(1004);
	AAA.Add(cc4);

	AAA.RemoveAt(2);

	for (int i = 0; i < AAA.Num(); i++)
	{
		cout << AAA[i]->GetA() << endl;
	}

	for (TArray<FTestA>::TIterator It = AAA.Begin(); It != AAA.End(); It++)
	{
		cout << (*It).GetA() << endl;
	}

	return 0;
}
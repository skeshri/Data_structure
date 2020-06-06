
/*
Impementing inbuilt Array as DS with more features:

-- empty list has size 0.
-- insert element at given position: O(n)
-- remove element at given position: O(n)
-- count number of elements: 
-- Read/Modify element at given position: O(1)
-- Specify data-type
(remaining) -- Increase the size of array when full. O(n) ?? 

*/

#include <iostream>

using namespace std;


template <typename T>
class DS_Array
{
private:
	static const unsigned int MAXSIZE=10; // Maximum size considered.
	//int size = MAXSIZE;
	int end=-1;  // increment for each element inserted.
	T *A = new T[MAXSIZE]; // Allocating memory on heap and retrun address to "A".
public:
	void Init();// Initializing array.
	void Insert(T element); // Insert element at the end.
	void Insert(T element, int index); // Insert element at a given position.
	T Remove(int index); // remove element at given index and return the removed element.
	int GetSize() const; // Get the size. It counts how many time insert method is called.
	T GetElementAt(int index) const; // Access element at the given index.
	void ModifyElementAt(int index, T element); // Modify the existing element. 
	~DS_Array()
	{
		delete[] A; // Free the memeory allocated on heap.
	}
};

template <typename T>
void DS_Array<T>::Init()
{
	for (int i = 0; i < MAXSIZE; i++)
	{
		A[i] = 0;
	}
}

template <typename T>
void DS_Array<T>::Insert(T element)
{
	end++;
	A[end] = element;
}

template <typename T>
void DS_Array<T>::Insert(T element, int index)
{
	if(index == end)
	{
		end++;
		A[index] = element;
	}
	else
	{
		T B[end+1];
		for(int i=0; i<end+1; i++)
		{
			B[i] = A[i];
		}
		if(index == 0)
		{
			end++;
		    for(int i=0; i<end+1; i++)
		    {
		  	    if(i == index) A[i] = element;
			    else A[i] = B[i-1];
		    }
		}
		else
		{
			end++;
			for(int i=0; i<end+1; i++)
			{
				if(i < index) A[i] = B[i];
				else if(i > index) A[i] = B[i-1];
				else A[i] = element;
			}

		}
	}
}

template <typename T>
T DS_Array<T>::Remove(int index)
{
	T element;
	if(index == end)
	{
		end--;
		element = A[index];
		return element;
	}
	else
	{
		T B[end+1];
		for(int i=0; i<end+1; i++)
		{
			B[i] = A[i];
		}
		if(index == 0)
		{
			end--;
			element = A[index];
		    for(int i=0; i<end+1; i++)
		    {
		  	    A[i] = B[i+1];
		    }
		    return element;
		}
		else
		{
			end--;
			for(int i=0; i<end+1; i++)
			{
				if(i < index) A[i] = B[i];
				else
				{
					if(i == index)
					{
						element = A[i];
					}
					A[i] = B[i+1];
				}
			}
			return element;
		}
	}
}

template <typename T>
int DS_Array<T>::GetSize() const
{
	return end+1;
}

template <typename T>
T DS_Array<T>::GetElementAt(int index) const
{
	// trying to do some experimantation with exception handling. Will improve later.
	try
	{
		if(end == -1)
		{
			throw "A[i] is empty. Please insert the elements first.";
		}
	}
	catch(const char* exception)
	{
		cout<<"[line:"<<__LINE__<<"]: "<<exception<<endl;
		exit(0);
	}
	return A[index];
}

template <typename T>
void DS_Array<T>::ModifyElementAt(int index, T element)
{
	A[index] = element;
}

int main()
{
	DS_Array<float> a;
	a.Init();
//	cout<<a.GetElementAt(2)<<endl;
	a.Insert(1);
	a.Insert(2);
	a.Insert(3);
	cout<<"size of the array: "<<a.GetSize()<<endl;
	a.ModifyElementAt(1,10);
//	a.Insert(3,0);
//	a.Insert(10, 2);
//	cout<<"removed : "<<a.Remove(1)<<endl;
//	cout<<"removed : "<<a.Remove(1)<<endl;
//	a.WriteElementAt(0, 1000);

	for(int i=0; i< a.GetSize(); i++)
	{
		cout<<a.GetElementAt(i)<<endl;
	}

}
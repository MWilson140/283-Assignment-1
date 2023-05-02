//add eetsize

#ifndef VECTOR_H_INCLUDED
#define VECTOR_H_INCLUDED

    /**
     * @class Vector
     * @brief Minimal vector class.
     * @author Mitchell Wilson - 34497163
     */
template <class T>
class Vector
{
public:
        /**
        *@brief vector assignment operator
        *Copies arrays over, moves the pointer to new array, deletes old array, copies variables.
        *@param two vectors
        */
    Vector & operator = (const Vector & t)
    {
        delete[] (this->Array);
        this->Size = t.Size;
        this->Length = t.Length;
        this->Array = new T[t.Length];
        for (int i = 0; i < t.Length;i++)
			this->Array[i] = t.Array[i];

		return *this;
    }
        /**
         * @brief square bracket operator
         * @param int n - index location
         * @return returns the array at index n
         * @pre n needs to be in bounds
         */
    T & operator [](int n) const //error check???????
    {
        if (n > Length-1 || n < 0)
            throw "Vector out of bounds";

        return this->Array[n];
    }

    Vector();
    ~Vector();
    Vector(int n);
    Vector(const Vector & t);

        /**
         * @brief Adds to the vector
         * @param t - an object of the class
         * @return void
         */
    void AddTo(T t); //needs to be &??
        /**
         * @brief Getter for size
         * @return int - value of size
         */
    int GetSize() const;
        /**
         * @brief Getter for length
         * @return int - value of length
         */
    int GetLength() const;
        /*/**
         * @brief Deletes entry at location n
         * @param int n - location of index to be deleted
         * @return void
         * @pre n must be in bounds
    void DeleteAt(int n);*/
        /**
         * @brief Empties the array
         * @return void
         */
    void Empty();
        /**
         * @brief increases the size of the vector
         * @return void
         * @pre n must be larger than length
         */
    void SetSize(int n);

private:
    T* Array;
    int Length; //used slots
    int Size; //total slots
        /**
         * @brief increases the size of the vector
         * Increases the size of the vector and copies the entries over
         * @return T*
         */
    T* Expand();
};

template<class T>
Vector<T>::Vector()
{
    Size = 1;
    Length = 0;
    Array = new T[Size];
}

template<class T>
Vector<T>::Vector(int n)
{
    if (n < 1)
        throw "must be more than 0";
    Length = 0;
    Size = n;
    Array = new T[Size];
}

template<class T>
Vector<T>::Vector(const Vector & t)
{
    this->Size = t.Size;
    this->Array = new T[t.Length];
    for (int i = 0; i < t.Length;i++)
    {
        this->Array[i]=t.Array[i];
    }
    this->Length = t.Length;
}

template<class T>
Vector<T>::~Vector()
{
    delete[] this->Array;
}

template <class T> //needs to be &??
void Vector<T>::AddTo(T t)
{
    if (this->Size <= this->Length)
    {
        this->Expand();
    }
    this->Array[Length] = t;
    this->Length++;
}

template <class T>
T* Vector<T>::Expand()
{
    this->Size *= 2; //increase size
    T* Temp = new T[this->Size];
    for(int i = 0; i < this->Length;i++)
    {
        Temp[i] = this->Array[i];
    }
    delete [] this->Array;
    this->Array = Temp;
    return this->Array;
}
template <class T>
int Vector<T>::GetSize() const
{
    return this->Size;
}
/* No longer used
template <class T>
void Vector<T>::DeleteAt(int n)
{
    this->Length--;
    for (int i = n-1; i<Length;i++)
    {
        this->Array[i] = this->Array[i+1];
    }
}*/

template <class T>
int Vector<T>::GetLength() const
{
    return Length;
}
template <class T>
void Vector<T>::Empty()
{
    delete[] this->Array;
    Length = 0;
    Size = 1;
    Array = new T[Size];

}

template <class T>
void Vector<T>::SetSize(int n)
{
    if (n < this->Length)
        throw "must be larger than the length";
    this-> Size = n;
    T* temp = new T[Size];
    for (int i = 0; this->Length; i++)
        temp[i] = this->Array[i];
    delete[] this->Array;
    this->Array = temp;
}
#endif // VECTOR_H_INCLUDED

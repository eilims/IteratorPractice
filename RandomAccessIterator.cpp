template <class T>
class RandomAccessIterator : public std::iterator<std::random_access_iterator_tag, T>
{
public:
    RandomAccessIterator(uint32_t index, LinkedNodeInterface<T>*** listReference)
    {
        this->index = index;
        this->objectReference = (*listReference)[index];
        this->listReference = listReference;
    }

    RandomAccessIterator(bool isStart, uint32_t size, LinkedNodeInterface<T>* obj) : objectReference(obj)
    {
        this->index = (isStart) ? 0 : size;
        this->oglistReference = new LinkedNodeInterface<T>*[size+1];
        this->listReference = &this->oglistReference;
        LinkedNodeInterface<T>* currentNode = obj;
        for(uint32_t index = 0; index < size+1; index++)
        {
            if(isStart)
            {
                (*listReference)[index] = currentNode;
                currentNode = currentNode->GetNext();
            }
            else
            {
                (*listReference)[size - index] = currentNode;
                currentNode = currentNode->GetPrevious();
            }
        }
    }

    // Copy constructor
    RandomAccessIterator(const RandomAccessIterator& other) 
    : index(other.index), listReference(other.listReference), objectReference(other.objectReference) {}

    // Copy assignable
    RandomAccessIterator& operator=(RandomAccessIterator& other){this->objectReference = other.objectReference; return *this;}

    ~RandomAccessIterator(){}

    // Comparison Operators
    bool operator==(RandomAccessIterator& other){return objectReference == other.objectReference;}
    bool operator!=(RandomAccessIterator& other){return objectReference != other.objectReference;}
    
    // Reference operators
    T& operator*(){return objectReference->GetData();}
    T* operator->(){return &objectReference->GetData();}
    
    // Increment Operators
    RandomAccessIterator& operator++()
    {
        objectReference = objectReference->GetNext();
        this->index++;
    }
    RandomAccessIterator& operator--()
    {
        objectReference = objectReference->GetPrevious();
        this->index--;
    }

    // Arithmetic operators
    // General moving access
    friend RandomAccessIterator operator+(RandomAccessIterator& lhs, int rhs)
    {
        return RandomAccessIterator(lhs.index+rhs,lhs.listReference);
    }
    friend RandomAccessIterator operator+(int lhs, RandomAccessIterator& rhs)
    {
        return RandomAccessIterator(lhs+rhs.index,rhs.listReference);
    }
    friend RandomAccessIterator operator-(RandomAccessIterator& lhs, int rhs)
    {
        return RandomAccessIterator(lhs.index-rhs,lhs.listReference);
    }
    friend RandomAccessIterator operator-(int lhs, RandomAccessIterator& rhs)
    {
        return RandomAccessIterator(lhs-rhs.index,rhs.listReference);
    }
    // Special difference access (Note the parameters are both iterators)
    friend int operator-(RandomAccessIterator& lhs, RandomAccessIterator& rhs)
    {
        return lhs.index - rhs.index;
    }
    
    // Inequality
    bool operator<(RandomAccessIterator& other){return index < other.index;}
    bool operator>(RandomAccessIterator& other){return index > other.index;}
    bool operator<=(RandomAccessIterator& other){return index <= other.index;}
    bool operator>=(RandomAccessIterator& other){return index >= other.index;}
    // Compound assignment
    RandomAccessIterator& operator+=(RandomAccessIterator& other)
    {
        this->index+=other.index;
        this->objectReference = (*listReference)[this->index];
        return *this;
    }
    RandomAccessIterator& operator-=(RandomAccessIterator& other)
    {
        this->index-=other.index;
        this->objectReference = (*listReference)[this->index];
        return *this;
    }
    // Access Operator
    T& operator[](int& index){return (*listReference)[index]->GetData();}
private:
    uint32_t index;
    LinkedNodeInterface<T>** oglistReference;
    LinkedNodeInterface<T>*** listReference;
    LinkedNodeInterface<T>* objectReference;
};
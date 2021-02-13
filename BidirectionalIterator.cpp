template <class T>
class BidirectionalIterator : public std::iterator<std::bidirectional_iterator_tag, T>
{
public:

    BidirectionalIterator(){this->objectReference = nullptr;}
    BidirectionalIterator(LinkedNodeInterface<T>* obj) : objectReference(obj){}

    // Copy constructor
    BidirectionalIterator(const BidirectionalIterator& other) : objectReference(other.objectReference){}

    // Copy assignable
    BidirectionalIterator& operator=(BidirectionalIterator& other){this->objectReference = other.objectReference; return *this;}

    ~BidirectionalIterator(){}

    // Comparison Operators
    bool operator==(BidirectionalIterator& other){return objectReference == other.objectReference;}
    bool operator!=(BidirectionalIterator& other){return objectReference != other.objectReference;}
    // Reference operators
    T& operator*(){return objectReference->GetData();}
    T* operator->(){return &objectReference->GetData();}
    // Increment Operators
    BidirectionalIterator& operator++(){objectReference = objectReference->GetNext();}
    BidirectionalIterator& operator--(){objectReference = objectReference->GetPrevious();}
private:
    LinkedNodeInterface<T>* objectReference;
};
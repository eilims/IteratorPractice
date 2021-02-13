
template <class T>
class ForwardIterator : public std::iterator<std::forward_iterator_tag, T>
{
public:

    ForwardIterator(){this->objectReference = nullptr;}
    ForwardIterator(LinkedNodeInterface<T>* obj) : objectReference(obj){}

    // Copy constructor
    ForwardIterator(const ForwardIterator& other) : objectReference(other.objectReference){}

    // Copy assignable
    ForwardIterator& operator=(ForwardIterator& other){this->objectReference = other.objectReference; return *this;}

    ~ForwardIterator(){}

    // Comparison Operators
    bool operator==(ForwardIterator& other){return objectReference == other.objectReference;}
    bool operator!=(ForwardIterator& other){return objectReference != other.objectReference;}
    // Reference operators
    T& operator*(){return objectReference->GetData();}
    T* operator->(){return &objectReference->GetData();}
    // Increment Operators
    ForwardIterator& operator++(){objectReference = objectReference->GetNext();}
private:
    LinkedNodeInterface<T>* objectReference;
};
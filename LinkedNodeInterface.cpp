template <typename T>
class LinkedNodeInterface
{
public:
    LinkedNodeInterface(){}
    LinkedNodeInterface(T data){this->data = data;this->next=nullptr;this->previous=nullptr;}
    LinkedNodeInterface(LinkedNodeInterface<T>& other){this->data = other.data;}
    virtual T& GetData() {return this->data;}
    virtual void SetData(T data){this->data = data;}
    virtual LinkedNodeInterface<T>* GetNext(){return this->next;}
    virtual void SetNext(LinkedNodeInterface<T>* next){this->next=next;}
    virtual LinkedNodeInterface<T>* GetPrevious(){return this->previous;}
    virtual void SetPrevious(LinkedNodeInterface<T>* previous){this->previous=previous;}
private:
    T data;
    LinkedNodeInterface<T>* next;
    LinkedNodeInterface<T>* previous;
};
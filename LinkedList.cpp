template <typename T, template<typename> typename I, template<typename> typename N>
class LinkedList 
{
public:
    LinkedList()
    {
        this->head = new N<T>();
        this->tail = new N<T>();
        this->head->SetNext(tail);
        this->tail->SetPrevious(head);
        nodeCount = 0;
    }
    void AddEntry(T data)
    {
        if(nodeCount == 0)
        {
            head->SetData(data);
        }
        else
        {
            tail->SetData(data);
            N<T>* newEntry = new N<T>();
            newEntry->SetPrevious(tail);
            tail->SetNext(newEntry);
            tail = newEntry;
        }
        nodeCount++;
    }
    I<T> Begin() {return I<T>(true, nodeCount, head);}
    I<T> End() {return I<T>(false, nodeCount, tail);}
private:
    N<T>* head;
    N<T>* tail;
    uint32_t nodeCount;
};
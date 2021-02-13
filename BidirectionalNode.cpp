template <typename T>
class BidirectionalNode : public LinkedNodeInterface<T>
{
public:
    BidirectionalNode() : LinkedNodeInterface<T>(){}
    BidirectionalNode(T data) : LinkedNodeInterface<T>(data){}
    BidirectionalNode(ForwardNode<T>& other) : LinkedNodeInterface<T>(other){}
};
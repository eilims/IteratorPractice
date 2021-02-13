template <typename T>
class ForwardNode : public LinkedNodeInterface<T>
{
public:
    ForwardNode() : LinkedNodeInterface<T>(){}
    ForwardNode(T data) : LinkedNodeInterface<T>(data){}
    ForwardNode(ForwardNode<T>& other) : LinkedNodeInterface<T>(other){}
};
#include <iostream>
#include <algorithm>

#include "LinkedNodeInterface.cpp"
#include "ForwardNode.cpp"
#include "ForwardIterator.cpp"
#include "BidirectionalNode.cpp"
#include "BidirectionalIterator.cpp"
#include "RandomAccessIterator.cpp"
#include "LinkedList.cpp"

int main(int argc, char** argv)
{
    std::cout << "Hello World!" << std::endl;
    // LinkedList<int, ForwardIterator, ForwardNode> list;
    // list.AddEntry(1);
    // list.AddEntry(2);
    // list.AddEntry(3);
    // auto result = std::find(list.Begin(), list.End(), 4);
    // auto result2 = std::find(list.Begin(), list.End(), 3);
    // *result2 = 4;
    LinkedList<int, RandomAccessIterator, BidirectionalNode> list2;
    list2.AddEntry(1);
    list2.AddEntry(3);
    list2.AddEntry(2);
    auto val = list2.Begin();
    auto val2 = list2.End();
    std::reverse(val, val2);
    std::sort(val, val2);
}
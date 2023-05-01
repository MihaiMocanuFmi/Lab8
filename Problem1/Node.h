#ifndef NODE_H
#define NODE_H

template <typename TElem>
class Node
{
    template <typename>
    friend class Set;
private:
    TElem m_element;
    Node *m_ptrNextNode = END;


public:
    static constexpr Node* END = nullptr;
    Node() = default;
    Node(TElem element, Node *next = END): m_element(element), m_ptrNextNode(next)
    {
    }


    //TElem &element();
    const TElem &element() const
    {
        return m_element;
    }

    Node *next()
    {
        return m_ptrNextNode;
    }

};


#endif //NODE_H

#pragma once

#include "Node.h"

template <typename>
class SetIterator;

template<typename TElem>
class Set
{
    template <typename>
    friend class SetIterator;

private:
    Node<TElem> *m_first = Node<TElem>::END;
    int m_size = 0;

public:
    //implicit constructor
    Set() = default;

    //adds an element to the set
    //returns true if the element was added, false otherwise (if the element was already in the set and it was not added)
    bool add(TElem element)
    {
        if (search(element))
            return false;

        Node<TElem> *newNode = new Node(element, m_first);
        m_first = newNode;
        m_size++;
        return true;
    }

    //removes an element from the set
    //returns true if e was removed, false otherwise
    bool remove(TElem element)
    {
        bool found = false;
        Node<TElem> *p = this->m_first;
        Node<TElem> *previous = nullptr;

        if (isEmpty())
            return false;

        //If we have to delete the first node of the list
        if (m_first->element() == element)
        {
            found = true;
            m_first = m_first->next();

            delete p;
            m_size--;
        }
        else
        {
            previous = p;
            p = p->next();
        }


        while (p != Node<TElem>::END and not found)
        {
            if (p->element() == element)
            {
                found = true;
                previous->m_ptrNextNode = p->next();

                //We have delete the node after the one pointed by previous
                delete p;
                m_size--;
            }
            else
            {
                previous = p;
                p = p->next();
            }
        }
        return found;
    }

    //checks whether an element belongs to the set or not
    bool search(TElem element) const
    {

        Node<TElem> *p = this->m_first;
        while (p != Node<TElem>::END)
            if (p->element() == element)
                return true;
            else
                p = p->next();
        return false;
    }

    //returns the number of elements;
    int size() const
    {
        return m_size;
    }

    //check whether the set is empty or not;
    bool isEmpty() const
    {
        return m_first == Node<TElem>::END;
    }

    //return an iterator for the set
    SetIterator<TElem> iterator() const
    {
        return SetIterator<TElem>(*this);
    }


    // destructor
    ~Set()
    {
        while (m_first != Node<TElem>::END)
        {
            Node<TElem> *p = m_first;
            m_first = m_first->next();
            delete p;
        }

        m_first = Node<TElem>::END;
        m_size = 0;
    }

};






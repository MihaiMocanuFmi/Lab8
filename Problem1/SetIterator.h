#pragma once
#include "Set.h"

#include <exception>

template <typename TElem>
class SetIterator
{
    template<typename>
	friend class Set;
private:
	//DO NOT CHANGE THIS PART
	const Set<TElem>& set;
    Node<TElem> *m_current = Node<TElem>::END;

    explicit SetIterator(const Set<TElem>& s) : set{s}, m_current(s.m_first)
    {
    }


public:
	void first()
    {
        m_current = set.m_first;
    }

	void next()
    {
        if (not valid())
            throw std::exception();
        else
            m_current = m_current->next();
    }
	TElem getCurrent()
    {
        if (not valid())
            throw std::exception();
        else
            return m_current->element();
    }

	bool valid() const
    {
        return m_current != Node<TElem>::END;
    }
};



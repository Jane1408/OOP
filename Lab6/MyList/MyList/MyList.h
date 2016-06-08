#pragma once
#include "stdafx.h"

template<typename T>
struct Node
{
	Node(T const& val)
		: value(val)
	{}
	Node(Node<T> * node)
		: value(node->value)
	{}
	T value;
	std::unique_ptr<Node<T>> next = nullptr;
	Node * prev = nullptr;
};

template<typename T>
class MyIterator
{
public:
	MyIterator(Node<T> * node, bool isReverse)
		: m_isReverse(isReverse)
		, m_currentNode(node)
	{}

	bool IsReverse()const
	{
		return m_isReverse;
	}

	T & operator* ()
	{
		return m_currentNode->value;
	}

	void operator= (Node<T> * node)
	{
		m_currentNode = node;
	}

	const bool operator== (Node<T> * node)
	{
		return m_currentNode == node;
	}

	const bool operator!= (Node<T> * node)
	{
		return m_currentNode != node;
	}

	const bool operator== (MyIterator<T> const& iterator)
	{
		return m_currentNode == iterator.m_currentNode;
	}

	const bool operator!= (MyIterator<T> const& iterator)
	{
		return m_currentNode != iterator.m_currentNode;
	}

	friend const MyIterator<T> & operator++ (MyIterator<T> & iterator)
	{
		if (iterator.IsReverse())
		{
			iterator.m_currentNode = iterator.m_currentNode->prev;
		}
		else
		{
			iterator.m_currentNode = iterator.m_currentNode->next.get();
		}
		return iterator;
	}

	friend const MyIterator<T> & operator-- (MyIterator<T> & iterator)
	{
		if (iterator.IsReverse())
		{
			iterator.m_currentNode = iterator.m_currentNode->next.get();
		}
		else
		{
			iterator.m_currentNode = iterator.m_currentNode->prev;
		}
		return iterator;
	}

	friend const MyIterator<T> operator++ (MyIterator<T> & iterator, int)
	{
		auto oldIter = iterator;
		if (iterator.IsReverse())
		{
			iterator.m_currentNode = iterator.m_currentNode->prev;
		}
		else
		{
			iterator.m_currentNode = iterator.m_currentNode->next.get();
		}
		return oldIter;
	}

	friend const MyIterator<T> operator-- (MyIterator<T> & iterator, int)
	{
		auto oldIter = iterator;
		if (iterator.IsReverse())
		{
			iterator.m_currentNode = iterator.m_currentNode->next.get();
		}
		else
		{
			iterator.m_currentNode = iterator.m_currentNode->prev;
		}
		return oldIter;
	}

	Node<T> * m_currentNode;
private:
	bool m_isReverse;
};


///////////////////////////////////////
///////////////////////////////////////
template <typename T>
class MyList
{
public:
	MyList<T>() {};

	MyList<T>(MyList<T> const& list)
	{
		for (auto &it : list)
		{
			PushBack(it);
		}
	}

	~MyList() = default;

	size_t size()
	{
		return m_size;
	}

	void PushBack(T const& val)
	{
		if (m_end == nullptr)
		{
			m_begin = move(std::make_unique<Node<T>>(val));
			m_end = m_begin.get();
		}
		else
		{
			auto node = std::make_unique<Node<T>>(val);
			auto prevNode = node.get();
			node->prev = m_end;
			m_end->next = move(node);
			m_end = prevNode; 
		}
		++m_size;
	}

	void PushFront(T const& val)
	{
		if (m_end == nullptr)
		{
			m_begin = move(std::make_unique<Node<T>>(val));
			m_end = m_begin.get();
		}
		else
		{
			auto node = std::make_unique<Node<T>>(val);
			auto prevNode = node.get();
			m_begin->prev = prevNode;
			node->next = move(m_begin);
			m_begin = move(node);
		}
		++m_size;
	}

	void Insert(MyIterator<T> & iterator, T const& value)
	{
		if (iterator == m_begin.get())
		{
			PushFront(value);
			iterator = m_begin.get();
		}
		else if (iterator == m_end)
		{
			PushBack(value);
			iterator = m_end;
		}
		else
		{
			auto addingNode = std::make_unique<Node<T>>(value);
			auto node = iterator.m_currentNode;

			addingNode->prev = node->prev;
			node->prev = addingNode.get();
			addingNode->next = move(addingNode->prev->next);
			addingNode->prev->next = move(addingNode);

			iterator = node->prev;
			++m_size;
		}
	}

	void Erase(MyIterator<T> & iterator)
	{
		if (iterator == m_begin.get())
		{
			m_begin = move(m_begin.get()->next);
		}
		else if (iterator == m_end)
		{
			m_end = m_end->prev;
			m_end->next = nullptr;
		}
		else
		{
			auto node = iterator.m_currentNode;
			node->next.get()->prev = node->prev;
			node->prev->next = move(node->next);
		}
		--m_size;
	}

	MyIterator<T> begin()
	{
		return MyIterator<T>(m_begin.get(), false);
	}
	MyIterator<T> end()
	{
		return MyIterator<T>(nullptr, false);
	}
	MyIterator<T> rbegin()
	{
		return MyIterator<T>(m_end, true);
	}
	MyIterator<T> rend()
	{
		return MyIterator<T>(nullptr, true);
	}

	const MyIterator<T> begin() const
	{
		return MyIterator<T>(m_begin.get(), false);
	}
	const MyIterator<T> end() const
	{
		return MyIterator<T>(nullptr, false);
	}
	const MyIterator<T> rbegin() const
	{
		return MyIterator<T>(m_end, true);
	}
	const MyIterator<T> rend() const
	{
		return MyIterator<T>(nullptr, true);
	}

	void operator= (MyList<T> const& list)
	{
		m_begin = move(list.begin());
		m_end = (list.rbegin());
		m_size = list.size();
	}
private:

	size_t m_size = 0;
	std::unique_ptr<Node<T>> m_begin = nullptr;
	Node<T> * m_end = nullptr;

};
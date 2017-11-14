#ifndef _LIST_HPP_
#define _LIST_HPP_

namespace sc{
	template <typename T>
	struct Node{
		T data;
		Node *prev;
		Node *next;
		Node(const T & d = T(), Node * p = nullptr, Node * n = nullptr):
			data(d), prev(p), next(n){ /* Empty */ }
	};

	class const_iterator{
		protected:
			Node *current;
			const_iterator( Node * p ): current(p);
			friend class list<Object>;

		public:
			const_iterator();
			const Object & operator*() const;
			const_iterator & operator++();
			const_iterator operator++(int);
			const_iterator & operator--();
			const_iterator & operator--(int);
			bool operator==(const const_iterator & rhs ) const;
			bool operator!=(const const_iterator & rhs ) const;
	};

	template <typename T>
	class iterator : public const_iterator{
		public:
			iterator(): const_iterator(){ /* Empty */ }
			const T& operator*() const;
			Object & operator*();

			iterator & operator++();
			iterator operator++(int);
			iterator & operator--();
			iterator operator--(int);
			bool operator!=( const iterator & rhs );
		
		protected:
			iterator(Node * p): const_iterator(p);
			friend class list<Object>;
	};

	template <typename T>
	class list{
	
		private:
			size_t m_size;
			Node * m_head;
			Node * m_tail;

		public:
			list();
			~list();
			list( const list & );
			list &operator=( const list & );

	};
}

#include "const_iterator.inl"
#include "iterator.inl"
#include "list.inl"

#endif
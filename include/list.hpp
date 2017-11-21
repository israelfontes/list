#ifndef _LIST_HPP_
#define _LIST_HPP_
#include <iostream>

namespace sc{

	template <typename T>
	class list{
		private:
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
				const_iterator( Node * p ): current(p){}
				friend class list<T>;

			public:
				const_iterator();
				const T & operator*() const;
				const_iterator & operator++();
				const_iterator operator++(int);
				const_iterator & operator--();
				const_iterator & operator--(int);
				bool operator==(const const_iterator & rhs ) const;
				bool operator!=(const const_iterator & rhs ) const;
		};

		class iterator : public const_iterator{
			public:
				iterator(): const_iterator(){}
				const T& operator*() const;
				iterator & operator++();
				iterator operator++(int);
				iterator & operator--();
				iterator operator--(int);
				bool operator!=( const iterator & rhs );
				bool operator==( const iterator & rhs );
			
			protected:
				iterator(Node *p): const_iterator(p){}
				friend class list<T>;
		};

		private:
			size_t m_size = 0;
			Node * m_head;
			Node * m_tail;

		public:
			list();
			~list();
			explicit list ( size_t count );
			list( const list & other);
			list &operator=( const list & other );

			iterator begin();
			const_iterator cbegin() const;
			iterator end();
			const_iterator cend() const;

			size_t size() const;
			bool empty() const;

			void clear();
			T & front();
			const T & front() const;
			T & back();
			const T & back() const;
			void push_front( const T & value );
			void push_back( const T & value );
			void pop_front();
			void pop_back();

	};
}

#include "const_iterator.inl"
#include "iterator.inl"
#include "list.inl"

#endif
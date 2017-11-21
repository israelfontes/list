template <typename T>
sc::list<T>::list(){ 
	m_head = new Node();
	m_tail = new Node();
	m_head->prev = nullptr;
	m_tail->next = nullptr;	
	m_head->next = m_tail;
	m_tail->prev = m_head;

}

template <typename T>
sc::list<T>::~list(){ 
	Node * _tmp, * tmp_ = this->m_head;
	while( tmp_ != m_tail ){
		_tmp = tmp_;
		tmp_ = tmp_->next;
		delete _tmp;
	}
	delete this->m_tail;
}

template <typename T>
sc::list<T>::list( const list & other ){
	list();
	this->m_size = other.size();
	iterator it = other.begin();

	while( it != other.end() ){
		push_front( *(it).data );
		++it;
	}
}

template <typename T>
typename sc::list<T> & sc::list<T>::operator=( const list & other ){ this->list( other ); }

template <typename T>
typename sc::list<T>::iterator sc::list<T>::begin(){ return iterator(m_head->next); }

template <typename T>
typename sc::list<T>::const_iterator sc::list<T>::cbegin() const{ return const_iterator( m_head ); }

template <typename T>
typename sc::list<T>::iterator sc::list<T>::end(){ return iterator(m_tail); }

template <typename T>
typename sc::list<T>::const_iterator sc::list<T>::cend() const{ return const_iterator( m_tail ); }

template <typename T>
size_t sc::list<T>::size() const{ return m_size; }

template <typename T>
bool sc::list<T>::empty() const{ return m_size==0; }

template <typename T>
void sc::list<T>::clear(){ m_size = 0; }

template <typename T>
T & sc::list<T>::front(){ return (m_tail->prev)->data; }

template <typename T>
const T & sc::list<T>::front() const{ return (m_tail->prev)->data; }

template <typename T>
T & sc::list<T>::back(){ return (m_head->next)->data; }

template <typename T>
const T & sc::list<T>::back() const{ return (m_head->next)->data; }

template <typename T>
void sc::list<T>::push_front( const T & value ){ 
	Node * tmp = m_tail->prev;
	tmp->next = new Node( value, tmp, m_tail );
	m_tail->prev = tmp->next;
	++m_size;
}

template <typename T>
void sc::list<T>::push_back( const T& value ){
	Node * tmp = m_head->next;
	tmp->prev = new Node( value, m_head, tmp );
	m_head->next = tmp->prev;
	++m_size;
}

template <typename T>
void sc::list<T>::pop_front(){	
	Node * tmp = m_tail->prev;
	(tmp->prev)->next = m_tail;
	m_tail->prev = tmp->prev;
	delete tmp;
	--m_size;	
}

template <typename T>
void sc::list<T>::pop_back(){
	Node * tmp = m_head->next;
	(tmp->next)->prev = m_head;
	m_head->next = tmp->next;
	delete tmp;
	--m_size;
}
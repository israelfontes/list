
template<typename T>
sc::list<T>::const_iterator::const_iterator(){ /* Empty */ }

template<typename T>
const T & sc::list<T>::const_iterator::operator*() const{ return *current; }

template<typename T>
typename sc::list<T>::const_iterator & sc::list<T>::const_iterator::operator++(){ current = current->next; return *current; }

template<typename T>
typename sc::list<T>::const_iterator sc::list<T>::const_iterator::operator++(int){ const_iterator temp(*this); operator++(); return temp; }

template<typename T>
typename sc::list<T>::const_iterator & sc::list<T>::const_iterator::operator--(){ current = current->prev; return *this; }

template<typename T>
typename sc::list<T>::const_iterator & sc::list<T>::const_iterator::operator--(int){ const_iterator temp(*this); operator--(); return temp; }

template<typename T>
bool sc::list<T>::const_iterator::operator==(const const_iterator & rhs ) const{ return current==rhs.current; }

template<typename T>
bool sc::list<T>::const_iterator::operator!=(const const_iterator & rhs ) const{ return current!=rhs.current; }
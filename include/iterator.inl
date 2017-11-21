
template<typename T>
const T& sc::list<T>::iterator::operator*() const{ return *(const_iterator::current)->data; }

template<typename T>
typename sc::list<T>::iterator & sc::list<T>::iterator::operator++(){ return ++this; }

template<typename T>
typename sc::list<T>::iterator sc::list<T>::iterator::operator++(int){ return this++; }

template<typename T>
typename sc::list<T>::iterator & sc::list<T>::iterator::operator--(){ return --this; }

template<typename T>
typename sc::list<T>::iterator sc::list<T>::iterator::operator--(int){ return this--; }

template<typename T>
bool sc::list<T>::iterator::operator!=( const iterator & rhs ){ return rhs!=this; }

template<typename T>
bool sc::list<T>::iterator::operator==( const iterator & rhs ){ return rhs==this; }
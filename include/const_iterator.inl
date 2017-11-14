
template<typename T>
sc::const_iterator<T>::const_iterator(){ /* Empty */ }

template<typename T>
const Object & sc::const_iterator<T>::operator*() const{ return *current; }

template<typename T>
const_iterator & sc::const_iterator<T>::operator++(){ ++current; return *current; }

template<typename T>
const_iterator sc::const_iterator<T>::operator++(int){ const_iterator temp(*this); operator++(); return temp; }

template<typename T>
const_iterator & sc::const_iterator<T>::operator--(){ --current; return *this; }

template<typename T>
const_iterator & sc::const_iterator<T>::operator--(int){ iterator temp(*this); operator--(); return temp; }

template<typename T>
bool sc::const_iterator<T>::operator==(const const_iterator & rhs ) const{ return current==rhs.current; }

template<typename T>
bool sc::const_iterator<T>::operator!=(const const_iterator & rhs ) const{ return current!=rhs.current; }
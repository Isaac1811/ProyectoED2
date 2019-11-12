#ifndef DICTIONARY_H
#define DICTIONARY_H
#include "List.h"

/*
Creador: María Fernanda Lanza Cruz
Fecha: 11/11/19
Funcionalidad:
*/
template <typename K, typename V>
class Dictionary
{
    public:
    Dictionary() {}
    virtual ~Dictionary() {}
    virtual void insert(K key, V value) = 0;
    virtual V remove(K key) = 0;
    virtual V getValue(K key) = 0;
    virtual void setValue(K key, V value) = 0;
    virtual void clear() = 0;
    virtual bool contains(K key) = 0;
    virtual LinkedList<K>* getKeys() = 0;
    virtual LinkedList<V>* getValues() = 0;
    virtual int getSize() = 0;
};

#endif // DICTIONARY_H

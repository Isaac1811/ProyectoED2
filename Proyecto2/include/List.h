#ifndef LIST_H
#define LIST_H

/*
Creador: Mar�a Fernanda Lanza Cruz
Fecha: 11/11/19
Funcionalidad: Clase abstracta de lista , esta posee los m�todos que se deben incluir.
*/
template <typename E>
class List{

private:
    void operator =(const List&) {}
    List(const List& obj) {}

public:
    List() {}
    virtual ~List() {}
    virtual void insert(E element) = 0;
    virtual void append(E element) = 0;
    virtual E remove() = 0;
    virtual void clear() = 0;
    virtual E getElement() = 0;
    virtual void goToStart() = 0;
    virtual void goToEnd() = 0;
    virtual void goToPos(int pos) = 0;
    virtual void next() = 0;
    virtual bool atEnd() = 0;
    virtual void previous() = 0;
    virtual bool atStart() = 0;
    virtual int getPos() = 0;
    virtual int getSize() = 0;
};

#endif // LIST_H

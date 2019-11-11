#ifndef BSTNODE_H
#define BSTNODE_H


template <typename Key, typename E>
class BSTNode{

    private:
        Key key;
        E element;
        BSTNode<Key, E>* left;
        BSTNode<Key, E>* right;

        BSTNode(BSTNode<Key, E>* pLeft = NULL, BSTNode<Key, E>* pRight= NULL) {
            left = pLeft;
            right = pRight;
        }

        BSTNode(Key pKey, E pElement, BSTNode<Key, E>* pLeft = NULL,BSTNode<Key, E>* pRight = NULL) {
            key = pKey;
            element = pElement;
            left = pLeft;
            right = pRight;
        }

        ~BSTNode() {}

        E getElement() {
            return element;
        }

        void setElement(E pElement) {
            element = pElement;
        }

        Key getKey() {
            return key;
        }

        void setKey(Key pKey) {
            key = pKey;
        }

        BSTNode<Key, E>* getLeft() {
            return left;
        }

        void setLeft(BSTNode<Key, E>* pLeft) {
            left = pLeft;
        }

        BSTNode<Key, E>* getRight() {
            return right;
        }

        void setRight(BSTNode<Key, E>* pRight) {
            right = pRight;
        }

        bool isLeaf() {
            return (left == NULL) && (right == NULL);
        }

};

#endif // BSTNODE_H

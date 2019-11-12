#include "TrieNode.h"
#include <string>
#include <stdexcept>

/*
Creador: María Fernanda Lanza Cruz
Fecha: 11/11/19
Funcionalidad:
*/
using namespace std;
class Trie{
	private:
		TrieNode *root;

	public:
		Trie(){
			root= new TrieNode();
		}
		~Trie(){
			clear();
			delete root;
		}
		bool containsWord(string word){
			TrieNode *current=root;
			for (int i=0; i<word.size(); i++){
				char c =word[i];
				if(!current->contains(c)){
					return false;
				}
				current=current->getChild(c);
			}
			return current-> isFinal();
		}

		void insert(string word)throw(runtime_error){
			if(contains(word))throw runtime_error("Word already in Trie");
			TrieNode *current=root;
			for(int i=0; i<word.size();i++){
				current->increaseCount();
				if(!current->contains(word[i])){
					current->add(word[i]);
				}
				current=current->getChild(word[i]);
			}
			current->setIsFinal(true);
			current->increaseCount();
		}

		int prefixCount(string prefix){
			TrieNode *current=root;
			for(unsigned i=0; i<prefix.size();i++){
				if(!current->contains(prefix[i])) return 0;
				current=current->getChild(prefix[i]);
			}
			return current->getPrefixCount();
		}

		void remove(string word)throw(runtime_error){
			if(!containsWord(word)) throw runtime_error("Word not found");
			for(int i=0; i<word.size();i++){
				current->decreaseCount();
				TrieNode *child= current->getChild(word[i]);
				if(current->getPrefixCount()==0) delete current;
				if(child->getPrefixCount()==1) current->remove(word[i]);
				current=child;
			}
			current->decreaseCount();
			if(current->getPrefixCount==0) delete current;
			else current->setIsFinal(false);
		}

	public:
		void clear(){
			clearAux(root);
			root=new TrieNode();
		}

	private:
		void clearAux(TrieNode*current){
			List<TrieNode> *pointers=current->getChildrenPointers();
			for(pointers->goToStart();!pointers->atEnd(); pointers->next()){
				clearAux(pointers->getElement());
			}
			delete current;
			delete pointers;
		}

	public:
		List<string> *getMatches(string prefix){
			List<string> *words= new DLinkedList<string>();
			getMatchesAux(root, prefix,"", words);
			return words;
		}

	private:
		void getMatchesAux(TrieNode*current, string rest, string prefix, List<string>*words){
			if(current->getIsFinal()) words->append(prefix);
			List<char>*children=current->getChildren();
			for(children->goToStart(); !children->atEnd();children->next()){
				char c=children->getElement;
				if(rest.size()==0){
					string newPrefix= prefix;
					newPrefix.append(1,c);
					getMatchesAux(current->getChild(c), rest, newPrefix, words);
				}
				else if(c==rets[0]){
					string newPrefix=prefix;
					newPrefix.append(1,c);
					rest.erase(0,1);
					getMatchesAux(current->getChild(c),rest,newPrefix, words);
				}
			}
			delete children;
		}
};
#endif // TRIE_H

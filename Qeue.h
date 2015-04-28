#ifndef _Qeue_
#define _Qeue_

#include <stdio.h>

template<class TYPE>
struct qNode {

	TYPE value;
	qNode<TYPE>* next;
	qNode<TYPE>* prev;

	inline qNode(const TYPE& _value) {

		value = _value;
		next = NULL;
	}

	~qNode(){}
};

template<class TYPE>
class Qeue {

public:

	qNode<TYPE>* start;
	qNode<TYPE>* end;

private:

	unsigned int size;

public:

	//Constructor
	inline Qeue() {

		start = end = NULL;
		size = 0;
	}

	//Destructor
	~Qeue() {

		delAll();
	}

	//Get Size
	unsigned int get_size(){ 

		return size;
	}

	//push
	void push(const TYPE& value) {

		qNode<TYPE>* new_qNode = new qNode<TYPE>(value);

		if (start == NULL)
			start = end = new_qNode;
		
		else {

			newqNode->prev = end;
			end->next = new_qNode;
			end = newqNode;
		}

		size++;
	}

	//pop
	bool pop(TYPE& value {

		if (start == NULL || end == NULL)
			return false;

		else {

			qNode<TYPE>* tmp = start;
			start = start->next;
			start->prev = NULL;
			value = tmp->value;
			delete tmp;
			--size;
		}

		return(true);
	}

	bool del(unsigned int x) {
		if (start == NULL || end == NULL)
			return false;

		else {

			if (x == 0) {

				start = start->next;
				return(true);
			}

			qNode* tmp = start;
			qNode* tmp2;

			for (unsigned int i = 1; i < x; i++) {
				if (tmp == NULL)
					return(false);
				tmp = tmp->next;
			}

			tmp2 = tmp->next;

			if (tmp2->next != NULL) {

				tmp->next = tmp2->next;
				tmp = tmp2->next;
				tmp->prev = tmp2->prev;
			}

			else {
				end = end->previous;
				end->next = NULL;
			}
		}

		delete tmp2;
		--size;
		return(true)
	}


	//Destroy and free all mem
	void delAll() {

		if (start != NULL) {

			qNode<TYPE>* tmp;
			while (start != NULL) {

				tmp = start;
				start = start->next;
				delete tmp;
			}

			start = end = NULL;
			size = 0;
		}
	}

};



#endif
#ifndef __TREE_H__
#define __TREE_H__
#include <stdio.h>
#include "p2List.h"
#include "Stack.h"

template<class VALUE>
class NodeTree {

public: 

	VALUE data;
	NodeTree* parent;
	p2List<NodeTree*> children;

	NodeTree (const VALUE &value) {
		data = value;
		parent = NULL;
	}

	~NodeTree(){}

	void addSon(NodeTree* to_add) {
		if (to_add != NULL){
			children.add(to_add);
			to_add->parent = this;
		}
	}

	bool delSon(NodeTree* to_del) {
		bool del = false;

		if (to_del != NULL) {
			p2List_item<NodeTree*> *tmp = children.getFirst();
			for (; tmp != NULL; tmp = tmp->next) {
				NodeTree* child = tmp->data;

				if (to_del == child){
					children.del(tmp);
					to_del->parent = NULL;
					del = true;
					break;
				}

			}

		}
		return del;
	}

	void preOrderRec(p2List<NodeTree<VALUE>*> *list) {

		list->add(this);

		p2List_item<NodeTree*> *tmp = children.getFirst();
		
		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->preOrderRec(list);
	}


	void postOrderRec(p2List<NodeTree<VALUE>*> *list) {

		p2List_item<NodeTree*> *tmp = children.getFirst();
		
		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->postOrderRec(list);
		
		list->add(this);
	}

	void inOrderRec(p2List<NodeTree<VALUE>*> *list) {

		p2List_item<NodeTree*> *tmp = children.getFirst();

		unsigned int middle = children.count() / 2;

		for (unsigned int i = 0; i < middle; i++, tmp = tmp->next)
			tmp->data->inOrderRec(list);

		list->add(this);
		
		for (; tmp != NULL; tmp = tmp->next)
			tmp->data->inOrderRec(list);
		
	}

	void gatherAll(p2List<NodeTree<VALUE>*> *list)
	{
		list->add(this);

		p2List_item<NodeTree*>* item = children.getFirst();
		for (item; item != NULL; item = item->next)
		{
			NodeTree* child = item->data;
			child->gatherAll(list);
		}
	}


};


template<class VALUE>
class Tree{

public:
	NodeTree<VALUE> root_node;

	Tree(const VALUE& value) : root_node(value) {}

	~Tree(){}

	NodeTree<VALUE>* add(const VALUE &value, NodeTree<VALUE>* parent){

		NodeTree<VALUE>* tmp = new NodeTree<VALUE>(value);

		if (parent == NULL) 
			root_node.addSon(tmp);
	
		else 
			parent->addSon(tmp);
		
		return tmp;

	}



	bool clear(NodeTree<VALUE>* to_delete)
	{
		bool ret = false;

		NodeTree<VALUE>* tmp = to_delete;

		if (tmp != NULL)
		{
			p2List<NodeTree<VALUE>*> res;
			tmp->gatherAll(&res);
			p2List_item<NodeTree<VALUE>*> *item = res.getFirst();

			for (; item != NULL; item = item->next)
			{
				NodeTree<VALUE>* child = item->data;

				if (child->parent)
					child->parent->delSon(child);
			}
			ret = true;
		}
		return ret;
	}

	void preOrderRec(p2List<NodeTree<VALUE>*> *list) {

		root_node.preOrderRec(list);
	}


	void postOrderRec(p2List<NodeTree<VALUE>*> *list) {

		root_node.postOrderRec(list);
	}

	void inOrderRec(p2List<NodeTree<VALUE>*> *list) {

		root_node.inOrderRec(list);
	}

	void preOrderIt(p2List<NodeTree<VALUE>*> *list) {

		Stack<NodeTree<VALUE>*> stack;
		NodeTree<VALUE>* tmp = &root_node;

		while (tmp != NULL || stack.pop(tmp)) {

			list->add(tmp);
			p2List_item<NodeTree<VALUE>*> *tmp_children = tmp->children.getLast();
			for (tmp_children; tmp_children != tmp->children.getFirst(); tmp_children = tmp_children->prev)
				stack.pushBack(tmp_children->data);
			if (tmp_children != NULL)
				tmp = tmp_children->data;
			else
				tmp = NULL;
		}
		
	}

	void postOrderIt(p2List<NodeTree<VALUE>*>* list) {

		Stack<NodeTree<VALUE>*> stack;
		NodeTree<VALUE>* tmp = &root_node;

		while (tmp != NULL || stack.pop(tmp)) {

			p2List_item<NodeTree<VALUE>*> *tmp_children = tmp->children.getLast();
			if (tmp_children != NULL && list->find(tmp_children->data) == -1)
			{
				stack.pushBack(tmp);
				for (; tmp_children != tmp->children.getFirst(); tmp_children = tmp_children->prev)
					stack.pushBack(tmp_children->data);
				tmp = tmp_children->data;
			}
			else {
				list->add(tmp);
				tmp = NULL;
			}
	

		}

	}

	void inOrderIt(p2List<NodeTree<VALUE>*>* list)
	{
		bool isWorking = true;
		Stack<NodeTree<VALUE>*> stack;
		NodeTree<VALUE>* tmp = &root_node;


		while (isWorking)
		{
			if (tmp != NULL) {
				if (list->find(tmp) == -1)
					stack.pushBack(tmp);

				if (tmp->children.count() != 0)
					tmp = tmp->children.getFirst()->data;

				else
					tmp = NULL;
			}

			else if (stack.count() > 0) {
				stack.pop(tmp);
				list->add(tmp);
				if (tmp->children.count() != 0)
					tmp = tmp->children.getLast()->data;

				else
					tmp = NULL;
			}

			else
				isWorking = false;

		}
	}

	

};

#endif

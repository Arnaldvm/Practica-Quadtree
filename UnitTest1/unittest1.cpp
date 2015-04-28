#include "stdafx.h"
#include "CppUnitTest.h"
#include "../Practica2-Quadtree/TreeClass.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{		
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(add_root)
		{
			Tree<int> a(0);

			a.add(100, NULL);

			Assert::IsTrue(a.root_node.children.count() == 1);
		}

		TEST_METHOD(add)
		{
			Tree<int> t(0);

			NodeTree<int>* t1 = t.add(100, NULL);

			NodeTree<int>* t2 = t.add(100, t1);

			Assert::IsTrue(t2->parent == t1);
		}

		TEST_METHOD(clear)
		{
			Tree<char> tree('F');

			NodeTree<char>* b = tree.add('B', NULL);
			NodeTree<char>* g = tree.add('G', NULL);
			NodeTree<char>* a = tree.add('A', b);
			NodeTree<char>* d = tree.add('D', b);
			NodeTree<char>* x = tree.add('X', b);
			NodeTree<char>* c = tree.add('C', d);
			NodeTree<char>* e = tree.add('E', d);
			NodeTree<char>* i = tree.add('I', g);
			NodeTree<char>* h = tree.add('H', i);


			tree.clear(d);
			p2List<NodeTree<char>*> list;
			tree.preOrderRec(&list);


			Assert::AreEqual((int)list.count(), 7);
		}

		//Recursive

		TEST_METHOD(TreePreOrder)
		{
			Tree<char> tree('F');

			NodeTree<char>* b = tree.add('B', NULL);
			NodeTree<char>* g = tree.add('G', NULL);
			NodeTree<char>* a = tree.add('A', b);
			NodeTree<char>* d = tree.add('D', b);
			NodeTree<char>* x = tree.add('X', b);
			NodeTree<char>* c = tree.add('C', d);
			NodeTree<char>* e = tree.add('E', d);
			NodeTree<char>* i = tree.add('I', g);
			NodeTree<char>* h = tree.add('H', i);

			p2List<NodeTree<char>*> list;
			tree.preOrderRec(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(TreePostOrder)
		{
			Tree<char> tree('F');

			NodeTree<char>* b = tree.add('B', NULL);
			NodeTree<char>* g = tree.add('G', NULL);
			NodeTree<char>* a = tree.add('A', b);
			NodeTree<char>* d = tree.add('D', b);
			NodeTree<char>* c = tree.add('C', d);
			NodeTree<char>* e = tree.add('E', d);
			NodeTree<char>* i = tree.add('I', g);
			NodeTree<char>* h = tree.add('H', i);

			p2List<NodeTree<char>*> list;
			tree.postOrderRec(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrder)
		{
			Tree<char> tree('F');

			NodeTree<char>* b = tree.add('B', NULL);
			NodeTree<char>* g = tree.add('G', NULL);
			NodeTree<char>* a = tree.add('A', b);
			NodeTree<char>* d = tree.add('D', b);
			NodeTree<char>* c = tree.add('C', d);
			NodeTree<char>* e = tree.add('E', d);
			NodeTree<char>* i = tree.add('I', g);
			NodeTree<char>* h = tree.add('H', i);

			p2List<NodeTree<char>*> list;
			tree.inOrderRec(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'G');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'H');
		}

		//Iterative

		TEST_METHOD(TreePreOrder_Iterative)
		{
			Tree<char> tree('F');

			NodeTree<char>* b = tree.add('B', NULL);
			NodeTree<char>* g = tree.add('G', NULL);
			NodeTree<char>* a = tree.add('A', b);
			NodeTree<char>* d = tree.add('D', b);
			NodeTree<char>* x = tree.add('X', b);
			NodeTree<char>* c = tree.add('C', d);
			NodeTree<char>* e = tree.add('E', d);
			NodeTree<char>* i = tree.add('I', g);
			NodeTree<char>* h = tree.add('H', i);

			p2List<NodeTree<char>*> list;
			tree.preOrderIt(&list);

			Assert::AreEqual((int)list.count(), 10);

			Assert::AreEqual((char)list[0]->data, 'F');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'A');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'C');
			Assert::AreEqual((char)list[5]->data, 'E');
			Assert::AreEqual((char)list[6]->data, 'X');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'I');
			Assert::AreEqual((char)list[9]->data, 'H');
		}

		TEST_METHOD(TreePostOrder_Iterative)
		{
			Tree<char> tree('F');

			NodeTree<char>* b = tree.add('B', NULL);
			NodeTree<char>* g = tree.add('G', NULL);
			NodeTree<char>* a = tree.add('A', b);
			NodeTree<char>* d = tree.add('D', b);
			NodeTree<char>* c = tree.add('C', d);
			NodeTree<char>* e = tree.add('E', d);
			NodeTree<char>* i = tree.add('I', g);
			NodeTree<char>* h = tree.add('H', i);

			p2List<NodeTree<char>*> list;
			tree.postOrderIt(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'C');
			Assert::AreEqual((char)list[2]->data, 'E');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'B');
			Assert::AreEqual((char)list[5]->data, 'H');
			Assert::AreEqual((char)list[6]->data, 'I');
			Assert::AreEqual((char)list[7]->data, 'G');
			Assert::AreEqual((char)list[8]->data, 'F');
		}

		TEST_METHOD(TreeInOrder_Iterative)
		{
			Tree<char> tree('F');

			NodeTree<char>* b = tree.add('B', NULL);
			NodeTree<char>* g = tree.add('G', NULL);
			NodeTree<char>* a = tree.add('A', b);
			NodeTree<char>* d = tree.add('D', b);
			NodeTree<char>* c = tree.add('C', d);
			NodeTree<char>* e = tree.add('E', d);
			NodeTree<char>* i = tree.add('I', g);
			NodeTree<char>* h = tree.add('H', i);

			p2List<NodeTree<char>*> list;
			tree.inOrderIt(&list);

			Assert::AreEqual((int)list.count(), 9);

			Assert::AreEqual((char)list[0]->data, 'A');
			Assert::AreEqual((char)list[1]->data, 'B');
			Assert::AreEqual((char)list[2]->data, 'C');
			Assert::AreEqual((char)list[3]->data, 'D');
			Assert::AreEqual((char)list[4]->data, 'E');
			Assert::AreEqual((char)list[5]->data, 'F');
			Assert::AreEqual((char)list[6]->data, 'H');
			Assert::AreEqual((char)list[7]->data, 'I');
			Assert::AreEqual((char)list[8]->data, 'G');
		}

	};
}
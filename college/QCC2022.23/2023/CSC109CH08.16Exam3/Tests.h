#define TEMPLATE_TESTS_H
#include <cxxtest/TestSuite.h>

#include "NameNode.h"
#include "NameList.h"

class newCxxTest : public CxxTest::TestSuite
{
public:
    // All tests should start with the word 'test' followed by
    // the name of the function being tested.

    void TestNameNodeConstructorNull()
    {
        NameNode *node = new NameNode();
        TS_ASSERT_EQUALS(node->getName(), "");
        TS_ASSERT_EQUALS(node->getAge(), 0);
        TS_ASSERT_EQUALS(node->getNext(), nullptr);
        delete node;
    }

    void TestNameNodeConstructor()
    {
        NameNode *node = new NameNode("John", 20);
        TS_ASSERT_EQUALS(node->getName(), "John");
        TS_ASSERT_EQUALS(node->getAge(), 20);
        TS_ASSERT_EQUALS(node->getNext(), nullptr);
        delete node;
    }

    void TestNameNodeSetters()
    {
        NameNode *node = new NameNode();
        node->setName("John");
        node->setAge(20);
        TS_ASSERT_EQUALS(node->getName(), "John");
        TS_ASSERT_EQUALS(node->getAge(), 20);
        TS_ASSERT_EQUALS(node->getNext(), nullptr);
        delete node;
    }

    void TestNameNodePrint()
    {
        NameNode *node = new NameNode("John", 20);
        TS_ASSERT_EQUALS(node->getName(), "John");
        TS_ASSERT_EQUALS(node->getAge(), 20);
        TS_ASSERT_EQUALS(node->getNext(), nullptr);
        delete node;
    }

    void TestNameNodeDestructor()
    {
        NameNode *node = new NameNode("John", 20);
        TS_ASSERT_EQUALS(node->getName(), "John");
        TS_ASSERT_EQUALS(node->getAge(), 20);
        TS_ASSERT_EQUALS(node->getNext(), nullptr);
        delete node;
    }

    void TestNameListConstructor()
    {
        NameList *list = new NameList();
        TS_ASSERT_EQUALS(list->getHead(), nullptr);
        TS_ASSERT_EQUALS(list->getTail(), nullptr);
        delete list;
    }

    void TestNameListPushFront()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        list->push_front(node);
        TS_ASSERT_EQUALS(list->getHead(), node);
        TS_ASSERT_EQUALS(list->getTail(), node);
        delete list;
    }

    void TestNameListPushBack()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        list->push_back(node);
        TS_ASSERT_EQUALS(list->getHead(), node);
        TS_ASSERT_EQUALS(list->getTail(), node);
        delete list;
    }

    void TestNameListPrint()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        list->push_back(node);
        list->print();
        TS_ASSERT_EQUALS(list->getHead(), node);
        TS_ASSERT_EQUALS(list->getTail(), node);
        delete list;
    }

    void TestNameListDestructor()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        list->push_back(node);
        delete list;
    }

    void TestNameNodeSetNext()
    {
        NameNode *node = new NameNode("John", 20);
        NameNode *node2 = new NameNode("John", 20);
        node->setNext(node2);
        TS_ASSERT_EQUALS(node->getNext(), node2);
        delete node;
        delete node2;
    }

    void TestNameListPushFrontElse()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        NameNode *node2 = new NameNode("John", 20);
        list->push_front(node);
        list->push_front(node2);
        TS_ASSERT_EQUALS(list->getHead(), node2);
        TS_ASSERT_EQUALS(list->getTail(), node);
        delete list;
    }

    void TestNameListPushBackElse()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        NameNode *node2 = new NameNode("John", 20);
        list->push_back(node);
        list->push_back(node2);
        TS_ASSERT_EQUALS(list->getHead(), node);
        TS_ASSERT_EQUALS(list->getTail(), node2);
        delete list;
    }

    void TestNameListSetTail()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        NameNode *node2 = new NameNode("John", 20);
        list->push_back(node);
        list->push_back(node2);
        list->setTail(node);
        TS_ASSERT_EQUALS(list->getHead(), node);
        TS_ASSERT_EQUALS(list->getTail(), node);
        delete list;
    }

    void TestNameListSetHead()
    {
        NameList *list = new NameList();
        NameNode *node = new NameNode("John", 20);
        NameNode *node2 = new NameNode("John", 20);
        list->push_back(node);
        list->push_back(node2);
        list->setHead(node2);
        TS_ASSERT_EQUALS(list->getHead(), node2);
        TS_ASSERT_EQUALS(list->getTail(), node2);
        delete list;
    }
};

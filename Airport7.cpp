#include "Airport7.h"

//Class functions for MyNode Class
MyNode::MyNode(int v)
{
    val = v;
    next = NULL;
}

MyNode::MyNode(int v, MyNode *n)
{
    val = v;
    next = n;
}

void MyNode::setVal(int v)
{
    val = v;
}

int MyNode::getVal()
{
    return val;
}

void MyNode::setNext(MyNode *n)
{
    next = n;
}

MyNode *MyNode::getNext()
{
    return next;
}

//Class functions for MyList Class
MyList::MyList()
{
    head = NULL;
}

void MyList::show()
{
    MyNode *temp = head;

    if (temp == NULL)
        printf("(empty)");

    while (temp != NULL){
        
        printf("%d, ", temp->getVal());
        temp = temp->getNext();
    }

    printf("\n");
}

void MyList::insert(int v)
{
    MyNode *newNode = new MyNode(v);

    if(head == NULL){
        head = newNode;
    }
    else {
        MyNode *temp = head;
        
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }

        temp->setNext(newNode);
    }
}

void MyList::remove(int v)
{
    MyNode *curr = head;
    MyNode *prev = NULL;

    if (curr != NULL && curr->getVal() == v){
        head = curr->getNext();
        delete curr;
        return;
    }

    while (curr->getVal() != v && curr != NULL)
    {
        prev = curr;
        curr = curr->getNext();
    }

    if (curr == NULL) {
        return;
    }
    else {
        prev->setNext(curr->getNext());
        delete curr;
    }

}

void MyList::clear()
{
    MyNode *curr = head;
    MyNode *temp;

    while(curr != NULL)
    {
        temp = curr->getNext();
        delete curr;
        curr = temp;
    }

    head = NULL;
}

int MyList::getListLength()
{
    MyNode *temp = head;
    int length = 0;

    while (temp != NULL)
    {
        length++;
        temp = temp->getNext();
    }

    return length;
}

int MyList::getNthValue(int n)
{
    MyNode *temp = head;
    int length = 0;

    while (temp != NULL && length != n)
    {
        length ++;
        temp = temp->getNext();
    }

    return temp->getVal();
}

void MyList::addToFrontOfList(int v)
{
    MyNode *temp = new MyNode(v);

    temp->setNext(head);
    head = temp;
}

int MyList::getValueAtFrontOfList()
{
    return head->getVal();
}

void MyList::removeValueFromFrontOfList()
{
    MyNode *temp = head;

    head = head->getNext();
    delete temp;
}
bool MyList::isListEmpty()
{
    if(head == NULL){
        return true;
    }
    else {
        return false;
    }
}

//Class functions for the Airport Class
Airport::Airport()
{
    adjecency = new MyList;
    visited = false;
    previous = -1;
}

void Airport::setVisitedFalse()
{
    visited = false;
}

void Airport::setVisitedTrue()
{
    visited = true;
}

bool Airport::visitedStatus()
{
    return visited;
}

void Airport::setPrevious(int v)
{
    previous = v;
}

int Airport::getPrevious()
{
    return previous;
}

MyList *Airport::getList()
{
    return adjecency;
}

//Class functions for FileNode Class

FileNode::FileNode(char *f)
{
    filename = f;
    next = NULL;
}

FileNode::FileNode(char *f, FileNode *n)
{
    filename = f;
    next = n;
}

void FileNode::setName(char *f)
{
    filename = f;
}

char *FileNode::getName()
{
    return filename;
}

void FileNode::setNext(FileNode *n)
{
    next = n;
}

FileNode *FileNode::getNext()
{
    return next;
}

//Class functions for FileList Class
FileList::FileList()
{
    head = NULL;
}

void FileList::insert(char *n)
{
    FileNode *newNode = new FileNode(n);

    if(head == NULL){
        head = newNode;
    }
    else {
        FileNode *temp = head;
        
        while (temp->getNext() != NULL)
        {
            temp = temp->getNext();
        }

        temp->setNext(newNode);
    }
}

void FileList::remove(char *n)
{
    FileNode *curr = head;
    FileNode *prev = NULL;
    char *firstn = curr->getName();

    if (curr != NULL && strcmp(n, firstn) == 0){
        head = curr->getNext();
        delete curr;
        return;
    }

    while (strcmp(n, firstn) != 0 && curr != NULL)
    {
        prev = curr;
        curr = curr->getNext();
        firstn = curr->getName();
    }

    if (curr == NULL) {
        return;
    }
    else {
        prev->setNext(curr->getNext());
        delete curr;
    }
}

bool FileList::nameSearch(char *n)
{
    FileNode *temp = head;

    while(temp != NULL)
    {
        char *cmp = temp->getName();

        if (strcmp(cmp, n) == 0)
            return true;
        
        temp = temp->getNext();
    }

    return false;
}


#include <cstdio>
#include <cstring>
#include <cstdlib>

class MyNode
{
 private: 
    int val;
    MyNode *next;
 public: 
    MyNode(int v);
    MyNode(int v, MyNode *n);

    void setVal(int v);
    int getVal();
    void setNext(MyNode *n);
    MyNode *getNext();
};

class MyList
{
 private:
    MyNode *head;
 public: 
    MyList();

    void show();
    void insert(int v); // Inserts at the back of list
    void remove(int v);
    void clear();
    int getListLength();
    int getNthValue(int n);

    // Queue/Stack operations
    void addToFrontOfList(int v);
    int getValueAtFrontOfList();
    void removeValueFromFrontOfList();
    bool isListEmpty();

};

class Airport
{
 private: 
    MyList *adjecency;
    bool visited;
    int previous;
 public:
    Airport();

    void setVisitedFalse();
    void setVisitedTrue();
    bool visitedStatus();
    void setPrevious(int v);
    int getPrevious();
    MyList *getList();
};

class FileNode
{
   private:
      char *filename;
      FileNode *next;
   public:
      FileNode(char *f);
      FileNode(char *f, FileNode *n);

      void setName(char *f);
      char *getName();
      void setNext(FileNode *n);
      FileNode *getNext();
};

class FileList
{
   private:
      FileNode *head;
   public:
      FileList();

      void insert(char *n);
      void remove(char *n);
      bool nameSearch(char *n);
};
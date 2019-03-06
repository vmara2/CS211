#include "Airport7.h"

class TravelNetwork
{
 private:
   // Create the Data Members for the Travel Network here
    int size;
    int inUse;
    Airport *network;
    FileList *files;
    MyList *airportQueue;
    MyList *pathStack;
 public:
  
 // Use a constructor to initialize the Data Members for Travel Network
 TravelNetwork()
 {
    size = 11;
    inUse = 0;
    network = new Airport[size];
    files = new FileList;
    airportQueue = new MyList;
    pathStack = new MyList;
 }
 
 
 // Depth First Search algorithm that finds a path to from a to b
 bool dfs(int a, int b)
 {
   MyList *alist = network[a].getList();

   for(int i = 0; i < alist->getListLength(); i++)
   {
     int c = alist->getNthValue(i);
     if (c == b){
       return true;
     }

     if (network[c].visitedStatus() == false){
       network[c].setVisitedTrue();

       if(dfs(c,b) == true){
         return true;
       }
     }
   }

   return false;
 }

// Helper function to DFS
 void depthFirstSearchHelper(int x, int y)
 {
   for(int i = 0; i < size; i++)
   {
     network[i].setVisitedFalse();
   }

   if (dfs(x,y) == true) // Recursive call to dfs()
   {
     printf( "You can get from airport %d to airport %d in one or more flights\n",x,y);
   }
   else
   {
     printf("You can NOT get from airport %d to airport %d in one or more flights\n",x,y);
   }
 }

 bool bfs(int b)
 {
   while (airportQueue->isListEmpty() == false)
   {
     int a = airportQueue->getValueAtFrontOfList();
     airportQueue->removeValueFromFrontOfList();

     MyList *clist = network[a].getList();

     for (int i = 0; i < clist->getListLength() ; i++){
       int c = clist->getNthValue(i);

       if (network[c].getPrevious() == -1){
         network[c].setVisitedTrue();
         network[c].setPrevious(a);
         
         if (c == b)
          return true;
          
         airportQueue->insert(c);
       }
     }
   }
   return false;
 }

 MyList *breadthFirstSearch(int x, int y)
 {
   for(int i = 0; i < size; i++){
     network[i].setVisitedFalse();
     network[i].setPrevious(-1);
   }

   airportQueue->clear();
   airportQueue->insert(x);
   
   if (bfs(y) == false){
     printf("You can NOT get from airport %d to airport %d in one or more flights\n",x,y);
     pathStack->clear();
     return pathStack;
   }
   else {
     printf( "You can get from airport %d to airport %d in one or more flights\n",x,y);
     pathStack->clear();

     int currentAirport = y;
     pathStack->addToFrontOfList(y);

     do {
       currentAirport = network[currentAirport].getPrevious();
       pathStack->addToFrontOfList(currentAirport);
     } while (currentAirport != x);

     return pathStack;

   }
 }

 // The main loop for reading in input
 void processCommandLoop (FILE* inFile)
 {
  char  buffer[300];
  char* input;

  input = fgets ( buffer, 300, inFile );   // get a line of input
    
  // loop until all lines are read from the input
  while (input != NULL)
  {
    // process each line of input using the strtok functions 
    char* command;
    command = strtok (input , " \n\t");

    printf ("*%s*\n", command);
    
    if ( command == NULL )
      printf ("Blank Line\n");
 
    else if ( strcmp (command, "q") == 0) 
      exit(1);
     
    else if ( strcmp (command, "?") == 0) 
      showCommands();
    
    else if ( strcmp (command, "s") == 0)
      doShort();
    
    else if ( strcmp (command, "t") == 0) 
      doTravel();
     
    else if ( strcmp (command, "r") == 0) 
      doResize();

    else if ( strcmp (command, "i") == 0) 
      doInsert();

    else if ( strcmp (command, "d") == 0) 
      doDelete();

    else if ( strcmp (command, "l") == 0) 
      doList();

    else if ( strcmp (command, "f") == 0) 
      doFile();

    else if ( strcmp (command, "#") == 0) 
      ;
     
    else
      printf ("Command is not known: %s\n", command);
     
    input = fgets ( buffer, 300, inFile );   // get the next line of input

  }
 }
 
 void showCommands()
 {
   printf ("The commands for this project are:\n");
   printf ("  q \n");
   printf ("  ? \n");
   printf ("  # \n");
   printf ("  s <int1> <int2> \n");
   printf ("  t <int1> <int2> \n");
   printf ("  r <int> \n");
   printf ("  i <int1> <int2> \n");
   printf ("  d <int1> <int2> \n");
   printf ("  l \n");
   printf ("  f <filename> \n");
 }

 void doShort()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   printf ("Performing the Shortest Path Command from %d to %d\n", 
            val1, val2);
   
   breadthFirstSearch(val1, val2);
   printf("Shortest path from %d to %d: ", val1, val2);
   pathStack->show();
   printf("\n");
 }
 
 void doTravel()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   
   printf ("Performing the Travel Command from %d to %d\n", 
            val1, val2);
   
   depthFirstSearchHelper(val1, val2);
 }
 
 void doResize()
 {
   int val1 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );

   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   if(val1 <= 0){
     printf("The size you are trying to resize to is too small!");
     return;
   }
   
   printf ("Performing the Resize Command with %d\n", val1 );

   for (int i = 0; i < size; i++){
     MyList *deleteList = network[i].getList();

     deleteList->clear();
   }

   delete[] network;

   size = val1 + 1;
   inUse = 0;
   network = new Airport[size];
 }
 
 void doInsert()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   if (val1 < 1 || val1 > (size - 1)){
     printf ("Airport %d does not exist in the system!", val1);
     return;
   }

   if (val2 < 1 || val2 > (size - 1)){
     printf ("Airport %d does not exist in the system!", val2);
     return;
   }

   MyList *airportList = network[val1].getList();

   airportList->insert(val2);
 }
 
 void doDelete()
 {
   int val1 = 0;
   int val2 = 0;

   // get an integer value from the input
   char* next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val1 = atoi ( next );
   if ( val1 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }
   
   // get another integer value from the input
   next = strtok (NULL, " \n\t");
   if ( next == NULL )
   {
     printf ("Integer value expected\n");
     return;
   }
   val2 = atoi ( next );
   if ( val2 == 0 && strcmp (next, "0") != 0)
   {
     printf ("Integer value expected\n");
     return;
   }

   if (val1 < 1 || val1 > (size - 1)){
     printf ("Airport %d does not exist in the system!", val1);
     return;
   }

   if (val2 < 1 || val2 > (size - 1)){
     printf ("Airport %d does not exist in the system!", val2);
     return;
   }

   MyList *airportList = network[val1].getList();

   airportList->remove(val2);

   airportList->show();

 }
 
 void doList()
 {
   for (int i = 1; i < size; i++){
     printf("Airport %d: ", i);
     MyList *displayList = network[i].getList();
     displayList->show();
   }
 }
 
 void doFile()
 {
   FILE *pFile;
   // get a filename from the input
   char* fname = strtok (NULL, " \n\t");
   if ( fname == NULL )
   {
     printf ("Filename expected\n");
     return;
   }

   if (files->nameSearch(fname) == true)
   {
     printf("File is already in use!\n");
     return;
   }
   
   printf ("Performing the File command with file: %s\n", fname);
   
   // next steps:  (if any step fails: print an error message and return ) 
   //  1. verify the file name is not currently in use
   //  2. open the file using fopen creating a new instance of FILE*
   //  3. recursively call processCommandLoop() with this new instance of FILE* as the parameter
   //  4. close the file when processCommandLoop() returns

   pFile = fopen(fname, "r");

   if (pFile == NULL)
   {
       printf("ERROR FILE NOT READ\n");
       return;
   }

   files->insert(fname);

   this->processCommandLoop(pFile);

   fclose(pFile);

   files->remove(fname);

 }
};

int main (int argc, char** argv)
{
  // set up the variable inFile to read from standard input
  FILE* inFile = stdin;

  // set up the data needed for the airport adjcency list
  TravelNetwork airportData;
   
  // call the method that reads and parses the input
  airportData.showCommands();
  printf ("\nEnter commands at blank line\n");
  printf ("    (No prompts are given because of f command)\n");
  airportData.processCommandLoop (inFile);
   
  printf ("Goodbye\n");
  return 1;
 }
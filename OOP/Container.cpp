// Link: http://oj.csie.ndhu.edu.tw/problem/PR110-2Q10
#include <iostream>

using namespace std;

class container
{
private:
    int *box; // *box is a pointer that is pointing at an array
    int len;
    int index;                // holding the index of the last value of the array
    static int count;         /* static variables mean that because in the main function we could use the class with different names and changes in one class
             //will not affect the others classes but for static variables any changes that made to those variables all classes will experience that */
    bool reallocate(int size) // size is a bigger size of the new array, bigger than the that of the original
    {
        int *a = new int[size];       // creating an array; a has the first index of the array which is 0
        for (int i = 0; i < len; i++) // i is short for index
        {
            a[i] = box[i]; // this is for copying, because box is pointing at an array so box would work like an array
        }
        delete[] box; // delete data of the old array
        box = a;      // address of box
        len = size;   // because size is not available outside the function
        return true;  // true is same as 1
    }
    static void increase()
    {
        count++; // count is the number of objects
    }
    static void decrease()
    {
        count--; // count is the number of objects
    }

public:
    container(void) 
    {
      box = NULL;
      len = 0;
      index = -1;
        increase();
    } // the index is the index of the array and initially when it has nothing the index is -1 and if it has the first thing
    // it will increment by 1
    container(int len)
    {
        box = new int[len];
      	len = len;
      	index = -1;
      	increase();
    }
    ~container() // destructor
    {
        decrease();
    }
    int getLen()
    {
        return len;
    }
    int getIndex()
    {
        return index;
    }
    void traversal()
    {
        if (index == -1)
        {
            cout << "empty\n";
        }
        else
        {
            for (int i = 0; i <= index; i++)
            {
                cout << box[i] << " ";
            }
            cout << "\n";
        }
    }
    bool push(int data) // just put one only
    {
        if (index == len - 1) // checking the array is full or not
        {
          	if(len == 0)
              len = 1;
            // reallocate(len * 2) if write like this, it will return true so basically it is meaningless, that is why we need this
            if (!reallocate(len * 2))
                return false; //! not -> not true -> false
        }
        box[++index] = data;
        return true;
    }
    int pop()
    {
        if (index == -1)
            return 0;
        int a;
        a = box[0];
        for (int i = 0; i < index; i++)
        {
            box[i] = box[i + 1];
        }
      index--;
        return a;
    }
    static int getCount()
    {
        return count;
    }
};
int container::count = 0; // have to assign static values outside with these syntax

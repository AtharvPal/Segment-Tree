# Segment-Tree
A general purpose Segment Tree library

This library implements a general purpose Segment Tree data structure. Operations include query() and update(). 

INSTRUCTIONS - 

1. Include the heaader file "SEGTREE.h" in your header files directory and also in your code.

2. To construct the segment tree you need to initalize an object of SEGMENT_TREE and specify the following - 
    a. The datatype of the array/ vector.
    b. The array/ vector of which you need to construct the tree.
    c. An extravalue ehich is used to fill the remaining nodes of the segment tree.
    d. A comparison function that detemines how the parent node is filled wrt left and right child nodes.
 
 An exmaple of creating a segement tree of type double with sum queries-
    double sum(double a, double b)
    {   return a+b; }
    double extravalue = 0.0;
    vector<double> arr1= = {1.1,2.2,-5.4};
    double arr2[] = {1.1,2.2,-5.4};
    int size = 3;
    with vector - SEGMENT_TREE<double> s(arr1,extravalue,sum);
    with array - SEGMENT_TREE<double> s(arr2,size,extravalue,sum);
 
 3.  Functions include - 
    a. query(int leftindex, int rightindex) - returns a value according to comparison function; returns extravalue if invalid range.
    b. update(int index, datatype value) - updates the position index in the original array by value; leaves everything unchanged if invalid range.

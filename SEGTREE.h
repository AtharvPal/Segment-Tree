#include <bits/stdc++.h>
using namespace std;
template<class T>
class SEGMENT_TREE
{
    vector<T> A;
    int max_size,curr_size;
    T extra_val;
    T (*comb)(T ob1, T ob2);
    int size_tree(int n)
    {
        int p2 = 1;
        while( p2 < n)
            p2 = p2 << 1;
        return 2*p2 - 1;
    }
public:
    SEGMENT_TREE(T arr[], int n, T extra, T (*comp)(T ob1, T ob2))
    {
        int size=n;
        this->comb=comp;
        max_size=size_tree(size);
        curr_size=size;
        extra_val=extra;
        for(int i=0;i<max_size;i++)
            A.push_back(extra);
        vector<T> v;
        for(int i=0;i<size;i++)
            v.push_back(arr[i]);
        segtree(v,0,size-1,0);
    }
    SEGMENT_TREE(vector<T> &arr, T extra, T (*comp)(T ob1, T ob2))
    {
        int size=arr.size();
        this->comb=comp;
        max_size=size_tree(size);
        curr_size=size;
        extra_val=extra;
        for(int i=0;i<max_size;i++)
            A.push_back(extra);
        segtree(arr,0,size-1,0);
    }
    void segtree(vector<T> &v, int s, int e, int spos)
    {
        if(s>e)
            return;
        if(s==e)
        {
            A[spos]=v[s];
            return;
        }
        int mid=s+(e-s)/2;
        segtree(v,s,mid,2*spos+1);
        segtree(v,mid+1,e,2*spos+2);
        A[spos]=comb(A[2*spos+1],A[2*spos+2]);
    }
    void update(int s, int e, int spos, int pos, T val)
    {
        if(s>e)
            return;
        if(s==e)
        {
            A[spos]=val;
            return;
        }
        int mid=s+(e-s)/2;
        if(pos<=mid)
            update(s,mid,2*spos+1,pos,val);
        else
            update(mid+1,e,2*spos+2,pos,val);
        A[spos]=comb(A[2*spos+1],A[2*spos+2]);
    }
    void update(int pos, T val)
    {
        if(pos<0 || pos>=curr_size)     ///Invalid cases
            return;
        update(0,curr_size-1,0,pos,val);
    }
    T query(int l, int r, int s, int e, int spos)
    {
        if(s>r || l>e)
            return extra_val;
        if(s>=l && e<=r)
            return A[spos];
        int mid=s+(e-s)/2;
        return comb(query(l,r,s,mid,2*spos+1),query(l,r,mid+1,e,2*spos+2));
    }
    T query(int l, int r)
    {
        if(l>r || l<0 || r<0 || l>=curr_size || r>=curr_size)   ///Invalid cases
            return extra_val;
        return query(l,r,0,curr_size-1,0);
    }
};
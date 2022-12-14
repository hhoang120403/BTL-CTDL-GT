#include<bits/stdc++.h>
#ifndef __Vector__h__
#define __Vector__h__
using namespace std;

template<class T>
class vector_iterator;

template <class T>
class vector_reverse_iterator;

template<class T>
class Vector{
    private:
        unsigned int cap,n;
        T *V;
    public:
        Vector(){
        	cap = n = 0;
			V = 0;
		}
        Vector(int num);
        Vector(int k,T x);
        Vector& operator=(Vector a);
        ~Vector(){
        	if(V) delete[] V;
		}
        int capacity();
        int size();
        bool empty();
        void pop_back();
        T& back();
        void push_back(T x);
        T& operator[](int k);
        T& at(int k);
        void resize(int newsize,T x);
        void insert(int k, T x);
        void erase(int k);
        void extend(int newcap);

        // Bo lap iterator
        typedef T *iterator;
		typedef vector_reverse_iterator<T> reverse_iterator;
        iterator begin(){
        	return V;
		}
        iterator end(){
        	return (V + n);
		}
        reverse_iterator rbegin(){
        	return V + (n-1);
		}
        reverse_iterator rend(){
        	return V - 1;	
		}
};
#endif

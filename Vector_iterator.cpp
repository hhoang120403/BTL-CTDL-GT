#include"Vector.h"
#include"Vector.cpp"

#ifndef __Vector_iterator__cpp__
#define __Vector_iterator__cpp__

template<class T>
class vector_iterator{
	T *curr; // con tro tro vao phan tu hien tai
	public:
		vector_iterator(T *p=NULL){
			curr = NULL;
		}
		T *getcurr(){
			return curr;
		}
		T &operator*(){
			return *curr;
		}
		vector_iterator<T> &operator=(vector_iterator<T> p){
			this->curr = p.getcurr();
			return *this;
		}
		bool operator!=(vector_iterator<T> p){
			return curr != p.getcurr();
		}
		vector_iterator<T> operator++(){
			curr++;
		}
};

template <class T>
class vector_reverse_iterator{
	T *curr;
	public:
		vector_reverse_iterator(T *p=NULL){
			curr = p;
		}
		T *getcurr(){
			return curr;
		}
		T &operator*(){
			return *curr;
		}
		vector_reverse_iterator<T> &operator=(vector_reverse_iterator<T> p){
			this->curr = p.getcurr();
			return *this;
		}
		bool operator!=(vector_reverse_iterator<T> p){
			return curr != p.getCurr();
		}
		vector_reverse_iterator<T> operator++(){
			return --curr;
		}
};
#endif

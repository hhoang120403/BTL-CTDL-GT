#include"Vector.h"
#ifndef __Vector__cpp__
#define __Vector__cpp__

template<class T>
Vector<T>::Vector(int num){
    cap = n = num;
    V = new T[n];
}

template<class T>
Vector<T>::Vector(int k, T x){
    cap = n = k;
    V = new T[k];
    for(int i=0;i<k;i++) V[i] = x;
}

template<class T>
Vector<T>& Vector<T>::operator=(Vector a){
    cap = a.capacity();
    n = a.size();
    if(cap) V = new T[cap];
    for(int i=0;i<n;i++){
        V[i] = a[i];
    }
    return *this;
}

template<class T>
void Vector<T>::extend(int newcap){
    if(newcap < cap) return;
    cap = newcap;
    T *temp = new T[cap];
    for(int i=0;i<n;i++){
        temp[i] = V[i];
    }
    if(V) delete[] V;
    V = temp;
}

template<class T>
int Vector<T>::capacity(){
	return cap;
}

template<class T>
int Vector<T>::size(){
    return n;
}

template<class T>
bool Vector<T>::empty(){
    return n==0;
}

template<class T>
void Vector<T>::pop_back(){
    if(n) n--;
}

template<class T>
T& Vector<T>::back(){
    return V[n-1];
}

template<class T>
void Vector<T>::push_back(T x){
    if(n == cap) extend(cap*2 + 5);
    V[n++] = x;
}

template<class T>
T& Vector<T>::operator[](int k){
	if(k<0 || k>=n){
		k = 0;
	}
    return V[k];
}

template<class T>
T& Vector<T>::at(int k){
	if(k<0 || k>=n){
		k = 0;
	}
    return V[k];
}

template<class T>
void Vector<T>::resize(int newsize,T x){
	if(newsize>cap) extend(newsize);
	for(int i=n;i<newsize;i++) V[i] = x;
	n = newsize;
}

template<class T>
void Vector<T>::insert(int k, T x){
	if(k<0 || k>=n) return;
    if(cap == n) extend(cap*2 + 5);
    for(int i=n-1;i>=k;i--){
        V[i+1] = V[i];
    }
    V[k] = x;
    n++;
}

template<class T>
void Vector<T>::erase(int k){
	if(k<0 || k>=n) return;
    for(int i=k+1;i<=n;i++){
    	V[i-1] = V[i]; 
	}
    n--;
}

#endif


#ifndef __SortedList_h__
#define __SortedList_h__

#include "Lista.hpp"

using namespace std;

template <typename T> 
class SortedList{
public:
	SortedList();
	void add(T element);
	int size();
	int position (T element);
	T get();
	T getInPosition(int position);
	bool isEmpty();

private: 
	Lista<T> sortedList;
	int findPosition(T element);
	int binarySearch(int begin, int end, T element);

};

template <typename T> 
SortedList<T>::SortedList() {
	
}

template <typename T>
void SortedList<T>::add(T element) {
	int position = findPosition(element);
	sortedList.adicionaNaPosicao(element, position);
	
}

template <typename T>
int SortedList<T>::findPosition(T element) {
	int position = binarySearch(0, sortedList.tamanho()-1, element);
	return position;
}

template <typename T> 
int SortedList<T>::binarySearch(int begin, int end, T element) {
	if(begin >= end) {
		if(sortedList.elementoNaPosicao(begin) < element) { 
			if(sortedList.estaVazia()) {
				return begin;
			}
			return ++begin;
		}
		return begin;
	}
	int average = (end - begin)/2 + begin;
	if(sortedList.elementoNaPosicao(average) < element) {
		return binarySearch(average + 1, end, element);
	} else if(sortedList.elementoNaPosicao(average) > element){
		return binarySearch(0, average-1, element);
	} else {
		return average;  
	}

}

template <typename T> 
int SortedList<T>::size() {
	return sortedList.tamanho();
}

template <typename T>
T SortedList<T>::get() {
	return sortedList.retira();
}

template <typename T>
T SortedList<T>::getInPosition(int position) {
	return sortedList.retiraDaPosicao(position);
}

template <typename T>
int SortedList<T>::position(T element) {
	return sortedList.posicao(element);
}

template <typename T>
bool SortedList<T>::isEmpty() {
	return sortedList.estaVazia();
}

#endif
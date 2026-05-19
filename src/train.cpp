// Copyright 2021 NNTU-CS
#include "train.h"

Train::Train() : countOp(0), first(nullptr) {}

void Train::addCar(bool light) {
  Car *newCar = new Car{light, nullptr, nullptr};
  
  if (first == nullptr) {
    first = newCar;
    first->next = first;
    first->prev = first;
  } else {
    newCar->next = first;
    newCar->prev = first->prev;
    first->prev->next = newCar;
    first->prev = newCar;
  }
}

int Train::getLength() {
  if (first == nullptr) return 0;
  if (first->next == first) return 1;
  
  countOp = 0;
  
  // Запоминаем начальное состояние света
  bool initialState = first->light;
  
  // Включаем свет в начальном вагоне (помечаем его)
  first->light = true;
  
  // Переходим в следующий вагон
  Car *current = first->next;
  countOp++;
  
  int length = 1;
  
  // Идем по кругу, выключая свет во всех вагонах
  while (current != first) {
    if (current->light == true) {
      current->light = false;
    }
    
    current = current->next;
    countOp++;
    length++;
  }
  
  // Восстанавливаем начальное состояние первого вагона
  first->light = initialState;
  
  return length;
}

int Train::getOpCount() {
  return countOp;
}

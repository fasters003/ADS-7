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

  first->light = true;
  Car *current = first->next;
  countOp++;

  while (current->light == false) {
    current = current->next;
    countOp++;
  }

  current->light = false;
  current = first;
  countOp++;

  int length = 1;
  while (current->light == true) {
    current = current->next;
    countOp++;
    length++;
  }

  return length;
}

int Train::getOpCount() {
  return countOp;
}

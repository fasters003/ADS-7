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

  first->light = false;
  Car *current = first;

  int length = 0;
  do {
    current = current->next;
    countOp++;
    length++;
  } while (current != first);

  do {
    current->light = true;
    current = current->next;
    countOp++;
  } while (current != first);

  int count = 0;
  while (current->light == false) {
    current = current->next;
    countOp++;
    count++;
  }

  current->light = false;

  return length;
}

int Train::getOpCount() {
  return countOp;
}

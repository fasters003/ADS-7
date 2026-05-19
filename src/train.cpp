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

  countOp = 0;
  first->light = true;
  Car *current = first;

  while (true) {
    int stepsToNextLight = 0;

    do {
      current = current->next;
      countOp++;
      stepsToNextLight++;
    } while (!current->light);

    current->light = false;

    Car *temp = current;
    for (int i = 0; i < stepsToNextLight; i++) {
      temp = temp->prev;
      countOp++;
    }

    if (!temp->light) {
      return stepsToNextLight;
    }
    current = temp;
  }
}

int Train::getOpCount() {
  return countOp;
}

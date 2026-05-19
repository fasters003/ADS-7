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
    int length = 0;

    first->light = true;

    Car *current = first->next;
    countOp++;

    length = 1;
    while (current->light == false) {
        current = current->next;
        countOp++;
        length++;
    }

    if (current == first) {
        current = first;
        for (int i = 0; i < length; i++) {
            current->light = false;
            current = current->next;
            countOp++;
        }
    } else {
        current->light = false;
        current = current->next;
        countOp++;

        while (current != first) {
            if (current->light == true) {
                current->light = false;
            }
            current = current->next;
            countOp++;
            length++;
        }

        first->light = false;
    }

    return length;
}

int Train::getOpCount() {
    return countOp;
}

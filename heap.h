//
// Created by Manju Muralidharan on 10/19/25.
//

#ifndef HEAP_H
#define HEAP_H

#include <iostream>
using namespace std;

struct MinHeap {
    int data[64];
    int size;

    MinHeap() { size = 0; }

    void push(int idx, int weightArr[]) {
        // TODO: insert index at end of heap, restore order using upheap()
        if (size>= 64) {
            return;
        }
        data[size] =idx;
        upheap(size, weightArr);
        size++;
    }

    int pop(int weightArr[]) {
        // TODO: remove and return smallest index
        // Replace root with last element, then call downheap()
        if (size==0) {
            return-1;
        }
        int top = data[0];
        data[0] = data[size-1];
        size--;
        if (size>0) {
            downheap(0, weightArr);
        }
        return top; // placeholder
    }

    void upheap(int pos, int weightArr[]) {
        // TODO: swap child upward while smaller than parent
        while (pos>0) {
            int parent = (pos-1)/2;
            int curIdx = data[pos];
            int parIdx = data[parent];
            if (weightArr[curIdx] < weightArr[parIdx]||
                weightArr[curIdx] == weightArr[parIdx] && curIdx < parIdx)
                {
                    int temp = data[pos];
                    data[pos] = data[parent];
                    data[parent] = temp;
                    pos = parent;
                } else break;
        }
    }

    void downheap(int pos, int weightArr[]) {
        // TODO: swap parent downward while larger than any child
        while (true) {
            int left = (pos*2)+1;
            int right = (pos*2)+2;
            int smallest = pos;
            if (left<size) {
                int lIdx = data[left], sIdx = data[smallest];
                if (weightArr[lIdx] < weightArr[sIdx] ||
                   (weightArr[lIdx] == weightArr[sIdx] && lIdx < sIdx)) {
                    smallest = left;
                   }
            }
            if (right < size) {
                int rIdx = data[right], sIdx = data[smallest];
                if (weightArr[rIdx] < weightArr[sIdx] ||
                   (weightArr[rIdx] == weightArr[sIdx] && rIdx < sIdx)) {
                    smallest = right;
                   }
            }

            if (smallest != pos) {
                int tmp = data[pos]; data[pos] = data[smallest]; data[smallest] = tmp;
                pos = smallest;
            } else break;


        }
    }
};

#endif
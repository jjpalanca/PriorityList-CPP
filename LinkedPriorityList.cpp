/*
 * LinkedPriorityList.cpp
 *
 *  Created on: March 8, 2019
 *      Author: Rick Mercer and Jessmer John Palanca
 *
 * This class represents one implementation of the abstract
 * base class PriorityList. Like any container, there
 * are insert and remove functions. Indexes represent
 * priorities and the priorities can change in several ways.
 * The element at index 0 has the highest priority.
 * The element at size()-1 has the lowest priority.
 */
#include "PriorityList.h"
#include <stdexcept> // for std::invalid_argument(string)
#include <memory>    // for std::shared_ptr<T>
#include <string>    // for std::to_string

using namespace std;

template<typename Type>
class LinkedPriorityList : public PriorityList<Type> {

private:
    struct Node {
        Type data;
        std::shared_ptr<Node> next;

        // You may not need this Node constructor
        explicit Node(Type element) {
            data = element;
            next = nullptr;
        }

        Node(Type element, std::shared_ptr<Node> nextRef) {
            data = element;
            next = nextRef;
        }
    };

    std::shared_ptr<Node> first;
    int n;

public:

    // Create an empty list with zero elements
    LinkedPriorityList() {
        first = nullptr;
        n = 0;
    }

    // Add all functions found in PriorityList.h except
    // ~PriorityList. Consider copying the function headings
    // and comments from PriorityList.h. Remove virtuals
    // and = 0;.  Replace ;s with a function body.

    /*
     * Return the number of elements in this PriorityList
     */
    int size() const {
        return n;
    }

    /*
     * Return true if there are zero elements in this PriorityList
     */
    bool isEmpty() const {
        return n == 0;
    }

    /*
     * If possible, return a reference to the element at the
     * given index. If index is out of the valid range of
     * 0..size()-1, throw a std::invalid_argument(string).
     * When size is 3, the only possible values for index
     * are 0, 1, and 2.
     *
     * throw std::invalid_argument(string)
     */
    Type getElementAt(int index) const {
        if (index < 0 or index > this->size() - 1) {
            throw invalid_argument("getElementAt: index = " + to_string(index));
        } else {
            shared_ptr<Node> curr = first;
            int i = 0;
            while (i < index) {
                i++;
                curr = curr->next;
            }
            return curr->data;
        }
    }

    /*
     * If possible, insert the element at the given index.
     * If index is out of the valid range of 0..size(),
     * throw a std::invalid_argument(string). When size is 3,
     * the only possible values for index are 0, 1, 2, AND 3
     * because you can add an element as the new last.
     *
     * throw std::invalid_argument(string)
     */
    void insertElementAt(int index, const Type &el) {
        if (index < 0 or index > this->size()) {
            throw invalid_argument("insertElementAt: index = " + to_string(index));
        } else {

            shared_ptr<Node> curr = first;
            shared_ptr<Node> newNode(new Node(el));
            if (n == 0) {
                first = newNode;
            } else {
                int i = 0;

                if (index == 0) {
                    newNode->next = first;
                    first = newNode;
                } else {
                    while (i < index - 1) {
                        i++;
                        curr = curr->next;
                    }
                    newNode->next = curr->next;
                    curr->next = newNode;
                }
            }
            n++;
        }
    }

    /*
     * If possible, remove the element at the given index.
     * If index is out of the valid range of 0..size()-1,
     * throw std::invalid_argument(string). When size is 3,
     * the only possible values for index are 0, 1, and 2.
     *
     * throw std::invalid_argument(string)
     */
    void removeElementAt(int index) {
        if (index < 0 or index > this->size() - 1) {
            throw invalid_argument("removelementAt: index = " + to_string(index));
        } else {
            shared_ptr<Node> curr = first;
            shared_ptr<Node> prev = first;
            if (index == 0) {
                first = curr->next;
            } else {
                int i = 0;
                while (i < index - 1) {
                    i++;
                    prev = prev->next;
                }
                curr = prev->next;
                prev->next = curr->next;
            }
            n--;
        }
    }


    /*
     * If possible, swap the element located at index with
     * the element at index + 1.  An attempt to lower the
     * priority of an element at index size()-1 has no effect.
     * If index is out of the valid range of 0..size()-1,
     * throw std::invalid_argument(string). When size is 3,
     * the only possible values for index are 0, 1, and 2.
     *
     *  throw std::invalid_argument(string)
     */
    void lowerPriorityOf(int index) {
        if (index < 0 or index > this->size() - 1) {
            throw invalid_argument("lowerPriorityOf: index = " + to_string(index));
        }
        if (index == size() - 1) {
            return;
        } else {
            shared_ptr<Node> prev = first;
            shared_ptr<Node> curr = first;
            shared_ptr<Node> next = first;
            if (index == 0) {
                curr = first->next;
                first->next = curr->next;
                curr->next = first;
                first = curr;
            } else if (index < n) {
                int i = 0;
                while (i < index - 1) {
                    i++;
                    prev = prev->next;
                }
                curr = prev->next;
                next = curr->next;
                curr->next = next->next;
                next->next = curr;
                prev->next = next;
            }
        }
    }

    /*
     * If possible, swap the element located at index with
     * the element at index-1. An attempt to raise the
     * priority of the element at index 0 has no effect and
     * it must not throw an exceptopn.
     *
     * If index is out of the valid range of 0..size()-1,
     * throw std::invalid_argument(string). When size is 3,
     * the only possible values for index are 0, 1, and 2.
     *
     * throw std::invalid_argument(string)
     */
    void raisePriorityOf(int index) {
        if (index < 0 or index > this->size() - 1) {
            throw invalid_argument("raisePriorityOf: index = " + to_string(index));
        }
        if (n == 0) {
            return;
        } else if (n > 0) {
            shared_ptr<Node> prev1 = first;
            shared_ptr<Node> prev2 = first;
            shared_ptr<Node> next = first;
            if (index == 0) {
                return;
            } else if (index == 1) {
                prev2 = first->next;
                first->next = prev2->next;
                prev2->next = first;
                first = prev2;
            } else {
                int i = 0;
                while (i < index - 2) {
                    i++;
                    prev1 = prev1->next;
                }
                prev2 = prev1->next;
                next = prev2->next;
                prev2->next = next->next;
                next->next = prev2;
                prev1->next = next;
            }
        }
    }

    /*
     * If possible, move the element at the given index to
     * the end of this list. An attempt to move the element at
     * the largest possible index to the end  has no effect.
     * Do nothing.  Do not throw n excpetion.
     *
     * If the index is out of the valid range 0..size()-1
     * throw std::invalid_argument(string). When size is 3,
     * the only possible values for index are 0, 1, and 2.
     *
     * throw std::invalid_argument(string)
     */
    void moveToLast(int index) {
        if (index < 0 or index > this->size() - 1) {
            throw invalid_argument("moveToLast: index = " + to_string(index));
        } else {
            while (index < size() - 1) {
                lowerPriorityOf(index);
                index++;
            }
        }

    }

    /*
     * If possible, move the element at the given index to the
     * front. An attempt to move the top element to the top
     * has no effect. If the index is out of the valid range
     * of 0..size()-1, throw std::invalid_argument(string)
     *
     * When size is 3, the only possible values for index
     * are 0, 1, and 2.
     *
     * throw std::invalid_argument(string)
     */
    void moveToTop(int index) {
        if (index < 0 or index > this->size() - 1) {
            throw invalid_argument("moveToTop: index = " + to_string(index));
        } else {
            while (index >= 0) {
                raisePriorityOf(index);
                index--;
            }
        }
    }

    ~LinkedPriorityList() {}

};

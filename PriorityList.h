/*
 * PriorityList.h
 *
 *  Created on: Oct 20, 2018
 *      Author: mercer
 */
#ifndef PRIORITYLIST_H_
#define PRIORITYLIST_H_

/*
 * This class describes an abstract base class Priority to
 * store elements where indexes represent priorities and
 * the priorities can change in several ways. Like any
 * container, there are insert and remove functions. Indexes
 * represent priorities and the priorities can change in
 * several ways. The element at index 0 has the highest
 * priority, the element at size()-1 has the lowest priority
 *
 * This abstract class is designed to be implemented by
 * subclasses using different data structures such as linked
 * structures, arrays, or an existing container like vector.
 *
 * Execpt for the destructor ~LinkedPriorityList all members
 * are pure virtual functions. This means that each subclass
 * MUST implement every method, except the destructor.
 *
 * author: Rick Mercer
 *
 * <Type> The type of elements stored in this collection
 */
template<class Type>
class PriorityList {
    
public:
    /*
     * Return the number of elements in this PriorityList
     */
    virtual int size() const = 0;
    
    /*
     * Return true if there are zero elements in this PriorityList
     */
    virtual bool isEmpty() const = 0;
    
    /*
     * If possible, return a reference to the element at the
     * given index. If index is out of the valid range of
     * 0..size()-1, throw a std::invalid_argument(string).
     * When size is 3, the only possible values for index
     * are 0, 1, and 2.
     *
     * throw std::invalid_argument(string)
     */
    virtual Type getElementAt(int index) const = 0;
    
    /*
     * If possible, insert the element at the given index.
     * If index is out of the valid range of 0..size(),
     * throw a std::invalid_argument(string). When size is 3,
     * the only possible values for index are 0, 1, 2, AND 3
     * because you can add an element as the new last.
     *
     * throw std::invalid_argument(string)
     */
    virtual void insertElementAt(int index, const Type & el) = 0;
    
    /*
     * If possible, remove the element at the given index.
     * If index is out of the valid range of 0..size()-1,
     * throw std::invalid_argument(string). When size is 3,
     * the only possible values for index are 0, 1, and 2.
     *
     * throw std::invalid_argument(string)
     */
    virtual void removeElementAt(int index) = 0;
    
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
    virtual void lowerPriorityOf(int index) = 0;
    
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
    virtual void raisePriorityOf(int index) = 0;
    
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
    virtual void moveToLast(int index) = 0;
    
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
    virtual void moveToTop(int index) = 0;
    
    /* A virtual destructor is required if the object may
     * be deleted through a pointer to this class or a subclass
     * This also avoids a warning on the class declaration
     */
    virtual ~PriorityList() {
    }
};

#endif /* PRIORITYLIST_H_ */


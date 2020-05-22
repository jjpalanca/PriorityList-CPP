#include "catch.hpp"
#include "LinkedPriorityList.cpp"
using namespace std;

// The beginning of a Unit test for LinkedPriorityList
TEST_CASE ("testSizeAndIsEmptyWithInsertElementAt") {
    LinkedPriorityList<int> list;
    list.insertElementAt(0, 00);
    list.insertElementAt(1, 11);//0//2
    list.insertElementAt(2, 22);//1//1
    list.insertElementAt(3, 33);//2//0
    list.insertElementAt(4, 44);//3//3
    list.insertElementAt(5, 55);//4//5
    list.insertElementAt(6, 66);//5//6
    list.insertElementAt(7, 77);//6//4
    list.removeElementAt(0);
    REQUIRE(11==list.getElementAt(0));
    list.insertElementAt(0, 00);
    REQUIRE(00==list.getElementAt(0));
    REQUIRE(44==list.getElementAt(4));
    list.removeElementAt(4);
    REQUIRE(55==list.getElementAt(4));
    list.insertElementAt(4, 44);
    list.removeElementAt(7);
    REQUIRE(7==list.size());
    REQUIRE(66==list.getElementAt(6));
    list.insertElementAt(7, 77);
    REQUIRE(8==list.size());
    REQUIRE(77==list.getElementAt(7));
    list.moveToLast(0);
    REQUIRE(00==list.getElementAt(7));
    REQUIRE(11==list.getElementAt(0));
    list.moveToTop(7);
    REQUIRE(77==list.getElementAt(7));
    REQUIRE(00==list.getElementAt(0));
    list.moveToLast(4);
    REQUIRE(44==list.getElementAt(7));
    REQUIRE(55==list.getElementAt(4));
    list.removeElementAt(7);
    list.insertElementAt(4, 44);
    REQUIRE(8==list.size());
    REQUIRE(44==list.getElementAt(4));
    list.moveToTop(4);
    REQUIRE(44==list.getElementAt(0));
    REQUIRE(33==list.getElementAt(4));
    list.removeElementAt(0);
    REQUIRE(7==list.size());
    list.insertElementAt(4, 44);
    REQUIRE(8==list.size());
    REQUIRE(44==list.getElementAt(4));
}
/*#include "catch.hpp"
#include "LinkedPriorityList.cpp"
using namespace std;

// The beginning of a Unit test for LinkedPriorityList
TEST_CASE ("testSizeAndIsEmptyWithInsertElementAt") {
    LinkedPriorityList<int> list;
    REQUIRE(list.isEmpty());
    list.insertElementAt(0, 00);
    REQUIRE(!list.isEmpty());
    list.insertElementAt(1, 11);//0//2
    REQUIRE(!list.isEmpty());//
    list.insertElementAt(2, 22);//1//1
    list.insertElementAt(3, 33);//2//0
    list.insertElementAt(4, 44);//3//3
    list.insertElementAt(5, 55);//4//5
    list.insertElementAt(6, 66);//5//6
    list.insertElementAt(7, 77);//6//4
    list.removeElementAt(0);
    REQUIRE(11==list.getElementAt(0));
    list.lowerPriorityOf(0);
    REQUIRE(22==list.getElementAt(0));
    REQUIRE(11==list.getElementAt(1));
    list.lowerPriorityOf(1);
    REQUIRE(33==list.getElementAt(1));
    REQUIRE(11==list.getElementAt(2));
    list.lowerPriorityOf(6);
    REQUIRE(77==list.getElementAt(6));
    REQUIRE(55==list.getElementAt(4));
    list.raisePriorityOf(6);
    REQUIRE(77==list.getElementAt(5));
    REQUIRE(66==list.getElementAt(6));
    list.raisePriorityOf(5);
    REQUIRE(77==list.getElementAt(4));
    REQUIRE(55==list.getElementAt(5));
    list.raisePriorityOf(1);
    REQUIRE(33==list.getElementAt(0));
    REQUIRE(22==list.getElementAt(1));
    list.moveToTop(6);
    REQUIRE(66==list.getElementAt(0));
    list.moveToLast(0);
    REQUIRE(66==list.getElementAt(6));
    //REQUIRE(66==list.getElementAt(5));
    //REQUIRE(66==list.getElementAt(4));
    //REQUIRE(66==list.getElementAt(3));
    //REQUIRE(66==list.getElementAt(2));
    REQUIRE(22==list.getElementAt(1));
    REQUIRE(33==list.getElementAt(0));
    REQUIRE(7==list.size());
    list.removeElementAt(6);
    REQUIRE(6==list.size());
    list.moveToLast(5);
    REQUIRE(55==list.getElementAt(5));
    list.insertElementAt(0, 00);
    REQUIRE(00==list.getElementAt(0));
    REQUIRE(33==list.getElementAt(1));
    CHECK_THROWS(list.getElementAt(7));
    for(int i=0;i<list.size();i++){
        cout<<list.getElementAt(i)<<endl;
    }
    list.moveToTop(3);
    list.moveToTop(1);
    list.raisePriorityOf(3);
    cout<<endl;
    for(int i=0;i<list.size();i++){
        cout<<list.getElementAt(i)<<endl;
    }

}

//--------------------------------------------------------

// Make sure all functions throw exceptions
// when they are supposed to!
TEST_CASE ("testInsertExceptUpper") { // index out of bounds
    LinkedPriorityList<string> list1;
    //index can only be 0. With 1, an exception must be thrown
    CHECK_THROWS( list1.insertElementAt(1, "2nd") );
    CHECK_THROWS( list1.removeElementAt(0));
    CHECK_THROWS( list1.moveToTop(0));
    CHECK_THROWS( list1.moveToLast(0));
    //CHECK_THROWS( list1.moveToLast(0));
}
*/

//--------------------------------------------------------

// Make sure all functions throw exceptions
// when they are supposed to!
TEST_CASE ("testInsertExceptUpper") { // index out of bounds
  LinkedPriorityList<string> list;
  //index can only be 0. With 1, an exception must be thrown
  CHECK_THROWS( list.insertElementAt(1, "2nd") );
}


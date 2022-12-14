// Uncomment the next line to use precompiled headers
#include "pch.h"
// uncomment the next line if you do not use precompiled headers
//#include "gtest/gtest.h"
//
// the global test environment setup and tear down
// you should not need to change anything here
class Environment : public ::testing::Environment
{
public:
    ~Environment() override {}

    // Override this to define how to set up the environment.
    void SetUp() override
    {
        //  initialize random seed
        srand(time(nullptr));
    }

    // Override this to define how to tear down the environment.
    void TearDown() override {}
};

// create our test class to house shared data between tests
// you should not need to change anything here
class CollectionTest : public ::testing::Test
{
protected:
    // create a smart point to hold our collection
    std::unique_ptr<std::vector<int>> collection;

    void SetUp() override
    { // create a new collection to be used in the test
        collection.reset(new std::vector<int>);
    }

    void TearDown() override
    { //  erase all elements in the collection, if any remain
        collection->clear();
        // free the pointer
        collection.reset(nullptr);
    }

    // helper function to add random values from 0 to 99 count times to the collection
    void add_entries(int count)
    {
        assert(count > 0);
        for (auto i = 0; i < count; ++i)
            collection->push_back(rand() % 100);
    }
};

// When should you use the EXPECT_xxx or ASSERT_xxx macros?
// Use ASSERT when failure should terminate processing, such as the reason for the test case.
// Use EXPECT when failure should notify, but processing should continue

// Test that a collection is empty when created.
// Prior to calling this (and all other TEST_F defined methods),
//  CollectionTest::StartUp is called.
// Following this method (and all other TEST_F defined methods),
//  CollectionTest::TearDown is called
TEST_F(CollectionTest, CollectionSmartPointerIsNotNull)
{
    // is the collection created
    ASSERT_TRUE(collection);

    // if empty, the size must be 0
    ASSERT_NE(collection.get(), nullptr);
}

// Test that a collection is empty when created.
TEST_F(CollectionTest, IsEmptyOnCreate)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());

    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);
}

/* Comment this test out to prevent the test from running
 * Uncomment this test to see a failure in the test explorer 
TEST_F(CollectionTest, AlwaysFail)
{
    FAIL();
}*/

// TODO: Create a test to verify adding a single value to an empty collection
TEST_F(CollectionTest, CanAddToEmptyVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(1);

    // is the collection still empty?
    ASSERT_FALSE(collection->empty());
    // if not empty, what must the size be? (1)
    ASSERT_EQ(collection->size(), 1);
}

// TODO: Create a test to verify adding five values to collection
TEST_F(CollectionTest, CanAddFiveValuesToVector)
{
    // is the collection empty?
    ASSERT_TRUE(collection->empty());
    // if empty, the size must be 0
    ASSERT_EQ(collection->size(), 0);

    add_entries(5);

    // is the collection still empty?
    ASSERT_FALSE(collection->empty());
    // if not empty, what must the size be? (5)
    ASSERT_EQ(collection->size(), 5);
}

// TODO: Create a test to verify that max size is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, MaxGreaterThanOrEqualToSize) {
    // Adding 11 entries to be 1 over the "10 entries" from the comment prompt above
    add_entries(11);

    // Assert that it is true that the max size is greater than or eequal to the size for 0 entries
    // https://cplusplus.com/reference/vector/vector/max_size/
    ASSERT_TRUE(collection->max_size() >= 0);
    //Assert that it is true that the max size is greater than or eequal to the size for 1 entries
    ASSERT_TRUE(collection->max_size() >= 1);
    //Assert that it is true that the max size is greater than or eequal to the size for 5 entries
    ASSERT_TRUE(collection->max_size() >= 5);
    //Assert that it is true that the max size is greater than or eequal to the size for 10 entries
    ASSERT_TRUE(collection->max_size() >= 10);

}
// TODO: Create a test to verify that capacity is greater than or equal to size for 0, 1, 5, 10 entries
TEST_F(CollectionTest, CapacityGreaterThanOrEqualToSize) {
    // adding 11 entries to be 1 over the "10 entries" from the command prompt above
    add_entries(11);

    // Assert that it is true that the capacity is greater than or equal to the size for 0 entries
    // https://cplusplus.com/reference/vector/vector/capacity/
    ASSERT_TRUE(collection->capacity() >= 0);
    // Assert that it is true that the capacity is greater than or equal to the size for 1 entries
    ASSERT_TRUE(collection->capacity() >= 1);
    // Assert that it is true that the capacity is greater than or equal to the size for 5 entries
    ASSERT_TRUE(collection->capacity() >= 5);
    // Assert that it is true that the capacity is greater than or equal to the size for 10 entries
    ASSERT_TRUE(collection->capacity() >= 10);
}
// TODO: Create a test to verify resizing increases the collection
TEST_F(CollectionTest, ResizingIncreasesTheCollection) {
    // Add a single entry to the collection
    add_entries(1);

    // Define a variable we can compare to, to assert collection increased
    int startingSize = collection->size();

    // Resize the collection to be 5 (arbitrary number that is larger)
    // https://cplusplus.com/reference/vector/vector/resize/
    collection->resize(5);

    // Assert that it is true that the size of the collection is larger than its starting size
    ASSERT_TRUE(collection ->size() > startingSize);
}
// TODO: Create a test to verify resizing decreases the collection
TEST_F(CollectionTest, ResizingDecreasesTheCollection) {
    // Add 5 entries to the collection
    add_entries(5);

    // Define a variable we can compare to, to assert collection decreased
    int startingSize = collection->size();

    // Resize the collection to be 1 (arbitrary number that is smaller)
    collection->resize(1);

    // Assert that it is true that the size of the collection is smaller than its starting size
    ASSERT_TRUE(collection->size() < startingSize);
}
// TODO: Create a test to verify resizing decreases the collection to zero
TEST_F(CollectionTest, ResizingDecreasesTheCollectionToZero) {
    // Add 5 entries to the collection (arbitrary number)
    add_entries(5);

    // Resize the collection to be 0
    collection->resize(0);

    // Assert that it is true that the size of the collection is decreased to zero
    ASSERT_TRUE(collection->size() == 0);
}
// TODO: Create a test to verify clear erases the collection
TEST_F(CollectionTest, ClearErasesTheCollection) {
    // Add 5 entries to the collection (arbitrary number)
    add_entries(5);

    // use clear() to remove all entries
    // https://cplusplus.com/reference/vector/vector/clear/
    collection->clear();

    // Assert that it is true that the collection has been cleared/erased and is now 0
    ASSERT_TRUE(collection->size() == 0);
}
// TODO: Create a test to verify erase(begin,end) erases the collection
TEST_F(CollectionTest, EraseBeginEndErasesTheCollection) {
    // Add 5 entries to the collection (arbitrary number)
    add_entries(5);

    // use erase() to remove entries from beginning to end
    // https://cplusplus.com/reference/vector/vector/erase/
    collection->erase(collection->begin(), collection->end());

    // Assert that it is true that the collection has been erased and is now 0
    ASSERT_TRUE(collection->size() == 0);
}
// TODO: Create a test to verify reserve increases the capacity but not the size of the collection
TEST_F(CollectionTest, ReserveIncreasesCapacityNotSize) {
    // Add 5 entries to the collection (arbitrary number)
    add_entries(5);

    // Define variables for the starting size and starting capacity to compare to
    int startingSize = collection->size();
    int startingCapacity = collection->capacity();

    // use reserve() to increase the capacity but not affect the size
    // https://cplusplus.com/reference/vector/vector/reserve/
    collection->reserve(25);

    ASSERT_TRUE(collection->size() == startingSize);
    ASSERT_TRUE(collection->capacity() > startingCapacity);
}
// TODO: Create a test to verify the std::out_of_range exception is thrown when calling at() with an index out of bounds
// NOTE: This is a negative test
TEST_F(CollectionTest, OutOfRangeExceptionThrown) {
    // Define a vector with the size of 5
    std::vector<int> elements(5);

    // Expect a throw of the std::out_of_range when using at() on an element/index out of bounds.
    // https://cplusplus.com/reference/vector/vector/at/
    ASSERT_THROW(elements.at(9), std::out_of_range);
}

// TODO: Create 2 unit tests of your own to test something on the collection - do 1 positive & 1 negative
// I created a first custom unit test, this one adds 6 entries, and then uses pop_back() to remove the last entry
// and asserts_false that the size is still 6, as it should now be 5.
TEST_F(CollectionTest, CustemNegative_PopBackReducesSize) {
    // Add 6 entries to the collection
    add_entries(6);

    // Use pop_back() to remove the last element
    // https://cplusplus.com/reference/vector/vector/pop_back/
    collection->pop_back();

    // Assert that it is false that the collection size is still 6
    ASSERT_FALSE(collection->size() == 6);
}
// I created a second custom unit test, this one adds four starting entries, and then uses push_back() and assert that
// the entries are now 5 instead of the starting 4.
TEST_F(CollectionTest, CustomPositive_PushBackIncreasesSize) {
    //add 4 entries to the colleection
    add_entries(4);

    // use push_back() to add an eleent to the collection
    // https://cplusplus.com/reference/vector/vector/push_back/
    collection->push_back(1);
    
    // Assert that it is true that the collection size has been increased to 5 from 4.
    ASSERT_TRUE(collection->size() == 5);
}
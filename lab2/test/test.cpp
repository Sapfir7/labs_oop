#include <gtest/gtest.h>
#include "Six.h"
#include "SixBuilder.h"

TEST(DefaultConstructor, BasicAssertions) {
  // arrange 
  // через билдер не создать arr -> null лол
 
  int expectedSize = 0;
  
  // act
  Six obj {};
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  EXPECT_EQ(array, nullptr);
}

TEST(FillConstructor, BasicAssertions) {
  // arrange 
  int n = 5;
  char val = '0';
  int expectedSize = 5;
  unsigned char expectedArray[] = "00000";
  Six expectedObj = SixBuilder().size(expectedSize).data(expectedArray).build();

  // act
  Six obj(n, val);
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedObj.getSize());
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedObj.getArray()[i]);
  }
  
}

TEST(FillConstructorValueExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  char val = 'k';
  // assert
  EXPECT_THROW(Six obj(n, val);, std::invalid_argument);

}

TEST(ListConstructor, BasicAssertions) {
  // arrange 
  
  unsigned char expectedArray[] = "5555";
  int expectedSize = 4;
  Six expectedObj = SixBuilder().size(expectedSize).data(expectedArray).build();
  // act
  Six obj {'5', '5', '5', '5'};
  

  // assert
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(ListConstructorValueExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  
  // assert
  EXPECT_THROW(Six obj('k','k');, std::invalid_argument);

}

TEST(StringConstructor, BasicAssertions) {
  // arrange 
  unsigned char expectedArray[] = "5555";
  int expectedSize = 4;
  Six expectedObj = SixBuilder().size(expectedSize).data(expectedArray).build();

  // act
  Six obj {"5555"};

  // assert
  int size = obj.getSize();
  unsigned char* array = obj.getArray();
  EXPECT_EQ(size, expectedObj.getSize());
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedObj.getArray()[i]);
  }
}

TEST(StringConstructorValueExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  
  // assert
  EXPECT_THROW(Six obj{"kj"};, std::invalid_argument);

}

TEST(CopyConstructor, BasicAssertions) {
  // arrange 
  unsigned char expectedArray[] = "2222";
  int expectedSize = 4;
  Six parentObj = SixBuilder().size(expectedSize).data(expectedArray).build();

  // act
  Six obj {parentObj};
  int size = obj.getSize();
  
  // assert
  EXPECT_EQ(size, parentObj.getSize());
  
  for (int i =0; i < size; ++i){
    EXPECT_EQ(obj.getArray()[i], parentObj.getArray()[i]);
  }
}

TEST(MoveConstructor, BasicAssertions) {
  // arrange 
  unsigned char expectedArray[] = "1111";
  int expectedSize = 4;
  Six parentObj = SixBuilder().size(expectedSize).data(expectedArray).build();
  // act
  Six obj(std::move(parentObj));
  int size = obj.getSize();
  unsigned char* array = obj.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(addOperation1, BasicAssertions) {
  // arrange 
  int firstSize = 4;
  int secondSize = 4;
  unsigned char firstArr[] = "1111";
  unsigned char secondArr[] = "1111";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
  unsigned char expectedArray[] = "2222";
  int expectedSize = 4;
  // act
  Six res{first.add(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(addOperation2, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 5;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "12345";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
  unsigned char expectedArray[] = "43152";
  int expectedSize = 5;
  // act
   Six res{first.add(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}



TEST(RemoveOperation1, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 5;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "12345";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  unsigned char expectedArray[] = "0";
  int expectedSize = 1;
  // act
   Six res{first.remove(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();
  std::cout << size << "\n";

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(RemoveOperation2, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 4;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "1234";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
  unsigned char expectedArray[] = "11111";
  int expectedSize = 5;
  // act
  Six res{first.remove(second)};
  int size = res.getSize();
  unsigned char* array = res.getArray();
  

  // assert
  EXPECT_EQ(size, expectedSize);
  for (int i =0; i < size; ++i){
    EXPECT_EQ(array[i], expectedArray[i]);
  }
}

TEST(RemoveOperationLogicExeption, BasicAssertions) {
  // arrange 
  int n = 5;
  int firstSize = 5;
  int secondSize = 4;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "1234";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
  // assert
  EXPECT_THROW(second.remove(first);, std::logic_error);

}

TEST(Equals, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 5;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "12345";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first.equals(second);
  
  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(Equals2, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 4;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "1245";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first.equals(second);
  

  // assert
  EXPECT_EQ(res, 0);
  
}

TEST(OperatorGreter1, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 4;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "1235";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first.greaterThan(second);
  
  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(OperatorGreter2, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 6;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "123555";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first.greaterThan(second);
  

  // assert
  EXPECT_EQ(res, 0);
  
}

TEST(OperatorLower, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 6;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "123555";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first.lessThan(second);
  

  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(OperatorLower2, BasicAssertions) {
  // arrange 
  int firstSize = 9;
  int secondSize = 6;
  unsigned char firstArr[] = "123434345";
  unsigned char secondArr[] = "123555";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first.lessThan(second);
  

  // assert
  EXPECT_EQ(res, 0);
  
}

TEST(Greater1, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 6;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "123555";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first > second;
  

  // assert
  EXPECT_EQ(res, 0);
  
}

TEST(Greater2, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 6;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "123555";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = second > first;
  

  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(lower1, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 6;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "123555";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first < second;
  

  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(equality1, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 6;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "123555";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first == second;
  

  // assert
  EXPECT_EQ(res, 0);
  
}

TEST(equality2, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  int secondSize = 5;
  unsigned char firstArr[] = "12345";
  unsigned char secondArr[] = "12345";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  Six second = SixBuilder().size(secondSize).data(secondArr).build();
 
  // act
 bool res = first == second;
  

  // assert
  EXPECT_EQ(res, 1);
  
}

TEST(assignment, BasicAssertions) {
  // arrange 
  int firstSize = 5;
  unsigned char firstArr[] = "12345";
  Six first = SixBuilder().size(firstSize).data(firstArr).build();
  
 
  // act
  Six res = first;
  

  // assert
  EXPECT_EQ(res.getSize(), firstSize);
  for (int i = 0; i < firstSize; ++i){
     EXPECT_EQ(res.getArray()[i], first.getArray()[i]);
  }
  
}

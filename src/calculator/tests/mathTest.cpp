/*
© Copyright 2022
    Alexaj Ondrej <xalexa09@stud.fit.vutbr.cz>
    Gurka Oliver <xgurka00@stud.fit.vutbr.cz>
    Magda Jakub <xmagda03@stud.fit.vutbr.cz>
*/

/**
 * @file mathTest.cpp
 * @author Jakub Magda (xmagda03@stud.fit.vutbr.cz>)
 * @brief Tests for wmath library
 * @date 2022-03-22
 */

#include "gtest/gtest.h"
#include "../math/wmath.h"
#include "../math/exceptions/exceptions.h"

class MathTest: public ::testing::Test {
    protected:
    void SetUp() override {

    }
    Math operation;
};

TEST_F(MathTest, Add){
    EXPECT_DOUBLE_EQ(operation.Add(5,2),7);
    EXPECT_DOUBLE_EQ(operation.Add(-5,5),0);
    EXPECT_DOUBLE_EQ(operation.Add(799,-800),-1);
    EXPECT_DOUBLE_EQ(operation.Add(3.85679,-7.12387),-3.26708);
    EXPECT_DOUBLE_EQ(operation.Add(789456,456123),1245579);
}

TEST_F(MathTest, Subtract){
    EXPECT_DOUBLE_EQ(operation.Subtract(0,0),0);
    EXPECT_DOUBLE_EQ(operation.Subtract(50,14),36);
    EXPECT_DOUBLE_EQ(operation.Subtract(5,10),-5);
    EXPECT_DOUBLE_EQ(operation.Subtract(-46,0),-46);
    EXPECT_DOUBLE_EQ(operation.Subtract(-71,-71),0);
    EXPECT_DOUBLE_EQ(operation.Subtract(100000,99999),1);
}

TEST_F(MathTest, Multiply){
    EXPECT_DOUBLE_EQ(operation.Multiply(1,1),1);
    EXPECT_DOUBLE_EQ(operation.Multiply(2,5),operation.Multiply(5,2));
    EXPECT_DOUBLE_EQ(operation.Multiply(8,-8),-64);
    EXPECT_DOUBLE_EQ(operation.Multiply(-10,5),-50);
    EXPECT_DOUBLE_EQ(operation.Multiply(1.5,10),15);
    EXPECT_DOUBLE_EQ(operation.Multiply(0.125,5000),625);
    EXPECT_DOUBLE_EQ(operation.Multiply(0,0),0);
    EXPECT_DOUBLE_EQ(operation.Multiply(450,0),0);
}

TEST_F(MathTest, Divide){
    EXPECT_THROW(operation.Divide(0,0), Exc::DivisionByZeroException);
    EXPECT_THROW(operation.Divide(100,0), Exc::DivisionByZeroException);
    EXPECT_THROW(operation.Divide(-500,0), Exc::DivisionByZeroException);
    EXPECT_DOUBLE_EQ(operation.Divide(5,2),2.5);
    EXPECT_DOUBLE_EQ(operation.Divide(1,3),1.0/3.0);
    EXPECT_DOUBLE_EQ(operation.Divide(1,10),0.1);
    EXPECT_DOUBLE_EQ(operation.Divide(500,500),1);
    EXPECT_DOUBLE_EQ(operation.Divide(-5,4),-1.25);
    EXPECT_DOUBLE_EQ(operation.Divide(1,500),0.002);
    EXPECT_DOUBLE_EQ(operation.Divide(0,1),0);
    EXPECT_DOUBLE_EQ(operation.Divide(10,3),operation.Divide(200,60));
    EXPECT_DOUBLE_EQ(operation.Divide(500,0.001),500000);
}

TEST_F(MathTest, Power){
    EXPECT_DOUBLE_EQ(operation.Power(5,0),1);
    EXPECT_DOUBLE_EQ(operation.Power(0,0),1);
    EXPECT_DOUBLE_EQ(operation.Power(2,2),4);
    EXPECT_DOUBLE_EQ(operation.Power(5,3),125);

    EXPECT_DOUBLE_EQ(operation.Power(10,10),10000000000);
    // exponent has to be natural number
    EXPECT_THROW(operation.Power(64,1.0/6.0), Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Power(100,0.5), Exc::InvalidArgumentException);
    // base has to be positive number
    EXPECT_THROW(operation.Power(-5,0.5), Exc::InvalidArgumentException);
}

TEST_F(MathTest, Root){
    EXPECT_DOUBLE_EQ(operation.Root(4,2),2);
    EXPECT_DOUBLE_EQ(operation.Root(25,2),5);
    EXPECT_DOUBLE_EQ(operation.Root(27,3),3);
    EXPECT_DOUBLE_EQ(operation.Root(35831808,7),12);
    EXPECT_DOUBLE_EQ(operation.Root(5,1),5);
    EXPECT_DOUBLE_EQ(operation.Root(3125,5),5);
    EXPECT_DOUBLE_EQ(operation.Root(2,0.1),1024);
    EXPECT_DOUBLE_EQ(operation.Root(450,0.5),202500);
    EXPECT_DOUBLE_EQ(operation.Root(1,8.2),1);
    EXPECT_DOUBLE_EQ(operation.Root(1999,16.8),1.572088359660982);
    EXPECT_THROW(operation.Root(0,0),Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Root(2,0),Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Root(-5,2),Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Root(-5,6),Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Root(2,0.000000000000001),Exc::NumberNotValidException);
}

TEST_F(MathTest, Factorial){
    EXPECT_DOUBLE_EQ(operation.Factorial(0.0),1);
    EXPECT_DOUBLE_EQ(operation.Factorial(1.0),1);
    EXPECT_DOUBLE_EQ(operation.Factorial(2),2);
    EXPECT_DOUBLE_EQ(operation.Factorial(3),6);
    EXPECT_DOUBLE_EQ(operation.Factorial(9),362880);
    EXPECT_DOUBLE_EQ(operation.Factorial(18),6402373705728000);
    EXPECT_THROW(operation.Factorial(1.1), Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Factorial(-1), Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Factorial(50.00000000000001), Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Factorial(-5.8), Exc::InvalidArgumentException);
}

TEST_F(MathTest, Logarithm){
    EXPECT_DOUBLE_EQ(operation.Log(10),1);
    EXPECT_DOUBLE_EQ(operation.Log(1),0);
    EXPECT_DOUBLE_EQ(operation.Log(100),2);
    EXPECT_DOUBLE_EQ(operation.Log(1000),3);
    EXPECT_DOUBLE_EQ(operation.Log(1000000),6);
    EXPECT_NEAR(operation.Log(5),0.6989700043,0.00000001);
    EXPECT_NEAR(operation.Log(600),2.77815125,0.00000001);
    EXPECT_NEAR(operation.Log(2487),3.395675785,0.00000001);
    EXPECT_NEAR(operation.Log(15.58),1.192567453,0.00000001);
    EXPECT_NEAR(operation.Log(847.9157),2.928352677,0.00000001);
    EXPECT_THROW(operation.Log(0),Exc::InvalidArgumentException);
    EXPECT_THROW(operation.Log(-10),Exc::InvalidArgumentException);
}

TEST_F(MathTest, Answer){
    //if the library had a bug and gave nullptr as answer test would be canceled
    operation.Log(10);
    ASSERT_NE(operation.GetAnswer(),nullptr);
    EXPECT_DOUBLE_EQ(operation.GetAnswer()->GetValue(),1);
    ASSERT_NE(operation.GetAnswer(),nullptr);
    EXPECT_DOUBLE_EQ(operation.Add(operation.GetAnswer()->GetValue(),2),3);
    ASSERT_NE(operation.GetAnswer(),nullptr);
    EXPECT_DOUBLE_EQ(operation.Multiply(operation.GetAnswer()->GetValue(),51),153);
    //invalid operation
    EXPECT_ANY_THROW(operation.Root(0,0));
    ASSERT_NE(operation.GetAnswer(),nullptr);
    // try if library get answer as last valid operation
    EXPECT_DOUBLE_EQ(operation.Subtract(operation.GetAnswer()->GetValue(),13),140);
    ASSERT_NE(operation.GetAnswer(),nullptr);
    EXPECT_DOUBLE_EQ(operation.Divide(70,operation.GetAnswer()->GetValue()),0.5);
    ASSERT_NE(operation.GetAnswer(),nullptr);
    EXPECT_DOUBLE_EQ(operation.Subtract(operation.GetAnswer()->GetValue(),18),-17.5);
    ASSERT_NE(operation.GetAnswer(),nullptr);
    EXPECT_DOUBLE_EQ(operation.Add(operation.GetAnswer()->GetValue(),17.5),0);
    ASSERT_NE(operation.GetAnswer(),nullptr);
    EXPECT_DOUBLE_EQ(operation.Multiply(164,operation.GetAnswer()->GetValue()),0);
}

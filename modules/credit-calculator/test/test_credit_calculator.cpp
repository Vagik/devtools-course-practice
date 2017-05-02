// Copyright 2017 Simonyan Vaginak

#include <gtest/gtest.h>

#include "include/credit_calculator.h"

TEST(Simonyan_Vaginak_CreditCalculatorTest, check_data_when_all_parametrs_are_correct) {
    // Arrange
    int amount = 300000;
    int period = 24;
    double interest = 22;
    bool result;
    CreditCalculator cred;
    
    // Act
    result = cred.check_data(amount, period, interest);

    // Assert
    EXPECT_EQ(true, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, check_data_when_amount_parametr_is_incorrect) {
    // Arrange
    int amount = -300000;
    int period = 24;
    double interest = 22;
    bool result;
    CreditCalculator cred;
    
    // Act
    result = cred.check_data(amount, period, interest);

    // Assert
    EXPECT_EQ(false, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, check_data_when_period_parametr_is_incorrect) {
    // Arrange
    int amount = 300000;
    int period = -5;
    double interest = 22;
    bool result;
    CreditCalculator cred;
    
    // Act
    result = cred.check_data(amount, period, interest);

    // Assert
    EXPECT_EQ(false, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, check_data_when_interest_parametr_is_incorrect) {
    // Arrange
    int amount = 300000;
    int period = -5;
    double interest = 105;
    bool result;
    CreditCalculator cred;
    
    // Act
    result = cred.check_data(amount, period, interest);

    // Assert
    EXPECT_EQ(false, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, check_data_when_passed_parametr_is_incorrect) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_passed = 16;
    double interest = 105;
    bool result;
    CreditCalculator cred;

    // Act
    result = cred.check_data(amount, period, interest,month_passed);

    // Assert
    EXPECT_EQ(false, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, get_monthly_payment) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double interest = 22;
    double result;
    double moth_pay = 28078;
    double month_error = 0.2;
    CreditCalculator cred;

    // Act
    result = cred.monthly_payment(amount, period, interest);

    // Assert
    EXPECT_NEAR(moth_pay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, get_monthly_payment_with_incorrect_parametrs) {
    // Arrange
    int amount = -300000;
    int period = 12;
    double interest = 150;
    double result;
    CreditCalculator cred;

    // Act
    result = cred.monthly_payment(amount, period, interest);

    // Assert
    EXPECT_EQ(-1, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, get_total_payout) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double interest = 22;
    double result;
    double payout = 336940;
    double month_error = 0.2;
    CreditCalculator cred;

    // Act
    result = cred.total_payout(amount, period, interest);

    // Assert
    EXPECT_NEAR(payout, result,period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, get_total_payout_with_incorrect_parametrs) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double interest = 22;
    double result;
    CreditCalculator cred;

    // Act
    result = cred.total_payout(amount, period, interest);

    // Assert
    EXPECT_EQ(-1, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, get_overpayment_amount) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double interest = 22;
    double result;
    double overpay = 36940;
    double month_error = 0.2;
    CreditCalculator cred;

    // Act
    result = cred.overpayment_amount(amount, period, interest);

    // Assert
    EXPECT_NEAR(overpay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, get_overpayment_amount_with_incorrect_parametrs) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double interest = 22;
    double result;
    CreditCalculator cred;

    // Act
    result = cred.overpayment_amount(amount, period, interest);

    // Assert
    EXPECT_EQ(-1, result);
}

TEST(Simonyan_Vaginak_CreditCalculatorTest, check_balance) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_passed = 5;
    double interest = 22;
    double result;
    double balance = 196550;
    double month_error = 0.2;
    CreditCalculator cred;

    // Act
    result = cred.check_balance(amount, period, interest, month_passed);

    // Assert
    EXPECT_NEAR(balance, result, period*month_error);
}
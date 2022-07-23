#include "calc_test.h"

START_TEST(simple_test_1) {
    int code = OK;
    char input[] = "1+1=";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 2;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_2) {
    int code = OK;
    char input[] = "sin(1)";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 0.8414709848;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_3) {
    int code = OK;
    char input[] = "sin(cos(1+1))";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = -0.4042391539;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_4) {
    int code = OK;
    char input[] = "2+2*2";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 6;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_5) {
    int code = OK;
    char input[] = "sin(1)^cos(1)";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 0.9109582586;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_6) {
    int code = OK;
    char input[] = "2 - 3";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = -1;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_7) {
    int code = OK;
    char input[] = "atan(1.1)";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 0.8329812667;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_8) {
    int code = OK;
    char input[] = "acos(asin(0.7777))";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 0.4712559697;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_9) {
    int code = OK;
    char input[] = "ln(log(11))";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 0.04055893768;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(simple_test_10) {
    int code = OK;
    char input[] = "tan(sqrt(4))";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = -2.185039863;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_1) {
    int code = OK;
    char input[] =
        "cos(tan( 2.0221 + tan( sin( cos( 5.0945 ) ) - tan(cos(3.6593))  ) ^1.4616 )  -sin(4.1949- sin("
        "cos(tan(tan( cos(3.8475 ) )  ) ) ^  8.8451) ^  1.4109) - tan( 2.6884/tan( 5.2519 / 6.5461 ) )"
        ")";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = -0.8998910097532222;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_2) {
    int code = OK;
    char input[] =
        "tan( 3.764) ^sin( 9.445-sin( 7.2889 /  8.0438 -cos( sin(cos( tan(8.4448))) - 4.482)  )  /"
        "tan(cos(cos(sin(cos( cos(2.003)) )  ) / 0.1315) ))  -  8.8453/ 0.3612";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = -23.76667454586336;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_3) {
    int code = OK;
    char input[] =
        "tan(sin(cos( 8.8905 )-9.586)) / tan(9.6334 ) -sin(4.091-  6.8317 ^1.3065 ) +sin(tan( 2.4431 +  "
        "7.5867 )^ sin(sin(  6.6115^3.7525) / tan(sin( tan( tan(7.1462)  ) ) /sin( 2.7571)  )  ) )";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 7.167106761528132;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(hard_test_4) {
    int code = OK;
    char input[] =
        "2.4474 /8.0162/ 3.2142+tan( 0.6211 +sin(tan( 7.5952 +5.3702) ) - 4.7121^sin(  1.9427- 2.8496) )"
        "/cos(0.2688 ^0.5391+cos( tan(cos( cos(  5.6221 ))  ) /sin( 2.3295)  -tan( cos(tan( cos(9.2239)  ))"
        ") ) )";
    double result = smart_calc(input, 0, &code, 1, 0);
    double expected = 1.660108415837855;
    ck_assert_double_eq_tol(result, expected, 1e-6);
}
END_TEST

START_TEST(valid_test_1) {
    int code = OK;
    char input[] = "sin";
    smart_calc(input, 0, &code, 1, 0);
    ck_assert_int_eq(code, INVALID_LYXEMS);
}
END_TEST

START_TEST(valid_test_2) {
    int code = OK;
    char input[] = "-sin(x)";
    smart_calc(input, 0, &code, 1, 0);
    ck_assert_int_eq(code, OK);
}
END_TEST

START_TEST(valid_test_3) {
    int code = OK;
    char input[] = "sin(-x)";
    smart_calc(input, 0, &code, 1, 0);
    ck_assert_int_eq(code, OK);
}
END_TEST
Suite *suite_polish(void) {
    Suite *s = suite_create("polish");
    TCase *tc = tcase_create("polish");

    tcase_add_test(tc, simple_test_1);
    tcase_add_test(tc, simple_test_2);
    tcase_add_test(tc, simple_test_3);
    tcase_add_test(tc, simple_test_4);
    tcase_add_test(tc, simple_test_5);
    tcase_add_test(tc, simple_test_6);
    tcase_add_test(tc, simple_test_7);
    tcase_add_test(tc, simple_test_8);
    tcase_add_test(tc, simple_test_9);
    tcase_add_test(tc, simple_test_10);

    tcase_add_test(tc, hard_test_1);
    tcase_add_test(tc, hard_test_2);
    tcase_add_test(tc, hard_test_3);
    tcase_add_test(tc, hard_test_4);

    tcase_add_test(tc, valid_test_1);
    tcase_add_test(tc, valid_test_2);
    tcase_add_test(tc, valid_test_3);

    suite_add_tcase(s, tc);
    return s;
}

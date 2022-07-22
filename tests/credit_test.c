#include "calc_test.h"
START_TEST(simple_test_1) {
  //
    int code = OK;
  double input[4];
  double output[3];
  input[0] = 10645.08;
  input[1] = 48;
  input[2] = 0.06;
  input[3] = 1;
  double d_m[(int)input[1]];
  credit_calculator(input, output, d_m, &code);
  printf("%lf\n", output[0]);
  printf("%lf\n", output[1]);
  printf("%lf\n", output[2]);
}
END_TEST

Suite *suite_credit(void) {
  Suite *s = suite_create("credit");
  TCase *tc = tcase_create("credit");

  tcase_add_test(tc, simple_test_1);

  suite_add_tcase(s, tc);
  return s;
}

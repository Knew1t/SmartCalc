#include "test_main.h"
#include <check.h>

START_TEST(plus_test) {
  char expression_string[256] = "1234.9824+89812.1246";
  char *x_value_string = "";
  double right_answer = 1234.9824 + 89812.1246;
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(plus_test_extensive) {
  char expression_string[256] = "1.2+2.3-4.5+6.7-9.8-2.3*10.11/12.13";
  char *x_value_string = "";
  double right_answer = 1.2+2.3-4.5+6.7-9.8-2.3*10.11/12.13;
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(minus_test) {
  char expression_string[256] = "1234.98234-89812.12456";
  char *x_value_string = "";
  double right_answer = 1234.98234 - 89812.12456;
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(multiply_test) {
  char expression_string[256] = "1234.98234*89812.12456";
  char *x_value_string = "";
  double right_answer = 1234.98234 * 89812.12456;
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}

START_TEST(division_test) {
  char expression_string[256] = "1234.98234/89812.12456";
  char *x_value_string = "";
  double right_answer = 1234.98234 / 89812.12456;
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(pow_test) {
  char expression_string[256] = "12^3.123";
  char *x_value_string = "";
  double right_answer = pow(12, 3.123);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(pow_test_extensive) {
  char expression_string[256] = "2^2^3";
  char *x_value_string = "";
  double right_answer = 256.0;
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(sqrt_test) {
  char expression_string[256] = "sqrt(980987)";
  char *x_value_string = "";
  double right_answer = sqrt(980987);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(mod_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(sin_test) {
  char expression_string[256] = "sin(1.98087)";
  char *x_value_string = "";
  double right_answer = sin(1.98087);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(cos_test) {
  char expression_string[256] = "cos(1.98087)";
  char *x_value_string = "";
  double right_answer = cos(1.98087);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(tan_test) {
  char expression_string[256] = "tan(1.98087)";
  char *x_value_string = "";
  double right_answer = tan(1.98087);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(asin_test) {
  char expression_string[256] = "asin(0.98087)";
  char *x_value_string = "";
  double right_answer = asin(0.98087);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(asin_test_nan) {
  char expression_string[256] = "asin(1.98087)";
  char *x_value_string = "";
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_nan(answer);
}
END_TEST

START_TEST(acos_test) {
  char expression_string[256] = "acos(0.123)";
  char *x_value_string = "";
  double right_answer = acos(0.123);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(atan_test) {
  char expression_string[256] = "atan(1.98087)";
  char *x_value_string = "";
  double right_answer = atan(1.98087);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(ln_test) {
  char expression_string[256] = "ln(1.98087)";
  char *x_value_string = "";
  double right_answer = log(1.98087);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(log_test) {
  char expression_string[256] = "log(1.98087)";
  char *x_value_string = "";
  double right_answer = log10(1.98087);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST

START_TEST(long_expression_correct_test) {
  char expression_string[256] = "(1+2)*4*cos(x*7-2)+sin(x*2)";
  char *x_value_string = "2";
  double right_answer = (1+2)*4*cos(2*7-2)+sin(2*2);
  double answer = 0;
  Calculate(expression_string, &answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
}
END_TEST


START_TEST(wrong_input_1) {
  char expression_string[256] = "2l2";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_2) {
  char expression_string[256] = "sinn()";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_3) {
  char expression_string[256] = "sin()+cos()";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_4) {
  char expression_string[256] = "sin(";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_5) {
  char expression_string[256] = "*323*";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_6) {
  char expression_string[256] = "/3";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_7) {
  char expression_string[256] = "3+*4";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_8) {
  char expression_string[256] = "*sin))";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_9) {
  char expression_string[256] = ")";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_10) {
  char expression_string[256] = "(sin";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_11) {
  char expression_string[256] = "*x";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_12) {
  char expression_string[256] = "-+-";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_13) {
  char expression_string[256] = "modx";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_14) {
  char expression_string[256] = "^3";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_15) {
  char expression_string[256] = "sin(-+-)";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_16) {
  char expression_string[256] = "2sinx";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_17) {
  char expression_string[256] = "cosx";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_18) {
  char expression_string[256] = "2sin(.)";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

START_TEST(wrong_input_19) {
  char expression_string[256] = "2tan(23)";
  char *x_value_string = "";
  double answer = 0;
  int error_output= Calculate(expression_string, &answer, x_value_string);
  int expected_error_output = 2;
  ck_assert_int_eq(expected_error_output, error_output);
}
END_TEST

// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double answer = 0;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double answer = 0;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double answer = 0;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double answer = 0;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double answer = 0;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double answer = 0;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, answer, TEST_EPS);
// }
// END_TEST


Suite *backend_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Backend");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, plus_test);
  tcase_add_test(tc_core, plus_test_extensive);
  tcase_add_test(tc_core, minus_test);
  tcase_add_test(tc_core, multiply_test);
  tcase_add_test(tc_core, division_test);
  tcase_add_test(tc_core, pow_test);
  tcase_add_test(tc_core, pow_test_extensive);
  tcase_add_test(tc_core, sqrt_test);
  tcase_add_test(tc_core, log_test);
  tcase_add_test(tc_core, sin_test);
  tcase_add_test(tc_core, cos_test);
  tcase_add_test(tc_core, tan_test);
  tcase_add_test(tc_core, asin_test);
  tcase_add_test(tc_core, asin_test_nan);
  tcase_add_test(tc_core, acos_test);
  tcase_add_test(tc_core, atan_test);
  tcase_add_test(tc_core, ln_test);
  tcase_add_test(tc_core, long_expression_correct_test);

  tcase_add_test(tc_core, wrong_input_1);
  tcase_add_test(tc_core, wrong_input_2);
  tcase_add_test(tc_core, wrong_input_3);
  tcase_add_test(tc_core, wrong_input_4);
  tcase_add_test(tc_core, wrong_input_5);
  tcase_add_test(tc_core, wrong_input_6);
  tcase_add_test(tc_core, wrong_input_7);
  tcase_add_test(tc_core, wrong_input_8);
  tcase_add_test(tc_core, wrong_input_9);
  tcase_add_test(tc_core, wrong_input_10);
  tcase_add_test(tc_core, wrong_input_11);
  tcase_add_test(tc_core, wrong_input_12);
  tcase_add_test(tc_core, wrong_input_13);
  tcase_add_test(tc_core, wrong_input_14);
  tcase_add_test(tc_core, wrong_input_15);
  tcase_add_test(tc_core, wrong_input_16);
  tcase_add_test(tc_core, wrong_input_17);
  tcase_add_test(tc_core, wrong_input_18);
  tcase_add_test(tc_core, wrong_input_19);
  // tcase_add_test(tc_core,);
  // tcase_add_test(tc_core,);
  // tcase_add_test(tc_core,);
  // tcase_add_test(tc_core,);
  suite_add_tcase(s, tc_core);

  return s;
}

int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner = 0;

  s = backend_suite();
  runner = srunner_create(s);
  srunner_set_fork_status(runner, CK_NOFORK);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

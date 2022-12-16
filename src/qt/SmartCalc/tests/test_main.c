#include "test_main.h"

START_TEST(plus_test) {
  char expression_string[256] = "1234.9824+89812.1246";
  char *x_value_string = "";
  double right_answer = 1234.9824+89812.1246;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(minus_test) {
  char expression_string[256] = "1234.98234-89812.12456";
  char *x_value_string = "";
  double right_answer = 1234.98234 - 89812.12456;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(multiply_test) {
  char expression_string[256] = "1234.98234*89812.12456";
  char *x_value_string = "";
  double right_answer = 1234.98234 * 89812.12456;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}

START_TEST(division_test) {
  char expression_string[256] = "1234.98234/89812.12456";
  char *x_value_string = "";
  double right_answer = 1234.98234 / 89812.12456;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(pow_test) {
  char expression_string[256] = "12^3.123";
  char *x_value_string = "";
  double right_answer = pow(12, 3.123);
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST
//
START_TEST(sqrt_test) {
  char expression_string[256] = "sqrt(980987)";
  char *x_value_string = "";
  double right_answer = sqrt(980987);
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST
//
START_TEST(mod_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(sin_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(cos_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST


START_TEST(tan_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(asin_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(acos_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(atan_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(ln_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

START_TEST(log_test) {
  char expression_string[256] = "2+2";
  char *x_value_string = "";
  double right_answer = 4.0;
  double *answer;
  Calculate(expression_string, answer, x_value_string);
  ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
}
END_TEST

// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double *answer;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double *answer;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double *answer;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double *answer;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double *answer;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double *answer;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
// }
// END_TEST
//
// START_TEST() {
//   char expression_string[256] = "2+2";
//   char *x_value_string = "";
//   double right_answer = 4.0;
//   double *answer;
//   Calculate(expression_string, answer, x_value_string);
//   ck_assert_double_eq_tol(right_answer, *answer, TEST_EPS);
// }
// END_TEST

Suite *backend_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Backend");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, plus_test);
  tcase_add_test(tc_core, minus_test);
  tcase_add_test(tc_core, multiply_test);
  tcase_add_test(tc_core, division_test);
  tcase_add_test(tc_core,pow_test );
  tcase_add_test(tc_core,sqrt_test );
  // tcase_add_test(tc_core,log_test );
  // tcase_add_test(tc_core, );
  // tcase_add_test(tc_core, );
  // tcase_add_test(tc_core, );
  // tcase_add_test(tc_core, );
  suite_add_tcase(s, tc_core);

  return s;
}
int main(void) {
  int no_failed = 0;
  Suite *s;
  SRunner *runner;

  s = backend_suite();
  runner = srunner_create(s);

  srunner_run_all(runner, CK_NORMAL);
  no_failed = srunner_ntests_failed(runner);
  srunner_free(runner);
  return (no_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}

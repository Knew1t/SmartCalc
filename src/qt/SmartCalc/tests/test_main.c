#include "test_main.h"
#include "backend.h"

START_TEST(plus_test) {
  char *expression_string = "2+2";
  char *x_value_string = "";
  double *answer = NULL;
  Calculate(expression_string, answer, x_value_string);
}
END_TEST

Suite *backend_suite(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("Backend");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, plus_test);
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  tcase_add_test(tc_core, );
  suite_add_tcase(s, tc_core);

  return s;
}
int main(void) {
  Suite *s = backend_suite();
  SRunner *sr = srunner_create(s);
  srunner_set_fork_status(sr, CK_NOFORK);

  srunner_add_suite(sr, s);

  srunner_run_all(sr, CK_NORMAL);
  int nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}

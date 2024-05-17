#include <linux/module.h>

// Metadata
MODULE_AUTHOR("Zi");
MODULE_LICENSE("GPL");

// Init
static int jlf_driver_init(void) {
  return 0;
}
module_init(jlf_driver_init);

// Exit
static void jlf_driver_exit(void) { }
module_exit(jlf_driver_exit);

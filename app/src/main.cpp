#include <chrono>
#include <iostream>
#include <diod_printer.h>
#include <thread>

int32_t diod_on() {
  printf("1\n");
  return 0;
}

int32_t diod_off() {
  printf("0\n");
  return 0;
}

int main(int argc, char* argv[]) {
  diod_printer_attrs attrs;

  int ret = diod_printer_get_default_attrs(&attrs);

  attrs.diod_on  = &diod_on;
  attrs.diod_off = &diod_off;  

  printf("--- diod_printer_get_default_attrs ret %d ---\n", ret);
  
  printf("create: %p\ndelete: %p\nsem_create: %p\nsem_delete: %p\nsem_wait: %p\nsem_post: %p\non: %p\noff: %p\n",
         attrs.thread_ops.thread_create,
         attrs.thread_ops.thread_delete,
         attrs.thread_ops.sem_create,
         attrs.thread_ops.sem_delete,
         attrs.thread_ops.sem_wait,
         attrs.thread_ops.sem_post,
         attrs.diod_on,
         attrs.diod_off);

  ret = diod_printer_init(&attrs);
  printf("--- diod_printer_init ret %d ---\n", ret);

  diod_start_print("user", MESSAGE_OK, "hello");

  std::this_thread::sleep_for(std::chrono::seconds(5));

  diod_stop_print();

  ret = diod_printer_done();
  printf("--- diod_printer_done ret %d ---\n", ret);

  return ret;
}

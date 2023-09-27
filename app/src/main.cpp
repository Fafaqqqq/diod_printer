#include <iostream>
#include <diod_printer.h>

int main()
{
  diod_printer_attrs attrs = diod_printer_get_default_attrs();

  printf("create: %p\ndelete: %p\nlock: %p\nunlock: %p\non: %p\noff: %p\n",
         attrs.thread_create,
         attrs.thread_delete,
         attrs.thread_lock,
         attrs.thread_unlock,
         attrs.diod_on,
         attrs.diod_off);
  return 0;
}

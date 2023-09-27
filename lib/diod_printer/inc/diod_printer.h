#ifndef DIOD_PRINTER_H
#define DIOD_PRINTER_H

#ifdef __cplusplus
extern "C" {
#endif

typedef void* thread_handle;
typedef void* thread_attr_t;
typedef void (*thread_func_t)(thread_attr_t);

typedef struct {
  thread_handle (*thread_create)(thread_func_t, thread_attr_t);
  void (*thread_delete)(thread_handle);
  void (*thread_lock)();
  void (*thread_unlock)();
  int  (*diod_on)();
  int  (*diod_off)();
} diod_printer_attrs;

diod_printer_attrs diod_printer_get_default_attrs();

int diod_printer_init(diod_printer_attrs*);

int diod_start_print_fmt(const char* format, ...);
int diod_start_print(const char* str);
int diod_stop_print();

#ifdef __cplusplus
}
#endif

#endif // !DIOD_PRINTER_H

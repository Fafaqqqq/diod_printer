#include "diod_printer.h"

#include <mutex>
#include <thread>

static std::mutex _diod_default_mutex;

static thread_handle _diod_default_create_thread(thread_func_t func, thread_attr_t attr) {
  if (!func)
    return nullptr;

  std::thread *thread_ = new std::thread(func, attr);
  return thread_;
}

static void _diod_default_delete_thread(thread_handle handle) {
  if (!handle)
    return;

  delete static_cast<std::thread*>(handle);
}

static void _diod_default_thread_lock() {
  _diod_default_mutex.lock();
}
static void _diod_default_thread_unlock() {
  _diod_default_mutex.unlock();
}

diod_printer_attrs diod_printer_get_default_attrs() {
  return {
    .thread_create = &_diod_default_create_thread,
    .thread_delete = &_diod_default_delete_thread,
    .thread_lock   = &_diod_default_thread_lock,
    .thread_unlock = &_diod_default_thread_unlock,
    .diod_on = nullptr,
    .diod_off = nullptr,
  };
}

#include "diod_printer.h"

static diod_printer_attrs* _diod_attrs = nullptr;

int diod_printer_init(diod_printer_attrs* attrs) {
  _diod_attrs = attrs;
  return 0;
}


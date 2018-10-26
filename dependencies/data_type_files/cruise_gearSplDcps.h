#ifndef CRUISE_GEARSPLTYPES_H
#define CRUISE_GEARSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "cruise_gear_DCPS.hpp"


extern c_metaObject __cruise_gear_cruise_gear__load (c_base base);

extern const char *cruise_gear_Msg_metaDescriptor[];
extern const int cruise_gear_Msg_metaDescriptorArrLength;
extern const int cruise_gear_Msg_metaDescriptorLength;
extern c_metaObject __cruise_gear_Msg__load (c_base base);
struct _cruise_gear_Msg ;
extern  v_copyin_result __cruise_gear_Msg__copyIn(c_base base, const class cruise_gear::Msg *from, struct _cruise_gear_Msg *to);
extern  void __cruise_gear_Msg__copyOut(const void *_from, void *_to);
struct _cruise_gear_Msg {
    c_long id;
    c_double curr_gear;
};

#undef OS_API
#endif

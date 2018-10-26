#ifndef CRUISE_SPEEDSPLTYPES_H
#define CRUISE_SPEEDSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "cruise_speed_DCPS.hpp"


extern c_metaObject __cruise_speed_cruise_speed__load (c_base base);

extern const char *cruise_speed_Msg_metaDescriptor[];
extern const int cruise_speed_Msg_metaDescriptorArrLength;
extern const int cruise_speed_Msg_metaDescriptorLength;
extern c_metaObject __cruise_speed_Msg__load (c_base base);
struct _cruise_speed_Msg ;
extern  v_copyin_result __cruise_speed_Msg__copyIn(c_base base, const class cruise_speed::Msg *from, struct _cruise_speed_Msg *to);
extern  void __cruise_speed_Msg__copyOut(const void *_from, void *_to);
struct _cruise_speed_Msg {
    c_long id;
    c_double curr_speed;
};

#undef OS_API
#endif

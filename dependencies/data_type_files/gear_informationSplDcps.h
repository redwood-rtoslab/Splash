#ifndef GEAR_INFORMATIONSPLTYPES_H
#define GEAR_INFORMATIONSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "gear_information_DCPS.hpp"


extern c_metaObject __gear_information_gear_information__load (c_base base);

extern const char *gear_information_Msg_metaDescriptor[];
extern const int gear_information_Msg_metaDescriptorArrLength;
extern const int gear_information_Msg_metaDescriptorLength;
extern c_metaObject __gear_information_Msg__load (c_base base);
struct _gear_information_Msg ;
extern  v_copyin_result __gear_information_Msg__copyIn(c_base base, const class gear_information::Msg *from, struct _gear_information_Msg *to);
extern  void __gear_information_Msg__copyOut(const void *_from, void *_to);
struct _gear_information_Msg {
    c_long id;
    c_long curr_gear;
};

#undef OS_API
#endif

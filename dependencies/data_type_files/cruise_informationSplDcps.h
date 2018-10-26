#ifndef CRUISE_INFORMATIONSPLTYPES_H
#define CRUISE_INFORMATIONSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "cruise_information_DCPS.hpp"


extern c_metaObject __cruise_information_cruise_information__load (c_base base);

extern const char *cruise_information_Msg_metaDescriptor[];
extern const int cruise_information_Msg_metaDescriptorArrLength;
extern const int cruise_information_Msg_metaDescriptorLength;
extern c_metaObject __cruise_information_Msg__load (c_base base);
struct _cruise_information_Msg ;
extern  v_copyin_result __cruise_information_Msg__copyIn(c_base base, const class cruise_information::Msg *from, struct _cruise_information_Msg *to);
extern  void __cruise_information_Msg__copyOut(const void *_from, void *_to);
struct _cruise_information_Msg {
    c_long id;
    c_double throttle;
    c_double brake;
};

#undef OS_API
#endif

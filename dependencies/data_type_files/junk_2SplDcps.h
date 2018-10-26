#ifndef JUNK_2SPLTYPES_H
#define JUNK_2SPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "junk_2_DCPS.hpp"


extern c_metaObject __junk_2_junk_2__load (c_base base);

extern const char *junk_2_Msg_metaDescriptor[];
extern const int junk_2_Msg_metaDescriptorArrLength;
extern const int junk_2_Msg_metaDescriptorLength;
extern c_metaObject __junk_2_Msg__load (c_base base);
struct _junk_2_Msg ;
extern  v_copyin_result __junk_2_Msg__copyIn(c_base base, const class junk_2::Msg *from, struct _junk_2_Msg *to);
extern  void __junk_2_Msg__copyOut(const void *_from, void *_to);
struct _junk_2_Msg {
    c_long id;
    c_string message;
    c_longlong constraint_deadline_duetime;
    c_longlong constraint_freshness_gentime;
};

#undef OS_API
#endif

#ifndef JUNK_1SPLTYPES_H
#define JUNK_1SPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "junk_1_DCPS.hpp"


extern c_metaObject __junk_1_junk_1__load (c_base base);

extern const char *junk_1_Msg_metaDescriptor[];
extern const int junk_1_Msg_metaDescriptorArrLength;
extern const int junk_1_Msg_metaDescriptorLength;
extern c_metaObject __junk_1_Msg__load (c_base base);
struct _junk_1_Msg ;
extern  v_copyin_result __junk_1_Msg__copyIn(c_base base, const class junk_1::Msg *from, struct _junk_1_Msg *to);
extern  void __junk_1_Msg__copyOut(const void *_from, void *_to);
struct _junk_1_Msg {
    c_long id;
    c_string message;
    c_longlong constraint_deadline_duetime;
    c_longlong constraint_freshness_gentime;
};

#undef OS_API
#endif

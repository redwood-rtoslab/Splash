#ifndef JUNK_4SPLTYPES_H
#define JUNK_4SPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "junk_4_DCPS.hpp"


extern c_metaObject __junk_4_junk_4__load (c_base base);

extern const char *junk_4_Msg_metaDescriptor[];
extern const int junk_4_Msg_metaDescriptorArrLength;
extern const int junk_4_Msg_metaDescriptorLength;
extern c_metaObject __junk_4_Msg__load (c_base base);
struct _junk_4_Msg ;
extern  v_copyin_result __junk_4_Msg__copyIn(c_base base, const class junk_4::Msg *from, struct _junk_4_Msg *to);
extern  void __junk_4_Msg__copyOut(const void *_from, void *_to);
struct _junk_4_Msg {
    c_long id;
    c_string message;
    c_longlong constraint_deadline_duetime;
    c_longlong constraint_freshness_gentime;
};

#undef OS_API
#endif

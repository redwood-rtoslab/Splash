#ifndef JUNK_9SPLTYPES_H
#define JUNK_9SPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "junk_9_DCPS.hpp"


extern c_metaObject __junk_9_junk_9__load (c_base base);

extern const char *junk_9_Msg_metaDescriptor[];
extern const int junk_9_Msg_metaDescriptorArrLength;
extern const int junk_9_Msg_metaDescriptorLength;
extern c_metaObject __junk_9_Msg__load (c_base base);
struct _junk_9_Msg ;
extern  v_copyin_result __junk_9_Msg__copyIn(c_base base, const class junk_9::Msg *from, struct _junk_9_Msg *to);
extern  void __junk_9_Msg__copyOut(const void *_from, void *_to);
struct _junk_9_Msg {
    c_long id;
    c_string message;
    c_longlong constraint_deadline_duetime;
    c_longlong constraint_freshness_gentime;
};

#undef OS_API
#endif

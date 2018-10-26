#ifndef SPLASH_MESSAGESPLTYPES_H
#define SPLASH_MESSAGESPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "splash_message_DCPS.hpp"


extern c_metaObject __splash_message_splash_message__load (c_base base);

extern const char *splash_message_new_record_metaDescriptor[];
extern const int splash_message_new_record_metaDescriptorArrLength;
extern const int splash_message_new_record_metaDescriptorLength;
extern c_metaObject __splash_message_new_record__load (c_base base);
struct _splash_message_new_record ;
extern  v_copyin_result __splash_message_new_record__copyIn(c_base base, const class splash_message::new_record *from, struct _splash_message_new_record *to);
extern  void __splash_message_new_record__copyOut(const void *_from, void *_to);
struct _splash_message_new_record {
    c_bool a;
    c_string sibal;
};

extern const char *splash_message_msg0_metaDescriptor[];
extern const int splash_message_msg0_metaDescriptorArrLength;
extern const int splash_message_msg0_metaDescriptorLength;
extern c_metaObject __splash_message_msg0__load (c_base base);
struct _splash_message_msg0 ;
extern  v_copyin_result __splash_message_msg0__copyIn(c_base base, const class splash_message::msg0 *from, struct _splash_message_msg0 *to);
extern  void __splash_message_msg0__copyOut(const void *_from, void *_to);
struct _splash_message_msg0 {
    c_long id;
    c_bool k;
};

extern const char *splash_message_msg1_metaDescriptor[];
extern const int splash_message_msg1_metaDescriptorArrLength;
extern const int splash_message_msg1_metaDescriptorLength;
extern c_metaObject __splash_message_msg1__load (c_base base);
struct _splash_message_msg1 ;
extern  v_copyin_result __splash_message_msg1__copyIn(c_base base, const class splash_message::msg1 *from, struct _splash_message_msg1 *to);
extern  void __splash_message_msg1__copyOut(const void *_from, void *_to);
struct _splash_message_msg1 {
    c_long id;
    c_double a;
    c_double b;
};

extern const char *splash_message_msg2_metaDescriptor[];
extern const int splash_message_msg2_metaDescriptorArrLength;
extern const int splash_message_msg2_metaDescriptorLength;
extern c_metaObject __splash_message_msg2__load (c_base base);
struct _splash_message_msg2 ;
extern  v_copyin_result __splash_message_msg2__copyIn(c_base base, const class splash_message::msg2 *from, struct _splash_message_msg2 *to);
extern  void __splash_message_msg2__copyOut(const void *_from, void *_to);
struct _splash_message_msg2 {
    c_long id;
    c_short sibal;
};

extern const char *splash_message_msg3_metaDescriptor[];
extern const int splash_message_msg3_metaDescriptorArrLength;
extern const int splash_message_msg3_metaDescriptorLength;
extern c_metaObject __splash_message_msg3__load (c_base base);
struct _splash_message_msg3 ;
extern  v_copyin_result __splash_message_msg3__copyIn(c_base base, const class splash_message::msg3 *from, struct _splash_message_msg3 *to);
extern  void __splash_message_msg3__copyOut(const void *_from, void *_to);
struct _splash_message_msg3 {
    c_long id;
    c_string str;
    c_longlong sisi;
};

extern const char *splash_message_msg4_metaDescriptor[];
extern const int splash_message_msg4_metaDescriptorArrLength;
extern const int splash_message_msg4_metaDescriptorLength;
extern c_metaObject __splash_message_msg4__load (c_base base);
struct _splash_message_msg4 ;
extern  v_copyin_result __splash_message_msg4__copyIn(c_base base, const class splash_message::msg4 *from, struct _splash_message_msg4 *to);
extern  void __splash_message_msg4__copyOut(const void *_from, void *_to);
struct _splash_message_msg4 {
    c_long id;
    c_float a;
    c_long kk;
};

extern const char *splash_message_msg5_metaDescriptor[];
extern const int splash_message_msg5_metaDescriptorArrLength;
extern const int splash_message_msg5_metaDescriptorLength;
extern c_metaObject __splash_message_msg5__load (c_base base);
struct _splash_message_msg5 ;
extern  v_copyin_result __splash_message_msg5__copyIn(c_base base, const class splash_message::msg5 *from, struct _splash_message_msg5 *to);
extern  void __splash_message_msg5__copyOut(const void *_from, void *_to);
struct _splash_message_msg5 {
    c_long id;
    c_char cc;
    struct _splash_message_new_record A;
};

#undef OS_API
#endif

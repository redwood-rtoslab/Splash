#ifndef FUSION_DATASPLTYPES_H
#define FUSION_DATASPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "fusion_data_DCPS.hpp"


extern c_metaObject __fusion_data_fusion_data__load (c_base base);

extern c_metaObject __fusion_data_QQ__load (c_base base);
typedef c_string _fusion_data_QQ[10];

extern const char *fusion_data_Msg_metaDescriptor[];
extern const int fusion_data_Msg_metaDescriptorArrLength;
extern const int fusion_data_Msg_metaDescriptorLength;
extern c_metaObject __fusion_data_Msg__load (c_base base);
struct _fusion_data_Msg ;
extern  v_copyin_result __fusion_data_Msg__copyIn(c_base base, const class fusion_data::Msg *from, struct _fusion_data_Msg *to);
extern  void __fusion_data_Msg__copyOut(const void *_from, void *_to);
struct _fusion_data_Msg {
    c_long fusion_data_id;
    c_long received_port[9];
    c_long data_id[9];
    c_string message[9];
    c_longlong constraint_deadline_duetime;
    c_longlong constraint_freshness_gentime;
    _fusion_data_QQ test;
};

#undef OS_API
#endif

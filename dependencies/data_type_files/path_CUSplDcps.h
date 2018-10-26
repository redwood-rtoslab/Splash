#ifndef PATH_CUSPLTYPES_H
#define PATH_CUSPLTYPES_H

#include <c_base.h>
#include <c_misc.h>
#include <c_sync.h>
#include <c_collection.h>
#include <c_field.h>
#include <v_copyIn.h>

#include "path_CU_DCPS.hpp"


extern c_metaObject __path_CU_path_CU__load (c_base base);

extern const char *path_CU_Msg_metaDescriptor[];
extern const int path_CU_Msg_metaDescriptorArrLength;
extern const int path_CU_Msg_metaDescriptorLength;
extern c_metaObject __path_CU_Msg__load (c_base base);
struct _path_CU_Msg ;
extern  v_copyin_result __path_CU_Msg__copyIn(c_base base, const class path_CU::Msg *from, struct _path_CU_Msg *to);
extern  void __path_CU_Msg__copyOut(const void *_from, void *_to);
struct _path_CU_Msg {
    c_long id;
    c_double steering_input;
};

#undef OS_API
#endif

#include "pmmem.h"
#include "genclip.h"
#include "harness.h"
#include "pmsetup.h"
#include "resource.h"
#include "tokenval.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

br_tv_template_entry matchTemplateEntries[6] = {
    { BRT_USE_T, NULL, 0, 2, 3, 0, 0 },
    { BRT_PIXEL_TYPE_U8, NULL, 4, 2, 3, 0, 0 },
    { BRT_PIXEL_BITS_I32, NULL, 8, 2, 3, 0, 0 },
    { BRT_RENDERER_O, NULL, 20, 2, 3, 0, 0 },
    { BRT_WIDTH_I32, NULL, 12, 2, 3, 0, 0 },
    { BRT_HEIGHT_I32, NULL, 16, 2, 3, 0, 0 }
};
br_device_pixelmap_dispatch devicePixelmapDispatch; // = {
//     NULL,
//     NULL,
//     NULL,
//     NULL,
//     &_M_br_device_pixelmap_mem_free,
//     &_M_br_device_pixelmap_mem_identifier,
//     &_M_br_device_pixelmap_mem_type,
//     &_M_br_device_pixelmap_mem_isType,
//     &_M_br_device_pixelmap_mem_validSource,
//     &_M_br_device_pixelmap_mem_space,
//     &_M_br_device_pixelmap_mem_queryTemplate,
//     NULL, //&_M_br_object_query,
//     NULL, //&_M_br_object_queryBuffer,
//     NULL, //&_M_br_object_queryMany,
//     NULL, //&_M_br_object_queryManySize,
//     NULL, //&_M_br_object_queryAll,
//     NULL, //&_M_br_object_queryAllSize,
//     &_M_br_device_pixelmap_mem_validSource,
//     &_M_br_device_pixelmap_mem_resize,
//     &_M_br_device_pixelmap_mem_match,
//     &_M_br_device_pixelmap_mem_allocateSub,
//     &_M_br_device_pixelmap_mem_copyTo,
//     &_M_br_device_pixelmap_mem_copyTo,
//     &_M_br_device_pixelmap_mem_copyFrom,
//     &_M_br_device_pixelmap_mem_fill,
//     NULL, //&_M_br_device_pixelmap_gen_doubleBuffer,
//     NULL, //&_M_br_device_pixelmap_gen_copyDirty,
//     NULL, //&_M_br_device_pixelmap_gen_copyToDirty,
//     NULL, //&_M_br_device_pixelmap_gen_copyFromDirty,
//     NULL, //&_M_br_device_pixelmap_gen_fillDirty,
//     NULL, //&_M_br_device_pixelmap_gen_doubleBufferDirty,
//     NULL, //&_M_br_device_pixelmap_gen_rectangle,
//     NULL, //&_M_br_device_pixelmap_gen_rectangle2,
//     &_M_br_device_pixelmap_mem_rectangleCopyTo,
//     &_M_br_device_pixelmap_mem_rectangleCopyTo,
//     &_M_br_device_pixelmap_mem_rectangleCopyFrom,
//     &_M_br_device_pixelmap_mem_rectangleStretchCopyFrom,
//     &_M_br_device_pixelmap_mem_rectangleStretchCopyFrom,
//     &_M_br_device_pixelmap_mem_rectangleStretchCopyFrom,
//     &_M_br_device_pixelmap_mem_rectangleFill,
//     &_M_br_device_pixelmap_mem_pixelSet,
//     &_M_br_device_pixelmap_mem_line,
//     &_M_br_device_pixelmap_mem_copyBits,
//     NULL, //&_M_br_device_pixelmap_gen_text,
//     NULL, //&_M_br_device_pixelmap_gen_textBounds,
//     &_M_br_device_pixelmap_mem_directLock,
//     &_M_br_device_pixelmap_mem_directLock,
//     &_M_br_device_pixelmap_mem_directLock,
//     &_M_br_device_pixelmap_mem_pixelQuery,
//     &_M_br_device_pixelmap_mem_pixelAddressQuery,
//     &_M_br_device_pixelmap_mem_pixelAddressSet,
//     &_M_br_device_pixelmap_mem_originSet,
//     &_M_br_device_pixelmap_mem_directLock,
//     &_M_br_device_pixelmap_mem_directLock,
//     &_M_br_device_pixelmap_mem_directLock,
//     &_M_br_device_pixelmap_mem_directLock
// };

br_tv_template_entry devicePixelmapTemplateEntries[4];
pm_type_info pmTypeInfo[30] = {
    { 1u, 1u, 32u, 1u },
    { 2u, 1u, 16u, 1u },
    { 4u, 1u, 8u, 1u },
    { 8u, 1u, 4u, 1u },
    { 16u, 2u, 2u, 2u },
    { 16u, 2u, 2u, 2u },
    { 24u, 3u, 4u, 2u },
    { 32u, 4u, 1u, 2u },
    { 32u, 4u, 1u, 10u },
    { 16u, 1u, 2u, 16u },
    { 32u, 1u, 1u, 16u },
    { 16u, 2u, 4u, 4u },
    { 32u, 4u, 4u, 4u },
    { 8u, 1u, 4u, 8u },
    { 16u, 2u, 2u, 9u },
    { 54u, 0u, 0u, 0u },
    { 4u, 0u, 5u, 3u },
    { 0u, 0u, 0u, 0u },
    { 69u, 0u, 0u, 0u },
    { 52u, 0u, 5u, 13u },
    { 0u, 0u, 0u, 0u },
    { 72u, 0u, 0u, 0u },
    { 54u, 0u, 5u, 13u },
    { 0u, 0u, 0u, 0u },
    { 75u, 0u, 0u, 0u },
    { 44u, 0u, 5u, 12u },
    { 0u, 0u, 0u, 0u },
    { 1u, 0u, 0u, 0u },
    { 0u, 0u, 0u, 0u },
    { 0u, 0u, 0u, 0u }
};

char rscid[53];

// Offset: 26
// Size: 498
// EAX: type
// EDX: w
// EBX: h
// ECX: pixels
br_device_pixelmap* DevicePixelmapMemAllocate(br_uint_8 type, br_uint_16 w, br_uint_16 h, void* pixels, int flags) {
    br_device_pixelmap* pm;
    pm_type_info* tip;

    tip = &pmTypeInfo[type];
    pm = BrResAllocate(_pixelmap.res, sizeof(br_device_pixelmap), BR_MEMORY_PIXELMAP);
    //pm->dispatch = &devicePixelmapDispatch;
    pm->pm_identifier = NULL;
    pm->pm_map = NULL;
    pm->pm_flags = BR_PMF_LINEAR;
    pm->pm_copy_function = BR_PMCOPY_NORMAL;
    pm->pm_base_x = 0;
    pm->pm_base_y = 0;

    pm->pm_origin_x = 0;
    pm->pm_origin_y = 0;
    pm->pm_type = type;
    pm->pm_width = w;
    pm->pm_height = h;
    //8 bits, 1, 4 align, 1

    //v11 = (tip->align + w - 1) / tip->align * tip->align * tip->bits;
    //pm->pm_row_bytes = (v11 - (__CFSHL__(v11 >> 31, 3) + 8 * (v11 >> 31))) >> 3;
    // TODO: calculate this differently
    pm->pm_row_bytes = w;
    if ((8 * pm->pm_row_bytes % tip->bits) == 0) {
        pm->pm_flags |= BR_PMF_ROW_WHOLEPIXELS;
    }
    if (!(flags & BR_PMAF_NO_PIXELS)) {
        if (pixels) {
            pm->pm_pixels = pixels;
        } else {
            pm->pm_pixels = BrResAllocate(pm, pm->pm_height * pm->pm_row_bytes, BR_MEMORY_PIXELS);
        }
    }
    //TODO: not sure we need this
    //pm->pm_pixels_qualifier = (unsigned __int16)_GetSysQual();
    if (flags & BR_PMAF_INVERTED) {
        pm->pm_pixels = (char*)pm->pm_pixels + (pm->pm_height - 1) * pm->pm_row_bytes;
        pm->pm_row_bytes *= -1;
    }
    return pm;
}

// Offset: 539
// Size: 54
// EAX: pm
void CheckDispatch(br_device_pixelmap* pm) {
    // if (!pm->dispatch) {
    //     pm->dispatch = &devicePixelmapDispatch;
    // }
}

// Offset: 631
// Size: 222
br_error _M_br_device_pixelmap_mem_allocateSub(br_device_pixelmap* self, br_device_pixelmap** newpm, br_rectangle* rect) {
    br_device_pixelmap* pm;
    br_rectangle out;
    LOG_TRACE("(%p, %p, %p)", self, newpm, rect);

    if (PixelmapRectangleClip(&out, rect, (br_pixelmap*)self) == BR_CLIP_REJECT) {
        return 4098;
    }
    pm = (br_device_pixelmap*)BrResAllocate(_pixelmap.res, sizeof(br_pixelmap), BR_MEMORY_PIXELMAP);
    memcpy(pm, self, sizeof(br_pixelmap));
    pm->pm_base_x += out.x;
    pm->pm_base_y += out.y;
    pm->pm_width = out.w;
    pm->pm_height = out.h;
    pm->pm_origin_x = 0;
    pm->pm_origin_y = 0;
    pm->pm_stored = 0;
    pm->dispatch = &devicePixelmapDispatch;
    if (pm->pm_width != self->pm_width) {
        pm->pm_flags &= 0xFDu; //unset BR_PMF_LINEAR
    }
    *newpm = pm;
    return 0;
}

// Offset: 884
// Size: 42
void _M_br_device_pixelmap_mem_free(br_device_pixelmap* self) {
    BrResFree(self);
}

// Offset: 963
// Size: 42
char* _M_br_device_pixelmap_mem_identifier(br_device_pixelmap* self) {
    NOT_IMPLEMENTED();
}

// Offset: 1036
// Size: 40
br_token _M_br_device_pixelmap_mem_type(br_device_pixelmap* self) {
    NOT_IMPLEMENTED();
}

// Offset: 1109
// Size: 67
br_boolean _M_br_device_pixelmap_mem_isType(br_device_pixelmap* self, br_token t) {
    NOT_IMPLEMENTED();
}

// Offset: 1209
// Size: 40
br_device* _M_br_device_pixelmap_mem_device(br_device_pixelmap* self) {
    NOT_IMPLEMENTED();
}

// Offset: 1281
// Size: 48
br_int_32 _M_br_device_pixelmap_mem_space(br_device_pixelmap* self) {
    NOT_IMPLEMENTED();
}

// Offset: 1369
// Size: 77
br_tv_template* _M_br_device_pixelmap_mem_queryTemplate(br_device_pixelmap* self) {
    NOT_IMPLEMENTED();
}

// Offset: 1484
// Size: 40
br_error _M_br_device_pixelmap_mem_validSource(br_device_pixelmap* self, br_object* h) {
    NOT_IMPLEMENTED();
}

// Offset: 1557
// Size: 411
br_error _M_br_device_pixelmap_mem_resize(br_device_pixelmap* self, br_int_32 width, br_int_32 height) {
    char* pixels;
    pm_type_info* tip;
    br_int_16 old_row_bytes;
    NOT_IMPLEMENTED();
}

// Offset: 2000
// Size: 771
br_error _M_br_device_pixelmap_mem_match(br_device_pixelmap* self, br_device_pixelmap** newpm, br_token_value* tv) {
    match_tokens mt;
    br_int_32 count;
    br_device_pixelmap* pm;
    br_int_32 bytes;
    br_int_32 r;
    LOG_TRACE("(%p, %p, %p)", self, newpm, tv);

    if (!_pixelmap.pixelmap_match_template) {
        _pixelmap.pixelmap_match_template = BrTVTemplateAllocate(_pixelmap.res, matchTemplateEntries, 6);
        if (!_pixelmap.pixelmap_match_template) {
            LOG_WARN("x");
            return 4098;
        }
    }
    mt.pixel_type = self->pm_type;
    mt.width = self->pm_width;
    mt.height = self->pm_height;

    // TOOD: We haven't implemented BrTokenValueSetMany - just emulate enough for now
    mt.use = tv[1].t; // se BrPixelmapMatch
    mt.pixel_bits = 16;

    BrTokenValueSetMany(&mt, &count, 0, tv, _pixelmap.pixelmap_match_template);
    // if ( (unsigned int)mt.use < 0x64 )
    // {
    //     if ( mt.use != 84 )
    //         return 4098;
    //     if ( mt.pixel_bits < 0x10u )
    //     {
    //         if ( mt.pixel_bits )
    //             return 4098;
    //     }
    //     else if ( mt.pixel_bits > 0x10u )
    //     {
    //         if ( mt.pixel_bits != 32 )
    //             return 4098;
    //         mt.pixel_type = 12;
    //         goto LABEL_18;
    //     }
    //     mt.pixel_type = 11;
    //     goto LABEL_18;
    // }
    // if ( (unsigned int)mt.use > 0x66 )
    // {
    //     if ( (unsigned int)mt.use >= 0x116 )
    //     {
    //         if ( (unsigned int)mt.use > 0x116 && mt.use != 379 )
    //             return 4098;
    //         goto LABEL_18;
    //     }
    //     return 4098;
    // }

    if (mt.use == BRT_DEPTH) {
        pm = DevicePixelmapMemAllocate(mt.pixel_type, mt.width, mt.height, NULL, (self->pm_row_bytes < 0) | BR_PMAF_NO_PIXELS);
        r = abs(self->pm_row_bytes);
        bytes = (signed int)pmTypeInfo[self->pm_type].bits >> 3;
        pm->pm_row_bytes = ((signed int)pmTypeInfo[pm->pm_type].bits >> 3) * (unsigned int)((bytes + r - 1) / bytes);
        pm->pm_pixels = BrResAllocate(pm, pm->pm_height * pm->pm_row_bytes, BR_MEMORY_PIXELS);
        if (pm->pm_width * ((signed int)pmTypeInfo[pm->pm_type].bits >> 3) == pm->pm_row_bytes)
            pm->pm_flags |= BR_PMF_LINEAR;
        else {
            pm->pm_flags &= 0xFDu;
        }
        if (self->pm_row_bytes < 0) {
            pm->pm_row_bytes = -pm->pm_row_bytes;
            // TODO: is this a bug in the original code? We say row_bytes is positive, but still set the pixels pointer to the bottom
            // of the data
            pm->pm_pixels = (char*)pm->pm_pixels + (pm->pm_height - 1) * pm->pm_row_bytes;
        }
    } else {
        pm = DevicePixelmapMemAllocate(mt.pixel_type, mt.width, mt.height, NULL, self->pm_row_bytes < 0);
    }
    pm->pm_origin_x = self->pm_origin_x;
    pm->pm_origin_y = self->pm_origin_y;
    //self->dispatch = pm;
    *newpm = pm;
    return 0;

    // br_pixelmap* ret = BrPixelmapAllocate(src->type, src->width, src->height, NULL, BR_PMAF_NORMAL);

    // if (match_type == BR_PMMATCH_DEPTH_16) {
    //     ret->type = BR_PMT_DEPTH_16;
    //     ret->flags |= BR_PMAF_DEPTHBUFFER;
    // } else {
    //     ret->flags |= BR_PMAF_OFFSCREEN;
    // }
}

// Offset: 2804
// Size: 759
br_error _M_br_device_pixelmap_mem_copyTo(br_device_pixelmap* self, br_device_pixelmap* src) {
    br_int_8 bytes;
    NOT_IMPLEMENTED();
}

// Offset: 3598
// Size: 759
br_error _M_br_device_pixelmap_mem_copyFrom(br_device_pixelmap* self, br_device_pixelmap* dest) {
    br_int_8 bytes;
    NOT_IMPLEMENTED();
}

// Offset: 4388
// Size: 530
br_error _M_br_device_pixelmap_mem_fill(br_device_pixelmap* self, br_uint_32 colour) {
    br_int_8 bytes;
    NOT_IMPLEMENTED();
}

// Offset: 4957
// Size: 40
br_error _M_br_device_pixelmap_mem_doubleBuffer(br_device_pixelmap* self, br_device_pixelmap* src) {
    NOT_IMPLEMENTED();
}

// Offset: 5033
// Size: 40
br_error _M_br_device_pixelmap_mem_copyDirty(br_device_pixelmap* self, br_device_pixelmap* src, br_rectangle* dirty, br_int_32 num_rects) {
    NOT_IMPLEMENTED();
}

// Offset: 5111
// Size: 40
br_error _M_br_device_pixelmap_mem_copyToDirty(br_device_pixelmap* self, br_device_pixelmap* src, br_rectangle* dirty, br_int_32 num_rects) {
    NOT_IMPLEMENTED();
}

// Offset: 5191
// Size: 40
br_error _M_br_device_pixelmap_mem_copyFromDirty(br_device_pixelmap* self, br_device_pixelmap* src, br_rectangle* dirty, br_int_32 num_rects) {
    NOT_IMPLEMENTED();
}

// Offset: 5267
// Size: 40
br_error _M_br_device_pixelmap_mem_fillDirty(br_device_pixelmap* self, br_uint_32 colour, br_rectangle* dirty, br_int_32 num_rects) {
    NOT_IMPLEMENTED();
}

// Offset: 5351
// Size: 40
br_error _M_br_device_pixelmap_mem_doubleBufferDirty(br_device_pixelmap* self, br_device_pixelmap* src, br_rectangle* dirty, br_int_32 num_rects) {
    NOT_IMPLEMENTED();
}

// Offset: 5433
// Size: 935
br_error _M_br_device_pixelmap_mem_rectangleCopyTo(br_device_pixelmap* self, br_point* p, br_device_pixelmap* src, br_rectangle* r) {
    int bytes;
    br_rectangle ar;
    br_point ap;
    NOT_IMPLEMENTED();
}

// Offset: 6412
// Size: 935
br_error _M_br_device_pixelmap_mem_rectangleCopyFrom(br_device_pixelmap* self, br_point* p, br_device_pixelmap* dest, br_rectangle* r) {
    int bytes;
    br_rectangle ar;
    br_point ap;
    NOT_IMPLEMENTED();
}

// Offset: 7396
// Size: 40
br_error _M_br_device_pixelmap_mem_rectangleStretchCopyTo(br_device_pixelmap* self, br_rectangle* destinationRectangle, br_device_pixelmap* src, br_rectangle* sourceRectangle) {
    NOT_IMPLEMENTED();
}

// Offset: 7487
// Size: 40
br_error _M_br_device_pixelmap_mem_rectangleStretchCopyFrom(br_device_pixelmap* self, br_rectangle* d, br_device_pixelmap* src, br_rectangle* s) {
    NOT_IMPLEMENTED();
}

// Offset: 7567
// Size: 596
br_error _M_br_device_pixelmap_mem_rectangleFill(br_device_pixelmap* self, br_rectangle* rect, br_uint_32 colour) {
    br_rectangle arect;
    br_int_8 bytes;
    NOT_IMPLEMENTED();
}

// Offset: 8198
// Size: 196
br_error _M_br_device_pixelmap_mem_pixelSet(br_device_pixelmap* self, br_point* p, br_uint_32 colour) {
    br_point ap;
    br_int_8 bytes;
    NOT_IMPLEMENTED();
}

// Offset: 8425
// Size: 8332
br_error _M_br_device_pixelmap_mem_line(br_device_pixelmap* self, br_point* s, br_point* e, br_uint_32 colour) {
    int dx;
    int dy;
    int incr1;
    int incr2;
    int D;
    int x;
    int y;
    int xend;
    int c;
    int pixels_left;
    int x1;
    int y1;
    int sign_x;
    int sign_y;
    int step;
    int reverse;
    int i;
    char* dest;
    int bytes;
    br_point as;
    br_point ae;
    NOT_IMPLEMENTED();
}

// Offset: 16792
// Size: 260
br_error _M_br_device_pixelmap_mem_copyBits(br_device_pixelmap* self, br_point* point, br_uint_8* src, br_uint_16 s_stride, br_rectangle* bit_rect, br_uint_32 colour) {
    int bytes;
    int bit;
    br_rectangle ar;
    br_point ap;
    NOT_IMPLEMENTED();
}

// Offset: 17089
// Size: 199
br_error _M_br_device_pixelmap_mem_pixelQuery(br_device_pixelmap* self, br_uint_32* pcolour, br_point* p) {
    br_point ap;
    br_int_8 bytes;
    NOT_IMPLEMENTED();
}

// Offset: 17332
// Size: 200
br_error _M_br_device_pixelmap_mem_pixelAddressQuery(br_device_pixelmap* self, void** pptr, br_uint_32* pqual, br_point* p) {
    br_int_8 bytes;
    br_point ap;
    NOT_IMPLEMENTED();
}

// Offset: 17574
// Size: 72
br_error _M_br_device_pixelmap_mem_pixelAddressSet(br_device_pixelmap* self, void* ptr, br_uint_32* qual) {
    NOT_IMPLEMENTED();
}

// Offset: 17682
// Size: 67
br_error _M_br_device_pixelmap_mem_originSet(br_device_pixelmap* self, br_point* p) {
    NOT_IMPLEMENTED();
}

// Offset: 17783
// Size: 40
br_error _M_br_device_pixelmap_mem_rowSize(br_device_pixelmap* self, br_size_t* sizep) {
    NOT_IMPLEMENTED();
}

// Offset: 17858
// Size: 40
br_error _M_br_device_pixelmap_mem_rowQuery(br_device_pixelmap* self, void* buffer, br_size_t buffer_size, br_int_32 row) {
    NOT_IMPLEMENTED();
}

// Offset: 17931
// Size: 40
br_error _M_br_device_pixelmap_mem_rowSet(br_device_pixelmap* self, void* buffer, br_size_t buffer_size, br_int_32 row) {
    NOT_IMPLEMENTED();
}

// Offset: 18003
// Size: 40
br_error _M_br_device_pixelmap_mem_flush(br_device_pixelmap* self) {
    NOT_IMPLEMENTED();
}

// Offset: 18081
// Size: 40
br_error _M_br_device_pixelmap_mem_synchronise(br_device_pixelmap* self, br_token sync_type, br_boolean block) {
    NOT_IMPLEMENTED();
}

// Offset: 18158
// Size: 40
br_error _M_br_device_pixelmap_mem_directLock(br_device_pixelmap* self, br_boolean block) {
    NOT_IMPLEMENTED();
}

// Offset: 18237
// Size: 40
br_error _M_br_device_pixelmap_mem_directUnlock(br_device_pixelmap* self) {
    NOT_IMPLEMENTED();
}

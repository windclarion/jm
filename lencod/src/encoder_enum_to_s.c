#include "conformance.h"
#include "defines.h"
#include "errdo.h"
#include "me_epzs_common.h"
#include "me_hme.h"
#include "pred_struct_types.h"
#include "sei.h"


const char* LevelId_to_s(int n)
{
    switch(n) {
        case LEVEL_1: return "LEVEL_1";
        case LEVEL_1b: return "LEVEL_1b";
        case LEVEL_1_1: return "LEVEL_1_1";
        case LEVEL_1_2: return "LEVEL_1_2";
        case LEVEL_1_3: return "LEVEL_1_3";
        case LEVEL_2: return "LEVEL_2";
        case LEVEL_2_1: return "LEVEL_2_1";
        case LEVEL_2_2: return "LEVEL_2_2";
        case LEVEL_3: return "LEVEL_3";
        case LEVEL_3_1: return "LEVEL_3_1";
        case LEVEL_3_2: return "LEVEL_3_2";
        case LEVEL_4: return "LEVEL_4";
        case LEVEL_4_1: return "LEVEL_4_1";
        case LEVEL_4_2: return "LEVEL_4_2";
        case LEVEL_5: return "LEVEL_5";
        case LEVEL_5_1: return "LEVEL_5_1";
        case LEVEL_5_2: return "LEVEL_5_2";
        case LEVEL_6: return "LEVEL_6";
        case LEVEL_6_1: return "LEVEL_6_1";
        case LEVEL_6_2: return "LEVEL_6_2";
        case LEVEL_UNCONSTRAINED: return "LEVEL_UNCONSTRAINED";
        default: return "error enum LevelId";
    }
}
const char* ProfileIDC_to_s(int n)
{
    switch(n) {
        case NO_PROFILE: return "NO_PROFILE";
        case FREXT_CAVLC444: return "FREXT_CAVLC444";
        case BASELINE: return "BASELINE";
        case MAIN: return "MAIN";
        case EXTENDED: return "EXTENDED";
        case FREXT_HP: return "FREXT_HP";
        case FREXT_Hi10P: return "FREXT_Hi10P";
        case FREXT_Hi422: return "FREXT_Hi422";
        case FREXT_Hi444: return "FREXT_Hi444";
        case MULTIVIEW_HIGH: return "MULTIVIEW_HIGH";
        case STEREO_HIGH: return "STEREO_HIGH";
        default: return "error enum ProfileIDC";
    }
}
const char* MBModeTypes_to_s(int n)
{
    switch(n) {
        case PSKIP: return "PSKIP/BSKIP_DIRECT";
        case P16x16: return "P16x16";
        case P16x8: return "P16x8";
        case P8x16: return "P8x16";
        case SMB8x8: return "SMB8x8";
        case SMB8x4: return "SMB8x4";
        case SMB4x8: return "SMB4x8";
        case SMB4x4: return "SMB4x4";
        case P8x8: return "P8x8";
        case I4MB: return "I4MB";
        case I16MB: return "I16MB";
        case IBLOCK: return "IBLOCK";
        case SI4MB: return "SI4MB";
        case I8MB: return "I8MB";
        case IPCM: return "IPCM";
        case MAXMODE: return "MAXMODE";
        default: return "error enum MBModeTypes";
    }
}
const char* DirectModes_to_s(int n)
{
    switch(n) {
        case DIR_TEMPORAL: return "DIR_TEMPORAL";
        case DIR_SPATIAL: return "DIR_SPATIAL";
        default: return "error enum DirectModes";
    }
}
const char* CAVLCBlockTypes_to_s(int n)
{
    switch(n) {
        case LUMA: return "LUMA";
        case LUMA_INTRA16x16DC: return "LUMA_INTRA16x16DC";
        case LUMA_INTRA16x16AC: return "LUMA_INTRA16x16AC";
        case CB: return "CB";
        case CB_INTRA16x16DC: return "CB_INTRA16x16DC";
        case CB_INTRA16x16AC: return "CB_INTRA16x16AC";
        case CR: return "CR";
        case CR_INTRA16x16DC: return "CR_INTRA16x16DC";
        case CR_INTRA16x16AC: return "CR_INTRA16x16AC";
        default: return "error enum CAVLCBlockTypes";
    }
}
const char* CABACBlockTypes_to_s(int n)
{
    switch(n) {
        case LUMA_16DC: return "LUMA_16DC";
        case LUMA_16AC: return "LUMA_16AC";
        case LUMA_8x8: return "LUMA_8x8";
        case LUMA_8x4: return "LUMA_8x4";
        case LUMA_4x8: return "LUMA_4x8";
        case LUMA_4x4: return "LUMA_4x4";
        case CHROMA_DC: return "CHROMA_DC";
        case CHROMA_AC: return "CHROMA_AC";
        case CHROMA_DC_2x4: return "CHROMA_DC_2x4";
        case CHROMA_DC_4x4: return "CHROMA_DC_4x4";
        case CB_16DC: return "CB_16DC";
        case CB_16AC: return "CB_16AC";
        case CB_8x8: return "CB_8x8";
        case CB_8x4: return "CB_8x4";
        case CB_4x8: return "CB_4x8";
        case CB_4x4: return "CB_4x4";
        case CR_16DC: return "CR_16DC";
        case CR_16AC: return "CR_16AC";
        case CR_8x8: return "CR_8x8";
        case CR_8x4: return "CR_8x4";
        case CR_4x8: return "CR_4x8";
        case CR_4x4: return "CR_4x4";
        default: return "error enum CABACBlockTypes";
    }
}
const char* ColorComponent_to_s(int n)
{
    switch(n) {
        case Y_COMP: return "Y_COMP";
        case U_COMP: return "U_COMP";
        case V_COMP: return "V_COMP";
        case R_COMP: return "R_COMP";
        case G_COMP: return "G_COMP";
        case B_COMP: return "B_COMP";
        case T_COMP: return "T_COMP";
        default: return "error enum ColorComponent";
    }
}
const char* I4x4PredModes_to_s(int n)
{
    switch(n) {
        case VERT_PRED: return "VERT_PRED";
        case HOR_PRED: return "HOR_PRED";
        case DC_PRED: return "DC_PRED";
        case DIAG_DOWN_LEFT_PRED: return "DIAG_DOWN_LEFT_PRED";
        case DIAG_DOWN_RIGHT_PRED: return "DIAG_DOWN_RIGHT_PRED";
        case VERT_RIGHT_PRED: return "VERT_RIGHT_PRED";
        case HOR_DOWN_PRED: return "HOR_DOWN_PRED";
        case VERT_LEFT_PRED: return "VERT_LEFT_PRED";
        case HOR_UP_PRED: return "HOR_UP_PRED";
        default: return "error enum I4x4PredModes";
    }
}
const char* I16x16PredModes_to_s(int n)
{
    switch(n) {
        case VERT_PRED_16: return "VERT_PRED_16";
        case HOR_PRED_16: return "HOR_PRED_16";
        case DC_PRED_16: return "DC_PRED_16";
        case PLANE_16: return "PLANE_16";
        default: return "error enum I16x16PredModes";
    }
}
const char* I8x8PredModes_to_s(int n)
{
    switch(n) {
        case DC_PRED_8: return "DC_PRED_8";
        case HOR_PRED_8: return "HOR_PRED_8";
        case VERT_PRED_8: return "VERT_PRED_8";
        case PLANE_8: return "PLANE_8";
        default: return "error enum I8x8PredModes";
    }
}
const char* anonymous_enum_1_to_s(int n)
{
    switch(n) {
        case EOS: return "EOS";
        case SOP: return "SOP";
        case SOS: return "SOS";
        default: return "error enum anonymous_enum_1";
    }
}
const char* MVPredTypes_to_s(int n)
{
    switch(n) {
        case MVPRED_MEDIAN: return "MVPRED_MEDIAN";
        case MVPRED_L: return "MVPRED_L";
        case MVPRED_U: return "MVPRED_U";
        case MVPRED_UR: return "MVPRED_UR";
        default: return "error enum MVPredTypes";
    }
}
const char* OTFMode_to_s(int n)
{
    switch(n) {
        case OTF_L0: return "OTF_L0";
        case OTF_L1: return "OTF_L1";
        case OTF_L2: return "OTF_L2";
        default: return "error enum OTFMode";
    }
}
const char* OTFFunction_to_s(int n)
{
    switch(n) {
        case OTF_ME: return "OTF_ME";
        case OTF_MC: return "OTF_MC";
        default: return "error enum OTFFunction";
    }
}
const char* DE_Type_to_s(int n)
{
    switch(n) {
        case LLN: return "LLN";
        case ROPE: return "ROPE";
        case RMPC: return "RMPC";
        default: return "error enum DE_Type";
    }
}
const char* EPZSPatterns_to_s(int n)
{
    switch(n) {
        case SDIAMOND: return "SDIAMOND";
        case SQUARE: return "SQUARE";
        case EDIAMOND: return "EDIAMOND";
        case LDIAMOND: return "LDIAMOND";
        case SBDIAMOND: return "SBDIAMOND";
        default: return "error enum EPZSPatterns";
    }
}
const char* HMEMECostCalcMethod_to_s(int n)
{
    switch(n) {
        case MECOST_CALC_RDNORM: return "MECOST_CALC_RDNORM";
        case MECOST_CALC_RDN_PLUS_MVN: return "MECOST_CALC_RDN_PLUS_MVN";
        case MECOST_CALC_RDN_PLUS_MVN_FAST: return "MECOST_CALC_RDN_PLUS_MVN_FAST";
        case MECOST_CALC_RDN_PLUS_NP: return "MECOST_CALC_RDN_PLUS_NP";
        case MECOST_CALC_RDN_PLUS_NP_FAST: return "MECOST_CALC_RDN_PLUS_NP_FAST";
        default: return "error enum HMEMECostCalcMethod";
    }
}
const char* SliceTypeToPop_to_s(int n)
{
    switch(n) {
        case POP_IDR: return "POP_IDR";
        case POP_INTRA: return "POP_INTRA";
        case POP_SP: return "POP_SP";
        default: return "error enum SliceTypeToPop";
    }
}
const char* SEI_type_to_s(int n)
{
    switch(n) {
        case SEI_BUFFERING_PERIOD: return "SEI_BUFFERING_PERIOD";
        case SEI_PIC_TIMING: return "SEI_PIC_TIMING";
        case SEI_PAN_SCAN_RECT: return "SEI_PAN_SCAN_RECT";
        case SEI_FILLER_PAYLOAD: return "SEI_FILLER_PAYLOAD";
        case SEI_USER_DATA_REGISTERED_ITU_T_T35: return "SEI_USER_DATA_REGISTERED_ITU_T_T35";
        case SEI_USER_DATA_UNREGISTERED: return "SEI_USER_DATA_UNREGISTERED";
        case SEI_RECOVERY_POINT: return "SEI_RECOVERY_POINT";
        case SEI_DEC_REF_PIC_MARKING_REPETITION: return "SEI_DEC_REF_PIC_MARKING_REPETITION";
        case SEI_SPARE_PIC: return "SEI_SPARE_PIC";
        case SEI_SCENE_INFO: return "SEI_SCENE_INFO";
        case SEI_SUB_SEQ_INFO: return "SEI_SUB_SEQ_INFO";
        case SEI_SUB_SEQ_LAYER_CHARACTERISTICS: return "SEI_SUB_SEQ_LAYER_CHARACTERISTICS";
        case SEI_SUB_SEQ_CHARACTERISTICS: return "SEI_SUB_SEQ_CHARACTERISTICS";
        case SEI_FULL_FRAME_FREEZE: return "SEI_FULL_FRAME_FREEZE";
        case SEI_FULL_FRAME_FREEZE_RELEASE: return "SEI_FULL_FRAME_FREEZE_RELEASE";
        case SEI_FULL_FRAME_SNAPSHOT: return "SEI_FULL_FRAME_SNAPSHOT";
        case SEI_PROGRESSIVE_REFINEMENT_SEGMENT_START: return "SEI_PROGRESSIVE_REFINEMENT_SEGMENT_START";
        case SEI_PROGRESSIVE_REFINEMENT_SEGMENT_END: return "SEI_PROGRESSIVE_REFINEMENT_SEGMENT_END";
        case SEI_MOTION_CONSTRAINED_SLICE_GROUP_SET: return "SEI_MOTION_CONSTRAINED_SLICE_GROUP_SET";
        case SEI_FILM_GRAIN_CHARACTERISTICS: return "SEI_FILM_GRAIN_CHARACTERISTICS";
        case SEI_DEBLOCKING_FILTER_DISPLAY_PREFERENCE: return "SEI_DEBLOCKING_FILTER_DISPLAY_PREFERENCE";
        case SEI_STEREO_VIDEO_INFO: return "SEI_STEREO_VIDEO_INFO";
        case SEI_POST_FILTER_HINTS: return "SEI_POST_FILTER_HINTS";
        case SEI_TONE_MAPPING: return "SEI_TONE_MAPPING";
        case SEI_SCALABILITY_INFO: return "SEI_SCALABILITY_INFO";
        case SEI_SUB_PIC_SCALABLE_LAYER: return "SEI_SUB_PIC_SCALABLE_LAYER";
        case SEI_NON_REQUIRED_LAYER_REP: return "SEI_NON_REQUIRED_LAYER_REP";
        case SEI_PRIORITY_LAYER_INFO: return "SEI_PRIORITY_LAYER_INFO";
        case SEI_LAYERS_NOT_PRESENT: return "SEI_LAYERS_NOT_PRESENT";
        case SEI_LAYER_DEPENDENCY_CHANGE: return "SEI_LAYER_DEPENDENCY_CHANGE";
        case SEI_SCALABLE_NESTING: return "SEI_SCALABLE_NESTING";
        case SEI_BASE_LAYER_TEMPORAL_HRD: return "SEI_BASE_LAYER_TEMPORAL_HRD";
        case SEI_QUALITY_LAYER_INTEGRITY_CHECK: return "SEI_QUALITY_LAYER_INTEGRITY_CHECK";
        case SEI_REDUNDANT_PIC_PROPERTY: return "SEI_REDUNDANT_PIC_PROPERTY";
        case SEI_TL0_DEP_REP_INDEX: return "SEI_TL0_DEP_REP_INDEX";
        case SEI_TL_SWITCHING_POINT: return "SEI_TL_SWITCHING_POINT";
        case SEI_PARALLEL_DECODING_INFO: return "SEI_PARALLEL_DECODING_INFO";
        case SEI_MVC_SCALABLE_NESTING: return "SEI_MVC_SCALABLE_NESTING";
        case SEI_VIEW_SCALABILITY_INFO: return "SEI_VIEW_SCALABILITY_INFO";
        case SEI_MULTIVIEW_SCENE_INFO: return "SEI_MULTIVIEW_SCENE_INFO";
        case SEI_MULTIVIEW_ACQUISITION_INFO: return "SEI_MULTIVIEW_ACQUISITION_INFO";
        case SEI_NON_REQUIRED_VIEW_COMPONENT: return "SEI_NON_REQUIRED_VIEW_COMPONENT";
        case SEI_VIEW_DEPENDENCY_CHANGE: return "SEI_VIEW_DEPENDENCY_CHANGE";
        case SEI_OPERATION_POINTS_NOT_PRESENT: return "SEI_OPERATION_POINTS_NOT_PRESENT";
        case SEI_BASE_VIEW_TEMPORAL_HRD: return "SEI_BASE_VIEW_TEMPORAL_HRD";
        case SEI_FRAME_PACKING_ARRANGEMENT: return "SEI_FRAME_PACKING_ARRANGEMENT";
        case SEI_MAX_ELEMENTS: return "SEI_MAX_ELEMENTS";
        default: return "error enum SEI_type";
    }
}

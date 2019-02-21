#include "frame.h"
#include "io_video.h"
#include "nalucommon.h"
#include "typedefs.h"
#include "types.h"


const char* ColorModel_to_s(int n)
{
    switch(n) {
        case CM_UNKNOWN: return "CM_UNKNOWN";
        case CM_YUV: return "CM_YUV";
        case CM_RGB: return "CM_RGB";
        case CM_XYZ: return "CM_XYZ";
        default: return "error enum ColorModel";
    }
}
const char* ColorFormat_to_s(int n)
{
    switch(n) {
        case CF_UNKNOWN: return "CF_UNKNOWN";
        case YUV400: return "YUV400";
        case YUV420: return "YUV420";
        case YUV422: return "YUV422";
        case YUV444: return "YUV444";
        default: return "error enum ColorFormat";
    }
}
const char* PixelFormat_to_s(int n)
{
    switch(n) {
        case PF_UNKNOWN: return "PF_UNKNOWN";
        case UYVY: return "UYVY";
        case YUYV: return "YUYV/YUY2";
        case YVYU: return "YVYU";
        case BGR: return "BGR";
        case V210: return "V210";
        default: return "error enum PixelFormat";
    }
}
const char* VideoFileType_to_s(int n)
{
    switch(n) {
        case VIDEO_UNKNOWN: return "VIDEO_UNKNOWN";
        case VIDEO_YUV: return "VIDEO_YUV";
        case VIDEO_RGB: return "VIDEO_RGB";
        case VIDEO_XYZ: return "VIDEO_XYZ";
        case VIDEO_TIFF: return "VIDEO_TIFF";
        case VIDEO_AVI: return "VIDEO_AVI";
        default: return "error enum VideoFileType";
    }
}
const char* NaluType_to_s(int n)
{
    switch(n) {
        case NALU_TYPE_SLICE: return "NALU_TYPE_SLICE";
        case NALU_TYPE_DPA: return "NALU_TYPE_DPA";
        case NALU_TYPE_DPB: return "NALU_TYPE_DPB";
        case NALU_TYPE_DPC: return "NALU_TYPE_DPC";
        case NALU_TYPE_IDR: return "NALU_TYPE_IDR";
        case NALU_TYPE_SEI: return "NALU_TYPE_SEI";
        case NALU_TYPE_SPS: return "NALU_TYPE_SPS";
        case NALU_TYPE_PPS: return "NALU_TYPE_PPS";
        case NALU_TYPE_AUD: return "NALU_TYPE_AUD";
        case NALU_TYPE_EOSEQ: return "NALU_TYPE_EOSEQ";
        case NALU_TYPE_EOSTREAM: return "NALU_TYPE_EOSTREAM";
        case NALU_TYPE_FILL: return "NALU_TYPE_FILL";
#if (MVC_EXTENSION_ENABLE)
        case NALU_TYPE_PREFIX: return "NALU_TYPE_PREFIX";
        case NALU_TYPE_SUB_SPS: return "NALU_TYPE_SUB_SPS";
        case NALU_TYPE_SLC_EXT: return "NALU_TYPE_SLC_EXT";
        case NALU_TYPE_VDRD: return "NALU_TYPE_VDRD";
#endif
        default: return "error enum NaluType";
    }
}
const char* NalRefIdc_to_s(int n)
{
    switch(n) {
        case NALU_PRIORITY_HIGHEST: return "NALU_PRIORITY_HIGHEST";
        case NALU_PRIORITY_HIGH: return "NALU_PRIORITY_HIGH";
        case NALU_PRIORITY_LOW: return "NALU_PRIORITY_LOW";
        case NALU_PRIORITY_DISPOSABLE: return "NALU_PRIORITY_DISPOSABLE";
        default: return "error enum NalRefIdc";
    }
}
const char* Boolean_to_s(int n)
{
    switch(n) {
        case FALSE: return "FALSE";
        case TRUE: return "TRUE";
        default: return "error enum Boolean";
    }
}
const char* ColorPlane_to_s(int n)
{
    switch(n) {
        case PLANE_Y: return "PLANE_Y/G";
        case PLANE_U: return "PLANE_U/B";
        case PLANE_V: return "PLANE_V/R";
        default: return "error enum ColorPlane";
    }
}
const char* List_to_s(int n)
{
    switch(n) {
        case LIST_0: return "LIST_0";
        case LIST_1: return "LIST_1";
        case BI_PRED: return "BI_PRED";
        case BI_PRED_L0: return "BI_PRED_L0";
        case BI_PRED_L1: return "BI_PRED_L1";
        default: return "error enum List";
    }
}
const char* PIC_ERROR_to_s(int n)
{
    switch(n) {
        case ERROR_SAD: return "ERROR_SAD";
        case ERROR_SSE: return "ERROR_SSE";
        case ERROR_SATD: return "ERROR_SATD";
        case ERROR_PSATD: return "ERROR_PSATD";
        default: return "error enum PIC_ERROR";
    }
}
const char* ME_YUV_to_s(int n)
{
    switch(n) {
        case ME_Y_ONLY: return "ME_Y_ONLY";
        case ME_YUV_FP: return "ME_YUV_FP";
        case ME_YUV_FP_SP: return "ME_YUV_FP_SP";
        default: return "error enum ME_YUV";
    }
}
const char* MSE_to_s(int n)
{
    switch(n) {
        case DISTORTION_MSE: return "DISTORTION_MSE";
        default: return "error enum MSE";
    }
}
const char* PAR_DP_TYPE_to_s(int n)
{
    switch(n) {
        case PAR_DP_1: return "PAR_DP_1";
        case PAR_DP_3: return "PAR_DP_3";
        default: return "error enum PAR_DP_TYPE";
    }
}
const char* PAR_OF_TYPE_to_s(int n)
{
    switch(n) {
        case PAR_OF_ANNEXB: return "PAR_OF_ANNEXB";
        case PAR_OF_RTP: return "PAR_OF_RTP";
        default: return "error enum PAR_OF_TYPE";
    }
}
const char* CodingType_to_s(int n)
{
    switch(n) {
        case FRAME_CODING: return "FRAME_CODING";
        case FIELD_CODING: return "FIELD_CODING";
        case ADAPTIVE_CODING: return "ADAPTIVE_CODING";
        case FRAME_MB_PAIR_CODING: return "FRAME_MB_PAIR_CODING";
        default: return "error enum CodingType";
    }
}
const char* SE_type_to_s(int n)
{
    switch(n) {
        case SE_HEADER: return "SE_HEADER";
        case SE_PTYPE: return "SE_PTYPE";
        case SE_MBTYPE: return "SE_MBTYPE";
        case SE_REFFRAME: return "SE_REFFRAME";
        case SE_INTRAPREDMODE: return "SE_INTRAPREDMODE";
        case SE_MVD: return "SE_MVD";
        case SE_CBP: return "SE_CBP";
        case SE_LUM_DC_INTRA: return "SE_LUM_DC_INTRA";
        case SE_CHR_DC_INTRA: return "SE_CHR_DC_INTRA";
        case SE_LUM_AC_INTRA: return "SE_LUM_AC_INTRA";
        case SE_CHR_AC_INTRA: return "SE_CHR_AC_INTRA";
        case SE_LUM_DC_INTER: return "SE_LUM_DC_INTER";
        case SE_CHR_DC_INTER: return "SE_CHR_DC_INTER";
        case SE_LUM_AC_INTER: return "SE_LUM_AC_INTER";
        case SE_CHR_AC_INTER: return "SE_CHR_AC_INTER";
        case SE_DELTA_QUANT: return "SE_DELTA_QUANT";
        case SE_BFRAME: return "SE_BFRAME";
        case SE_EOS: return "SE_EOS";
        case SE_MAX_ELEMENTS: return "SE_MAX_ELEMENTS";
        default: return "error enum SE_type";
    }
}
const char* SliceMode_to_s(int n)
{
    switch(n) {
        case NO_SLICES: return "NO_SLICES";
        case FIXED_MB: return "FIXED_MB";
        case FIXED_RATE: return "FIXED_RATE";
        case CALL_BACK: return "CALL_BACK";
        default: return "error enum SliceMode";
    }
}
const char* SymbolMode_to_s(int n)
{
    switch(n) {
        case CAVLC: return "CAVLC";
        case CABAC: return "CABAC";
        default: return "error enum SymbolMode";
    }
}
const char* SearchType_to_s(int n)
{
    switch(n) {
        case FULL_SEARCH: return "FULL_SEARCH";
        case FAST_FULL_SEARCH: return "FAST_FULL_SEARCH";
        case UM_HEX: return "UM_HEX";
        case UM_HEX_SIMPLE: return "UM_HEX_SIMPLE";
        case EPZS: return "EPZS";
        default: return "error enum SearchType";
    }
}
const char* PictureStructure_to_s(int n)
{
    switch(n) {
        case FRAME: return "FRAME";
        case TOP_FIELD: return "TOP_FIELD";
        case BOTTOM_FIELD: return "BOTTOM_FIELD";
        default: return "error enum PictureStructure";
    }
}
const char* SliceType_to_s(int n)
{
    switch(n) {
        case P_SLICE: return "P_SLICE";
        case B_SLICE: return "B_SLICE";
        case I_SLICE: return "I_SLICE";
        case SP_SLICE: return "SP_SLICE";
        case SI_SLICE: return "SI_SLICE";
        case NUM_SLICE_TYPES: return "NUM_SLICE_TYPES";
        default: return "error enum SliceType";
    }
}
const char* MELevel_to_s(int n)
{
    switch(n) {
        case F_PEL: return "F_PEL";
        case H_PEL: return "H_PEL";
        case Q_PEL: return "Q_PEL";
        default: return "error enum MELevel";
    }
}
const char* REF_ACCESS_TYPE_to_s(int n)
{
    switch(n) {
        case FAST_ACCESS: return "FAST_ACCESS";
        case UMV_ACCESS: return "UMV_ACCESS";
        default: return "error enum REF_ACCESS_TYPE";
    }
}
const char* Component_Type_to_s(int n)
{
    switch(n) {
        case IS_LUMA: return "IS_LUMA";
        case IS_CHROMA: return "IS_CHROMA";
        default: return "error enum Component_Type";
    }
}
const char* RCModeType_to_s(int n)
{
    switch(n) {
        case RC_MODE_0: return "RC_MODE_0";
        case RC_MODE_1: return "RC_MODE_1";
        case RC_MODE_2: return "RC_MODE_2";
        case RC_MODE_3: return "RC_MODE_3";
        default: return "error enum RCModeType";
    }
}
const char* distortion_types_to_s(int n)
{
    switch(n) {
        case SSE: return "SSE";
        case SSE_RGB: return "SSE_RGB";
        case PSNR: return "PSNR";
        case PSNR_RGB: return "PSNR_RGB";
        case SSIM: return "SSIM";
        case SSIM_RGB: return "SSIM_RGB";
        case MS_SSIM: return "MS_SSIM";
        case MS_SSIM_RGB: return "MS_SSIM_RGB";
        case TOTAL_DIST_TYPES: return "TOTAL_DIST_TYPES";
        default: return "error enum distortion_types";
    }
}
const char* weighted_prediction_types_to_s(int n)
{
    switch(n) {
        case WP_MCPREC_PLUS0: return "WP_MCPREC_PLUS0";
        case WP_MCPREC_PLUS1: return "WP_MCPREC_PLUS1";
        case WP_MCPREC_MINUS0: return "WP_MCPREC_MINUS0";
        case WP_MCPREC_MINUS1: return "WP_MCPREC_MINUS1";
        case WP_MCPREC_MINUS_PLUS0: return "WP_MCPREC_MINUS_PLUS0";
        case WP_REGULAR: return "WP_REGULAR";
        default: return "error enum weighted_prediction_types";
    }
}

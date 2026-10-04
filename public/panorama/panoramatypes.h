#ifndef PANORAMATYPES_H
#define PANORAMATYPES_H

#ifdef _WIN32
#pragma once
#endif

#include <tier0/platform.h>

namespace panorama
{

enum EPanelFlag : uint8
{
	k_EPanelFlag_IsVisible = 0x01,
	k_EPanelFlag_HasOwnLayoutFile = 0x40,
};

enum EHorizontalAlignment : uint8
{
	k_EHorizontalAlignmentUnset,
	k_EHorizontalAlignmentLeft,
	k_EHorizontalAlignmentCenter,
	k_EHorizontalAlignmentRight,
};

enum EVerticalAlignment : uint8
{
	k_EVerticalAlignmentUnset,
	k_EVerticalAlignmentTop,
	k_EVerticalAlignmentCenter,
	k_EVerticalAlignmentBottom,
};

enum EFlowDirection : uint8
{
	k_EFlowUnset,
	k_EFlowNone,
	k_EFlowDown,
	k_EFlowRight,
};

enum EFontStyle : int8
{
	k_EFontStyleUnset = -1,
	k_EFontStyleNormal = 0,
	k_EFontStyleItalic = 2,
};

enum EFontWeight : int8
{
	k_EFontWeightUnset = -1,
	k_EFontWeightNormal = 0,
	k_EFontWeightMedium = 1,
	k_EFontWeightBold = 2,
	k_EFontWeightBlack = 3,
	k_EFontWeightThin = 4,
	k_EFontWeightLight = 5,
	k_EFontWeightSemiBold = 6,
};

enum EFontStretch : int8
{
	k_EFontStretchUnset = -1,
	k_EFontStretchNormal = 0,
	k_EFontStretchCondensed = 1,
	k_EFontStretchExpanded = 2,
};

enum EMixBlendMode : uint8
{
	k_EMixBlendModeNormal,
	k_EMixBlendModeMultiply,
	k_EMixBlendModeScreen,
	k_EMixBlendModeAdditive,
	k_EMixBlendModeOpaque,
};

enum ETextAlign : int8
{
	k_ETextAlignUnset = -1,
	k_ETextAlignLeft = 0,
	k_ETextAlignCenter = 1,
	k_ETextAlignRight = 2,
	k_ETextAlignJustify = 3,
	k_ETextAlignJustifyLetterSpacing = 4,
};

enum EBorderStyle : int8
{
	k_EBorderStyleUnset = -1,
	k_EBorderStyleNone = 0,
	k_EBorderStyleSolid = 1,
};

enum BlurType_t
{
	BT_NORMAL = 0,
	BT_FAST = 1,
	BT_FASTANIM = 2,
};

enum ETextDecoration : int8
{
	k_ETextDecorationUnset = -1,
	k_ETextDecorationNone = 0,
	k_ETextDecorationUnderline = 1,
	k_ETextDecorationLineThrough = 2,
};

enum ETextTransform : int8
{
	k_ETextTransformUnset = -1,
	k_ETextTransformNone = 0,
	k_ETextTransformUppercase = 1,
	k_ETextTransformLowercase = 2,
};

enum ETextOverflow : int8
{
	k_ETextOverflowUnset = -1,
	k_ETextOverflowClip = 0,
	k_ETextOverflowEllipsis = 1,
	k_ETextOverflowShrink = 2,
	k_ETextOverflowNoClip = 3,
};

enum EAnimationTimingFunction : uint8
{
	k_EAnimationNone = 0,
	k_EAnimationEase,
	k_EAnimationEaseIn,
	k_EAnimationEaseOut,
	k_EAnimationEaseInOut,
	k_EAnimationLinear,
	k_EAnimationCustomBezier,
	k_EAnimationUnset,
};

enum EContextUIPosition : uint8
{
	k_EContextUIPositionUnset,
	k_EContextUIPositionLeft,
	k_EContextUIPositionTop,
	k_EContextUIPositionRight,
	k_EContextUIPositionBottom,
};

enum EOverflowValue : uint8
{
	k_EOverflowSquish,
	k_EOverflowClip,
	k_EOverflowScroll,
	k_EOverflowNoClip,
};

enum EMouseCanActivate : uint8
{
	k_EMouseCanActivateUnfocused = 0,
	k_EMouseCanActivateIfFocused,
	k_EMouseCanActivateIfParentFocused,
	k_EMouseCanActivateIfAnyParentFocused,
};

enum EFocusMoveDirection : uint8
{
	k_ENextInTabOrder = 1 << 0,
	k_EPrevInTabOrder = 1 << 1,
	k_ENextByXPosition = 1 << 2,
	k_EPrevByXPosition = 1 << 3,
	k_ENextByYPosition = 1 << 4,
	k_EPrevByYPosition = 1 << 5,
};

enum ETextureSampleMode : uint8
{
	k_ETextureSampleModeNormal,
	k_ETextureSampleModeAlphaOnly,
};

enum EPanelEventSource_t : uint8
{
	k_ePanelEventSourceProgram,
	k_ePanelEventSourceGamepad,
	k_ePanelEventSourceKeyboard,
	k_ePanelEventSourceMouse,
	k_ePanelEventSourceInvalid,
};

} // namespace panorama

#endif

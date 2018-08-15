// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/enums.h"

#include "yasl/binding/enum.h"
#include "yasl/binding/namespace.h"
#include "yasl/core/flags.h"

#include "yasl/core/enums.h"

#include <script/enumbuilder.h>

static void register_qt_global_color_enum(script::Namespace qt)
{
  using namespace script;

  Enum global_color = qt.Enum("GlobalColor").setId(script::Type::QtGlobalColor)
    .setEnumClass().get();

  global_color.addValue("color0", Qt::color0);
  global_color.addValue("color1", Qt::color1);
  global_color.addValue("black", Qt::black);
  global_color.addValue("white", Qt::white);
  global_color.addValue("darkGray", Qt::darkGray);
  global_color.addValue("gray", Qt::gray);
  global_color.addValue("lightGray", Qt::lightGray);
  global_color.addValue("red", Qt::red);
  global_color.addValue("green", Qt::green);
  global_color.addValue("blue", Qt::blue);
  global_color.addValue("cyan", Qt::cyan);
  global_color.addValue("magenta", Qt::magenta);
  global_color.addValue("yellow", Qt::yellow);
  global_color.addValue("darkRed", Qt::darkRed);
  global_color.addValue("darkGreen", Qt::darkGreen);
  global_color.addValue("darkBlue", Qt::darkBlue);
  global_color.addValue("darkCyan", Qt::darkCyan);
  global_color.addValue("darkMagenta", Qt::darkMagenta);
  global_color.addValue("darkYellow", Qt::darkYellow);
  global_color.addValue("transparent", Qt::transparent);
}


static void register_qt_keyboard_modifier_enum(script::Namespace qt)
{
  using namespace script;

  Enum keyboard_modifier = qt.Enum("KeyboardModifier").setId(script::Type::QtKeyboardModifier)
    .setEnumClass().get();

  register_qflags_type<Qt::KeyboardModifier>(qt, "KeyboardModifiers", script::Type::QtKeyboardModifiers);
  keyboard_modifier.addValue("NoModifier", Qt::NoModifier);
  keyboard_modifier.addValue("ShiftModifier", Qt::ShiftModifier);
  keyboard_modifier.addValue("ControlModifier", Qt::ControlModifier);
  keyboard_modifier.addValue("AltModifier", Qt::AltModifier);
  keyboard_modifier.addValue("MetaModifier", Qt::MetaModifier);
  keyboard_modifier.addValue("KeypadModifier", Qt::KeypadModifier);
  keyboard_modifier.addValue("GroupSwitchModifier", Qt::GroupSwitchModifier);
  keyboard_modifier.addValue("KeyboardModifierMask", Qt::KeyboardModifierMask);
}


static void register_qt_modifier_enum(script::Namespace qt)
{
  using namespace script;

  Enum modifier = qt.Enum("Modifier").setId(script::Type::QtModifier)
    .setEnumClass().get();

  modifier.addValue("META", Qt::META);
  modifier.addValue("SHIFT", Qt::SHIFT);
  modifier.addValue("CTRL", Qt::CTRL);
  modifier.addValue("ALT", Qt::ALT);
  modifier.addValue("MODIFIER_MASK", Qt::MODIFIER_MASK);
  modifier.addValue("UNICODE_ACCEL", Qt::UNICODE_ACCEL);
}


static void register_qt_mouse_button_enum(script::Namespace qt)
{
  using namespace script;

  Enum mouse_button = qt.Enum("MouseButton").setId(script::Type::QtMouseButton)
    .setEnumClass().get();

  mouse_button.addValue("NoButton", Qt::NoButton);
  mouse_button.addValue("LeftButton", Qt::LeftButton);
  mouse_button.addValue("RightButton", Qt::RightButton);
  mouse_button.addValue("MidButton", Qt::MidButton);
  mouse_button.addValue("MiddleButton", Qt::MiddleButton);
  mouse_button.addValue("BackButton", Qt::BackButton);
  mouse_button.addValue("XButton1", Qt::XButton1);
  mouse_button.addValue("ExtraButton1", Qt::ExtraButton1);
  mouse_button.addValue("ForwardButton", Qt::ForwardButton);
  mouse_button.addValue("XButton2", Qt::XButton2);
  mouse_button.addValue("ExtraButton2", Qt::ExtraButton2);
  mouse_button.addValue("TaskButton", Qt::TaskButton);
  mouse_button.addValue("ExtraButton3", Qt::ExtraButton3);
  mouse_button.addValue("ExtraButton4", Qt::ExtraButton4);
  mouse_button.addValue("ExtraButton5", Qt::ExtraButton5);
  mouse_button.addValue("ExtraButton6", Qt::ExtraButton6);
  mouse_button.addValue("ExtraButton7", Qt::ExtraButton7);
  mouse_button.addValue("ExtraButton8", Qt::ExtraButton8);
  mouse_button.addValue("ExtraButton9", Qt::ExtraButton9);
  mouse_button.addValue("ExtraButton10", Qt::ExtraButton10);
  mouse_button.addValue("ExtraButton11", Qt::ExtraButton11);
  mouse_button.addValue("ExtraButton12", Qt::ExtraButton12);
  mouse_button.addValue("ExtraButton13", Qt::ExtraButton13);
  mouse_button.addValue("ExtraButton14", Qt::ExtraButton14);
  mouse_button.addValue("ExtraButton15", Qt::ExtraButton15);
  mouse_button.addValue("ExtraButton16", Qt::ExtraButton16);
  mouse_button.addValue("ExtraButton17", Qt::ExtraButton17);
  mouse_button.addValue("ExtraButton18", Qt::ExtraButton18);
  mouse_button.addValue("ExtraButton19", Qt::ExtraButton19);
  mouse_button.addValue("ExtraButton20", Qt::ExtraButton20);
  mouse_button.addValue("ExtraButton21", Qt::ExtraButton21);
  mouse_button.addValue("ExtraButton22", Qt::ExtraButton22);
  mouse_button.addValue("ExtraButton23", Qt::ExtraButton23);
  mouse_button.addValue("ExtraButton24", Qt::ExtraButton24);
  mouse_button.addValue("AllButtons", Qt::AllButtons);
  mouse_button.addValue("MaxMouseButton", Qt::MaxMouseButton);
  mouse_button.addValue("MouseButtonMask", Qt::MouseButtonMask);
}


static void register_qt_orientation_enum(script::Namespace qt)
{
  using namespace script;

  Enum orientation = qt.Enum("Orientation").setId(script::Type::QtOrientation)
    .setEnumClass().get();

  orientation.addValue("Horizontal", Qt::Horizontal);
  orientation.addValue("Vertical", Qt::Vertical);
}


static void register_qt_focus_policy_enum(script::Namespace qt)
{
  using namespace script;

  Enum focus_policy = qt.Enum("FocusPolicy").setId(script::Type::QtFocusPolicy)
    .setEnumClass().get();

  focus_policy.addValue("NoFocus", Qt::NoFocus);
  focus_policy.addValue("TabFocus", Qt::TabFocus);
  focus_policy.addValue("ClickFocus", Qt::ClickFocus);
  focus_policy.addValue("StrongFocus", Qt::StrongFocus);
  focus_policy.addValue("WheelFocus", Qt::WheelFocus);
}


static void register_qt_tab_focus_behavior_enum(script::Namespace qt)
{
  using namespace script;

  Enum tab_focus_behavior = qt.Enum("TabFocusBehavior").setId(script::Type::QtTabFocusBehavior)
    .setEnumClass().get();

  tab_focus_behavior.addValue("NoTabFocus", Qt::NoTabFocus);
  tab_focus_behavior.addValue("TabFocusTextControls", Qt::TabFocusTextControls);
  tab_focus_behavior.addValue("TabFocusListControls", Qt::TabFocusListControls);
  tab_focus_behavior.addValue("TabFocusAllControls", Qt::TabFocusAllControls);
}


static void register_qt_sort_order_enum(script::Namespace qt)
{
  using namespace script;

  Enum sort_order = qt.Enum("SortOrder").setId(script::Type::QtSortOrder)
    .setEnumClass().get();

  sort_order.addValue("AscendingOrder", Qt::AscendingOrder);
  sort_order.addValue("DescendingOrder", Qt::DescendingOrder);
}


static void register_qt_tile_rule_enum(script::Namespace qt)
{
  using namespace script;

  Enum tile_rule = qt.Enum("TileRule").setId(script::Type::QtTileRule)
    .setEnumClass().get();

  tile_rule.addValue("StretchTile", Qt::StretchTile);
  tile_rule.addValue("RepeatTile", Qt::RepeatTile);
  tile_rule.addValue("RoundTile", Qt::RoundTile);
}


static void register_qt_alignment_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum alignment_flag = qt.Enum("AlignmentFlag").setId(script::Type::QtAlignmentFlag)
    .setEnumClass().get();

  alignment_flag.addValue("AlignLeft", Qt::AlignLeft);
  alignment_flag.addValue("AlignLeading", Qt::AlignLeading);
  alignment_flag.addValue("AlignRight", Qt::AlignRight);
  alignment_flag.addValue("AlignTrailing", Qt::AlignTrailing);
  alignment_flag.addValue("AlignHCenter", Qt::AlignHCenter);
  alignment_flag.addValue("AlignJustify", Qt::AlignJustify);
  alignment_flag.addValue("AlignAbsolute", Qt::AlignAbsolute);
  alignment_flag.addValue("AlignHorizontal_Mask", Qt::AlignHorizontal_Mask);
  alignment_flag.addValue("AlignTop", Qt::AlignTop);
  alignment_flag.addValue("AlignBottom", Qt::AlignBottom);
  alignment_flag.addValue("AlignVCenter", Qt::AlignVCenter);
  alignment_flag.addValue("AlignBaseline", Qt::AlignBaseline);
  alignment_flag.addValue("AlignVertical_Mask", Qt::AlignVertical_Mask);
  alignment_flag.addValue("AlignCenter", Qt::AlignCenter);
}


static void register_qt_text_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum text_flag = qt.Enum("TextFlag").setId(script::Type::QtTextFlag)
    .setEnumClass().get();

  text_flag.addValue("TextSingleLine", Qt::TextSingleLine);
  text_flag.addValue("TextDontClip", Qt::TextDontClip);
  text_flag.addValue("TextExpandTabs", Qt::TextExpandTabs);
  text_flag.addValue("TextShowMnemonic", Qt::TextShowMnemonic);
  text_flag.addValue("TextWordWrap", Qt::TextWordWrap);
  text_flag.addValue("TextWrapAnywhere", Qt::TextWrapAnywhere);
  text_flag.addValue("TextDontPrint", Qt::TextDontPrint);
  text_flag.addValue("TextIncludeTrailingSpaces", Qt::TextIncludeTrailingSpaces);
  text_flag.addValue("TextHideMnemonic", Qt::TextHideMnemonic);
  text_flag.addValue("TextJustificationForced", Qt::TextJustificationForced);
  text_flag.addValue("TextForceLeftToRight", Qt::TextForceLeftToRight);
  text_flag.addValue("TextForceRightToLeft", Qt::TextForceRightToLeft);
  text_flag.addValue("TextLongestVariant", Qt::TextLongestVariant);
  text_flag.addValue("TextBypassShaping", Qt::TextBypassShaping);
}


static void register_qt_text_elide_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum text_elide_mode = qt.Enum("TextElideMode").setId(script::Type::QtTextElideMode)
    .setEnumClass().get();

  text_elide_mode.addValue("ElideLeft", Qt::ElideLeft);
  text_elide_mode.addValue("ElideRight", Qt::ElideRight);
  text_elide_mode.addValue("ElideMiddle", Qt::ElideMiddle);
  text_elide_mode.addValue("ElideNone", Qt::ElideNone);
}


static void register_qt_white_space_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum white_space_mode = qt.Enum("WhiteSpaceMode").setId(script::Type::QtWhiteSpaceMode)
    .setEnumClass().get();

  white_space_mode.addValue("WhiteSpaceNormal", Qt::WhiteSpaceNormal);
  white_space_mode.addValue("WhiteSpacePre", Qt::WhiteSpacePre);
  white_space_mode.addValue("WhiteSpaceNoWrap", Qt::WhiteSpaceNoWrap);
  white_space_mode.addValue("WhiteSpaceModeUndefined", Qt::WhiteSpaceModeUndefined);
}


static void register_qt_hit_test_accuracy_enum(script::Namespace qt)
{
  using namespace script;

  Enum hit_test_accuracy = qt.Enum("HitTestAccuracy").setId(script::Type::QtHitTestAccuracy)
    .setEnumClass().get();

  hit_test_accuracy.addValue("ExactHit", Qt::ExactHit);
  hit_test_accuracy.addValue("FuzzyHit", Qt::FuzzyHit);
}


static void register_qt_window_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum window_type = qt.Enum("WindowType").setId(script::Type::QtWindowType)
    .setEnumClass().get();

  window_type.addValue("Widget", Qt::Widget);
  window_type.addValue("Window", Qt::Window);
  window_type.addValue("Dialog", Qt::Dialog);
  window_type.addValue("Sheet", Qt::Sheet);
  window_type.addValue("Drawer", Qt::Drawer);
  window_type.addValue("Popup", Qt::Popup);
  window_type.addValue("Tool", Qt::Tool);
  window_type.addValue("ToolTip", Qt::ToolTip);
  window_type.addValue("SplashScreen", Qt::SplashScreen);
  window_type.addValue("Desktop", Qt::Desktop);
  window_type.addValue("SubWindow", Qt::SubWindow);
  window_type.addValue("ForeignWindow", Qt::ForeignWindow);
  window_type.addValue("CoverWindow", Qt::CoverWindow);
  window_type.addValue("WindowType_Mask", Qt::WindowType_Mask);
  window_type.addValue("MSWindowsFixedSizeDialogHint", Qt::MSWindowsFixedSizeDialogHint);
  window_type.addValue("MSWindowsOwnDC", Qt::MSWindowsOwnDC);
  window_type.addValue("BypassWindowManagerHint", Qt::BypassWindowManagerHint);
  window_type.addValue("X11BypassWindowManagerHint", Qt::X11BypassWindowManagerHint);
  window_type.addValue("FramelessWindowHint", Qt::FramelessWindowHint);
  window_type.addValue("WindowTitleHint", Qt::WindowTitleHint);
  window_type.addValue("WindowSystemMenuHint", Qt::WindowSystemMenuHint);
  window_type.addValue("WindowMinimizeButtonHint", Qt::WindowMinimizeButtonHint);
  window_type.addValue("WindowMaximizeButtonHint", Qt::WindowMaximizeButtonHint);
  window_type.addValue("WindowMinMaxButtonsHint", Qt::WindowMinMaxButtonsHint);
  window_type.addValue("WindowContextHelpButtonHint", Qt::WindowContextHelpButtonHint);
  window_type.addValue("WindowShadeButtonHint", Qt::WindowShadeButtonHint);
  window_type.addValue("WindowStaysOnTopHint", Qt::WindowStaysOnTopHint);
  window_type.addValue("WindowTransparentForInput", Qt::WindowTransparentForInput);
  window_type.addValue("WindowOverridesSystemGestures", Qt::WindowOverridesSystemGestures);
  window_type.addValue("WindowDoesNotAcceptFocus", Qt::WindowDoesNotAcceptFocus);
  window_type.addValue("MaximizeUsingFullscreenGeometryHint", Qt::MaximizeUsingFullscreenGeometryHint);
  window_type.addValue("CustomizeWindowHint", Qt::CustomizeWindowHint);
  window_type.addValue("WindowStaysOnBottomHint", Qt::WindowStaysOnBottomHint);
  window_type.addValue("WindowCloseButtonHint", Qt::WindowCloseButtonHint);
  window_type.addValue("MacWindowToolBarButtonHint", Qt::MacWindowToolBarButtonHint);
  window_type.addValue("BypassGraphicsProxyWidget", Qt::BypassGraphicsProxyWidget);
  window_type.addValue("NoDropShadowWindowHint", Qt::NoDropShadowWindowHint);
  window_type.addValue("WindowFullscreenButtonHint", Qt::WindowFullscreenButtonHint);
}


static void register_qt_window_state_enum(script::Namespace qt)
{
  using namespace script;

  Enum window_state = qt.Enum("WindowState").setId(script::Type::QtWindowState)
    .setEnumClass().get();

  window_state.addValue("WindowNoState", Qt::WindowNoState);
  window_state.addValue("WindowMinimized", Qt::WindowMinimized);
  window_state.addValue("WindowMaximized", Qt::WindowMaximized);
  window_state.addValue("WindowFullScreen", Qt::WindowFullScreen);
  window_state.addValue("WindowActive", Qt::WindowActive);
}


static void register_qt_application_state_enum(script::Namespace qt)
{
  using namespace script;

  Enum application_state = qt.Enum("ApplicationState").setId(script::Type::QtApplicationState)
    .setEnumClass().get();

  application_state.addValue("ApplicationSuspended", Qt::ApplicationSuspended);
  application_state.addValue("ApplicationHidden", Qt::ApplicationHidden);
  application_state.addValue("ApplicationInactive", Qt::ApplicationInactive);
  application_state.addValue("ApplicationActive", Qt::ApplicationActive);
}


static void register_qt_screen_orientation_enum(script::Namespace qt)
{
  using namespace script;

  Enum screen_orientation = qt.Enum("ScreenOrientation").setId(script::Type::QtScreenOrientation)
    .setEnumClass().get();

  screen_orientation.addValue("PrimaryOrientation", Qt::PrimaryOrientation);
  screen_orientation.addValue("PortraitOrientation", Qt::PortraitOrientation);
  screen_orientation.addValue("LandscapeOrientation", Qt::LandscapeOrientation);
  screen_orientation.addValue("InvertedPortraitOrientation", Qt::InvertedPortraitOrientation);
  screen_orientation.addValue("InvertedLandscapeOrientation", Qt::InvertedLandscapeOrientation);
}


static void register_qt_widget_attribute_enum(script::Namespace qt)
{
  using namespace script;

  Enum widget_attribute = qt.Enum("WidgetAttribute").setId(script::Type::QtWidgetAttribute)
    .setEnumClass().get();

  widget_attribute.addValue("WA_Disabled", Qt::WA_Disabled);
  widget_attribute.addValue("WA_UnderMouse", Qt::WA_UnderMouse);
  widget_attribute.addValue("WA_MouseTracking", Qt::WA_MouseTracking);
  widget_attribute.addValue("WA_ContentsPropagated", Qt::WA_ContentsPropagated);
  widget_attribute.addValue("WA_OpaquePaintEvent", Qt::WA_OpaquePaintEvent);
  widget_attribute.addValue("WA_NoBackground", Qt::WA_NoBackground);
  widget_attribute.addValue("WA_StaticContents", Qt::WA_StaticContents);
  widget_attribute.addValue("WA_LaidOut", Qt::WA_LaidOut);
  widget_attribute.addValue("WA_PaintOnScreen", Qt::WA_PaintOnScreen);
  widget_attribute.addValue("WA_NoSystemBackground", Qt::WA_NoSystemBackground);
  widget_attribute.addValue("WA_UpdatesDisabled", Qt::WA_UpdatesDisabled);
  widget_attribute.addValue("WA_Mapped", Qt::WA_Mapped);
  widget_attribute.addValue("WA_MacNoClickThrough", Qt::WA_MacNoClickThrough);
  widget_attribute.addValue("WA_InputMethodEnabled", Qt::WA_InputMethodEnabled);
  widget_attribute.addValue("WA_WState_Visible", Qt::WA_WState_Visible);
  widget_attribute.addValue("WA_WState_Hidden", Qt::WA_WState_Hidden);
  widget_attribute.addValue("WA_ForceDisabled", Qt::WA_ForceDisabled);
  widget_attribute.addValue("WA_KeyCompression", Qt::WA_KeyCompression);
  widget_attribute.addValue("WA_PendingMoveEvent", Qt::WA_PendingMoveEvent);
  widget_attribute.addValue("WA_PendingResizeEvent", Qt::WA_PendingResizeEvent);
  widget_attribute.addValue("WA_SetPalette", Qt::WA_SetPalette);
  widget_attribute.addValue("WA_SetFont", Qt::WA_SetFont);
  widget_attribute.addValue("WA_SetCursor", Qt::WA_SetCursor);
  widget_attribute.addValue("WA_NoChildEventsFromChildren", Qt::WA_NoChildEventsFromChildren);
  widget_attribute.addValue("WA_WindowModified", Qt::WA_WindowModified);
  widget_attribute.addValue("WA_Resized", Qt::WA_Resized);
  widget_attribute.addValue("WA_Moved", Qt::WA_Moved);
  widget_attribute.addValue("WA_PendingUpdate", Qt::WA_PendingUpdate);
  widget_attribute.addValue("WA_InvalidSize", Qt::WA_InvalidSize);
  widget_attribute.addValue("WA_MacBrushedMetal", Qt::WA_MacBrushedMetal);
  widget_attribute.addValue("WA_MacMetalStyle", Qt::WA_MacMetalStyle);
  widget_attribute.addValue("WA_CustomWhatsThis", Qt::WA_CustomWhatsThis);
  widget_attribute.addValue("WA_LayoutOnEntireRect", Qt::WA_LayoutOnEntireRect);
  widget_attribute.addValue("WA_OutsideWSRange", Qt::WA_OutsideWSRange);
  widget_attribute.addValue("WA_GrabbedShortcut", Qt::WA_GrabbedShortcut);
  widget_attribute.addValue("WA_TransparentForMouseEvents", Qt::WA_TransparentForMouseEvents);
  widget_attribute.addValue("WA_PaintUnclipped", Qt::WA_PaintUnclipped);
  widget_attribute.addValue("WA_SetWindowIcon", Qt::WA_SetWindowIcon);
  widget_attribute.addValue("WA_NoMouseReplay", Qt::WA_NoMouseReplay);
  widget_attribute.addValue("WA_DeleteOnClose", Qt::WA_DeleteOnClose);
  widget_attribute.addValue("WA_RightToLeft", Qt::WA_RightToLeft);
  widget_attribute.addValue("WA_SetLayoutDirection", Qt::WA_SetLayoutDirection);
  widget_attribute.addValue("WA_NoChildEventsForParent", Qt::WA_NoChildEventsForParent);
  widget_attribute.addValue("WA_ForceUpdatesDisabled", Qt::WA_ForceUpdatesDisabled);
  widget_attribute.addValue("WA_WState_Created", Qt::WA_WState_Created);
  widget_attribute.addValue("WA_WState_CompressKeys", Qt::WA_WState_CompressKeys);
  widget_attribute.addValue("WA_WState_InPaintEvent", Qt::WA_WState_InPaintEvent);
  widget_attribute.addValue("WA_WState_Reparented", Qt::WA_WState_Reparented);
  widget_attribute.addValue("WA_WState_ConfigPending", Qt::WA_WState_ConfigPending);
  widget_attribute.addValue("WA_WState_Polished", Qt::WA_WState_Polished);
  widget_attribute.addValue("WA_WState_DND", Qt::WA_WState_DND);
  widget_attribute.addValue("WA_WState_OwnSizePolicy", Qt::WA_WState_OwnSizePolicy);
  widget_attribute.addValue("WA_WState_ExplicitShowHide", Qt::WA_WState_ExplicitShowHide);
  widget_attribute.addValue("WA_ShowModal", Qt::WA_ShowModal);
  widget_attribute.addValue("WA_MouseNoMask", Qt::WA_MouseNoMask);
  widget_attribute.addValue("WA_GroupLeader", Qt::WA_GroupLeader);
  widget_attribute.addValue("WA_NoMousePropagation", Qt::WA_NoMousePropagation);
  widget_attribute.addValue("WA_Hover", Qt::WA_Hover);
  widget_attribute.addValue("WA_InputMethodTransparent", Qt::WA_InputMethodTransparent);
  widget_attribute.addValue("WA_QuitOnClose", Qt::WA_QuitOnClose);
  widget_attribute.addValue("WA_KeyboardFocusChange", Qt::WA_KeyboardFocusChange);
  widget_attribute.addValue("WA_AcceptDrops", Qt::WA_AcceptDrops);
  widget_attribute.addValue("WA_DropSiteRegistered", Qt::WA_DropSiteRegistered);
  widget_attribute.addValue("WA_ForceAcceptDrops", Qt::WA_ForceAcceptDrops);
  widget_attribute.addValue("WA_WindowPropagation", Qt::WA_WindowPropagation);
  widget_attribute.addValue("WA_NoX11EventCompression", Qt::WA_NoX11EventCompression);
  widget_attribute.addValue("WA_TintedBackground", Qt::WA_TintedBackground);
  widget_attribute.addValue("WA_X11OpenGLOverlay", Qt::WA_X11OpenGLOverlay);
  widget_attribute.addValue("WA_AlwaysShowToolTips", Qt::WA_AlwaysShowToolTips);
  widget_attribute.addValue("WA_MacOpaqueSizeGrip", Qt::WA_MacOpaqueSizeGrip);
  widget_attribute.addValue("WA_SetStyle", Qt::WA_SetStyle);
  widget_attribute.addValue("WA_SetLocale", Qt::WA_SetLocale);
  widget_attribute.addValue("WA_MacShowFocusRect", Qt::WA_MacShowFocusRect);
  widget_attribute.addValue("WA_MacNormalSize", Qt::WA_MacNormalSize);
  widget_attribute.addValue("WA_MacSmallSize", Qt::WA_MacSmallSize);
  widget_attribute.addValue("WA_MacMiniSize", Qt::WA_MacMiniSize);
  widget_attribute.addValue("WA_LayoutUsesWidgetRect", Qt::WA_LayoutUsesWidgetRect);
  widget_attribute.addValue("WA_StyledBackground", Qt::WA_StyledBackground);
  widget_attribute.addValue("WA_MSWindowsUseDirect3D", Qt::WA_MSWindowsUseDirect3D);
  widget_attribute.addValue("WA_CanHostQMdiSubWindowTitleBar", Qt::WA_CanHostQMdiSubWindowTitleBar);
  widget_attribute.addValue("WA_MacAlwaysShowToolWindow", Qt::WA_MacAlwaysShowToolWindow);
  widget_attribute.addValue("WA_StyleSheet", Qt::WA_StyleSheet);
  widget_attribute.addValue("WA_ShowWithoutActivating", Qt::WA_ShowWithoutActivating);
  widget_attribute.addValue("WA_X11BypassTransientForHint", Qt::WA_X11BypassTransientForHint);
  widget_attribute.addValue("WA_NativeWindow", Qt::WA_NativeWindow);
  widget_attribute.addValue("WA_DontCreateNativeAncestors", Qt::WA_DontCreateNativeAncestors);
  widget_attribute.addValue("WA_MacVariableSize", Qt::WA_MacVariableSize);
  widget_attribute.addValue("WA_DontShowOnScreen", Qt::WA_DontShowOnScreen);
  widget_attribute.addValue("WA_X11NetWmWindowTypeDesktop", Qt::WA_X11NetWmWindowTypeDesktop);
  widget_attribute.addValue("WA_X11NetWmWindowTypeDock", Qt::WA_X11NetWmWindowTypeDock);
  widget_attribute.addValue("WA_X11NetWmWindowTypeToolBar", Qt::WA_X11NetWmWindowTypeToolBar);
  widget_attribute.addValue("WA_X11NetWmWindowTypeMenu", Qt::WA_X11NetWmWindowTypeMenu);
  widget_attribute.addValue("WA_X11NetWmWindowTypeUtility", Qt::WA_X11NetWmWindowTypeUtility);
  widget_attribute.addValue("WA_X11NetWmWindowTypeSplash", Qt::WA_X11NetWmWindowTypeSplash);
  widget_attribute.addValue("WA_X11NetWmWindowTypeDialog", Qt::WA_X11NetWmWindowTypeDialog);
  widget_attribute.addValue("WA_X11NetWmWindowTypeDropDownMenu", Qt::WA_X11NetWmWindowTypeDropDownMenu);
  widget_attribute.addValue("WA_X11NetWmWindowTypePopupMenu", Qt::WA_X11NetWmWindowTypePopupMenu);
  widget_attribute.addValue("WA_X11NetWmWindowTypeToolTip", Qt::WA_X11NetWmWindowTypeToolTip);
  widget_attribute.addValue("WA_X11NetWmWindowTypeNotification", Qt::WA_X11NetWmWindowTypeNotification);
  widget_attribute.addValue("WA_X11NetWmWindowTypeCombo", Qt::WA_X11NetWmWindowTypeCombo);
  widget_attribute.addValue("WA_X11NetWmWindowTypeDND", Qt::WA_X11NetWmWindowTypeDND);
  widget_attribute.addValue("WA_MacFrameworkScaled", Qt::WA_MacFrameworkScaled);
  widget_attribute.addValue("WA_SetWindowModality", Qt::WA_SetWindowModality);
  widget_attribute.addValue("WA_WState_WindowOpacitySet", Qt::WA_WState_WindowOpacitySet);
  widget_attribute.addValue("WA_TranslucentBackground", Qt::WA_TranslucentBackground);
  widget_attribute.addValue("WA_AcceptTouchEvents", Qt::WA_AcceptTouchEvents);
  widget_attribute.addValue("WA_WState_AcceptedTouchBeginEvent", Qt::WA_WState_AcceptedTouchBeginEvent);
  widget_attribute.addValue("WA_TouchPadAcceptSingleTouchEvents", Qt::WA_TouchPadAcceptSingleTouchEvents);
  widget_attribute.addValue("WA_X11DoNotAcceptFocus", Qt::WA_X11DoNotAcceptFocus);
  widget_attribute.addValue("WA_MacNoShadow", Qt::WA_MacNoShadow);
  widget_attribute.addValue("WA_AlwaysStackOnTop", Qt::WA_AlwaysStackOnTop);
  widget_attribute.addValue("WA_TabletTracking", Qt::WA_TabletTracking);
  widget_attribute.addValue("WA_AttributeCount", Qt::WA_AttributeCount);
}


static void register_qt_application_attribute_enum(script::Namespace qt)
{
  using namespace script;

  Enum application_attribute = qt.Enum("ApplicationAttribute").setId(script::Type::QtApplicationAttribute)
    .setEnumClass().get();

  application_attribute.addValue("AA_ImmediateWidgetCreation", Qt::AA_ImmediateWidgetCreation);
  application_attribute.addValue("AA_MSWindowsUseDirect3DByDefault", Qt::AA_MSWindowsUseDirect3DByDefault);
  application_attribute.addValue("AA_DontShowIconsInMenus", Qt::AA_DontShowIconsInMenus);
  application_attribute.addValue("AA_NativeWindows", Qt::AA_NativeWindows);
  application_attribute.addValue("AA_DontCreateNativeWidgetSiblings", Qt::AA_DontCreateNativeWidgetSiblings);
  application_attribute.addValue("AA_PluginApplication", Qt::AA_PluginApplication);
  application_attribute.addValue("AA_MacPluginApplication", Qt::AA_MacPluginApplication);
  application_attribute.addValue("AA_DontUseNativeMenuBar", Qt::AA_DontUseNativeMenuBar);
  application_attribute.addValue("AA_MacDontSwapCtrlAndMeta", Qt::AA_MacDontSwapCtrlAndMeta);
  application_attribute.addValue("AA_Use96Dpi", Qt::AA_Use96Dpi);
  application_attribute.addValue("AA_X11InitThreads", Qt::AA_X11InitThreads);
  application_attribute.addValue("AA_SynthesizeTouchForUnhandledMouseEvents", Qt::AA_SynthesizeTouchForUnhandledMouseEvents);
  application_attribute.addValue("AA_SynthesizeMouseForUnhandledTouchEvents", Qt::AA_SynthesizeMouseForUnhandledTouchEvents);
  application_attribute.addValue("AA_UseHighDpiPixmaps", Qt::AA_UseHighDpiPixmaps);
  application_attribute.addValue("AA_ForceRasterWidgets", Qt::AA_ForceRasterWidgets);
  application_attribute.addValue("AA_UseDesktopOpenGL", Qt::AA_UseDesktopOpenGL);
  application_attribute.addValue("AA_UseOpenGLES", Qt::AA_UseOpenGLES);
  application_attribute.addValue("AA_UseSoftwareOpenGL", Qt::AA_UseSoftwareOpenGL);
  application_attribute.addValue("AA_ShareOpenGLContexts", Qt::AA_ShareOpenGLContexts);
  application_attribute.addValue("AA_SetPalette", Qt::AA_SetPalette);
  application_attribute.addValue("AA_EnableHighDpiScaling", Qt::AA_EnableHighDpiScaling);
  application_attribute.addValue("AA_DisableHighDpiScaling", Qt::AA_DisableHighDpiScaling);
  application_attribute.addValue("AA_UseStyleSheetPropagationInWidgetStyles", Qt::AA_UseStyleSheetPropagationInWidgetStyles);
  application_attribute.addValue("AA_DontUseNativeDialogs", Qt::AA_DontUseNativeDialogs);
  application_attribute.addValue("AA_SynthesizeMouseForUnhandledTabletEvents", Qt::AA_SynthesizeMouseForUnhandledTabletEvents);
  application_attribute.addValue("AA_CompressHighFrequencyEvents", Qt::AA_CompressHighFrequencyEvents);
  application_attribute.addValue("AA_DontCheckOpenGLContextThreadAffinity", Qt::AA_DontCheckOpenGLContextThreadAffinity);
  application_attribute.addValue("AA_DisableShaderDiskCache", Qt::AA_DisableShaderDiskCache);
  application_attribute.addValue("AA_DontShowShortcutsInContextMenus", Qt::AA_DontShowShortcutsInContextMenus);
  application_attribute.addValue("AA_CompressTabletEvents", Qt::AA_CompressTabletEvents);
  application_attribute.addValue("AA_DisableWindowContextHelpButton", Qt::AA_DisableWindowContextHelpButton);
  application_attribute.addValue("AA_AttributeCount", Qt::AA_AttributeCount);
}


static void register_qt_image_conversion_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum image_conversion_flag = qt.Enum("ImageConversionFlag").setId(script::Type::QtImageConversionFlag)
    .setEnumClass().get();

  register_qflags_type<Qt::ImageConversionFlag>(qt, "ImageConversionFlags", script::Type::QtImageConversionFlags);
  image_conversion_flag.addValue("ColorMode_Mask", Qt::ColorMode_Mask);
  image_conversion_flag.addValue("AutoColor", Qt::AutoColor);
  image_conversion_flag.addValue("ColorOnly", Qt::ColorOnly);
  image_conversion_flag.addValue("MonoOnly", Qt::MonoOnly);
  image_conversion_flag.addValue("AlphaDither_Mask", Qt::AlphaDither_Mask);
  image_conversion_flag.addValue("ThresholdAlphaDither", Qt::ThresholdAlphaDither);
  image_conversion_flag.addValue("OrderedAlphaDither", Qt::OrderedAlphaDither);
  image_conversion_flag.addValue("DiffuseAlphaDither", Qt::DiffuseAlphaDither);
  image_conversion_flag.addValue("NoAlpha", Qt::NoAlpha);
  image_conversion_flag.addValue("Dither_Mask", Qt::Dither_Mask);
  image_conversion_flag.addValue("DiffuseDither", Qt::DiffuseDither);
  image_conversion_flag.addValue("OrderedDither", Qt::OrderedDither);
  image_conversion_flag.addValue("ThresholdDither", Qt::ThresholdDither);
  image_conversion_flag.addValue("DitherMode_Mask", Qt::DitherMode_Mask);
  image_conversion_flag.addValue("AutoDither", Qt::AutoDither);
  image_conversion_flag.addValue("PreferDither", Qt::PreferDither);
  image_conversion_flag.addValue("AvoidDither", Qt::AvoidDither);
  image_conversion_flag.addValue("NoOpaqueDetection", Qt::NoOpaqueDetection);
  image_conversion_flag.addValue("NoFormatConversion", Qt::NoFormatConversion);
}


static void register_qt_b_g_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum b_g_mode = qt.Enum("BGMode").setId(script::Type::QtBGMode)
    .setEnumClass().get();

  b_g_mode.addValue("TransparentMode", Qt::TransparentMode);
  b_g_mode.addValue("OpaqueMode", Qt::OpaqueMode);
}


static void register_qt_key_enum(script::Namespace qt)
{
  using namespace script;

  Enum key = qt.Enum("Key").setId(script::Type::QtKey)
    .setEnumClass().get();

  key.addValue("Key_Escape", Qt::Key_Escape);
  key.addValue("Key_Tab", Qt::Key_Tab);
  key.addValue("Key_Backtab", Qt::Key_Backtab);
  key.addValue("Key_Backspace", Qt::Key_Backspace);
  key.addValue("Key_Return", Qt::Key_Return);
  key.addValue("Key_Enter", Qt::Key_Enter);
  key.addValue("Key_Insert", Qt::Key_Insert);
  key.addValue("Key_Delete", Qt::Key_Delete);
  key.addValue("Key_Pause", Qt::Key_Pause);
  key.addValue("Key_Print", Qt::Key_Print);
  key.addValue("Key_SysReq", Qt::Key_SysReq);
  key.addValue("Key_Clear", Qt::Key_Clear);
  key.addValue("Key_Home", Qt::Key_Home);
  key.addValue("Key_End", Qt::Key_End);
  key.addValue("Key_Left", Qt::Key_Left);
  key.addValue("Key_Up", Qt::Key_Up);
  key.addValue("Key_Right", Qt::Key_Right);
  key.addValue("Key_Down", Qt::Key_Down);
  key.addValue("Key_PageUp", Qt::Key_PageUp);
  key.addValue("Key_PageDown", Qt::Key_PageDown);
  key.addValue("Key_Shift", Qt::Key_Shift);
  key.addValue("Key_Control", Qt::Key_Control);
  key.addValue("Key_Meta", Qt::Key_Meta);
  key.addValue("Key_Alt", Qt::Key_Alt);
  key.addValue("Key_CapsLock", Qt::Key_CapsLock);
  key.addValue("Key_NumLock", Qt::Key_NumLock);
  key.addValue("Key_ScrollLock", Qt::Key_ScrollLock);
  key.addValue("Key_F1", Qt::Key_F1);
  key.addValue("Key_F2", Qt::Key_F2);
  key.addValue("Key_F3", Qt::Key_F3);
  key.addValue("Key_F4", Qt::Key_F4);
  key.addValue("Key_F5", Qt::Key_F5);
  key.addValue("Key_F6", Qt::Key_F6);
  key.addValue("Key_F7", Qt::Key_F7);
  key.addValue("Key_F8", Qt::Key_F8);
  key.addValue("Key_F9", Qt::Key_F9);
  key.addValue("Key_F10", Qt::Key_F10);
  key.addValue("Key_F11", Qt::Key_F11);
  key.addValue("Key_F12", Qt::Key_F12);
  key.addValue("Key_F13", Qt::Key_F13);
  key.addValue("Key_F14", Qt::Key_F14);
  key.addValue("Key_F15", Qt::Key_F15);
  key.addValue("Key_F16", Qt::Key_F16);
  key.addValue("Key_F17", Qt::Key_F17);
  key.addValue("Key_F18", Qt::Key_F18);
  key.addValue("Key_F19", Qt::Key_F19);
  key.addValue("Key_F20", Qt::Key_F20);
  key.addValue("Key_F21", Qt::Key_F21);
  key.addValue("Key_F22", Qt::Key_F22);
  key.addValue("Key_F23", Qt::Key_F23);
  key.addValue("Key_F24", Qt::Key_F24);
  key.addValue("Key_F25", Qt::Key_F25);
  key.addValue("Key_F26", Qt::Key_F26);
  key.addValue("Key_F27", Qt::Key_F27);
  key.addValue("Key_F28", Qt::Key_F28);
  key.addValue("Key_F29", Qt::Key_F29);
  key.addValue("Key_F30", Qt::Key_F30);
  key.addValue("Key_F31", Qt::Key_F31);
  key.addValue("Key_F32", Qt::Key_F32);
  key.addValue("Key_F33", Qt::Key_F33);
  key.addValue("Key_F34", Qt::Key_F34);
  key.addValue("Key_F35", Qt::Key_F35);
  key.addValue("Key_Super_L", Qt::Key_Super_L);
  key.addValue("Key_Super_R", Qt::Key_Super_R);
  key.addValue("Key_Menu", Qt::Key_Menu);
  key.addValue("Key_Hyper_L", Qt::Key_Hyper_L);
  key.addValue("Key_Hyper_R", Qt::Key_Hyper_R);
  key.addValue("Key_Help", Qt::Key_Help);
  key.addValue("Key_Direction_L", Qt::Key_Direction_L);
  key.addValue("Key_Direction_R", Qt::Key_Direction_R);
  key.addValue("Key_Space", Qt::Key_Space);
  key.addValue("Key_Any", Qt::Key_Any);
  key.addValue("Key_Exclam", Qt::Key_Exclam);
  key.addValue("Key_QuoteDbl", Qt::Key_QuoteDbl);
  key.addValue("Key_NumberSign", Qt::Key_NumberSign);
  key.addValue("Key_Dollar", Qt::Key_Dollar);
  key.addValue("Key_Percent", Qt::Key_Percent);
  key.addValue("Key_Ampersand", Qt::Key_Ampersand);
  key.addValue("Key_Apostrophe", Qt::Key_Apostrophe);
  key.addValue("Key_ParenLeft", Qt::Key_ParenLeft);
  key.addValue("Key_ParenRight", Qt::Key_ParenRight);
  key.addValue("Key_Asterisk", Qt::Key_Asterisk);
  key.addValue("Key_Plus", Qt::Key_Plus);
  key.addValue("Key_Comma", Qt::Key_Comma);
  key.addValue("Key_Minus", Qt::Key_Minus);
  key.addValue("Key_Period", Qt::Key_Period);
  key.addValue("Key_Slash", Qt::Key_Slash);
  key.addValue("Key_0", Qt::Key_0);
  key.addValue("Key_1", Qt::Key_1);
  key.addValue("Key_2", Qt::Key_2);
  key.addValue("Key_3", Qt::Key_3);
  key.addValue("Key_4", Qt::Key_4);
  key.addValue("Key_5", Qt::Key_5);
  key.addValue("Key_6", Qt::Key_6);
  key.addValue("Key_7", Qt::Key_7);
  key.addValue("Key_8", Qt::Key_8);
  key.addValue("Key_9", Qt::Key_9);
  key.addValue("Key_Colon", Qt::Key_Colon);
  key.addValue("Key_Semicolon", Qt::Key_Semicolon);
  key.addValue("Key_Less", Qt::Key_Less);
  key.addValue("Key_Equal", Qt::Key_Equal);
  key.addValue("Key_Greater", Qt::Key_Greater);
  key.addValue("Key_Question", Qt::Key_Question);
  key.addValue("Key_At", Qt::Key_At);
  key.addValue("Key_A", Qt::Key_A);
  key.addValue("Key_B", Qt::Key_B);
  key.addValue("Key_C", Qt::Key_C);
  key.addValue("Key_D", Qt::Key_D);
  key.addValue("Key_E", Qt::Key_E);
  key.addValue("Key_F", Qt::Key_F);
  key.addValue("Key_G", Qt::Key_G);
  key.addValue("Key_H", Qt::Key_H);
  key.addValue("Key_I", Qt::Key_I);
  key.addValue("Key_J", Qt::Key_J);
  key.addValue("Key_K", Qt::Key_K);
  key.addValue("Key_L", Qt::Key_L);
  key.addValue("Key_M", Qt::Key_M);
  key.addValue("Key_N", Qt::Key_N);
  key.addValue("Key_O", Qt::Key_O);
  key.addValue("Key_P", Qt::Key_P);
  key.addValue("Key_Q", Qt::Key_Q);
  key.addValue("Key_R", Qt::Key_R);
  key.addValue("Key_S", Qt::Key_S);
  key.addValue("Key_T", Qt::Key_T);
  key.addValue("Key_U", Qt::Key_U);
  key.addValue("Key_V", Qt::Key_V);
  key.addValue("Key_W", Qt::Key_W);
  key.addValue("Key_X", Qt::Key_X);
  key.addValue("Key_Y", Qt::Key_Y);
  key.addValue("Key_Z", Qt::Key_Z);
  key.addValue("Key_BracketLeft", Qt::Key_BracketLeft);
  key.addValue("Key_Backslash", Qt::Key_Backslash);
  key.addValue("Key_BracketRight", Qt::Key_BracketRight);
  key.addValue("Key_AsciiCircum", Qt::Key_AsciiCircum);
  key.addValue("Key_Underscore", Qt::Key_Underscore);
  key.addValue("Key_QuoteLeft", Qt::Key_QuoteLeft);
  key.addValue("Key_BraceLeft", Qt::Key_BraceLeft);
  key.addValue("Key_Bar", Qt::Key_Bar);
  key.addValue("Key_BraceRight", Qt::Key_BraceRight);
  key.addValue("Key_AsciiTilde", Qt::Key_AsciiTilde);
  key.addValue("Key_nobreakspace", Qt::Key_nobreakspace);
  key.addValue("Key_exclamdown", Qt::Key_exclamdown);
  key.addValue("Key_cent", Qt::Key_cent);
  key.addValue("Key_sterling", Qt::Key_sterling);
  key.addValue("Key_currency", Qt::Key_currency);
  key.addValue("Key_yen", Qt::Key_yen);
  key.addValue("Key_brokenbar", Qt::Key_brokenbar);
  key.addValue("Key_section", Qt::Key_section);
  key.addValue("Key_diaeresis", Qt::Key_diaeresis);
  key.addValue("Key_copyright", Qt::Key_copyright);
  key.addValue("Key_ordfeminine", Qt::Key_ordfeminine);
  key.addValue("Key_guillemotleft", Qt::Key_guillemotleft);
  key.addValue("Key_notsign", Qt::Key_notsign);
  key.addValue("Key_hyphen", Qt::Key_hyphen);
  key.addValue("Key_registered", Qt::Key_registered);
  key.addValue("Key_macron", Qt::Key_macron);
  key.addValue("Key_degree", Qt::Key_degree);
  key.addValue("Key_plusminus", Qt::Key_plusminus);
  key.addValue("Key_twosuperior", Qt::Key_twosuperior);
  key.addValue("Key_threesuperior", Qt::Key_threesuperior);
  key.addValue("Key_acute", Qt::Key_acute);
  key.addValue("Key_mu", Qt::Key_mu);
  key.addValue("Key_paragraph", Qt::Key_paragraph);
  key.addValue("Key_periodcentered", Qt::Key_periodcentered);
  key.addValue("Key_cedilla", Qt::Key_cedilla);
  key.addValue("Key_onesuperior", Qt::Key_onesuperior);
  key.addValue("Key_masculine", Qt::Key_masculine);
  key.addValue("Key_guillemotright", Qt::Key_guillemotright);
  key.addValue("Key_onequarter", Qt::Key_onequarter);
  key.addValue("Key_onehalf", Qt::Key_onehalf);
  key.addValue("Key_threequarters", Qt::Key_threequarters);
  key.addValue("Key_questiondown", Qt::Key_questiondown);
  key.addValue("Key_Agrave", Qt::Key_Agrave);
  key.addValue("Key_Aacute", Qt::Key_Aacute);
  key.addValue("Key_Acircumflex", Qt::Key_Acircumflex);
  key.addValue("Key_Atilde", Qt::Key_Atilde);
  key.addValue("Key_Adiaeresis", Qt::Key_Adiaeresis);
  key.addValue("Key_Aring", Qt::Key_Aring);
  key.addValue("Key_AE", Qt::Key_AE);
  key.addValue("Key_Ccedilla", Qt::Key_Ccedilla);
  key.addValue("Key_Egrave", Qt::Key_Egrave);
  key.addValue("Key_Eacute", Qt::Key_Eacute);
  key.addValue("Key_Ecircumflex", Qt::Key_Ecircumflex);
  key.addValue("Key_Ediaeresis", Qt::Key_Ediaeresis);
  key.addValue("Key_Igrave", Qt::Key_Igrave);
  key.addValue("Key_Iacute", Qt::Key_Iacute);
  key.addValue("Key_Icircumflex", Qt::Key_Icircumflex);
  key.addValue("Key_Idiaeresis", Qt::Key_Idiaeresis);
  key.addValue("Key_ETH", Qt::Key_ETH);
  key.addValue("Key_Ntilde", Qt::Key_Ntilde);
  key.addValue("Key_Ograve", Qt::Key_Ograve);
  key.addValue("Key_Oacute", Qt::Key_Oacute);
  key.addValue("Key_Ocircumflex", Qt::Key_Ocircumflex);
  key.addValue("Key_Otilde", Qt::Key_Otilde);
  key.addValue("Key_Odiaeresis", Qt::Key_Odiaeresis);
  key.addValue("Key_multiply", Qt::Key_multiply);
  key.addValue("Key_Ooblique", Qt::Key_Ooblique);
  key.addValue("Key_Ugrave", Qt::Key_Ugrave);
  key.addValue("Key_Uacute", Qt::Key_Uacute);
  key.addValue("Key_Ucircumflex", Qt::Key_Ucircumflex);
  key.addValue("Key_Udiaeresis", Qt::Key_Udiaeresis);
  key.addValue("Key_Yacute", Qt::Key_Yacute);
  key.addValue("Key_THORN", Qt::Key_THORN);
  key.addValue("Key_ssharp", Qt::Key_ssharp);
  key.addValue("Key_division", Qt::Key_division);
  key.addValue("Key_ydiaeresis", Qt::Key_ydiaeresis);
  key.addValue("Key_AltGr", Qt::Key_AltGr);
  key.addValue("Key_Multi_key", Qt::Key_Multi_key);
  key.addValue("Key_Codeinput", Qt::Key_Codeinput);
  key.addValue("Key_SingleCandidate", Qt::Key_SingleCandidate);
  key.addValue("Key_MultipleCandidate", Qt::Key_MultipleCandidate);
  key.addValue("Key_PreviousCandidate", Qt::Key_PreviousCandidate);
  key.addValue("Key_Mode_switch", Qt::Key_Mode_switch);
  key.addValue("Key_Kanji", Qt::Key_Kanji);
  key.addValue("Key_Muhenkan", Qt::Key_Muhenkan);
  key.addValue("Key_Henkan", Qt::Key_Henkan);
  key.addValue("Key_Romaji", Qt::Key_Romaji);
  key.addValue("Key_Hiragana", Qt::Key_Hiragana);
  key.addValue("Key_Katakana", Qt::Key_Katakana);
  key.addValue("Key_Hiragana_Katakana", Qt::Key_Hiragana_Katakana);
  key.addValue("Key_Zenkaku", Qt::Key_Zenkaku);
  key.addValue("Key_Hankaku", Qt::Key_Hankaku);
  key.addValue("Key_Zenkaku_Hankaku", Qt::Key_Zenkaku_Hankaku);
  key.addValue("Key_Touroku", Qt::Key_Touroku);
  key.addValue("Key_Massyo", Qt::Key_Massyo);
  key.addValue("Key_Kana_Lock", Qt::Key_Kana_Lock);
  key.addValue("Key_Kana_Shift", Qt::Key_Kana_Shift);
  key.addValue("Key_Eisu_Shift", Qt::Key_Eisu_Shift);
  key.addValue("Key_Eisu_toggle", Qt::Key_Eisu_toggle);
  key.addValue("Key_Hangul", Qt::Key_Hangul);
  key.addValue("Key_Hangul_Start", Qt::Key_Hangul_Start);
  key.addValue("Key_Hangul_End", Qt::Key_Hangul_End);
  key.addValue("Key_Hangul_Hanja", Qt::Key_Hangul_Hanja);
  key.addValue("Key_Hangul_Jamo", Qt::Key_Hangul_Jamo);
  key.addValue("Key_Hangul_Romaja", Qt::Key_Hangul_Romaja);
  key.addValue("Key_Hangul_Jeonja", Qt::Key_Hangul_Jeonja);
  key.addValue("Key_Hangul_Banja", Qt::Key_Hangul_Banja);
  key.addValue("Key_Hangul_PreHanja", Qt::Key_Hangul_PreHanja);
  key.addValue("Key_Hangul_PostHanja", Qt::Key_Hangul_PostHanja);
  key.addValue("Key_Hangul_Special", Qt::Key_Hangul_Special);
  key.addValue("Key_Dead_Grave", Qt::Key_Dead_Grave);
  key.addValue("Key_Dead_Acute", Qt::Key_Dead_Acute);
  key.addValue("Key_Dead_Circumflex", Qt::Key_Dead_Circumflex);
  key.addValue("Key_Dead_Tilde", Qt::Key_Dead_Tilde);
  key.addValue("Key_Dead_Macron", Qt::Key_Dead_Macron);
  key.addValue("Key_Dead_Breve", Qt::Key_Dead_Breve);
  key.addValue("Key_Dead_Abovedot", Qt::Key_Dead_Abovedot);
  key.addValue("Key_Dead_Diaeresis", Qt::Key_Dead_Diaeresis);
  key.addValue("Key_Dead_Abovering", Qt::Key_Dead_Abovering);
  key.addValue("Key_Dead_Doubleacute", Qt::Key_Dead_Doubleacute);
  key.addValue("Key_Dead_Caron", Qt::Key_Dead_Caron);
  key.addValue("Key_Dead_Cedilla", Qt::Key_Dead_Cedilla);
  key.addValue("Key_Dead_Ogonek", Qt::Key_Dead_Ogonek);
  key.addValue("Key_Dead_Iota", Qt::Key_Dead_Iota);
  key.addValue("Key_Dead_Voiced_Sound", Qt::Key_Dead_Voiced_Sound);
  key.addValue("Key_Dead_Semivoiced_Sound", Qt::Key_Dead_Semivoiced_Sound);
  key.addValue("Key_Dead_Belowdot", Qt::Key_Dead_Belowdot);
  key.addValue("Key_Dead_Hook", Qt::Key_Dead_Hook);
  key.addValue("Key_Dead_Horn", Qt::Key_Dead_Horn);
  key.addValue("Key_Back", Qt::Key_Back);
  key.addValue("Key_Forward", Qt::Key_Forward);
  key.addValue("Key_Stop", Qt::Key_Stop);
  key.addValue("Key_Refresh", Qt::Key_Refresh);
  key.addValue("Key_VolumeDown", Qt::Key_VolumeDown);
  key.addValue("Key_VolumeMute", Qt::Key_VolumeMute);
  key.addValue("Key_VolumeUp", Qt::Key_VolumeUp);
  key.addValue("Key_BassBoost", Qt::Key_BassBoost);
  key.addValue("Key_BassUp", Qt::Key_BassUp);
  key.addValue("Key_BassDown", Qt::Key_BassDown);
  key.addValue("Key_TrebleUp", Qt::Key_TrebleUp);
  key.addValue("Key_TrebleDown", Qt::Key_TrebleDown);
  key.addValue("Key_MediaPlay", Qt::Key_MediaPlay);
  key.addValue("Key_MediaStop", Qt::Key_MediaStop);
  key.addValue("Key_MediaPrevious", Qt::Key_MediaPrevious);
  key.addValue("Key_MediaNext", Qt::Key_MediaNext);
  key.addValue("Key_MediaRecord", Qt::Key_MediaRecord);
  key.addValue("Key_MediaPause", Qt::Key_MediaPause);
  key.addValue("Key_MediaTogglePlayPause", Qt::Key_MediaTogglePlayPause);
  key.addValue("Key_HomePage", Qt::Key_HomePage);
  key.addValue("Key_Favorites", Qt::Key_Favorites);
  key.addValue("Key_Search", Qt::Key_Search);
  key.addValue("Key_Standby", Qt::Key_Standby);
  key.addValue("Key_OpenUrl", Qt::Key_OpenUrl);
  key.addValue("Key_LaunchMail", Qt::Key_LaunchMail);
  key.addValue("Key_LaunchMedia", Qt::Key_LaunchMedia);
  key.addValue("Key_Launch0", Qt::Key_Launch0);
  key.addValue("Key_Launch1", Qt::Key_Launch1);
  key.addValue("Key_Launch2", Qt::Key_Launch2);
  key.addValue("Key_Launch3", Qt::Key_Launch3);
  key.addValue("Key_Launch4", Qt::Key_Launch4);
  key.addValue("Key_Launch5", Qt::Key_Launch5);
  key.addValue("Key_Launch6", Qt::Key_Launch6);
  key.addValue("Key_Launch7", Qt::Key_Launch7);
  key.addValue("Key_Launch8", Qt::Key_Launch8);
  key.addValue("Key_Launch9", Qt::Key_Launch9);
  key.addValue("Key_LaunchA", Qt::Key_LaunchA);
  key.addValue("Key_LaunchB", Qt::Key_LaunchB);
  key.addValue("Key_LaunchC", Qt::Key_LaunchC);
  key.addValue("Key_LaunchD", Qt::Key_LaunchD);
  key.addValue("Key_LaunchE", Qt::Key_LaunchE);
  key.addValue("Key_LaunchF", Qt::Key_LaunchF);
  key.addValue("Key_MonBrightnessUp", Qt::Key_MonBrightnessUp);
  key.addValue("Key_MonBrightnessDown", Qt::Key_MonBrightnessDown);
  key.addValue("Key_KeyboardLightOnOff", Qt::Key_KeyboardLightOnOff);
  key.addValue("Key_KeyboardBrightnessUp", Qt::Key_KeyboardBrightnessUp);
  key.addValue("Key_KeyboardBrightnessDown", Qt::Key_KeyboardBrightnessDown);
  key.addValue("Key_PowerOff", Qt::Key_PowerOff);
  key.addValue("Key_WakeUp", Qt::Key_WakeUp);
  key.addValue("Key_Eject", Qt::Key_Eject);
  key.addValue("Key_ScreenSaver", Qt::Key_ScreenSaver);
  key.addValue("Key_WWW", Qt::Key_WWW);
  key.addValue("Key_Memo", Qt::Key_Memo);
  key.addValue("Key_LightBulb", Qt::Key_LightBulb);
  key.addValue("Key_Shop", Qt::Key_Shop);
  key.addValue("Key_History", Qt::Key_History);
  key.addValue("Key_AddFavorite", Qt::Key_AddFavorite);
  key.addValue("Key_HotLinks", Qt::Key_HotLinks);
  key.addValue("Key_BrightnessAdjust", Qt::Key_BrightnessAdjust);
  key.addValue("Key_Finance", Qt::Key_Finance);
  key.addValue("Key_Community", Qt::Key_Community);
  key.addValue("Key_AudioRewind", Qt::Key_AudioRewind);
  key.addValue("Key_BackForward", Qt::Key_BackForward);
  key.addValue("Key_ApplicationLeft", Qt::Key_ApplicationLeft);
  key.addValue("Key_ApplicationRight", Qt::Key_ApplicationRight);
  key.addValue("Key_Book", Qt::Key_Book);
  key.addValue("Key_CD", Qt::Key_CD);
  key.addValue("Key_Calculator", Qt::Key_Calculator);
  key.addValue("Key_ToDoList", Qt::Key_ToDoList);
  key.addValue("Key_ClearGrab", Qt::Key_ClearGrab);
  key.addValue("Key_Close", Qt::Key_Close);
  key.addValue("Key_Copy", Qt::Key_Copy);
  key.addValue("Key_Cut", Qt::Key_Cut);
  key.addValue("Key_Display", Qt::Key_Display);
  key.addValue("Key_DOS", Qt::Key_DOS);
  key.addValue("Key_Documents", Qt::Key_Documents);
  key.addValue("Key_Excel", Qt::Key_Excel);
  key.addValue("Key_Explorer", Qt::Key_Explorer);
  key.addValue("Key_Game", Qt::Key_Game);
  key.addValue("Key_Go", Qt::Key_Go);
  key.addValue("Key_iTouch", Qt::Key_iTouch);
  key.addValue("Key_LogOff", Qt::Key_LogOff);
  key.addValue("Key_Market", Qt::Key_Market);
  key.addValue("Key_Meeting", Qt::Key_Meeting);
  key.addValue("Key_MenuKB", Qt::Key_MenuKB);
  key.addValue("Key_MenuPB", Qt::Key_MenuPB);
  key.addValue("Key_MySites", Qt::Key_MySites);
  key.addValue("Key_News", Qt::Key_News);
  key.addValue("Key_OfficeHome", Qt::Key_OfficeHome);
  key.addValue("Key_Option", Qt::Key_Option);
  key.addValue("Key_Paste", Qt::Key_Paste);
  key.addValue("Key_Phone", Qt::Key_Phone);
  key.addValue("Key_Calendar", Qt::Key_Calendar);
  key.addValue("Key_Reply", Qt::Key_Reply);
  key.addValue("Key_Reload", Qt::Key_Reload);
  key.addValue("Key_RotateWindows", Qt::Key_RotateWindows);
  key.addValue("Key_RotationPB", Qt::Key_RotationPB);
  key.addValue("Key_RotationKB", Qt::Key_RotationKB);
  key.addValue("Key_Save", Qt::Key_Save);
  key.addValue("Key_Send", Qt::Key_Send);
  key.addValue("Key_Spell", Qt::Key_Spell);
  key.addValue("Key_SplitScreen", Qt::Key_SplitScreen);
  key.addValue("Key_Support", Qt::Key_Support);
  key.addValue("Key_TaskPane", Qt::Key_TaskPane);
  key.addValue("Key_Terminal", Qt::Key_Terminal);
  key.addValue("Key_Tools", Qt::Key_Tools);
  key.addValue("Key_Travel", Qt::Key_Travel);
  key.addValue("Key_Video", Qt::Key_Video);
  key.addValue("Key_Word", Qt::Key_Word);
  key.addValue("Key_Xfer", Qt::Key_Xfer);
  key.addValue("Key_ZoomIn", Qt::Key_ZoomIn);
  key.addValue("Key_ZoomOut", Qt::Key_ZoomOut);
  key.addValue("Key_Away", Qt::Key_Away);
  key.addValue("Key_Messenger", Qt::Key_Messenger);
  key.addValue("Key_WebCam", Qt::Key_WebCam);
  key.addValue("Key_MailForward", Qt::Key_MailForward);
  key.addValue("Key_Pictures", Qt::Key_Pictures);
  key.addValue("Key_Music", Qt::Key_Music);
  key.addValue("Key_Battery", Qt::Key_Battery);
  key.addValue("Key_Bluetooth", Qt::Key_Bluetooth);
  key.addValue("Key_WLAN", Qt::Key_WLAN);
  key.addValue("Key_UWB", Qt::Key_UWB);
  key.addValue("Key_AudioForward", Qt::Key_AudioForward);
  key.addValue("Key_AudioRepeat", Qt::Key_AudioRepeat);
  key.addValue("Key_AudioRandomPlay", Qt::Key_AudioRandomPlay);
  key.addValue("Key_Subtitle", Qt::Key_Subtitle);
  key.addValue("Key_AudioCycleTrack", Qt::Key_AudioCycleTrack);
  key.addValue("Key_Time", Qt::Key_Time);
  key.addValue("Key_Hibernate", Qt::Key_Hibernate);
  key.addValue("Key_View", Qt::Key_View);
  key.addValue("Key_TopMenu", Qt::Key_TopMenu);
  key.addValue("Key_PowerDown", Qt::Key_PowerDown);
  key.addValue("Key_Suspend", Qt::Key_Suspend);
  key.addValue("Key_ContrastAdjust", Qt::Key_ContrastAdjust);
  key.addValue("Key_LaunchG", Qt::Key_LaunchG);
  key.addValue("Key_LaunchH", Qt::Key_LaunchH);
  key.addValue("Key_TouchpadToggle", Qt::Key_TouchpadToggle);
  key.addValue("Key_TouchpadOn", Qt::Key_TouchpadOn);
  key.addValue("Key_TouchpadOff", Qt::Key_TouchpadOff);
  key.addValue("Key_MicMute", Qt::Key_MicMute);
  key.addValue("Key_Red", Qt::Key_Red);
  key.addValue("Key_Green", Qt::Key_Green);
  key.addValue("Key_Yellow", Qt::Key_Yellow);
  key.addValue("Key_Blue", Qt::Key_Blue);
  key.addValue("Key_ChannelUp", Qt::Key_ChannelUp);
  key.addValue("Key_ChannelDown", Qt::Key_ChannelDown);
  key.addValue("Key_Guide", Qt::Key_Guide);
  key.addValue("Key_Info", Qt::Key_Info);
  key.addValue("Key_Settings", Qt::Key_Settings);
  key.addValue("Key_MicVolumeUp", Qt::Key_MicVolumeUp);
  key.addValue("Key_MicVolumeDown", Qt::Key_MicVolumeDown);
  key.addValue("Key_New", Qt::Key_New);
  key.addValue("Key_Open", Qt::Key_Open);
  key.addValue("Key_Find", Qt::Key_Find);
  key.addValue("Key_Undo", Qt::Key_Undo);
  key.addValue("Key_Redo", Qt::Key_Redo);
  key.addValue("Key_MediaLast", Qt::Key_MediaLast);
  key.addValue("Key_Select", Qt::Key_Select);
  key.addValue("Key_Yes", Qt::Key_Yes);
  key.addValue("Key_No", Qt::Key_No);
  key.addValue("Key_Cancel", Qt::Key_Cancel);
  key.addValue("Key_Printer", Qt::Key_Printer);
  key.addValue("Key_Execute", Qt::Key_Execute);
  key.addValue("Key_Sleep", Qt::Key_Sleep);
  key.addValue("Key_Play", Qt::Key_Play);
  key.addValue("Key_Zoom", Qt::Key_Zoom);
  key.addValue("Key_Exit", Qt::Key_Exit);
  key.addValue("Key_Context1", Qt::Key_Context1);
  key.addValue("Key_Context2", Qt::Key_Context2);
  key.addValue("Key_Context3", Qt::Key_Context3);
  key.addValue("Key_Context4", Qt::Key_Context4);
  key.addValue("Key_Call", Qt::Key_Call);
  key.addValue("Key_Hangup", Qt::Key_Hangup);
  key.addValue("Key_Flip", Qt::Key_Flip);
  key.addValue("Key_ToggleCallHangup", Qt::Key_ToggleCallHangup);
  key.addValue("Key_VoiceDial", Qt::Key_VoiceDial);
  key.addValue("Key_LastNumberRedial", Qt::Key_LastNumberRedial);
  key.addValue("Key_Camera", Qt::Key_Camera);
  key.addValue("Key_CameraFocus", Qt::Key_CameraFocus);
  key.addValue("Key_unknown", Qt::Key_unknown);
}


static void register_qt_arrow_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum arrow_type = qt.Enum("ArrowType").setId(script::Type::QtArrowType)
    .setEnumClass().get();

  arrow_type.addValue("NoArrow", Qt::NoArrow);
  arrow_type.addValue("UpArrow", Qt::UpArrow);
  arrow_type.addValue("DownArrow", Qt::DownArrow);
  arrow_type.addValue("LeftArrow", Qt::LeftArrow);
  arrow_type.addValue("RightArrow", Qt::RightArrow);
}


static void register_qt_pen_style_enum(script::Namespace qt)
{
  using namespace script;

  Enum pen_style = qt.Enum("PenStyle").setId(script::Type::QtPenStyle)
    .setEnumClass().get();

  pen_style.addValue("NoPen", Qt::NoPen);
  pen_style.addValue("SolidLine", Qt::SolidLine);
  pen_style.addValue("DashLine", Qt::DashLine);
  pen_style.addValue("DotLine", Qt::DotLine);
  pen_style.addValue("DashDotLine", Qt::DashDotLine);
  pen_style.addValue("DashDotDotLine", Qt::DashDotDotLine);
  pen_style.addValue("CustomDashLine", Qt::CustomDashLine);
  pen_style.addValue("MPenStyle", Qt::MPenStyle);
}


static void register_qt_pen_cap_style_enum(script::Namespace qt)
{
  using namespace script;

  Enum pen_cap_style = qt.Enum("PenCapStyle").setId(script::Type::QtPenCapStyle)
    .setEnumClass().get();

  pen_cap_style.addValue("FlatCap", Qt::FlatCap);
  pen_cap_style.addValue("SquareCap", Qt::SquareCap);
  pen_cap_style.addValue("RoundCap", Qt::RoundCap);
  pen_cap_style.addValue("MPenCapStyle", Qt::MPenCapStyle);
}


static void register_qt_pen_join_style_enum(script::Namespace qt)
{
  using namespace script;

  Enum pen_join_style = qt.Enum("PenJoinStyle").setId(script::Type::QtPenJoinStyle)
    .setEnumClass().get();

  pen_join_style.addValue("MiterJoin", Qt::MiterJoin);
  pen_join_style.addValue("BevelJoin", Qt::BevelJoin);
  pen_join_style.addValue("RoundJoin", Qt::RoundJoin);
  pen_join_style.addValue("SvgMiterJoin", Qt::SvgMiterJoin);
  pen_join_style.addValue("MPenJoinStyle", Qt::MPenJoinStyle);
}


static void register_qt_brush_style_enum(script::Namespace qt)
{
  using namespace script;

  Enum brush_style = qt.Enum("BrushStyle").setId(script::Type::QtBrushStyle)
    .setEnumClass().get();

  brush_style.addValue("NoBrush", Qt::NoBrush);
  brush_style.addValue("SolidPattern", Qt::SolidPattern);
  brush_style.addValue("Dense1Pattern", Qt::Dense1Pattern);
  brush_style.addValue("Dense2Pattern", Qt::Dense2Pattern);
  brush_style.addValue("Dense3Pattern", Qt::Dense3Pattern);
  brush_style.addValue("Dense4Pattern", Qt::Dense4Pattern);
  brush_style.addValue("Dense5Pattern", Qt::Dense5Pattern);
  brush_style.addValue("Dense6Pattern", Qt::Dense6Pattern);
  brush_style.addValue("Dense7Pattern", Qt::Dense7Pattern);
  brush_style.addValue("HorPattern", Qt::HorPattern);
  brush_style.addValue("VerPattern", Qt::VerPattern);
  brush_style.addValue("CrossPattern", Qt::CrossPattern);
  brush_style.addValue("BDiagPattern", Qt::BDiagPattern);
  brush_style.addValue("FDiagPattern", Qt::FDiagPattern);
  brush_style.addValue("DiagCrossPattern", Qt::DiagCrossPattern);
  brush_style.addValue("LinearGradientPattern", Qt::LinearGradientPattern);
  brush_style.addValue("RadialGradientPattern", Qt::RadialGradientPattern);
  brush_style.addValue("ConicalGradientPattern", Qt::ConicalGradientPattern);
  brush_style.addValue("TexturePattern", Qt::TexturePattern);
}


static void register_qt_size_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum size_mode = qt.Enum("SizeMode").setId(script::Type::QtSizeMode)
    .setEnumClass().get();

  size_mode.addValue("AbsoluteSize", Qt::AbsoluteSize);
  size_mode.addValue("RelativeSize", Qt::RelativeSize);
}


static void register_qt_u_i_effect_enum(script::Namespace qt)
{
  using namespace script;

  Enum u_i_effect = qt.Enum("UIEffect").setId(script::Type::QtUIEffect)
    .setEnumClass().get();

  u_i_effect.addValue("UI_General", Qt::UI_General);
  u_i_effect.addValue("UI_AnimateMenu", Qt::UI_AnimateMenu);
  u_i_effect.addValue("UI_FadeMenu", Qt::UI_FadeMenu);
  u_i_effect.addValue("UI_AnimateCombo", Qt::UI_AnimateCombo);
  u_i_effect.addValue("UI_AnimateTooltip", Qt::UI_AnimateTooltip);
  u_i_effect.addValue("UI_FadeTooltip", Qt::UI_FadeTooltip);
  u_i_effect.addValue("UI_AnimateToolBox", Qt::UI_AnimateToolBox);
}


static void register_qt_cursor_shape_enum(script::Namespace qt)
{
  using namespace script;

  Enum cursor_shape = qt.Enum("CursorShape").setId(script::Type::QtCursorShape)
    .setEnumClass().get();

  cursor_shape.addValue("ArrowCursor", Qt::ArrowCursor);
  cursor_shape.addValue("UpArrowCursor", Qt::UpArrowCursor);
  cursor_shape.addValue("CrossCursor", Qt::CrossCursor);
  cursor_shape.addValue("WaitCursor", Qt::WaitCursor);
  cursor_shape.addValue("IBeamCursor", Qt::IBeamCursor);
  cursor_shape.addValue("SizeVerCursor", Qt::SizeVerCursor);
  cursor_shape.addValue("SizeHorCursor", Qt::SizeHorCursor);
  cursor_shape.addValue("SizeBDiagCursor", Qt::SizeBDiagCursor);
  cursor_shape.addValue("SizeFDiagCursor", Qt::SizeFDiagCursor);
  cursor_shape.addValue("SizeAllCursor", Qt::SizeAllCursor);
  cursor_shape.addValue("BlankCursor", Qt::BlankCursor);
  cursor_shape.addValue("SplitVCursor", Qt::SplitVCursor);
  cursor_shape.addValue("SplitHCursor", Qt::SplitHCursor);
  cursor_shape.addValue("PointingHandCursor", Qt::PointingHandCursor);
  cursor_shape.addValue("ForbiddenCursor", Qt::ForbiddenCursor);
  cursor_shape.addValue("WhatsThisCursor", Qt::WhatsThisCursor);
  cursor_shape.addValue("BusyCursor", Qt::BusyCursor);
  cursor_shape.addValue("OpenHandCursor", Qt::OpenHandCursor);
  cursor_shape.addValue("ClosedHandCursor", Qt::ClosedHandCursor);
  cursor_shape.addValue("DragCopyCursor", Qt::DragCopyCursor);
  cursor_shape.addValue("DragMoveCursor", Qt::DragMoveCursor);
  cursor_shape.addValue("DragLinkCursor", Qt::DragLinkCursor);
  cursor_shape.addValue("LastCursor", Qt::LastCursor);
  cursor_shape.addValue("BitmapCursor", Qt::BitmapCursor);
  cursor_shape.addValue("CustomCursor", Qt::CustomCursor);
}


static void register_qt_text_format_enum(script::Namespace qt)
{
  using namespace script;

  Enum text_format = qt.Enum("TextFormat").setId(script::Type::QtTextFormat)
    .setEnumClass().get();

  text_format.addValue("PlainText", Qt::PlainText);
  text_format.addValue("RichText", Qt::RichText);
  text_format.addValue("AutoText", Qt::AutoText);
}


static void register_qt_aspect_ratio_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum aspect_ratio_mode = qt.Enum("AspectRatioMode").setId(script::Type::QtAspectRatioMode)
    .setEnumClass().get();

  aspect_ratio_mode.addValue("IgnoreAspectRatio", Qt::IgnoreAspectRatio);
  aspect_ratio_mode.addValue("KeepAspectRatio", Qt::KeepAspectRatio);
  aspect_ratio_mode.addValue("KeepAspectRatioByExpanding", Qt::KeepAspectRatioByExpanding);
}


static void register_qt_dock_widget_area_enum(script::Namespace qt)
{
  using namespace script;

  Enum dock_widget_area = qt.Enum("DockWidgetArea").setId(script::Type::QtDockWidgetArea)
    .setEnumClass().get();

  dock_widget_area.addValue("LeftDockWidgetArea", Qt::LeftDockWidgetArea);
  dock_widget_area.addValue("RightDockWidgetArea", Qt::RightDockWidgetArea);
  dock_widget_area.addValue("TopDockWidgetArea", Qt::TopDockWidgetArea);
  dock_widget_area.addValue("BottomDockWidgetArea", Qt::BottomDockWidgetArea);
  dock_widget_area.addValue("DockWidgetArea_Mask", Qt::DockWidgetArea_Mask);
  dock_widget_area.addValue("AllDockWidgetAreas", Qt::AllDockWidgetAreas);
  dock_widget_area.addValue("NoDockWidgetArea", Qt::NoDockWidgetArea);
}


static void register_qt_dock_widget_area_sizes_enum(script::Namespace qt)
{
  using namespace script;

  Enum dock_widget_area_sizes = qt.Enum("DockWidgetAreaSizes").setId(script::Type::QtDockWidgetAreaSizes)
    .setEnumClass().get();

  dock_widget_area_sizes.addValue("NDockWidgetAreas", Qt::NDockWidgetAreas);
}


static void register_qt_tool_bar_area_enum(script::Namespace qt)
{
  using namespace script;

  Enum tool_bar_area = qt.Enum("ToolBarArea").setId(script::Type::QtToolBarArea)
    .setEnumClass().get();

  tool_bar_area.addValue("LeftToolBarArea", Qt::LeftToolBarArea);
  tool_bar_area.addValue("RightToolBarArea", Qt::RightToolBarArea);
  tool_bar_area.addValue("TopToolBarArea", Qt::TopToolBarArea);
  tool_bar_area.addValue("BottomToolBarArea", Qt::BottomToolBarArea);
  tool_bar_area.addValue("ToolBarArea_Mask", Qt::ToolBarArea_Mask);
  tool_bar_area.addValue("AllToolBarAreas", Qt::AllToolBarAreas);
  tool_bar_area.addValue("NoToolBarArea", Qt::NoToolBarArea);
}


static void register_qt_tool_bar_area_sizes_enum(script::Namespace qt)
{
  using namespace script;

  Enum tool_bar_area_sizes = qt.Enum("ToolBarAreaSizes").setId(script::Type::QtToolBarAreaSizes)
    .setEnumClass().get();

  tool_bar_area_sizes.addValue("NToolBarAreas", Qt::NToolBarAreas);
}


static void register_qt_date_format_enum(script::Namespace qt)
{
  using namespace script;

  Enum date_format = qt.Enum("DateFormat").setId(script::Type::QtDateFormat)
    .setEnumClass().get();

  date_format.addValue("TextDate", Qt::TextDate);
  date_format.addValue("ISODate", Qt::ISODate);
  date_format.addValue("SystemLocaleDate", Qt::SystemLocaleDate);
  date_format.addValue("LocalDate", Qt::LocalDate);
  date_format.addValue("LocaleDate", Qt::LocaleDate);
  date_format.addValue("SystemLocaleShortDate", Qt::SystemLocaleShortDate);
  date_format.addValue("SystemLocaleLongDate", Qt::SystemLocaleLongDate);
  date_format.addValue("DefaultLocaleShortDate", Qt::DefaultLocaleShortDate);
  date_format.addValue("DefaultLocaleLongDate", Qt::DefaultLocaleLongDate);
  date_format.addValue("RFC2822Date", Qt::RFC2822Date);
  date_format.addValue("ISODateWithMs", Qt::ISODateWithMs);
}


static void register_qt_time_spec_enum(script::Namespace qt)
{
  using namespace script;

  Enum time_spec = qt.Enum("TimeSpec").setId(script::Type::QtTimeSpec)
    .setEnumClass().get();

  time_spec.addValue("LocalTime", Qt::LocalTime);
  time_spec.addValue("UTC", Qt::UTC);
  time_spec.addValue("OffsetFromUTC", Qt::OffsetFromUTC);
  time_spec.addValue("TimeZone", Qt::TimeZone);
}


static void register_qt_day_of_week_enum(script::Namespace qt)
{
  using namespace script;

  Enum day_of_week = qt.Enum("DayOfWeek").setId(script::Type::QtDayOfWeek)
    .setEnumClass().get();

  day_of_week.addValue("Monday", Qt::Monday);
  day_of_week.addValue("Tuesday", Qt::Tuesday);
  day_of_week.addValue("Wednesday", Qt::Wednesday);
  day_of_week.addValue("Thursday", Qt::Thursday);
  day_of_week.addValue("Friday", Qt::Friday);
  day_of_week.addValue("Saturday", Qt::Saturday);
  day_of_week.addValue("Sunday", Qt::Sunday);
}


static void register_qt_scroll_bar_policy_enum(script::Namespace qt)
{
  using namespace script;

  Enum scroll_bar_policy = qt.Enum("ScrollBarPolicy").setId(script::Type::QtScrollBarPolicy)
    .setEnumClass().get();

  scroll_bar_policy.addValue("ScrollBarAsNeeded", Qt::ScrollBarAsNeeded);
  scroll_bar_policy.addValue("ScrollBarAlwaysOff", Qt::ScrollBarAlwaysOff);
  scroll_bar_policy.addValue("ScrollBarAlwaysOn", Qt::ScrollBarAlwaysOn);
}


static void register_qt_case_sensitivity_enum(script::Namespace qt)
{
  using namespace script;

  Enum case_sensitivity = qt.Enum("CaseSensitivity").setId(script::Type::QtCaseSensitivity)
    .setEnumClass().get();

  case_sensitivity.addValue("CaseInsensitive", Qt::CaseInsensitive);
  case_sensitivity.addValue("CaseSensitive", Qt::CaseSensitive);
}


static void register_qt_corner_enum(script::Namespace qt)
{
  using namespace script;

  Enum corner = qt.Enum("Corner").setId(script::Type::QtCorner)
    .setEnumClass().get();

  corner.addValue("TopLeftCorner", Qt::TopLeftCorner);
  corner.addValue("TopRightCorner", Qt::TopRightCorner);
  corner.addValue("BottomLeftCorner", Qt::BottomLeftCorner);
  corner.addValue("BottomRightCorner", Qt::BottomRightCorner);
}


static void register_qt_edge_enum(script::Namespace qt)
{
  using namespace script;

  Enum edge = qt.Enum("Edge").setId(script::Type::QtEdge)
    .setEnumClass().get();

  edge.addValue("TopEdge", Qt::TopEdge);
  edge.addValue("LeftEdge", Qt::LeftEdge);
  edge.addValue("RightEdge", Qt::RightEdge);
  edge.addValue("BottomEdge", Qt::BottomEdge);
}


static void register_qt_connection_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum connection_type = qt.Enum("ConnectionType").setId(script::Type::QtConnectionType)
    .setEnumClass().get();

  connection_type.addValue("AutoConnection", Qt::AutoConnection);
  connection_type.addValue("DirectConnection", Qt::DirectConnection);
  connection_type.addValue("QueuedConnection", Qt::QueuedConnection);
  connection_type.addValue("BlockingQueuedConnection", Qt::BlockingQueuedConnection);
  connection_type.addValue("UniqueConnection", Qt::UniqueConnection);
}


static void register_qt_shortcut_context_enum(script::Namespace qt)
{
  using namespace script;

  Enum shortcut_context = qt.Enum("ShortcutContext").setId(script::Type::QtShortcutContext)
    .setEnumClass().get();

  shortcut_context.addValue("WidgetShortcut", Qt::WidgetShortcut);
  shortcut_context.addValue("WindowShortcut", Qt::WindowShortcut);
  shortcut_context.addValue("ApplicationShortcut", Qt::ApplicationShortcut);
  shortcut_context.addValue("WidgetWithChildrenShortcut", Qt::WidgetWithChildrenShortcut);
}


static void register_qt_fill_rule_enum(script::Namespace qt)
{
  using namespace script;

  Enum fill_rule = qt.Enum("FillRule").setId(script::Type::QtFillRule)
    .setEnumClass().get();

  fill_rule.addValue("OddEvenFill", Qt::OddEvenFill);
  fill_rule.addValue("WindingFill", Qt::WindingFill);
}


static void register_qt_mask_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum mask_mode = qt.Enum("MaskMode").setId(script::Type::QtMaskMode)
    .setEnumClass().get();

  mask_mode.addValue("MaskInColor", Qt::MaskInColor);
  mask_mode.addValue("MaskOutColor", Qt::MaskOutColor);
}


static void register_qt_clip_operation_enum(script::Namespace qt)
{
  using namespace script;

  Enum clip_operation = qt.Enum("ClipOperation").setId(script::Type::QtClipOperation)
    .setEnumClass().get();

  clip_operation.addValue("NoClip", Qt::NoClip);
  clip_operation.addValue("ReplaceClip", Qt::ReplaceClip);
  clip_operation.addValue("IntersectClip", Qt::IntersectClip);
}


static void register_qt_item_selection_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum item_selection_mode = qt.Enum("ItemSelectionMode").setId(script::Type::QtItemSelectionMode)
    .setEnumClass().get();

  item_selection_mode.addValue("ContainsItemShape", Qt::ContainsItemShape);
  item_selection_mode.addValue("IntersectsItemShape", Qt::IntersectsItemShape);
  item_selection_mode.addValue("ContainsItemBoundingRect", Qt::ContainsItemBoundingRect);
  item_selection_mode.addValue("IntersectsItemBoundingRect", Qt::IntersectsItemBoundingRect);
}


static void register_qt_item_selection_operation_enum(script::Namespace qt)
{
  using namespace script;

  Enum item_selection_operation = qt.Enum("ItemSelectionOperation").setId(script::Type::QtItemSelectionOperation)
    .setEnumClass().get();

  item_selection_operation.addValue("ReplaceSelection", Qt::ReplaceSelection);
  item_selection_operation.addValue("AddToSelection", Qt::AddToSelection);
}


static void register_qt_transformation_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum transformation_mode = qt.Enum("TransformationMode").setId(script::Type::QtTransformationMode)
    .setEnumClass().get();

  transformation_mode.addValue("FastTransformation", Qt::FastTransformation);
  transformation_mode.addValue("SmoothTransformation", Qt::SmoothTransformation);
}


static void register_qt_axis_enum(script::Namespace qt)
{
  using namespace script;

  Enum axis = qt.Enum("Axis").setId(script::Type::QtAxis)
    .setEnumClass().get();

  axis.addValue("XAxis", Qt::XAxis);
  axis.addValue("YAxis", Qt::YAxis);
  axis.addValue("ZAxis", Qt::ZAxis);
}


static void register_qt_focus_reason_enum(script::Namespace qt)
{
  using namespace script;

  Enum focus_reason = qt.Enum("FocusReason").setId(script::Type::QtFocusReason)
    .setEnumClass().get();

  focus_reason.addValue("MouseFocusReason", Qt::MouseFocusReason);
  focus_reason.addValue("TabFocusReason", Qt::TabFocusReason);
  focus_reason.addValue("BacktabFocusReason", Qt::BacktabFocusReason);
  focus_reason.addValue("ActiveWindowFocusReason", Qt::ActiveWindowFocusReason);
  focus_reason.addValue("PopupFocusReason", Qt::PopupFocusReason);
  focus_reason.addValue("ShortcutFocusReason", Qt::ShortcutFocusReason);
  focus_reason.addValue("MenuBarFocusReason", Qt::MenuBarFocusReason);
  focus_reason.addValue("OtherFocusReason", Qt::OtherFocusReason);
  focus_reason.addValue("NoFocusReason", Qt::NoFocusReason);
}


static void register_qt_context_menu_policy_enum(script::Namespace qt)
{
  using namespace script;

  Enum context_menu_policy = qt.Enum("ContextMenuPolicy").setId(script::Type::QtContextMenuPolicy)
    .setEnumClass().get();

  context_menu_policy.addValue("NoContextMenu", Qt::NoContextMenu);
  context_menu_policy.addValue("DefaultContextMenu", Qt::DefaultContextMenu);
  context_menu_policy.addValue("ActionsContextMenu", Qt::ActionsContextMenu);
  context_menu_policy.addValue("CustomContextMenu", Qt::CustomContextMenu);
  context_menu_policy.addValue("PreventContextMenu", Qt::PreventContextMenu);
}


static void register_qt_input_method_query_enum(script::Namespace qt)
{
  using namespace script;

  Enum input_method_query = qt.Enum("InputMethodQuery").setId(script::Type::QtInputMethodQuery)
    .setEnumClass().get();

  input_method_query.addValue("ImEnabled", Qt::ImEnabled);
  input_method_query.addValue("ImCursorRectangle", Qt::ImCursorRectangle);
  input_method_query.addValue("ImMicroFocus", Qt::ImMicroFocus);
  input_method_query.addValue("ImFont", Qt::ImFont);
  input_method_query.addValue("ImCursorPosition", Qt::ImCursorPosition);
  input_method_query.addValue("ImSurroundingText", Qt::ImSurroundingText);
  input_method_query.addValue("ImCurrentSelection", Qt::ImCurrentSelection);
  input_method_query.addValue("ImMaximumTextLength", Qt::ImMaximumTextLength);
  input_method_query.addValue("ImAnchorPosition", Qt::ImAnchorPosition);
  input_method_query.addValue("ImHints", Qt::ImHints);
  input_method_query.addValue("ImPreferredLanguage", Qt::ImPreferredLanguage);
  input_method_query.addValue("ImAbsolutePosition", Qt::ImAbsolutePosition);
  input_method_query.addValue("ImTextBeforeCursor", Qt::ImTextBeforeCursor);
  input_method_query.addValue("ImTextAfterCursor", Qt::ImTextAfterCursor);
  input_method_query.addValue("ImEnterKeyType", Qt::ImEnterKeyType);
  input_method_query.addValue("ImAnchorRectangle", Qt::ImAnchorRectangle);
  input_method_query.addValue("ImInputItemClipRectangle", Qt::ImInputItemClipRectangle);
  input_method_query.addValue("ImPlatformData", Qt::ImPlatformData);
  input_method_query.addValue("ImQueryInput", Qt::ImQueryInput);
  input_method_query.addValue("ImQueryAll", Qt::ImQueryAll);
}


static void register_qt_input_method_hint_enum(script::Namespace qt)
{
  using namespace script;

  Enum input_method_hint = qt.Enum("InputMethodHint").setId(script::Type::QtInputMethodHint)
    .setEnumClass().get();

  input_method_hint.addValue("ImhNone", Qt::ImhNone);
  input_method_hint.addValue("ImhHiddenText", Qt::ImhHiddenText);
  input_method_hint.addValue("ImhSensitiveData", Qt::ImhSensitiveData);
  input_method_hint.addValue("ImhNoAutoUppercase", Qt::ImhNoAutoUppercase);
  input_method_hint.addValue("ImhPreferNumbers", Qt::ImhPreferNumbers);
  input_method_hint.addValue("ImhPreferUppercase", Qt::ImhPreferUppercase);
  input_method_hint.addValue("ImhPreferLowercase", Qt::ImhPreferLowercase);
  input_method_hint.addValue("ImhNoPredictiveText", Qt::ImhNoPredictiveText);
  input_method_hint.addValue("ImhDate", Qt::ImhDate);
  input_method_hint.addValue("ImhTime", Qt::ImhTime);
  input_method_hint.addValue("ImhPreferLatin", Qt::ImhPreferLatin);
  input_method_hint.addValue("ImhMultiLine", Qt::ImhMultiLine);
  input_method_hint.addValue("ImhDigitsOnly", Qt::ImhDigitsOnly);
  input_method_hint.addValue("ImhFormattedNumbersOnly", Qt::ImhFormattedNumbersOnly);
  input_method_hint.addValue("ImhUppercaseOnly", Qt::ImhUppercaseOnly);
  input_method_hint.addValue("ImhLowercaseOnly", Qt::ImhLowercaseOnly);
  input_method_hint.addValue("ImhDialableCharactersOnly", Qt::ImhDialableCharactersOnly);
  input_method_hint.addValue("ImhEmailCharactersOnly", Qt::ImhEmailCharactersOnly);
  input_method_hint.addValue("ImhUrlCharactersOnly", Qt::ImhUrlCharactersOnly);
  input_method_hint.addValue("ImhLatinOnly", Qt::ImhLatinOnly);
  input_method_hint.addValue("ImhExclusiveInputMask", Qt::ImhExclusiveInputMask);
}


static void register_qt_enter_key_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum enter_key_type = qt.Enum("EnterKeyType").setId(script::Type::QtEnterKeyType)
    .setEnumClass().get();

  enter_key_type.addValue("EnterKeyDefault", Qt::EnterKeyDefault);
  enter_key_type.addValue("EnterKeyReturn", Qt::EnterKeyReturn);
  enter_key_type.addValue("EnterKeyDone", Qt::EnterKeyDone);
  enter_key_type.addValue("EnterKeyGo", Qt::EnterKeyGo);
  enter_key_type.addValue("EnterKeySend", Qt::EnterKeySend);
  enter_key_type.addValue("EnterKeySearch", Qt::EnterKeySearch);
  enter_key_type.addValue("EnterKeyNext", Qt::EnterKeyNext);
  enter_key_type.addValue("EnterKeyPrevious", Qt::EnterKeyPrevious);
}


static void register_qt_tool_button_style_enum(script::Namespace qt)
{
  using namespace script;

  Enum tool_button_style = qt.Enum("ToolButtonStyle").setId(script::Type::QtToolButtonStyle)
    .setEnumClass().get();

  tool_button_style.addValue("ToolButtonIconOnly", Qt::ToolButtonIconOnly);
  tool_button_style.addValue("ToolButtonTextOnly", Qt::ToolButtonTextOnly);
  tool_button_style.addValue("ToolButtonTextBesideIcon", Qt::ToolButtonTextBesideIcon);
  tool_button_style.addValue("ToolButtonTextUnderIcon", Qt::ToolButtonTextUnderIcon);
  tool_button_style.addValue("ToolButtonFollowStyle", Qt::ToolButtonFollowStyle);
}


static void register_qt_layout_direction_enum(script::Namespace qt)
{
  using namespace script;

  Enum layout_direction = qt.Enum("LayoutDirection").setId(script::Type::QtLayoutDirection)
    .setEnumClass().get();

  layout_direction.addValue("LeftToRight", Qt::LeftToRight);
  layout_direction.addValue("RightToLeft", Qt::RightToLeft);
  layout_direction.addValue("LayoutDirectionAuto", Qt::LayoutDirectionAuto);
}


static void register_qt_anchor_point_enum(script::Namespace qt)
{
  using namespace script;

  Enum anchor_point = qt.Enum("AnchorPoint").setId(script::Type::QtAnchorPoint)
    .setEnumClass().get();

  anchor_point.addValue("AnchorLeft", Qt::AnchorLeft);
  anchor_point.addValue("AnchorHorizontalCenter", Qt::AnchorHorizontalCenter);
  anchor_point.addValue("AnchorRight", Qt::AnchorRight);
  anchor_point.addValue("AnchorTop", Qt::AnchorTop);
  anchor_point.addValue("AnchorVerticalCenter", Qt::AnchorVerticalCenter);
  anchor_point.addValue("AnchorBottom", Qt::AnchorBottom);
}


static void register_qt_find_child_option_enum(script::Namespace qt)
{
  using namespace script;

  Enum find_child_option = qt.Enum("FindChildOption").setId(script::Type::QtFindChildOption)
    .setEnumClass().get();

  find_child_option.addValue("FindDirectChildrenOnly", Qt::FindDirectChildrenOnly);
  find_child_option.addValue("FindChildrenRecursively", Qt::FindChildrenRecursively);
}


static void register_qt_drop_action_enum(script::Namespace qt)
{
  using namespace script;

  Enum drop_action = qt.Enum("DropAction").setId(script::Type::QtDropAction)
    .setEnumClass().get();

  drop_action.addValue("CopyAction", Qt::CopyAction);
  drop_action.addValue("MoveAction", Qt::MoveAction);
  drop_action.addValue("LinkAction", Qt::LinkAction);
  drop_action.addValue("ActionMask", Qt::ActionMask);
  drop_action.addValue("TargetMoveAction", Qt::TargetMoveAction);
  drop_action.addValue("IgnoreAction", Qt::IgnoreAction);
}


static void register_qt_check_state_enum(script::Namespace qt)
{
  using namespace script;

  Enum check_state = qt.Enum("CheckState").setId(script::Type::QtCheckState)
    .setEnumClass().get();

  check_state.addValue("Unchecked", Qt::Unchecked);
  check_state.addValue("PartiallyChecked", Qt::PartiallyChecked);
  check_state.addValue("Checked", Qt::Checked);
}


static void register_qt_item_data_role_enum(script::Namespace qt)
{
  using namespace script;

  Enum item_data_role = qt.Enum("ItemDataRole").setId(script::Type::QtItemDataRole)
    .setEnumClass().get();

  item_data_role.addValue("DisplayRole", Qt::DisplayRole);
  item_data_role.addValue("DecorationRole", Qt::DecorationRole);
  item_data_role.addValue("EditRole", Qt::EditRole);
  item_data_role.addValue("ToolTipRole", Qt::ToolTipRole);
  item_data_role.addValue("StatusTipRole", Qt::StatusTipRole);
  item_data_role.addValue("WhatsThisRole", Qt::WhatsThisRole);
  item_data_role.addValue("FontRole", Qt::FontRole);
  item_data_role.addValue("TextAlignmentRole", Qt::TextAlignmentRole);
  item_data_role.addValue("BackgroundColorRole", Qt::BackgroundColorRole);
  item_data_role.addValue("BackgroundRole", Qt::BackgroundRole);
  item_data_role.addValue("TextColorRole", Qt::TextColorRole);
  item_data_role.addValue("ForegroundRole", Qt::ForegroundRole);
  item_data_role.addValue("CheckStateRole", Qt::CheckStateRole);
  item_data_role.addValue("AccessibleTextRole", Qt::AccessibleTextRole);
  item_data_role.addValue("AccessibleDescriptionRole", Qt::AccessibleDescriptionRole);
  item_data_role.addValue("SizeHintRole", Qt::SizeHintRole);
  item_data_role.addValue("InitialSortOrderRole", Qt::InitialSortOrderRole);
  item_data_role.addValue("DisplayPropertyRole", Qt::DisplayPropertyRole);
  item_data_role.addValue("DecorationPropertyRole", Qt::DecorationPropertyRole);
  item_data_role.addValue("ToolTipPropertyRole", Qt::ToolTipPropertyRole);
  item_data_role.addValue("StatusTipPropertyRole", Qt::StatusTipPropertyRole);
  item_data_role.addValue("WhatsThisPropertyRole", Qt::WhatsThisPropertyRole);
  item_data_role.addValue("UserRole", Qt::UserRole);
}


static void register_qt_item_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum item_flag = qt.Enum("ItemFlag").setId(script::Type::QtItemFlag)
    .setEnumClass().get();

  item_flag.addValue("NoItemFlags", Qt::NoItemFlags);
  item_flag.addValue("ItemIsSelectable", Qt::ItemIsSelectable);
  item_flag.addValue("ItemIsEditable", Qt::ItemIsEditable);
  item_flag.addValue("ItemIsDragEnabled", Qt::ItemIsDragEnabled);
  item_flag.addValue("ItemIsDropEnabled", Qt::ItemIsDropEnabled);
  item_flag.addValue("ItemIsUserCheckable", Qt::ItemIsUserCheckable);
  item_flag.addValue("ItemIsEnabled", Qt::ItemIsEnabled);
  item_flag.addValue("ItemIsAutoTristate", Qt::ItemIsAutoTristate);
  item_flag.addValue("ItemIsTristate", Qt::ItemIsTristate);
  item_flag.addValue("ItemNeverHasChildren", Qt::ItemNeverHasChildren);
  item_flag.addValue("ItemIsUserTristate", Qt::ItemIsUserTristate);
}


static void register_qt_match_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum match_flag = qt.Enum("MatchFlag").setId(script::Type::QtMatchFlag)
    .setEnumClass().get();

  match_flag.addValue("MatchExactly", Qt::MatchExactly);
  match_flag.addValue("MatchContains", Qt::MatchContains);
  match_flag.addValue("MatchStartsWith", Qt::MatchStartsWith);
  match_flag.addValue("MatchEndsWith", Qt::MatchEndsWith);
  match_flag.addValue("MatchRegExp", Qt::MatchRegExp);
  match_flag.addValue("MatchWildcard", Qt::MatchWildcard);
  match_flag.addValue("MatchFixedString", Qt::MatchFixedString);
  match_flag.addValue("MatchCaseSensitive", Qt::MatchCaseSensitive);
  match_flag.addValue("MatchWrap", Qt::MatchWrap);
  match_flag.addValue("MatchRecursive", Qt::MatchRecursive);
}


static void register_qt_window_modality_enum(script::Namespace qt)
{
  using namespace script;

  Enum window_modality = qt.Enum("WindowModality").setId(script::Type::QtWindowModality)
    .setEnumClass().get();

  window_modality.addValue("NonModal", Qt::NonModal);
  window_modality.addValue("WindowModal", Qt::WindowModal);
  window_modality.addValue("ApplicationModal", Qt::ApplicationModal);
}


static void register_qt_text_interaction_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum text_interaction_flag = qt.Enum("TextInteractionFlag").setId(script::Type::QtTextInteractionFlag)
    .setEnumClass().get();

  text_interaction_flag.addValue("NoTextInteraction", Qt::NoTextInteraction);
  text_interaction_flag.addValue("TextSelectableByMouse", Qt::TextSelectableByMouse);
  text_interaction_flag.addValue("TextSelectableByKeyboard", Qt::TextSelectableByKeyboard);
  text_interaction_flag.addValue("LinksAccessibleByMouse", Qt::LinksAccessibleByMouse);
  text_interaction_flag.addValue("LinksAccessibleByKeyboard", Qt::LinksAccessibleByKeyboard);
  text_interaction_flag.addValue("TextEditable", Qt::TextEditable);
  text_interaction_flag.addValue("TextEditorInteraction", Qt::TextEditorInteraction);
  text_interaction_flag.addValue("TextBrowserInteraction", Qt::TextBrowserInteraction);
}


static void register_qt_event_priority_enum(script::Namespace qt)
{
  using namespace script;

  Enum event_priority = qt.Enum("EventPriority").setId(script::Type::QtEventPriority)
    .setEnumClass().get();

  event_priority.addValue("HighEventPriority", Qt::HighEventPriority);
  event_priority.addValue("NormalEventPriority", Qt::NormalEventPriority);
  event_priority.addValue("LowEventPriority", Qt::LowEventPriority);
}


static void register_qt_size_hint_enum(script::Namespace qt)
{
  using namespace script;

  Enum size_hint = qt.Enum("SizeHint").setId(script::Type::QtSizeHint)
    .setEnumClass().get();

  size_hint.addValue("MinimumSize", Qt::MinimumSize);
  size_hint.addValue("PreferredSize", Qt::PreferredSize);
  size_hint.addValue("MaximumSize", Qt::MaximumSize);
  size_hint.addValue("MinimumDescent", Qt::MinimumDescent);
  size_hint.addValue("NSizeHints", Qt::NSizeHints);
}


static void register_qt_window_frame_section_enum(script::Namespace qt)
{
  using namespace script;

  Enum window_frame_section = qt.Enum("WindowFrameSection").setId(script::Type::QtWindowFrameSection)
    .setEnumClass().get();

  window_frame_section.addValue("NoSection", Qt::NoSection);
  window_frame_section.addValue("LeftSection", Qt::LeftSection);
  window_frame_section.addValue("TopLeftSection", Qt::TopLeftSection);
  window_frame_section.addValue("TopSection", Qt::TopSection);
  window_frame_section.addValue("TopRightSection", Qt::TopRightSection);
  window_frame_section.addValue("RightSection", Qt::RightSection);
  window_frame_section.addValue("BottomRightSection", Qt::BottomRightSection);
  window_frame_section.addValue("BottomSection", Qt::BottomSection);
  window_frame_section.addValue("BottomLeftSection", Qt::BottomLeftSection);
  window_frame_section.addValue("TitleBarArea", Qt::TitleBarArea);
}


static void register_qt_initialization_enum(script::Namespace qt)
{
  using namespace script;

  Enum initialization = qt.Enum("Initialization").setId(script::Type::QtInitialization)
    .setEnumClass().get();

  initialization.addValue("Uninitialized", static_cast<int>(Qt::Uninitialized));
}


static void register_qt_coordinate_system_enum(script::Namespace qt)
{
  using namespace script;

  Enum coordinate_system = qt.Enum("CoordinateSystem").setId(script::Type::QtCoordinateSystem)
    .setEnumClass().get();

  coordinate_system.addValue("DeviceCoordinates", Qt::DeviceCoordinates);
  coordinate_system.addValue("LogicalCoordinates", Qt::LogicalCoordinates);
}


static void register_qt_touch_point_state_enum(script::Namespace qt)
{
  using namespace script;

  Enum touch_point_state = qt.Enum("TouchPointState").setId(script::Type::QtTouchPointState)
    .setEnumClass().get();

  touch_point_state.addValue("TouchPointPressed", Qt::TouchPointPressed);
  touch_point_state.addValue("TouchPointMoved", Qt::TouchPointMoved);
  touch_point_state.addValue("TouchPointStationary", Qt::TouchPointStationary);
  touch_point_state.addValue("TouchPointReleased", Qt::TouchPointReleased);
}


static void register_qt_gesture_state_enum(script::Namespace qt)
{
  using namespace script;

  Enum gesture_state = qt.Enum("GestureState").setId(script::Type::QtGestureState)
    .setEnumClass().get();

  gesture_state.addValue("NoGesture", Qt::NoGesture);
  gesture_state.addValue("GestureStarted", Qt::GestureStarted);
  gesture_state.addValue("GestureUpdated", Qt::GestureUpdated);
  gesture_state.addValue("GestureFinished", Qt::GestureFinished);
  gesture_state.addValue("GestureCanceled", Qt::GestureCanceled);
}


static void register_qt_gesture_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum gesture_type = qt.Enum("GestureType").setId(script::Type::QtGestureType)
    .setEnumClass().get();

  gesture_type.addValue("TapGesture", Qt::TapGesture);
  gesture_type.addValue("TapAndHoldGesture", Qt::TapAndHoldGesture);
  gesture_type.addValue("PanGesture", Qt::PanGesture);
  gesture_type.addValue("PinchGesture", Qt::PinchGesture);
  gesture_type.addValue("SwipeGesture", Qt::SwipeGesture);
  gesture_type.addValue("CustomGesture", Qt::CustomGesture);
  gesture_type.addValue("LastGestureType", Qt::LastGestureType);
}


static void register_qt_gesture_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum gesture_flag = qt.Enum("GestureFlag").setId(script::Type::QtGestureFlag)
    .setEnumClass().get();

  gesture_flag.addValue("DontStartGestureOnChildren", Qt::DontStartGestureOnChildren);
  gesture_flag.addValue("ReceivePartialGestures", Qt::ReceivePartialGestures);
  gesture_flag.addValue("IgnoredGesturesPropagateToParent", Qt::IgnoredGesturesPropagateToParent);
}


static void register_qt_native_gesture_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum native_gesture_type = qt.Enum("NativeGestureType").setId(script::Type::QtNativeGestureType)
    .setEnumClass().get();

  native_gesture_type.addValue("BeginNativeGesture", Qt::BeginNativeGesture);
  native_gesture_type.addValue("EndNativeGesture", Qt::EndNativeGesture);
  native_gesture_type.addValue("PanNativeGesture", Qt::PanNativeGesture);
  native_gesture_type.addValue("ZoomNativeGesture", Qt::ZoomNativeGesture);
  native_gesture_type.addValue("SmartZoomNativeGesture", Qt::SmartZoomNativeGesture);
  native_gesture_type.addValue("RotateNativeGesture", Qt::RotateNativeGesture);
  native_gesture_type.addValue("SwipeNativeGesture", Qt::SwipeNativeGesture);
}


static void register_qt_navigation_mode_enum(script::Namespace qt)
{
  using namespace script;

  Enum navigation_mode = qt.Enum("NavigationMode").setId(script::Type::QtNavigationMode)
    .setEnumClass().get();

  navigation_mode.addValue("NavigationModeNone", Qt::NavigationModeNone);
  navigation_mode.addValue("NavigationModeKeypadTabOrder", Qt::NavigationModeKeypadTabOrder);
  navigation_mode.addValue("NavigationModeKeypadDirectional", Qt::NavigationModeKeypadDirectional);
  navigation_mode.addValue("NavigationModeCursorAuto", Qt::NavigationModeCursorAuto);
  navigation_mode.addValue("NavigationModeCursorForceVisible", Qt::NavigationModeCursorForceVisible);
}


static void register_qt_cursor_move_style_enum(script::Namespace qt)
{
  using namespace script;

  Enum cursor_move_style = qt.Enum("CursorMoveStyle").setId(script::Type::QtCursorMoveStyle)
    .setEnumClass().get();

  cursor_move_style.addValue("LogicalMoveStyle", Qt::LogicalMoveStyle);
  cursor_move_style.addValue("VisualMoveStyle", Qt::VisualMoveStyle);
}


static void register_qt_timer_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum timer_type = qt.Enum("TimerType").setId(script::Type::QtTimerType)
    .setEnumClass().get();

  timer_type.addValue("PreciseTimer", Qt::PreciseTimer);
  timer_type.addValue("CoarseTimer", Qt::CoarseTimer);
  timer_type.addValue("VeryCoarseTimer", Qt::VeryCoarseTimer);
}


static void register_qt_scroll_phase_enum(script::Namespace qt)
{
  using namespace script;

  Enum scroll_phase = qt.Enum("ScrollPhase").setId(script::Type::QtScrollPhase)
    .setEnumClass().get();

  scroll_phase.addValue("NoScrollPhase", Qt::NoScrollPhase);
  scroll_phase.addValue("ScrollBegin", Qt::ScrollBegin);
  scroll_phase.addValue("ScrollUpdate", Qt::ScrollUpdate);
  scroll_phase.addValue("ScrollEnd", Qt::ScrollEnd);
}


static void register_qt_mouse_event_source_enum(script::Namespace qt)
{
  using namespace script;

  Enum mouse_event_source = qt.Enum("MouseEventSource").setId(script::Type::QtMouseEventSource)
    .setEnumClass().get();

  mouse_event_source.addValue("MouseEventNotSynthesized", Qt::MouseEventNotSynthesized);
  mouse_event_source.addValue("MouseEventSynthesizedBySystem", Qt::MouseEventSynthesizedBySystem);
  mouse_event_source.addValue("MouseEventSynthesizedByQt", Qt::MouseEventSynthesizedByQt);
  mouse_event_source.addValue("MouseEventSynthesizedByApplication", Qt::MouseEventSynthesizedByApplication);
}


static void register_qt_mouse_event_flag_enum(script::Namespace qt)
{
  using namespace script;

  Enum mouse_event_flag = qt.Enum("MouseEventFlag").setId(script::Type::QtMouseEventFlag)
    .setEnumClass().get();

  mouse_event_flag.addValue("MouseEventCreatedDoubleClick", Qt::MouseEventCreatedDoubleClick);
  mouse_event_flag.addValue("MouseEventFlagMask", Qt::MouseEventFlagMask);
}


static void register_qt_checksum_type_enum(script::Namespace qt)
{
  using namespace script;

  Enum checksum_type = qt.Enum("ChecksumType").setId(script::Type::QtChecksumType)
    .setEnumClass().get();

  checksum_type.addValue("ChecksumIso3309", Qt::ChecksumIso3309);
  checksum_type.addValue("ChecksumItuV41", Qt::ChecksumItuV41);
}


static void register_qt_namespace(script::Namespace ns)
{
  using namespace script;

  Namespace qt = ns;

  register_qt_global_color_enum(qt);
  register_qt_keyboard_modifier_enum(qt);
  register_qt_modifier_enum(qt);
  register_qt_mouse_button_enum(qt);
  register_qt_orientation_enum(qt);
  register_qt_focus_policy_enum(qt);
  register_qt_tab_focus_behavior_enum(qt);
  register_qt_sort_order_enum(qt);
  register_qt_tile_rule_enum(qt);
  register_qt_alignment_flag_enum(qt);
  register_qt_text_flag_enum(qt);
  register_qt_text_elide_mode_enum(qt);
  register_qt_white_space_mode_enum(qt);
  register_qt_hit_test_accuracy_enum(qt);
  register_qt_window_type_enum(qt);
  register_qt_window_state_enum(qt);
  register_qt_application_state_enum(qt);
  register_qt_screen_orientation_enum(qt);
  register_qt_widget_attribute_enum(qt);
  register_qt_application_attribute_enum(qt);
  register_qt_image_conversion_flag_enum(qt);
  register_qt_b_g_mode_enum(qt);
  register_qt_key_enum(qt);
  register_qt_arrow_type_enum(qt);
  register_qt_pen_style_enum(qt);
  register_qt_pen_cap_style_enum(qt);
  register_qt_pen_join_style_enum(qt);
  register_qt_brush_style_enum(qt);
  register_qt_size_mode_enum(qt);
  register_qt_u_i_effect_enum(qt);
  register_qt_cursor_shape_enum(qt);
  register_qt_text_format_enum(qt);
  register_qt_aspect_ratio_mode_enum(qt);
  register_qt_dock_widget_area_enum(qt);
  register_qt_dock_widget_area_sizes_enum(qt);
  register_qt_tool_bar_area_enum(qt);
  register_qt_tool_bar_area_sizes_enum(qt);
  register_qt_date_format_enum(qt);
  register_qt_time_spec_enum(qt);
  register_qt_day_of_week_enum(qt);
  register_qt_scroll_bar_policy_enum(qt);
  register_qt_case_sensitivity_enum(qt);
  register_qt_corner_enum(qt);
  register_qt_edge_enum(qt);
  register_qt_connection_type_enum(qt);
  register_qt_shortcut_context_enum(qt);
  register_qt_fill_rule_enum(qt);
  register_qt_mask_mode_enum(qt);
  register_qt_clip_operation_enum(qt);
  register_qt_item_selection_mode_enum(qt);
  register_qt_item_selection_operation_enum(qt);
  register_qt_transformation_mode_enum(qt);
  register_qt_axis_enum(qt);
  register_qt_focus_reason_enum(qt);
  register_qt_context_menu_policy_enum(qt);
  register_qt_input_method_query_enum(qt);
  register_qt_input_method_hint_enum(qt);
  register_qt_enter_key_type_enum(qt);
  register_qt_tool_button_style_enum(qt);
  register_qt_layout_direction_enum(qt);
  register_qt_anchor_point_enum(qt);
  register_qt_find_child_option_enum(qt);
  register_qt_drop_action_enum(qt);
  register_qt_check_state_enum(qt);
  register_qt_item_data_role_enum(qt);
  register_qt_item_flag_enum(qt);
  register_qt_match_flag_enum(qt);
  register_qt_window_modality_enum(qt);
  register_qt_text_interaction_flag_enum(qt);
  register_qt_event_priority_enum(qt);
  register_qt_size_hint_enum(qt);
  register_qt_window_frame_section_enum(qt);
  register_qt_initialization_enum(qt);
  register_qt_coordinate_system_enum(qt);
  register_qt_touch_point_state_enum(qt);
  register_qt_gesture_state_enum(qt);
  register_qt_gesture_type_enum(qt);
  register_qt_gesture_flag_enum(qt);
  register_qt_native_gesture_type_enum(qt);
  register_qt_navigation_mode_enum(qt);
  register_qt_cursor_move_style_enum(qt);
  register_qt_timer_type_enum(qt);
  register_qt_scroll_phase_enum(qt);
  register_qt_mouse_event_source_enum(qt);
  register_qt_mouse_event_flag_enum(qt);
  register_qt_checksum_type_enum(qt);
  binding::Namespace binder{ qt };

  // const QMetaObject * qt_getEnumMetaObject(Qt::ScrollBarPolicy);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ScrollBarPolicy);
  // const char * qt_getEnumName(Qt::ScrollBarPolicy);
  /// TODO: const char * qt_getEnumName(Qt::ScrollBarPolicy);
  // const QMetaObject * qt_getEnumMetaObject(Qt::FocusPolicy);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::FocusPolicy);
  // const char * qt_getEnumName(Qt::FocusPolicy);
  /// TODO: const char * qt_getEnumName(Qt::FocusPolicy);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ContextMenuPolicy);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ContextMenuPolicy);
  // const char * qt_getEnumName(Qt::ContextMenuPolicy);
  /// TODO: const char * qt_getEnumName(Qt::ContextMenuPolicy);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ArrowType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ArrowType);
  // const char * qt_getEnumName(Qt::ArrowType);
  /// TODO: const char * qt_getEnumName(Qt::ArrowType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ToolButtonStyle);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ToolButtonStyle);
  // const char * qt_getEnumName(Qt::ToolButtonStyle);
  /// TODO: const char * qt_getEnumName(Qt::ToolButtonStyle);
  // const QMetaObject * qt_getEnumMetaObject(Qt::PenStyle);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::PenStyle);
  // const char * qt_getEnumName(Qt::PenStyle);
  /// TODO: const char * qt_getEnumName(Qt::PenStyle);
  // const QMetaObject * qt_getEnumMetaObject(Qt::PenCapStyle);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::PenCapStyle);
  // const char * qt_getEnumName(Qt::PenCapStyle);
  /// TODO: const char * qt_getEnumName(Qt::PenCapStyle);
  // const QMetaObject * qt_getEnumMetaObject(Qt::PenJoinStyle);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::PenJoinStyle);
  // const char * qt_getEnumName(Qt::PenJoinStyle);
  /// TODO: const char * qt_getEnumName(Qt::PenJoinStyle);
  // const QMetaObject * qt_getEnumMetaObject(Qt::BrushStyle);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::BrushStyle);
  // const char * qt_getEnumName(Qt::BrushStyle);
  /// TODO: const char * qt_getEnumName(Qt::BrushStyle);
  // const QMetaObject * qt_getEnumMetaObject(Qt::FillRule);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::FillRule);
  // const char * qt_getEnumName(Qt::FillRule);
  /// TODO: const char * qt_getEnumName(Qt::FillRule);
  // const QMetaObject * qt_getEnumMetaObject(Qt::MaskMode);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::MaskMode);
  // const char * qt_getEnumName(Qt::MaskMode);
  /// TODO: const char * qt_getEnumName(Qt::MaskMode);
  // const QMetaObject * qt_getEnumMetaObject(Qt::BGMode);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::BGMode);
  // const char * qt_getEnumName(Qt::BGMode);
  /// TODO: const char * qt_getEnumName(Qt::BGMode);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ClipOperation);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ClipOperation);
  // const char * qt_getEnumName(Qt::ClipOperation);
  /// TODO: const char * qt_getEnumName(Qt::ClipOperation);
  // const QMetaObject * qt_getEnumMetaObject(Qt::SizeMode);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::SizeMode);
  // const char * qt_getEnumName(Qt::SizeMode);
  /// TODO: const char * qt_getEnumName(Qt::SizeMode);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Axis);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Axis);
  // const char * qt_getEnumName(Qt::Axis);
  /// TODO: const char * qt_getEnumName(Qt::Axis);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Corner);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Corner);
  // const char * qt_getEnumName(Qt::Corner);
  /// TODO: const char * qt_getEnumName(Qt::Corner);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Edge);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Edge);
  // const char * qt_getEnumName(Qt::Edge);
  /// TODO: const char * qt_getEnumName(Qt::Edge);
  // const QMetaObject * qt_getEnumMetaObject(Qt::LayoutDirection);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::LayoutDirection);
  // const char * qt_getEnumName(Qt::LayoutDirection);
  /// TODO: const char * qt_getEnumName(Qt::LayoutDirection);
  // const QMetaObject * qt_getEnumMetaObject(Qt::SizeHint);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::SizeHint);
  // const char * qt_getEnumName(Qt::SizeHint);
  /// TODO: const char * qt_getEnumName(Qt::SizeHint);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Orientation);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Orientation);
  // const char * qt_getEnumName(Qt::Orientation);
  /// TODO: const char * qt_getEnumName(Qt::Orientation);
  // const QMetaObject * qt_getEnumMetaObject(Qt::DropAction);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::DropAction);
  // const char * qt_getEnumName(Qt::DropAction);
  /// TODO: const char * qt_getEnumName(Qt::DropAction);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Alignment);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Alignment);
  // const char * qt_getEnumName(Qt::Alignment);
  /// TODO: const char * qt_getEnumName(Qt::Alignment);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TextFlag);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TextFlag);
  // const char * qt_getEnumName(Qt::TextFlag);
  /// TODO: const char * qt_getEnumName(Qt::TextFlag);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Orientations);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Orientations);
  // const char * qt_getEnumName(Qt::Orientations);
  /// TODO: const char * qt_getEnumName(Qt::Orientations);
  // const QMetaObject * qt_getEnumMetaObject(Qt::DropActions);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::DropActions);
  // const char * qt_getEnumName(Qt::DropActions);
  /// TODO: const char * qt_getEnumName(Qt::DropActions);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Edges);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Edges);
  // const char * qt_getEnumName(Qt::Edges);
  /// TODO: const char * qt_getEnumName(Qt::Edges);
  // const QMetaObject * qt_getEnumMetaObject(Qt::DockWidgetAreas);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::DockWidgetAreas);
  // const char * qt_getEnumName(Qt::DockWidgetAreas);
  /// TODO: const char * qt_getEnumName(Qt::DockWidgetAreas);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ToolBarAreas);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ToolBarAreas);
  // const char * qt_getEnumName(Qt::ToolBarAreas);
  /// TODO: const char * qt_getEnumName(Qt::ToolBarAreas);
  // const QMetaObject * qt_getEnumMetaObject(Qt::DockWidgetArea);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::DockWidgetArea);
  // const char * qt_getEnumName(Qt::DockWidgetArea);
  /// TODO: const char * qt_getEnumName(Qt::DockWidgetArea);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ToolBarArea);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ToolBarArea);
  // const char * qt_getEnumName(Qt::ToolBarArea);
  /// TODO: const char * qt_getEnumName(Qt::ToolBarArea);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TextFormat);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TextFormat);
  // const char * qt_getEnumName(Qt::TextFormat);
  /// TODO: const char * qt_getEnumName(Qt::TextFormat);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TextElideMode);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TextElideMode);
  // const char * qt_getEnumName(Qt::TextElideMode);
  /// TODO: const char * qt_getEnumName(Qt::TextElideMode);
  // const QMetaObject * qt_getEnumMetaObject(Qt::DateFormat);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::DateFormat);
  // const char * qt_getEnumName(Qt::DateFormat);
  /// TODO: const char * qt_getEnumName(Qt::DateFormat);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TimeSpec);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TimeSpec);
  // const char * qt_getEnumName(Qt::TimeSpec);
  /// TODO: const char * qt_getEnumName(Qt::TimeSpec);
  // const QMetaObject * qt_getEnumMetaObject(Qt::DayOfWeek);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::DayOfWeek);
  // const char * qt_getEnumName(Qt::DayOfWeek);
  /// TODO: const char * qt_getEnumName(Qt::DayOfWeek);
  // const QMetaObject * qt_getEnumMetaObject(Qt::CursorShape);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::CursorShape);
  // const char * qt_getEnumName(Qt::CursorShape);
  /// TODO: const char * qt_getEnumName(Qt::CursorShape);
  // const QMetaObject * qt_getEnumMetaObject(Qt::GlobalColor);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::GlobalColor);
  // const char * qt_getEnumName(Qt::GlobalColor);
  /// TODO: const char * qt_getEnumName(Qt::GlobalColor);
  // const QMetaObject * qt_getEnumMetaObject(Qt::AspectRatioMode);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::AspectRatioMode);
  // const char * qt_getEnumName(Qt::AspectRatioMode);
  /// TODO: const char * qt_getEnumName(Qt::AspectRatioMode);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TransformationMode);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TransformationMode);
  // const char * qt_getEnumName(Qt::TransformationMode);
  /// TODO: const char * qt_getEnumName(Qt::TransformationMode);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ImageConversionFlags);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ImageConversionFlags);
  // const char * qt_getEnumName(Qt::ImageConversionFlags);
  /// TODO: const char * qt_getEnumName(Qt::ImageConversionFlags);
  // const QMetaObject * qt_getEnumMetaObject(Qt::Key);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::Key);
  // const char * qt_getEnumName(Qt::Key);
  /// TODO: const char * qt_getEnumName(Qt::Key);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ShortcutContext);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ShortcutContext);
  // const char * qt_getEnumName(Qt::ShortcutContext);
  /// TODO: const char * qt_getEnumName(Qt::ShortcutContext);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TextInteractionFlag);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TextInteractionFlag);
  // const char * qt_getEnumName(Qt::TextInteractionFlag);
  /// TODO: const char * qt_getEnumName(Qt::TextInteractionFlag);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TextInteractionFlags);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TextInteractionFlags);
  // const char * qt_getEnumName(Qt::TextInteractionFlags);
  /// TODO: const char * qt_getEnumName(Qt::TextInteractionFlags);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ItemSelectionMode);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ItemSelectionMode);
  // const char * qt_getEnumName(Qt::ItemSelectionMode);
  /// TODO: const char * qt_getEnumName(Qt::ItemSelectionMode);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ItemSelectionOperation);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ItemSelectionOperation);
  // const char * qt_getEnumName(Qt::ItemSelectionOperation);
  /// TODO: const char * qt_getEnumName(Qt::ItemSelectionOperation);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ItemFlags);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ItemFlags);
  // const char * qt_getEnumName(Qt::ItemFlags);
  /// TODO: const char * qt_getEnumName(Qt::ItemFlags);
  // const QMetaObject * qt_getEnumMetaObject(Qt::CheckState);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::CheckState);
  // const char * qt_getEnumName(Qt::CheckState);
  /// TODO: const char * qt_getEnumName(Qt::CheckState);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ItemDataRole);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ItemDataRole);
  // const char * qt_getEnumName(Qt::ItemDataRole);
  /// TODO: const char * qt_getEnumName(Qt::ItemDataRole);
  // const QMetaObject * qt_getEnumMetaObject(Qt::SortOrder);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::SortOrder);
  // const char * qt_getEnumName(Qt::SortOrder);
  /// TODO: const char * qt_getEnumName(Qt::SortOrder);
  // const QMetaObject * qt_getEnumMetaObject(Qt::CaseSensitivity);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::CaseSensitivity);
  // const char * qt_getEnumName(Qt::CaseSensitivity);
  /// TODO: const char * qt_getEnumName(Qt::CaseSensitivity);
  // const QMetaObject * qt_getEnumMetaObject(Qt::MatchFlags);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::MatchFlags);
  // const char * qt_getEnumName(Qt::MatchFlags);
  /// TODO: const char * qt_getEnumName(Qt::MatchFlags);
  // const QMetaObject * qt_getEnumMetaObject(Qt::KeyboardModifiers);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::KeyboardModifiers);
  // const char * qt_getEnumName(Qt::KeyboardModifiers);
  /// TODO: const char * qt_getEnumName(Qt::KeyboardModifiers);
  // const QMetaObject * qt_getEnumMetaObject(Qt::MouseButtons);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::MouseButtons);
  // const char * qt_getEnumName(Qt::MouseButtons);
  /// TODO: const char * qt_getEnumName(Qt::MouseButtons);
  // const QMetaObject * qt_getEnumMetaObject(Qt::WindowType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::WindowType);
  // const char * qt_getEnumName(Qt::WindowType);
  /// TODO: const char * qt_getEnumName(Qt::WindowType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::WindowState);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::WindowState);
  // const char * qt_getEnumName(Qt::WindowState);
  /// TODO: const char * qt_getEnumName(Qt::WindowState);
  // const QMetaObject * qt_getEnumMetaObject(Qt::WindowModality);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::WindowModality);
  // const char * qt_getEnumName(Qt::WindowModality);
  /// TODO: const char * qt_getEnumName(Qt::WindowModality);
  // const QMetaObject * qt_getEnumMetaObject(Qt::WidgetAttribute);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::WidgetAttribute);
  // const char * qt_getEnumName(Qt::WidgetAttribute);
  /// TODO: const char * qt_getEnumName(Qt::WidgetAttribute);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ApplicationAttribute);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ApplicationAttribute);
  // const char * qt_getEnumName(Qt::ApplicationAttribute);
  /// TODO: const char * qt_getEnumName(Qt::ApplicationAttribute);
  // const QMetaObject * qt_getEnumMetaObject(Qt::WindowFlags);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::WindowFlags);
  // const char * qt_getEnumName(Qt::WindowFlags);
  /// TODO: const char * qt_getEnumName(Qt::WindowFlags);
  // const QMetaObject * qt_getEnumMetaObject(Qt::WindowStates);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::WindowStates);
  // const char * qt_getEnumName(Qt::WindowStates);
  /// TODO: const char * qt_getEnumName(Qt::WindowStates);
  // const QMetaObject * qt_getEnumMetaObject(Qt::FocusReason);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::FocusReason);
  // const char * qt_getEnumName(Qt::FocusReason);
  /// TODO: const char * qt_getEnumName(Qt::FocusReason);
  // const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodHint);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodHint);
  // const char * qt_getEnumName(Qt::InputMethodHint);
  /// TODO: const char * qt_getEnumName(Qt::InputMethodHint);
  // const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodQuery);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodQuery);
  // const char * qt_getEnumName(Qt::InputMethodQuery);
  /// TODO: const char * qt_getEnumName(Qt::InputMethodQuery);
  // const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodHints);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodHints);
  // const char * qt_getEnumName(Qt::InputMethodHints);
  /// TODO: const char * qt_getEnumName(Qt::InputMethodHints);
  // const QMetaObject * qt_getEnumMetaObject(Qt::EnterKeyType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::EnterKeyType);
  // const char * qt_getEnumName(Qt::EnterKeyType);
  /// TODO: const char * qt_getEnumName(Qt::EnterKeyType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodQueries);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::InputMethodQueries);
  // const char * qt_getEnumName(Qt::InputMethodQueries);
  /// TODO: const char * qt_getEnumName(Qt::InputMethodQueries);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TouchPointStates);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TouchPointStates);
  // const char * qt_getEnumName(Qt::TouchPointStates);
  /// TODO: const char * qt_getEnumName(Qt::TouchPointStates);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ScreenOrientation);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ScreenOrientation);
  // const char * qt_getEnumName(Qt::ScreenOrientation);
  /// TODO: const char * qt_getEnumName(Qt::ScreenOrientation);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ScreenOrientations);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ScreenOrientations);
  // const char * qt_getEnumName(Qt::ScreenOrientations);
  /// TODO: const char * qt_getEnumName(Qt::ScreenOrientations);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ConnectionType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ConnectionType);
  // const char * qt_getEnumName(Qt::ConnectionType);
  /// TODO: const char * qt_getEnumName(Qt::ConnectionType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ApplicationState);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ApplicationState);
  // const char * qt_getEnumName(Qt::ApplicationState);
  /// TODO: const char * qt_getEnumName(Qt::ApplicationState);
  // const QMetaObject * qt_getEnumMetaObject(Qt::GestureState);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::GestureState);
  // const char * qt_getEnumName(Qt::GestureState);
  /// TODO: const char * qt_getEnumName(Qt::GestureState);
  // const QMetaObject * qt_getEnumMetaObject(Qt::GestureType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::GestureType);
  // const char * qt_getEnumName(Qt::GestureType);
  /// TODO: const char * qt_getEnumName(Qt::GestureType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::NativeGestureType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::NativeGestureType);
  // const char * qt_getEnumName(Qt::NativeGestureType);
  /// TODO: const char * qt_getEnumName(Qt::NativeGestureType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::CursorMoveStyle);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::CursorMoveStyle);
  // const char * qt_getEnumName(Qt::CursorMoveStyle);
  /// TODO: const char * qt_getEnumName(Qt::CursorMoveStyle);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TimerType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TimerType);
  // const char * qt_getEnumName(Qt::TimerType);
  /// TODO: const char * qt_getEnumName(Qt::TimerType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ScrollPhase);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ScrollPhase);
  // const char * qt_getEnumName(Qt::ScrollPhase);
  /// TODO: const char * qt_getEnumName(Qt::ScrollPhase);
  // const QMetaObject * qt_getEnumMetaObject(Qt::MouseEventSource);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::MouseEventSource);
  // const char * qt_getEnumName(Qt::MouseEventSource);
  /// TODO: const char * qt_getEnumName(Qt::MouseEventSource);
  // const QMetaObject * qt_getEnumMetaObject(Qt::MouseEventFlag);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::MouseEventFlag);
  // const char * qt_getEnumName(Qt::MouseEventFlag);
  /// TODO: const char * qt_getEnumName(Qt::MouseEventFlag);
  // const QMetaObject * qt_getEnumMetaObject(Qt::ChecksumType);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::ChecksumType);
  // const char * qt_getEnumName(Qt::ChecksumType);
  /// TODO: const char * qt_getEnumName(Qt::ChecksumType);
  // const QMetaObject * qt_getEnumMetaObject(Qt::TabFocusBehavior);
  /// TODO: const QMetaObject * qt_getEnumMetaObject(Qt::TabFocusBehavior);
  // const char * qt_getEnumName(Qt::TabFocusBehavior);
  /// TODO: const char * qt_getEnumName(Qt::TabFocusBehavior);
}

void register_enums_file(script::Namespace core)
{
  using namespace script;

  Namespace ns = core;

  register_qt_namespace(ns);
  binding::Namespace binder{ ns };

  // const QMetaObject * qt_getQtMetaObject();
  /// TODO: const QMetaObject * qt_getQtMetaObject();
  // QFlags<Qt::MouseButtons::enum_type> operator|(Qt::MouseButtons::enum_type, Qt::MouseButtons::enum_type);
  /// TODO: QFlags<Qt::MouseButtons::enum_type> operator|(Qt::MouseButtons::enum_type, Qt::MouseButtons::enum_type);
  // QFlags<Qt::MouseButtons::enum_type> operator|(Qt::MouseButtons::enum_type, QFlags<Qt::MouseButtons::enum_type>);
  /// TODO: QFlags<Qt::MouseButtons::enum_type> operator|(Qt::MouseButtons::enum_type, QFlags<Qt::MouseButtons::enum_type>);
  // QIncompatibleFlag operator|(Qt::MouseButtons::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::MouseButtons::enum_type, int);
  // QFlags<Qt::Orientations::enum_type> operator|(Qt::Orientations::enum_type, Qt::Orientations::enum_type);
  /// TODO: QFlags<Qt::Orientations::enum_type> operator|(Qt::Orientations::enum_type, Qt::Orientations::enum_type);
  // QFlags<Qt::Orientations::enum_type> operator|(Qt::Orientations::enum_type, QFlags<Qt::Orientations::enum_type>);
  /// TODO: QFlags<Qt::Orientations::enum_type> operator|(Qt::Orientations::enum_type, QFlags<Qt::Orientations::enum_type>);
  // QIncompatibleFlag operator|(Qt::Orientations::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::Orientations::enum_type, int);
  // QFlags<Qt::KeyboardModifiers::enum_type> operator|(Qt::KeyboardModifiers::enum_type, Qt::KeyboardModifiers::enum_type);
  /// TODO: QFlags<Qt::KeyboardModifiers::enum_type> operator|(Qt::KeyboardModifiers::enum_type, Qt::KeyboardModifiers::enum_type);
  // QFlags<Qt::KeyboardModifiers::enum_type> operator|(Qt::KeyboardModifiers::enum_type, QFlags<Qt::KeyboardModifiers::enum_type>);
  /// TODO: QFlags<Qt::KeyboardModifiers::enum_type> operator|(Qt::KeyboardModifiers::enum_type, QFlags<Qt::KeyboardModifiers::enum_type>);
  // QIncompatibleFlag operator|(Qt::KeyboardModifiers::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::KeyboardModifiers::enum_type, int);
  // QFlags<Qt::WindowFlags::enum_type> operator|(Qt::WindowFlags::enum_type, Qt::WindowFlags::enum_type);
  /// TODO: QFlags<Qt::WindowFlags::enum_type> operator|(Qt::WindowFlags::enum_type, Qt::WindowFlags::enum_type);
  // QFlags<Qt::WindowFlags::enum_type> operator|(Qt::WindowFlags::enum_type, QFlags<Qt::WindowFlags::enum_type>);
  /// TODO: QFlags<Qt::WindowFlags::enum_type> operator|(Qt::WindowFlags::enum_type, QFlags<Qt::WindowFlags::enum_type>);
  // QIncompatibleFlag operator|(Qt::WindowFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::WindowFlags::enum_type, int);
  // QFlags<Qt::Alignment::enum_type> operator|(Qt::Alignment::enum_type, Qt::Alignment::enum_type);
  /// TODO: QFlags<Qt::Alignment::enum_type> operator|(Qt::Alignment::enum_type, Qt::Alignment::enum_type);
  // QFlags<Qt::Alignment::enum_type> operator|(Qt::Alignment::enum_type, QFlags<Qt::Alignment::enum_type>);
  /// TODO: QFlags<Qt::Alignment::enum_type> operator|(Qt::Alignment::enum_type, QFlags<Qt::Alignment::enum_type>);
  // QIncompatibleFlag operator|(Qt::Alignment::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::Alignment::enum_type, int);
  // QFlags<Qt::Edges::enum_type> operator|(Qt::Edges::enum_type, Qt::Edges::enum_type);
  /// TODO: QFlags<Qt::Edges::enum_type> operator|(Qt::Edges::enum_type, Qt::Edges::enum_type);
  // QFlags<Qt::Edges::enum_type> operator|(Qt::Edges::enum_type, QFlags<Qt::Edges::enum_type>);
  /// TODO: QFlags<Qt::Edges::enum_type> operator|(Qt::Edges::enum_type, QFlags<Qt::Edges::enum_type>);
  // QIncompatibleFlag operator|(Qt::Edges::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::Edges::enum_type, int);
  // QFlags<Qt::ImageConversionFlags::enum_type> operator|(Qt::ImageConversionFlags::enum_type, Qt::ImageConversionFlags::enum_type);
  /// TODO: QFlags<Qt::ImageConversionFlags::enum_type> operator|(Qt::ImageConversionFlags::enum_type, Qt::ImageConversionFlags::enum_type);
  // QFlags<Qt::ImageConversionFlags::enum_type> operator|(Qt::ImageConversionFlags::enum_type, QFlags<Qt::ImageConversionFlags::enum_type>);
  /// TODO: QFlags<Qt::ImageConversionFlags::enum_type> operator|(Qt::ImageConversionFlags::enum_type, QFlags<Qt::ImageConversionFlags::enum_type>);
  // QIncompatibleFlag operator|(Qt::ImageConversionFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::ImageConversionFlags::enum_type, int);
  // QFlags<Qt::DockWidgetAreas::enum_type> operator|(Qt::DockWidgetAreas::enum_type, Qt::DockWidgetAreas::enum_type);
  /// TODO: QFlags<Qt::DockWidgetAreas::enum_type> operator|(Qt::DockWidgetAreas::enum_type, Qt::DockWidgetAreas::enum_type);
  // QFlags<Qt::DockWidgetAreas::enum_type> operator|(Qt::DockWidgetAreas::enum_type, QFlags<Qt::DockWidgetAreas::enum_type>);
  /// TODO: QFlags<Qt::DockWidgetAreas::enum_type> operator|(Qt::DockWidgetAreas::enum_type, QFlags<Qt::DockWidgetAreas::enum_type>);
  // QIncompatibleFlag operator|(Qt::DockWidgetAreas::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::DockWidgetAreas::enum_type, int);
  // QFlags<Qt::ToolBarAreas::enum_type> operator|(Qt::ToolBarAreas::enum_type, Qt::ToolBarAreas::enum_type);
  /// TODO: QFlags<Qt::ToolBarAreas::enum_type> operator|(Qt::ToolBarAreas::enum_type, Qt::ToolBarAreas::enum_type);
  // QFlags<Qt::ToolBarAreas::enum_type> operator|(Qt::ToolBarAreas::enum_type, QFlags<Qt::ToolBarAreas::enum_type>);
  /// TODO: QFlags<Qt::ToolBarAreas::enum_type> operator|(Qt::ToolBarAreas::enum_type, QFlags<Qt::ToolBarAreas::enum_type>);
  // QIncompatibleFlag operator|(Qt::ToolBarAreas::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::ToolBarAreas::enum_type, int);
  // QFlags<Qt::WindowStates::enum_type> operator|(Qt::WindowStates::enum_type, Qt::WindowStates::enum_type);
  /// TODO: QFlags<Qt::WindowStates::enum_type> operator|(Qt::WindowStates::enum_type, Qt::WindowStates::enum_type);
  // QFlags<Qt::WindowStates::enum_type> operator|(Qt::WindowStates::enum_type, QFlags<Qt::WindowStates::enum_type>);
  /// TODO: QFlags<Qt::WindowStates::enum_type> operator|(Qt::WindowStates::enum_type, QFlags<Qt::WindowStates::enum_type>);
  // QIncompatibleFlag operator|(Qt::WindowStates::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::WindowStates::enum_type, int);
  // QFlags<Qt::ScreenOrientations::enum_type> operator|(Qt::ScreenOrientations::enum_type, Qt::ScreenOrientations::enum_type);
  /// TODO: QFlags<Qt::ScreenOrientations::enum_type> operator|(Qt::ScreenOrientations::enum_type, Qt::ScreenOrientations::enum_type);
  // QFlags<Qt::ScreenOrientations::enum_type> operator|(Qt::ScreenOrientations::enum_type, QFlags<Qt::ScreenOrientations::enum_type>);
  /// TODO: QFlags<Qt::ScreenOrientations::enum_type> operator|(Qt::ScreenOrientations::enum_type, QFlags<Qt::ScreenOrientations::enum_type>);
  // QIncompatibleFlag operator|(Qt::ScreenOrientations::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::ScreenOrientations::enum_type, int);
  // QFlags<Qt::DropActions::enum_type> operator|(Qt::DropActions::enum_type, Qt::DropActions::enum_type);
  /// TODO: QFlags<Qt::DropActions::enum_type> operator|(Qt::DropActions::enum_type, Qt::DropActions::enum_type);
  // QFlags<Qt::DropActions::enum_type> operator|(Qt::DropActions::enum_type, QFlags<Qt::DropActions::enum_type>);
  /// TODO: QFlags<Qt::DropActions::enum_type> operator|(Qt::DropActions::enum_type, QFlags<Qt::DropActions::enum_type>);
  // QIncompatibleFlag operator|(Qt::DropActions::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::DropActions::enum_type, int);
  // QFlags<Qt::ItemFlags::enum_type> operator|(Qt::ItemFlags::enum_type, Qt::ItemFlags::enum_type);
  /// TODO: QFlags<Qt::ItemFlags::enum_type> operator|(Qt::ItemFlags::enum_type, Qt::ItemFlags::enum_type);
  // QFlags<Qt::ItemFlags::enum_type> operator|(Qt::ItemFlags::enum_type, QFlags<Qt::ItemFlags::enum_type>);
  /// TODO: QFlags<Qt::ItemFlags::enum_type> operator|(Qt::ItemFlags::enum_type, QFlags<Qt::ItemFlags::enum_type>);
  // QIncompatibleFlag operator|(Qt::ItemFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::ItemFlags::enum_type, int);
  // QFlags<Qt::MatchFlags::enum_type> operator|(Qt::MatchFlags::enum_type, Qt::MatchFlags::enum_type);
  /// TODO: QFlags<Qt::MatchFlags::enum_type> operator|(Qt::MatchFlags::enum_type, Qt::MatchFlags::enum_type);
  // QFlags<Qt::MatchFlags::enum_type> operator|(Qt::MatchFlags::enum_type, QFlags<Qt::MatchFlags::enum_type>);
  /// TODO: QFlags<Qt::MatchFlags::enum_type> operator|(Qt::MatchFlags::enum_type, QFlags<Qt::MatchFlags::enum_type>);
  // QIncompatibleFlag operator|(Qt::MatchFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::MatchFlags::enum_type, int);
  // QFlags<Qt::TextInteractionFlags::enum_type> operator|(Qt::TextInteractionFlags::enum_type, Qt::TextInteractionFlags::enum_type);
  /// TODO: QFlags<Qt::TextInteractionFlags::enum_type> operator|(Qt::TextInteractionFlags::enum_type, Qt::TextInteractionFlags::enum_type);
  // QFlags<Qt::TextInteractionFlags::enum_type> operator|(Qt::TextInteractionFlags::enum_type, QFlags<Qt::TextInteractionFlags::enum_type>);
  /// TODO: QFlags<Qt::TextInteractionFlags::enum_type> operator|(Qt::TextInteractionFlags::enum_type, QFlags<Qt::TextInteractionFlags::enum_type>);
  // QIncompatibleFlag operator|(Qt::TextInteractionFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::TextInteractionFlags::enum_type, int);
  // QFlags<Qt::InputMethodQueries::enum_type> operator|(Qt::InputMethodQueries::enum_type, Qt::InputMethodQueries::enum_type);
  /// TODO: QFlags<Qt::InputMethodQueries::enum_type> operator|(Qt::InputMethodQueries::enum_type, Qt::InputMethodQueries::enum_type);
  // QFlags<Qt::InputMethodQueries::enum_type> operator|(Qt::InputMethodQueries::enum_type, QFlags<Qt::InputMethodQueries::enum_type>);
  /// TODO: QFlags<Qt::InputMethodQueries::enum_type> operator|(Qt::InputMethodQueries::enum_type, QFlags<Qt::InputMethodQueries::enum_type>);
  // QIncompatibleFlag operator|(Qt::InputMethodQueries::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::InputMethodQueries::enum_type, int);
  // QFlags<Qt::InputMethodHints::enum_type> operator|(Qt::InputMethodHints::enum_type, Qt::InputMethodHints::enum_type);
  /// TODO: QFlags<Qt::InputMethodHints::enum_type> operator|(Qt::InputMethodHints::enum_type, Qt::InputMethodHints::enum_type);
  // QFlags<Qt::InputMethodHints::enum_type> operator|(Qt::InputMethodHints::enum_type, QFlags<Qt::InputMethodHints::enum_type>);
  /// TODO: QFlags<Qt::InputMethodHints::enum_type> operator|(Qt::InputMethodHints::enum_type, QFlags<Qt::InputMethodHints::enum_type>);
  // QIncompatibleFlag operator|(Qt::InputMethodHints::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::InputMethodHints::enum_type, int);
  // QFlags<Qt::TouchPointStates::enum_type> operator|(Qt::TouchPointStates::enum_type, Qt::TouchPointStates::enum_type);
  /// TODO: QFlags<Qt::TouchPointStates::enum_type> operator|(Qt::TouchPointStates::enum_type, Qt::TouchPointStates::enum_type);
  // QFlags<Qt::TouchPointStates::enum_type> operator|(Qt::TouchPointStates::enum_type, QFlags<Qt::TouchPointStates::enum_type>);
  /// TODO: QFlags<Qt::TouchPointStates::enum_type> operator|(Qt::TouchPointStates::enum_type, QFlags<Qt::TouchPointStates::enum_type>);
  // QIncompatibleFlag operator|(Qt::TouchPointStates::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::TouchPointStates::enum_type, int);
  // QFlags<Qt::MouseEventFlags::enum_type> operator|(Qt::MouseEventFlags::enum_type, Qt::MouseEventFlags::enum_type);
  /// TODO: QFlags<Qt::MouseEventFlags::enum_type> operator|(Qt::MouseEventFlags::enum_type, Qt::MouseEventFlags::enum_type);
  // QFlags<Qt::MouseEventFlags::enum_type> operator|(Qt::MouseEventFlags::enum_type, QFlags<Qt::MouseEventFlags::enum_type>);
  /// TODO: QFlags<Qt::MouseEventFlags::enum_type> operator|(Qt::MouseEventFlags::enum_type, QFlags<Qt::MouseEventFlags::enum_type>);
  // QIncompatibleFlag operator|(Qt::MouseEventFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::MouseEventFlags::enum_type, int);
  // QFlags<Qt::GestureFlags::enum_type> operator|(Qt::GestureFlags::enum_type, Qt::GestureFlags::enum_type);
  /// TODO: QFlags<Qt::GestureFlags::enum_type> operator|(Qt::GestureFlags::enum_type, Qt::GestureFlags::enum_type);
  // QFlags<Qt::GestureFlags::enum_type> operator|(Qt::GestureFlags::enum_type, QFlags<Qt::GestureFlags::enum_type>);
  /// TODO: QFlags<Qt::GestureFlags::enum_type> operator|(Qt::GestureFlags::enum_type, QFlags<Qt::GestureFlags::enum_type>);
  // QIncompatibleFlag operator|(Qt::GestureFlags::enum_type, int);
  /// TODO: QIncompatibleFlag operator|(Qt::GestureFlags::enum_type, int);
}


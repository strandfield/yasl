// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/enums.h"

#include "yasl/core/flags.h"

#include <script/enum.h>


void register_alignment_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum alignment_flag = n.newEnum("AlignmentFlag", Type::QtAlignmentFlag);

  alignment_flag.addValue("AlignLeft", Qt::AlignLeft);
  alignment_flag.addValue("AlignRight", Qt::AlignRight);
  alignment_flag.addValue("AlignHCenter", Qt::AlignHCenter);
  alignment_flag.addValue("AlignJustify", Qt::AlignJustify);

  alignment_flag.addValue("AlignTop", Qt::AlignTop);
  alignment_flag.addValue("AlignBottom", Qt::AlignBottom);
  alignment_flag.addValue("AlignVCenter", Qt::AlignVCenter);
  alignment_flag.addValue("AlignBaseline", Qt::AlignBaseline);

  alignment_flag.addValue("AlignCenter", Qt::AlignCenter);

  alignment_flag.addValue("AlignAbsolute", Qt::AlignAbsolute);
  alignment_flag.addValue("AlignLeading", Qt::AlignLeading);
  alignment_flag.addValue("AlignTrailing", Qt::AlignTrailing);
}


void register_anchor_point_enum(script::Namespace n)
{
  using namespace script;

  Enum anchor_point = n.newEnum("AnchorPoint", Type::QtAnchorPoint);
  /// TODO !!!
}


void register_application_attribute_enum(script::Namespace n)
{
  using namespace script;

  Enum application_attribute = n.newEnum("ApplicationAttribute", Type::QtApplicationAttribute);

  /// TODO !!!
}


void register_application_state_enum(script::Namespace n)
{
  using namespace script;

  Enum application_state = n.newEnum("ApplicationState", Type::QtApplicationState);
  /// TODO !!!
}


void register_arrow_type_enum(script::Namespace n)
{
  using namespace script;

  Enum arrow_type = n.newEnum("ArrowType", Type::QtArrowType);

  /// TODO !!!
}


void register_aspect_ratio_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum aspect_ratio_mode = n.newEnum("AspectRatioMode", Type::QtAspectRatioMode);

  aspect_ratio_mode.addValue("IgnoreAspectRatio", Qt::IgnoreAspectRatio);
  aspect_ratio_mode.addValue("KeepAspectRatio", Qt::KeepAspectRatio);
  aspect_ratio_mode.addValue("KeepAspectRatioByExpanding", Qt::KeepAspectRatioByExpanding);
}


void register_axis_enum(script::Namespace n)
{
  using namespace script;

  Enum axis = n.newEnum("Axis", Type::QtAxis);

  axis.addValue("XAxis", Qt::XAxis);
  axis.addValue("YAxis", Qt::YAxis);
  axis.addValue("ZAxis", Qt::ZAxis);
}


void register_bgmode_enum(script::Namespace n)
{
  using namespace script;

  Enum bgmode = n.newEnum("BGMode", Type::QtBGMode);

  bgmode.addValue("TransparentMode", Qt::TransparentMode);
  bgmode.addValue("OpaqueMode", Qt::OpaqueMode);
}


void register_brush_style_enum(script::Namespace n)
{
  using namespace script;

  Enum brush_style = n.newEnum("BrushStyle", Type::QtBrushStyle);

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
  brush_style.addValue("BDiagPattern", Qt::BDiagPattern);
  brush_style.addValue("FDiagPattern", Qt::FDiagPattern);
  brush_style.addValue("DiagCrossPattern", Qt::DiagCrossPattern);
  brush_style.addValue("LinearGradientPattern", Qt::LinearGradientPattern);
  brush_style.addValue("RadialGradientPattern", Qt::RadialGradientPattern);
  brush_style.addValue("ConicalGradientPattern", Qt::ConicalGradientPattern);
  brush_style.addValue("TexturePattern", Qt::TexturePattern);
}


void register_case_sensitivity_enum(script::Namespace n)
{
  using namespace script;

  Enum case_sensitivity = n.newEnum("CaseSensitivity", Type::QtCaseSensitivity);

  case_sensitivity.addValue("CaseInsensitive", Qt::CaseInsensitive);
  case_sensitivity.addValue("CaseSensitive", Qt::CaseSensitive);
}


void register_check_state_enum(script::Namespace n)
{
  using namespace script;

  Enum check_state = n.newEnum("CheckState", Type::QtCheckState);

  check_state.addValue("Unchecked", Qt::Unchecked);
  check_state.addValue("PartiallyChecked", Qt::PartiallyChecked);
  check_state.addValue("Checked", Qt::Checked);
}


void register_checksum_type_enum(script::Namespace n)
{
  using namespace script;

  Enum checksum_type = n.newEnum("ChecksumType", Type::QtChecksumType);

  /// TODO !!!
}


void register_clip_operation_enum(script::Namespace n)
{
  using namespace script;

  Enum clip_operation = n.newEnum("ClipOperation", Type::QtClipOperation);

  clip_operation.addValue("NoClip", Qt::NoClip);
  clip_operation.addValue("ReplaceClip", Qt::ReplaceClip);
  clip_operation.addValue("IntersectClip", Qt::IntersectClip);
}


void register_connection_type_enum(script::Namespace n)
{
  using namespace script;

  Enum connection_type = n.newEnum("ConnectionType", Type::QtConnectionType);

  /// TODO !!!
}


void register_context_menu_policy_enum(script::Namespace n)
{
  using namespace script;

  Enum context_menu_policy = n.newEnum("ContextMenuPolicy", Type::QtContextMenuPolicy);

  context_menu_policy.addValue("NoContextMenu", Qt::NoContextMenu);
  context_menu_policy.addValue("PreventContextMenu", Qt::PreventContextMenu);
  context_menu_policy.addValue("DefaultContextMenu", Qt::DefaultContextMenu);
  context_menu_policy.addValue("ActionsContextMenu", Qt::ActionsContextMenu);
  context_menu_policy.addValue("CustomContextMenu", Qt::CustomContextMenu);
}


void register_coordinate_system_enum(script::Namespace n)
{
  using namespace script;

  Enum coordinate_system = n.newEnum("CoordinateSystem", Type::QtCoordinateSystem);

  coordinate_system.addValue("DeviceCoordinates", Qt::DeviceCoordinates);
  coordinate_system.addValue("LogicalCoordinates", Qt::LogicalCoordinates);
}


void register_corner_enum(script::Namespace n)
{
  using namespace script;

  Enum corner = n.newEnum("Corner", Type::QtCorner);

  corner.addValue("TopLeftCorner", Qt::TopLeftCorner);
  corner.addValue("TopRightCorner", Qt::TopRightCorner);
  corner.addValue("BottomLeftCorner", Qt::BottomLeftCorner);
  corner.addValue("BottomRightCorner", Qt::BottomRightCorner);
}


void register_cursor_move_style_enum(script::Namespace n)
{
  using namespace script;

  Enum cursor_move_style = n.newEnum("CursorMoveStyle", Type::QtCursorMoveStyle);

  cursor_move_style.addValue("LogicalMoveStyle", Qt::LogicalMoveStyle);
  cursor_move_style.addValue("VisualMoveStyle", Qt::VisualMoveStyle);
}


void register_cursor_shape_enum(script::Namespace n)
{
  using namespace script;

  Enum cursor_shape = n.newEnum("CursorShape", Type::QtCursorShape);

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
  cursor_shape.addValue("OpenHandCursor", Qt::OpenHandCursor);
  cursor_shape.addValue("ClosedHandCursor", Qt::ClosedHandCursor);
  cursor_shape.addValue("WhatsThisCursor", Qt::WhatsThisCursor);
  cursor_shape.addValue("BusyCursor", Qt::BusyCursor);
  cursor_shape.addValue("DragMoveCursor", Qt::DragMoveCursor);
  cursor_shape.addValue("DragCopyCursor", Qt::DragCopyCursor);
  cursor_shape.addValue("DragLinkCursor", Qt::DragLinkCursor);
  cursor_shape.addValue("BitmapCursor", Qt::BitmapCursor);
}


void register_date_format_enum(script::Namespace n)
{
  using namespace script;

  Enum date_format = n.newEnum("DateFormat", Type::QtDateFormat);

  date_format.addValue("TextDate", Qt::TextDate);
  date_format.addValue("ISODate", Qt::ISODate);
  date_format.addValue("ISODateWithMs", Qt::ISODateWithMs);
  date_format.addValue("SystemLocaleShortDate", Qt::SystemLocaleShortDate);
  date_format.addValue("SystemLocaleLongDate", Qt::SystemLocaleLongDate);
  date_format.addValue("DefaultLocaleShortDate", Qt::DefaultLocaleShortDate);
  date_format.addValue("DefaultLocaleLongDate", Qt::DefaultLocaleLongDate);
  date_format.addValue("SystemLocaleDate", Qt::SystemLocaleDate);
  date_format.addValue("LocaleDate", Qt::LocaleDate);
  date_format.addValue("LocalDate", Qt::LocalDate);
  date_format.addValue("RFC2822Date", Qt::RFC2822Date);
}


void register_day_of_week_enum(script::Namespace n)
{
  using namespace script;

  Enum day_of_week = n.newEnum("DayOfWeek", Type::QtDayOfWeek);

  day_of_week.addValue("Monday", Qt::Monday);
  day_of_week.addValue("Tuesday", Qt::Tuesday);
  day_of_week.addValue("Wednesday", Qt::Wednesday);
  day_of_week.addValue("Thursday", Qt::Thursday);
  day_of_week.addValue("Friday", Qt::Friday);
  day_of_week.addValue("Saturday", Qt::Saturday);
  day_of_week.addValue("Sunday", Qt::Sunday);
}


void register_dock_widget_area_enum(script::Namespace n)
{
  using namespace script;

  Enum dock_widget_area = n.newEnum("DockWidgetArea", Type::QtDockWidgetArea);

  dock_widget_area.addValue("LeftDockWidgetArea", Qt::LeftDockWidgetArea);
  dock_widget_area.addValue("RightDockWidgetArea", Qt::RightDockWidgetArea);
  dock_widget_area.addValue("TopDockWidgetArea", Qt::TopDockWidgetArea);
  dock_widget_area.addValue("BottomDockWidgetArea", Qt::BottomDockWidgetArea);
  dock_widget_area.addValue("AllDockWidgetAreas", Qt::AllDockWidgetAreas);
  dock_widget_area.addValue("NoDockWidgetArea", Qt::NoDockWidgetArea);
}


void register_drop_action_enum(script::Namespace n)
{
  using namespace script;

  Enum drop_action = n.newEnum("DropAction", Type::QtDropAction);

  drop_action.addValue("CopyAction", Qt::CopyAction);
  drop_action.addValue("MoveAction", Qt::MoveAction);
  drop_action.addValue("LinkAction", Qt::LinkAction);
  drop_action.addValue("ActionMask", Qt::ActionMask);
  drop_action.addValue("IgnoreAction", Qt::IgnoreAction);
  drop_action.addValue("TargetMoveAction", Qt::TargetMoveAction);
}


void register_edge_enum(script::Namespace n)
{
  using namespace script;

  Enum edge = n.newEnum("Edge", Type::QtEdge);

  edge.addValue("TopEdge", Qt::TopEdge);
  edge.addValue("LeftEdge", Qt::LeftEdge);
  edge.addValue("RightEdge", Qt::RightEdge);
  edge.addValue("BottomEdge", Qt::BottomEdge);
}


void register_enter_key_type_enum(script::Namespace n)
{
  using namespace script;

  Enum enter_key_type = n.newEnum("EnterKeyType", Type::QtEnterKeyType);

  enter_key_type.addValue("EnterKeyDefault", Qt::EnterKeyDefault);
  enter_key_type.addValue("EnterKeyReturn", Qt::EnterKeyReturn);
  enter_key_type.addValue("EnterKeyDone", Qt::EnterKeyDone);
  enter_key_type.addValue("EnterKeyGo", Qt::EnterKeyGo);
  enter_key_type.addValue("EnterKeySend", Qt::EnterKeySend);
  enter_key_type.addValue("EnterKeySearch", Qt::EnterKeySearch);
  enter_key_type.addValue("EnterKeyNext", Qt::EnterKeyNext);
  enter_key_type.addValue("EnterKeyPrevious", Qt::EnterKeyPrevious);
}


void register_event_priority_enum(script::Namespace n)
{
  using namespace script;

  Enum event_priority = n.newEnum("EventPriority", Type::QtEventPriority);

  event_priority.addValue("HighEventPriority", Qt::HighEventPriority);
  event_priority.addValue("NormalEventPriority", Qt::NormalEventPriority);
  event_priority.addValue("LowEventPriority", Qt::LowEventPriority);
}


void register_fill_rule_enum(script::Namespace n)
{
  using namespace script;

  Enum fill_rule = n.newEnum("FillRule", Type::QtFillRule);

  fill_rule.addValue("OddEvenFill", Qt::OddEvenFill);
  fill_rule.addValue("WindingFill", Qt::WindingFill);
}


void register_find_child_option_enum(script::Namespace n)
{
  using namespace script;

  Enum find_child_option = n.newEnum("FindChildOption", Type::QtFindChildOption);

  find_child_option.addValue("FindDirectChildrenOnly", Qt::FindDirectChildrenOnly);
  find_child_option.addValue("FindChildrenRecursively", Qt::FindChildrenRecursively);
}


void register_focus_policy_enum(script::Namespace n)
{
  using namespace script;

  Enum focus_policy = n.newEnum("FocusPolicy", Type::QtFocusPolicy);

  focus_policy.addValue("TabFocus", Qt::TabFocus);
  focus_policy.addValue("ClickFocus", Qt::ClickFocus);
  focus_policy.addValue("StrongFocus", Qt::StrongFocus);
  focus_policy.addValue("WheelFocus", Qt::WheelFocus);
  focus_policy.addValue("NoFocus", Qt::NoFocus);
}


void register_focus_reason_enum(script::Namespace n)
{
  using namespace script;

  Enum focus_reason = n.newEnum("FocusReason", Type::QtFocusReason);

  focus_reason.addValue("MouseFocusReason", Qt::MouseFocusReason);
  focus_reason.addValue("TabFocusReason", Qt::TabFocusReason);
  focus_reason.addValue("BacktabFocusReason", Qt::BacktabFocusReason);
  focus_reason.addValue("ActiveWindowFocusReason", Qt::ActiveWindowFocusReason);
  focus_reason.addValue("PopupFocusReason", Qt::PopupFocusReason);
  focus_reason.addValue("ShortcutFocusReason", Qt::ShortcutFocusReason);
  focus_reason.addValue("MenuBarFocusReason", Qt::MenuBarFocusReason);
  focus_reason.addValue("OtherFocusReason", Qt::OtherFocusReason);
}


void register_gesture_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum gesture_flag = n.newEnum("GestureFlag", Type::QtGestureFlag);

  gesture_flag.addValue("DontStartGestureOnChildren", Qt::DontStartGestureOnChildren);
  gesture_flag.addValue("ReceivePartialGestures", Qt::ReceivePartialGestures);
  gesture_flag.addValue("IgnoredGesturesPropagateToParent", Qt::IgnoredGesturesPropagateToParent);
}


void register_gesture_state_enum(script::Namespace n)
{
  using namespace script;

  Enum gesture_state = n.newEnum("GestureState", Type::QtGestureState);

  gesture_state.addValue("NoGesture", Qt::NoGesture);
  gesture_state.addValue("GestureStarted", Qt::GestureStarted);
  gesture_state.addValue("GestureUpdated", Qt::GestureUpdated);
  gesture_state.addValue("GestureFinished", Qt::GestureFinished);
  gesture_state.addValue("GestureCanceled", Qt::GestureCanceled);
}


void register_gesture_type_enum(script::Namespace n)
{
  using namespace script;

  Enum gesture_type = n.newEnum("GestureType", Type::QtGestureType);

  gesture_type.addValue("TapGesture", Qt::TapGesture);
  gesture_type.addValue("TapAndHoldGesture", Qt::TapAndHoldGesture);
  gesture_type.addValue("PanGesture", Qt::PanGesture);
  gesture_type.addValue("PinchGesture", Qt::PinchGesture);
  gesture_type.addValue("SwipeGesture", Qt::SwipeGesture);
  gesture_type.addValue("CustomGesture", Qt::CustomGesture);
}


void register_global_color_enum(script::Namespace n)
{
  using namespace script;

  Enum global_color = n.newEnum("GlobalColor", Type::QtGlobalColor);

  global_color.addValue("white", Qt::white);
  global_color.addValue("black", Qt::black);
  global_color.addValue("red", Qt::red);
  global_color.addValue("darkRed", Qt::darkRed);
  global_color.addValue("green", Qt::green);
  global_color.addValue("darkGreen", Qt::darkGreen);
  global_color.addValue("blue", Qt::blue);
  global_color.addValue("darkBlue", Qt::darkBlue);
  global_color.addValue("cyan", Qt::cyan);
  global_color.addValue("darkCyan", Qt::darkCyan);
  global_color.addValue("magenta", Qt::magenta);
  global_color.addValue("darkMagenta", Qt::darkMagenta);
  global_color.addValue("yellow", Qt::yellow);
  global_color.addValue("darkYellow", Qt::darkYellow);
  global_color.addValue("gray", Qt::gray);
  global_color.addValue("darkGray", Qt::darkGray);
  global_color.addValue("lightGray", Qt::lightGray);
  global_color.addValue("transparent", Qt::transparent);
  global_color.addValue("color0", Qt::color0);
  global_color.addValue("color1", Qt::color1);
}


void register_hit_test_accuracy_enum(script::Namespace n)
{
  using namespace script;

  Enum hit_test_accuracy = n.newEnum("HitTestAccuracy", Type::QtHitTestAccuracy);

  hit_test_accuracy.addValue("ExactHit", Qt::ExactHit);
  hit_test_accuracy.addValue("FuzzyHit", Qt::FuzzyHit);
}


void register_image_conversion_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum image_conversion_flag = n.newEnum("ImageConversionFlag", Type::QtImageConversionFlag);

  image_conversion_flag.addValue("AutoColor", Qt::AutoColor);
  image_conversion_flag.addValue("ColorOnly", Qt::ColorOnly);
  image_conversion_flag.addValue("MonoOnly", Qt::MonoOnly);
  image_conversion_flag.addValue("DiffuseDither", Qt::DiffuseDither);
  image_conversion_flag.addValue("OrderedDither", Qt::OrderedDither);
  image_conversion_flag.addValue("ThresholdDither", Qt::ThresholdDither);
  image_conversion_flag.addValue("ThresholdAlphaDither", Qt::ThresholdAlphaDither);
  image_conversion_flag.addValue("OrderedAlphaDither", Qt::OrderedAlphaDither);
  image_conversion_flag.addValue("DiffuseAlphaDither", Qt::DiffuseAlphaDither);
  image_conversion_flag.addValue("PreferDither", Qt::PreferDither);
  image_conversion_flag.addValue("AvoidDither", Qt::AvoidDither);
  image_conversion_flag.addValue("AutoDither", Qt::AutoDither);
  image_conversion_flag.addValue("NoOpaqueDetection", Qt::NoOpaqueDetection);
  image_conversion_flag.addValue("NoFormatConversion", Qt::NoFormatConversion);
}


void register_input_method_hint_enum(script::Namespace n)
{
  using namespace script;

  Enum input_method_hint = n.newEnum("InputMethodHint", Type::QtInputMethodHint);
  /// TODO !!!
}


void register_input_method_query_enum(script::Namespace n)
{
  using namespace script;

  Enum input_method_query = n.newEnum("InputMethodQuery", Type::QtInputMethodQuery);
  /// TODO !!!
}


void register_item_data_role_enum(script::Namespace n)
{
  using namespace script;

  Enum item_data_role = n.newEnum("ItemDataRole", Type::QtItemDataRole);

  /// TODO !!!
}


void register_item_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum item_flag = n.newEnum("ItemFlag", Type::QtItemFlag);

  /// TODO !!!
}


void register_item_selection_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum item_selection_mode = n.newEnum("ItemSelectionMode", Type::QtItemSelectionMode);

  /// TODO !!!
}


void register_item_selection_operation_enum(script::Namespace n)
{
  using namespace script;

  Enum item_selection_operation = n.newEnum("ItemSelectionOperation", Type::QtItemSelectionOperation);

  /// TODO !!!
}


void register_key_enum(script::Namespace n)
{
  using namespace script;

  Enum key = n.newEnum("Key", Type::QtKey);
  /// TODO !!!
}


void register_keyboard_modifier_enum(script::Namespace n)
{
  using namespace script;

  Enum keyboard_modifier = n.newEnum("KeyboardModifier", Type::QtKeyboardModifier);

  keyboard_modifier.addValue("NoModifier", Qt::NoModifier);
  keyboard_modifier.addValue("ShiftModifier", Qt::ShiftModifier);
  keyboard_modifier.addValue("ControlModifier", Qt::ControlModifier);
  keyboard_modifier.addValue("AltModifier", Qt::AltModifier);
  keyboard_modifier.addValue("MetaModifier", Qt::MetaModifier);
  keyboard_modifier.addValue("KeypadModifier", Qt::KeypadModifier);
  keyboard_modifier.addValue("GroupSwitchModifier", Qt::GroupSwitchModifier);

  Class keyboard_modifiers = register_qflags_type<Qt::KeyboardModifier>(n, "KeyboardModifiers", Type::QtKeyboardModifiers);
}


void register_layout_direction_enum(script::Namespace n)
{
  using namespace script;

  Enum layout_direction = n.newEnum("LayoutDirection", Type::QtLayoutDirection);
  /// TODO !!!
}



void register_mask_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum mask_mode = n.newEnum("MaskMode", Type::QtMaskMode);
  /// TODO !!!
}


void register_match_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum match_flag = n.newEnum("MatchFlag", Type::QtMatchFlag);
  /// TODO !!!
}


void register_modifier_enum(script::Namespace n)
{
  using namespace script;

  Enum modifier = n.newEnum("Modifier", Type::QtModifier);
  /// TODO !!!
}


void register_mouse_button_enum(script::Namespace n)
{
  using namespace script;

  Enum mouse_button = n.newEnum("MouseButton", Type::QtMouseButton);
  /// TODO !!!
}


void register_mouse_event_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum mouse_event_flag = n.newEnum("MouseEventFlag", Type::QtMouseEventFlag);
  /// TODO !!!
}


void register_mouse_event_source_enum(script::Namespace n)
{
  using namespace script;

  Enum mouse_event_source = n.newEnum("MouseEventSource", Type::QtMouseEventSource);
  /// TODO !!!
}


void register_native_gesture_type_enum(script::Namespace n)
{
  using namespace script;

  Enum native_gesture_type = n.newEnum("NativeGestureType", Type::QtNativeGestureType);
  /// TODO !!!
}


void register_navigation_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum navigation_mode = n.newEnum("NavigationMode", Type::QtNavigationMode);
  /// TODO !!!
}

void register_orientation_enum(script::Namespace n)
{
  using namespace script;

  Enum orientation = n.newEnum("Orientation", Type::QtOrientation);
  /// TODO !!!
}


void register_pen_cap_style_enum(script::Namespace n)
{
  using namespace script;

  Enum pen_cap_style = n.newEnum("PenCapStyle", Type::QtPenCapStyle);
  /// TODO !!!
}


void register_pen_join_style_enum(script::Namespace n)
{
  using namespace script;

  Enum pen_join_style = n.newEnum("PenJoinStyle", Type::QtPenJoinStyle);
  /// TODO !!!
}


void register_pen_style_enum(script::Namespace n)
{
  using namespace script;

  Enum pen_style = n.newEnum("PenStyle", Type::QtPenStyle);
  /// TODO !!!
}


void register_screen_orientation_enum(script::Namespace n)
{
  using namespace script;

  Enum screen_orientation = n.newEnum("ScreenOrientation", Type::QtScreenOrientation);
  /// TODO !!!
}


void register_scroll_bar_policy_enum(script::Namespace n)
{
  using namespace script;

  Enum scroll_bar_policy = n.newEnum("ScrollBarPolicy", Type::QtScrollBarPolicy);
  /// TODO !!!
}


void register_scroll_phase_enum(script::Namespace n)
{
  using namespace script;

  Enum scroll_phase = n.newEnum("ScrollPhase", Type::QtScrollPhase);
  /// TODO !!!
}


void register_shortcut_context_enum(script::Namespace n)
{
  using namespace script;

  Enum shortcut_context = n.newEnum("ShortcutContext", Type::QtShortcutContext);
  /// TODO !!!
}


void register_size_hint_enum(script::Namespace n)
{
  using namespace script;

  Enum size_hint = n.newEnum("SizeHint", Type::QtSizeHint);
  /// TODO !!!
}


void register_size_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum size_mode = n.newEnum("SizeMode", Type::QtSizeMode);
  /// TODO !!!
}


void register_sort_order_enum(script::Namespace n)
{
  using namespace script;

  Enum sort_order = n.newEnum("SortOrder", Type::QtSortOrder);
  /// TODO !!!
}


void register_tab_focus_behavior_enum(script::Namespace n)
{
  using namespace script;

  Enum tab_focus_behavior = n.newEnum("TabFocusBehavior", Type::QtTabFocusBehavior);
  /// TODO !!!
}


void register_text_elide_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum text_elide_mode = n.newEnum("TextElideMode", Type::QtTextElideMode);
  /// TODO !!!
}


void register_text_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum text_flag = n.newEnum("TextFlag", Type::QtTextFlag);
  /// TODO !!!
}


void register_text_format_enum(script::Namespace n)
{
  using namespace script;

  Enum text_format = n.newEnum("TextFormat", Type::QtTextFormat);
  /// TODO !!!
}


void register_text_interaction_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum text_interaction_flag = n.newEnum("TextInteractionFlag", Type::QtTextInteractionFlag);
  /// TODO !!!
}


void register_tile_rule_enum(script::Namespace n)
{
  using namespace script;

  Enum tile_rule = n.newEnum("TileRule", Type::QtTileRule);
  /// TODO !!!
}


void register_time_spec_enum(script::Namespace n)
{
  using namespace script;

  Enum time_spec = n.newEnum("TimeSpec", Type::QtTimeSpec);
  /// TODO !!!
}


void register_timer_type_enum(script::Namespace n)
{
  using namespace script;

  Enum timer_type = n.newEnum("TimerType", Type::QtTimerType);
  /// TODO !!!
}


void register_tool_bar_area_enum(script::Namespace n)
{
  using namespace script;

  Enum tool_bar_area = n.newEnum("ToolBarArea", Type::QtToolBarArea);
  /// TODO !!!
}


void register_tool_button_style_enum(script::Namespace n)
{
  using namespace script;

  Enum tool_button_style = n.newEnum("ToolButtonStyle", Type::QtToolButtonStyle);
  /// TODO !!!
}


void register_touch_point_state_enum(script::Namespace n)
{
  using namespace script;

  Enum touch_point_state = n.newEnum("TouchPointState", Type::QtTouchPointState);
  /// TODO !!!
}


void register_transformation_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum transformation_mode = n.newEnum("TransformationMode", Type::QtTransformationMode);
  /// TODO !!!
}


void register_ui_effect_enum(script::Namespace n)
{
  using namespace script;

  Enum ui_effect = n.newEnum("UIEffect", Type::QtUIEffect);
  /// TODO !!!
}


void register_white_space_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum white_space_mode = n.newEnum("WhiteSpaceMode", Type::QtWhiteSpaceMode);
  /// TODO !!!
}


void register_widget_attribute_enum(script::Namespace n)
{
  using namespace script;

  Enum widget_attribute = n.newEnum("WidgetAttribute", Type::QtWidgetAttribute);
  /// TODO !!!
}


void register_window_frame_section_enum(script::Namespace n)
{
  using namespace script;

  Enum window_frame_section = n.newEnum("WindowFrameSection", Type::QtWindowFrameSection);
  /// TODO !!!
}


void register_window_modality_enum(script::Namespace n)
{
  using namespace script;

  Enum window_modality = n.newEnum("WindowModality", Type::QtWindowModality);
  /// TODO !!!
}


void register_window_state_enum(script::Namespace n)
{
  using namespace script;

  Enum window_state = n.newEnum("WindowState", Type::QtWindowState);
  /// TODO !!!
}


void register_window_type_enum(script::Namespace n)
{
  using namespace script;

  Enum window_type = n.newEnum("WindowType", Type::QtWindowType);
  /// TODO !!!
}



void register_core_enums(script::Namespace n)
{
  register_alignment_flag_enum(n);
  register_anchor_point_enum(n);
  register_application_attribute_enum(n);
  register_application_state_enum(n);
  register_arrow_type_enum(n);
  register_aspect_ratio_mode_enum(n);
  register_axis_enum(n);
  register_bgmode_enum(n);
  register_brush_style_enum(n);
  register_case_sensitivity_enum(n);
  register_check_state_enum(n);
  register_checksum_type_enum(n);
  register_clip_operation_enum(n);
  register_connection_type_enum(n);
  register_context_menu_policy_enum(n);
  register_coordinate_system_enum(n);
  register_corner_enum(n);
  register_cursor_move_style_enum(n);
  register_cursor_shape_enum(n);
  register_date_format_enum(n);
  register_day_of_week_enum(n);
  register_dock_widget_area_enum(n);
  register_drop_action_enum(n);
  register_edge_enum(n);
  register_enter_key_type_enum(n);
  register_event_priority_enum(n);
  register_fill_rule_enum(n);
  register_find_child_option_enum(n);
  register_focus_policy_enum(n);
  register_focus_reason_enum(n);
  register_gesture_flag_enum(n);
  register_gesture_state_enum(n);
  register_gesture_type_enum(n);
  register_global_color_enum(n);
  register_hit_test_accuracy_enum(n);
  register_image_conversion_flag_enum(n);
  register_input_method_hint_enum(n);
  register_input_method_query_enum(n);
  register_item_data_role_enum(n);
  register_item_flag_enum(n);
  register_item_selection_mode_enum(n);
  register_item_selection_operation_enum(n);
  register_key_enum(n);
  register_keyboard_modifier_enum(n);
  register_layout_direction_enum(n);
  register_mask_mode_enum(n);
  register_match_flag_enum(n);
  register_modifier_enum(n);
  register_mouse_button_enum(n);
  register_mouse_event_flag_enum(n);
  register_mouse_event_source_enum(n);
  register_native_gesture_type_enum(n);
  register_navigation_mode_enum(n);
  register_orientation_enum(n);
  register_pen_cap_style_enum(n);
  register_pen_join_style_enum(n);
  register_pen_style_enum(n);
  register_screen_orientation_enum(n);
  register_scroll_bar_policy_enum(n);
  register_scroll_phase_enum(n);
  register_shortcut_context_enum(n);
  register_size_hint_enum(n);
  register_size_mode_enum(n);
  register_sort_order_enum(n);
  register_tab_focus_behavior_enum(n);
  register_text_elide_mode_enum(n);
  register_text_flag_enum(n);
  register_text_format_enum(n);
  register_text_interaction_flag_enum(n);
  register_tile_rule_enum(n);
  register_time_spec_enum(n);
  register_timer_type_enum(n);
  register_tool_bar_area_enum(n);
  register_tool_button_style_enum(n);
  register_touch_point_state_enum(n);
  register_transformation_mode_enum(n);
  register_ui_effect_enum(n);
  register_white_space_mode_enum(n);
  register_widget_attribute_enum(n);
  register_window_frame_section_enum(n);
  register_window_modality_enum(n);
  register_window_state_enum(n);
  register_window_type_enum(n);
}
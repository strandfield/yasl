// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#include "yasl/core/enums.h"

#include "yasl/core/flags.h"

#include <script/enum.h>

static int alignment_flag_type_id = 0;
static int anchor_point_type_id = 0;
static int application_attribute_type_id = 0;
static int application_state_type_id = 0;
static int arrow_type_type_id = 0;
static int aspect_ratio_mode_type_id = 0;
static int axis_type_id = 0;
static int bgmode_type_id = 0;
static int brush_style_type_id = 0;
static int case_sensitivity_type_id = 0;
static int check_state_type_id = 0;
static int checksum_type_type_id = 0;
static int clip_operation_type_id = 0;
static int connection_type_type_id = 0;
static int context_menu_policy_type_id = 0;
static int coordinate_system_type_id = 0;
static int corner_type_id = 0;
static int cursor_move_style_type_id = 0;
static int cursor_shape_type_id = 0;
static int date_format_type_id = 0;
static int day_of_week_type_id = 0;
static int dock_widget_area_type_id = 0;
static int drop_action_type_id = 0;
static int edge_type_id = 0;
static int enter_key_type_type_id = 0;
static int event_priority_type_id = 0;
static int fill_rule_type_id = 0;
static int find_child_option_type_id = 0;
static int focus_policy_type_id = 0;
static int focus_reason_type_id = 0;
static int gesture_flag_type_id = 0;
static int gesture_state_type_id = 0;
static int gesture_type_type_id = 0;
static int global_color_type_id = 0;
static int hit_test_accuracy_type_id = 0;
static int image_conversion_flag_type_id = 0;
static int input_method_hint_type_id = 0;
static int input_method_query_type_id = 0;
static int item_data_role_type_id = 0;
static int item_flag_type_id = 0;
static int item_selection_mode_type_id = 0;
static int item_selection_operation_type_id = 0;
static int key_type_id = 0;
static int keyboard_modifier_type_id = 0;
static int keyboard_modifiers_type_id = 0;
static int layout_direction_type_id = 0;
static int mask_mode_type_id = 0;
static int match_flag_type_id = 0;
static int modifier_type_id = 0;
static int mouse_button_type_id = 0;
static int mouse_event_flag_type_id = 0;
static int mouse_event_source_type_id = 0;
static int native_gesture_type_type_id = 0;
static int navigation_mode_type_id = 0;
static int orientation_type_id = 0;
static int pen_cap_style_type_id = 0;
static int pen_join_style_type_id = 0;
static int pen_style_type_id = 0;
static int screen_orientation_type_id = 0;
static int scroll_bar_policy_type_id = 0;
static int scroll_phase_type_id = 0;
static int shortcut_context_type_id = 0;
static int size_hint_type_id = 0;
static int size_mode_type_id = 0;
static int sort_order_type_id = 0;
static int tab_focus_behavior_type_id = 0;
static int text_elide_mode_type_id = 0;
static int text_flag_type_id = 0;
static int text_format_type_id = 0;
static int text_interaction_flag_type_id = 0;
static int tile_rule_type_id = 0;
static int time_spec_type_id = 0;
static int timer_type_type_id = 0;
static int tool_bar_area_type_id = 0;
static int tool_button_style_type_id = 0;
static int touch_point_state_type_id = 0;
static int transformation_mode_type_id = 0;
static int ui_effect_type_id = 0;
static int white_space_mode_type_id = 0;
static int widget_attribute_type_id = 0;
static int window_frame_section_type_id = 0;
static int window_modality_type_id = 0;
static int window_state_type_id = 0;
static int window_type_type_id = 0;


void register_alignment_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum alignment_flag = n.newEnum("AlignmentFlag");
  alignment_flag_type_id = alignment_flag.id();

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

script::Type get_alignment_flag_type()
{
  return alignment_flag_type_id;
}


void register_anchor_point_enum(script::Namespace n)
{
  using namespace script;

  Enum anchor_point = n.newEnum("AnchorPoint");
  anchor_point_type_id = anchor_point.id();

  /// TODO !!!
}

script::Type get_anchor_point_type()
{
  return anchor_point_type_id;
}


void register_application_attribute_enum(script::Namespace n)
{
  using namespace script;

  Enum application_attribute = n.newEnum("ApplicationAttribute");
  application_attribute_type_id = application_attribute.id();

  /// TODO !!!
}

script::Type get_application_attribute_type()
{
  return application_attribute_type_id;
}


void register_application_state_enum(script::Namespace n)
{
  using namespace script;

  Enum application_state = n.newEnum("ApplicationState");
  application_state_type_id = application_state.id();

  /// TODO !!!
}

script::Type get_application_state_type()
{
  return application_state_type_id;
}


void register_arrow_type_enum(script::Namespace n)
{
  using namespace script;

  Enum arrow_type = n.newEnum("ArrowType");
  arrow_type_type_id = arrow_type.id();

  /// TODO !!!
}

script::Type get_arrow_type_type()
{
  return arrow_type_type_id;
}


void register_aspect_ratio_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum aspect_ratio_mode = n.newEnum("AspectRatioMode");
  aspect_ratio_mode_type_id = aspect_ratio_mode.id();

  aspect_ratio_mode.addValue("IgnoreAspectRatio", Qt::IgnoreAspectRatio);
  aspect_ratio_mode.addValue("KeepAspectRatio", Qt::KeepAspectRatio);
  aspect_ratio_mode.addValue("KeepAspectRatioByExpanding", Qt::KeepAspectRatioByExpanding);
}

script::Type get_aspect_ratio_mode_type()
{
  return aspect_ratio_mode_type_id;
}


void register_axis_enum(script::Namespace n)
{
  using namespace script;

  Enum axis = n.newEnum("Axis");
  axis_type_id = axis.id();

  axis.addValue("XAxis", Qt::XAxis);
  axis.addValue("YAxis", Qt::YAxis);
  axis.addValue("ZAxis", Qt::ZAxis);
}

script::Type get_axis_type()
{
  return axis_type_id;
}


void register_bgmode_enum(script::Namespace n)
{
  using namespace script;

  Enum bgmode = n.newEnum("BGMode");
  bgmode_type_id = bgmode.id();

  bgmode.addValue("TransparentMode", Qt::TransparentMode);
  bgmode.addValue("OpaqueMode", Qt::OpaqueMode);
}

script::Type get_bgmode_type()
{
  return bgmode_type_id;
}


void register_brush_style_enum(script::Namespace n)
{
  using namespace script;

  Enum brush_style = n.newEnum("BrushStyle");
  brush_style_type_id = brush_style.id();

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

script::Type get_brush_style_type()
{
  return brush_style_type_id;
}


void register_case_sensitivity_enum(script::Namespace n)
{
  using namespace script;

  Enum case_sensitivity = n.newEnum("CaseSensitivity");
  case_sensitivity_type_id = case_sensitivity.id();

  case_sensitivity.addValue("CaseInsensitive", Qt::CaseInsensitive);
  case_sensitivity.addValue("CaseSensitive", Qt::CaseSensitive);
}

script::Type get_case_sensitivity_type()
{
  return case_sensitivity_type_id;
}


void register_check_state_enum(script::Namespace n)
{
  using namespace script;

  Enum check_state = n.newEnum("CheckState");
  check_state_type_id = check_state.id();

  check_state.addValue("Unchecked", Qt::Unchecked);
  check_state.addValue("PartiallyChecked", Qt::PartiallyChecked);
  check_state.addValue("Checked", Qt::Checked);
}

script::Type get_check_state_type()
{
  return check_state_type_id;
}


void register_checksum_type_enum(script::Namespace n)
{
  using namespace script;

  Enum checksum_type = n.newEnum("ChecksumType");
  checksum_type_type_id = checksum_type.id();

  /// TODO !!!
}

script::Type get_checksum_type_type()
{
  return checksum_type_type_id;
}


void register_clip_operation_enum(script::Namespace n)
{
  using namespace script;

  Enum clip_operation = n.newEnum("ClipOperation");
  clip_operation_type_id = clip_operation.id();

  clip_operation.addValue("NoClip", Qt::NoClip);
  clip_operation.addValue("ReplaceClip", Qt::ReplaceClip);
  clip_operation.addValue("IntersectClip", Qt::IntersectClip);
}

script::Type get_clip_operation_type()
{
  return clip_operation_type_id;
}


void register_connection_type_enum(script::Namespace n)
{
  using namespace script;

  Enum connection_type = n.newEnum("ConnectionType");
  connection_type_type_id = connection_type.id();

  /// TODO !!!
}

script::Type get_connection_type_type()
{
  return connection_type_type_id;
}


void register_context_menu_policy_enum(script::Namespace n)
{
  using namespace script;

  Enum context_menu_policy = n.newEnum("ContextMenuPolicy");
  context_menu_policy_type_id = context_menu_policy.id();

  context_menu_policy.addValue("NoContextMenu", Qt::NoContextMenu);
  context_menu_policy.addValue("PreventContextMenu", Qt::PreventContextMenu);
  context_menu_policy.addValue("DefaultContextMenu", Qt::DefaultContextMenu);
  context_menu_policy.addValue("ActionsContextMenu", Qt::ActionsContextMenu);
  context_menu_policy.addValue("CustomContextMenu", Qt::CustomContextMenu);
}

script::Type get_context_menu_policy_type()
{
  return context_menu_policy_type_id;
}


void register_coordinate_system_enum(script::Namespace n)
{
  using namespace script;

  Enum coordinate_system = n.newEnum("CoordinateSystem");
  coordinate_system_type_id = coordinate_system.id();

  coordinate_system.addValue("DeviceCoordinates", Qt::DeviceCoordinates);
  coordinate_system.addValue("LogicalCoordinates", Qt::LogicalCoordinates);
}

script::Type get_coordinate_system_type()
{
  return coordinate_system_type_id;
}


void register_corner_enum(script::Namespace n)
{
  using namespace script;

  Enum corner = n.newEnum("Corner");
  corner_type_id = corner.id();

  corner.addValue("TopLeftCorner", Qt::TopLeftCorner);
  corner.addValue("TopRightCorner", Qt::TopRightCorner);
  corner.addValue("BottomLeftCorner", Qt::BottomLeftCorner);
  corner.addValue("BottomRightCorner", Qt::BottomRightCorner);
}

script::Type get_corner_type()
{
  return corner_type_id;
}


void register_cursor_move_style_enum(script::Namespace n)
{
  using namespace script;

  Enum cursor_move_style = n.newEnum("CursorMoveStyle");
  cursor_move_style_type_id = cursor_move_style.id();

  cursor_move_style.addValue("LogicalMoveStyle", Qt::LogicalMoveStyle);
  cursor_move_style.addValue("VisualMoveStyle", Qt::VisualMoveStyle);
}

script::Type get_cursor_move_style_type()
{
  return cursor_move_style_type_id;
}


void register_cursor_shape_enum(script::Namespace n)
{
  using namespace script;

  Enum cursor_shape = n.newEnum("CursorShape");
  cursor_shape_type_id = cursor_shape.id();

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

script::Type get_cursor_shape_type()
{
  return cursor_shape_type_id;
}


void register_date_format_enum(script::Namespace n)
{
  using namespace script;

  Enum date_format = n.newEnum("DateFormat");
  date_format_type_id = date_format.id();

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

script::Type get_date_format_type()
{
  return date_format_type_id;
}


void register_day_of_week_enum(script::Namespace n)
{
  using namespace script;

  Enum day_of_week = n.newEnum("DayOfWeek");
  day_of_week_type_id = day_of_week.id();

  day_of_week.addValue("Monday", Qt::Monday);
  day_of_week.addValue("Tuesday", Qt::Tuesday);
  day_of_week.addValue("Wednesday", Qt::Wednesday);
  day_of_week.addValue("Thursday", Qt::Thursday);
  day_of_week.addValue("Friday", Qt::Friday);
  day_of_week.addValue("Saturday", Qt::Saturday);
  day_of_week.addValue("Sunday", Qt::Sunday);
}

script::Type get_day_of_week_type()
{
  return day_of_week_type_id;
}


void register_dock_widget_area_enum(script::Namespace n)
{
  using namespace script;

  Enum dock_widget_area = n.newEnum("DockWidgetArea");
  dock_widget_area_type_id = dock_widget_area.id();

  dock_widget_area.addValue("LeftDockWidgetArea", Qt::LeftDockWidgetArea);
  dock_widget_area.addValue("RightDockWidgetArea", Qt::RightDockWidgetArea);
  dock_widget_area.addValue("TopDockWidgetArea", Qt::TopDockWidgetArea);
  dock_widget_area.addValue("BottomDockWidgetArea", Qt::BottomDockWidgetArea);
  dock_widget_area.addValue("AllDockWidgetAreas", Qt::AllDockWidgetAreas);
  dock_widget_area.addValue("NoDockWidgetArea", Qt::NoDockWidgetArea);
}

script::Type get_dock_widget_area_type()
{
  return dock_widget_area_type_id;
}


void register_drop_action_enum(script::Namespace n)
{
  using namespace script;

  Enum drop_action = n.newEnum("DropAction");
  drop_action_type_id = drop_action.id();

  drop_action.addValue("CopyAction", Qt::CopyAction);
  drop_action.addValue("MoveAction", Qt::MoveAction);
  drop_action.addValue("LinkAction", Qt::LinkAction);
  drop_action.addValue("ActionMask", Qt::ActionMask);
  drop_action.addValue("IgnoreAction", Qt::IgnoreAction);
  drop_action.addValue("TargetMoveAction", Qt::TargetMoveAction);
}

script::Type get_drop_action_type()
{
  return drop_action_type_id;
}


void register_edge_enum(script::Namespace n)
{
  using namespace script;

  Enum edge = n.newEnum("Edge");
  edge_type_id = edge.id();

  edge.addValue("TopEdge", Qt::TopEdge);
  edge.addValue("LeftEdge", Qt::LeftEdge);
  edge.addValue("RightEdge", Qt::RightEdge);
  edge.addValue("BottomEdge", Qt::BottomEdge);
}

script::Type get_edge_type()
{
  return edge_type_id;
}


void register_enter_key_type_enum(script::Namespace n)
{
  using namespace script;

  Enum enter_key_type = n.newEnum("EnterKeyType");
  enter_key_type_type_id = enter_key_type.id();

  enter_key_type.addValue("EnterKeyDefault", Qt::EnterKeyDefault);
  enter_key_type.addValue("EnterKeyReturn", Qt::EnterKeyReturn);
  enter_key_type.addValue("EnterKeyDone", Qt::EnterKeyDone);
  enter_key_type.addValue("EnterKeyGo", Qt::EnterKeyGo);
  enter_key_type.addValue("EnterKeySend", Qt::EnterKeySend);
  enter_key_type.addValue("EnterKeySearch", Qt::EnterKeySearch);
  enter_key_type.addValue("EnterKeyNext", Qt::EnterKeyNext);
  enter_key_type.addValue("EnterKeyPrevious", Qt::EnterKeyPrevious);
}

script::Type get_enter_key_type_type()
{
  return enter_key_type_type_id;
}


void register_event_priority_enum(script::Namespace n)
{
  using namespace script;

  Enum event_priority = n.newEnum("EventPriority");
  event_priority_type_id = event_priority.id();

  event_priority.addValue("HighEventPriority", Qt::HighEventPriority);
  event_priority.addValue("NormalEventPriority", Qt::NormalEventPriority);
  event_priority.addValue("LowEventPriority", Qt::LowEventPriority);
}

script::Type get_event_priority_type()
{
  return event_priority_type_id;
}


void register_fill_rule_enum(script::Namespace n)
{
  using namespace script;

  Enum fill_rule = n.newEnum("FillRule");
  fill_rule_type_id = fill_rule.id();

  fill_rule.addValue("OddEvenFill", Qt::OddEvenFill);
  fill_rule.addValue("WindingFill", Qt::WindingFill);
}

script::Type get_fill_rule_type()
{
  return fill_rule_type_id;
}


void register_find_child_option_enum(script::Namespace n)
{
  using namespace script;

  Enum find_child_option = n.newEnum("FindChildOption");
  find_child_option_type_id = find_child_option.id();

  find_child_option.addValue("FindDirectChildrenOnly", Qt::FindDirectChildrenOnly);
  find_child_option.addValue("FindChildrenRecursively", Qt::FindChildrenRecursively);
}

script::Type get_find_child_option_type()
{
  return find_child_option_type_id;
}


void register_focus_policy_enum(script::Namespace n)
{
  using namespace script;

  Enum focus_policy = n.newEnum("FocusPolicy");
  focus_policy_type_id = focus_policy.id();

  focus_policy.addValue("TabFocus", Qt::TabFocus);
  focus_policy.addValue("ClickFocus", Qt::ClickFocus);
  focus_policy.addValue("StrongFocus", Qt::StrongFocus);
  focus_policy.addValue("WheelFocus", Qt::WheelFocus);
  focus_policy.addValue("NoFocus", Qt::NoFocus);
}

script::Type get_focus_policy_type()
{
  return focus_policy_type_id;
}


void register_focus_reason_enum(script::Namespace n)
{
  using namespace script;

  Enum focus_reason = n.newEnum("FocusReason");
  focus_reason_type_id = focus_reason.id();

  focus_reason.addValue("MouseFocusReason", Qt::MouseFocusReason);
  focus_reason.addValue("TabFocusReason", Qt::TabFocusReason);
  focus_reason.addValue("BacktabFocusReason", Qt::BacktabFocusReason);
  focus_reason.addValue("ActiveWindowFocusReason", Qt::ActiveWindowFocusReason);
  focus_reason.addValue("PopupFocusReason", Qt::PopupFocusReason);
  focus_reason.addValue("ShortcutFocusReason", Qt::ShortcutFocusReason);
  focus_reason.addValue("MenuBarFocusReason", Qt::MenuBarFocusReason);
  focus_reason.addValue("OtherFocusReason", Qt::OtherFocusReason);
}

script::Type get_focus_reason_type()
{
  return focus_reason_type_id;
}


void register_gesture_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum gesture_flag = n.newEnum("GestureFlag");
  gesture_flag_type_id = gesture_flag.id();

  gesture_flag.addValue("DontStartGestureOnChildren", Qt::DontStartGestureOnChildren);
  gesture_flag.addValue("ReceivePartialGestures", Qt::ReceivePartialGestures);
  gesture_flag.addValue("IgnoredGesturesPropagateToParent", Qt::IgnoredGesturesPropagateToParent);
}

script::Type get_gesture_flag_type()
{
  return gesture_flag_type_id;
}


void register_gesture_state_enum(script::Namespace n)
{
  using namespace script;

  Enum gesture_state = n.newEnum("GestureState");
  gesture_state_type_id = gesture_state.id();

  gesture_state.addValue("NoGesture", Qt::NoGesture);
  gesture_state.addValue("GestureStarted", Qt::GestureStarted);
  gesture_state.addValue("GestureUpdated", Qt::GestureUpdated);
  gesture_state.addValue("GestureFinished", Qt::GestureFinished);
  gesture_state.addValue("GestureCanceled", Qt::GestureCanceled);
}

script::Type get_gesture_state_type()
{
  return gesture_state_type_id;
}


void register_gesture_type_enum(script::Namespace n)
{
  using namespace script;

  Enum gesture_type = n.newEnum("GestureType");
  gesture_type_type_id = gesture_type.id();

  gesture_type.addValue("TapGesture", Qt::TapGesture);
  gesture_type.addValue("TapAndHoldGesture", Qt::TapAndHoldGesture);
  gesture_type.addValue("PanGesture", Qt::PanGesture);
  gesture_type.addValue("PinchGesture", Qt::PinchGesture);
  gesture_type.addValue("SwipeGesture", Qt::SwipeGesture);
  gesture_type.addValue("CustomGesture", Qt::CustomGesture);
}

script::Type get_gesture_type_type()
{
  return gesture_type_type_id;
}


void register_global_color_enum(script::Namespace n)
{
  using namespace script;

  Enum global_color = n.newEnum("GlobalColor");
  global_color_type_id = global_color.id();

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

script::Type get_global_color_type()
{
  return global_color_type_id;
}


void register_hit_test_accuracy_enum(script::Namespace n)
{
  using namespace script;

  Enum hit_test_accuracy = n.newEnum("HitTestAccuracy");
  hit_test_accuracy_type_id = hit_test_accuracy.id();

  hit_test_accuracy.addValue("ExactHit", Qt::ExactHit);
  hit_test_accuracy.addValue("FuzzyHit", Qt::FuzzyHit);
}

script::Type get_hit_test_accuracy_type()
{
  return hit_test_accuracy_type_id;
}


void register_image_conversion_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum image_conversion_flag = n.newEnum("ImageConversionFlag");
  image_conversion_flag_type_id = image_conversion_flag.id();

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

script::Type get_image_conversion_flag_type()
{
  return image_conversion_flag_type_id;
}


void register_input_method_hint_enum(script::Namespace n)
{
  using namespace script;

  Enum input_method_hint = n.newEnum("InputMethodHint");
  input_method_hint_type_id = input_method_hint.id();

  /// TODO !!!
}

script::Type get_input_method_hint_type()
{
  return input_method_hint_type_id;
}


void register_input_method_query_enum(script::Namespace n)
{
  using namespace script;

  Enum input_method_query = n.newEnum("InputMethodQuery");
  input_method_query_type_id = input_method_query.id();

  /// TODO !!!
}

script::Type get_input_method_query_type()
{
  return input_method_query_type_id;
}


void register_item_data_role_enum(script::Namespace n)
{
  using namespace script;

  Enum item_data_role = n.newEnum("ItemDataRole");
  item_data_role_type_id = item_data_role.id();

  /// TODO !!!
}

script::Type get_item_data_role_type()
{
  return item_data_role_type_id;
}


void register_item_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum item_flag = n.newEnum("ItemFlag");
  item_flag_type_id = item_flag.id();

  /// TODO !!!
}

script::Type get_item_flag_type()
{
  return item_flag_type_id;
}


void register_item_selection_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum item_selection_mode = n.newEnum("ItemSelectionMode");
  item_selection_mode_type_id = item_selection_mode.id();

  /// TODO !!!
}

script::Type get_item_selection_mode_type()
{
  return item_selection_mode_type_id;
}


void register_item_selection_operation_enum(script::Namespace n)
{
  using namespace script;

  Enum item_selection_operation = n.newEnum("ItemSelectionOperation");
  item_selection_operation_type_id = item_selection_operation.id();

  /// TODO !!!
}

script::Type get_item_selection_operation_type()
{
  return item_selection_operation_type_id;
}


void register_key_enum(script::Namespace n)
{
  using namespace script;

  Enum key = n.newEnum("Key");
  key_type_id = key.id();

  /// TODO !!!
}

script::Type get_key_type()
{
  return key_type_id;
}


void register_keyboard_modifier_enum(script::Namespace n)
{
  using namespace script;

  Enum keyboard_modifier = n.newEnum("KeyboardModifier");
  keyboard_modifier_type_id = keyboard_modifier.id();

  keyboard_modifier.addValue("NoModifier", Qt::NoModifier);
  keyboard_modifier.addValue("ShiftModifier", Qt::ShiftModifier);
  keyboard_modifier.addValue("ControlModifier", Qt::ControlModifier);
  keyboard_modifier.addValue("AltModifier", Qt::AltModifier);
  keyboard_modifier.addValue("MetaModifier", Qt::MetaModifier);
  keyboard_modifier.addValue("KeypadModifier", Qt::KeypadModifier);
  keyboard_modifier.addValue("GroupSwitchModifier", Qt::GroupSwitchModifier);

  Class keyboard_modifiers = register_qflags_type<Qt::KeyboardModifier>(n, "KeyboardModifiers");
  keyboard_modifiers_type_id = keyboard_modifiers.id();
}

script::Type get_keyboard_modifier_type()
{
  return keyboard_modifier_type_id;
}

script::Type get_keyboard_modifiers_type()
{
  return keyboard_modifiers_type_id;
}


void register_layout_direction_enum(script::Namespace n)
{
  using namespace script;

  Enum layout_direction = n.newEnum("LayoutDirection");
  layout_direction_type_id = layout_direction.id();

  /// TODO !!!
}

script::Type get_layout_direction_type()
{
  return layout_direction_type_id;
}


void register_mask_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum mask_mode = n.newEnum("MaskMode");
  mask_mode_type_id = mask_mode.id();

  /// TODO !!!
}

script::Type get_mask_mode_type()
{
  return mask_mode_type_id;
}


void register_match_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum match_flag = n.newEnum("MatchFlag");
  match_flag_type_id = match_flag.id();

  /// TODO !!!
}

script::Type get_match_flag_type()
{
  return match_flag_type_id;
}


void register_modifier_enum(script::Namespace n)
{
  using namespace script;

  Enum modifier = n.newEnum("Modifier");
  modifier_type_id = modifier.id();

  /// TODO !!!
}

script::Type get_modifier_type()
{
  return modifier_type_id;
}


void register_mouse_button_enum(script::Namespace n)
{
  using namespace script;

  Enum mouse_button = n.newEnum("MouseButton");
  mouse_button_type_id = mouse_button.id();

  /// TODO !!!
}

script::Type get_mouse_button_type()
{
  return mouse_button_type_id;
}


void register_mouse_event_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum mouse_event_flag = n.newEnum("MouseEventFlag");
  mouse_event_flag_type_id = mouse_event_flag.id();

  /// TODO !!!
}

script::Type get_mouse_event_flag_type()
{
  return mouse_event_flag_type_id;
}


void register_mouse_event_source_enum(script::Namespace n)
{
  using namespace script;

  Enum mouse_event_source = n.newEnum("MouseEventSource");
  mouse_event_source_type_id = mouse_event_source.id();

  /// TODO !!!
}

script::Type get_mouse_event_source_type()
{
  return mouse_event_source_type_id;
}


void register_native_gesture_type_enum(script::Namespace n)
{
  using namespace script;

  Enum native_gesture_type = n.newEnum("NativeGestureType");
  native_gesture_type_type_id = native_gesture_type.id();

  /// TODO !!!
}

script::Type get_native_gesture_type_type()
{
  return native_gesture_type_type_id;
}


void register_navigation_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum navigation_mode = n.newEnum("NavigationMode");
  navigation_mode_type_id = navigation_mode.id();

  /// TODO !!!
}

script::Type get_navigation_mode_type()
{
  return navigation_mode_type_id;
}


void register_orientation_enum(script::Namespace n)
{
  using namespace script;

  Enum orientation = n.newEnum("Orientation");
  orientation_type_id = orientation.id();

  /// TODO !!!
}

script::Type get_orientation_type()
{
  return orientation_type_id;
}


void register_pen_cap_style_enum(script::Namespace n)
{
  using namespace script;

  Enum pen_cap_style = n.newEnum("PenCapStyle");
  pen_cap_style_type_id = pen_cap_style.id();

  /// TODO !!!
}

script::Type get_pen_cap_style_type()
{
  return pen_cap_style_type_id;
}


void register_pen_join_style_enum(script::Namespace n)
{
  using namespace script;

  Enum pen_join_style = n.newEnum("PenJoinStyle");
  pen_join_style_type_id = pen_join_style.id();

  /// TODO !!!
}

script::Type get_pen_join_style_type()
{
  return pen_join_style_type_id;
}


void register_pen_style_enum(script::Namespace n)
{
  using namespace script;

  Enum pen_style = n.newEnum("PenStyle");
  pen_style_type_id = pen_style.id();

  /// TODO !!!
}

script::Type get_pen_style_type()
{
  return pen_style_type_id;
}


void register_screen_orientation_enum(script::Namespace n)
{
  using namespace script;

  Enum screen_orientation = n.newEnum("ScreenOrientation");
  screen_orientation_type_id = screen_orientation.id();

  /// TODO !!!
}

script::Type get_screen_orientation_type()
{
  return screen_orientation_type_id;
}


void register_scroll_bar_policy_enum(script::Namespace n)
{
  using namespace script;

  Enum scroll_bar_policy = n.newEnum("ScrollBarPolicy");
  scroll_bar_policy_type_id = scroll_bar_policy.id();

  /// TODO !!!
}

script::Type get_scroll_bar_policy_type()
{
  return scroll_bar_policy_type_id;
}


void register_scroll_phase_enum(script::Namespace n)
{
  using namespace script;

  Enum scroll_phase = n.newEnum("ScrollPhase");
  scroll_phase_type_id = scroll_phase.id();

  /// TODO !!!
}

script::Type get_scroll_phase_type()
{
  return scroll_phase_type_id;
}


void register_shortcut_context_enum(script::Namespace n)
{
  using namespace script;

  Enum shortcut_context = n.newEnum("ShortcutContext");
  shortcut_context_type_id = shortcut_context.id();

  /// TODO !!!
}

script::Type get_shortcut_context_type()
{
  return shortcut_context_type_id;
}


void register_size_hint_enum(script::Namespace n)
{
  using namespace script;

  Enum size_hint = n.newEnum("SizeHint");
  size_hint_type_id = size_hint.id();

  /// TODO !!!
}

script::Type get_size_hint_type()
{
  return size_hint_type_id;
}


void register_size_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum size_mode = n.newEnum("SizeMode");
  size_mode_type_id = size_mode.id();

  /// TODO !!!
}

script::Type get_size_mode_type()
{
  return size_mode_type_id;
}


void register_sort_order_enum(script::Namespace n)
{
  using namespace script;

  Enum sort_order = n.newEnum("SortOrder");
  sort_order_type_id = sort_order.id();

  /// TODO !!!
}

script::Type get_sort_order_type()
{
  return sort_order_type_id;
}


void register_tab_focus_behavior_enum(script::Namespace n)
{
  using namespace script;

  Enum tab_focus_behavior = n.newEnum("TabFocusBehavior");
  tab_focus_behavior_type_id = tab_focus_behavior.id();

  /// TODO !!!
}

script::Type get_tab_focus_behavior_type()
{
  return tab_focus_behavior_type_id;
}


void register_text_elide_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum text_elide_mode = n.newEnum("TextElideMode");
  text_elide_mode_type_id = text_elide_mode.id();

  /// TODO !!!
}

script::Type get_text_elide_mode_type()
{
  return text_elide_mode_type_id;
}


void register_text_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum text_flag = n.newEnum("TextFlag");
  text_flag_type_id = text_flag.id();

  /// TODO !!!
}

script::Type get_text_flag_type()
{
  return text_flag_type_id;
}


void register_text_format_enum(script::Namespace n)
{
  using namespace script;

  Enum text_format = n.newEnum("TextFormat");
  text_format_type_id = text_format.id();

  /// TODO !!!
}

script::Type get_text_format_type()
{
  return text_format_type_id;
}


void register_text_interaction_flag_enum(script::Namespace n)
{
  using namespace script;

  Enum text_interaction_flag = n.newEnum("TextInteractionFlag");
  text_interaction_flag_type_id = text_interaction_flag.id();

  /// TODO !!!
}

script::Type get_text_interaction_flag_type()
{
  return text_interaction_flag_type_id;
}


void register_tile_rule_enum(script::Namespace n)
{
  using namespace script;

  Enum tile_rule = n.newEnum("TileRule");
  tile_rule_type_id = tile_rule.id();

  /// TODO !!!
}

script::Type get_tile_rule_type()
{
  return tile_rule_type_id;
}


void register_time_spec_enum(script::Namespace n)
{
  using namespace script;

  Enum time_spec = n.newEnum("TimeSpec");
  time_spec_type_id = time_spec.id();

  /// TODO !!!
}

script::Type get_time_spec_type()
{
  return time_spec_type_id;
}


void register_timer_type_enum(script::Namespace n)
{
  using namespace script;

  Enum timer_type = n.newEnum("TimerType");
  timer_type_type_id = timer_type.id();

  /// TODO !!!
}

script::Type get_timer_type_type()
{
  return timer_type_type_id;
}


void register_tool_bar_area_enum(script::Namespace n)
{
  using namespace script;

  Enum tool_bar_area = n.newEnum("ToolBarArea");
  tool_bar_area_type_id = tool_bar_area.id();

  /// TODO !!!
}

script::Type get_tool_bar_area_type()
{
  return tool_bar_area_type_id;
}


void register_tool_button_style_enum(script::Namespace n)
{
  using namespace script;

  Enum tool_button_style = n.newEnum("ToolButtonStyle");
  tool_button_style_type_id = tool_button_style.id();

  /// TODO !!!
}

script::Type get_tool_button_style_type()
{
  return tool_button_style_type_id;
}


void register_touch_point_state_enum(script::Namespace n)
{
  using namespace script;

  Enum touch_point_state = n.newEnum("TouchPointState");
  touch_point_state_type_id = touch_point_state.id();

  /// TODO !!!
}

script::Type get_touch_point_state_type()
{
  return touch_point_state_type_id;
}


void register_transformation_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum transformation_mode = n.newEnum("TransformationMode");
  transformation_mode_type_id = transformation_mode.id();

  /// TODO !!!
}

script::Type get_transformation_mode_type()
{
  return transformation_mode_type_id;
}


void register_ui_effect_enum(script::Namespace n)
{
  using namespace script;

  Enum ui_effect = n.newEnum("UIEffect");
  ui_effect_type_id = ui_effect.id();

  /// TODO !!!
}

script::Type get_ui_effect_type()
{
  return ui_effect_type_id;
}


void register_white_space_mode_enum(script::Namespace n)
{
  using namespace script;

  Enum white_space_mode = n.newEnum("WhiteSpaceMode");
  white_space_mode_type_id = white_space_mode.id();

  /// TODO !!!
}

script::Type get_white_space_mode_type()
{
  return white_space_mode_type_id;
}


void register_widget_attribute_enum(script::Namespace n)
{
  using namespace script;

  Enum widget_attribute = n.newEnum("WidgetAttribute");
  widget_attribute_type_id = widget_attribute.id();

  /// TODO !!!
}

script::Type get_widget_attribute_type()
{
  return widget_attribute_type_id;
}


void register_window_frame_section_enum(script::Namespace n)
{
  using namespace script;

  Enum window_frame_section = n.newEnum("WindowFrameSection");
  window_frame_section_type_id = window_frame_section.id();

  /// TODO !!!
}

script::Type get_window_frame_section_type()
{
  return window_frame_section_type_id;
}


void register_window_modality_enum(script::Namespace n)
{
  using namespace script;

  Enum window_modality = n.newEnum("WindowModality");
  window_modality_type_id = window_modality.id();

  /// TODO !!!
}

script::Type get_window_modality_type()
{
  return window_modality_type_id;
}


void register_window_state_enum(script::Namespace n)
{
  using namespace script;

  Enum window_state = n.newEnum("WindowState");
  window_state_type_id = window_state.id();

  /// TODO !!!
}

script::Type get_window_state_type()
{
  return window_state_type_id;
}


void register_window_type_enum(script::Namespace n)
{
  using namespace script;

  Enum window_type = n.newEnum("WindowType");
  window_type_type_id = window_type.id();

  /// TODO !!!
}

script::Type get_window_type_type()
{
  return window_type_type_id;
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
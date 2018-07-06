// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_ENUMS_H
#define YASL_CORE_ENUMS_H

#include "yasl/binding/utils.h"

#include "yasl/binding/enum.h"

#include <script/namespace.h>

#include <Qt>

script::Type get_alignment_flag_type();
script::Type get_anchor_point_type();
script::Type get_application_attribute_type();
script::Type get_application_state_type();
script::Type get_arrow_type_type();
script::Type get_aspect_ratio_mode_type();
script::Type get_axis_type();
script::Type get_bgmode_type();
script::Type get_brush_style_type();
script::Type get_case_sensitivity_type();
script::Type get_check_state_type();
script::Type get_checksum_type_type();
script::Type get_clip_operation_type();
script::Type get_connection_type_type();
script::Type get_context_menu_policy_type();
script::Type get_coordinate_system_type();
script::Type get_corner_type();
script::Type get_cursor_move_style_type();
script::Type get_cursor_shape_type();
script::Type get_date_format_type();
script::Type get_day_of_week_type();
script::Type get_dock_widget_area_type();
script::Type get_drop_action_type();
script::Type get_edge_type();
script::Type get_enter_key_type_type();
script::Type get_event_priority_type();
script::Type get_fill_rule_type();
script::Type get_find_child_option_type();
script::Type get_focus_policy_type();
script::Type get_focus_reason_type();
script::Type get_gesture_flag_type();
script::Type get_gesture_state_type();
script::Type get_gesture_type_type();
script::Type get_global_color_type();
script::Type get_hit_test_accuracy_type();
script::Type get_image_conversion_flag_type();
script::Type get_input_method_hint_type();
script::Type get_input_method_query_type();
script::Type get_item_data_role_type();
script::Type get_item_flag_type();
script::Type get_item_selection_mode_type();
script::Type get_item_selection_operation_type();
script::Type get_key_type();
script::Type get_keyboard_modifier_type();
script::Type get_keyboard_modifiers_type();
script::Type get_layout_direction_type();
script::Type get_mask_mode_type();
script::Type get_match_flag_type();
script::Type get_modifier_type();
script::Type get_mouse_button_type();
script::Type get_mouse_event_flag_type();
script::Type get_mouse_event_source_type();
script::Type get_native_gesture_type_type();
script::Type get_navigation_mode_type();
script::Type get_orientation_type();
script::Type get_pen_cap_style_type();
script::Type get_pen_join_style_type();
script::Type get_pen_style_type();
script::Type get_screen_orientation_type();
script::Type get_scroll_bar_policy_type();
script::Type get_scroll_phase_type();
script::Type get_shortcut_context_type();
script::Type get_size_hint_type();
script::Type get_size_mode_type();
script::Type get_sort_order_type();
script::Type get_tab_focus_behavior_type();
script::Type get_text_elide_mode_type();
script::Type get_text_flag_type();
script::Type get_text_format_type();
script::Type get_text_interaction_flag_type();
script::Type get_tile_rule_type();
script::Type get_time_spec_type();
script::Type get_timer_type_type();
script::Type get_tool_bar_area_type();
script::Type get_tool_button_style_type();
script::Type get_touch_point_state_type();
script::Type get_transformation_mode_type();
script::Type get_ui_effect_type();
script::Type get_white_space_mode_type();
script::Type get_widget_attribute_type();
script::Type get_window_frame_section_type();
script::Type get_window_modality_type();
script::Type get_window_state_type();
script::Type get_window_type_type();

void register_core_enums(script::Namespace n);

namespace binding
{

template<> struct make_type_t<Qt::AlignmentFlag> { inline static script::Type get() { return get_alignment_flag_type(); } };
template<> struct make_type_t<Qt::AnchorPoint> { inline static script::Type get() { return get_anchor_point_type(); } };
template<> struct make_type_t<Qt::ApplicationAttribute> { inline static script::Type get() { return get_application_attribute_type(); } };
template<> struct make_type_t<Qt::ApplicationState> { inline static script::Type get() { return get_application_state_type(); } };
template<> struct make_type_t<Qt::ArrowType> { inline static script::Type get() { return get_arrow_type_type(); } };
template<> struct make_type_t<Qt::AspectRatioMode> { inline static script::Type get() { return get_aspect_ratio_mode_type(); } };
template<> struct make_type_t<Qt::Axis> { inline static script::Type get() { return get_axis_type(); } };
template<> struct make_type_t<Qt::BGMode> { inline static script::Type get() { return get_bgmode_type(); } };
template<> struct make_type_t<Qt::BrushStyle> { inline static script::Type get() { return get_brush_style_type(); } };
template<> struct make_type_t<Qt::CaseSensitivity> { inline static script::Type get() { return get_case_sensitivity_type(); } };
template<> struct make_type_t<Qt::CheckState> { inline static script::Type get() { return get_check_state_type(); } };
template<> struct make_type_t<Qt::ChecksumType> { inline static script::Type get() { return get_checksum_type_type(); } };
template<> struct make_type_t<Qt::ClipOperation> { inline static script::Type get() { return get_clip_operation_type(); } };
template<> struct make_type_t<Qt::ConnectionType> { inline static script::Type get() { return get_connection_type_type(); } };
template<> struct make_type_t<Qt::ContextMenuPolicy> { inline static script::Type get() { return get_context_menu_policy_type(); } };
template<> struct make_type_t<Qt::CoordinateSystem> { inline static script::Type get() { return get_coordinate_system_type(); } };
template<> struct make_type_t<Qt::Corner> { inline static script::Type get() { return get_corner_type(); } };
template<> struct make_type_t<Qt::CursorMoveStyle> { inline static script::Type get() { return get_cursor_move_style_type(); } };
template<> struct make_type_t<Qt::CursorShape> { inline static script::Type get() { return get_cursor_shape_type(); } };
template<> struct make_type_t<Qt::DateFormat> { inline static script::Type get() { return get_date_format_type(); } };
template<> struct make_type_t<Qt::DayOfWeek> { inline static script::Type get() { return get_day_of_week_type(); } };
template<> struct make_type_t<Qt::DockWidgetArea> { inline static script::Type get() { return get_dock_widget_area_type(); } };
template<> struct make_type_t<Qt::DropAction> { inline static script::Type get() { return get_drop_action_type(); } };
template<> struct make_type_t<Qt::Edge> { inline static script::Type get() { return get_edge_type(); } };
template<> struct make_type_t<Qt::EnterKeyType> { inline static script::Type get() { return get_enter_key_type_type(); } };
template<> struct make_type_t<Qt::EventPriority> { inline static script::Type get() { return get_event_priority_type(); } };
template<> struct make_type_t<Qt::FillRule> { inline static script::Type get() { return get_fill_rule_type(); } };
template<> struct make_type_t<Qt::FindChildOption> { inline static script::Type get() { return get_find_child_option_type(); } };
template<> struct make_type_t<Qt::FocusPolicy> { inline static script::Type get() { return get_focus_policy_type(); } };
template<> struct make_type_t<Qt::FocusReason> { inline static script::Type get() { return get_focus_reason_type(); } };
template<> struct make_type_t<Qt::GestureFlag> { inline static script::Type get() { return get_gesture_flag_type(); } };
template<> struct make_type_t<Qt::GestureState> { inline static script::Type get() { return get_gesture_state_type(); } };
template<> struct make_type_t<Qt::GestureType> { inline static script::Type get() { return get_gesture_type_type(); } };
template<> struct make_type_t<Qt::GlobalColor> { inline static script::Type get() { return get_global_color_type(); } };
template<> struct make_type_t<Qt::HitTestAccuracy> { inline static script::Type get() { return get_hit_test_accuracy_type(); } };
template<> struct make_type_t<Qt::ImageConversionFlag> { inline static script::Type get() { return get_image_conversion_flag_type(); } };
template<> struct make_type_t<Qt::InputMethodHint> { inline static script::Type get() { return get_input_method_hint_type(); } };
template<> struct make_type_t<Qt::InputMethodQuery> { inline static script::Type get() { return get_input_method_query_type(); } };
template<> struct make_type_t<Qt::ItemDataRole> { inline static script::Type get() { return get_item_data_role_type(); } };
template<> struct make_type_t<Qt::ItemFlag> { inline static script::Type get() { return get_item_flag_type(); } };
template<> struct make_type_t<Qt::ItemSelectionMode> { inline static script::Type get() { return get_item_selection_mode_type(); } };
template<> struct make_type_t<Qt::ItemSelectionOperation> { inline static script::Type get() { return get_item_selection_operation_type(); } };
template<> struct make_type_t<Qt::Key> { inline static script::Type get() { return get_key_type(); } };
template<> struct make_type_t<Qt::KeyboardModifier> { inline static script::Type get() { return get_keyboard_modifier_type(); } };
template<> struct make_type_t<Qt::KeyboardModifiers> { inline static script::Type get() { return get_keyboard_modifiers_type(); } };
template<> struct make_type_t<Qt::LayoutDirection> { inline static script::Type get() { return get_layout_direction_type(); } };
template<> struct make_type_t<Qt::MaskMode> { inline static script::Type get() { return get_mask_mode_type(); } };
template<> struct make_type_t<Qt::MatchFlag> { inline static script::Type get() { return get_match_flag_type(); } };
template<> struct make_type_t<Qt::Modifier> { inline static script::Type get() { return get_modifier_type(); } };
template<> struct make_type_t<Qt::MouseButton> { inline static script::Type get() { return get_mouse_button_type(); } };
template<> struct make_type_t<Qt::MouseEventFlag> { inline static script::Type get() { return get_mouse_event_flag_type(); } };
template<> struct make_type_t<Qt::MouseEventSource> { inline static script::Type get() { return get_mouse_event_source_type(); } };
template<> struct make_type_t<Qt::NativeGestureType> { inline static script::Type get() { return get_native_gesture_type_type(); } };
template<> struct make_type_t<Qt::NavigationMode> { inline static script::Type get() { return get_navigation_mode_type(); } };
template<> struct make_type_t<Qt::Orientation> { inline static script::Type get() { return get_orientation_type(); } };
template<> struct make_type_t<Qt::PenCapStyle> { inline static script::Type get() { return get_pen_cap_style_type(); } };
template<> struct make_type_t<Qt::PenJoinStyle> { inline static script::Type get() { return get_pen_join_style_type(); } };
template<> struct make_type_t<Qt::PenStyle> { inline static script::Type get() { return get_pen_style_type(); } };
template<> struct make_type_t<Qt::ScreenOrientation> { inline static script::Type get() { return get_screen_orientation_type(); } };
template<> struct make_type_t<Qt::ScrollBarPolicy> { inline static script::Type get() { return get_scroll_bar_policy_type(); } };
template<> struct make_type_t<Qt::ScrollPhase> { inline static script::Type get() { return get_scroll_phase_type(); } };
template<> struct make_type_t<Qt::ShortcutContext> { inline static script::Type get() { return get_shortcut_context_type(); } };
template<> struct make_type_t<Qt::SizeHint> { inline static script::Type get() { return get_size_hint_type(); } };
template<> struct make_type_t<Qt::SizeMode> { inline static script::Type get() { return get_size_mode_type(); } };
template<> struct make_type_t<Qt::SortOrder> { inline static script::Type get() { return get_sort_order_type(); } };
template<> struct make_type_t<Qt::TabFocusBehavior> { inline static script::Type get() { return get_tab_focus_behavior_type(); } };
template<> struct make_type_t<Qt::TextElideMode> { inline static script::Type get() { return get_text_elide_mode_type(); } };
template<> struct make_type_t<Qt::TextFlag> { inline static script::Type get() { return get_text_flag_type(); } };
template<> struct make_type_t<Qt::TextFormat> { inline static script::Type get() { return get_text_format_type(); } };
template<> struct make_type_t<Qt::TextInteractionFlag> { inline static script::Type get() { return get_text_interaction_flag_type(); } };
template<> struct make_type_t<Qt::TileRule> { inline static script::Type get() { return get_tile_rule_type(); } };
template<> struct make_type_t<Qt::TimeSpec> { inline static script::Type get() { return get_time_spec_type(); } };
template<> struct make_type_t<Qt::TimerType> { inline static script::Type get() { return get_timer_type_type(); } };
template<> struct make_type_t<Qt::ToolBarArea> { inline static script::Type get() { return get_tool_bar_area_type(); } };
template<> struct make_type_t<Qt::ToolButtonStyle> { inline static script::Type get() { return get_tool_button_style_type(); } };
template<> struct make_type_t<Qt::TouchPointState> { inline static script::Type get() { return get_touch_point_state_type(); } };
template<> struct make_type_t<Qt::TransformationMode> { inline static script::Type get() { return get_transformation_mode_type(); } };
template<> struct make_type_t<Qt::UIEffect> { inline static script::Type get() { return get_ui_effect_type(); } };
template<> struct make_type_t<Qt::WhiteSpaceMode> { inline static script::Type get() { return get_white_space_mode_type(); } };
template<> struct make_type_t<Qt::WidgetAttribute> { inline static script::Type get() { return get_widget_attribute_type(); } };
template<> struct make_type_t<Qt::WindowFrameSection> { inline static script::Type get() { return get_window_frame_section_type(); } };
template<> struct make_type_t<Qt::WindowModality> { inline static script::Type get() { return get_window_modality_type(); } };
template<> struct make_type_t<Qt::WindowState> { inline static script::Type get() { return get_window_state_type(); } };
template<> struct make_type_t<Qt::WindowType> { inline static script::Type get() { return get_window_type_type(); } };

} // namespace binding

#endif // YASL_CORE_ENUMS_H

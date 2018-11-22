// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_ENUMS_H
#define YASL_CORE_ENUMS_H

#include "yasl/binding2/types.h"

#include <Qt>

namespace script { namespace bind {
template<> struct make_type_t<Qt::Alignment> { inline static script::Type get() { return script::Type::QtAlignment; } };
template<> struct make_type_t<Qt::AlignmentFlag> { inline static script::Type get() { return script::Type::QtAlignmentFlag; } };
template<> struct make_type_t<Qt::AnchorPoint> { inline static script::Type get() { return script::Type::QtAnchorPoint; } };
template<> struct make_type_t<Qt::ApplicationAttribute> { inline static script::Type get() { return script::Type::QtApplicationAttribute; } };
template<> struct make_type_t<Qt::ApplicationState> { inline static script::Type get() { return script::Type::QtApplicationState; } };
template<> struct make_type_t<Qt::ArrowType> { inline static script::Type get() { return script::Type::QtArrowType; } };
template<> struct make_type_t<Qt::AspectRatioMode> { inline static script::Type get() { return script::Type::QtAspectRatioMode; } };
template<> struct make_type_t<Qt::Axis> { inline static script::Type get() { return script::Type::QtAxis; } };
template<> struct make_type_t<Qt::BGMode> { inline static script::Type get() { return script::Type::QtBGMode; } };
template<> struct make_type_t<Qt::BrushStyle> { inline static script::Type get() { return script::Type::QtBrushStyle; } };
template<> struct make_type_t<Qt::CaseSensitivity> { inline static script::Type get() { return script::Type::QtCaseSensitivity; } };
template<> struct make_type_t<Qt::CheckState> { inline static script::Type get() { return script::Type::QtCheckState; } };
template<> struct make_type_t<Qt::ChecksumType> { inline static script::Type get() { return script::Type::QtChecksumType; } };
template<> struct make_type_t<Qt::ClipOperation> { inline static script::Type get() { return script::Type::QtClipOperation; } };
template<> struct make_type_t<Qt::ConnectionType> { inline static script::Type get() { return script::Type::QtConnectionType; } };
template<> struct make_type_t<Qt::ContextMenuPolicy> { inline static script::Type get() { return script::Type::QtContextMenuPolicy; } };
template<> struct make_type_t<Qt::CoordinateSystem> { inline static script::Type get() { return script::Type::QtCoordinateSystem; } };
template<> struct make_type_t<Qt::Corner> { inline static script::Type get() { return script::Type::QtCorner; } };
template<> struct make_type_t<Qt::CursorMoveStyle> { inline static script::Type get() { return script::Type::QtCursorMoveStyle; } };
template<> struct make_type_t<Qt::CursorShape> { inline static script::Type get() { return script::Type::QtCursorShape; } };
template<> struct make_type_t<Qt::DateFormat> { inline static script::Type get() { return script::Type::QtDateFormat; } };
template<> struct make_type_t<Qt::DayOfWeek> { inline static script::Type get() { return script::Type::QtDayOfWeek; } };
template<> struct make_type_t<Qt::DockWidgetArea> { inline static script::Type get() { return script::Type::QtDockWidgetArea; } };
template<> struct make_type_t<Qt::DockWidgetAreaSizes> { inline static script::Type get() { return script::Type::QtDockWidgetAreaSizes; } };
template<> struct make_type_t<Qt::DropAction> { inline static script::Type get() { return script::Type::QtDropAction; } };
template<> struct make_type_t<Qt::Edge> { inline static script::Type get() { return script::Type::QtEdge; } };
template<> struct make_type_t<Qt::EnterKeyType> { inline static script::Type get() { return script::Type::QtEnterKeyType; } };
template<> struct make_type_t<Qt::EventPriority> { inline static script::Type get() { return script::Type::QtEventPriority; } };
template<> struct make_type_t<Qt::FillRule> { inline static script::Type get() { return script::Type::QtFillRule; } };
template<> struct make_type_t<Qt::FindChildOption> { inline static script::Type get() { return script::Type::QtFindChildOption; } };
template<> struct make_type_t<Qt::FocusPolicy> { inline static script::Type get() { return script::Type::QtFocusPolicy; } };
template<> struct make_type_t<Qt::FocusReason> { inline static script::Type get() { return script::Type::QtFocusReason; } };
template<> struct make_type_t<Qt::GestureFlag> { inline static script::Type get() { return script::Type::QtGestureFlag; } };
template<> struct make_type_t<Qt::GestureState> { inline static script::Type get() { return script::Type::QtGestureState; } };
template<> struct make_type_t<Qt::GestureType> { inline static script::Type get() { return script::Type::QtGestureType; } };
template<> struct make_type_t<Qt::GlobalColor> { inline static script::Type get() { return script::Type::QtGlobalColor; } };
template<> struct make_type_t<Qt::HitTestAccuracy> { inline static script::Type get() { return script::Type::QtHitTestAccuracy; } };
template<> struct make_type_t<Qt::ImageConversionFlag> { inline static script::Type get() { return script::Type::QtImageConversionFlag; } };
template<> struct make_type_t<Qt::ImageConversionFlags> { inline static script::Type get() { return script::Type::QtImageConversionFlags; } };
template<> struct make_type_t<Qt::Initialization> { inline static script::Type get() { return script::Type::QtInitialization; } };
template<> struct make_type_t<Qt::InputMethodHint> { inline static script::Type get() { return script::Type::QtInputMethodHint; } };
template<> struct make_type_t<Qt::InputMethodQuery> { inline static script::Type get() { return script::Type::QtInputMethodQuery; } };
template<> struct make_type_t<Qt::ItemDataRole> { inline static script::Type get() { return script::Type::QtItemDataRole; } };
template<> struct make_type_t<Qt::ItemFlag> { inline static script::Type get() { return script::Type::QtItemFlag; } };
template<> struct make_type_t<Qt::ItemSelectionMode> { inline static script::Type get() { return script::Type::QtItemSelectionMode; } };
template<> struct make_type_t<Qt::ItemSelectionOperation> { inline static script::Type get() { return script::Type::QtItemSelectionOperation; } };
template<> struct make_type_t<Qt::Key> { inline static script::Type get() { return script::Type::QtKey; } };
template<> struct make_type_t<Qt::KeyboardModifier> { inline static script::Type get() { return script::Type::QtKeyboardModifier; } };
template<> struct make_type_t<Qt::KeyboardModifiers> { inline static script::Type get() { return script::Type::QtKeyboardModifiers; } };
template<> struct make_type_t<Qt::LayoutDirection> { inline static script::Type get() { return script::Type::QtLayoutDirection; } };
template<> struct make_type_t<Qt::MaskMode> { inline static script::Type get() { return script::Type::QtMaskMode; } };
template<> struct make_type_t<Qt::MatchFlag> { inline static script::Type get() { return script::Type::QtMatchFlag; } };
template<> struct make_type_t<Qt::Modifier> { inline static script::Type get() { return script::Type::QtModifier; } };
template<> struct make_type_t<Qt::MouseButton> { inline static script::Type get() { return script::Type::QtMouseButton; } };
template<> struct make_type_t<Qt::MouseEventFlag> { inline static script::Type get() { return script::Type::QtMouseEventFlag; } };
template<> struct make_type_t<Qt::MouseEventSource> { inline static script::Type get() { return script::Type::QtMouseEventSource; } };
template<> struct make_type_t<Qt::NativeGestureType> { inline static script::Type get() { return script::Type::QtNativeGestureType; } };
template<> struct make_type_t<Qt::NavigationMode> { inline static script::Type get() { return script::Type::QtNavigationMode; } };
template<> struct make_type_t<Qt::Orientation> { inline static script::Type get() { return script::Type::QtOrientation; } };
template<> struct make_type_t<Qt::PenCapStyle> { inline static script::Type get() { return script::Type::QtPenCapStyle; } };
template<> struct make_type_t<Qt::PenJoinStyle> { inline static script::Type get() { return script::Type::QtPenJoinStyle; } };
template<> struct make_type_t<Qt::PenStyle> { inline static script::Type get() { return script::Type::QtPenStyle; } };
template<> struct make_type_t<Qt::ScreenOrientation> { inline static script::Type get() { return script::Type::QtScreenOrientation; } };
template<> struct make_type_t<Qt::ScrollBarPolicy> { inline static script::Type get() { return script::Type::QtScrollBarPolicy; } };
template<> struct make_type_t<Qt::ScrollPhase> { inline static script::Type get() { return script::Type::QtScrollPhase; } };
template<> struct make_type_t<Qt::ShortcutContext> { inline static script::Type get() { return script::Type::QtShortcutContext; } };
template<> struct make_type_t<Qt::SizeHint> { inline static script::Type get() { return script::Type::QtSizeHint; } };
template<> struct make_type_t<Qt::SizeMode> { inline static script::Type get() { return script::Type::QtSizeMode; } };
template<> struct make_type_t<Qt::SortOrder> { inline static script::Type get() { return script::Type::QtSortOrder; } };
template<> struct make_type_t<Qt::TabFocusBehavior> { inline static script::Type get() { return script::Type::QtTabFocusBehavior; } };
template<> struct make_type_t<Qt::TextElideMode> { inline static script::Type get() { return script::Type::QtTextElideMode; } };
template<> struct make_type_t<Qt::TextFlag> { inline static script::Type get() { return script::Type::QtTextFlag; } };
template<> struct make_type_t<Qt::TextFormat> { inline static script::Type get() { return script::Type::QtTextFormat; } };
template<> struct make_type_t<Qt::TextInteractionFlag> { inline static script::Type get() { return script::Type::QtTextInteractionFlag; } };
template<> struct make_type_t<Qt::TileRule> { inline static script::Type get() { return script::Type::QtTileRule; } };
template<> struct make_type_t<Qt::TimeSpec> { inline static script::Type get() { return script::Type::QtTimeSpec; } };
template<> struct make_type_t<Qt::TimerType> { inline static script::Type get() { return script::Type::QtTimerType; } };
template<> struct make_type_t<Qt::ToolBarArea> { inline static script::Type get() { return script::Type::QtToolBarArea; } };
template<> struct make_type_t<Qt::ToolBarAreaSizes> { inline static script::Type get() { return script::Type::QtToolBarAreaSizes; } };
template<> struct make_type_t<Qt::ToolBarAreas> { inline static script::Type get() { return script::Type::QtToolBarAreas; } };
template<> struct make_type_t<Qt::ToolButtonStyle> { inline static script::Type get() { return script::Type::QtToolButtonStyle; } };
template<> struct make_type_t<Qt::TouchPointState> { inline static script::Type get() { return script::Type::QtTouchPointState; } };
template<> struct make_type_t<Qt::TransformationMode> { inline static script::Type get() { return script::Type::QtTransformationMode; } };
template<> struct make_type_t<Qt::UIEffect> { inline static script::Type get() { return script::Type::QtUIEffect; } };
template<> struct make_type_t<Qt::WhiteSpaceMode> { inline static script::Type get() { return script::Type::QtWhiteSpaceMode; } };
template<> struct make_type_t<Qt::WidgetAttribute> { inline static script::Type get() { return script::Type::QtWidgetAttribute; } };
template<> struct make_type_t<Qt::WindowFrameSection> { inline static script::Type get() { return script::Type::QtWindowFrameSection; } };
template<> struct make_type_t<Qt::WindowModality> { inline static script::Type get() { return script::Type::QtWindowModality; } };
template<> struct make_type_t<Qt::WindowState> { inline static script::Type get() { return script::Type::QtWindowState; } };
template<> struct make_type_t<Qt::WindowType> { inline static script::Type get() { return script::Type::QtWindowType; } };
} /* namespace bind */ } /* namespace script */

#endif // YASL_CORE_ENUMS_H

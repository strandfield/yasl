// Copyright (C) 2018 Vincent Chambrin
// This file is part of the Yasl project
// For conditions of distribution and use, see copyright notice in LICENSE

#ifndef YASL_CORE_ENUMS_H
#define YASL_CORE_ENUMS_H

#include "yasl/common/types.h"

#include <Qt>

namespace script {
template<> struct make_type_helper<Qt::Alignment> { inline static script::Type get() { return script::Type::QtAlignment; } };
template<> struct make_type_helper<Qt::AlignmentFlag> { inline static script::Type get() { return script::Type::QtAlignmentFlag; } };
template<> struct make_type_helper<Qt::AnchorPoint> { inline static script::Type get() { return script::Type::QtAnchorPoint; } };
template<> struct make_type_helper<Qt::ApplicationAttribute> { inline static script::Type get() { return script::Type::QtApplicationAttribute; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
template<> struct make_type_helper<Qt::ApplicationState> { inline static script::Type get() { return script::Type::QtApplicationState; } };
#endif
template<> struct make_type_helper<Qt::ArrowType> { inline static script::Type get() { return script::Type::QtArrowType; } };
template<> struct make_type_helper<Qt::AspectRatioMode> { inline static script::Type get() { return script::Type::QtAspectRatioMode; } };
template<> struct make_type_helper<Qt::Axis> { inline static script::Type get() { return script::Type::QtAxis; } };
template<> struct make_type_helper<Qt::BGMode> { inline static script::Type get() { return script::Type::QtBGMode; } };
template<> struct make_type_helper<Qt::BrushStyle> { inline static script::Type get() { return script::Type::QtBrushStyle; } };
template<> struct make_type_helper<Qt::CaseSensitivity> { inline static script::Type get() { return script::Type::QtCaseSensitivity; } };
template<> struct make_type_helper<Qt::CheckState> { inline static script::Type get() { return script::Type::QtCheckState; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 9, 0))
template<> struct make_type_helper<Qt::ChecksumType> { inline static script::Type get() { return script::Type::QtChecksumType; } };
#endif
template<> struct make_type_helper<Qt::ClipOperation> { inline static script::Type get() { return script::Type::QtClipOperation; } };
template<> struct make_type_helper<Qt::ConnectionType> { inline static script::Type get() { return script::Type::QtConnectionType; } };
template<> struct make_type_helper<Qt::ContextMenuPolicy> { inline static script::Type get() { return script::Type::QtContextMenuPolicy; } };
template<> struct make_type_helper<Qt::CoordinateSystem> { inline static script::Type get() { return script::Type::QtCoordinateSystem; } };
template<> struct make_type_helper<Qt::Corner> { inline static script::Type get() { return script::Type::QtCorner; } };
template<> struct make_type_helper<Qt::CursorMoveStyle> { inline static script::Type get() { return script::Type::QtCursorMoveStyle; } };
template<> struct make_type_helper<Qt::CursorShape> { inline static script::Type get() { return script::Type::QtCursorShape; } };
template<> struct make_type_helper<Qt::DateFormat> { inline static script::Type get() { return script::Type::QtDateFormat; } };
template<> struct make_type_helper<Qt::DayOfWeek> { inline static script::Type get() { return script::Type::QtDayOfWeek; } };
template<> struct make_type_helper<Qt::DockWidgetArea> { inline static script::Type get() { return script::Type::QtDockWidgetArea; } };
template<> struct make_type_helper<Qt::DockWidgetAreaSizes> { inline static script::Type get() { return script::Type::QtDockWidgetAreaSizes; } };
template<> struct make_type_helper<Qt::DropAction> { inline static script::Type get() { return script::Type::QtDropAction; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 1, 0))
template<> struct make_type_helper<Qt::Edge> { inline static script::Type get() { return script::Type::QtEdge; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 6, 0))
template<> struct make_type_helper<Qt::EnterKeyType> { inline static script::Type get() { return script::Type::QtEnterKeyType; } };
#endif
template<> struct make_type_helper<Qt::EventPriority> { inline static script::Type get() { return script::Type::QtEventPriority; } };
template<> struct make_type_helper<Qt::FillRule> { inline static script::Type get() { return script::Type::QtFillRule; } };
template<> struct make_type_helper<Qt::FindChildOption> { inline static script::Type get() { return script::Type::QtFindChildOption; } };
template<> struct make_type_helper<Qt::FocusPolicy> { inline static script::Type get() { return script::Type::QtFocusPolicy; } };
template<> struct make_type_helper<Qt::FocusReason> { inline static script::Type get() { return script::Type::QtFocusReason; } };
template<> struct make_type_helper<Qt::GestureFlag> { inline static script::Type get() { return script::Type::QtGestureFlag; } };
template<> struct make_type_helper<Qt::GestureState> { inline static script::Type get() { return script::Type::QtGestureState; } };
template<> struct make_type_helper<Qt::GestureType> { inline static script::Type get() { return script::Type::QtGestureType; } };
template<> struct make_type_helper<Qt::GlobalColor> { inline static script::Type get() { return script::Type::QtGlobalColor; } };
template<> struct make_type_helper<Qt::HitTestAccuracy> { inline static script::Type get() { return script::Type::QtHitTestAccuracy; } };
template<> struct make_type_helper<Qt::ImageConversionFlag> { inline static script::Type get() { return script::Type::QtImageConversionFlag; } };
template<> struct make_type_helper<Qt::ImageConversionFlags> { inline static script::Type get() { return script::Type::QtImageConversionFlags; } };
template<> struct make_type_helper<Qt::Initialization> { inline static script::Type get() { return script::Type::QtInitialization; } };
template<> struct make_type_helper<Qt::InputMethodHint> { inline static script::Type get() { return script::Type::QtInputMethodHint; } };
template<> struct make_type_helper<Qt::InputMethodQuery> { inline static script::Type get() { return script::Type::QtInputMethodQuery; } };
template<> struct make_type_helper<Qt::ItemDataRole> { inline static script::Type get() { return script::Type::QtItemDataRole; } };
template<> struct make_type_helper<Qt::ItemFlag> { inline static script::Type get() { return script::Type::QtItemFlag; } };
template<> struct make_type_helper<Qt::ItemSelectionMode> { inline static script::Type get() { return script::Type::QtItemSelectionMode; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
template<> struct make_type_helper<Qt::ItemSelectionOperation> { inline static script::Type get() { return script::Type::QtItemSelectionOperation; } };
#endif
template<> struct make_type_helper<Qt::Key> { inline static script::Type get() { return script::Type::QtKey; } };
template<> struct make_type_helper<Qt::KeyboardModifier> { inline static script::Type get() { return script::Type::QtKeyboardModifier; } };
template<> struct make_type_helper<Qt::KeyboardModifiers> { inline static script::Type get() { return script::Type::QtKeyboardModifiers; } };
template<> struct make_type_helper<Qt::LayoutDirection> { inline static script::Type get() { return script::Type::QtLayoutDirection; } };
template<> struct make_type_helper<Qt::MaskMode> { inline static script::Type get() { return script::Type::QtMaskMode; } };
template<> struct make_type_helper<Qt::MatchFlag> { inline static script::Type get() { return script::Type::QtMatchFlag; } };
template<> struct make_type_helper<Qt::Modifier> { inline static script::Type get() { return script::Type::QtModifier; } };
template<> struct make_type_helper<Qt::MouseButton> { inline static script::Type get() { return script::Type::QtMouseButton; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
template<> struct make_type_helper<Qt::MouseEventFlag> { inline static script::Type get() { return script::Type::QtMouseEventFlag; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 3, 0))
template<> struct make_type_helper<Qt::MouseEventSource> { inline static script::Type get() { return script::Type::QtMouseEventSource; } };
#endif
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_helper<Qt::NativeGestureType> { inline static script::Type get() { return script::Type::QtNativeGestureType; } };
#endif
template<> struct make_type_helper<Qt::NavigationMode> { inline static script::Type get() { return script::Type::QtNavigationMode; } };
template<> struct make_type_helper<Qt::Orientation> { inline static script::Type get() { return script::Type::QtOrientation; } };
template<> struct make_type_helper<Qt::PenCapStyle> { inline static script::Type get() { return script::Type::QtPenCapStyle; } };
template<> struct make_type_helper<Qt::PenJoinStyle> { inline static script::Type get() { return script::Type::QtPenJoinStyle; } };
template<> struct make_type_helper<Qt::PenStyle> { inline static script::Type get() { return script::Type::QtPenStyle; } };
template<> struct make_type_helper<Qt::ScreenOrientation> { inline static script::Type get() { return script::Type::QtScreenOrientation; } };
template<> struct make_type_helper<Qt::ScrollBarPolicy> { inline static script::Type get() { return script::Type::QtScrollBarPolicy; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 2, 0))
template<> struct make_type_helper<Qt::ScrollPhase> { inline static script::Type get() { return script::Type::QtScrollPhase; } };
#endif
template<> struct make_type_helper<Qt::ShortcutContext> { inline static script::Type get() { return script::Type::QtShortcutContext; } };
template<> struct make_type_helper<Qt::SizeHint> { inline static script::Type get() { return script::Type::QtSizeHint; } };
template<> struct make_type_helper<Qt::SizeMode> { inline static script::Type get() { return script::Type::QtSizeMode; } };
template<> struct make_type_helper<Qt::SortOrder> { inline static script::Type get() { return script::Type::QtSortOrder; } };
#if (QT_VERSION >= QT_VERSION_CHECK(5, 5, 0))
template<> struct make_type_helper<Qt::TabFocusBehavior> { inline static script::Type get() { return script::Type::QtTabFocusBehavior; } };
#endif
template<> struct make_type_helper<Qt::TextElideMode> { inline static script::Type get() { return script::Type::QtTextElideMode; } };
template<> struct make_type_helper<Qt::TextFlag> { inline static script::Type get() { return script::Type::QtTextFlag; } };
template<> struct make_type_helper<Qt::TextFormat> { inline static script::Type get() { return script::Type::QtTextFormat; } };
template<> struct make_type_helper<Qt::TextInteractionFlag> { inline static script::Type get() { return script::Type::QtTextInteractionFlag; } };
template<> struct make_type_helper<Qt::TileRule> { inline static script::Type get() { return script::Type::QtTileRule; } };
template<> struct make_type_helper<Qt::TimeSpec> { inline static script::Type get() { return script::Type::QtTimeSpec; } };
template<> struct make_type_helper<Qt::TimerType> { inline static script::Type get() { return script::Type::QtTimerType; } };
template<> struct make_type_helper<Qt::ToolBarArea> { inline static script::Type get() { return script::Type::QtToolBarArea; } };
template<> struct make_type_helper<Qt::ToolBarAreaSizes> { inline static script::Type get() { return script::Type::QtToolBarAreaSizes; } };
template<> struct make_type_helper<Qt::ToolBarAreas> { inline static script::Type get() { return script::Type::QtToolBarAreas; } };
template<> struct make_type_helper<Qt::ToolButtonStyle> { inline static script::Type get() { return script::Type::QtToolButtonStyle; } };
template<> struct make_type_helper<Qt::TouchPointState> { inline static script::Type get() { return script::Type::QtTouchPointState; } };
template<> struct make_type_helper<Qt::TransformationMode> { inline static script::Type get() { return script::Type::QtTransformationMode; } };
template<> struct make_type_helper<Qt::UIEffect> { inline static script::Type get() { return script::Type::QtUIEffect; } };
template<> struct make_type_helper<Qt::WhiteSpaceMode> { inline static script::Type get() { return script::Type::QtWhiteSpaceMode; } };
template<> struct make_type_helper<Qt::WidgetAttribute> { inline static script::Type get() { return script::Type::QtWidgetAttribute; } };
template<> struct make_type_helper<Qt::WindowFrameSection> { inline static script::Type get() { return script::Type::QtWindowFrameSection; } };
template<> struct make_type_helper<Qt::WindowModality> { inline static script::Type get() { return script::Type::QtWindowModality; } };
template<> struct make_type_helper<Qt::WindowState> { inline static script::Type get() { return script::Type::QtWindowState; } };
template<> struct make_type_helper<Qt::WindowType> { inline static script::Type get() { return script::Type::QtWindowType; } };
} // namespace script

#endif // YASL_CORE_ENUMS_H

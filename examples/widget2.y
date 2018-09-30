import core;
import gui;
import widgets;

Widget & w = newWidget("Hello World");
BoxLayout & layout = newBoxLayout(BoxLayout::LeftToRight);
w.setLayout(layout);
PushButton & b = newPushButton("Close", w);
layout.addWidget(b, 0, AlignmentFlag::AlignCenter);
Object::connect(b, PushButton::clicked, w, Widget::close);
w.show();
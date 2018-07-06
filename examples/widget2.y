import core;
import gui;

Widget & w = newWidget("Hello World");
PushButton & b = newPushButton("Close", w);
Object::connect(b, PushButton::clicked, w, Widget::close);
w.show();
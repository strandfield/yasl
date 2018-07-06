import core;
import gui;

Widget & w = newWidget("Hello World!");
Widget & v = newWidget("Bye !");

if(w.parentWidget().isNull()) {
  print("Null parent");
}

w.setParent(v);

if(w.parentWidget().isValid()) {
  Widget & p = w.parentWidget();
  print(p.windowTitle());
}

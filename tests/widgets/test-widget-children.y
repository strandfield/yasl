import core;
import widgets;

Widget & w = newWidget("Hello World!");
Widget & v = newWidget("Bye !");
w.setParent(v);
List<Ref<Object>> children = v.children();
import core;
import gui;

Widget & w = newWidget();
Locale l = Locale::system();
String day = l.dayName(1, Locale::LongFormat);
w.setWindowTitle(day);
w.show();